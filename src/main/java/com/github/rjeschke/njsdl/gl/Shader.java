/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.util.HashMap;

public class Shader
{
	private int glProgram = -1;
	private int glVertexShader = -1;
	private int glFragmentShader = -1;
	private int glGeometryShader = -1;
	private boolean linkOk = false;
	private final HashMap<String, Integer> map = new HashMap<String, Integer>();
	private boolean beVerbose = false;
	private String[] vertexAttribs = null;
	private String[] fragmentAttribs = null;
	
	public Shader()
	{
		this.glProgram = GL.glCreateProgram();
	}

	public Shader(final boolean beVerbose)
	{
		this.glProgram = GL.glCreateProgram();
		this.beVerbose = beVerbose;
	}

	public void dispose()
	{
		if(this.glVertexShader != -1)
		{
			if(this.glProgram != -1)
				GL.glDetachShader(this.glProgram, this.glVertexShader);
			GL.glDeleteShader(this.glVertexShader);
			this.glVertexShader = -1;
		}
		if(this.glFragmentShader != -1)
		{
			if(this.glProgram != -1)
				GL.glDetachShader(this.glProgram, this.glFragmentShader);
			GL.glDeleteShader(this.glFragmentShader);
			this.glFragmentShader = -1;
		}
		if(this.glGeometryShader != -1)
		{
			if(this.glProgram != -1)
				GL.glDetachShader(this.glProgram, this.glGeometryShader);
			GL.glDeleteShader(this.glGeometryShader);
			this.glGeometryShader = -1;
		}
		if(this.glProgram != -1)
		{
			GL.glDeleteProgram(this.glProgram);
			this.glProgram = -1;
		}
	}
	
	public Shader attachVertexShader(final String filename)
	{
		final String shader = this.loadFileAsString(filename);
		this.glVertexShader = GL.glCreateShader(GL.GL_VERTEX_SHADER);
		GL.glShaderSource(this.glVertexShader, 1, new String[] { shader }, null);
		GL.glCompileShader(this.glVertexShader);
		GL.glAttachShader(this.glProgram, this.glVertexShader);
		if(!this.isShaderOk(this.glVertexShader) || this.beVerbose)
			this.printErrors(this.glVertexShader);
		return this;
	}
	
	public Shader attachFragmentShader(final String filename)
	{
		final String shader = this.loadFileAsString(filename);
		this.glFragmentShader = GL.glCreateShader(GL.GL_FRAGMENT_SHADER);
		GL.glShaderSource(this.glFragmentShader, 1, new String[] { shader }, null);
		GL.glCompileShader(this.glFragmentShader);
		GL.glAttachShader(this.glProgram, this.glFragmentShader);
		if(!this.isShaderOk(this.glFragmentShader) || this.beVerbose)
			this.printErrors(this.glFragmentShader);
		return this;
	}

	public Shader attachGeometryShader(final String filename)
	{
		final String shader = this.loadFileAsString(filename);
		this.glGeometryShader = GL.glCreateShader(GL.GL_GEOMETRY_SHADER);
		GL.glShaderSource(this.glGeometryShader, 1, new String[] { shader }, null);
		GL.glCompileShader(this.glGeometryShader);
		GL.glAttachShader(this.glProgram, this.glGeometryShader);
		if(!this.isShaderOk(this.glGeometryShader) || this.beVerbose)
			this.printErrors(this.glGeometryShader);
		return this;
	}

	public Shader setVertexAttributesList(String ... values)
	{
	    this.vertexAttribs = new String[values.length];
	    for(int i = 0; i < values.length; i++)
	        this.vertexAttribs[i] = values[i];
	    return this;
	}
	
    public Shader setFragmentAttributesList(String ... values)
    {
        this.fragmentAttribs = new String[values.length];
        for(int i = 0; i < values.length; i++)
            this.fragmentAttribs[i] = values[i];
        return this;
    }

    public Shader link()
	{
        if(this.vertexAttribs != null)
        {
            for(int i = 0; i < this.vertexAttribs.length; i++)
            {
                GL.glBindAttribLocation(this.glProgram, i, this.vertexAttribs[i]);
            }
        }
        
        if(this.fragmentAttribs != null)
        {
            for(int i = 0; i < this.fragmentAttribs.length; i++)
            {
                GL.glBindAttribLocation(this.glProgram, i, this.fragmentAttribs[i]);
            }
        }
        
		GL.glLinkProgram(this.glProgram);
		if(!this.isProgramOk(this.glProgram))
			this.printErrors(this.glProgram);
		else
		{
			if(this.beVerbose)
				this.printErrors(this.glProgram);
			this.linkOk = true;
		}
		return this;
	}
	
	public boolean linkOk()
	{
		return this.linkOk;
	}
	
	public void use()
	{
		GL.glUseProgram(this.glProgram);
	}
	
	public void unuse()
	{
		GL.glUseProgram(0);
	}

	public String loadFileAsString(final String filename)
	{
		BufferedReader br = null;
		final StringBuilder sb = new StringBuilder();
		try
		{
			br = new BufferedReader(new InputStreamReader(this.fileAsStream(filename)));
			String line = br.readLine();
			while(line != null)
			{
				sb.append(line + "\n");
				line = br.readLine();
			}
		}
		catch(IOException ioe)
		{
			throw new RuntimeException(ioe);
		}
		finally
		{
			try
			{
				if(br != null)
				{
					br.close();
				}
			}
			catch(IOException ioe)
			{
				throw new RuntimeException(ioe);
			}
			
		}
		return sb.toString();
	}
	
	private InputStream fileAsStream(final String filename) throws IOException
	{
		final InputStream ins = this.getClass().getResourceAsStream(filename);
		if(ins != null)
			return ins;
		return new FileInputStream(filename);
	}

	private int getUniLoc(final String name)
	{
		if(this.map.containsKey(name))
			return this.map.get(name);
		final int i = GL.glGetUniformLocation(this.glProgram, name);
		this.map.put(name, i);
		return i;
	}
	
	public int getAttribLocation(final String name)
	{
		return GL.glGetAttribLocation(this.glProgram, name);
	}
	
	public void setUniformMat4(final String name, final Mat4 matrix)
	{
		GL.glUniformMatrix4fv(this.getUniLoc(name), 1, false, matrix.data, 0);
	}
	
	public void setUniform1f(final String name, final float v0)
	{
		GL.glUniform1f(this.getUniLoc(name), v0);
	}
	
    public void setUniform1f(final String name, final float[] arr)
    {
        GL.glUniform1fv(this.getUniLoc(name), arr.length, arr, 0);
    }

    public void setUniform1f(final String name, final float[] arr, final int offset)
    {
        GL.glUniform1fv(this.getUniLoc(name), arr.length, arr, offset);
    }

    public void setUniform1f(final String name, final FloatBuffer buffer)
    {
        GL.glUniform1fv(this.getUniLoc(name), buffer.capacity(), buffer);
    }

    public void setUniform2f(final String name, final Vec2 v)
    {
        GL.glUniform2fv(this.getUniLoc(name), 2, v.data, 0);
    }

    public void setUniform2f(final String name, final float v0, final float v1)
	{
		GL.glUniform2f(this.getUniLoc(name), v0, v1);
	}

	public void setUniform2f(final String name, final Vec2[] v)
	{
	    final float[] buffer = new float[2 * v.length];
    	for(int i = 0; i < v.length; i++)
    	{
    	    buffer[i * 2 + 0] = v[i].data[0];
    	    buffer[i * 2 + 1] = v[i].data[1];
    	}
    	GL.glUniform2fv(this.getUniLoc(name), v.length, buffer, 0);
	}

    public void setUniform3f(final String name, final Vec3 v)
    {
        GL.glUniform3fv(this.getUniLoc(name), 3, v.data, 0);
    }

	public void setUniform3f(final String name, final float v0, final float v1, final float v2)
	{
		GL.glUniform3f(this.getUniLoc(name), v0, v1, v2);
	}

    public void setUniform3fv(final String name, final Vec3[] v)
    {
        final float[] buffer = new float[3 * v.length];
        for(int i = 0; i < v.length; i++)
        {
            buffer[i * 3 + 0] = v[i].data[0];
            buffer[i * 3 + 1] = v[i].data[1];
            buffer[i * 3 + 2] = v[i].data[2];
        }
        GL.glUniform3fv(this.getUniLoc(name), v.length, buffer, 0);
    }

    public void setUniform4f(final String name, final Vec4 v)
    {
        GL.glUniform4fv(this.getUniLoc(name), 4, v.data, 0);
    }

    public void setUniform4f(final String name, final Vec3 v, final float w)
    {
        GL.glUniform4f(this.getUniLoc(name), v.getX(), v.getY(), v.getZ(), w);
    }

    public void setUniform4f(final String name, final float v0, final float v1, final float v2, final float v3)
	{
		GL.glUniform4f(this.getUniLoc(name), v0, v1, v2, v3);
	}

    public void setUniform4f(final String name, final Vec4[] v)
    {
        final float[] buffer = new float[4 * v.length];
        for(int i = 0; i < v.length; i++)
        {
            buffer[i * 4 + 0] = v[i].data[0];
            buffer[i * 4 + 1] = v[i].data[1];
            buffer[i * 4 + 2] = v[i].data[2];
            buffer[i * 4 + 3] = v[i].data[3];
        }
        GL.glUniform4fv(this.getUniLoc(name), v.length, buffer, 0);
    }

    public void setUniform1i(final String name, final int v0)
	{
		GL.glUniform1i(this.getUniLoc(name), v0);
	}

    public void setUniform1i(final String name, final int[] array)
    {
        GL.glUniform1iv(this.getUniLoc(name), array.length, array, 0);
    }

    public void setUniform1i(final String name, final int[] array, final int offset)
    {
        GL.glUniform1iv(this.getUniLoc(name), array.length, array, offset);
    }

    public void setUniform1i(final String name, IntBuffer buffer)
    {
        GL.glUniform1iv(this.getUniLoc(name), buffer.capacity(), buffer);
    }

	public void setUniform2i(final String name, final int v0, final int v1)
	{
		GL.glUniform2i(this.getUniLoc(name), v0, v1);
	}

	public void setUniform3i(final String name, final int v0, final int v1, final int v2)
	{
		GL.glUniform3i(this.getUniLoc(name), v0, v1, v2);
	}

	public void setUniform4i(final String name, final int v0, final int v1, final int v2, final int v3)
	{
		GL.glUniform4i(this.getUniLoc(name), v0, v1, v2, v3);
	}

    private boolean isShaderOk(int id)
	{
		final int[] temp = new int[1];
		GL.glGetShaderiv(id, GL.GL_COMPILE_STATUS, temp, 0);
		return temp[0] == GL.GL_TRUE;
	}
	
	private boolean isProgramOk(int id)
	{
		final int[] temp = new int[1];
		GL.glGetProgramiv(id, GL.GL_LINK_STATUS, temp, 0);
		return temp[0] == GL.GL_TRUE;
	}
	
	public void printErrors(int id)
	{
		final int[] length = new int[2];
		byte[] bytes = null;
		if(GL.glIsShader(id))
		{
			GL.glGetShaderiv(id, GL.GL_INFO_LOG_LENGTH, length, 0);
			if(length[0] > 1)
			{
				bytes = new byte[length[0]];
				GL.glGetShaderInfoLog(id, length[0], length, 1, bytes, 0);
			}
		}
		else
		{
			GL.glGetProgramiv(id, GL.GL_INFO_LOG_LENGTH, length, 0);
			if(length[0] > 1)
			{
				bytes = new byte[length[0]];
				GL.glGetProgramInfoLog(id, length[0], length, 1, bytes, 0);
			}
		}
		if(bytes != null)
		{
			int z = 0;
			while(bytes[z] != 0)
				z++;
			if(z > 0)
				System.out.println(new String(bytes, 0, z));
		}
	}
}

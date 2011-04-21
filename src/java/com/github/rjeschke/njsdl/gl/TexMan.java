/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.util.HashMap;

public class TexMan
{
	private final static String TAG = "TexMan";
	private static HashMap<String, Integer> texMapping = new HashMap<String, Integer>();

	private TexMan() { /* */ }
	
	public static int generate(String texture)
	{
		if(texMapping.containsKey(texture))
			Log.println(TAG, "Duplicate texture: '" + texture + "'");
		final int[] temp = new int[1];
		GL.glGenTextures(1, temp, 0);
		texMapping.put(texture, temp[0]);
		return temp[0];
	}
	
	public static int genBind1D(String texture)
	{
		final int tex = generate(texture);
		GL.glBindTexture(GL.GL_TEXTURE_1D, tex);
		return tex;
	}

	public static int genBind2D(String texture)
	{
		final int tex = generate(texture);
		GL.glBindTexture(GL.GL_TEXTURE_2D, tex);
		return tex;
	}

	public static int genBind3D(String texture)
	{
		final int tex = generate(texture);
		GL.glBindTexture(GL.GL_TEXTURE_3D, tex);
		return tex;
	}

	public static int genBindCube(String texture)
	{
		final int tex = generate(texture);
		GL.glBindTexture(GL.GL_TEXTURE_CUBE_MAP, tex);
		return tex;
	}

	public static void dispose()
	{
		final int[] textures = new int[texMapping.size()];
		int i = 0;
		for(int t : texMapping.values())
			textures[i++] = t;
		GL.glDeleteTextures(i, textures, 0);
		texMapping.clear();
	}
	
	public static void texParam1D(int minFilter, int magFilter, int wrapS)
	{
		GL.glTexParameteri(GL.GL_TEXTURE_1D, GL.GL_TEXTURE_MIN_FILTER, minFilter);
		GL.glTexParameteri(GL.GL_TEXTURE_1D, GL.GL_TEXTURE_MAG_FILTER, magFilter);
		GL.glTexParameteri(GL.GL_TEXTURE_1D, GL.GL_TEXTURE_WRAP_S, wrapS);
	}
	
	public static void texParam2D(int minFilter, int magFilter, int wrapS, int wrapT)
	{
		GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MIN_FILTER, minFilter);
		GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAG_FILTER, magFilter);
		GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_S, wrapS);
		GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_T, wrapT);
	}

	public static void texParam3D(int minFilter, int magFilter, int wrapS, int wrapT, int wrapR)
	{
		GL.glTexParameteri(GL.GL_TEXTURE_3D, GL.GL_TEXTURE_MIN_FILTER, minFilter);
		GL.glTexParameteri(GL.GL_TEXTURE_3D, GL.GL_TEXTURE_MAG_FILTER, magFilter);
		GL.glTexParameteri(GL.GL_TEXTURE_3D, GL.GL_TEXTURE_WRAP_S, wrapS);
		GL.glTexParameteri(GL.GL_TEXTURE_3D, GL.GL_TEXTURE_WRAP_T, wrapT);
		GL.glTexParameteri(GL.GL_TEXTURE_3D, GL.GL_TEXTURE_WRAP_R, wrapR);
	}
	
	public static int generatePerlin(String texture)
	{
		final int tex = generate(texture);
		GL.glBindTexture(GL.GL_TEXTURE_2D, tex);
		texParam2D(GL.GL_NEAREST, GL.GL_NEAREST, GL.GL_REPEAT, GL.GL_REPEAT);
		GL.glTexImage2D(GL.GL_TEXTURE_2D, 0, GL.GL_RGBA, 256, 256, 0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, TexUtil.genPerlin());
		GL.glBindTexture(GL.GL_TEXTURE_2D, 0);
		return tex;
	}
	
	public static int generatePerlinF(String texture)
	{
		final int tex = generate(texture);
		GL.glBindTexture(GL.GL_TEXTURE_2D, tex);
		texParam2D(GL.GL_NEAREST, GL.GL_NEAREST, GL.GL_REPEAT, GL.GL_REPEAT);
		GL.glTexImage2D(GL.GL_TEXTURE_2D, 0, GL.GL_RGBA16F, 256, 256, 0, GL.GL_RGBA, GL.GL_FLOAT, TexUtil.genPerlinF());
		GL.glBindTexture(GL.GL_TEXTURE_2D, 0);
		return tex;
	}

	public static void bindTexture1D(String texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_1D, texMapping.get(texture));
	}

	public static void bindTexture1D(int texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_1D, texture);
	}

	public static void bindTexture2D(String texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_2D, texMapping.get(texture));
	}

	public static void bindTexture2D(int texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_2D, texture);
	}

	public static void bindTexture3D(String texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_3D, texMapping.get(texture));
	}

	public static void bindTexture3D(int texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_3D, texture);
	}

	public static void bindTextureCube(String texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_CUBE_MAP, texMapping.get(texture));
	}

	public static void bindTextureCube(int texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_CUBE_MAP, texture);
	}
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.nio.FloatBuffer;

import com.github.rjeschke.njsdl.Buffers;


public class FSQ
{
	private static int vArray = -1;
	
	private FSQ() { /* */ }
	
	public static void init()
	{
		FloatBuffer buf = Buffers.newFloat(12);
		
		buf.put( 0, -1);	buf.put( 1,  1);
		buf.put( 2,  1);	buf.put( 3,  1);
		buf.put( 4, -1);	buf.put( 5, -1);
		
		buf.put( 6,  1);	buf.put( 7,  1);
		buf.put( 8,  1);	buf.put( 9, -1);
		buf.put(10, -1);	buf.put(11, -1);

		int[] temp = new int[2];
		
		GL.glGenVertexArrays(1, temp, 0);
		GL.glBindVertexArray(temp[0]);
		// Vertices == 1
		GL.glGenBuffers(1, temp, 1);
		GL.glBindBuffer(GL.GL_ARRAY_BUFFER, temp[1]);
		GL.glBufferData(GL.GL_ARRAY_BUFFER, 12 * 4, buf, GL.GL_STATIC_DRAW);
		GL.glVertexAttribPointer(0, 2, GL.GL_FLOAT, false, 0, null);
		GL.glEnableVertexAttribArray(0);
		GL.glBindVertexArray(0);
		vArray = temp[0];
	}

	public static void bind()
	{
	    GL.glDepthFunc(GL.GL_ALWAYS);
	    GL.glBindVertexArray(vArray);
	}
	
	public static void render()
	{
	    GL.glDrawArrays(GL.GL_TRIANGLES, 0, 12);
	}
	
	public static void unbind()
	{
	    GL.glBindVertexArray(0);
	    GL.glDepthFunc(GL.GL_LEQUAL);
	}
}

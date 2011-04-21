/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class Util
{
    private Util() { /* */ }
    
	public static float[] gaussian(int size, double sigma)
	{
		final float[] g = new float[size];
		final int s2 = size / 2;
		float sum = 0;
		
		for(int i = 0; i < size; i++)
		{
			final double x = (double)(i - s2) / (double)s2;
			final float v = (float)Math.exp(-(x * x) / (2.0 * sigma * sigma));
			sum += v;
			g[i] = v;
		}
		
		for(int i = 0; i < size; i++)
			g[i] /= sum;
		
		return g;
	}
	
	public static boolean sleep(long millis)
	{
	    try
        {
            Thread.sleep(millis);
        }
        catch (InterruptedException e)
        {
            return false;
        }
        return true;
	}
	
	public static void stdInit()
	{
		GL.glClearColor(0, 0, 0, 0);
		GL.glClearDepth(1);
		GL.glEnable(GL.GL_DEPTH_TEST);
		GL.glDepthFunc(GL.GL_LEQUAL);
		GL.glEnable(GL.GL_CULL_FACE);
		GL.glFrontFace(GL.GL_CW);
	}
}

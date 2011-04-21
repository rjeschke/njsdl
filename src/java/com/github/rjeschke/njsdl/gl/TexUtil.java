/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.awt.image.BufferedImage;
import java.awt.image.DataBufferInt;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.FloatBuffer;

import javax.imageio.ImageIO;

import com.github.rjeschke.njsdl.Buffers;


public class TexUtil
{
	private static int[] perm = {
		151, 160, 137,  91,  90,  15, 131,  13, 201,  95,  96,  53, 194, 233,   7, 225,
		140,  36, 103,  30,  69, 142,   8,  99,  37, 240,  21,  10,  23, 190,   6, 148,
		247, 120, 234,  75,   0,  26, 197,  62,  94, 252, 219, 203, 117,  35,  11,  32,
		 57, 177,  33,  88, 237, 149,  56,  87, 174,  20, 125, 136, 171, 168,  68, 175,
		 74, 165,  71, 134, 139,  48,  27, 166,  77, 146, 158, 231,  83, 111, 229, 122,
		 60, 211, 133, 230, 220, 105,  92,  41,  55,  46, 245,  40, 244, 102, 143,  54,
		 65,  25,  63, 161,   1, 216,  80,  73, 209,  76, 132, 187, 208,  89,  18, 169,
		200, 196, 135, 130, 116, 188, 159,  86, 164, 100, 109, 198, 173, 186,   3,  64,
		 52, 217, 226, 250, 124, 123,   5, 202,  38, 147, 118, 126, 255,  82,  85, 212,
		207, 206,  59, 227,  47,  16,  58,  17, 182, 189,  28,  42, 223, 183, 170, 213,
		119, 248, 152,   2,  44, 154, 163,  70, 221, 153, 101, 155, 167,  43, 172,   9,
		129,  22,  39, 253,  19,  98, 108, 110,  79, 113, 224, 232, 178, 185, 112, 104,
		218, 246,  97, 228, 251,  34, 242, 193, 238, 210, 144,  12, 191, 179, 162, 241,
		 81,  51, 145, 235, 249,  14, 239, 107,  49, 192, 214,  31, 181, 199, 106, 157,
		184,  84, 204, 176, 115, 121,  50,  45, 127,   4, 150, 254, 138, 236, 205,  93,
		222, 114,  67,  29,  24,  72, 243, 141, 128, 195,  78,  66, 215,  61, 156, 180};

	private static int[][] grad3 = {
		{ 0, 1, 1}, { 0, 1,-1}, { 0,-1, 1}, { 0,-1,-1},
		{ 1, 0, 1}, { 1, 0,-1}, {-1, 0, 1}, {-1, 0,-1},
		{ 1, 1, 0}, { 1,-1, 0}, {-1, 1, 0}, {-1,-1, 0},
		{ 1, 0,-1}, {-1, 0,-1}, { 0,-1, 1}, { 0, 1, 1}};

	private TexUtil() { /* */ }
	
	public static ByteBuffer genPerlin()
	{
		final ByteBuffer ret = Buffers.newByte(256 * 256 * 4);
		
		for(int y = 0; y < 256; y++)
		{
			for(int x = 0; x < 256; x++)
			{
				int v = perm[(x + y) & 255] & 15;
				ret.put((x + y * 256) * 4 + 0, (byte)Math3D.clamp(grad3[v][0] * 128 + 128, 0, 255)); 
				ret.put((x + y * 256) * 4 + 1, (byte)Math3D.clamp(grad3[v][1] * 128 + 128, 0, 255)); 
				ret.put((x + y * 256) * 4 + 2, (byte)Math3D.clamp(grad3[v][2] * 128 + 128, 0, 255)); 
				ret.put((x + y * 256) * 4 + 3, (byte)perm[(perm[x] + y) & 255]); 
			}
		}
		
		return ret;
	}

	public static FloatBuffer genPerlinF()
	{
		final FloatBuffer ret = Buffers.newFloat(256 * 256 * 4);
		
		for(int y = 0; y < 256; y++)
		{
			for(int x = 0; x < 256; x++)
			{
				int v = perm[(x + y) & 255] & 15;
				ret.put((x + y * 256) * 4 + 0, grad3[v][0]); 
				ret.put((x + y * 256) * 4 + 1, grad3[v][1]); 
				ret.put((x + y * 256) * 4 + 2, grad3[v][2]); 
				ret.put((x + y * 256) * 4 + 3, perm[(perm[x] + y) & 255] / 255.0f); 
			}
		}
		
		return ret;
	}

	public static ByteBuffer bufferedImageToByteBuffer(BufferedImage image)
	{
        final ByteBuffer buf = Buffers.newByte(image.getWidth() * image.getHeight() * 4);
        final WritableRaster r = image.getRaster();
        final int[] pix = new int[4];
        for(int n = 0; n < image.getHeight(); n++)
        {
	        for(int m = 0; m < image.getWidth(); m++)
	        {
	        	r.getPixel(m, image.getHeight() - 1 - n, pix);
	        	final int i = (m + n * image.getWidth()) * 4;
	        	buf.put(i + 0, (byte)pix[0]);
	        	buf.put(i + 1, (byte)pix[1]);
	        	buf.put(i + 2, (byte)pix[2]);
	        	buf.put(i + 3, r.getNumBands() == 4 ? (byte)pix[3] : (byte)255);
	        }
        }
        return buf;
	}
	
	public static int genTexture()
	{
	    final int[] ret = new int[1];
	    GL.glGenTextures(1, ret, 0);
	    return ret[0];
	}
	
	public static void texImage2D(BufferedImage image)
	{
		GL.glTexImage2D(GL.GL_TEXTURE_2D, 0, GL.GL_RGBA, image.getWidth(), image.getHeight(), 0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, bufferedImageToByteBuffer(image));
	}

	public static void texImage2DCube(int side, BufferedImage image)
	{
		GL.glTexImage2D(side, 0, GL.GL_RGBA, image.getWidth(), image.getHeight(), 0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, bufferedImageToByteBuffer(image));
	}

	public static ByteBuffer readPixels(int x, int y, int width, int height)
	{
        final ByteBuffer buf = Buffers.newByte(width * height * 4);
		GL.glReadPixels(x, y, width, height, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, buf);
		return buf;
	}
	
	public static BufferedImage readPixelsAsImage(int x, int y, int width, int height)
	{
        final ByteBuffer buf = Buffers.newByte(width * height * 4);
		GL.glReadPixels(x, y, width, height, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, buf);
		final BufferedImage img = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
		final int[] pix = ((DataBufferInt)img.getRaster().getDataBuffer()).getData();
		for(int i = 0; i < pix.length; i++)
		{
			pix[i] = 
				((buf.get(i * 4 + 0) & 255) << 16) |
				((buf.get(i * 4 + 1) & 255) <<  8) |
				 (buf.get(i * 4 + 2) & 255)        |
				((buf.get(i * 4 + 3) & 255) << 24);
		}
		return img;
	}
	
	public static BufferedImage loadImage(String filename)
	{
		BufferedImage ret = null;
		final File file = new File(filename);
		try
		{
			if(file.exists() && file.isFile())
			{
				ret = ImageIO.read(file);
			}
			else
			{
				InputStream in = TexUtil.class.getResourceAsStream(filename);
				if(in != null)
				{
					ret = ImageIO.read(in);
				}
			}
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		return ret;
	}
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class RenderTargetCM
{
	private final Type colorBuffer, depthBuffer;
	private int cubeTexture = -1, depthMap = -1, frameBuffer = -1;
	private int bufferWidth, bufferHeight;
	private int[] prevViewPort = new int[4];

	public RenderTargetCM(Type colorBuffer, Type depthBuffer)
	{
		this.colorBuffer = colorBuffer;
		this.depthBuffer = depthBuffer;
	}
	
	public int getWidth()
	{
		return this.bufferWidth;
	}
	
	public int getHeight()
	{
		return this.bufferHeight;
	}
	
	public void dispose()
	{
		int[] temp = new int[1];
		if(this.cubeTexture != -1)
		{
			temp[0] = this.cubeTexture;
			this.cubeTexture = -1;
			GL.glDeleteTextures(1, temp, 0);
		}
		if(this.depthMap != -1)
		{
			temp[0] = this.depthMap;
			this.depthMap = -1;
			GL.glDeleteRenderbuffers(1, temp, 0);
		}
		if(this.frameBuffer != -1)
		{
			temp[0] = this.frameBuffer;
			this.frameBuffer = -1;
			GL.glDeleteFramebuffers(1, temp, 0);
		}
	}
	
	public void bind()
	{
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, this.frameBuffer);
		GL.glGetIntegerv(GL.GL_VIEWPORT, this.prevViewPort, 0);
		if(this.prevViewPort[0] != 0 || this.prevViewPort[1] != 0 || this.prevViewPort[2] != this.bufferWidth || this.prevViewPort[3] != this.bufferHeight)
			GL.glViewport(0, 0, this.bufferWidth, this.bufferHeight);
		GL.glDrawBuffers(1, new int[] { GL.GL_COLOR_ATTACHMENT0 }, 0);
	}

	public void bindFace(int face)
	{
		GL.glFramebufferTexture2D(GL.GL_FRAMEBUFFER, GL.GL_COLOR_ATTACHMENT0, face, this.cubeTexture, 0);
	}
	
	public void bindTexture()
	{
		GL.glBindTexture(GL.GL_TEXTURE_CUBE_MAP, this.cubeTexture);
	}
	
	public void unbind()
	{
		if(this.prevViewPort[0] != 0 || this.prevViewPort[1] != 0 || this.prevViewPort[2] != this.bufferWidth || this.prevViewPort[3] != this.bufferHeight)
			GL.glViewport(this.prevViewPort[0], this.prevViewPort[1], this.prevViewPort[2], this.prevViewPort[3]);
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, 0);
	}

	private void genTexImage(int index, int width, int height)
	{
		switch(this.colorBuffer)
		{
		case RGBA:
			GL.glTexImage2D(index, 0, GL.GL_RGBA, width, height, 0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, null);
			break;
		case RGBAF16:
			GL.glTexImage2D(index, 0, GL.GL_RGBA16F, width, height, 0, GL.GL_RGBA, GL.GL_FLOAT, null);
			break;
		case RGBAF32:
			GL.glTexImage2D(index, 0, GL.GL_RGBA32F, width, height, 0, GL.GL_RGBA, GL.GL_FLOAT, null);
			break;
		default:
			throw new IllegalArgumentException("Unsupported color buffer type: " + this.colorBuffer);
		}
	}
	
	public void resize(int width, int height)
	{
		int[] temp = new int[3];
		this.dispose();
		
		GL.glGenFramebuffers(1, temp, 0); this.frameBuffer = temp[0];
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, this.frameBuffer);
		
		GL.glGenTextures(1, temp, 1); this.cubeTexture = temp[1];
		GL.glBindTexture(GL.GL_TEXTURE_CUBE_MAP, temp[1]);
		GL.glTexParameteri(GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_WRAP_S, GL.GL_CLAMP_TO_EDGE);
		GL.glTexParameteri(GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_WRAP_T, GL.GL_CLAMP_TO_EDGE);
		GL.glTexParameteri(GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_WRAP_R, GL.GL_CLAMP_TO_EDGE);
		GL.glTexParameteri(GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MIN_FILTER, GL.GL_LINEAR);
		GL.glTexParameteri(GL.GL_TEXTURE_CUBE_MAP, GL.GL_TEXTURE_MAG_FILTER, GL.GL_LINEAR);
		for(int i = 0; i < 6; i++)
			this.genTexImage(GL.GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, width, height);
		
		GL.glGenRenderbuffers(1, temp, 0); this.depthMap = temp[2];
		GL.glBindRenderbuffer(GL.GL_RENDERBUFFER, this.depthMap);
		switch(this.depthBuffer)
		{
		case DEPTH16:
			GL.glRenderbufferStorage(GL.GL_RENDERBUFFER, GL.GL_DEPTH_COMPONENT16, width, height);
			break;
		case DEPTH24:
			GL.glRenderbufferStorage(GL.GL_RENDERBUFFER, GL.GL_DEPTH_COMPONENT24, width, height);
			break;
		case DEPTH32:
			GL.glRenderbufferStorage(GL.GL_RENDERBUFFER, GL.GL_DEPTH_COMPONENT32, width, height);
			break;
		default:
			throw new IllegalArgumentException("Unsupported depth buffer type: " + this.depthBuffer);
		}
		GL.glFramebufferRenderbuffer(GL.GL_FRAMEBUFFER, GL.GL_DEPTH_ATTACHMENT, GL.GL_RENDERBUFFER, this.depthMap);
		
		GL.glBindRenderbuffer(GL.GL_RENDERBUFFER, 0);
		GL.glBindTexture(GL.GL_TEXTURE_CUBE_MAP, 0);
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, 0);
		
		this.bufferWidth = width;
		this.bufferHeight = height;
	}

	public enum Type
	{
		/** Alpha component, 16 bit float */
		RGBA,
		/** RGBA 16 bit float */
		RGBAF16,
		/** RGBA 32 bit float */
		RGBAF32,
		/** 16 bit depth buffer */
		DEPTH16,
		/** 24 bit depth buffer */
		DEPTH24,
		/** 32 bit depth buffer */
		DEPTH32
	}
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.util.Arrays;

public class RenderTarget
{
	private final Type colorBuffer, depthBuffer;
	private final int[] colorTextures, drawBuffers;
	private int depthTexture, frameBuffer;
	private final int[] textureProperties, prevViewPort = new int[4];
	private int bufferWidth, bufferHeight;
	
	public RenderTarget(Type colorBuffer, int numColorBuffers, Type depthBuffer)
	{
		this.colorBuffer = colorBuffer;
		this.depthBuffer = depthBuffer;
		this.colorTextures = new int[numColorBuffers];
		this.drawBuffers = new int[numColorBuffers];
		this.textureProperties = new int[numColorBuffers * 4];
		Arrays.fill(this.colorTextures, -1);
		this.depthTexture = this.frameBuffer = -1;
		this.defaultTextureProperties();
	}
	
	public void setTextureProperties(int texture, int minFilter, int magFilter, int clampS, int clampT)
	{
		this.textureProperties[texture * 4 + 0] = minFilter; 
		this.textureProperties[texture * 4 + 1] = magFilter; 
		this.textureProperties[texture * 4 + 2] = clampS; 
		this.textureProperties[texture * 4 + 3] = clampT; 
	}
	
	private void defaultTextureProperties()
	{
		for(int i = 0; i < this.colorTextures.length; i++)
		{
			this.textureProperties[i * 4 + 0] = GL.GL_NEAREST;
			this.textureProperties[i * 4 + 1] = GL.GL_NEAREST;
			this.textureProperties[i * 4 + 2] = GL.GL_CLAMP_TO_EDGE;
			this.textureProperties[i * 4 + 3] = GL.GL_CLAMP_TO_EDGE;
		}
	}
	
	public int getWidth()
	{
		return this.bufferWidth;
	}
	
	public int getHeight()
	{
		return this.bufferHeight;
	}
	
	public void bindColorTexture()
	{
		GL.glBindTexture(GL.GL_TEXTURE_2D, this.colorTextures[0]);
	}
	
	public void bindColorTexture(int texture)
	{
		GL.glBindTexture(GL.GL_TEXTURE_2D, this.colorTextures[texture]);
	}

	public int getColorTexture(int index)
	{
		return this.colorTextures[index];
	}
	
	public int getColorTexture()
	{
		return this.colorTextures[0];
	}

	public void bind()
	{
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, this.frameBuffer);
		GL.glGetIntegerv(GL.GL_VIEWPORT, this.prevViewPort, 0);
		if(this.prevViewPort[0] != 0 || this.prevViewPort[1] != 0 || this.prevViewPort[2] != this.bufferWidth || this.prevViewPort[3] != this.bufferHeight)
			GL.glViewport(0, 0, this.bufferWidth, this.bufferHeight);
		if(this.depthBuffer == Type.NONE)
		{
			GL.glDepthMask(false);
		}
		GL.glDrawBuffers(this.drawBuffers.length, this.drawBuffers, 0);
	}
	
	public void unbind()
	{
		if(this.prevViewPort[0] != 0 || this.prevViewPort[1] != 0 || this.prevViewPort[2] != this.bufferWidth || this.prevViewPort[3] != this.bufferHeight)
			GL.glViewport(this.prevViewPort[0], this.prevViewPort[1], this.prevViewPort[2], this.prevViewPort[3]);
		if(this.depthBuffer == Type.NONE)
		{
			GL.glDepthMask(true);
		}
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, 0);
	}
	
	public void dispose()
	{
		int n = 0;
		int[] temp = new int[2 + this.colorTextures.length];
		if(this.depthTexture != -1)
		{
			temp[0] = this.depthTexture;
			GL.glDeleteRenderbuffers(1, temp, 0);
			this.depthTexture = -1;
		}
		for(int i = 0; i < this.colorTextures.length; i++)
		{
			if(this.colorTextures[i] != -1)
			{
				temp[n++] = this.colorTextures[i];
				this.colorTextures[i] = -1;
			}
		}
		if(n > 0)
		{
			GL.glDeleteTextures(n, temp, 0);
		}
		if(this.frameBuffer != -1)
		{
			temp[0] = this.frameBuffer;
			GL.glDeleteFramebuffers(1, temp, 0);
			this.frameBuffer = -1;
		}
	}

	public void resize(int width, int height)
	{
		int[] temp = new int[1];
		this.dispose();
	
		this.bufferWidth = width;
		this.bufferHeight = height;

		GL.glGenFramebuffers(1, temp, 0); this.frameBuffer = temp[0];
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, this.frameBuffer);
		GL.glGenTextures(this.colorTextures.length, this.colorTextures, 0);
		for(int i = 0; i < this.colorTextures.length; i++)
		{
			GL.glBindTexture(GL.GL_TEXTURE_2D, this.colorTextures[i]);
			GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MIN_FILTER, this.textureProperties[i * 4 + 0]);
			GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAG_FILTER, this.textureProperties[i * 4 + 1]);
			GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_S, this.textureProperties[i * 4 + 2]);
			GL.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_T, this.textureProperties[i * 4 + 3]);
			switch(this.colorBuffer)
			{
			case RGBA:
				GL.glTexImage2D(GL.GL_TEXTURE_2D, 0, GL.GL_RGBA, width, height, 0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, null);
				break;
			case RGBAF16:
				GL.glTexImage2D(GL.GL_TEXTURE_2D, 0, GL.GL_RGBA16F, width, height, 0, GL.GL_RGBA, GL.GL_FLOAT, null);
				break;
			case RGBAF32:
				GL.glTexImage2D(GL.GL_TEXTURE_2D, 0, GL.GL_RGBA32F, width, height, 0, GL.GL_RGBA, GL.GL_FLOAT, null);
				break;
			default:
				throw new IllegalArgumentException("Unsupported color buffer type: " + this.colorBuffer);
			}
			this.drawBuffers[i] = GL.GL_COLOR_ATTACHMENT0 + i;
			GL.glFramebufferTexture2D(GL.GL_FRAMEBUFFER, this.drawBuffers[i], GL.GL_TEXTURE_2D, this.colorTextures[i], 0);
			GL.glBindTexture(GL.GL_TEXTURE_2D, 0);
		}
		
		if(this.depthBuffer != Type.NONE)
		{
			GL.glGenRenderbuffers(1, temp, 0); this.depthTexture = temp[0];
			GL.glBindRenderbuffer(GL.GL_RENDERBUFFER, this.depthTexture);
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
			GL.glFramebufferRenderbuffer(GL.GL_FRAMEBUFFER, GL.GL_DEPTH_ATTACHMENT, GL.GL_RENDERBUFFER, this.depthTexture);
		}
		GL.glBindFramebuffer(GL.GL_FRAMEBUFFER, 0);
	}
	
	public enum Type
	{
		/** None */
		NONE,
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

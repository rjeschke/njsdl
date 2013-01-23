/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public final class Math3D
{
    private Math3D() { /* */ }
    
	public final static float radians(final float x)
	{
		return (float)(Math.PI / 180.0) * x;
	}
	
	public final static float radians(final double x)
	{
		return (float)(x * Math.PI / 180.0);
	}
	
	public final static float degrees(final float x)
	{
		return (float)(180.0 / Math.PI) * x;
	}

	public final static float sin(final float x)
	{
		return (float)Math.sin(x);
	}
	
	public final static float cos(final float x)
	{
		return (float)Math.cos(x);
	}

	public final static float tan(final float x)
	{
		return (float)Math.tan(x);
	}

	public final static float asin(final float x)
	{
		return (float)Math.asin(x);
	}
	
	public final static float acos(final float x)
	{
		return (float)Math.acos(x);
	}

	public final static float atan(final float x)
	{
		return (float)Math.atan(x);
	}

	public final static float atan(final float y, final float x)
	{
		return (float)Math.atan2(y, x);
	}

	public final static float pow(final float x, final float y)
	{
		return (float)Math.pow(x, y);
	}
	
	public final static float exp(final float x)
	{
		return (float)Math.exp(x);
	}

	public final static float log(final float x)
	{
		return (float)Math.log(x);
	}

	public final static float exp2(final float x)
	{
		return (float)Math.pow(2, x);
	}

	public final static float log2(final float x)
	{
		return (float)(Math.log(x) / Math.log(2));
	}

	public final static float sqrt(final float x)
	{
		return (float)Math.sqrt(x);
	}

	public final static float inversesqrt(final float x)
	{
		return (float)(1.0 / Math.sqrt(x));
	}

	public final static float abs(final float x)
	{
		return Math.abs(x);
	}
	
	public final static float sign(final float x)
	{
		return x < 0 ? -1.0f : x > 0 ? 1.0f : 0.0f;
	}

	public final static float floor(final float x)
	{
		return (float)Math.floor(x);
	}

	public final static float ceil(final float x)
	{
		return (float)Math.ceil(x);
	}

	public final static float fract(final float x)
	{
		return x - (float)Math.floor(x);
	}

	public final static float mod(final float x, final float y)
	{
		return (float)(x - y * Math.floor(x / y));
	}

	public final static float min(final float a, final float b)
	{
		return a < b ? a : b;
	}

	public final static float max(final float a, final float b)
	{
		return a > b ? a : b;
	}
	
	public final static float clamp(final float x, final float min, final float max)
	{
		return x < min ? min : x > max ? max : x;
	}
	
	public final static double clamp(final double x, final double min, final double max)
	{
		return x < min ? min : x > max ? max : x;
	}

	public final static int clamp(final int x, final int min, final int max)
	{
		return x < min ? min : x > max ? max : x;
	}

	public final static float mix(final float x, final float y, final float a)
	{
		return x + (y - x) * a;
	}
	
	public final static float step(final float edge, final float x)
	{
		return x < edge ? 0 : 1;
	}
	
	public final static float smoothstep(final float edge0, final float edge1, final float x)
	{
	    final float y = saturate((x - edge0) / (edge1 - edge0));
		return y * y * (3.0f - 2.0f * y);
	}
	
	public final static float saturate(final float x)
	{
		return x < 0.0f ? 0.0f : x > 1.0f ? 1.0f : x;
	}
	
	public final static float lerp(final float x, final float y, final float a)
	{
		return x + (y - x) * a;
	}

	public final static Vec3 reflect(final Vec3 i, final Vec3 n)
	{
		return i.clone().subScaled(n, 2.0f * n.dot(i));
	}

	public final static Vec3 refract(final Vec3 i, final Vec3 n, final float eta)
	{
	    final float d = n.dot(i);
	    final float k = 1.0f - eta * eta * (1.0f - d * d);
		if(k < 0)
			return new Vec3(0, 0, 0);
		return i.clone().scale(eta).subScaled(n, eta * d + Math3D.sqrt(k));
	}
	
	public final static Mat4 matrixLookAtLH(final Vec3 pos, final Vec3 lookat, final Vec3 up)
	{
	    final float[] ret = new float[16];
		final Vec3 zaxis = lookat.clone().sub(pos).normalize(); 
		final Vec3 xaxis = up.clone().cross(zaxis).normalize();
		final Vec3 yaxis = zaxis.clone().cross(xaxis).normalize();

		ret[Mat4.M00] = xaxis.getX();
		ret[Mat4.M01] = xaxis.getY();
		ret[Mat4.M02] = xaxis.getZ();
		ret[Mat4.M03] = -xaxis.dot(pos);
		
		ret[Mat4.M10] = yaxis.getX();
		ret[Mat4.M11] = yaxis.getY();
		ret[Mat4.M12] = yaxis.getZ();
		ret[Mat4.M13] = -yaxis.dot(pos);

		ret[Mat4.M20] = zaxis.getX();
		ret[Mat4.M21] = zaxis.getY();
		ret[Mat4.M22] = zaxis.getZ();
		ret[Mat4.M23] = -zaxis.dot(pos);

		ret[Mat4.M33] = 1.0f;
		
		return new Mat4(ret);
	}

	public final static Mat4 matrixLookAtRH(final Vec3 pos, final Vec3 lookat, final Vec3 up)
	{
	    final float[] ret = new float[16];
		final Vec3 zaxis = pos.clone().sub(lookat).normalize(); 
		final Vec3 xaxis = up.clone().cross(zaxis).normalize();
		final Vec3 yaxis = zaxis.clone().cross(xaxis);

		ret[Mat4.M00] = xaxis.getX();
		ret[Mat4.M01] = xaxis.getY();
		ret[Mat4.M02] = xaxis.getZ();
		ret[Mat4.M03] = -xaxis.dot(pos);
		
		ret[Mat4.M10] = yaxis.getX();
		ret[Mat4.M11] = yaxis.getY();
		ret[Mat4.M12] = yaxis.getZ();
		ret[Mat4.M13] = -yaxis.dot(pos);

		ret[Mat4.M20] = zaxis.getX();
		ret[Mat4.M21] = zaxis.getY();
		ret[Mat4.M22] = zaxis.getZ();
		ret[Mat4.M23] = -zaxis.dot(pos);

		ret[Mat4.M33] = 1.0f;
		
		return new Mat4(ret);
	}

	public final static Mat4 matrixProjectionLH(final float fov, final float aspect, final float near_z, final float far_z)
	{
		final float[] ret = new float[16];
		final float yscale = 1.0f / (float)Math.tan(fov * 0.5f), t = 1.0f / (far_z - near_z);
		final float xscale = yscale / aspect;
		
		ret[Mat4.M00] = xscale; 

		ret[Mat4.M11] = yscale; 

		ret[Mat4.M22] = far_z * t; 
		ret[Mat4.M23] = (-near_z * far_z) * t; 

		ret[Mat4.M32] = 1.0f;
		
		return new Mat4(ret);
	} 

	public final static Mat4 matrixProjectionRH(final float fov, final float aspect, final float near_z, final float far_z)
	{
	    final float[] ret = new float[16];
	    final float yscale = 1.0f / (float)Math.tan(fov * 0.5f), t = 1.0f / (far_z - near_z);
	    final float xscale = yscale / aspect;
		
		ret[Mat4.M00] = xscale; 

		ret[Mat4.M11] = yscale; 

		ret[Mat4.M22] = far_z * t; 
		ret[Mat4.M23] = (-near_z * far_z) * t; 

		ret[Mat4.M32] = -1.0f;
		
		return new Mat4(ret);
	}
	
	public final static Mat4 matrixTranslate(final float x, final float y, final float z)
	{
	    final float[] ret = new float[16];
		ret[Mat4.M00] = 1.0f;
		ret[Mat4.M11] = 1.0f;
		ret[Mat4.M22] = 1.0f;
		ret[Mat4.M33] = 1.0f;

		ret[Mat4.M03] = x;
		ret[Mat4.M13] = y;
		ret[Mat4.M23] = z;
		return new Mat4(ret);
	}
	
	public final static Mat4 matrixScale(final float x, final float y, final float z)
	{
	    final float[] ret = new float[16];
		ret[Mat4.M00] = x;
		ret[Mat4.M11] = y;
		ret[Mat4.M22] = z;
		ret[Mat4.M33] = 1.0f;
		return new Mat4(ret);
	}

	public final static Mat4 matrixUniformScale(final float s)
	{
	    final float[] ret = new float[16];
		ret[Mat4.M00] = s;
		ret[Mat4.M11] = s;
		ret[Mat4.M22] = s;
		ret[Mat4.M33] = 1.0f;
		return new Mat4(ret);
	}

	public final static Mat4 matrixRotateX(final float a)
	{
	    final float[] ret = new float[16];
	    final float sn = (float)Math.sin(a);
	    final float cs = (float)Math.cos(a);
		
		ret[Mat4.M11] = cs;
		ret[Mat4.M21] = sn;
		ret[Mat4.M12] = -sn;
		ret[Mat4.M22] = cs;

		ret[Mat4.M00] = 1.0f;
		ret[Mat4.M33] = 1.0f;
		
		return new Mat4(ret);
	}

	public final static Mat4 matrixRotateY(final float a)
	{
	    final float[] ret = new float[16];
	    final float sn = (float)Math.sin(a);
	    final float cs = (float)Math.cos(a);
		
		ret[Mat4.M00] = cs;
		ret[Mat4.M20] = -sn;
		ret[Mat4.M02] = sn;
		ret[Mat4.M22] = cs;

		ret[Mat4.M11] = 1.0f;
		ret[Mat4.M33] = 1.0f;

		return new Mat4(ret);
	}

	public final static Mat4 matrixRotateZ(final float a)
	{
	    final float[] ret = new float[16];
	    final float sn = (float)Math.sin(a);
	    final float cs = (float)Math.cos(a);
		
		ret[Mat4.M00] = cs;
		ret[Mat4.M10] = sn;
		ret[Mat4.M01] = -sn;
		ret[Mat4.M11] = cs;

		ret[Mat4.M22] = 1.0f;
		ret[Mat4.M33] = 1.0f;
		
		return new Mat4(ret);
	}
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class Vec3
{
    protected final float[] data = new float[3];
	
	public Vec3(final float x, final float y, final float z)
	{
		this.data[0] = x;
		this.data[1] = y;
		this.data[2] = z;
	}

	public Vec3(final Vec2 v, final float z)
	{
        this.data[0] = v.getX();
        this.data[1] = v.getY();
        this.data[2] = z;
	}

	public float getX()
	{
		return this.data[0];
	}
	
	public float getY()
	{
		return this.data[1];
	}

	public float getZ()
	{
		return this.data[2];
	}

	public Vec2 getXY()
	{
		return new Vec2(this.data[0], this.data[1]);
	}

    public Vec3 set(final float x, final float y, final float z)
    {
        this.data[0] = x;
        this.data[1] = y;
        this.data[2] = z;
        return this;
    }
    
	@Override
    public Vec3 clone()
	{
	    return new Vec3(this.data[0], this.data[1], this.data[2]);
	}
	
	public Vec3 addScaled(final Vec3 v, final float f)
	{
	    this.data[0] += v.data[0] * f;
	    this.data[1] += v.data[1] * f;
	    this.data[2] += v.data[2] * f;
	    return this;
	}
	
    public Vec3 subScaled(final Vec3 v, final float f)
    {
        this.data[0] -= v.data[0] * f;
        this.data[1] -= v.data[1] * f;
        this.data[2] -= v.data[2] * f;
        return this;
    }

    public Vec3 add(final Vec3 v)
	{
        this.data[0] += v.data[0];
        this.data[1] += v.data[1];
        this.data[2] += v.data[2];
        return this;
	}
	
	public Vec3 mul(final Vec3 v)
	{
        this.data[0] *= v.data[0];
        this.data[1] *= v.data[1];
        this.data[2] *= v.data[2];
        return this;
	}

	public Vec3 sub(final Vec3 v)
	{
        this.data[0] -= v.data[0];
        this.data[1] -= v.data[1];
        this.data[2] -= v.data[2];
        return this;
	}
	
	public Vec3 scale(final float f)
	{
        this.data[0] *= f;
        this.data[1] *= f;
        this.data[2] *= f;
        return this;
	}

	public float length()
	{
		return (float)Math.sqrt(this.data[0] * this.data[0] + this.data[1] * this.data[1] + this.data[2] * this.data[2]);
	}

	public float dot(final Vec3 v)
	{
		return this.data[0] * v.data[0] + this.data[1] * v.data[1] + this.data[2] * v.data[2];
	}
	
	public float dot()
	{
		return this.data[0] * this.data[0] + this.data[1] * this.data[1] + this.data[2] * this.data[2];
	}

	public Vec3 normalize()
	{
	    final float len = this.length();
		if(len > 0)
		{
	        this.data[0] /= len;
	        this.data[1] /= len;
	        this.data[2] /= len;
		}
		return this;
	}
	
	public Vec3 negate()
	{
	    this.data[0] = -this.data[0];
	    this.data[1] = -this.data[1];
	    this.data[2] = -this.data[2];
		return this;
	}
	
	public Vec3 cross(final Vec3 v)
	{
		final float x = this.data[1] * v.data[2] - this.data[2] * v.data[1];
		final float z = this.data[0] * v.data[1] - this.data[1] * v.data[0];
		final float y = this.data[2] * v.data[0] - this.data[0] * v.data[2];
		
		this.data[0] = x;
		this.data[1] = y;
		this.data[2] = z;
		
		return this;
	}

	@Override
	public String toString()
	{
		return "(" + this.data[0] + ", " + this.data[1] + ", " + this.data[2] + ")";
	}
	
	public Vec3 rotateY(double angle)
	{
	    final float c = (float)Math.cos(angle);
	    final float s = (float)Math.sin(angle);
	    final float nx = this.data[0] * c - this.data[2] * s;
	    final float nz = this.data[0] * s + this.data[2] * c;
        this.data[0] = nx;
        this.data[2] = nz;
        return this;
	}
	
	public boolean epsilonEquals(final Vec3 other, final float epsilonSquared)
	{
		final float dx = this.data[0] - other.data[0];
		final float dy = this.data[1] - other.data[1];
		final float dz = this.data[2] - other.data[2];
		return dx * dx + dy * dy + dz * dz < epsilonSquared;
	}
}

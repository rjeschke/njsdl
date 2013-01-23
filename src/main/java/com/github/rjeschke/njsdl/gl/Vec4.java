/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class Vec4
{
    protected final float[] data = new float[4];
	
	protected Vec4()
	{
		//
	}

    public Vec4(final float x, final float y, final float z, final float w)
    {
        this.data[0] = x;
        this.data[1] = y;
        this.data[2] = z;
        this.data[3] = w;
    }

	public Vec4(final Vec3 v, final float w)
	{
	    this.data[0] = v.getX();
	    this.data[1] = v.getY();
	    this.data[2] = v.getZ();
	    this.data[3] = w;
	}
	
	public float getW()
	{
		return this.data[3];
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

    public Vec3 getXYZ()
    {
        return new Vec3(this.data[0], this.data[1], this.data[2]);
    }
    
    public Vec3 toVec3()
    {
        return new Vec3(this.data[0] / this.data[3], this.data[1] / this.data[3], this.data[2] / this.data[3]);
    }
    
    public Vec4 set(final float x, final float y, final float z, final float w)
    {
        this.data[0] = x;
        this.data[1] = y;
        this.data[2] = z;
        this.data[3] = w;
        return this;
    }

	public Vec4 addScaled(final Vec4 v, final float f)
	{
        this.data[0] += v.data[0] * f;
        this.data[1] += v.data[1] * f;
        this.data[2] += v.data[2] * f;
        this.data[3] += v.data[3] * f;
        return this;
	}

	public Vec4 add(final Vec4 v)
	{
        this.data[0] += v.data[0];
        this.data[1] += v.data[1];
        this.data[2] += v.data[2];
        this.data[3] += v.data[3];
        return this;
	}
	
	public Vec4 mul(final Vec4 v)
	{
        this.data[0] *= v.data[0];
        this.data[1] *= v.data[1];
        this.data[2] *= v.data[2];
        this.data[3] *= v.data[3];
        return this;
	}

	public Vec4 sub(final Vec4 v)
	{
        this.data[0] -= v.data[0];
        this.data[1] -= v.data[1];
        this.data[2] -= v.data[2];
        this.data[3] -= v.data[3];
        return this;
	}
	
	public Vec4 scale(final float f)
	{
        this.data[0] *= f;
        this.data[1] *= f;
        this.data[2] *= f;
        this.data[3] *= f;
        return this;
	}

	public float length()
	{
		return (float)Math.sqrt(this.data[0] * this.data[0] + this.data[1] * this.data[1] + this.data[2] * this.data[2] + this.data[3] * this.data[3]);
	}

	public float dot(final Vec4 v)
	{
		return this.data[0] * v.data[0] + this.data[1] * v.data[1] + this.data[2] * v.data[2] + this.data[3] * v.data[3];
	}
	
	@Override
	public String toString()
	{
		return "(" + this.data[0] + ", " + this.data[1] + ", " + this.data[2] + ", " + this.data[3] + ")";
	}
}

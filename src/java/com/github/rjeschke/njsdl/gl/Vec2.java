/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class Vec2
{
	protected final float[] data = new float[2];
	
	public Vec2(final float x, final float y)
	{
	    this.data[0] = x;
	    this.data[1] = y;
	}
	
	public float getX()
	{
		return this.data[0];
	}
	
	public float getY()
	{
		return this.data[1];
	}

	public Vec2 set(final float x, final float y)
    {
        this.data[0] = x;
        this.data[1] = y;
        return this;
    }
	
	@Override
    public Vec2 clone()
	{
	    return new Vec2(this.data[0], this.data[1]);
	}
	
	public Vec2 add(final Vec2 v)
	{
	    this.data[0] += v.data[0];
	    this.data[1] += v.data[1];
	    return this;
	}
	
	public Vec2 mul(final Vec2 v)
	{
        this.data[0] *= v.data[0];
        this.data[1] *= v.data[1];
        return this;
	}

	public Vec2 sub(final Vec2 v)
	{
        this.data[0] -= v.data[0];
        this.data[1] -= v.data[1];
        return this;
	}
	
	public Vec2 sphereDist(final Vec2 v)
	{
		final float dx1 = (this.data[0] - v.data[0] + 1) % 1.0f;
		final float dx2 = (this.data[0] - v.data[0] - 1) % 1.0f;
		final float dy1 = (this.data[1] - v.data[1] + 1) % 1.0f;
		final float dy2 = (this.data[1] - v.data[1] - 1) % 1.0f;
		return new Vec2(
				Math.min(Math.abs(dx1), Math.abs(dx2)),
				Math.min(Math.abs(dy1), Math.abs(dy2))
				);
	}

	public Vec2 scale(final float f)
	{
        this.data[0] = this.data[0] * f;
        this.data[1] = this.data[1] * f;
        return this;
	}

	public float length()
	{
		return (float)Math.sqrt(this.data[0] * this.data[0] + this.data[1] * this.data[1]);
	}

	public float dot(final Vec2 v)
	{
		return this.data[0] * v.data[0] + this.data[1] * v.data[1];
	}
	
	public Vec2 normalize()
	{
	    final float len = this.length();
	    if(len > 0)
	    {
            this.data[0] /= len;
            this.data[1] /= len;
	    }
        return this;
	}
	
	@Override
	public String toString()
	{
		return "(" + this.data[0] + ", " + this.data[1] + ")";
	}
}

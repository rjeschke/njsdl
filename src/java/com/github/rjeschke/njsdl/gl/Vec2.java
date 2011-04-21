/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.nio.FloatBuffer;

import com.github.rjeschke.njsdl.Buffers;



public class Vec2
{
	protected final FloatBuffer data = Buffers.newFloat(2);
	
	public Vec2(final float x, final float y)
	{
	    this.data.put(0, x);
	    this.data.put(1, y);
	}
	
	public float getX()
	{
		return this.data.get(0);
	}
	
	public float getY()
	{
		return this.data.get(1);
	}

	public Vec2 set(final float x, final float y)
    {
        this.data.put(0, x);
        this.data.put(1, y);
        return this;
    }
	
	@Override
    public Vec2 clone()
	{
	    return new Vec2(this.data.get(0), this.data.get(1));
	}
	
	public Vec2 add(final Vec2 v)
	{
	    this.data.put(0, this.data.get(0) + v.data.get(0));
	    this.data.put(1, this.data.get(1) + v.data.get(1));
	    return this;
	}
	
	public Vec2 mul(final Vec2 v)
	{
        this.data.put(0, this.data.get(0) * v.data.get(0));
        this.data.put(1, this.data.get(1) * v.data.get(1));
        return this;
	}

	public Vec2 sub(final Vec2 v)
	{
        this.data.put(0, this.data.get(0) - v.data.get(0));
        this.data.put(1, this.data.get(1) - v.data.get(1));
        return this;
	}
	
	public Vec2 sphereDist(final Vec2 v)
	{
		final float dx1 = (this.data.get(0) - v.data.get(0) + 1) % 1.0f;
		final float dx2 = (this.data.get(0) - v.data.get(0) - 1) % 1.0f;
		final float dy1 = (this.data.get(1) - v.data.get(1) + 1) % 1.0f;
		final float dy2 = (this.data.get(1) - v.data.get(1) - 1) % 1.0f;
		return new Vec2(
				Math.min(Math.abs(dx1), Math.abs(dx2)),
				Math.min(Math.abs(dy1), Math.abs(dy2))
				);
	}

	public Vec2 scale(final float f)
	{
        this.data.put(0, this.data.get(0) * f);
        this.data.put(1, this.data.get(1) * f);
        return this;
	}

	public float length()
	{
		return (float)Math.sqrt(this.data.get(0) * this.data.get(0) + this.data.get(1) * this.data.get(1));
	}

	public float dot(final Vec2 v)
	{
		return this.data.get(0) * v.data.get(0) + this.data.get(1) * v.data.get(1);
	}
	
	public Vec2 normalize()
	{
	    final float len = this.length();
	    if(len > 0)
	    {
            this.data.put(0, this.data.get(0) / len);
            this.data.put(1, this.data.get(1) / len);
	    }
        return this;
	}
	
	@Override
	public String toString()
	{
		return "(" + this.data.get(0) + ", " + this.data.get(1) + ")";
	}
}

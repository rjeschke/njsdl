package njsdl.gl;

import java.nio.FloatBuffer;

import njsdl.Buffers;


public class Vec4
{
    protected final FloatBuffer data = Buffers.newFloat(4);
	
	protected Vec4()
	{
		//
	}

    public Vec4(final float x, final float y, final float z, final float w)
    {
        this.data.put(0, x);
        this.data.put(1, y);
        this.data.put(2, z);
        this.data.put(3, w);
    }

	public Vec4(final Vec3 v, final float w)
	{
	    this.data.put(0, v.getX());
	    this.data.put(1, v.getY());
	    this.data.put(2, v.getZ());
	    this.data.put(3, w);
	}
	
	public float getW()
	{
		return this.data.get(3);
	}

	public float getX()
	{
		return this.data.get(0);
	}
	
	public float getY()
	{
		return this.data.get(1);
	}

	public float getZ()
	{
		return this.data.get(2);
	}

    public Vec2 getXY()
    {
        return new Vec2(this.data.get(0), this.data.get(1));
    }

    public Vec3 getXYZ()
    {
        return new Vec3(this.data.get(0), this.data.get(1), this.data.get(2));
    }
    
    public Vec3 toVec3()
    {
        return new Vec3(this.data.get(0) / this.data.get(3), this.data.get(1) / this.data.get(3), this.data.get(2) / this.data.get(3));
    }
    
    public Vec4 set(final float x, final float y, final float z, final float w)
    {
        this.data.put(0, x);
        this.data.put(1, y);
        this.data.put(2, z);
        this.data.put(3, w);
        return this;
    }

	public Vec4 addScaled(final Vec4 v, final float f)
	{
        this.data.put(0, this.data.get(0) + v.data.get(0) * f);
        this.data.put(1, this.data.get(1) + v.data.get(1) * f);
        this.data.put(2, this.data.get(2) + v.data.get(2) * f);
        this.data.put(3, this.data.get(3) + v.data.get(3) * f);
        return this;
	}

	public Vec4 add(final Vec4 v)
	{
        this.data.put(0, this.data.get(0) + v.data.get(0));
        this.data.put(1, this.data.get(1) + v.data.get(1));
        this.data.put(2, this.data.get(2) + v.data.get(2));
        this.data.put(3, this.data.get(3) + v.data.get(3));
        return this;
	}
	
	public Vec4 mul(final Vec4 v)
	{
        this.data.put(0, this.data.get(0) * v.data.get(0));
        this.data.put(1, this.data.get(1) * v.data.get(1));
        this.data.put(2, this.data.get(2) * v.data.get(2));
        this.data.put(3, this.data.get(3) * v.data.get(3));
        return this;
	}

	public Vec4 sub(final Vec4 v)
	{
        this.data.put(0, this.data.get(0) - v.data.get(0));
        this.data.put(1, this.data.get(1) - v.data.get(1));
        this.data.put(2, this.data.get(2) - v.data.get(2));
        this.data.put(3, this.data.get(3) - v.data.get(3));
        return this;
	}
	
	public Vec4 scale(final float f)
	{
        this.data.put(0, this.data.get(0) * f);
        this.data.put(1, this.data.get(1) * f);
        this.data.put(2, this.data.get(2) * f);
        this.data.put(3, this.data.get(3) * f);
        return this;
	}

	public float length()
	{
		return (float)Math.sqrt(this.data.get(0) * this.data.get(0) + this.data.get(1) * this.data.get(1) + this.data.get(2) * this.data.get(2) + this.data.get(3) * this.data.get(3));
	}

	public float dot(final Vec4 v)
	{
		return this.data.get(0) * v.data.get(0) + this.data.get(1) * v.data.get(1) + this.data.get(2) * v.data.get(2) + this.data.get(3) * v.data.get(3);
	}
	
	@Override
	public String toString()
	{
		return "(" + this.data.get(0) + ", " + this.data.get(1) + ", " + this.data.get(2) + ", " + this.data.get(3) + ")";
	}
}

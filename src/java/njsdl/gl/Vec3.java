package njsdl.gl;

import java.nio.FloatBuffer;

import njsdl.Buffers;


public class Vec3
{
    protected final FloatBuffer data = Buffers.newFloat(3);
	
	public Vec3(final float x, final float y, final float z)
	{
		this.data.put(0, x);
		this.data.put(1, y);
		this.data.put(2, z);
	}

	public Vec3(final Vec2 v, final float z)
	{
        this.data.put(0, v.getX());
        this.data.put(1, v.getY());
        this.data.put(2, z);
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

    public Vec3 set(final float x, final float y, final float z)
    {
        this.data.put(0, x);
        this.data.put(1, y);
        this.data.put(2, z);
        return this;
    }
    
	@Override
    public Vec3 clone()
	{
	    return new Vec3(this.data.get(0), this.data.get(1), this.data.get(2));
	}
	
	public Vec3 addScaled(final Vec3 v, final float f)
	{
	    this.data.put(0, this.data.get(0) + v.data.get(0) * f);
	    this.data.put(1, this.data.get(1) + v.data.get(1) * f);
	    this.data.put(2, this.data.get(2) + v.data.get(2) * f);
	    return this;
	}
	
    public Vec3 subScaled(final Vec3 v, final float f)
    {
        this.data.put(0, this.data.get(0) - v.data.get(0) * f);
        this.data.put(1, this.data.get(1) - v.data.get(1) * f);
        this.data.put(2, this.data.get(2) - v.data.get(2) * f);
        return this;
    }

    public Vec3 add(final Vec3 v)
	{
        this.data.put(0, this.data.get(0) + v.data.get(0));
        this.data.put(1, this.data.get(1) + v.data.get(1));
        this.data.put(2, this.data.get(2) + v.data.get(2));
        return this;
	}
	
	public Vec3 mul(final Vec3 v)
	{
        this.data.put(0, this.data.get(0) * v.data.get(0));
        this.data.put(1, this.data.get(1) * v.data.get(1));
        this.data.put(2, this.data.get(2) * v.data.get(2));
        return this;
	}

	public Vec3 sub(final Vec3 v)
	{
        this.data.put(0, this.data.get(0) - v.data.get(0));
        this.data.put(1, this.data.get(1) - v.data.get(1));
        this.data.put(2, this.data.get(2) - v.data.get(2));
        return this;
	}
	
	public Vec3 scale(final float f)
	{
        this.data.put(0, this.data.get(0) * f);
        this.data.put(1, this.data.get(1) * f);
        this.data.put(2, this.data.get(2) * f);
        return this;
	}

	public float length()
	{
		return (float)Math.sqrt(this.data.get(0) * this.data.get(0) + this.data.get(1) * this.data.get(1) + this.data.get(2) * this.data.get(2));
	}

	public float dot(final Vec3 v)
	{
		return this.data.get(0) * v.data.get(0) + this.data.get(1) * v.data.get(1) + this.data.get(2) * v.data.get(2);
	}
	
	public float dot()
	{
		return this.data.get(0) * this.data.get(0) + this.data.get(1) * this.data.get(1) + this.data.get(2) * this.data.get(2);
	}

	public Vec3 normalize()
	{
	    final float len = this.length();
		if(len > 0)
		{
	        this.data.put(0, this.data.get(0) / len);
	        this.data.put(1, this.data.get(1) / len);
	        this.data.put(2, this.data.get(2) / len);
		}
		return this;
	}
	
	public Vec3 negate()
	{
	    this.data.put(0, -this.data.get(0));
	    this.data.put(1, -this.data.get(1));
	    this.data.put(2, -this.data.get(2));
		return this;
	}
	
	public Vec3 cross(final Vec3 v)
	{
		final float x = this.data.get(1) * v.data.get(2) - this.data.get(2) * v.data.get(1);
		final float y = this.data.get(2) * v.data.get(0) - this.data.get(0) * v.data.get(2);
		final float z = this.data.get(0) * v.data.get(1) - this.data.get(1) * v.data.get(0);
		
		this.data.put(0, x);
		this.data.put(1, y);
		this.data.put(2, z);
		
		return this;
	}

	@Override
	public String toString()
	{
		return "(" + this.data.get(0) + ", " + this.data.get(1) + ", " + this.data.get(2) + ")";
	}
	
	public Vec3 rotateY(double angle)
	{
	    final float c = (float)Math.cos(angle);
	    final float s = (float)Math.sin(angle);
	    final float nx = this.data.get(0) * c - this.data.get(2) * s;
	    final float nz = this.data.get(0) * s + this.data.get(2) * c;
        this.data.put(0, nx);
        this.data.put(2, nz);
        return this;
	}
	
	public boolean epsilonEquals(final Vec3 other, final float epsilonSquared)
	{
		final float dx = this.data.get(0) - other.data.get(0);
		final float dy = this.data.get(1) - other.data.get(1);
		final float dz = this.data.get(2) - other.data.get(2);
		return dx * dx + dy * dy + dz * dz < epsilonSquared;
	}
}

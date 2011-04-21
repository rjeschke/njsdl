/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.nio.FloatBuffer;

import com.github.rjeschke.njsdl.Buffers;



public class Mat4
{
	public final static int M00 = 0 * 4 + 0;
	public final static int M01 = 1 * 4 + 0;
	public final static int M02 = 2 * 4 + 0;
	public final static int M03 = 3 * 4 + 0;
	public final static int M10 = 0 * 4 + 1;
	public final static int M11 = 1 * 4 + 1;
	public final static int M12 = 2 * 4 + 1;
	public final static int M13 = 3 * 4 + 1;
	public final static int M20 = 0 * 4 + 2;
	public final static int M21 = 1 * 4 + 2;
	public final static int M22 = 2 * 4 + 2;
	public final static int M23 = 3 * 4 + 2;
	public final static int M30 = 0 * 4 + 3;
	public final static int M31 = 1 * 4 + 3;
	public final static int M32 = 2 * 4 + 3;
	public final static int M33 = 3 * 4 + 3;
	protected final FloatBuffer data = Buffers.newFloat(16);

	public final static Mat4 IDENTITY = Mat4.identity();
	
	private Mat4()
	{
		//
	}
	
	public Mat4(final float[] m, boolean transpose)
	{
	    if(transpose)
	    {
            for(int y = 0; y < 4; y++)
            {
                for(int x = 0; x < 4; x++)
                {
                    this.data.put(y * 4 + x, m[x * 4 + y]);
                }
            }
	    }
        else
        {
            this.data.put(m);
            this.data.rewind();
        }
	}

    public Mat4(final float[] m)
    {
        this(m, false);
    }

    private static Mat4 identity()
	{
		final Mat4 mat = new Mat4();
		mat.data.put(M00, 1.0f);
		mat.data.put(M11, 1.0f);
		mat.data.put(M22, 1.0f);
		mat.data.put(M33, 1.0f);
		return mat;
	}

	public float determinant()
	{
		final float s0 = this.data.get(M00) * this.data.get(M11) - this.data.get(M01) * this.data.get(M10);
		final float s1 = this.data.get(M00) * this.data.get(M12) - this.data.get(M02) * this.data.get(M10);
		final float s2 = this.data.get(M00) * this.data.get(M13) - this.data.get(M03) * this.data.get(M10);
		final float s3 = this.data.get(M01) * this.data.get(M12) - this.data.get(M02) * this.data.get(M13);
		final float s4 = this.data.get(M01) * this.data.get(M13) - this.data.get(M03) * this.data.get(M11);
		final float s5 = this.data.get(M02) * this.data.get(M13) - this.data.get(M03) * this.data.get(M12);
		
		final float c5 = this.data.get(M22) * this.data.get(M33) - this.data.get(M23) * this.data.get(M32);
		final float c4 = this.data.get(M21) * this.data.get(M33) - this.data.get(M23) * this.data.get(M31);
		final float c3 = this.data.get(M21) * this.data.get(M32) - this.data.get(M22) * this.data.get(M31);
		final float c2 = this.data.get(M20) * this.data.get(M33) - this.data.get(M23) * this.data.get(M30);
		final float c1 = this.data.get(M20) * this.data.get(M32) - this.data.get(M22) * this.data.get(M30);
		final float c0 = this.data.get(M20) * this.data.get(M31) - this.data.get(M21) * this.data.get(M30);
		
		return s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
	}
	
	public Mat4 adjugate()
	{
		final float s0 = this.data.get(M00) * this.data.get(M11) - this.data.get(M01) * this.data.get(M10);
		final float s1 = this.data.get(M00) * this.data.get(M12) - this.data.get(M02) * this.data.get(M10);
		final float s2 = this.data.get(M00) * this.data.get(M13) - this.data.get(M03) * this.data.get(M10);
		final float s3 = this.data.get(M01) * this.data.get(M12) - this.data.get(M02) * this.data.get(M13);
		final float s4 = this.data.get(M01) * this.data.get(M13) - this.data.get(M03) * this.data.get(M11);
		final float s5 = this.data.get(M02) * this.data.get(M13) - this.data.get(M03) * this.data.get(M12);
		
		final float c5 = this.data.get(M22) * this.data.get(M33) - this.data.get(M23) * this.data.get(M32);
		final float c4 = this.data.get(M21) * this.data.get(M33) - this.data.get(M23) * this.data.get(M31);
		final float c3 = this.data.get(M21) * this.data.get(M32) - this.data.get(M22) * this.data.get(M31);
		final float c2 = this.data.get(M20) * this.data.get(M33) - this.data.get(M23) * this.data.get(M30);
		final float c1 = this.data.get(M20) * this.data.get(M32) - this.data.get(M22) * this.data.get(M30);
		final float c0 = this.data.get(M20) * this.data.get(M31) - this.data.get(M21) * this.data.get(M30);

		final Mat4 mat = new Mat4();
		
		mat.data.put(M00,  this.data.get(M11) * c5 - this.data.get(M12) * c4 + this.data.get(M13) * c3);
		mat.data.put(M01, -this.data.get(M01) * c5 + this.data.get(M02) * c4 - this.data.get(M03) * c3);
		mat.data.put(M02,  this.data.get(M31) * s5 - this.data.get(M32) * s4 + this.data.get(M33) * s3);
		mat.data.put(M03, -this.data.get(M21) * s5 + this.data.get(M22) * s4 - this.data.get(M23) * s3);
		
		mat.data.put(M10, -this.data.get(M10) * c5 + this.data.get(M12) * c2 - this.data.get(M13) * c1);
		mat.data.put(M11,  this.data.get(M00) * c5 - this.data.get(M02) * c2 + this.data.get(M03) * c1);
		mat.data.put(M12, -this.data.get(M30) * s5 + this.data.get(M32) * s2 - this.data.get(M33) * s1);
		mat.data.put(M13,  this.data.get(M20) * s5 - this.data.get(M22) * s2 + this.data.get(M23) * s1);

		mat.data.put(M20,  this.data.get(M10) * c4 - this.data.get(M11) * c2 + this.data.get(M13) * c0);
		mat.data.put(M21, -this.data.get(M00) * c4 + this.data.get(M01) * c2 - this.data.get(M03) * c0);
		mat.data.put(M22,  this.data.get(M30) * s4 - this.data.get(M31) * s2 + this.data.get(M33) * s0);
		mat.data.put(M23, -this.data.get(M20) * s4 + this.data.get(M21) * s2 - this.data.get(M23) * s0);

		mat.data.put(M30, -this.data.get(M10) * c3 + this.data.get(M11) * c1 - this.data.get(M12) * c0);
		mat.data.put(M31,  this.data.get(M00) * c3 - this.data.get(M01) * c1 + this.data.get(M02) * c0);
		mat.data.put(M32, -this.data.get(M30) * s3 + this.data.get(M31) * s1 - this.data.get(M32) * s0);
		mat.data.put(M33,  this.data.get(M20) * s3 - this.data.get(M21) * s1 + this.data.get(M22) * s0);

		return mat;
	}

	public Mat4 inverse()
	{
		final float s0 = this.data.get(M00) * this.data.get(M11) - this.data.get(M01) * this.data.get(M10);
		final float s1 = this.data.get(M00) * this.data.get(M12) - this.data.get(M02) * this.data.get(M10);
		final float s2 = this.data.get(M00) * this.data.get(M13) - this.data.get(M03) * this.data.get(M10);
		final float s3 = this.data.get(M01) * this.data.get(M12) - this.data.get(M02) * this.data.get(M13);
		final float s4 = this.data.get(M01) * this.data.get(M13) - this.data.get(M03) * this.data.get(M11);
		final float s5 = this.data.get(M02) * this.data.get(M13) - this.data.get(M03) * this.data.get(M12);
		
		final float c5 = this.data.get(M22) * this.data.get(M33) - this.data.get(M23) * this.data.get(M32);
		final float c4 = this.data.get(M21) * this.data.get(M33) - this.data.get(M23) * this.data.get(M31);
		final float c3 = this.data.get(M21) * this.data.get(M32) - this.data.get(M22) * this.data.get(M31);
		final float c2 = this.data.get(M20) * this.data.get(M33) - this.data.get(M23) * this.data.get(M30);
		final float c1 = this.data.get(M20) * this.data.get(M32) - this.data.get(M22) * this.data.get(M30);
		final float c0 = this.data.get(M20) * this.data.get(M31) - this.data.get(M21) * this.data.get(M30);

		final Mat4 mat = new Mat4();
		final float rcpdet = 1.0f / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);
		
		mat.data.put(M00, ( this.data.get(M11) * c5 - this.data.get(M12) * c4 + this.data.get(M13) * c3) * rcpdet);
		mat.data.put(M01, (-this.data.get(M01) * c5 + this.data.get(M02) * c4 - this.data.get(M03) * c3) * rcpdet);
		mat.data.put(M02, ( this.data.get(M31) * s5 - this.data.get(M32) * s4 + this.data.get(M33) * s3) * rcpdet);
		mat.data.put(M03, (-this.data.get(M21) * s5 + this.data.get(M22) * s4 - this.data.get(M23) * s3) * rcpdet);
		
		mat.data.put(M10, (-this.data.get(M10) * c5 + this.data.get(M12) * c2 - this.data.get(M13) * c1) * rcpdet);
		mat.data.put(M11, ( this.data.get(M00) * c5 - this.data.get(M02) * c2 + this.data.get(M03) * c1) * rcpdet);
		mat.data.put(M12, (-this.data.get(M30) * s5 + this.data.get(M32) * s2 - this.data.get(M33) * s1) * rcpdet);
		mat.data.put(M13, ( this.data.get(M20) * s5 - this.data.get(M22) * s2 + this.data.get(M23) * s1) * rcpdet);

		mat.data.put(M20, ( this.data.get(M10) * c4 - this.data.get(M11) * c2 + this.data.get(M13) * c0) * rcpdet);
		mat.data.put(M21, (-this.data.get(M00) * c4 + this.data.get(M01) * c2 - this.data.get(M03) * c0) * rcpdet);
		mat.data.put(M22, ( this.data.get(M30) * s4 - this.data.get(M31) * s2 + this.data.get(M33) * s0) * rcpdet);
		mat.data.put(M23, (-this.data.get(M20) * s4 + this.data.get(M21) * s2 - this.data.get(M23) * s0) * rcpdet);

		mat.data.put(M30, (-this.data.get(M10) * c3 + this.data.get(M11) * c1 - this.data.get(M12) * c0) * rcpdet);
		mat.data.put(M31, ( this.data.get(M00) * c3 - this.data.get(M01) * c1 + this.data.get(M02) * c0) * rcpdet);
		mat.data.put(M32, (-this.data.get(M30) * s3 + this.data.get(M31) * s1 - this.data.get(M32) * s0) * rcpdet);
		mat.data.put(M33, ( this.data.get(M20) * s3 - this.data.get(M21) * s1 + this.data.get(M22) * s0) * rcpdet);

		return mat;
	}
	
	public Mat4 transpose()
	{
		final Mat4 mat = new Mat4();
		for(int y = 0; y < 4; y++)
		{
			for(int x = 0; x < 4; x++)
			{
				mat.data.put(y * 4 + x, this.data.get(x * 4 + y));
			}
		}
		return mat;
	}
	
	public Mat4 multiply(final Mat4 mat)
	{
		final Mat4 r = new Mat4();
		
		r.data.put(M00, this.data.get(M00) * mat.data.get(M00) + this.data.get(M01) * mat.data.get(M10) + this.data.get(M02) * mat.data.get(M20) + this.data.get(M03) * mat.data.get(M30));
		r.data.put(M01, this.data.get(M00) * mat.data.get(M01) + this.data.get(M01) * mat.data.get(M11) + this.data.get(M02) * mat.data.get(M21) + this.data.get(M03) * mat.data.get(M31));
		r.data.put(M02, this.data.get(M00) * mat.data.get(M02) + this.data.get(M01) * mat.data.get(M12) + this.data.get(M02) * mat.data.get(M22) + this.data.get(M03) * mat.data.get(M32));
		r.data.put(M03, this.data.get(M00) * mat.data.get(M03) + this.data.get(M01) * mat.data.get(M13) + this.data.get(M02) * mat.data.get(M23) + this.data.get(M03) * mat.data.get(M33));
		
		r.data.put(M10, this.data.get(M10) * mat.data.get(M00) + this.data.get(M11) * mat.data.get(M10) + this.data.get(M12) * mat.data.get(M20) + this.data.get(M13) * mat.data.get(M30));
		r.data.put(M11, this.data.get(M10) * mat.data.get(M01) + this.data.get(M11) * mat.data.get(M11) + this.data.get(M12) * mat.data.get(M21) + this.data.get(M13) * mat.data.get(M31));
		r.data.put(M12, this.data.get(M10) * mat.data.get(M02) + this.data.get(M11) * mat.data.get(M12) + this.data.get(M12) * mat.data.get(M22) + this.data.get(M13) * mat.data.get(M32));
		r.data.put(M13, this.data.get(M10) * mat.data.get(M03) + this.data.get(M11) * mat.data.get(M13) + this.data.get(M12) * mat.data.get(M23) + this.data.get(M13) * mat.data.get(M33));

		r.data.put(M20, this.data.get(M20) * mat.data.get(M00) + this.data.get(M21) * mat.data.get(M10) + this.data.get(M22) * mat.data.get(M20) + this.data.get(M23) * mat.data.get(M30));
		r.data.put(M21, this.data.get(M20) * mat.data.get(M01) + this.data.get(M21) * mat.data.get(M11) + this.data.get(M22) * mat.data.get(M21) + this.data.get(M23) * mat.data.get(M31));
		r.data.put(M22, this.data.get(M20) * mat.data.get(M02) + this.data.get(M21) * mat.data.get(M12) + this.data.get(M22) * mat.data.get(M22) + this.data.get(M23) * mat.data.get(M32));
		r.data.put(M23, this.data.get(M20) * mat.data.get(M03) + this.data.get(M21) * mat.data.get(M13) + this.data.get(M22) * mat.data.get(M23) + this.data.get(M23) * mat.data.get(M33));

		r.data.put(M30, this.data.get(M30) * mat.data.get(M00) + this.data.get(M31) * mat.data.get(M10) + this.data.get(M32) * mat.data.get(M20) + this.data.get(M33) * mat.data.get(M30));
		r.data.put(M31, this.data.get(M30) * mat.data.get(M01) + this.data.get(M31) * mat.data.get(M11) + this.data.get(M32) * mat.data.get(M21) + this.data.get(M33) * mat.data.get(M31));
		r.data.put(M32, this.data.get(M30) * mat.data.get(M02) + this.data.get(M31) * mat.data.get(M12) + this.data.get(M32) * mat.data.get(M22) + this.data.get(M33) * mat.data.get(M32));
		r.data.put(M33, this.data.get(M30) * mat.data.get(M03) + this.data.get(M31) * mat.data.get(M13) + this.data.get(M32) * mat.data.get(M23) + this.data.get(M33) * mat.data.get(M33));

		return r;
	}

	public Mat4 toMatrix3x3()
	{
		final Mat4 ret = new Mat4();
		
		for(int y = 0; y < 4; y++)
		{
			for(int x = 0; x < 4; x++)
			{
				if(x < 3 && y < 3)
				{
					ret.data.put(x + y * 4, this.data.get(x + y * 4));
				}
				else
				{
					if(x == 3 && y == 3)
					{
						ret.data.put(x + y * 4, 1);
					}
					else
					{
						ret.data.put(x + y * 4,  0);
					}
				}
			}
		}
		
		return ret;
	}
	
	public Vec3 multiply(final Vec3 vec)
	{
		final float x = vec.getX();
		final float y = vec.getY();
		final float z = vec.getZ();
		final float rcpw = 1.0f / (x * this.data.get(M30) + y * this.data.get(M31) + z * this.data.get(M32) + this.data.get(M33));
		return new Vec3(
				(x * this.data.get(M00) + y * this.data.get(M01) + z * this.data.get(M02) + this.data.get(M03)) * rcpw,
				(x * this.data.get(M10) + y * this.data.get(M11) + z * this.data.get(M12) + this.data.get(M13)) * rcpw,
				(x * this.data.get(M20) + y * this.data.get(M21) + z * this.data.get(M22) + this.data.get(M23)) * rcpw
				);
	}
	
	public Vec3 multiply3x3(final Vec3 vec)
	{
	    final float x = vec.getX();
	    final float y = vec.getY();
	    final float z = vec.getZ();
		return new Vec3(
				x * this.data.get(M00) + y * this.data.get(M01) + z * this.data.get(M02),
				x * this.data.get(M10) + y * this.data.get(M11) + z * this.data.get(M12),
				x * this.data.get(M20) + y * this.data.get(M21) + z * this.data.get(M22)
				);
	}

	public Vec4 multiply(final Vec4 vec)
	{
	    final float x = vec.getX();
	    final float y = vec.getY();
	    final float z = vec.getZ();
	    final float w = vec.getW();
		return new Vec4(
				x * this.data.get(M00) + y * this.data.get(M01) + z * this.data.get(M02) + w * this.data.get(M03),
				x * this.data.get(M10) + y * this.data.get(M11) + z * this.data.get(M12) + w * this.data.get(M13),
				x * this.data.get(M20) + y * this.data.get(M21) + z * this.data.get(M22) + w * this.data.get(M23),
				x * this.data.get(M30) + y * this.data.get(M31) + z * this.data.get(M32) + w * this.data.get(M33)
				);
	}

	@Override
	public String toString()
	{
		return "{" +
			this.data.get(M00) + ", " + this.data.get(M01) + ", " + this.data.get(M02) + ", " + this.data.get(M03) + "\n" +
			this.data.get(M10) + ", " + this.data.get(M11) + ", " + this.data.get(M12) + ", " + this.data.get(M13) + "\n" +
			this.data.get(M20) + ", " + this.data.get(M21) + ", " + this.data.get(M22) + ", " + this.data.get(M23) + "\n" +
			this.data.get(M30) + ", " + this.data.get(M31) + ", " + this.data.get(M32) + ", " + this.data.get(M33) + "}";
	}
}

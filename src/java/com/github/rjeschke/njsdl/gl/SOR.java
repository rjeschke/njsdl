/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class SOR
{
    private SOR() { /* */ }
    
	public static Point2[] catmullRomSpline(Point2[] points, int steps, final boolean hasExtraPoints)
	{
		double len = 0;
		final double[] p = new double[points.length], d = new double[points.length];
		
		for(int i = hasExtraPoints ? 2 : 1; i < (hasExtraPoints ? points.length - 1 : points.length); i++)
		{
			final double dx = points[i].x - points[i - 1].x;
			final double dy = points[i].y - points[i - 1].y;
			len += Math.sqrt(dx * dx + dy * dy);
			p[i] = len;
		}
		
		for(int i = 0; i < (hasExtraPoints ? points.length - 1 : points.length); i++)
			d[i] = i + 1 < (hasExtraPoints ? points.length - 1 : points.length) ? p[i + 1] - p[i] : 1;
		
		final Point2[] ret = new Point2[steps];
		for(int i = 0; i < steps; i++)
		{
			final double z = len * i / (steps - 1);
			int n = hasExtraPoints ? 1 : 0;
			while(z > p[n] + d[n])
				n++;
			
			final Point2 s0 = n > 0 ? points[n - 1] : points[0];
			final Point2 s1 = points[n];
			final Point2 s2 = n + 1 < points.length ? points[n + 1] : points[points.length - 1];
			final Point2 s3 = n + 2 < points.length ? points[n + 2] : points[points.length - 1];
			ret[i] = spline((z - p[n]) / d[n], s0, s1, s2, s3);
		}
		return ret;
	}
	
	public static Point2 spline(double t, Point2 a, Point2 b, Point2 c, Point2 d)
	{
	    final double t2 = t * t;
	    final double t3 = t * t2;
	    final double f0 = -t + 2.0 * t2 - t3;
	    final double f1 = 2.0 - 5.0 * t2 + 3 * t3;
	    final double f2 = t + 4.0 * t2 - 3 * t3;
	    final double f3 = -t2 + t3;
	    return new Point2(
	    		(a.x * f0 + b.x * f1 + c.x * f2 + d.x * f3) * 0.5, 
	    		(a.y * f0 + b.y * f1 + c.y * f2 + d.y * f3) * 0.5 
	    		);
	}
	
	public static Mesh generateMesh(Point2[] points, int steps)
	{
		return generateMesh(points, steps, false);
	}
	
	public static Mesh generateMesh(Point2[] points, int steps, boolean invert)
	{
		final Mesh mesh = new Mesh(points.length * (steps + 1), (points.length - 1) * steps * 2, 2);
		final float[] tex = new float[points.length];
		
		float len = 0;
		for(int i = 1; i < points.length; i++)
		{
			final double dx = points[i].x - points[i - 1].x;
			final double dy = points[i].y - points[i - 1].y;
			final double l = Math.sqrt(dx * dx + dy * dy);
			len += l;
			tex[i] = len;
		}
		for(int i = 1; i < points.length; i++)
			tex[i] /= len;
		
		final double st = Math.PI * 2.0 / steps;
		for(int n = 0; n <= steps; n++)
		{
			final double s = Math.sin(st * n), c = Math.cos(st * n);
			final float tx = (float)n / (float)steps;
			for(int i = 0; i < points.length; i++)
			{
				final Point2 p = points[i];
				final double x = c * p.x;
				final double y = p.y;
				final double z = s * p.x;
				mesh.setVertex(n * points.length + i, new Vec3((float)x, (float)y, (float)z));
				mesh.setTexCoord(n * points.length + i, 0, tx, tex[i]);
			}
		}
	
		/*
		 * 0 + n    1 + n
		 * 0 + n2   1 + n2
		 * 
		 * 1 + n    0 + n
		 * 1 + n2   0 + n2
		 * 
		 */
		if(invert)
		{
			for(int n = 0; n < steps; n++)
			{
				final int n2 = n + 1;
				for(int i = 0; i < points.length - 1; i++)
				{
					mesh.addFace(
							n * points.length + i + 1, 
							n2 * points.length + i + 1, 
							n2 * points.length + i, 
							n * points.length + i);
				}
			}
		}
		else
		{
			for(int n = 0; n < steps; n++)
			{
				final int n2 = n + 1;
				for(int i = 0; i < points.length - 1; i++)
				{
					mesh.addFace(
							n * points.length + i, 
							n2 * points.length + i, 
							n2 * points.length + i + 1, 
							n * points.length + i + 1);
				}
			}
		}
		
		return mesh;
	}

	public static Point2[] divide(Point2[] points, int steps)
	{
		double len = 0;
		final double[] p = new double[points.length], d = new double[points.length];
		
		for(int i = 1; i < points.length; i++)
		{
			final double dx = points[i].x - points[i - 1].x;
			final double dy = points[i].y - points[i - 1].y;
			len += Math.sqrt(dx * dx + dy * dy);
			p[i] = len;
		}
		
		for(int i = 0; i < points.length; i++)
			d[i] = i + 1 < points.length ? p[i + 1] - p[i] : 1;
		
		final Point2[] ret = new Point2[steps];
		for(int i = 0; i < steps; i++)
		{
			final double z = len * i / (steps - 1);
			int n = 0;
			while(z > p[n] + d[n])
				n++;
			final double t = (z - p[n]) / d[n];
			final Point2 s1 = points[n];
			final Point2 s2 = n + 1 < points.length ? points[n + 1] : points[points.length - 1];
			ret[i] = new Point2(s1.x + (s2.x - s1.x) * t, s1.y + (s2.y - s1.y) * t);
		}
		return ret;
	}

	public static class Point2
	{
		public final double x, y;
		
		public Point2(double x, double y)
		{
			this.x = x;
			this.y = y;
		}
	}
}

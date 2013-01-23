/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.nio.FloatBuffer;
import java.util.ArrayList;
import java.util.Arrays;

import com.github.rjeschke.njsdl.Buffers;


public class Mesh
{
	private final static float EQUAL_EPSILON2 = 1e-6f * 1e-6f;
	private Vec3[] vertices, normals, faceNormals;
	private Face[] faces;
	private float[] texCoord;
	private int[] buildMapping, reverseMapping;
	private int[] adjacentFacesList, adjacentFacesOffset, adjacentFacesLen;
	private int numVertices = 0, numFaces = 0, numTexIndices;
	private boolean finished = false;
	private int[] texOffs = new int[4], texLen = new int[4];
	private int texStride = 0;
	private int vArray = -1, vBuffer = -1;
	private boolean disableDuplicateChecking = false;
	private float deformedTriangleEpsilon = 0, equalEpsilon = EQUAL_EPSILON2;
	private Vec3 minVert, maxVert;
	private FloatBuffer vertexBuffer = null;
	
	public Mesh(final int numVertices, final int numFaces, final int texElements0, final int texElements1, final int texElements2, final int texElements3)
	{
		this.numTexIndices = numVertices;
		this.vertices = new Vec3[numVertices];
		this.faces = new Face[numFaces];
	
		this.texOffs[0] = 0;
		this.texStride += this.texLen[0] = texElements0;
		this.texOffs[1] = this.texStride;
		this.texStride += this.texLen[1] = texElements1;
		this.texOffs[2] = this.texStride;
		this.texStride += this.texLen[2] = texElements2;
		this.texOffs[3] = this.texStride;
		this.texStride += this.texLen[3] = texElements3;
		
		this.texCoord = new float[numVertices * this.texStride];
		this.reverseMapping = new int[numVertices];
		this.buildMapping = new int[numVertices];
		
		this.setDeformedTriangleEpsilon(1e-15f);
	}

	public void setEqualEpsilon(final float epsilon)
	{
		this.equalEpsilon = epsilon * epsilon;
	}
	
	public void setDeformedTriangleEpsilon(final float epsilon)
	{
		this.deformedTriangleEpsilon = epsilon * epsilon;
	}
	
	public Mesh(final int numVertices, final int numFaces, final int texElements0, final int texElements1, final int texElements2)
	{
		this(numVertices, numFaces, texElements0, texElements1, texElements2, 0);
	}
	
	public Mesh(final int numVertices, final int numFaces, final int texElements0, final int texElements1)
	{
		this(numVertices, numFaces, texElements0, texElements1, 0, 0);
	}
	
	public Mesh(final int numVertices, final int numFaces, final int texElements0)
	{
		this(numVertices, numFaces, texElements0, 0, 0, 0);
	}
	
	public Mesh(final int numVertices, final int numFaces)
	{
		this(numVertices, numFaces, 0, 0, 0, 0);
	}

	public int getNumberOfFaces()
	{
		return this.numFaces;
	}
	
	public int getNumberOfVertices()
	{
		return this.numVertices;
	}
	
	public int getNumberOfTextureCoordinates()
	{
		return this.numTexIndices;
	}

	public void finish()
	{
		if(this.finished)
			return;
		this.finished = true;

		// Clear buildMapping
		this.buildMapping = null;
		// Resize arrays (if necessary)
		if(this.numVertices != this.vertices.length)
			this.vertices = Arrays.copyOf(this.vertices, this.numVertices);
		if(this.numFaces != this.faces.length)
			this.faces = Arrays.copyOf(this.faces, this.numFaces);
	
		this.faceNormals = new Vec3[this.numFaces];
		
		this.adjacentFacesList = new int[this.numFaces * 3];
		this.adjacentFacesLen = new int[this.numVertices];
		this.adjacentFacesOffset = new int[this.numVertices];

		final ArrayList<ArrayList<Integer>> connect = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i < this.numVertices; i++)
			connect.add(new ArrayList<Integer>());
		
		for(int n = 0; n < this.numFaces; n++)
		{
			final Face f = this.faces[n];
			connect.get(f.va).add(n | (0 << 29));
			connect.get(f.vb).add(n | (1 << 29));
			connect.get(f.vc).add(n | (2 << 29));
		}
		
		float minx = Float.MAX_VALUE, miny = Float.MAX_VALUE, minz = Float.MAX_VALUE;
		float maxx = Float.MIN_VALUE, maxy = Float.MIN_VALUE, maxz = Float.MIN_VALUE;
		
		int ovr = 0;
		for(int i = 0; i < this.numVertices; i++)
		{
			final Vec3 v = this.vertices[i];
			if(v.getX() < minx) minx = v.getX();
			if(v.getY() < miny) miny = v.getY();
			if(v.getZ() < minz) minz = v.getZ();

			if(v.getX() > maxx) maxx = v.getX();
			if(v.getY() > maxy) maxy = v.getY();
			if(v.getZ() > maxz) maxz = v.getZ();
			
			this.adjacentFacesOffset[i] = ovr;
			ArrayList<Integer> a = connect.get(i);
			for(int n = 0; n < a.size(); n++)
				this.adjacentFacesList[ovr + n] = a.get(n);
			this.adjacentFacesLen[i] = a.size();
			ovr += a.size();
		}

		this.minVert = new Vec3(minx, miny, minz);
		this.maxVert = new Vec3(maxx, maxy, maxz);
		
		if(ovr != this.adjacentFacesList.length)
			this.adjacentFacesList = Arrays.copyOf(this.adjacentFacesList, ovr);
		
		this.normals = new Vec3[this.numFaces * 3];
	}
	
	private void recalcMinMax()
	{
		float minx = Float.MAX_VALUE, miny = Float.MAX_VALUE, minz = Float.MAX_VALUE;
		float maxx = Float.MIN_VALUE, maxy = Float.MIN_VALUE, maxz = Float.MIN_VALUE;

		for(int i = 0; i < this.numVertices; i++)
		{
			final Vec3 v = this.vertices[i];
			
			if(v.getX() < minx) minx = v.getX();
			if(v.getY() < miny) miny = v.getY();
			if(v.getZ() < minz) minz = v.getZ();

			if(v.getX() > maxx) maxx = v.getX();
			if(v.getY() > maxy) maxy = v.getY();
			if(v.getZ() > maxz) maxz = v.getZ();
		}

		this.minVert = new Vec3(minx, miny, minz);
		this.maxVert = new Vec3(maxx, maxy, maxz);
	}
	
	public void center()
	{
		this.recalcMinMax();
		
		Vec3 d = new Vec3(
				(this.maxVert.getX() - this.minVert.getX()) * 0.5f + this.minVert.getX(),
				(this.maxVert.getY() - this.minVert.getY()) * 0.5f + this.minVert.getY(),
				(this.maxVert.getZ() - this.minVert.getZ()) * 0.5f + this.minVert.getZ());

		for(int i = 0; i < this.vertices.length; i++)
		{
			this.vertices[i] = this.vertices[i].sub(d);
		}
		
		this.recalcMinMax();
	}
	
	public Vec3 getMinimum()
	{
		return this.minVert;
	}
	
	public Vec3 getMaximum()
	{
		return this.maxVert;
	}
	
	public void setVertex(final int index, final Vec3 v)
	{
		final int i = this.addVertex(v);
		this.buildMapping[index] = i;
		this.reverseMapping[i] = index;
	}
	
	public void setVertex(final int index, final float x, final float y, final float z)
	{
		final int i = this.addVertex(new Vec3(x, y, z));
		this.buildMapping[index] = i;
		this.reverseMapping[i] = index;
	}
	
	public void setVertex(final int index, final double x, final double y, final double z)
	{
		this.buildMapping[index] = this.addVertex(new Vec3((float)x, (float)y, (float)z));
	}

	public void setTexCoord(final int index, final int number, final float x)
	{
		this.texCoord[index * this.texStride + this.texOffs[number]] = x;
	}
	
	public void setTexCoord(final int index, final int number, final float x, final float y)
	{
		this.texCoord[index * this.texStride + this.texOffs[number]] = x;
		this.texCoord[index * this.texStride + this.texOffs[number] + 1] = y;
	}
	
	public void setTexCoord(final int index, final int number, final float x, final float y, final float z)
	{
		this.texCoord[index * this.texStride + this.texOffs[number]] = x;
		this.texCoord[index * this.texStride + this.texOffs[number] + 1] = y;
		this.texCoord[index * this.texStride + this.texOffs[number] + 2] = z;
	}
	
	public void setTexCoord(final int index, final int number, final float x, final float y, final float z, final float w)
	{
		this.texCoord[index * this.texStride + this.texOffs[number]] = x;
		this.texCoord[index * this.texStride + this.texOffs[number] + 1] = y;
		this.texCoord[index * this.texStride + this.texOffs[number] + 2] = z;
		this.texCoord[index * this.texStride + this.texOffs[number] + 3] = w;
	}
	
	public void addFace(final int a, final int b, final int c)
	{
		final int ma = this.buildMapping[a];
		final int mb = this.buildMapping[b];
		final int mc = this.buildMapping[c];
		
		if(this.vertices[mb].clone().sub(this.vertices[ma]).dot() < this.deformedTriangleEpsilon) return;
		if(this.vertices[mc].clone().sub(this.vertices[mb]).dot() < this.deformedTriangleEpsilon) return;
		if(this.vertices[ma].clone().sub(this.vertices[mc]).dot() < this.deformedTriangleEpsilon) return;
		
		this.faces[this.numFaces++] = 
			new Face(ma, mb, mc, a * this.texStride, b * this.texStride, c * this.texStride);
	}

	public void addFace(final int a, final int b, final int c, final int d)
	{
		this.addFace(a, b, d);
		this.addFace(b, c, d);
	}
	
	public void compile()
	{
		int[] temp = new int[10];
		if(this.vBuffer != -1)
		{
			temp[0] = this.vBuffer;
			GL.glDeleteBuffers(1, temp, 0);
			this.vBuffer = 0;
		}
		if(this.vArray != -1)
		{
			temp[0] = this.vArray;
			GL.glDeleteVertexArrays(1, temp, 0);
			this.vArray = -1;
		}
		
		final int stride = 3 + 3 + this.texStride;
		if(this.vertexBuffer == null)
			this.vertexBuffer = Buffers.newFloat(stride * this.numFaces * 3);
		
		int p = 0;
		for(int i = 0; i < this.numFaces; i++)
		{
			final Face f = this.faces[i];
			Vec3 v, n;
			
			v = this.vertices[f.va];
			n = this.normals[i * 3 + 0];
			this.vertexBuffer.put(p++, v.getX());
			this.vertexBuffer.put(p++, v.getY());
			this.vertexBuffer.put(p++, v.getZ());
			this.vertexBuffer.put(p++, n.getX());
			this.vertexBuffer.put(p++, n.getY());
			this.vertexBuffer.put(p++, n.getZ());
			for(int t = 0; t < this.texStride; t++)
				this.vertexBuffer.put(p++, this.texCoord[f.ta + t]);
			
			v = this.vertices[f.vb];
			n = this.normals[i * 3 + 1];
			this.vertexBuffer.put(p++, v.getX());
			this.vertexBuffer.put(p++, v.getY());
			this.vertexBuffer.put(p++, v.getZ());
			this.vertexBuffer.put(p++, n.getX());
			this.vertexBuffer.put(p++, n.getY());
			this.vertexBuffer.put(p++, n.getZ());
			for(int t = 0; t < this.texStride; t++)
				this.vertexBuffer.put(p++, this.texCoord[f.tb + t]);

			v = this.vertices[f.vc];
			n = this.normals[i * 3 + 2];
			this.vertexBuffer.put(p++, v.getX());
			this.vertexBuffer.put(p++, v.getY());
			this.vertexBuffer.put(p++, v.getZ());
			this.vertexBuffer.put(p++, n.getX());
			this.vertexBuffer.put(p++, n.getY());
			this.vertexBuffer.put(p++, n.getZ());
			for(int t = 0; t < this.texStride; t++)
				this.vertexBuffer.put(p++, this.texCoord[f.tc + t]);
		}
		
		GL.glGenVertexArrays(1, temp, 0);
		GL.glBindVertexArray(temp[0]);
		GL.glGenBuffers(1, temp, 1);
		GL.glBindBuffer(GL.GL_ARRAY_BUFFER, temp[1]);
		GL.glBufferData(GL.GL_ARRAY_BUFFER, this.numFaces * stride * 12, this.vertexBuffer, GL.GL_STATIC_DRAW);
		GL.glVertexAttribPointer(0, 3, GL.GL_FLOAT, false, stride * 4, 0);
		GL.glEnableVertexAttribArray(0);
		GL.glVertexAttribPointer(1, 3, GL.GL_FLOAT, false, stride * 4, 3 * 4);
		GL.glEnableVertexAttribArray(1);
		
		int offs = 6 * 4;
		for(int i = 0; i < 4; i++)
		{
			if(this.texLen[i] > 0)
			{
				GL.glVertexAttribPointer(i + 2, this.texLen[i], GL.GL_FLOAT, false, stride * 4, offs);
				GL.glEnableVertexAttribArray(i + 2);
				offs += this.texLen[i] * 4;
			}
		}
		GL.glBindVertexArray(0);
		
		this.vArray = temp[0];
		this.vBuffer = temp[1];
	}
	
	public void bindRender()
	{
		GL.glBindVertexArray(this.vArray);
		GL.glDrawArrays(GL.GL_TRIANGLES, 0, this.numFaces * 3);
	}

	public void bind()
	{
		GL.glBindVertexArray(this.vArray);
	}
	
	public void render()
	{
		GL.glDrawArrays(GL.GL_TRIANGLES, 0, this.numFaces * 3);
	}

	public void render(int numInstances)
	{
		GL.glDrawArraysInstanced(GL.GL_TRIANGLES, 0, this.numFaces * 3, numInstances);
	}

	public void unbind()
	{
		GL.glBindVertexArray(0);
	}

	/*
	 * FIXME !
	public void displacement(final XImage image, final float strength, final int tex)
	{
		this.calculateFaceNormals();
		
		final Vec3[] normals = new Vec3[this.numVertices];
		for(int i = 0; i < normals.length; i++)
			normals[i] = new Vec3(0, 0, 0);
		
		// FIXME ... use adjacency information and faceNormal
		for(int i = 0; i < this.numFaces; i++)
		{
			final Face f = this.faces[i];
			normals[f.va].add(this.smoothNormal(f.va));
			normals[f.vb].add(this.smoothNormal(f.vb));
			normals[f.vc].add(this.smoothNormal(f.vc));
		}
		
		for(int i = 0; i < normals.length; i++)
			normals[i].normalize();

		for(int i = 0; i < this.vertices.length; i++)
		{
			final int t = this.reverseMapping[i] * this.texStride + this.texOffs[tex];
			final int c = image.getPixelIF(this.texCoord[t], this.texCoord[t + 1]);
			final int b =  c        & 255;
			final int g = (c >>  8) & 255;
			final int r = (c >> 16) & 255;
			final double fl = (r * 0.3 + g * 0.6 + b * 0.1 - 128) / 128.0;
			this.vertices[i] = this.vertices[i].clone().addScaled(normals[i], (float)fl * strength);
		}
	}
	*/
	
	public void scale(final double sx, final double sy, final double sz)
	{
	    final Vec3 m = new Vec3((float)sx, (float)sy, (float)sz);
		for(int i = 0; i < this.vertices.length; i++)
		{
			this.vertices[i].mul(m); 
		}
	}
	
	public void transform(final Mat4 matrix)
	{
		for(int i = 0; i < this.vertices.length; i++)
			this.vertices[i] = matrix.multiply(this.vertices[i]);
	}
	
	public void calculateNormals(final boolean smooth, final float theta)
	{
		this.calculateFaceNormals();
		if(smooth)
		{
			Arrays.fill(this.normals, null);
			for(int i = 0; i < this.numFaces; i++)
			{
				final Vec3 n0 = this.faceNormals[i];
				final Face f = this.faces[i];
				if(theta <= -1)
				{
					if(this.normals[i * 3 + 0] == null) this.smoothNormal(f.va);
					if(this.normals[i * 3 + 1] == null) this.smoothNormal(f.vb);
					if(this.normals[i * 3 + 2] == null) this.smoothNormal(f.vc);
				}
				else
				{
					if(this.normals[i * 3 + 0] == null) this.smoothNormal(f.va, n0, theta);
					if(this.normals[i * 3 + 1] == null) this.smoothNormal(f.vb, n0, theta);
					if(this.normals[i * 3 + 2] == null) this.smoothNormal(f.vc, n0, theta);
				}
			}
		}
		else
		{
			for(int i = 0; i < this.numFaces; i++)
			{
				this.normals[i * 3] = this.normals[i * 3 + 1] = this.normals[i * 3 + 2] = this.faceNormals[i];
			}
		}
	}
	
	public void twist(final Axis axis, final float center, final float strength)
	{
		switch(axis)
		{
		case X:
			for(int i = 0; i < this.numVertices; i++)
			{
				final Vec3 v = this.vertices[i];
				double a = (v.getX() - center) * strength * 2.0 * Math.PI;
				this.vertices[i] = Math3D.matrixRotateX((float)a).multiply(v);
			}
			break;
		case Y:
			for(int i = 0; i < this.numVertices; i++)
			{
				final Vec3 v = this.vertices[i];
				double a = (v.getY() - center) * strength * 2.0 * Math.PI;
				this.vertices[i] = Math3D.matrixRotateY((float)a).multiply(v);
			}
			break;
		case Z:
			for(int i = 0; i < this.numVertices; i++)
			{
				final Vec3 v = this.vertices[i];
				double a = (v.getZ() - center) * strength * 2.0 * Math.PI;
				this.vertices[i] = Math3D.matrixRotateZ((float)a).multiply(v);
			}
			break;
		}
	}
	
	/*
	public void bend(final Axis axis, final Vec3 center, final float strength)
	{
		switch(axis)
		{
		case X:
			for(int i = 0; i < this.numVertices; i++)
			{
				final Vec3 v = this.vertices[i];
				
				double z = v.getY() * strength * Math.PI * 2.0;
				float s = (float)Math.cos(z);
				
				this.vertices[i] = new Vec3(s * (v.getX() + 2), v.getY(), v.getZ());
			}
			break;
		case Y:
//			for(int i = 0; i < this.numVertices; i++)
//			{
//				final Vector3f v = this.vertices[i];
//				double a = (v.getY() - center) * strength * 2.0 * Math.PI;
//				this.vertices[i] = Math3D.matrixRotateY((float)a).multiply(v);
//			}
			break;
		case Z:
//			for(int i = 0; i < this.numVertices; i++)
//			{
//				final Vector3f v = this.vertices[i];
//				double a = (v.getZ() - center) * strength * 2.0 * Math.PI;
//				this.vertices[i] = Math3D.matrixRotateZ((float)a).multiply(v);
//			}
			break;
		}
	}
    */
	
	public void disableDuplicateChecking(boolean set)
	{
		this.disableDuplicateChecking = set;
	}
	
	private int addVertex(final Vec3 v)
	{
		if(!this.disableDuplicateChecking)
		{
			for(int i = 0; i < this.numVertices; i++)
			{
				if(v.epsilonEquals(this.vertices[i], this.equalEpsilon))
					return i;
			}
		}
		this.vertices[this.numVertices] = v.clone();
		return this.numVertices++;
	}

	private void smoothNormal(final int vIndex, final Vec3 normal, final float theta)
	{
		final int to = this.adjacentFacesOffset[vIndex];
		final int tl = this.adjacentFacesLen[vIndex];
		final int[] used = new int[tl];
		int c = 0;
		float nx = 0, ny = 0, nz = 0;
		for(int i = to; i < to + tl; i++)
		{
			final int t = this.adjacentFacesList[i];
			final Vec3 n = this.faceNormals[t & ((1 << 29) - 1)];
			if(n.dot(normal) >= theta)
			{
				nx += n.getX();
				ny += n.getY();
				nz += n.getZ();
				used[c++] = t;
			}
		}
		final Vec3 n = new Vec3(nx, ny, nz).normalize();
		for(int i = 0; i < c; i++)
		{
			final int t = used[i];
			this.normals[(t & ((1 << 29) - 1)) * 3 + (t >> 29)] = n;
		}
	}
	
	private Vec3 smoothNormal(int vIndex)
	{
		final int to = this.adjacentFacesOffset[vIndex];
		final int tl = this.adjacentFacesLen[vIndex];
		float nx = 0, ny = 0, nz = 0;
		for(int i = to; i < to + tl; i++)
		{
			final int t = this.adjacentFacesList[i];
			final Vec3 n = this.faceNormals[t & ((1 << 29) - 1)];
			nx += n.getX();
			ny += n.getY();
			nz += n.getZ();
		}
		return new Vec3(nx, ny, nz).normalize();
	}

	private void calculateFaceNormals()
	{
		for(int i = 0; i < this.numFaces; i++)
		{
			final Face f = this.faces[i];
			final Vec3 a = this.vertices[f.va];
			final Vec3 b = this.vertices[f.vb];
			final Vec3 c = this.vertices[f.vc];
			this.faceNormals[i] = b.clone().sub(a).cross(c.clone().sub(a)).normalize();
		}
	}
	
	protected static class Face
	{
		public int va, vb, vc;
		public int ta, tb, tc;
		
		public Face(int va, int vb, int vc, int ta, int tb, int tc)
		{
			this.va = va;	this.vb = vb;	this.vc = vc;
			this.ta = ta;	this.tb = tb;	this.tc = tc;
		}
	}
	
	public enum Axis
	{
		X, Y, Z
	}
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.CharBuffer;
import java.nio.DoubleBuffer;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;
import java.nio.ShortBuffer;

/**
 * Static Buffer utility class.
 * 
 * @author René Jeschke
 */
public final class Buffers
{
    private Buffers() { /* */ }
    
    /**
     * Creates a new direct ByteBuffer
     * 
     * @param size Size in bytes.
     * @return The Buffer object.
     */
    public final static ByteBuffer newByte(final int size)
    {
        return ByteBuffer.allocateDirect(size).order(ByteOrder.nativeOrder());
    }
    
    /**
     * Creates a new direct CharBuffer
     * 
     * @param size Size in chars.
     * @return The Buffer object.
     */
    public final static CharBuffer newChar(final int size)
    {
        return newByte(size * (Character.SIZE >> 3)).asCharBuffer();
    }

    /**
     * Creates a new direct ShortBuffer
     * 
     * @param size Size in shorts.
     * @return The Buffer object.
     */
    public final static ShortBuffer newShort(final int size)
    {
        return newByte(size * (Short.SIZE >> 3)).asShortBuffer();
    }

    /**
     * Creates a new direct IntBuffer
     * 
     * @param size Size in ints.
     * @return The Buffer object.
     */
    public final static IntBuffer newInt(final int size)
    {
        return newByte(size * (Integer.SIZE >> 3)).asIntBuffer();
    }

    /**
     * Creates a new direct LongBuffer
     * 
     * @param size Size in longs.
     * @return The Buffer object.
     */
    public final static LongBuffer newLong(final int size)
    {
        return newByte(size * (Long.SIZE >> 3)).asLongBuffer();
    }

    /**
     * Creates a new direct FloatBuffer
     * 
     * @param size Size in floats.
     * @return The Buffer object.
     */
    public final static FloatBuffer newFloat(final int size)
    {
        return newByte(size * (Float.SIZE >> 3)).asFloatBuffer();
    }

    /**
     * Creates a new direct DoubleBuffer
     * 
     * @param size Size in doubles.
     * @return The Buffer object.
     */
    public final static DoubleBuffer newDouble(final int size)
    {
        return newByte(size * (Double.SIZE >> 3)).asDoubleBuffer();
    }

    /**
     * Converts a null terminated string inside the given ByteBuffer to a Java String.
     * 
     * @param buffer ByteBuffer containing character data.
     * @param encoding Encoding.
     * @return Encoded String, <code>null</code> on failure.
     */
    public final static String toString(final ByteBuffer buffer, final String encoding)
    {
        final byte[] buf = new byte[buffer.capacity()];
        buffer.rewind();
        buffer.get(buf);
        buffer.rewind();
        
        int i = 0;
        
        while(i < buf.length && buf[i] != 0)
        {
            i++;
        }
        
        try
        {
            return new String(buf, 0, i, encoding);
        }
        catch (UnsupportedEncodingException e)
        {
            return null;
        }
    }

    /**
     * Converts a null terminated string inside the given ByteBuffer to a Java String
     * using US-ASCII.
     * 
     * @param buffer ByteBuffer containing character data.
     * @return Encoded String, <code>null</code> on failure.
     */
    public final static String toASCIIString(final ByteBuffer buffer)
    {
        return toString(buffer, "US-ASCII");
    }

    /**
     * Converts a null terminated string inside the given ByteBuffer to a Java String
     * using UTF-8.
     * 
     * @param buffer ByteBuffer containing character data.
     * @return Encoded String, <code>null</code> on failure.
     */
    public final static String toUTF8String(final ByteBuffer buffer)
    {
        return toString(buffer, "UTF-8");
    }
}

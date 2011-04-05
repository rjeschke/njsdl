package njsdl;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.CharBuffer;
import java.nio.DoubleBuffer;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;
import java.nio.ShortBuffer;

public final class Buffers
{
    private Buffers() { /* */ }
    
    public final static ByteBuffer newByte(final int size)
    {
        return ByteBuffer.allocateDirect(size).order(ByteOrder.nativeOrder());
    }
    
    public final static CharBuffer newChar(final int size)
    {
        return newByte(size * (Character.SIZE >> 3)).asCharBuffer();
    }

    public final static ShortBuffer newShort(final int size)
    {
        return newByte(size * (Short.SIZE >> 3)).asShortBuffer();
    }

    public final static IntBuffer newInt(final int size)
    {
        return newByte(size * (Integer.SIZE >> 3)).asIntBuffer();
    }

    public final static LongBuffer newLong(final int size)
    {
        return newByte(size * (Long.SIZE >> 3)).asLongBuffer();
    }

    public final static FloatBuffer newFloat(final int size)
    {
        return newByte(size * (Float.SIZE >> 3)).asFloatBuffer();
    }

    public final static DoubleBuffer newDouble(final int size)
    {
        return newByte(size * (Double.SIZE >> 3)).asDoubleBuffer();
    }

    private final static String toString(final ByteBuffer buffer, final String encoding)
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
    
    public final static String toASCIIString(final ByteBuffer buffer)
    {
        return toString(buffer, "US-ASCII");
    }

    public final static String toUTF8String(final ByteBuffer buffer)
    {
        return toString(buffer, "UTF-8");
    }
}

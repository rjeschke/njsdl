/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl;

public class SDLPixelFormat
{
    /** The number of bits used to represent each pixel in a surface. Usually 8, 16, 24 or 32. */
    public final int bitsPerPixel;
    /** The number of bytes used to represent each pixel in a surface. Usually one to four. */
    public final int bytesPerPixel;
    /** Binary mask used to retrieve individual color values. */
    public final int rmask, gmask, bmask, amask;
    /** Binary left shift of each color component in the pixel value */
    public final int rshift, gshift, bshift, ashift;
    /** Precision loss of each color component (2**[RGBA]loss) */
    public final int rloss, gloss, bloss, aloss;
    /** Pixel value of transparent pixels */
    public final int colorkey;
    /** Overall surface alpha value */
    public final int alpha;
    
    private final long ptr;

    private SDLPixelFormat(final long ptr,
            final int bitspp, final int bytespp, 
            final int rmask, final int gmask, final int bmask, final int amask,
            final int rshift, final int gshift, final int bshift, final int ashift,
            final int rloss, final int gloss, final int bloss, final int aloss,
            final int colorkey, final int alpha)
    {
        this.ptr = ptr;
        this.bitsPerPixel = bitspp;
        this.bytesPerPixel = bytespp;
        this.rmask = rmask;
        this.rshift = rshift;
        this.rloss = rloss;
        this.gmask = gmask;
        this.gshift = gshift;
        this.gloss = gloss;
        this.bmask = bmask;
        this.bshift = bshift;
        this.bloss = bloss;
        this.amask = amask;
        this.ashift = ashift;
        this.aloss = aloss;
        this.colorkey = colorkey;
        this.alpha = alpha;
    }
    
    /**
     * Maps an RGB triple to an opaque pixel value for this pixel format.
     * 
     * @param r Red.
     * @param g Green.
     * @param b Blue.
     * @return Mapped RGB value.
     */
    public int mapRGB(final int r, final int g, final int b)
    {
        return _mapRGB(this.ptr, r, g, b);
    }
    
    /**
     * Maps an RGBA quadruple to a pixel value for this pixel format.
     * 
     * @param r Red.
     * @param g Green.
     * @param b Blue.
     * @param a Alpha.
     * @return Mapped RGBA value.
     */
    public int mapRGBA(final int r, final int g, final int b, final int a)
    {
        return _mapRGBA(this.ptr, r, g, b, a);
    }
    
    /**
     * Maps a pixel value into the RGB components for this pixel format.
     * 
     * @param pixel The pixel value.
     * @return Converted color in RGB layout.
     */
    public int getRGB(final int pixel)
    {
        return _getRGB(this.ptr, pixel);
    }
    
    /**
     * Maps a pixel value into the RGBA components for this pixel format.
     * 
     * @param pixel The pixel value.
     * @return Converted color in ARGB layout.
     */
    public int getRGBA(final int pixel)
    {
        return _getRGBA(this.ptr, pixel);
    }

    private static native int _mapRGB(final long ptr, final int r, final int g, final int b);
    private static native int _mapRGBA(final long ptr, final int r, final int g, final int b, final int a);
    private static native int _getRGB(final long ptr, final int pixel);
    private static native int _getRGBA(final long ptr, final int pixel);
}

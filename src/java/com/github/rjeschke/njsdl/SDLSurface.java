/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl;

import java.awt.image.BufferedImage;
import java.awt.image.IndexColorModel;
import java.awt.image.Raster;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;

import javax.imageio.ImageIO;

public final class SDLSurface
{
    protected final long ptr;
    /** Surface flags */
    public final int flags;
    /** Width in pixels */
    public final int w;
    /** Height in pixels */
    public final int h;
    /** Pitch in bytes */
    public final int pitch;
    /** Pixel data */
    public final ByteBuffer pixels;
    /** Pixel format */
    public final SDLPixelFormat format;
    
    private final boolean mustLock;
    
    private SDLSurface(final long ptr, 
            final int w, final int h, final int pitch, final int flags, 
            final ByteBuffer pixels, final SDLPixelFormat format, final boolean mustLock)
    {
        this.ptr = ptr;
        this.w = w;
        this.h = h;
        this.pitch = pitch;
        this.flags = flags;
        this.pixels = pixels.order(ByteOrder.nativeOrder());
        this.format = format;
        this.mustLock = mustLock;
    }

    /**
     * Checks whether or not this surface needs to be locked before directly accessing its pixel data.
     * 
     * @return <code>true</code> if the surface must be locked, <code>false</code> otherwise.
     */
    public boolean mustLock()
    {
        return this.mustLock;
    }
    
    /**
     * SDL_LockSurface() sets up a surface for directly accessing the pixels.
     * Between calls to SDL_LockSurface()/SDL_UnlockSurface(), you can write
     * to and read from 'surface->pixels', using the pixel format stored in 
     * 'surface->format'.  Once you are done accessing the surface, you should 
     * use SDL_UnlockSurface() to release it.
     *
     * <p>Not all surfaces require locking.  If SDL_MUSTLOCK(surface) evaluates
     * to 0, then you can read and write to the surface at any time, and the
     * pixel format of the surface will not change.  In particular, if the
     * SDL_HWSURFACE flag is not given when calling SDL_SetVideoMode(), you
     * will not need to lock the display surface before accessing it.</p>
     * 
     * <p>No operating system or library calls should be made between lock/unlock
     * pairs, as critical system locks may be held during this time.</p>
     *
     * @return <code>true</code>, or <code>false</code> if the surface couldn't be locked.
     */
    public boolean lock()
    {
        return _lock(this.ptr) == 0;
    }
    
    /**
     * SDL_LockSurface() sets up a surface for directly accessing the pixels.
     * Between calls to SDL_LockSurface()/SDL_UnlockSurface(), you can write
     * to and read from 'surface->pixels', using the pixel format stored in 
     * 'surface->format'.  Once you are done accessing the surface, you should 
     * use SDL_UnlockSurface() to release it.
     *
     * <p>Not all surfaces require locking.  If SDL_MUSTLOCK(surface) evaluates
     * to 0, then you can read and write to the surface at any time, and the
     * pixel format of the surface will not change.  In particular, if the
     * SDL_HWSURFACE flag is not given when calling SDL_SetVideoMode(), you
     * will not need to lock the display surface before accessing it.</p>
     * 
     * <p>No operating system or library calls should be made between lock/unlock
     * pairs, as critical system locks may be held during this time.</p>
     */
    public void unlock()
    {
        _unlock(this.ptr);
    }
    
    /**
     * Frees this surface.
     */
    public void free()
    {
        _free(this.ptr);
    }
    
    /**
     * This function takes a surface and copies it to a new surface of the
     * pixel format and colors of the video framebuffer, suitable for fast
     * blitting onto the display surface.  It calls SDL_ConvertSurface()
     *
     * <p>If you want to take advantage of hardware colorkey or alpha blit
     * acceleration, you should set the colorkey and alpha value before
     * calling this function.</p>
     *
     * <p>If the conversion fails or runs out of memory, it returns NULL</p>
     * 
     * @return Converted surface, <code>NULL</code> on failure.
     */
    public SDLSurface displayFormat()
    {
        return _displayFormat(this.ptr);
    }
    
    /**
     * This function takes a surface and copies it to a new surface of the
     * pixel format and colors of the video framebuffer (if possible),
     * suitable for fast alpha blitting onto the display surface.
     * The new surface will always have an alpha channel.
     *
     * <p>If you want to take advantage of hardware colorkey or alpha blit
     * acceleration, you should set the colorkey and alpha value before
     * calling this function.</p>
     *
     * <p>If the conversion fails or runs out of memory, it returns NULL</p>
     * 
     * @return Converted surface, <code>NULL</code> on failure.
     */
    public SDLSurface displayFormatAlpha()
    {
        return _displayFormatAlpha(this.ptr);
    }

    /**
     * <p>This performs a fast blit from this surface to the destination
     * surface.</p>
     * <p>The blit function should not be called on a locked surface.</p>
     *
     * @param dst Destination surface.
     * @param dx Destination X.
     * @param dy Destination Y.
     * @return <code>true</code> if the blit was successful, <code>false</code> otherwise. 
     */
    public boolean blit(final SDLSurface dst, final int dx, final int dy)
    {
        return _blit(this.ptr, 0, 0, this.w, this.h, dst.ptr, dx, dy);
    }
    
    /**
     * <p>This performs a fast blit from this surface to the destination
     * surface.</p>
     * <p>The blit function should not be called on a locked surface.</p>
     *
     * @param sx Source X.
     * @param sy Source Y.
     * @param sw Width.
     * @param sh Height.
     * @param dst Destination surface.
     * @param dx Destination X.
     * @param dy Destination Y.
     * @return <code>true</code> if the blit was successful, <code>false</code> otherwise. 
     */
    public boolean blit(final int sx, final int sy, final int sw, final int sh, final SDLSurface dst, final int dx, final int dy)
    {
        return _blit(this.ptr, sx, sy, sw, sh, dst.ptr, dx, dy);
    }

    /**
     * <p>This function performs a fast fill of the given rectangle with 'color'.</p>
     * <p>The given rectangle is clipped to the destination surface clip area
     * and the final fill rectangle is saved in the passed in pointer.</p>
     * <p>The color should be a pixel of the format used by the surface, and 
     * can be generated by the SDL_MapRGB() function.</p>
     * @param x X.
     * @param y Y.
     * @param w Width.
     * @param h Height.
     * @param color Color.
     * @return <code>true</code> on success, <code>false</code> otherwise. 
     */
    public boolean fillRect(final int x, final int y, final int w, final int h, final int color)
    {
        return _fillRect(this.ptr, x, y, w, h, color);
    }
    
    /**
     * <p>This function performs a fast fill of this surface with 'color'.</p>
     * <p>The color should be a pixel of the format used by the surface, and 
     * can be generated by the SDL_MapRGB() function.</p>
     * @param color Color.
     * @return <code>true</code> on success, <code>false</code> otherwise. 
     */
    public boolean fill(final int color)
    {
        return _fillRect(this.ptr, 0, 0, 0, 0, color);
    }

    private static int clamp(final int x, final int min, final int max)
    {
        return x < min ? min : x > max ? max : x;
    }

    /**
     * Loads an image as a RGBA SDL surface.
     * 
     * @param file File to load.
     * @param flags Flags for SDL.createRGBSurface
     * @return The loaded SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromFileRGBA(final File file, final int flags)
    {
        try
        {
            return fromImageRGBA(ImageIO.read(file), flags);
        }
        catch(IOException e)
        {
            return null;
        }
    }
    
    /**
     * Loads an image as a RGBA SDL surface.
     * 
     * @param filename Filename to load.
     * @param flags Flags for SDL.createRGBSurface
     * @return The loaded SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromFileRGBA(final String filename, final int flags)
    {
        try
        {
            return fromImageRGBA(ImageIO.read(new File(filename)), flags);
        }
        catch(IOException e)
        {
            return null;
        }
    }

    /**
     * Loads an image as a RGBA SDL surface.
     * 
     * @param input InputStream to load.
     * @param flags Flags for SDL.createRGBSurface
     * @return The loaded SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromStreamRGBA(final InputStream input, final int flags)
    {
        try
        {
            return fromImageRGBA(ImageIO.read(input), flags);
        }
        catch(IOException e)
        {
            return null;
        }
    }

    /**
     * Loads an image as a ARGB SDL surface.
     * 
     * @param file File to load.
     * @param flags Flags for SDL.createRGBSurface
     * @return The loaded SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromFileARGB(final File file, final int flags)
    {
        try
        {
            return fromImageARGB(ImageIO.read(file), flags);
        }
        catch(IOException e)
        {
            return null;
        }
    }
    
    /**
     * Loads an image as a ARGB SDL surface.
     * 
     * @param filename Filename to load.
     * @param flags Flags for SDL.createRGBSurface
     * @return The loaded SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromFileARGB(final String filename, final int flags)
    {
        try
        {
            return fromImageARGB(ImageIO.read(new File(filename)), flags);
        }
        catch(IOException e)
        {
            return null;
        }
    }

    /**
     * Loads an image as a ARGB SDL surface.
     * 
     * @param input InputStream to load.
     * @param flags Flags for SDL.createRGBSurface
     * @return The loaded SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromStreamARGB(final InputStream input, final int flags)
    {
        try
        {
            return fromImageARGB(ImageIO.read(input), flags);
        }
        catch(IOException e)
        {
            return null;
        }
    }

    /**
     * Converts a BufferedImage into a 32 Bit (A)RGB SDLSurface.
     * 
     * @param image Image to convert.
     * @param flags Flags for SDL.createRGBSurface
     * @return The converted SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromImageARGB(final BufferedImage image, final int flags)
    {
        final Raster r = image.getRaster();
        final int[] pix = new int[r.getNumBands()];
        final IndexColorModel icm = (image.getColorModel() instanceof IndexColorModel) ? (IndexColorModel)image.getColorModel() : null;
        if(pix.length == 2 || pix.length > 4) return null;
        final boolean hasAlpha = pix.length == 4 || (icm != null && icm.getTransparentPixel() != -1);
        final SDLSurface s = SDL.createRGBSurface(flags, 
                image.getWidth(), image.getHeight(), 32, 
                0x00ff0000, 0x0000ff00, 0x000000ff, hasAlpha ? 0xff000000 : 0x00000000);
        if(s == null)
            return null;
        if(s.mustLock()) s.lock();
        final IntBuffer pixels = s.pixels.asIntBuffer();
        final int stride = s.pitch >> 2;
        for(int y = 0; y < image.getHeight(); y++)
        {
            for(int x = 0; x < image.getWidth(); x++)
            {
                final int col;
                r.getPixel(x, y, pix);
                for(int i = 0; i < pix.length; i++)
                    pix[i] = clamp(pix[i], 0, 255);
                
                switch(pix.length)
                {
                default:
                case 1:
                    if(icm != null)
                        col = icm.getTransparentPixel() == pix[0] ? 0x00000000 : 0xff000000 | icm.getRGB(pix[0]);
                    else
                        col = 0xff000000 | (pix[0] << 16) | (pix[0] << 8) | pix[0];
                    break;
                case 3:
                    col = 0xff000000 | (pix[0] << 16) | (pix[1] << 8) | pix[2];
                    break;
                case 4:
                    col = (pix[3] << 24) | (pix[0] << 16) | (pix[1] << 8) | pix[2];
                    break;
                }
                pixels.put(x + y * stride, col);
            }
        }
        if(s.mustLock()) s.unlock();
        return s;
    }
    
    /**
     * Converts a BufferedImage into a 32 Bit RGBA SDLSurface.
     * 
     * @param image Image to convert.
     * @param flags Flags for SDL.createRGBSurface
     * @return The converted SDLSurface or <code>NULL</code> on failure.
     */
    public static SDLSurface fromImageRGBA(final BufferedImage image, final int flags)
    {
        final Raster r = image.getRaster();
        final int[] pix = new int[r.getNumBands()];
        final IndexColorModel icm = (image.getColorModel() instanceof IndexColorModel) ? (IndexColorModel)image.getColorModel() : null;
        if(pix.length == 2 || pix.length > 4) return null;
        final SDLSurface s = SDL.createRGBSurface(flags, 
                image.getWidth(), image.getHeight(), 32, 
                0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
        if(s == null)
            return null;
        if(s.mustLock()) s.lock();
        final IntBuffer pixels = s.pixels.asIntBuffer();
        final int stride = s.pitch >> 2;
        for(int y = 0; y < image.getHeight(); y++)
        {
            for(int x = 0; x < image.getWidth(); x++)
            {
                final int col;
                r.getPixel(x, y, pix);
                for(int i = 0; i < pix.length; i++)
                    pix[i] = clamp(pix[i], 0, 255);
                
                switch(pix.length)
                {
                default:
                case 1:
                    if(icm != null)
                        col = icm.getTransparentPixel() == pix[0] ? 0x00000000 : 0x000000ff | ((icm.getRGB(pix[0]) & 0xffffff) << 8);
                    else
                        col = 0x000000ff | (pix[0] << 24) | (pix[0] << 16) | (pix[0] << 8);
                    break;
                case 3:
                    col = 0x000000ff | (pix[0] << 24) | (pix[1] << 16) | (pix[2] << 8);
                    break;
                case 4:
                    col = pix[3] | (pix[0] << 24) | (pix[1] << 16) | (pix[2] << 8);
                    break;
                }
                pixels.put(x + y * stride, col);
            }
        }
        if(s.mustLock()) s.unlock();
        return s;
    }

    private static native SDLSurface _displayFormat(final long p);
    private static native SDLSurface _displayFormatAlpha(final long p);
    private static native int _lock(final long p);
    private static native void _unlock(final long p);
    private static native void _free(final long p);
    private static native boolean _fillRect(final long p, final int x, final int y, final int w, final int h, final int color);
    private static native boolean _blit(final long src, final int sx, final int sy, final int sw, final int sh, final long dst, final int dx, final int dy);
}

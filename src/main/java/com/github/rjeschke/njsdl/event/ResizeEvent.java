/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class ResizeEvent extends SDLEvent
{
    /** New width */
    public final int w;
    /** New height */
    public final int h;
    
    private ResizeEvent(int w, int h)
    {
        super(SDLEvent.VIDEORESIZE);
        this.w = w;
        this.h = h;
    }
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class MouseMotionEvent extends SDLEvent
{
    /** The mouse device index */
    public final int which;
    /** The current button state */
    public final int state;
    /** The X/Y coordinates of the mouse */
    public final int x, y;
    /** The relative motion in the X direction */
    public final int xrel;
    /** The relative motion in the Y direction */
    public final int yrel;
    
    private MouseMotionEvent(int which, int state, int x, int y, int xrel, int yrel)
    {
        super(SDLEvent.MOUSEMOTION);
        this.which = which;
        this.state = state;
        this.x = x;
        this.y = y;
        this.xrel = xrel;
        this.yrel = yrel;
    }
}

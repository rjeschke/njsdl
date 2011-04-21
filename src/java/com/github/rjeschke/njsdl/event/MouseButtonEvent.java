/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class MouseButtonEvent extends SDLEvent
{
    /** The mouse device index */
    public final int which;
    /** SDL.PRESSED or SDL.RELEASED */
    public final int state;
    /** The mouse button index */
    public final int button;
    /** The X/Y coordinates of the mouse at press time */
    public final int x, y;
    
    private MouseButtonEvent(int type, int which, int state, int button, int x, int y)
    {
        super(type);
        this.which = which;
        this.state = state;
        this.button = button;
        this.x = x;
        this.y = y;
    }
}

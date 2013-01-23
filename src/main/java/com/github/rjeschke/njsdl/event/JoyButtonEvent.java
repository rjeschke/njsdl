/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class JoyButtonEvent extends SDLEvent
{
    /** The joystick device index */
    public final int which;
    /** The joystick button index */
    public final int button;
    /** SDL.PRESSED or SDL.RELEASED */
    public final int state;
    
    private JoyButtonEvent(int type, int which, int button, int state)
    {
        super(type);
        this.which = which;
        this.button = button;
        this.state = state;
    }
}

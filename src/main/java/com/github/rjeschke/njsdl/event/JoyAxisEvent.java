/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class JoyAxisEvent extends SDLEvent
{
    /** The joystick device index */
    public final int which;
    /** The joystick axis index */
    public final int axis;
    /** The axis value (range: -32768 to 32767) */
    public final int value;
    
    private JoyAxisEvent(int which, int axis, int value)
    {
        super(SDLEvent.JOYAXISMOTION);
        this.which = which;
        this.axis = axis;
        this.value = value;
    }
}

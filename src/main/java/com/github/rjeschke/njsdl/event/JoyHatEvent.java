/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class JoyHatEvent extends SDLEvent
{
    /** The joystick device index */
    public final int which;
    /** The joystick hat index */
    public final int hat;
    /** The hat position value:
     *   SDL.HAT_LEFTUP   SDL.HAT_UP       SDL.HAT_RIGHTUP
     *   SDL.HAT_LEFT     SDL.HAT_CENTERED SDL.HAT_RIGHT
     *   SDL.HAT_LEFTDOWN SDL.HAT_DOWN     SDL.HAT_RIGHTDOWN
     *  Note that zero means the POV is centered.
     */    
    public final int value;
    
    private JoyHatEvent(int which, int hat, int value)
    {
        super(SDLEvent.JOYHATMOTION);
        this.which = which;
        this.hat = hat;
        this.value = value;
    }
}

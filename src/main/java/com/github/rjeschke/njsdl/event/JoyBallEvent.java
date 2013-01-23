/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class JoyBallEvent extends SDLEvent
{
    /** The joystick device index */
    public final int which;
    /** The joystick trackball index */
    public final int ball;
    /** The relative motion in the X direction */
    public final int xrel;
    /** The relative motion in the Y direction */
    public final int yrel;
    
    private JoyBallEvent(int which, int ball, int xrel, int yrel)
    {
        super(SDLEvent.JOYBALLMOTION);
        this.which = which;
        this.ball = ball;
        this.xrel = xrel;
        this.yrel = yrel;
    }
}

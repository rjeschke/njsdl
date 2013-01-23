/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class ActiveEvent extends SDLEvent
{
    /** Whether given states were gained or lost (1/0) */
    public final int gain;
    /** A mask of the focus states */
    public final int state;
    
    private ActiveEvent(int gain, int state)
    {
        super(SDLEvent.ACTIVEEVENT);
        this.gain = gain;
        this.state = state;
    }
}

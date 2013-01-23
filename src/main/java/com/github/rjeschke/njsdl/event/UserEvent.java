/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class UserEvent extends SDLEvent
{
    /** User defined event code */
    public final int code;
    
    public UserEvent(int code)
    {
        super(SDLEvent.USEREVENT);
        this.code = code;
    }
}

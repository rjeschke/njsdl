/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public final class KeyboardEvent extends SDLEvent
{
    /** The keyboard device index */
    public final int which;
    /** SDL.PRESSED or SDL.RELEASED */
    public final int state;
    /** hardware specific scancode */
    public final int scancode;
    /** SDL virtual keysym */
    public final int sym;
    /** current key modifiers */
    public final int mod;
    /** translated character */
    public final int unicode;
    
    private KeyboardEvent(int type, int which, int state, int scancode, int sym, int mod, int unicode)
    {
        super(type);
        this.which = which;
        this.state = state;
        this.scancode = scancode;
        this.sym = sym;
        this.mod = mod;
        this.unicode = unicode;
    }
}

/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl;

public final class SDLJoystick
{
    private final long ptr;
    
    private SDLJoystick(final long ptr)
    {
        this.ptr = ptr;
    }
    
    /**
     * Close this joystick.
     */
    public void close()
    {
        _close(this.ptr);
    }
    
    /**
     * Get the device index of this joystick.
     * 
     * @return Device index.
     */
    public int index()
    {
        return _joystickIndex(this.ptr);
    }
    
    /**
     * Get the number of general axis controls on this joystick.
     * 
     * @return Number of axes.
     */
    public int numAxes()
    {
        return _joystickNumAxes(this.ptr);
    }
    
    /**
     * Get the number of trackballs on this joystick.
     *
     * Joystick trackballs have only relative motion events associated
     * with them and their state cannot be polled.
     * 
     * @return NUmber of trackballs.
     */
    public int numBalls()
    {
        return _joystickNumBalls(this.ptr);
    }

    /**
     * Get the number of POV hats on this joystick.
     * 
     * @return Number of hats.
     */
    public int numHats()
    {
        return _joystickNumHats(this.ptr);
    }

    /**
     * Get the number of buttons on this joystick.
     * 
     * @return Number of buttons.
     */
    public int numButtons()
    {
        return _joystickNumButtons(this.ptr);
    }

    /**
     * Get the current state of an axis control on a joystick.
     *
     * @param axis The axis indices start at index 0.
     * @return The state is a value ranging from -32768 to 32767.
     */
    public int getAxis(final int axis)
    {
        return _getAxis(this.ptr, axis);
    }
    
    /** 
     *  Get the current state of a POV hat on a joystick.
     *
     *  @param hat The hat indices start at index 0.
     *  @return Position out of SDL.HAT_* values.
     */
    public int getHat(final int hat)
    {
        return _getHat(this.ptr, hat);
    }

    /**
     * Get the current state of a button on a joystick.
     *
     * @param button The button indices start at index 0.
     * @return <code>true</code> if the button is currently pressed, <code>false</code>otherwise.
     */
    public boolean getButton(final int button)
    {
        return _getButton(this.ptr, button);
    }
    
    private static native int _joystickIndex(final long ptr);
    private static native int _joystickNumAxes(final long ptr);
    private static native int _joystickNumBalls(final long ptr);
    private static native int _joystickNumHats(final long ptr);
    private static native int _joystickNumButtons(final long ptr);
    private static native int _getAxis(final long ptr, final int axis);
    private static native int _getHat(final long ptr, final int hat);
    private static native boolean _getButton(final long ptr, final int button);
    private static native void _close(final long ptr);
}

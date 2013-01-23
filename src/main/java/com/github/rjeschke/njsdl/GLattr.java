/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl;

/** Public enumeration for setting the OpenGL window attributes. */
public enum GLattr
{
    RED_SIZE(0),
    GREEN_SIZE(1),
    BLUE_SIZE(2),
    ALPHA_SIZE(3),
    BUFFER_SIZE(4),
    DOUBLEBUFFER(5),
    DEPTH_SIZE(6),
    STENCIL_SIZE(7),
    ACCUM_RED_SIZE(8),
    ACCUM_GREEN_SIZE(9),
    ACCUM_BLUE_SIZE(10),
    ACCUM_ALPHA_SIZE(11),
    STEREO(12),
    MULTISAMPLEBUFFERS(13),
    MULTISAMPLESAMPLES(14),
    ACCELERATED_VISUAL(15),
    SWAP_CONTROL(16);
    
    private final int value;
    
    private GLattr(int v)
    {
        this.value = v;
    }
    
    public int getValue()
    {
        return this.value;
    }
}

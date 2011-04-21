/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.event;

public class SDLEvent
{
    public final static int RELEASED            = 0;
    public final static int PRESSED             = 1;
    
    public final static int NOEVENT             = 0;
    public final static int ACTIVEEVENT         = 1;
    public final static int KEYDOWN             = 2;
    public final static int KEYUP               = 3;
    public final static int MOUSEMOTION         = 4;
    public final static int MOUSEBUTTONDOWN     = 5;
    public final static int MOUSEBUTTONUP       = 6;
    public final static int JOYAXISMOTION       = 7;
    public final static int JOYBALLMOTION       = 8;
    public final static int JOYHATMOTION        = 9;
    public final static int JOYBUTTONDOWN       = 10;
    public final static int JOYBUTTONUP         = 11;
    public final static int QUIT                = 12;
    public final static int SYSWMEVENT          = 13;
    public final static int EVENT_RESERVEDA     = 14;
    public final static int EVENT_RESERVEDB     = 15;
    public final static int VIDEORESIZE         = 16;
    public final static int VIDEOEXPOSE         = 17;
    public final static int EVENT_RESERVED2     = 18;
    public final static int EVENT_RESERVED3     = 19;
    public final static int EVENT_RESERVED4     = 20;
    public final static int EVENT_RESERVED5     = 21;
    public final static int EVENT_RESERVED6     = 22;
    public final static int EVENT_RESERVED7     = 23; 
    public final static int USEREVENT           = 24;
    
    public final static int ACTIVEEVENTMASK     = EVENTMASK(ACTIVEEVENT);
    public final static int KEYDOWNMASK         = EVENTMASK(KEYDOWN);
    public final static int KEYUPMASK           = EVENTMASK(KEYUP);
    public final static int KEYEVENTMASK        = EVENTMASK(KEYDOWN)
                                                        | EVENTMASK(KEYUP);
    public final static int MOUSEMOTIONMASK     = EVENTMASK(MOUSEMOTION);
    public final static int MOUSEBUTTONDOWNMASK = EVENTMASK(MOUSEBUTTONDOWN);
    public final static int MOUSEBUTTONUPMASK   = EVENTMASK(MOUSEBUTTONUP);
    public final static int MOUSEEVENTMASK      = EVENTMASK(MOUSEMOTION)
                                                        | EVENTMASK(MOUSEBUTTONDOWN)
                                                        | EVENTMASK(MOUSEBUTTONUP);
    public final static int JOYAXISMOTIONMASK   = EVENTMASK(JOYAXISMOTION);
    public final static int JOYBALLMOTIONMASK   = EVENTMASK(JOYBALLMOTION);
    public final static int JOYHATMOTIONMASK    = EVENTMASK(JOYHATMOTION);
    public final static int JOYBUTTONDOWNMASK   = EVENTMASK(JOYBUTTONDOWN);
    public final static int JOYBUTTONUPMASK     = EVENTMASK(JOYBUTTONUP);
    public final static int JOYEVENTMASK        = EVENTMASK(JOYAXISMOTION)
                                                        | EVENTMASK(JOYBALLMOTION)
                                                        | EVENTMASK(JOYHATMOTION)
                                                        | EVENTMASK(JOYBUTTONDOWN)
                                                        | EVENTMASK(JOYBUTTONUP);
    public final static int VIDEORESIZEMASK     = EVENTMASK(VIDEORESIZE);
    public final static int VIDEOEXPOSEMASK     = EVENTMASK(VIDEOEXPOSE);
    public final static int QUITMASK            = EVENTMASK(QUIT);
    public final static int SYSWMEVENTMASK      = EVENTMASK(SYSWMEVENT);
    
    public final static int ALLEVENTS           = 0xFFFFFFFF;     
    
    public final int type;
    
    protected SDLEvent(int type)
    {
        this.type = type;
    }
    
    private final static int EVENTMASK(final int x)
    {
        return 1 << x;
    }
    
    /**
     * @return <code>true</code> if this event is not of type NOEVENT.
     */
    public final boolean isEvent()
    {
        return this.type != NOEVENT;
    }
    
    /**
     * @return <code>true</code> if this event is of type ACTIVEVENT.
     */
    public final boolean isActiveEvent()
    {
        return this.type == ACTIVEEVENT;
    }
    
    /**
     * @return <code>true</code> if this event is of type JOYAXISMOTION.
     */
    public final boolean isJoyAxisEvent()
    {
        return this.type == JOYAXISMOTION;
    }
    
    /**
     * @return <code>true</code> if this event is of type JOYBALLMOTION.
     */
    public final boolean isJoyBallEvent()
    {
        return this.type == JOYBALLMOTION;
    }
    
    /**
     * @return <code>true</code> if this event is of type JOYBUTTONDOWN or JOYBUTTONUP.
     */
    public final boolean isJoyButtonEvent()
    {
        return this.type == JOYBUTTONDOWN || this.type == JOYBUTTONUP;
    }
    
    /**
     * @return <code>true</code> if this event is of type JOYHATMOTION.
     */
    public final boolean isJoyHatEvent()
    {
        return this.type == JOYHATMOTION;
    }
    
    /**
     * @return <code>true</code> if this event is of type KEYDOWN or KEYUP.
     */
    public final boolean isKeyboardEvent()
    {
        return this.type == KEYDOWN || this.type == KEYUP;
    }
    
    /**
     * @return <code>true</code> if this event is of type MOUSEBUTTONDOWN or MOUSEBUTTONUP.
     */
    public final boolean isMouseButtonEvent()
    {
        return this.type == MOUSEBUTTONDOWN || this.type == MOUSEBUTTONUP;
    }
    
    /**
     * @return <code>true</code> if this event is of type MOUSEMOTION.
     */
    public final boolean isMouseMotionEvent()
    {
        return this.type == MOUSEMOTION;
    }
    
    /**
     * @return <code>true</code> if this event is of type QUIT.
     */
    public final boolean isQuitEvent()
    {
        return this.type == QUIT;
    }
    
    /**
     * @return <code>true</code> if this event is of type VIDEORESIZE.
     */
    public final boolean isResizeEvent()
    {
        return this.type == VIDEORESIZE;
    }
    
    /**
     * @return <code>true</code> if this event is of type USEREVENT.
     */
    public final boolean isUserEvent()
    {
        return this.type == USEREVENT;
    }
    
    public final ActiveEvent asActiveEvent()
    {
        return (ActiveEvent)this;
    }
    
    public final JoyAxisEvent asJoyAxisEvent()
    {
        return (JoyAxisEvent)this;
    }
    
    public final JoyBallEvent asJoyBallEvent()
    {
        return (JoyBallEvent)this;
    }
    
    public final JoyButtonEvent asJoyButtonEvent()
    {
        return (JoyButtonEvent)this;
    }
    
    public final JoyHatEvent asJoyHatEvent()
    {
        return (JoyHatEvent)this;
    }
    
    public final KeyboardEvent asKeyboardEvent()
    {
        return (KeyboardEvent)this;
    }
    
    public final MouseButtonEvent asMouseButtonEvent()
    {
        return (MouseButtonEvent)this;
    }
    
    public final MouseMotionEvent asMouseMotionEvent()
    {
        return (MouseMotionEvent)this;
    }
    
    public final QuitEvent asQuitEvent()
    {
        return (QuitEvent)this;
    }
    
    public final ResizeEvent asResizeEvent()
    {
        return (ResizeEvent)this;
    }
    
    public final UserEvent asUserEvent()
    {
        return (UserEvent)this;
    }
}

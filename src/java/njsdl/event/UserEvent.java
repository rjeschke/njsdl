package njsdl.event;

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

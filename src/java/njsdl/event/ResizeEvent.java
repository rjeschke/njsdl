package njsdl.event;

public final class ResizeEvent extends SDLEvent
{
    /** New width */
    public final int w;
    /** New height */
    public final int h;
    
    private ResizeEvent(int w, int h)
    {
        super(SDLEvent.VIDEORESIZE);
        this.w = w;
        this.h = h;
    }
}

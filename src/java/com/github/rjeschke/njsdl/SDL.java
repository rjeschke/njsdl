/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl;

import java.nio.Buffer;
import java.nio.ByteBuffer;

import com.github.rjeschke.njsdl.event.SDLEvent;
import com.github.rjeschke.njsdl.event.UserEvent;


public final class SDL
{
    //public final static int INIT_TIMER          = 0x00000001;
    //public final static int INIT_AUDIO          = 0x00000010;
    /** Initialize video API */
    public final static int INIT_VIDEO          = 0x00000020;
    //public final static int INIT_CDROM          = 0x00000100;
    /** Initialize joystick API */ 
    public final static int INIT_JOYSTICK       = 0x00000200;
    /** Don't catch fatal signals */
    public final static int INIT_NOPARACHUTE    = 0x00100000;
    public final static int INIT_EVENTTHREAD    = 0x01000000;
    /** Initialize every API */
    public final static int INIT_EVERYTHING     = 0x0000FFFF;
    /** Surface is in system memory */
    public final static int SWSURFACE           = 0x00000000;
    /** Surface is in video memory */
    public final static int HWSURFACE           = 0x00000001;
    /** Use asynchronous blits if possible */
    public final static int ASYNCBLIT           = 0x00000004;
    /** Allow any video depth/pixel-format */
    public final static int ANYFORMAT           = 0x10000000;
    /** Surface has exclusive palette */
    public final static int HWPALETTE           = 0x20000000;
    /** Set up double-buffered video mode */
    public final static int DOUBLEBUF           = 0x40000000;
    /** Surface is a full screen display */
    public final static int FULLSCREEN          = 0x80000000;
    /** Create an OpenGL rendering context */
    public final static int OPENGL              = 0x00000002;
    /** Create an OpenGL rendering context and use it for blitting */
    public final static int OPENGLBLIT          = 0x0000000A;
    /** This video mode may be resized */
    public final static int RESIZABLE           = 0x00000010;
    /** No window caption or edge frame */
    public final static int NOFRAME             = 0x00000020;
    /** Blit uses hardware acceleration */
    public final static int HWACCEL             = 0x00000100;
    /** Blit uses a source color key */
    public final static int SRCCOLORKEY         = 0x00001000;
    /** Private flag */
    public final static int RLEACCELOK          = 0x00002000;
    /** Surface is RLE encoded */
    public final static int RLEACCEL            = 0x00004000;
    /** Blit uses source alpha blending */
    public final static int SRCALPHA            = 0x00010000;
    /** Surface uses preallocated memory */
    public final static int PREALLOC            = 0x01000000;
    
    public final static int SDLK_UNKNOWN        = 0;
    public final static int SDLK_FIRST          = 0;
    public final static int SDLK_BACKSPACE      = 8;
    public final static int SDLK_TAB            = 9;
    public final static int SDLK_CLEAR          = 12;
    public final static int SDLK_RETURN         = 13;
    public final static int SDLK_PAUSE          = 19;
    public final static int SDLK_ESCAPE         = 27;
    public final static int SDLK_SPACE          = 32;
    public final static int SDLK_EXCLAIM        = 33;
    public final static int SDLK_QUOTEDBL       = 34;
    public final static int SDLK_HASH           = 35;
    public final static int SDLK_DOLLAR         = 36;
    public final static int SDLK_AMPERSAND      = 38;
    public final static int SDLK_QUOTE          = 39;
    public final static int SDLK_LEFTPAREN      = 40;
    public final static int SDLK_RIGHTPAREN     = 41;
    public final static int SDLK_ASTERISK       = 42;
    public final static int SDLK_PLUS           = 43;
    public final static int SDLK_COMMA          = 44;
    public final static int SDLK_MINUS          = 45;
    public final static int SDLK_PERIOD         = 46;
    public final static int SDLK_SLASH          = 47;
    public final static int SDLK_0              = 48;
    public final static int SDLK_1              = 49;
    public final static int SDLK_2              = 50;
    public final static int SDLK_3              = 51;
    public final static int SDLK_4              = 52;
    public final static int SDLK_5              = 53;
    public final static int SDLK_6              = 54;
    public final static int SDLK_7              = 55;
    public final static int SDLK_8              = 56;
    public final static int SDLK_9              = 57;
    public final static int SDLK_COLON          = 58;
    public final static int SDLK_SEMICOLON      = 59;
    public final static int SDLK_LESS           = 60;
    public final static int SDLK_EQUALS         = 61;
    public final static int SDLK_GREATER        = 62;
    public final static int SDLK_QUESTION       = 63;
    public final static int SDLK_AT             = 64;
    public final static int SDLK_LEFTBRACKET    = 91;
    public final static int SDLK_BACKSLASH      = 92;
    public final static int SDLK_RIGHTBRACKET   = 93;
    public final static int SDLK_CARET          = 94;
    public final static int SDLK_UNDERSCORE     = 95;
    public final static int SDLK_BACKQUOTE      = 96;
    public final static int SDLK_a              = 97;
    public final static int SDLK_b              = 98;
    public final static int SDLK_c              = 99;
    public final static int SDLK_d              = 100;
    public final static int SDLK_e              = 101;
    public final static int SDLK_f              = 102;
    public final static int SDLK_g              = 103;
    public final static int SDLK_h              = 104;
    public final static int SDLK_i              = 105;
    public final static int SDLK_j              = 106;
    public final static int SDLK_k              = 107;
    public final static int SDLK_l              = 108;
    public final static int SDLK_m              = 109;
    public final static int SDLK_n              = 110;
    public final static int SDLK_o              = 111;
    public final static int SDLK_p              = 112;
    public final static int SDLK_q              = 113;
    public final static int SDLK_r              = 114;
    public final static int SDLK_s              = 115;
    public final static int SDLK_t              = 116;
    public final static int SDLK_u              = 117;
    public final static int SDLK_v              = 118;
    public final static int SDLK_w              = 119;
    public final static int SDLK_x              = 120;
    public final static int SDLK_y              = 121;
    public final static int SDLK_z              = 122;
    public final static int SDLK_DELETE         = 127;
    public final static int SDLK_WORLD_0        = 160;      /* 0xA0 */
    public final static int SDLK_WORLD_1        = 161;
    public final static int SDLK_WORLD_2        = 162;
    public final static int SDLK_WORLD_3        = 163;
    public final static int SDLK_WORLD_4        = 164;
    public final static int SDLK_WORLD_5        = 165;
    public final static int SDLK_WORLD_6        = 166;
    public final static int SDLK_WORLD_7        = 167;
    public final static int SDLK_WORLD_8        = 168;
    public final static int SDLK_WORLD_9        = 169;
    public final static int SDLK_WORLD_10       = 170;
    public final static int SDLK_WORLD_11       = 171;
    public final static int SDLK_WORLD_12       = 172;
    public final static int SDLK_WORLD_13       = 173;
    public final static int SDLK_WORLD_14       = 174;
    public final static int SDLK_WORLD_15       = 175;
    public final static int SDLK_WORLD_16       = 176;
    public final static int SDLK_WORLD_17       = 177;
    public final static int SDLK_WORLD_18       = 178;
    public final static int SDLK_WORLD_19       = 179;
    public final static int SDLK_WORLD_20       = 180;
    public final static int SDLK_WORLD_21       = 181;
    public final static int SDLK_WORLD_22       = 182;
    public final static int SDLK_WORLD_23       = 183;
    public final static int SDLK_WORLD_24       = 184;
    public final static int SDLK_WORLD_25       = 185;
    public final static int SDLK_WORLD_26       = 186;
    public final static int SDLK_WORLD_27       = 187;
    public final static int SDLK_WORLD_28       = 188;
    public final static int SDLK_WORLD_29       = 189;
    public final static int SDLK_WORLD_30       = 190;
    public final static int SDLK_WORLD_31       = 191;
    public final static int SDLK_WORLD_32       = 192;
    public final static int SDLK_WORLD_33       = 193;
    public final static int SDLK_WORLD_34       = 194;
    public final static int SDLK_WORLD_35       = 195;
    public final static int SDLK_WORLD_36       = 196;
    public final static int SDLK_WORLD_37       = 197;
    public final static int SDLK_WORLD_38       = 198;
    public final static int SDLK_WORLD_39       = 199;
    public final static int SDLK_WORLD_40       = 200;
    public final static int SDLK_WORLD_41       = 201;
    public final static int SDLK_WORLD_42       = 202;
    public final static int SDLK_WORLD_43       = 203;
    public final static int SDLK_WORLD_44       = 204;
    public final static int SDLK_WORLD_45       = 205;
    public final static int SDLK_WORLD_46       = 206;
    public final static int SDLK_WORLD_47       = 207;
    public final static int SDLK_WORLD_48       = 208;
    public final static int SDLK_WORLD_49       = 209;
    public final static int SDLK_WORLD_50       = 210;
    public final static int SDLK_WORLD_51       = 211;
    public final static int SDLK_WORLD_52       = 212;
    public final static int SDLK_WORLD_53       = 213;
    public final static int SDLK_WORLD_54       = 214;
    public final static int SDLK_WORLD_55       = 215;
    public final static int SDLK_WORLD_56       = 216;
    public final static int SDLK_WORLD_57       = 217;
    public final static int SDLK_WORLD_58       = 218;
    public final static int SDLK_WORLD_59       = 219;
    public final static int SDLK_WORLD_60       = 220;
    public final static int SDLK_WORLD_61       = 221;
    public final static int SDLK_WORLD_62       = 222;
    public final static int SDLK_WORLD_63       = 223;
    public final static int SDLK_WORLD_64       = 224;
    public final static int SDLK_WORLD_65       = 225;
    public final static int SDLK_WORLD_66       = 226;
    public final static int SDLK_WORLD_67       = 227;
    public final static int SDLK_WORLD_68       = 228;
    public final static int SDLK_WORLD_69       = 229;
    public final static int SDLK_WORLD_70       = 230;
    public final static int SDLK_WORLD_71       = 231;
    public final static int SDLK_WORLD_72       = 232;
    public final static int SDLK_WORLD_73       = 233;
    public final static int SDLK_WORLD_74       = 234;
    public final static int SDLK_WORLD_75       = 235;
    public final static int SDLK_WORLD_76       = 236;
    public final static int SDLK_WORLD_77       = 237;
    public final static int SDLK_WORLD_78       = 238;
    public final static int SDLK_WORLD_79       = 239;
    public final static int SDLK_WORLD_80       = 240;
    public final static int SDLK_WORLD_81       = 241;
    public final static int SDLK_WORLD_82       = 242;
    public final static int SDLK_WORLD_83       = 243;
    public final static int SDLK_WORLD_84       = 244;
    public final static int SDLK_WORLD_85       = 245;
    public final static int SDLK_WORLD_86       = 246;
    public final static int SDLK_WORLD_87       = 247;
    public final static int SDLK_WORLD_88       = 248;
    public final static int SDLK_WORLD_89       = 249;
    public final static int SDLK_WORLD_90       = 250;
    public final static int SDLK_WORLD_91       = 251;
    public final static int SDLK_WORLD_92       = 252;
    public final static int SDLK_WORLD_93       = 253;
    public final static int SDLK_WORLD_94       = 254;
    public final static int SDLK_WORLD_95       = 255;
    public final static int SDLK_KP0            = 256;
    public final static int SDLK_KP1            = 257;
    public final static int SDLK_KP2            = 258;
    public final static int SDLK_KP3            = 259;
    public final static int SDLK_KP4            = 260;
    public final static int SDLK_KP5            = 261;
    public final static int SDLK_KP6            = 262;
    public final static int SDLK_KP7            = 263;
    public final static int SDLK_KP8            = 264;
    public final static int SDLK_KP9            = 265;
    public final static int SDLK_KP_PERIOD      = 266;
    public final static int SDLK_KP_DIVIDE      = 267;
    public final static int SDLK_KP_MULTIPLY    = 268;
    public final static int SDLK_KP_MINUS       = 269;
    public final static int SDLK_KP_PLUS        = 270;
    public final static int SDLK_KP_ENTER       = 271;
    public final static int SDLK_KP_EQUALS      = 272;
    public final static int SDLK_UP             = 273;
    public final static int SDLK_DOWN           = 274;
    public final static int SDLK_RIGHT          = 275;
    public final static int SDLK_LEFT           = 276;
    public final static int SDLK_INSERT         = 277;
    public final static int SDLK_HOME           = 278;
    public final static int SDLK_END            = 279;
    public final static int SDLK_PAGEUP         = 280;
    public final static int SDLK_PAGEDOWN       = 281;
    public final static int SDLK_F1             = 282;
    public final static int SDLK_F2             = 283;
    public final static int SDLK_F3             = 284;
    public final static int SDLK_F4             = 285;
    public final static int SDLK_F5             = 286;
    public final static int SDLK_F6             = 287;
    public final static int SDLK_F7             = 288;
    public final static int SDLK_F8             = 289;
    public final static int SDLK_F9             = 290;
    public final static int SDLK_F10            = 291;
    public final static int SDLK_F11            = 292;
    public final static int SDLK_F12            = 293;
    public final static int SDLK_F13            = 294;
    public final static int SDLK_F14            = 295;
    public final static int SDLK_F15            = 296;
    public final static int SDLK_NUMLOCK        = 300;
    public final static int SDLK_CAPSLOCK       = 301;
    public final static int SDLK_SCROLLOCK      = 302;
    public final static int SDLK_RSHIFT         = 303;
    public final static int SDLK_LSHIFT         = 304;
    public final static int SDLK_RCTRL          = 305;
    public final static int SDLK_LCTRL          = 306;
    public final static int SDLK_RALT           = 307;
    public final static int SDLK_LALT           = 308;
    public final static int SDLK_RMETA          = 309;
    public final static int SDLK_LMETA          = 310;
    /** Left "Windows" key */
    public final static int SDLK_LSUPER         = 311;
    /** Right "Windows" key */
    public final static int SDLK_RSUPER         = 312;
    /** "Alt Gr" key */
    public final static int SDLK_MODE           = 313;
    /** Multi-key compose key */
    public final static int SDLK_COMPOSE        = 314;      
    public final static int SDLK_HELP           = 315;
    public final static int SDLK_PRINT          = 316;
    public final static int SDLK_SYSREQ         = 317;
    public final static int SDLK_BREAK          = 318;
    public final static int SDLK_MENU           = 319;
    /** Power Macintosh power key */
    public final static int SDLK_POWER          = 320;
    /** Some european keyboards */
    public final static int SDLK_EURO           = 321;
    /** Atari keyboard has Undo */
    public final static int SDLK_UNDO           = 322;      

    public final static int KMOD_NONE           = 0x0000;
    public final static int KMOD_LSHIFT         = 0x0001;
    public final static int KMOD_RSHIFT         = 0x0002;
    public final static int KMOD_LCTRL          = 0x0040;
    public final static int KMOD_RCTRL          = 0x0080;
    public final static int KMOD_LALT           = 0x0100;
    public final static int KMOD_RALT           = 0x0200;
    public final static int KMOD_LMETA          = 0x0400;
    public final static int KMOD_RMETA          = 0x0800;
    public final static int KMOD_NUM            = 0x1000;
    public final static int KMOD_CAPS           = 0x2000;
    public final static int KMOD_MODE           = 0x4000;
    public final static int KMOD_RESERVED       = 0x8000;
    public final static int KMOD_CTRL           = (KMOD_LCTRL | KMOD_RCTRL);
    public final static int KMOD_SHIFT          = (KMOD_LSHIFT | KMOD_RSHIFT);
    public final static int KMOD_ALT            = (KMOD_LALT | KMOD_RALT);
    public final static int KMOD_META           = (KMOD_LMETA | KMOD_RMETA);
    
    public final static int BUTTON_LEFT         = 1;
    public final static int BUTTON_MIDDLE       = 2;
    public final static int BUTTON_RIGHT        = 3;
    public final static int BUTTON_WHEELUP      = 4;
    public final static int BUTTON_WHEELDOWN    = 5;
    public final static int BUTTON_X1           = 6;
    public final static int BUTTON_X2           = 7;
    public final static int BUTTON_LMASK        = 1 << (BUTTON_LEFT - 1);
    public final static int BUTTON_MMASK        = 1 << (BUTTON_MIDDLE - 1);
    public final static int BUTTON_RMASK        = 1 << (BUTTON_RIGHT - 1);
    public final static int BUTTON_X1MASK       = 1 << (BUTTON_X1 - 1);
    public final static int BUTTON_X2MASK       = 1 << (BUTTON_X2 - 1) ;
    
    public final static int HAT_CENTERED        = 0x00;
    public final static int HAT_UP              = 0x01;
    public final static int HAT_RIGHT           = 0x02;
    public final static int HAT_DOWN            = 0x04;
    public final static int HAT_LEFT            = 0x08;
    public final static int HAT_RIGHTUP         = (HAT_RIGHT | HAT_UP);
    public final static int HAT_RIGHTDOWN       = (HAT_RIGHT | HAT_DOWN);
    public final static int HAT_LEFTUP          = (HAT_LEFT | HAT_UP);
    public final static int HAT_LEFTDOWN        = (HAT_LEFT | HAT_DOWN); 
    
    public final static int QUERY               = -1;
    public final static int IGNORE              = 0;
    public final static int DISABLE             = 0;
    public final static int ENABLE              = 1; 
    
    public final static int GRAB_QUERY          = -1;
    public final static int GRAB_OFF            = 0;
    public final static int GRAB_ON             = 1;

    public final static int DEFAULT_REPEAT_DELAY    = 500;
    public final static int DEFAULT_REPEAT_INTERVAL = 30;
    
    // Main
    public static native int wasInit(final int flags);
    /** This function loads the SDL dynamically linked library and initializes 
     *  the subsystems specified by 'flags' (and those satisfying dependencies)
     *  Unless the SDL_INIT_NOPARACHUTE flag is set, it will install cleanup
     *  signal handlers for some commonly ignored fatal signals (like SIGSEGV)
     *  
     * @return <code>true</code> on success, <code>false</code> on failure.
     */
    public static native boolean init(final int flags);
    /** This function initializes specific SDL subsystems
     * 
     * @return <code>true</code> on success, <code>false</code> on failure.
     */
    public static native boolean initSubSystem(final int flags);
    /** This function cleans up specific SDL subsystems */
    public static native void quitSubSystem(final int flags);
    /** This function cleans up all initialized subsystems and unloads the
     *  dynamically linked library.  You should call it upon all exit conditions.
     */
    public static native void quit();
    public static native void clearError();
    public static native String getError();
    
    // Video
    /**
     * Check to see if a particular video mode is supported.
     * <p>It returns 0 if the requested mode is not supported under any bit depth,
     * or returns the bits-per-pixel of the closest available mode with the
     * given width and height.  If this bits-per-pixel is different from the
     * one used when setting the video mode, SDL_SetVideoMode() will succeed,
     * but will emulate the requested bits-per-pixel with a shadow surface.</p>
     * <p>The arguments to SDL_VideoModeOK() are the same ones you would pass to
     * SDL_SetVideoMode()</p>
     * 
     * @return 0 or a bit depth.
     */
    public static native int videoModeOK(final int width, final int height, final int bpp, final int flags);
    /**
     * Set up a video mode with the specified width, height and bits-per-pixel.
     *
     * <p>If 'bpp' is 0, it is treated as the current display bits per pixel.</p>
     * <p>If SDL_ANYFORMAT is set in 'flags', the SDL library will try to set the
     * requested bits-per-pixel, but will return whatever video pixel format is
     * available.  The default is to emulate the requested pixel format if it
     * is not natively available.</p>
     * <p>If SDL_HWSURFACE is set in 'flags', the video surface will be placed in
     * video memory, if possible, and you may have to call SDL_LockSurface()
     * in order to access the raw framebuffer.  Otherwise, the video surface
     * will be created in system memory.</p>
     * <p>If SDL_ASYNCBLIT is set in 'flags', SDL will try to perform rectangle
     * updates asynchronously, but you must always lock before accessing pixels.
     * SDL will wait for updates to complete before returning from the lock.</p>
     * <p>If SDL_HWPALETTE is set in 'flags', the SDL library will guarantee
     * that the colors set by SDL_SetColors() will be the colors you get.
     * Otherwise, in 8-bit mode, SDL_SetColors() may not be able to set all
     * of the colors exactly the way they are requested, and you should look
     * at the video surface structure to determine the actual palette.
     * If SDL cannot guarantee that the colors you request can be set, 
     * i.e. if the colormap is shared, then the video surface may be created
     * under emulation in system memory, overriding the SDL_HWSURFACE flag.</p>
     * <p>If SDL_FULLSCREEN is set in 'flags', the SDL library will try to set
     * a fullscreen video mode.  The default is to create a windowed mode
     * if the current graphics system has a window manager.
     * If the SDL library is able to set a fullscreen video mode, this flag 
     * will be set in the surface that is returned.</p>
     * <p>If SDL_DOUBLEBUF is set in 'flags', the SDL library will try to set up
     * two surfaces in video memory and swap between them when you call 
     * SDL_Flip().  This is usually slower than the normal single-buffering
     * scheme, but prevents "tearing" artifacts caused by modifying video 
     * memory while the monitor is refreshing.  It should only be used by 
     * applications that redraw the entire screen on every update.</p>
     * <p>If SDL_RESIZABLE is set in 'flags', the SDL library will allow the
     * window manager, if any, to resize the window at runtime.  When this
     * occurs, SDL will send a SDL_VIDEORESIZE event to you application,
     * and you must respond to the event by re-calling SDL_SetVideoMode()
     * with the requested size (or another size that suits the application).</p>
     * <p>If SDL_NOFRAME is set in 'flags', the SDL library will create a window
     * without any title bar or frame decoration.  Fullscreen video modes have
     * this flag set automatically.</p>
     * <p>This function returns the video framebuffer surface, or NULL if it fails.</p>
     * <p>If you rely on functionality provided by certain video flags, check the
     * flags of the returned surface to make sure that functionality is available.
     * SDL will fall back to reduced functionality if the exact flags you wanted
     * are not available.</p>
     * 
     * @param width Width in pixels
     * @param height Height in pixels.
     * @param bpp Bits per pixel.
     * @param flags Flags.
     * @return Video surface or <code>null</code> on failure.
     */
    public static native SDLSurface setVideoMode(final int width, final int height, final int bpp, final int flags);
    /**
     * This function returns a pointer to the current display surface.
     * <p>If SDL is doing format conversion on the display surface, this
     * function returns the publicly visible surface, not the real video
     * surface.</p>
     * 
     * @return The video surface.
     */
    public static native SDLSurface getVideoSurface();
    private static native void _updateRect(final long ptr, final int x, final int y, final int w, final int h);
    private static native boolean _flip(final long ptr);
    public static native int showCursor(final int toggle);
    /**
     * Allocate an RGB surface (must be called after SDL_SetVideoMode)
     * <p>If the depth is 4 or 8 bits, an empty palette is allocated for the surface.
     * If the depth is greater than 8 bits, the pixel format is set using the
     * flags '[RGB]mask'.
     * If the function runs out of memory, it will return NULL.</p>
     * <p>The 'flags' tell what kind of surface to create.</p>
     * <p>SDL_SWSURFACE means that the surface should be created in system memory.</p>
     * <p>SDL_HWSURFACE means that the surface should be created in video memory,
     * with the same format as the display surface.  This is useful for surfaces
     * that will not change much, to take advantage of hardware acceleration
     * when being blitted to the display surface.</p>
     * <p>SDL_ASYNCBLIT means that SDL will try to perform asynchronous blits with
     * this surface, but you must always lock it before accessing the pixels.
     * SDL will wait for current blits to finish before returning from the lock.</p>
     * <p>SDL_SRCCOLORKEY indicates that the surface will be used for colorkey blits.
     * If the hardware supports acceleration of colorkey blits between
     * two surfaces in video memory, SDL will try to place the surface in
     * video memory. If this isn't possible or if there is no hardware
     * acceleration available, the surface will be placed in system memory.</p>
     * <p>SDL_SRCALPHA means that the surface will be used for alpha blits and 
     * if the hardware supports hardware acceleration of alpha blits between
     * two surfaces in video memory, to place the surface in video memory
     * if possible, otherwise it will be placed in system memory.</p>
     * <p>If the surface is created in video memory, blits will be _much_ faster,
     * but the surface format must be identical to the video surface format,
     * and the only way to access the pixels member of the surface is to use
     * the SDL_LockSurface() and SDL_UnlockSurface() calls.</p>
     * <p>If the requested surface actually resides in video memory, SDL_HWSURFACE
     * will be set in the flags member of the returned surface.  If for some
     * reason the surface could not be placed in video memory, it will not have
     * the SDL_HWSURFACE flag set, and will be created in system memory instead.</p>
     * 
     * @param flags Flags.
     * @param width Width in pixels.
     * @param height Height in pixels.
     * @param depth Bits per pixel.
     * @param rmask Red mask.
     * @param gmask Green mask.
     * @param bmask Blue mask.
     * @param amask Alpha mask.
     * @return <code>NULL</code> on failure, a SDLSurface otherwise.
     */
    public static native SDLSurface createRGBSurface(final int flags, final int width, final int height, final int depth, final int rmask, final int gmask, final int bmask, final int amask);
    /**
     * Allocate an RGB surface (must be called after SDL_SetVideoMode)
     * <p>If the depth is 4 or 8 bits, an empty palette is allocated for the surface.
     * If the depth is greater than 8 bits, the pixel format is set using the
     * flags '[RGB]mask'.
     * If the function runs out of memory, it will return NULL.</p>
     * <p>The 'flags' tell what kind of surface to create.</p>
     * <p>SDL_SWSURFACE means that the surface should be created in system memory.</p>
     * <p>SDL_HWSURFACE means that the surface should be created in video memory,
     * with the same format as the display surface.  This is useful for surfaces
     * that will not change much, to take advantage of hardware acceleration
     * when being blitted to the display surface.</p>
     * <p>SDL_ASYNCBLIT means that SDL will try to perform asynchronous blits with
     * this surface, but you must always lock it before accessing the pixels.
     * SDL will wait for current blits to finish before returning from the lock.</p>
     * <p>SDL_SRCCOLORKEY indicates that the surface will be used for colorkey blits.
     * If the hardware supports acceleration of colorkey blits between
     * two surfaces in video memory, SDL will try to place the surface in
     * video memory. If this isn't possible or if there is no hardware
     * acceleration available, the surface will be placed in system memory.</p>
     * <p>SDL_SRCALPHA means that the surface will be used for alpha blits and 
     * if the hardware supports hardware acceleration of alpha blits between
     * two surfaces in video memory, to place the surface in video memory
     * if possible, otherwise it will be placed in system memory.</p>
     * <p>If the surface is created in video memory, blits will be _much_ faster,
     * but the surface format must be identical to the video surface format,
     * and the only way to access the pixels member of the surface is to use
     * the SDL_LockSurface() and SDL_UnlockSurface() calls.</p>
     * <p>If the requested surface actually resides in video memory, SDL_HWSURFACE
     * will be set in the flags member of the returned surface.  If for some
     * reason the surface could not be placed in video memory, it will not have
     * the SDL_HWSURFACE flag set, and will be created in system memory instead.</p>
     * 
     * @param pixels Pixel data.
     * @param width Width in pixels.
     * @param height Height in pixels.
     * @param depth Bits per pixel.
     * @param pitch Pitch in bytes.
     * @param rmask Red mask.
     * @param gmask Green mask.
     * @param bmask Blue mask.
     * @param amask Alpha mask.
     * @return <code>NULL</code> on failure, a SDLSurface otherwise.
     */
    public static native SDLSurface createRGBSurfaceFrom(final Buffer pixels, final int width, final int height, final int depth, final int pitch, final int rmask, final int gmask, final int bmask, final int amask);
    /**
     * Makes sure the given rectangle is updated on the given screen.
     * 
     * @param screen Video surface.
     * @param x X.
     * @param y Y.
     * @param w Width.
     * @param h height.
     */
    public static void updateRect(final SDLSurface screen, final int x, final int y, final int w, final int h)
    {
        _updateRect(screen.ptr, x, y, w, h);
    }
    /**
     * Makes sure the given rectangle is updated on the given screen.
     * 
     * @param x X.
     * @param y Y.
     * @param w Width.
     * @param h height.
     */
    public static void updateRect(final int x, final int y, final int w, final int h)
    {
        _updateRect(0L, x, y, w, h);
    }
    /**
     * Makes sure the given rectangle is updated on the given screen.
     */
    public static void updateRect()
    {
        _updateRect(0L, 0, 0, 0, 0);
    }
    /**
     * Makes sure the given rectangle is updated on the given screen.
     * 
     * @param screen Video surface.
     */
    public static void updateRect(final SDLSurface screen)
    {
        _updateRect(screen.ptr, 0, 0, 0, 0);
    }
    /**
     * <p>On hardware that supports double-buffering, this function sets up a flip
     * and returns.  The hardware will wait for vertical retrace, and then swap
     * video buffers before the next video surface blit or lock will return.
     * On hardware that doesn not support double-buffering, this is equivalent
     * to calling SDL_UpdateRect(screen, 0, 0, 0, 0);</p>
     * <p>The SDL_DOUBLEBUF flag must have been passed to SDL_SetVideoMode() when
     * setting the video mode for this function to perform hardware flipping.
     * This function returns <code>true</code> if successful, or <code>false</code> if there was an error.</p>
     * 
     * @param screen The video surface.
     * @return <code>true</code> on success, <code>false</code> on failure.
     */
    public static boolean flip(final SDLSurface screen)
    {
        return _flip(screen.ptr);
    }
    /**
     * <p>On hardware that supports double-buffering, this function sets up a flip
     * and returns.  The hardware will wait for vertical retrace, and then swap
     * video buffers before the next video surface blit or lock will return.
     * On hardware that doesn not support double-buffering, this is equivalent
     * to calling SDL_UpdateRect(screen, 0, 0, 0, 0);</p>
     * <p>The SDL_DOUBLEBUF flag must have been passed to SDL_SetVideoMode() when
     * setting the video mode for this function to perform hardware flipping.
     * This function returns <code>true</code> if successful, or <code>false</code> if there was an error.</p>
     * 
     * @return <code>true</code> on success, <code>false</code> on failure.
     */
    public static boolean flip()
    {
        return _flip(0);
    }
    
    // WM
    /**
     * This function allows you to set and query the input grab state of
     * the application.  It returns the new input grab state.
     *
     * <p>Grabbing means that the mouse is confined to the application window,
     * and nearly all keyboard input is passed directly to the application,
     * and not interpreted by a window manager, if any.</p>
     * 
     * @param mode GrabMode (GRAB_QUERY, GRAB_OFF, GRAB_ON)
     * @return The new input grab state.
     */
    public static native int wmGrabInput(final int mode);
    /**
     * Sets the title and icon text of the display window (UTF-8 encoded)
     * @param title Title.
     * @param icon Icon.
     */
    public static native void wmSetCaption(final String title, final String icon);
    /**
     * This function iconifies the window, and returns <code>true</code> if it succeeded.
     * If the function succeeds, it generates an SDL_APPACTIVE loss event.
     * This function is a noop and returns <code>false</code> in non-windowed environments.
     * 
     * @return <code>true</code> on success, <code>false</code> on failure
     */
    public static native boolean wmIconifyWindow();
    private static native void _wmSetIcon(final long surface, final byte[] mask);
    private static native void _wmSetIcon(final long surface, final ByteBuffer mask);
    
    /**
     * Sets the icon for the display window.
     * This function must be called before the first call to SDL_SetVideoMode().
     * It takes an icon surface, and a mask in MSB format.
     * If 'mask' is NULL, the entire icon surface will be used as the icon.
     * 
     * @param icon The icon.
     */
    public static void wmSetIcon(final SDLSurface icon)
    {
        _wmSetIcon(icon.ptr, (ByteBuffer)null);
    }
    /**
     * Sets the icon for the display window.
     * This function must be called before the first call to SDL_SetVideoMode().
     * It takes an icon surface, and a mask in MSB format.
     * If 'mask' is NULL, the entire icon surface will be used as the icon.
     * 
     * @param icon The icon.
     * @param mask The mask
     */
    public static void wmSetIcon(final SDLSurface icon, final byte[] mask)
    {
        _wmSetIcon(icon.ptr, mask);
    }
    /**
     * Sets the icon for the display window.
     * This function must be called before the first call to SDL_SetVideoMode().
     * It takes an icon surface, and a mask in MSB format.
     * If 'mask' is NULL, the entire icon surface will be used as the icon.
     * 
     * @param icon The icon.
     * @param mask The mask
     */
    public static void wmSetIcon(final SDLSurface icon, final ByteBuffer mask)
    {
        _wmSetIcon(icon.ptr, mask);
    }

    // OpenGL
    /**
     * Swap the OpenGL buffers, if double-buffering is supported.
     */
    public static native void glSwapBuffers();
    private static native int _glGetAttribute(final int attr);
    private static native boolean _glSetAttribute(final int attr, final int value);
    /**
     * Get an attribute of the OpenGL subsystem from the windowing
     * interface, such as glX. This is of course different from getting
     * the values from SDL's internal OpenGL subsystem, which only
     * stores the values you request before initialization.
     *
     * <p>Developers should track the values they pass into SDL_GL_SetAttribute
     * themselves if they want to retrieve these values.</p>
     * 
     * @param attr Attribute to get.
     * @return Value.
     */
    public static int glGetAttribute(final GLattr attr)
    {
        return _glGetAttribute(attr.getValue());
    }
    /**
     * Set an attribute of the OpenGL subsystem before intialization.
     * 
     * @param attr Attribute to set.
     * @param value Value.
     * @return <code>true</code> on success, <code>false</code> otherwise.
     */
    public static boolean glSetAttribute(final GLattr attr, final int value)
    {
        return _glSetAttribute(attr.getValue(), value);
    }
    
    // Events/Input
    /**
     * Polls for currently pending events.
     * If no events are pending, an event of type <code>NOEVENT</code> is returned.
     * 
     * @return The polled event.
     */
    public static native SDLEvent pollEvent();
    /** Pumps the event loop, gathering events from the input devices.
     *  <p>This function updates the event queue and internal input device state.
     *  This should only be run in the thread that sets the video mode.</p>
     */
    public static native void pumpEvents();
    /**
     * Get the current key modifier state
     * 
     * @return The current key modifier state.
     */
    public static native int getModState();
    /**
     * Get the name of an SDL virtual keysym
     * 
     * @param key The key.
     * @return The name.
     */
    public static native String getKeyName(final int key);
    /**
     * Enable/Disable UNICODE translation of keyboard input.
     *
     * <p>This translation has some overhead, so translation defaults off.</p>
     *
     * @param enable <code>true</code> to enable UNICODE translation, <code>false</code> to disable it.
     * @return The previous state of keyboard translation.
     */
    public static native boolean enableUnicode(final boolean enable);
    /**
     * Enable/Disable keyboard repeat.  Keyboard repeat defaults to off.
     *
     * If 'delay' is set to 0, keyboard repeat is disabled.
     *  
     * @param delay 'delay' is the initial delay in ms between the time when a key is pressed, and keyboard repeat begins.
     * @param interval 'interval' is the time in ms between keyboard repeat events.
     * @return <code>true</code> on success, <code>false</code> otherwise.
     */
    public static native boolean enableKeyRepeat(final int delay, final int interval);
    private static native boolean _pushUserEvent(final int code);
    /**
     * Pushes the given UserEvent onto the event queue.
     * 
     * @param event UserEvent to push.
     * @return <code>true</code> on success, <code>false</code> otherwise.
     */
    public static boolean pushEvent(final UserEvent event)
    {
        return _pushUserEvent(event.code);
    }
    
    // Joystick
    /**
     * Count the number of joysticks attached to the system.
     * 
     * @return Number of joysticks.
     */
    public static native int numJoysticks();
    /**
     * Get the implementation dependent name of a joystick.
     *
     * <p>This can be called before any joysticks are opened.
     * If no name can be found, this function returns NULL.</p>
     * 
     * @param index Device index.
     * @return The joystick name.
     */
    public static native String joystickName(final int index);
    /**
     * Open a joystick for use.
     * 
     * <p>The index passed as an argument refers to
     * the N'th joystick on the system.  This index is the value which will
     * identify this joystick in future joystick events.</p>
     *
     * @param index Device index.
     * @return SDLJoystick, or NULL if an error occurred.
     */
    public static native SDLJoystick joystickOpen(final int index);
    /**
     * Returns true if the joystick has been opened, or false if it has not.
     * 
     * @return Joystick's open state.
     */
    public static native boolean joystickOpened(final int index);
    /**
     * Update the current state of the open joysticks.
     *
     * This is called automatically by the event loop if any joystick
     * events are enabled.
     */
    public static native void joystickUpdate();

    private SDL()
    {
        // empty
    }

    static
    {
        LibraryLoader.loadNative("win", "com.github.rjeschke.njsdl", "SDL.dll");
        LibraryLoader.load("com.github.rjeschke.njsdl", "njsdl");
    }
}

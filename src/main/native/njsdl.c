/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
#include <jni.h>
#include <SDL/SDL.h>
#include "ngl3.h"

static jlong ptr2Long(void* ptr)
{
#if defined(HB32) && !defined(WIN32)
    return (jlong)((uint64_t)(uint32_t)ptr);
#else
    return (jlong)((uint64_t)ptr);
#endif
}

static void* long2Ptr(jlong ptr)
{
#if defined(HB32) && !defined(WIN32)
    return (void*)((uint32_t)(uint64_t)ptr);
#else
    return (void*)((uint64_t)ptr);
#endif
}

static jobject newPixelFormat(JNIEnv* env, SDL_PixelFormat* p)
{
    jclass jcl   = (*env)->FindClass(env, "com/github/rjeschke/njsdl/SDLPixelFormat");
    return (*env)->NewObject(env,
            jcl,
            (*env)->GetMethodID(env, jcl, "<init>", "(JIIIIIIIIIIIIIIII)V"),
            ptr2Long(p),
            p->BitsPerPixel,
            p->BytesPerPixel,
            p->Rmask, p->Gmask, p->Bmask, p->Amask,
            p->Rshift, p->Gshift, p->Bshift, p->Ashift,
            p->Rloss, p->Gloss, p->Bloss, p->Aloss,
            p->colorkey, p->alpha
            );
}

static jobject newSurface(JNIEnv* env, SDL_Surface* s)
{
    jclass jcl   = (*env)->FindClass(env, "com/github/rjeschke/njsdl/SDLSurface");
    return (*env)->NewObject(env,
    		jcl,
    		(*env)->GetMethodID(env, jcl, "<init>", "(JIIIILjava/nio/ByteBuffer;Lcom/github/rjeschke/njsdl/SDLPixelFormat;Z)V"),
    		ptr2Long(s),
    		(jint)s->w,
    		(jint)s->h,
    		(jint)s->pitch,
    		(jint)s->flags,
    		(*env)->NewDirectByteBuffer(env, s->pixels, s->pitch * s->h),
    		newPixelFormat(env, s->format),
    		SDL_MUSTLOCK(s) ? JNI_TRUE : JNI_FALSE);
}

static jobject newEvent(JNIEnv* env, SDL_Event *e)
{
	jclass jcl;

	switch(e->type)
	{
	default:
	case SDL_NOEVENT:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/SDLEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(I)V"),
				SDL_NOEVENT);
    case SDL_USEREVENT:
        jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/UserEvent");
        return (*env)->NewObject(env,
                jcl,
                (*env)->GetMethodID(env, jcl, "<init>", "(I)V"),
                e->user.code);
	case SDL_QUIT:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/QuitEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "()V"));
	case SDL_ACTIVEEVENT:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/ActiveEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(II)V"),
				e->active.gain,
				e->active.state);
	case SDL_VIDEORESIZE:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/ResizeEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(II)V"),
				e->resize.w,
				e->resize.h);
	case SDL_JOYAXISMOTION:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/JoyAxisEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(III)V"),
				e->jaxis.which,
				e->jaxis.axis,
				e->jaxis.value);
	case SDL_JOYHATMOTION:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/JoyHatEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(III)V"),
				e->jhat.which,
				e->jhat.hat,
				e->jhat.value);
	case SDL_JOYBALLMOTION:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/JoyBallEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(IIII)V"),
				e->jball.which,
				e->jball.ball,
				e->jball.xrel,
				e->jball.yrel);
	case SDL_JOYBUTTONDOWN:
	case SDL_JOYBUTTONUP:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/JoyButtonEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(IIII)V"),
				e->type,
				e->jbutton.which,
				e->jbutton.button,
				e->jbutton.state);
	case SDL_MOUSEMOTION:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/MouseMotionEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(IIIIII)V"),
				e->motion.which,
				e->motion.state,
				e->motion.x,
				e->motion.y,
				e->motion.xrel,
				e->motion.yrel);
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/MouseButtonEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(IIIIII)V"),
				e->type,
				e->button.which,
				e->button.state,
				e->button.button,
				e->button.x,
				e->button.y);
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/event/KeyboardEvent");
		return (*env)->NewObject(env,
				jcl,
				(*env)->GetMethodID(env, jcl, "<init>", "(IIIIIII)V"),
				e->type,
				e->key.which,
				e->key.state,
				e->key.keysym.scancode,
				e->key.keysym.sym,
				e->key.keysym.mod,
				e->key.keysym.unicode);
	}
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL_wasInit(JNIEnv* env, jclass clazz, jint flags)
{
	return (jint)SDL_WasInit((Uint32)flags);
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL_init(JNIEnv* env, jclass clazz, jint flags)
{
	return SDL_Init((Uint32)flags) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL_initSubSystem(JNIEnv* env, jclass clazz, jint flags)
{
	return SDL_InitSubSystem((Uint32)flags) == 0 ? JNI_TRUE : JNI_FALSE;
}

static void initGL3()
{
    int i;
    char* ptr;

    i = 0;
    ptr = (char*)ngl3Names;
    while(*ptr)
    {
#if defined(WIN32)
        ngl3Funcs[i] = wglGetProcAddress(ptr);
#elif defined(LINUX)
        ngl3Funcs[i] = glXGetProcAddress((GLubyte*)ptr);
#else
        ngl3Funcs[i] = SDL_GL_GetProcAddress(ptr);
#endif
        while(*ptr != 0)
            ptr++;
        ptr++;
        i++;
    }
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_quitSubSystem(JNIEnv* env, jclass clazz, jint flags)
{
	SDL_QuitSubSystem((Uint32)flags);
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_quit(JNIEnv* env, jclass clazz)
{
	SDL_Quit();
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_clearError(JNIEnv* env, jclass clazz)
{
    SDL_ClearError();
}

JNIEXPORT jstring JNICALL Java_com_github_rjeschke_njsdl_SDL_getError(JNIEnv* env, jclass clazz)
{
    char* err = SDL_GetError();
    return err ? (*env)->NewStringUTF(env, err) : NULL;
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDL_pollEvent(JNIEnv* env, jclass clazz)
{
	SDL_Event e;
	int flag = SDL_PollEvent(&e);
	if(!flag)
		e.type = SDL_NOEVENT;
	return newEvent(env, &e);
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_pumpEvents(JNIEnv* env, jclass clazz)
{
    SDL_PumpEvents();
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL__1pushUserEvent(JNIEnv* env, jclass clazz, jint code)
{
    SDL_Event e;
    e.type = SDL_USEREVENT;
    e.user.code = code;
    e.user.data1 = NULL;
    e.user.data2 = NULL;
    return SDL_PushEvent(&e) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL_getModState(JNIEnv* env, jclass clazz)
{
    return (jint)SDL_GetModState();
}

JNIEXPORT jstring JNICALL Java_com_github_rjeschke_njsdl_SDL_getKeyName(JNIEnv* env, jclass clazz, jint key)
{
    const char* name = SDL_GetKeyName((SDLKey)key);
    return name ? (*env)->NewStringUTF(env, name) : NULL;
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL_enableUnicode(JNIEnv* env, jclass clazz, jboolean enable)
{
    return SDL_EnableUNICODE(enable == JNI_TRUE ? 1 : 0) == 1 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL_enableKeyRepeat(JNIEnv* env, jclass clazz, jint delay, jint interval)
{
    return SDL_EnableKeyRepeat(delay, interval) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDL_setVideoMode(JNIEnv* env, jclass clazz, jint width, jint height, jint bpp, jint flags)
{
	SDL_Surface* s = SDL_SetVideoMode(width, height, bpp, (Uint32)flags);
	if(s && (flags & SDL_OPENGL))
	    initGL3();
	return s ? newSurface(env, s) : NULL;
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDL_getVideoSurface(JNIEnv* env, jclass clazz)
{
    SDL_Surface* s = SDL_GetVideoSurface();
    return s ? newSurface(env, s) : NULL;
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL_videoModeOK(JNIEnv* env, jclass clazz, jint width, jint height, jint bpp, jint flags)
{
	return (jint)SDL_VideoModeOK(width, height, bpp, (Uint32)flags);
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDL_createRGBSurface(JNIEnv* env, jclass clazz, jint flags, jint width, jint height, jint depth, jint rmask, jint gmask, jint bmask, jint amask)
{
    SDL_Surface* s = SDL_CreateRGBSurface((Uint32)flags, width, height, depth, (Uint32)rmask, (Uint32)gmask, (Uint32)bmask, (Uint32)amask);
    return s ? newSurface(env, s) : NULL;
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDL_createRGBSurfaceFrom(JNIEnv* env, jclass clazz, jobject pixels, jint width, jint height, jint depth, jint pitch, jint rmask, jint gmask, jint bmask, jint amask)
{
    SDL_Surface* s = SDL_CreateRGBSurfaceFrom((*env)->GetDirectBufferAddress(env, pixels), width, height, depth, pitch, (Uint32)rmask, (Uint32)gmask, (Uint32)bmask, (Uint32)amask);
    return s ? newSurface(env, s) : NULL;
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL_wmGrabInput(JNIEnv* env, jclass clazz, jint mode)
{
    return (jint)SDL_WM_GrabInput((SDL_GrabMode)mode);
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_wmSetCaption(JNIEnv* env, jclass clazz, jstring jTitle, jstring jIcon)
{
    const char* title = jTitle ? (*env)->GetStringUTFChars(env, jTitle, NULL) : NULL;
    const char* icon = jIcon ? (*env)->GetStringUTFChars(env, jIcon, NULL) : NULL;

    SDL_WM_SetCaption(title, icon);

    if(title)   (*env)->ReleaseStringUTFChars(env, jTitle, title);
    if(icon)    (*env)->ReleaseStringUTFChars(env, jIcon, icon);
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL_wmIconifyWindow(JNIEnv* env, jclass clazz)
{
    return SDL_WM_IconifyWindow() != 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL__1wmSetIcon__J_3B(JNIEnv* env, jclass clazz, jlong ptr, jbyteArray jMask)
{
    Uint8* mask = jMask ? (Uint8*)(*env)->GetPrimitiveArrayCritical(env, jMask, NULL) : NULL;
    SDL_WM_SetIcon((SDL_Surface*)long2Ptr(ptr), mask);
    if(mask) (*env)->ReleasePrimitiveArrayCritical(env, jMask, mask, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL__1wmSetIcon__JLjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jlong ptr, jobject mask)
{
    SDL_WM_SetIcon((SDL_Surface*)long2Ptr(ptr), mask ? (Uint8*)(*env)->GetDirectBufferAddress(env, mask) : NULL);
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_glSwapBuffers(JNIEnv* env, jclass clazz)
{
    SDL_GL_SwapBuffers();
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL__1glGetAttribute(JNIEnv* env, jclass clazz, jint attr)
{
    int value = 0;
    SDL_GL_GetAttribute((SDL_GLattr)attr, &value);
    return value;
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL__1glSetAttribute(JNIEnv* env, jclass clazz, jint attr, jint value)
{
    return SDL_GL_SetAttribute((SDL_GLattr)attr, value) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL__1updateRect(JNIEnv* env, jclass clazz, jlong ptr, jint x, jint y, jint width, jint height)
{
	SDL_UpdateRect(
			ptr ? (SDL_Surface*)long2Ptr(ptr) : SDL_GetVideoSurface(),
			x,
			y,
			width,
			height
			);
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL__1flip(JNIEnv* env, jclass clazz, jlong ptr)
{
	return SDL_Flip(ptr ? (SDL_Surface*)long2Ptr(ptr) : SDL_GetVideoSurface()) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL_showCursor(JNIEnv* env, jclass clazz, jint toggle)
{
	return (jint)SDL_ShowCursor(toggle);
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1displayFormat(JNIEnv* env, jclass clazz, jlong ptr)
{
    SDL_Surface* s = SDL_DisplayFormat((SDL_Surface*)long2Ptr(ptr));
    return s ? newSurface(env, s) : NULL;
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1displayFormatAlpha(JNIEnv* env, jclass clazz, jlong ptr)
{
    SDL_Surface* s = SDL_DisplayFormatAlpha((SDL_Surface*)long2Ptr(ptr));
    return s ? newSurface(env, s) : NULL;
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1mustLock(JNIEnv* env, jclass clazz, jlong ptr)
{
	return (jint)SDL_MUSTLOCK(((SDL_Surface*)long2Ptr(ptr)));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1lock(JNIEnv* env, jclass clazz, jlong ptr)
{
	return (jint)SDL_LockSurface((SDL_Surface*)long2Ptr(ptr));
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1unlock(JNIEnv* env, jclass clazz, jlong ptr)
{
	SDL_UnlockSurface((SDL_Surface*)long2Ptr(ptr));
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1free(JNIEnv* env, jclass clazz, jlong ptr)
{
	SDL_FreeSurface((SDL_Surface*)long2Ptr(ptr));
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1fillRect(JNIEnv* env, jclass clazz, jlong ptr, jint x, jint y, jint w, jint h, jint color)
{
    SDL_Rect r;
    if(w < 1 || h < 1)
        return SDL_FillRect((SDL_Surface*)long2Ptr(ptr), NULL, (Uint32)color) == 0 ? JNI_TRUE : JNI_FALSE;
    r.x = (Sint16)x;
    r.y = (Sint16)y;
    r.w = (Uint16)w;
    r.h = (Uint16)h;
    return SDL_FillRect((SDL_Surface*)long2Ptr(ptr), &r, (Uint32)color) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDLSurface__1blit(JNIEnv* env, jclass clazz,
		jlong src, jint sx, jint sy, jint sw, jint sh,
		jlong dst, jint dx, jint dy)
{
	SDL_Rect s, d;
	s.x = (Sint16)sx;
	s.y = (Sint16)sy;
	s.w = (Uint16)sw;
	s.h = (Uint16)sh;

	d.x = (Sint16)dx;
	d.y = (Sint16)dy;
	d.w = (Uint16)sw;
	d.h = (Uint16)sh;

	return SDL_BlitSurface(((SDL_Surface*)long2Ptr(src)), (&s), ((SDL_Surface*)long2Ptr(dst)), (&d)) == 0 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDL_numJoysticks(JNIEnv* env, jclass clazz)
{
	return SDL_NumJoysticks();
}

JNIEXPORT jstring JNICALL Java_com_github_rjeschke_njsdl_SDL_joystickName(JNIEnv* env, jclass clazz, jint index)
{
	const char* name = SDL_JoystickName(index);
	return name ? (*env)->NewStringUTF(env, name) : NULL;
}

JNIEXPORT jobject JNICALL Java_com_github_rjeschke_njsdl_SDL_joystickOpen(JNIEnv* env, jclass clazz, jint index)
{
	jclass jcl = (*env)->FindClass(env, "com/github/rjeschke/njsdl/SDLJoystick");
	SDL_Joystick* joy = SDL_JoystickOpen(index);
	if(!joy)
		return NULL;
	return (*env)->NewObject(env, jcl, (*env)->GetMethodID(env, jcl, "<init>", "(J)V"), ptr2Long(joy));
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDL_joystickOpened(JNIEnv* env, jclass clazz, jint index)
{
	return SDL_JoystickOpened(index) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDL_joystickUpdate(JNIEnv* env, jclass clazz)
{
	SDL_JoystickUpdate();
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1joystickIndex(JNIEnv* env, jclass clazz, jlong ptr)
{
	return SDL_JoystickIndex((SDL_Joystick*)long2Ptr(ptr));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1joystickNumAxes(JNIEnv* env, jclass clazz, jlong ptr)
{
	return SDL_JoystickNumAxes((SDL_Joystick*)long2Ptr(ptr));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1joystickNumBalls(JNIEnv* env, jclass clazz, jlong ptr)
{
	return SDL_JoystickNumBalls((SDL_Joystick*)long2Ptr(ptr));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1joystickNumHats(JNIEnv* env, jclass clazz, jlong ptr)
{
	return SDL_JoystickNumHats((SDL_Joystick*)long2Ptr(ptr));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1joystickNumButtons(JNIEnv* env, jclass clazz, jlong ptr)
{
	return SDL_JoystickNumButtons((SDL_Joystick*)long2Ptr(ptr));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1getAxis(JNIEnv* env, jclass clazz, jlong ptr, jint axis)
{
    return (jint)SDL_JoystickGetAxis((SDL_Joystick*)long2Ptr(ptr), axis);
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1getHat(JNIEnv* env, jclass clazz, jlong ptr, jint hat)
{
    return (jint)SDL_JoystickGetHat((SDL_Joystick*)long2Ptr(ptr), hat);
}

JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1getButton(JNIEnv* env, jclass clazz, jlong ptr, jint button)
{
    return (jint)SDL_JoystickGetButton((SDL_Joystick*)long2Ptr(ptr), button) == 1 ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_SDLJoystick__1close(JNIEnv* env, jclass clazz, jlong ptr)
{
	SDL_JoystickClose((SDL_Joystick*)long2Ptr(ptr));
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLPixelFormat__1mapRGB(JNIEnv* env, jclass clazz, jlong ptr, jint r, jint g, jint b)
{
    return (jint)SDL_MapRGB((const SDL_PixelFormat*)long2Ptr(ptr), (Uint8)r, (Uint8)g, (Uint8)b);
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLPixelFormat__1mapRGBA(JNIEnv* env, jclass clazz, jlong ptr, jint r, jint g, jint b, jint a)
{
    return (jint)SDL_MapRGBA((const SDL_PixelFormat*)long2Ptr(ptr), (Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a);
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLPixelFormat__1getRGB(JNIEnv* env, jclass clazz, jlong ptr, jint pixel)
{
    Uint8 r, g, b;
    SDL_GetRGB((Uint32)pixel, (const SDL_PixelFormat*)long2Ptr(ptr), &r, &g, &b);
    return (jint)(((Uint32)r << 16) | ((Uint32)g << 8) | (Uint32)b);
}

JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_SDLPixelFormat__1getRGBA(JNIEnv* env, jclass clazz, jlong ptr, jint pixel)
{
    Uint8 r, g, b, a;
    SDL_GetRGBA((Uint32)pixel, (const SDL_PixelFormat*)long2Ptr(ptr), &r, &g, &b, &a);
    return (jint)(((Uint32)a << 24) | ((Uint32)r << 16) | ((Uint32)g << 8) | (Uint32)b);
}

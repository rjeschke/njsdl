/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
#include <jni.h>
#ifdef MACOS
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#include <string.h>
#include "ngl3.h"

#ifdef WIN32
typedef unsigned __int32 uint32_t;
#endif

static const char** newNativeStringArray(JNIEnv* env, jobjectArray array)
{
    int i, size;
    char** ret;
    if(!array)
    {
        return 0;
    }
    size = (int)((*env)->GetArrayLength(env, array));
    ret = (char**)malloc(sizeof(void*) * (size + 1));

    for(i = 0; i < size; i++)
    {
        jstring      str = (jstring)((*env)->GetObjectArrayElement(env, array, i));
        if(str)
        {
            const char* nstr = (*env)->GetStringUTFChars(env, str, 0);
            ret[i] = (char*)malloc(strlen(nstr) + 1);
            strcpy(ret[i], nstr);
            (*env)->ReleaseStringUTFChars(env, str, nstr);
        }
        else
        {
            ret[i] = 0;
        }
    }

    ret[size] = 0;
    return (const char**)ret;
}

static void freeNativeStringArray(const char** array)
{
    int i = 0;
    if(array)
    {
        while(array[i])
        {
            free((void*)array[i++]);
        }
        free((void*)array);
    }
}

static void** newNativeBufferArray(JNIEnv* env, jobjectArray array)
{
    int i, size;
    void** ret;
    if(!array)
    {
        return 0;
    }
    size = (int)((*env)->GetArrayLength(env, array));
    ret = (void**)malloc(sizeof(void*) * (size + 1));

    for(i = 0; i < size; i++)
    {
        jobject obj = ((*env)->GetObjectArrayElement(env, array, i));
        ret[i] = obj ? (*env)->GetDirectBufferAddress(env, obj) : 0;
    }
    ret[size] = 0;
    return ret;
}

static void freeNativeBufferArray(void** array)
{
    free(array);
}


static void* long2Ptr(jlong ptr)
{
#if defined(HB32) && !defined(WIN32)
    return (void*)((uint32_t)(uint64_t)ptr);
#else
    return (void*)((uint64_t)ptr);
#endif
}

// void glBlendFunc(GLenum sfactor, GLenum dfactor);
// public static native void glBlendFunc(int sfactor, int dfactor);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendFunc(JNIEnv* env, jclass clazz, jint sfactor, jint dfactor)
{
    glBlendFunc(
        (GLenum)sfactor,
        (GLenum)dfactor);
}

// void glClear(GLbitfield mask);
// public static native void glClear(int mask);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClear(JNIEnv* env, jclass clazz, jint mask)
{
    glClear(
        (GLbitfield)mask);
}

// void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
// public static native void glClearColor(float red, float green, float blue, float alpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearColor(JNIEnv* env, jclass clazz, jfloat red, jfloat green, jfloat blue, jfloat alpha)
{
    glClearColor(
        (GLclampf)red,
        (GLclampf)green,
        (GLclampf)blue,
        (GLclampf)alpha);
}

// void glClearDepth(GLclampd depth);
// public static native void glClearDepth(double depth);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearDepth(JNIEnv* env, jclass clazz, jdouble depth)
{
    glClearDepth(
        (GLclampd)depth);
}

// void glClearStencil(GLint s);
// public static native void glClearStencil(int s);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearStencil(JNIEnv* env, jclass clazz, jint s)
{
    glClearStencil(
        (GLint)s);
}

// void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
// public static native void glColorMask(boolean red, boolean green, boolean blue, boolean alpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorMask(JNIEnv* env, jclass clazz, jboolean red, jboolean green, jboolean blue, jboolean alpha)
{
    glColorMask(
        (GLboolean)(red == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLboolean)(green == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLboolean)(blue == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLboolean)(alpha == JNI_TRUE ? GL_TRUE : GL_FALSE));
}

// void glCullFace(GLenum mode);
// public static native void glCullFace(int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCullFace(JNIEnv* env, jclass clazz, jint mode)
{
    glCullFace(
        (GLenum)mode);
}

// void glDepthFunc(GLenum func);
// public static native void glDepthFunc(int func);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthFunc(JNIEnv* env, jclass clazz, jint func)
{
    glDepthFunc(
        (GLenum)func);
}

// void glDepthMask(GLboolean flag);
// public static native void glDepthMask(boolean flag);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthMask(JNIEnv* env, jclass clazz, jboolean flag)
{
    glDepthMask(
        (GLboolean)(flag == JNI_TRUE ? GL_TRUE : GL_FALSE));
}

// void glDepthRange(GLclampd near, GLclampd far);
// public static native void glDepthRange(double near, double far);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthRange(JNIEnv* env, jclass clazz, jdouble p_near, jdouble p_far)
{
    glDepthRange(
        (GLclampd)p_near,
        (GLclampd)p_far);
}

// void glDisable(GLenum cap);
// public static native void glDisable(int cap);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDisable(JNIEnv* env, jclass clazz, jint cap)
{
    glDisable(
        (GLenum)cap);
}

// void glDrawBuffer(GLenum mode);
// public static native void glDrawBuffer(int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawBuffer(JNIEnv* env, jclass clazz, jint mode)
{
    glDrawBuffer(
        (GLenum)mode);
}

// void glEnable(GLenum cap);
// public static native void glEnable(int cap);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEnable(JNIEnv* env, jclass clazz, jint cap)
{
    glEnable(
        (GLenum)cap);
}

// void glFinish();
// public static native void glFinish();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFinish(JNIEnv* env, jclass clazz)
{
    glFinish();
}

// void glFlush();
// public static native void glFlush();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFlush(JNIEnv* env, jclass clazz)
{
    glFlush();
}

// void glFrontFace(GLenum mode);
// public static native void glFrontFace(int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFrontFace(JNIEnv* env, jclass clazz, jint mode)
{
    glFrontFace(
        (GLenum)mode);
}

// void glGetBooleanv(GLenum pname, GLboolean* params);
// public static native void glGetBooleanv(int pname, ByteBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBooleanv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glGetBooleanv(
        (GLenum)pname,
        (GLboolean*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetBooleanv(GLenum pname, GLboolean* params);
// public static native void glGetBooleanv(int pname, byte[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBooleanv__I_3BI(JNIEnv* env, jclass clazz, jint pname, jbyteArray params, jint paramsOffset)
{
    jbyte* j_params = params ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetBooleanv(
        (GLenum)pname,
        (GLboolean*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetDoublev(GLenum pname, GLdouble* params);
// public static native void glGetDoublev(int pname, DoubleBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetDoublev__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glGetDoublev(
        (GLenum)pname,
        (GLdouble*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetDoublev(GLenum pname, GLdouble* params);
// public static native void glGetDoublev(int pname, double[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetDoublev__I_3DI(JNIEnv* env, jclass clazz, jint pname, jdoubleArray params, jint paramsOffset)
{
    jdouble* j_params = params ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetDoublev(
        (GLenum)pname,
        (GLdouble*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLenum glGetError();
// public static native int glGetError();
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetError(JNIEnv* env, jclass clazz)
{
    return (jint)
        glGetError();
}

// void glGetFloatv(GLenum pname, GLfloat* params);
// public static native void glGetFloatv(int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFloatv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glGetFloatv(
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetFloatv(GLenum pname, GLfloat* params);
// public static native void glGetFloatv(int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFloatv__I_3FI(JNIEnv* env, jclass clazz, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetFloatv(
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetIntegerv(GLenum pname, GLint* params);
// public static native void glGetIntegerv(int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetIntegerv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glGetIntegerv(
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetIntegerv(GLenum pname, GLint* params);
// public static native void glGetIntegerv(int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetIntegerv__I_3II(JNIEnv* env, jclass clazz, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetIntegerv(
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLubyte* glGetString(GLenum name);
// public static native String glGetString(int name);
JNIEXPORT jstring JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetString(JNIEnv* env, jclass clazz, jint name)
{
    GLubyte* ret = (GLubyte*)
        glGetString(
        (GLenum)name);
    return (*env)->NewStringUTF(env, (char*)ret);
}

// void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glGetTexImage(int target, int level, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexImage__IIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint format, jint type, jobject pixels)
{
    glGetTexImage(
        (GLenum)target,
        (GLint)level,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glGetTexImage(int target, int level, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexImage__IIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint format, jint type, jlong pixels)
{
    glGetTexImage(
        (GLenum)target,
        (GLint)level,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
// public static native void glGetTexLevelParameterfv(int target, int level, int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexLevelParameterfv__IIILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint pname, jobject params)
{
    glGetTexLevelParameterfv(
        (GLenum)target,
        (GLint)level,
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
// public static native void glGetTexLevelParameterfv(int target, int level, int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexLevelParameterfv__III_3FI(JNIEnv* env, jclass clazz, jint target, jint level, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetTexLevelParameterfv(
        (GLenum)target,
        (GLint)level,
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
// public static native void glGetTexLevelParameteriv(int target, int level, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexLevelParameteriv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint pname, jobject params)
{
    glGetTexLevelParameteriv(
        (GLenum)target,
        (GLint)level,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
// public static native void glGetTexLevelParameteriv(int target, int level, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexLevelParameteriv__III_3II(JNIEnv* env, jclass clazz, jint target, jint level, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetTexLevelParameteriv(
        (GLenum)target,
        (GLint)level,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
// public static native void glGetTexParameterfv(int target, int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameterfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetTexParameterfv(
        (GLenum)target,
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
// public static native void glGetTexParameterfv(int target, int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameterfv__II_3FI(JNIEnv* env, jclass clazz, jint target, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetTexParameterfv(
        (GLenum)target,
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetTexParameteriv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameteriv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetTexParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetTexParameteriv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameteriv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetTexParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glHint(GLenum target, GLenum mode);
// public static native void glHint(int target, int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glHint(JNIEnv* env, jclass clazz, jint target, jint mode)
{
    glHint(
        (GLenum)target,
        (GLenum)mode);
}

// GLboolean glIsEnabled(GLenum cap);
// public static native boolean glIsEnabled(int cap);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsEnabled(JNIEnv* env, jclass clazz, jint cap)
{
    GLboolean ret = (GLboolean)
        glIsEnabled(
        (GLenum)cap);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glLineWidth(GLfloat width);
// public static native void glLineWidth(float width);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glLineWidth(JNIEnv* env, jclass clazz, jfloat width)
{
    glLineWidth(
        (GLfloat)width);
}

// void glLogicOp(GLenum opcode);
// public static native void glLogicOp(int opcode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glLogicOp(JNIEnv* env, jclass clazz, jint opcode)
{
    glLogicOp(
        (GLenum)opcode);
}

// void glPixelStoref(GLenum pname, GLfloat param);
// public static native void glPixelStoref(int pname, float param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPixelStoref(JNIEnv* env, jclass clazz, jint pname, jfloat param)
{
    glPixelStoref(
        (GLenum)pname,
        (GLfloat)param);
}

// void glPixelStorei(GLenum pname, GLint param);
// public static native void glPixelStorei(int pname, int param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPixelStorei(JNIEnv* env, jclass clazz, jint pname, jint param)
{
    glPixelStorei(
        (GLenum)pname,
        (GLint)param);
}

// void glPointSize(GLfloat size);
// public static native void glPointSize(float size);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointSize(JNIEnv* env, jclass clazz, jfloat size)
{
    glPointSize(
        (GLfloat)size);
}

// void glPolygonMode(GLenum face, GLenum mode);
// public static native void glPolygonMode(int face, int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPolygonMode(JNIEnv* env, jclass clazz, jint face, jint mode)
{
    glPolygonMode(
        (GLenum)face,
        (GLenum)mode);
}

// void glReadBuffer(GLenum mode);
// public static native void glReadBuffer(int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glReadBuffer(JNIEnv* env, jclass clazz, jint mode)
{
    glReadBuffer(
        (GLenum)mode);
}

// void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glReadPixels(int x, int y, int width, int height, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glReadPixels__IIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint x, jint y, jint width, jint height, jint format, jint type, jobject pixels)
{
    glReadPixels(
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glReadPixels(int x, int y, int width, int height, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glReadPixels__IIIIIIJ(JNIEnv* env, jclass clazz, jint x, jint y, jint width, jint height, jint format, jint type, jlong pixels)
{
    glReadPixels(
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
// public static native void glScissor(int x, int y, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glScissor(JNIEnv* env, jclass clazz, jint x, jint y, jint width, jint height)
{
    glScissor(
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height);
}

// void glStencilFunc(GLenum func, GLint ref, GLuint mask);
// public static native void glStencilFunc(int func, int ref, int mask);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glStencilFunc(JNIEnv* env, jclass clazz, jint func, jint ref, jint mask)
{
    glStencilFunc(
        (GLenum)func,
        (GLint)ref,
        (GLuint)mask);
}

// void glStencilMask(GLuint mask);
// public static native void glStencilMask(int mask);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glStencilMask(JNIEnv* env, jclass clazz, jint mask)
{
    glStencilMask(
        (GLuint)mask);
}

// void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
// public static native void glStencilOp(int fail, int zfail, int zpass);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glStencilOp(JNIEnv* env, jclass clazz, jint fail, jint zfail, jint zpass)
{
    glStencilOp(
        (GLenum)fail,
        (GLenum)zfail,
        (GLenum)zpass);
}

// void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexImage1D(int target, int level, int internalformat, int width, int border, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage1D__IIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint border, jint format, jint type, jobject pixels)
{
    glTexImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)internalformat,
        (GLsizei)width,
        (GLint)border,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexImage1D(int target, int level, int internalformat, int width, int border, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage1D__IIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint border, jint format, jint type, jlong pixels)
{
    glTexImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)internalformat,
        (GLsizei)width,
        (GLint)border,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage2D__IIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint format, jint type, jobject pixels)
{
    glTexImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLint)border,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage2D__IIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint format, jint type, jlong pixels)
{
    glTexImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLint)border,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
// public static native void glTexParameterf(int target, int pname, float param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterf(JNIEnv* env, jclass clazz, jint target, jint pname, jfloat param)
{
    glTexParameterf(
        (GLenum)target,
        (GLenum)pname,
        (GLfloat)param);
}

// void glTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
// public static native void glTexParameterfv(int target, int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glTexParameterfv(
        (GLenum)target,
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
// public static native void glTexParameterfv(int target, int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterfv__II_3FI(JNIEnv* env, jclass clazz, jint target, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glTexParameterfv(
        (GLenum)target,
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glTexParameteri(GLenum target, GLenum pname, GLint param);
// public static native void glTexParameteri(int target, int pname, int param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameteri(JNIEnv* env, jclass clazz, jint target, jint pname, jint param)
{
    glTexParameteri(
        (GLenum)target,
        (GLenum)pname,
        (GLint)param);
}

// void glTexParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glTexParameteriv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameteriv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glTexParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glTexParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glTexParameteriv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameteriv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glTexParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
// public static native void glViewport(int x, int y, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glViewport(JNIEnv* env, jclass clazz, jint x, jint y, jint width, jint height)
{
    glViewport(
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height);
}

// void glBindTexture(GLenum target, GLuint texture);
// public static native void glBindTexture(int target, int texture);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindTexture(JNIEnv* env, jclass clazz, jint target, jint texture)
{
    glBindTexture(
        (GLenum)target,
        (GLuint)texture);
}

// void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
// public static native void glCopyTexImage1D(int target, int level, int internalformat, int x, int y, int width, int border);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCopyTexImage1D(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint x, jint y, jint width, jint border)
{
    glCopyTexImage1D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLint)border);
}

// void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
// public static native void glCopyTexImage2D(int target, int level, int internalformat, int x, int y, int width, int height, int border);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCopyTexImage2D(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint x, jint y, jint width, jint height, jint border)
{
    glCopyTexImage2D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height,
        (GLint)border);
}

// void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
// public static native void glCopyTexSubImage1D(int target, int level, int xoffset, int x, int y, int width);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCopyTexSubImage1D(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint x, jint y, jint width)
{
    glCopyTexSubImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)x,
        (GLint)y,
        (GLsizei)width);
}

// void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
// public static native void glCopyTexSubImage2D(int target, int level, int xoffset, int yoffset, int x, int y, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCopyTexSubImage2D(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint x, jint y, jint width, jint height)
{
    glCopyTexSubImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height);
}

// void glDeleteTextures(GLsizei n, GLuint* textures);
// public static native void glDeleteTextures(int n, IntBuffer textures);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteTextures__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject textures)
{
    glDeleteTextures(
        (GLsizei)n,
        (GLuint*)(textures ? (*env)->GetDirectBufferAddress(env, textures) : 0));
}

// void glDeleteTextures(GLsizei n, GLuint* textures);
// public static native void glDeleteTextures(int n, int[] textures, int texturesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteTextures__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray textures, jint texturesOffset)
{
    jint* j_textures = textures ? (jint*)((*env)->GetPrimitiveArrayCritical(env, textures, 0)) : 0;
    glDeleteTextures(
        (GLsizei)n,
        (GLuint*)(j_textures + texturesOffset));
    if(textures) (*env)->ReleasePrimitiveArrayCritical(env, textures, j_textures, 0);
}

// void glDrawArrays(GLenum mode, GLint first, GLsizei count);
// public static native void glDrawArrays(int mode, int first, int count);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawArrays(JNIEnv* env, jclass clazz, jint mode, jint first, jint count)
{
    glDrawArrays(
        (GLenum)mode,
        (GLint)first,
        (GLsizei)count);
}

// void glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid* indices);
// public static native void glDrawElements(int mode, int count, int type, Buffer indices);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElements__IIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jobject indices)
{
    glDrawElements(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0));
}

// void glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid* indices);
// public static native void glDrawElements(int mode, int count, int type, long indices);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElements__IIIJ(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jlong indices)
{
    glDrawElements(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)long2Ptr(indices));
}

// void glGenTextures(GLsizei n, GLuint* textures);
// public static native void glGenTextures(int n, IntBuffer textures);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenTextures__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject textures)
{
    glGenTextures(
        (GLsizei)n,
        (GLuint*)(textures ? (*env)->GetDirectBufferAddress(env, textures) : 0));
}

// void glGenTextures(GLsizei n, GLuint* textures);
// public static native void glGenTextures(int n, int[] textures, int texturesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenTextures__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray textures, jint texturesOffset)
{
    jint* j_textures = textures ? (jint*)((*env)->GetPrimitiveArrayCritical(env, textures, 0)) : 0;
    glGenTextures(
        (GLsizei)n,
        (GLuint*)(j_textures + texturesOffset));
    if(textures) (*env)->ReleasePrimitiveArrayCritical(env, textures, j_textures, 0);
}

// GLboolean glIsTexture(GLuint texture);
// public static native boolean glIsTexture(int texture);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsTexture(JNIEnv* env, jclass clazz, jint texture)
{
    GLboolean ret = (GLboolean)
        glIsTexture(
        (GLuint)texture);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glPolygonOffset(GLfloat factor, GLfloat units);
// public static native void glPolygonOffset(float factor, float units);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPolygonOffset(JNIEnv* env, jclass clazz, jfloat factor, jfloat units)
{
    glPolygonOffset(
        (GLfloat)factor,
        (GLfloat)units);
}

// void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexSubImage1D(int target, int level, int xoffset, int width, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexSubImage1D__IIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint width, jint format, jint type, jobject pixels)
{
    glTexSubImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLsizei)width,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexSubImage1D(int target, int level, int xoffset, int width, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexSubImage1D__IIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint width, jint format, jint type, jlong pixels)
{
    glTexSubImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLsizei)width,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexSubImage2D__IIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint type, jobject pixels)
{
    glTexSubImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexSubImage2D__IIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint type, jlong pixels)
{
    glTexSubImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
// public static native void glBlendColor(float red, float green, float blue, float alpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendColor(JNIEnv* env, jclass clazz, jfloat red, jfloat green, jfloat blue, jfloat alpha)
{
    glBlendColor(
        (GLclampf)red,
        (GLclampf)green,
        (GLclampf)blue,
        (GLclampf)alpha);
}

// void glBlendEquation(GLenum mode);
// public static native void glBlendEquation(int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendEquation(JNIEnv* env, jclass clazz, jint mode)
{
    glBlendEquation(
        (GLenum)mode);
}

// void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
// public static native void glCopyTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCopyTexSubImage3D(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint zoffset, jint x, jint y, jint width, jint height)
{
    glCopyTexSubImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLint)zoffset,
        (GLint)x,
        (GLint)y,
        (GLsizei)width,
        (GLsizei)height);
}

// void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices);
// public static native void glDrawRangeElements(int mode, int start, int end, int count, int type, Buffer indices);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawRangeElements__IIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint mode, jint start, jint end, jint count, jint type, jobject indices)
{
    glDrawRangeElements(
        (GLenum)mode,
        (GLuint)start,
        (GLuint)end,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0));
}

// void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices);
// public static native void glDrawRangeElements(int mode, int start, int end, int count, int type, long indices);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawRangeElements__IIIIIJ(JNIEnv* env, jclass clazz, jint mode, jint start, jint end, jint count, jint type, jlong indices)
{
    glDrawRangeElements(
        (GLenum)mode,
        (GLuint)start,
        (GLuint)end,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)long2Ptr(indices));
}

// void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage3D__IIIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint depth, jint border, jint format, jint type, jobject pixels)
{
    glTexImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLint)border,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage3D__IIIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint depth, jint border, jint format, jint type, jlong pixels)
{
    glTexImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLint)border,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int type, Buffer pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexSubImage3D__IIIIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint zoffset, jint width, jint height, jint depth, jint format, jint type, jobject pixels)
{
    glTexSubImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLint)zoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)(pixels ? (*env)->GetDirectBufferAddress(env, pixels) : 0));
}

// void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid* pixels);
// public static native void glTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int type, long pixels);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexSubImage3D__IIIIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint zoffset, jint width, jint height, jint depth, jint format, jint type, jlong pixels)
{
    glTexSubImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLint)zoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLenum)format,
        (GLenum)type,
        (GLvoid*)long2Ptr(pixels));
}

// void glActiveTexture(GLenum texture);
// public static native void glActiveTexture(int texture);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glActiveTexture(JNIEnv* env, jclass clazz, jint texture)
{
    glActiveTexture(
        (GLenum)texture);
}

// void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexImage1D(int target, int level, int internalformat, int width, int border, int imageSize, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexImage1D__IIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint border, jint imageSize, jobject data)
{
    glCompressedTexImage1D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLint)border,
        (GLsizei)imageSize,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexImage1D(int target, int level, int internalformat, int width, int border, int imageSize, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexImage1D__IIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint border, jint imageSize, jlong data)
{
    glCompressedTexImage1D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLint)border,
        (GLsizei)imageSize,
        (GLvoid*)long2Ptr(data));
}

// void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexImage2D(int target, int level, int internalformat, int width, int height, int border, int imageSize, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexImage2D__IIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint imageSize, jobject data)
{
    glCompressedTexImage2D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLint)border,
        (GLsizei)imageSize,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexImage2D(int target, int level, int internalformat, int width, int height, int border, int imageSize, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexImage2D__IIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint imageSize, jlong data)
{
    glCompressedTexImage2D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLint)border,
        (GLsizei)imageSize,
        (GLvoid*)long2Ptr(data));
}

// void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int imageSize, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexImage3D__IIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint depth, jint border, jint imageSize, jobject data)
{
    glCompressedTexImage3D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLint)border,
        (GLsizei)imageSize,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int imageSize, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexImage3D__IIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint internalformat, jint width, jint height, jint depth, jint border, jint imageSize, jlong data)
{
    glCompressedTexImage3D(
        (GLenum)target,
        (GLint)level,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLint)border,
        (GLsizei)imageSize,
        (GLvoid*)long2Ptr(data));
}

// void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexSubImage1D(int target, int level, int xoffset, int width, int format, int imageSize, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexSubImage1D__IIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint width, jint format, jint imageSize, jobject data)
{
    glCompressedTexSubImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLsizei)width,
        (GLenum)format,
        (GLsizei)imageSize,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexSubImage1D(int target, int level, int xoffset, int width, int format, int imageSize, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexSubImage1D__IIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint width, jint format, jint imageSize, jlong data)
{
    glCompressedTexSubImage1D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLsizei)width,
        (GLenum)format,
        (GLsizei)imageSize,
        (GLvoid*)long2Ptr(data));
}

// void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int imageSize, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexSubImage2D__IIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint imageSize, jobject data)
{
    glCompressedTexSubImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLenum)format,
        (GLsizei)imageSize,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int imageSize, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexSubImage2D__IIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint imageSize, jlong data)
{
    glCompressedTexSubImage2D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLenum)format,
        (GLsizei)imageSize,
        (GLvoid*)long2Ptr(data));
}

// void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int imageSize, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexSubImage3D__IIIIIIIIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint zoffset, jint width, jint height, jint depth, jint format, jint imageSize, jobject data)
{
    glCompressedTexSubImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLint)zoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLenum)format,
        (GLsizei)imageSize,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid* data);
// public static native void glCompressedTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int imageSize, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompressedTexSubImage3D__IIIIIIIIIIJ(JNIEnv* env, jclass clazz, jint target, jint level, jint xoffset, jint yoffset, jint zoffset, jint width, jint height, jint depth, jint format, jint imageSize, jlong data)
{
    glCompressedTexSubImage3D(
        (GLenum)target,
        (GLint)level,
        (GLint)xoffset,
        (GLint)yoffset,
        (GLint)zoffset,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLenum)format,
        (GLsizei)imageSize,
        (GLvoid*)long2Ptr(data));
}

// void glGetCompressedTexImage(GLenum target, GLint level, GLvoid* img);
// public static native void glGetCompressedTexImage(int target, int level, Buffer img);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetCompressedTexImage__IILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint level, jobject img)
{
    glGetCompressedTexImage(
        (GLenum)target,
        (GLint)level,
        (GLvoid*)(img ? (*env)->GetDirectBufferAddress(env, img) : 0));
}

// void glGetCompressedTexImage(GLenum target, GLint level, GLvoid* img);
// public static native void glGetCompressedTexImage(int target, int level, long img);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetCompressedTexImage__IIJ(JNIEnv* env, jclass clazz, jint target, jint level, jlong img)
{
    glGetCompressedTexImage(
        (GLenum)target,
        (GLint)level,
        (GLvoid*)long2Ptr(img));
}

// void glSampleCoverage(GLclampf value, GLboolean invert);
// public static native void glSampleCoverage(float value, boolean invert);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSampleCoverage(JNIEnv* env, jclass clazz, jfloat value, jboolean invert)
{
    glSampleCoverage(
        (GLclampf)value,
        (GLboolean)(invert == JNI_TRUE ? GL_TRUE : GL_FALSE));
}

// void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
// public static native void glBlendFuncSeparate(int sfactorRGB, int dfactorRGB, int sfactorAlpha, int dfactorAlpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendFuncSeparate(JNIEnv* env, jclass clazz, jint sfactorRGB, jint dfactorRGB, jint sfactorAlpha, jint dfactorAlpha)
{
    glBlendFuncSeparate(
        (GLenum)sfactorRGB,
        (GLenum)dfactorRGB,
        (GLenum)sfactorAlpha,
        (GLenum)dfactorAlpha);
}

// void glMultiDrawArrays(GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
// public static native void glMultiDrawArrays(int mode, IntBuffer first, IntBuffer count, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiDrawArrays__ILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2I(JNIEnv* env, jclass clazz, jint mode, jobject first, jobject count, jint primcount)
{
    glMultiDrawArrays(
        (GLenum)mode,
        (GLint*)(first ? (*env)->GetDirectBufferAddress(env, first) : 0),
        (GLsizei*)(count ? (*env)->GetDirectBufferAddress(env, count) : 0),
        (GLsizei)primcount);
}

// void glMultiDrawArrays(GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
// public static native void glMultiDrawArrays(int mode, int[] first, int firstOffset, int[] count, int countOffset, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiDrawArrays__I_3II_3III(JNIEnv* env, jclass clazz, jint mode, jintArray first, jint firstOffset, jintArray count, jint countOffset, jint primcount)
{
    jint* j_first = first ? (jint*)((*env)->GetPrimitiveArrayCritical(env, first, 0)) : 0;
    jint* j_count = count ? (jint*)((*env)->GetPrimitiveArrayCritical(env, count, 0)) : 0;
    glMultiDrawArrays(
        (GLenum)mode,
        (GLint*)(j_first + firstOffset),
        (GLsizei*)(j_count + countOffset),
        (GLsizei)primcount);
    if(first) (*env)->ReleasePrimitiveArrayCritical(env, first, j_first, 0);
    if(count) (*env)->ReleasePrimitiveArrayCritical(env, count, j_count, 0);
}

// void glMultiDrawElements(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount);
// public static native void glMultiDrawElements(int mode, IntBuffer count, int type, Buffer[] indices, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiDrawElements__ILjava_nio_IntBuffer_2I_3Ljava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint mode, jobject count, jint type, jobjectArray indices, jint primcount)
{
    void** j_indices = newNativeBufferArray(env, indices);
    glMultiDrawElements(
        (GLenum)mode,
        (GLsizei*)(count ? (*env)->GetDirectBufferAddress(env, count) : 0),
        (GLenum)type,
        (const GLvoid**)j_indices,
        (GLsizei)primcount);
    freeNativeBufferArray(j_indices);
}

// void glMultiDrawElements(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount);
// public static native void glMultiDrawElements(int mode, int[] count, int countOffset, int type, Buffer[] indices, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiDrawElements__I_3III_3Ljava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint mode, jintArray count, jint countOffset, jint type, jobjectArray indices, jint primcount)
{
    jint* j_count = count ? (jint*)((*env)->GetPrimitiveArrayCritical(env, count, 0)) : 0;
    void** j_indices = newNativeBufferArray(env, indices);
    glMultiDrawElements(
        (GLenum)mode,
        (GLsizei*)(j_count + countOffset),
        (GLenum)type,
        (const GLvoid**)j_indices,
        (GLsizei)primcount);
    if(count) (*env)->ReleasePrimitiveArrayCritical(env, count, j_count, 0);
    freeNativeBufferArray(j_indices);
}

// void glPointParameterf(GLenum pname, GLfloat param);
// public static native void glPointParameterf(int pname, float param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointParameterf(JNIEnv* env, jclass clazz, jint pname, jfloat param)
{
    glPointParameterf(
        (GLenum)pname,
        (GLfloat)param);
}

// void glPointParameterfv(GLenum pname, GLfloat* params);
// public static native void glPointParameterfv(int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointParameterfv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glPointParameterfv(
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glPointParameterfv(GLenum pname, GLfloat* params);
// public static native void glPointParameterfv(int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointParameterfv__I_3FI(JNIEnv* env, jclass clazz, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glPointParameterfv(
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glPointParameteri(GLenum pname, GLint param);
// public static native void glPointParameteri(int pname, int param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointParameteri(JNIEnv* env, jclass clazz, jint pname, jint param)
{
    glPointParameteri(
        (GLenum)pname,
        (GLint)param);
}

// void glPointParameteriv(GLenum pname, GLint* params);
// public static native void glPointParameteriv(int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointParameteriv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glPointParameteriv(
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glPointParameteriv(GLenum pname, GLint* params);
// public static native void glPointParameteriv(int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPointParameteriv__I_3II(JNIEnv* env, jclass clazz, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glPointParameteriv(
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glBeginQuery(GLenum target, GLuint id);
// public static native void glBeginQuery(int target, int id);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBeginQuery(JNIEnv* env, jclass clazz, jint target, jint id)
{
    glBeginQuery(
        (GLenum)target,
        (GLuint)id);
}

// void glBindBuffer(GLenum target, GLuint buffer);
// public static native void glBindBuffer(int target, int buffer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindBuffer(JNIEnv* env, jclass clazz, jint target, jint buffer)
{
    glBindBuffer(
        (GLenum)target,
        (GLuint)buffer);
}

// void glBufferData(GLenum target, GLsizeiptr size, GLvoid* data, GLenum usage);
// public static native void glBufferData(int target, int size, Buffer data, int usage);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBufferData__IILjava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint target, jint size, jobject data, jint usage)
{
    glBufferData(
        (GLenum)target,
        (GLsizeiptr)size,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0),
        (GLenum)usage);
}

// void glBufferData(GLenum target, GLsizeiptr size, GLvoid* data, GLenum usage);
// public static native void glBufferData(int target, int size, long data, int usage);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBufferData__IIJI(JNIEnv* env, jclass clazz, jint target, jint size, jlong data, jint usage)
{
    glBufferData(
        (GLenum)target,
        (GLsizeiptr)size,
        (GLvoid*)long2Ptr(data),
        (GLenum)usage);
}

// void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
// public static native void glBufferSubData(int target, int offset, int size, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBufferSubData__IIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint offset, jint size, jobject data)
{
    glBufferSubData(
        (GLenum)target,
        (GLintptr)offset,
        (GLsizeiptr)size,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
// public static native void glBufferSubData(int target, int offset, int size, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBufferSubData__IIIJ(JNIEnv* env, jclass clazz, jint target, jint offset, jint size, jlong data)
{
    glBufferSubData(
        (GLenum)target,
        (GLintptr)offset,
        (GLsizeiptr)size,
        (GLvoid*)long2Ptr(data));
}

// void glDeleteBuffers(GLsizei n, GLuint* buffers);
// public static native void glDeleteBuffers(int n, IntBuffer buffers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteBuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject buffers)
{
    glDeleteBuffers(
        (GLsizei)n,
        (GLuint*)(buffers ? (*env)->GetDirectBufferAddress(env, buffers) : 0));
}

// void glDeleteBuffers(GLsizei n, GLuint* buffers);
// public static native void glDeleteBuffers(int n, int[] buffers, int buffersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteBuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray buffers, jint buffersOffset)
{
    jint* j_buffers = buffers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, buffers, 0)) : 0;
    glDeleteBuffers(
        (GLsizei)n,
        (GLuint*)(j_buffers + buffersOffset));
    if(buffers) (*env)->ReleasePrimitiveArrayCritical(env, buffers, j_buffers, 0);
}

// void glDeleteQueries(GLsizei n, GLuint* ids);
// public static native void glDeleteQueries(int n, IntBuffer ids);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteQueries__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject ids)
{
    glDeleteQueries(
        (GLsizei)n,
        (GLuint*)(ids ? (*env)->GetDirectBufferAddress(env, ids) : 0));
}

// void glDeleteQueries(GLsizei n, GLuint* ids);
// public static native void glDeleteQueries(int n, int[] ids, int idsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteQueries__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray ids, jint idsOffset)
{
    jint* j_ids = ids ? (jint*)((*env)->GetPrimitiveArrayCritical(env, ids, 0)) : 0;
    glDeleteQueries(
        (GLsizei)n,
        (GLuint*)(j_ids + idsOffset));
    if(ids) (*env)->ReleasePrimitiveArrayCritical(env, ids, j_ids, 0);
}

// void glEndQuery(GLenum target);
// public static native void glEndQuery(int target);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEndQuery(JNIEnv* env, jclass clazz, jint target)
{
    glEndQuery(
        (GLenum)target);
}

// void glGenBuffers(GLsizei n, GLuint* buffers);
// public static native void glGenBuffers(int n, IntBuffer buffers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenBuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject buffers)
{
    glGenBuffers(
        (GLsizei)n,
        (GLuint*)(buffers ? (*env)->GetDirectBufferAddress(env, buffers) : 0));
}

// void glGenBuffers(GLsizei n, GLuint* buffers);
// public static native void glGenBuffers(int n, int[] buffers, int buffersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenBuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray buffers, jint buffersOffset)
{
    jint* j_buffers = buffers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, buffers, 0)) : 0;
    glGenBuffers(
        (GLsizei)n,
        (GLuint*)(j_buffers + buffersOffset));
    if(buffers) (*env)->ReleasePrimitiveArrayCritical(env, buffers, j_buffers, 0);
}

// void glGenQueries(GLsizei n, GLuint* ids);
// public static native void glGenQueries(int n, IntBuffer ids);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenQueries__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject ids)
{
    glGenQueries(
        (GLsizei)n,
        (GLuint*)(ids ? (*env)->GetDirectBufferAddress(env, ids) : 0));
}

// void glGenQueries(GLsizei n, GLuint* ids);
// public static native void glGenQueries(int n, int[] ids, int idsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenQueries__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray ids, jint idsOffset)
{
    jint* j_ids = ids ? (jint*)((*env)->GetPrimitiveArrayCritical(env, ids, 0)) : 0;
    glGenQueries(
        (GLsizei)n,
        (GLuint*)(j_ids + idsOffset));
    if(ids) (*env)->ReleasePrimitiveArrayCritical(env, ids, j_ids, 0);
}

// void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetBufferParameteriv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBufferParameteriv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetBufferParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetBufferParameteriv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBufferParameteriv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetBufferParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
// public static native void glGetBufferSubData(int target, int offset, int size, Buffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBufferSubData__IIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint target, jint offset, jint size, jobject data)
{
    glGetBufferSubData(
        (GLenum)target,
        (GLintptr)offset,
        (GLsizeiptr)size,
        (GLvoid*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
// public static native void glGetBufferSubData(int target, int offset, int size, long data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBufferSubData__IIIJ(JNIEnv* env, jclass clazz, jint target, jint offset, jint size, jlong data)
{
    glGetBufferSubData(
        (GLenum)target,
        (GLintptr)offset,
        (GLsizeiptr)size,
        (GLvoid*)long2Ptr(data));
}

// void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
// public static native void glGetQueryObjectiv(int id, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjectiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint id, jint pname, jobject params)
{
    glGetQueryObjectiv(
        (GLuint)id,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
// public static native void glGetQueryObjectiv(int id, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjectiv__II_3II(JNIEnv* env, jclass clazz, jint id, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetQueryObjectiv(
        (GLuint)id,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
// public static native void glGetQueryObjectuiv(int id, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjectuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint id, jint pname, jobject params)
{
    glGetQueryObjectuiv(
        (GLuint)id,
        (GLenum)pname,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
// public static native void glGetQueryObjectuiv(int id, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjectuiv__II_3II(JNIEnv* env, jclass clazz, jint id, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetQueryObjectuiv(
        (GLuint)id,
        (GLenum)pname,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetQueryiv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetQueryiv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetQueryiv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetQueryiv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetQueryiv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryiv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetQueryiv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLboolean glIsBuffer(GLuint buffer);
// public static native boolean glIsBuffer(int buffer);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsBuffer(JNIEnv* env, jclass clazz, jint buffer)
{
    GLboolean ret = (GLboolean)
        glIsBuffer(
        (GLuint)buffer);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// GLboolean glIsQuery(GLuint id);
// public static native boolean glIsQuery(int id);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsQuery(JNIEnv* env, jclass clazz, jint id)
{
    GLboolean ret = (GLboolean)
        glIsQuery(
        (GLuint)id);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glAttachShader(GLuint program, GLuint shader);
// public static native void glAttachShader(int program, int shader);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glAttachShader(JNIEnv* env, jclass clazz, jint program, jint shader)
{
    glAttachShader(
        (GLuint)program,
        (GLuint)shader);
}

// void glBindAttribLocation(GLuint program, GLuint index, GLchar* name);
// public static native void glBindAttribLocation(int program, int index, String name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindAttribLocation(JNIEnv* env, jclass clazz, jint program, jint index, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    glBindAttribLocation(
        (GLuint)program,
        (GLuint)index,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
}

// void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
// public static native void glBlendEquationSeparate(int modeRGB, int modeAlpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendEquationSeparate(JNIEnv* env, jclass clazz, jint modeRGB, jint modeAlpha)
{
    glBlendEquationSeparate(
        (GLenum)modeRGB,
        (GLenum)modeAlpha);
}

// void glCompileShader(GLuint shader);
// public static native void glCompileShader(int shader);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCompileShader(JNIEnv* env, jclass clazz, jint shader)
{
    glCompileShader(
        (GLuint)shader);
}

// GLuint glCreateProgram();
// public static native int glCreateProgram();
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCreateProgram(JNIEnv* env, jclass clazz)
{
    return (jint)
        glCreateProgram();
}

// GLuint glCreateShader(GLenum type);
// public static native int glCreateShader(int type);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCreateShader(JNIEnv* env, jclass clazz, jint type)
{
    return (jint)
        glCreateShader(
        (GLenum)type);
}

// void glDeleteProgram(GLuint program);
// public static native void glDeleteProgram(int program);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteProgram(JNIEnv* env, jclass clazz, jint program)
{
    glDeleteProgram(
        (GLuint)program);
}

// void glDeleteShader(GLuint shader);
// public static native void glDeleteShader(int shader);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteShader(JNIEnv* env, jclass clazz, jint shader)
{
    glDeleteShader(
        (GLuint)shader);
}

// void glDetachShader(GLuint program, GLuint shader);
// public static native void glDetachShader(int program, int shader);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDetachShader(JNIEnv* env, jclass clazz, jint program, jint shader)
{
    glDetachShader(
        (GLuint)program,
        (GLuint)shader);
}

// void glDisableVertexAttribArray(GLuint index);
// public static native void glDisableVertexAttribArray(int index);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDisableVertexAttribArray(JNIEnv* env, jclass clazz, jint index)
{
    glDisableVertexAttribArray(
        (GLuint)index);
}

// void glDrawBuffers(GLsizei n, GLenum* bufs);
// public static native void glDrawBuffers(int n, IntBuffer bufs);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawBuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject bufs)
{
    glDrawBuffers(
        (GLsizei)n,
        (GLenum*)(bufs ? (*env)->GetDirectBufferAddress(env, bufs) : 0));
}

// void glDrawBuffers(GLsizei n, GLenum* bufs);
// public static native void glDrawBuffers(int n, int[] bufs, int bufsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawBuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray bufs, jint bufsOffset)
{
    jint* j_bufs = bufs ? (jint*)((*env)->GetPrimitiveArrayCritical(env, bufs, 0)) : 0;
    glDrawBuffers(
        (GLsizei)n,
        (GLenum*)(j_bufs + bufsOffset));
    if(bufs) (*env)->ReleasePrimitiveArrayCritical(env, bufs, j_bufs, 0);
}

// void glEnableVertexAttribArray(GLuint index);
// public static native void glEnableVertexAttribArray(int index);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEnableVertexAttribArray(JNIEnv* env, jclass clazz, jint index)
{
    glEnableVertexAttribArray(
        (GLuint)index);
}

// void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
// public static native void glGetActiveAttrib(int program, int index, int bufSize, IntBuffer length, IntBuffer size, IntBuffer type, ByteBuffer name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveAttrib__IIILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint index, jint bufSize, jobject length, jobject size, jobject type, jobject name)
{
    glGetActiveAttrib(
        (GLuint)program,
        (GLuint)index,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLint*)(size ? (*env)->GetDirectBufferAddress(env, size) : 0),
        (GLenum*)(type ? (*env)->GetDirectBufferAddress(env, type) : 0),
        (GLchar*)(name ? (*env)->GetDirectBufferAddress(env, name) : 0));
}

// void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
// public static native void glGetActiveAttrib(int program, int index, int bufSize, int[] length, int lengthOffset, int[] size, int sizeOffset, int[] type, int typeOffset, byte[] name, int nameOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveAttrib__III_3II_3II_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint index, jint bufSize, jintArray length, jint lengthOffset, jintArray size, jint sizeOffset, jintArray type, jint typeOffset, jbyteArray name, jint nameOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jint* j_size = size ? (jint*)((*env)->GetPrimitiveArrayCritical(env, size, 0)) : 0;
    jint* j_type = type ? (jint*)((*env)->GetPrimitiveArrayCritical(env, type, 0)) : 0;
    jbyte* j_name = name ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, name, 0)) : 0;
    glGetActiveAttrib(
        (GLuint)program,
        (GLuint)index,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLint*)(j_size + sizeOffset),
        (GLenum*)(j_type + typeOffset),
        (GLchar*)(j_name + nameOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(size) (*env)->ReleasePrimitiveArrayCritical(env, size, j_size, 0);
    if(type) (*env)->ReleasePrimitiveArrayCritical(env, type, j_type, 0);
    if(name) (*env)->ReleasePrimitiveArrayCritical(env, name, j_name, 0);
}

// void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
// public static native void glGetActiveUniform(int program, int index, int bufSize, IntBuffer length, IntBuffer size, IntBuffer type, ByteBuffer name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniform__IIILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint index, jint bufSize, jobject length, jobject size, jobject type, jobject name)
{
    glGetActiveUniform(
        (GLuint)program,
        (GLuint)index,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLint*)(size ? (*env)->GetDirectBufferAddress(env, size) : 0),
        (GLenum*)(type ? (*env)->GetDirectBufferAddress(env, type) : 0),
        (GLchar*)(name ? (*env)->GetDirectBufferAddress(env, name) : 0));
}

// void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
// public static native void glGetActiveUniform(int program, int index, int bufSize, int[] length, int lengthOffset, int[] size, int sizeOffset, int[] type, int typeOffset, byte[] name, int nameOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniform__III_3II_3II_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint index, jint bufSize, jintArray length, jint lengthOffset, jintArray size, jint sizeOffset, jintArray type, jint typeOffset, jbyteArray name, jint nameOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jint* j_size = size ? (jint*)((*env)->GetPrimitiveArrayCritical(env, size, 0)) : 0;
    jint* j_type = type ? (jint*)((*env)->GetPrimitiveArrayCritical(env, type, 0)) : 0;
    jbyte* j_name = name ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, name, 0)) : 0;
    glGetActiveUniform(
        (GLuint)program,
        (GLuint)index,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLint*)(j_size + sizeOffset),
        (GLenum*)(j_type + typeOffset),
        (GLchar*)(j_name + nameOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(size) (*env)->ReleasePrimitiveArrayCritical(env, size, j_size, 0);
    if(type) (*env)->ReleasePrimitiveArrayCritical(env, type, j_type, 0);
    if(name) (*env)->ReleasePrimitiveArrayCritical(env, name, j_name, 0);
}

// void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* obj);
// public static native void glGetAttachedShaders(int program, int maxCount, IntBuffer count, IntBuffer obj);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetAttachedShaders__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint maxCount, jobject count, jobject obj)
{
    glGetAttachedShaders(
        (GLuint)program,
        (GLsizei)maxCount,
        (GLsizei*)(count ? (*env)->GetDirectBufferAddress(env, count) : 0),
        (GLuint*)(obj ? (*env)->GetDirectBufferAddress(env, obj) : 0));
}

// void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* obj);
// public static native void glGetAttachedShaders(int program, int maxCount, int[] count, int countOffset, int[] obj, int objOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetAttachedShaders__II_3II_3II(JNIEnv* env, jclass clazz, jint program, jint maxCount, jintArray count, jint countOffset, jintArray obj, jint objOffset)
{
    jint* j_count = count ? (jint*)((*env)->GetPrimitiveArrayCritical(env, count, 0)) : 0;
    jint* j_obj = obj ? (jint*)((*env)->GetPrimitiveArrayCritical(env, obj, 0)) : 0;
    glGetAttachedShaders(
        (GLuint)program,
        (GLsizei)maxCount,
        (GLsizei*)(j_count + countOffset),
        (GLuint*)(j_obj + objOffset));
    if(count) (*env)->ReleasePrimitiveArrayCritical(env, count, j_count, 0);
    if(obj) (*env)->ReleasePrimitiveArrayCritical(env, obj, j_obj, 0);
}

// GLint glGetAttribLocation(GLuint program, GLchar* name);
// public static native int glGetAttribLocation(int program, String name);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetAttribLocation(JNIEnv* env, jclass clazz, jint program, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    GLint ret = (GLint)
        glGetAttribLocation(
        (GLuint)program,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
    return (jint)ret;
}

// void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
// public static native void glGetProgramInfoLog(int program, int bufSize, IntBuffer length, ByteBuffer infoLog);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramInfoLog__IILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint bufSize, jobject length, jobject infoLog)
{
    glGetProgramInfoLog(
        (GLuint)program,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(infoLog ? (*env)->GetDirectBufferAddress(env, infoLog) : 0));
}

// void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
// public static native void glGetProgramInfoLog(int program, int bufSize, int[] length, int lengthOffset, byte[] infoLog, int infoLogOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramInfoLog__II_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint bufSize, jintArray length, jint lengthOffset, jbyteArray infoLog, jint infoLogOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_infoLog = infoLog ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, infoLog, 0)) : 0;
    glGetProgramInfoLog(
        (GLuint)program,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_infoLog + infoLogOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(infoLog) (*env)->ReleasePrimitiveArrayCritical(env, infoLog, j_infoLog, 0);
}

// void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
// public static native void glGetProgramiv(int program, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint pname, jobject params)
{
    glGetProgramiv(
        (GLuint)program,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
// public static native void glGetProgramiv(int program, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramiv__II_3II(JNIEnv* env, jclass clazz, jint program, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetProgramiv(
        (GLuint)program,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
// public static native void glGetShaderInfoLog(int shader, int bufSize, IntBuffer length, ByteBuffer infoLog);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderInfoLog__IILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint shader, jint bufSize, jobject length, jobject infoLog)
{
    glGetShaderInfoLog(
        (GLuint)shader,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(infoLog ? (*env)->GetDirectBufferAddress(env, infoLog) : 0));
}

// void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
// public static native void glGetShaderInfoLog(int shader, int bufSize, int[] length, int lengthOffset, byte[] infoLog, int infoLogOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderInfoLog__II_3II_3BI(JNIEnv* env, jclass clazz, jint shader, jint bufSize, jintArray length, jint lengthOffset, jbyteArray infoLog, jint infoLogOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_infoLog = infoLog ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, infoLog, 0)) : 0;
    glGetShaderInfoLog(
        (GLuint)shader,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_infoLog + infoLogOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(infoLog) (*env)->ReleasePrimitiveArrayCritical(env, infoLog, j_infoLog, 0);
}

// void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
// public static native void glGetShaderSource(int shader, int bufSize, IntBuffer length, ByteBuffer source);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderSource__IILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint shader, jint bufSize, jobject length, jobject source)
{
    glGetShaderSource(
        (GLuint)shader,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(source ? (*env)->GetDirectBufferAddress(env, source) : 0));
}

// void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
// public static native void glGetShaderSource(int shader, int bufSize, int[] length, int lengthOffset, byte[] source, int sourceOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderSource__II_3II_3BI(JNIEnv* env, jclass clazz, jint shader, jint bufSize, jintArray length, jint lengthOffset, jbyteArray source, jint sourceOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_source = source ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, source, 0)) : 0;
    glGetShaderSource(
        (GLuint)shader,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_source + sourceOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(source) (*env)->ReleasePrimitiveArrayCritical(env, source, j_source, 0);
}

// void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
// public static native void glGetShaderiv(int shader, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint shader, jint pname, jobject params)
{
    glGetShaderiv(
        (GLuint)shader,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
// public static native void glGetShaderiv(int shader, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderiv__II_3II(JNIEnv* env, jclass clazz, jint shader, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetShaderiv(
        (GLuint)shader,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLint glGetUniformLocation(GLuint program, GLchar* name);
// public static native int glGetUniformLocation(int program, String name);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformLocation(JNIEnv* env, jclass clazz, jint program, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    GLint ret = (GLint)
        glGetUniformLocation(
        (GLuint)program,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
    return (jint)ret;
}

// void glGetUniformfv(GLuint program, GLint location, GLfloat* params);
// public static native void glGetUniformfv(int program, int location, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jobject params)
{
    glGetUniformfv(
        (GLuint)program,
        (GLint)location,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetUniformfv(GLuint program, GLint location, GLfloat* params);
// public static native void glGetUniformfv(int program, int location, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformfv__II_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetUniformfv(
        (GLuint)program,
        (GLint)location,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetUniformiv(GLuint program, GLint location, GLint* params);
// public static native void glGetUniformiv(int program, int location, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jobject params)
{
    glGetUniformiv(
        (GLuint)program,
        (GLint)location,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetUniformiv(GLuint program, GLint location, GLint* params);
// public static native void glGetUniformiv(int program, int location, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformiv__II_3II(JNIEnv* env, jclass clazz, jint program, jint location, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetUniformiv(
        (GLuint)program,
        (GLint)location,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params);
// public static native void glGetVertexAttribdv(int index, int pname, DoubleBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribdv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jint pname, jobject params)
{
    glGetVertexAttribdv(
        (GLuint)index,
        (GLenum)pname,
        (GLdouble*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params);
// public static native void glGetVertexAttribdv(int index, int pname, double[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribdv__II_3DI(JNIEnv* env, jclass clazz, jint index, jint pname, jdoubleArray params, jint paramsOffset)
{
    jdouble* j_params = params ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetVertexAttribdv(
        (GLuint)index,
        (GLenum)pname,
        (GLdouble*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
// public static native void glGetVertexAttribfv(int index, int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint index, jint pname, jobject params)
{
    glGetVertexAttribfv(
        (GLuint)index,
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
// public static native void glGetVertexAttribfv(int index, int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribfv__II_3FI(JNIEnv* env, jclass clazz, jint index, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetVertexAttribfv(
        (GLuint)index,
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
// public static native void glGetVertexAttribiv(int index, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint pname, jobject params)
{
    glGetVertexAttribiv(
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
// public static native void glGetVertexAttribiv(int index, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribiv__II_3II(JNIEnv* env, jclass clazz, jint index, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetVertexAttribiv(
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLboolean glIsProgram(GLuint program);
// public static native boolean glIsProgram(int program);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsProgram(JNIEnv* env, jclass clazz, jint program)
{
    GLboolean ret = (GLboolean)
        glIsProgram(
        (GLuint)program);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// GLboolean glIsShader(GLuint shader);
// public static native boolean glIsShader(int shader);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsShader(JNIEnv* env, jclass clazz, jint shader)
{
    GLboolean ret = (GLboolean)
        glIsShader(
        (GLuint)shader);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glLinkProgram(GLuint program);
// public static native void glLinkProgram(int program);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glLinkProgram(JNIEnv* env, jclass clazz, jint program)
{
    glLinkProgram(
        (GLuint)program);
}

// void glShaderSource(GLuint shader, GLsizei count, GLchar** string, GLint* length);
// public static native void glShaderSource(int shader, int count, String[] string, IntBuffer length);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glShaderSource__II_3Ljava_lang_String_2Ljava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint shader, jint count, jobjectArray string, jobject length)
{
    const char** j_string = newNativeStringArray(env, string);
    glShaderSource(
        (GLuint)shader,
        (GLsizei)count,
        (const GLchar**)j_string,
        (GLint*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0));
    freeNativeStringArray(j_string);
}

// void glShaderSource(GLuint shader, GLsizei count, GLchar** string, GLint* length);
// public static native void glShaderSource(int shader, int count, String[] string, int[] length, int lengthOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glShaderSource__II_3Ljava_lang_String_2_3II(JNIEnv* env, jclass clazz, jint shader, jint count, jobjectArray string, jintArray length, jint lengthOffset)
{
    const char** j_string = newNativeStringArray(env, string);
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    glShaderSource(
        (GLuint)shader,
        (GLsizei)count,
        (const GLchar**)j_string,
        (GLint*)(j_length + lengthOffset));
    freeNativeStringArray(j_string);
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
}

// void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
// public static native void glStencilFuncSeparate(int face, int func, int ref, int mask);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glStencilFuncSeparate(JNIEnv* env, jclass clazz, jint face, jint func, jint ref, jint mask)
{
    glStencilFuncSeparate(
        (GLenum)face,
        (GLenum)func,
        (GLint)ref,
        (GLuint)mask);
}

// void glStencilMaskSeparate(GLenum face, GLuint mask);
// public static native void glStencilMaskSeparate(int face, int mask);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glStencilMaskSeparate(JNIEnv* env, jclass clazz, jint face, jint mask)
{
    glStencilMaskSeparate(
        (GLenum)face,
        (GLuint)mask);
}

// void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
// public static native void glStencilOpSeparate(int face, int sfail, int dpfail, int dppass);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glStencilOpSeparate(JNIEnv* env, jclass clazz, jint face, jint sfail, jint dpfail, jint dppass)
{
    glStencilOpSeparate(
        (GLenum)face,
        (GLenum)sfail,
        (GLenum)dpfail,
        (GLenum)dppass);
}

// void glUniform1f(GLint location, GLfloat v0);
// public static native void glUniform1f(int location, float v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1f(JNIEnv* env, jclass clazz, jint location, jfloat v0)
{
    glUniform1f(
        (GLint)location,
        (GLfloat)v0);
}

// void glUniform1fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform1fv(int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1fv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform1fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform1fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform1fv(int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1fv__II_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform1fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform1i(GLint location, GLint v0);
// public static native void glUniform1i(int location, int v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1i(JNIEnv* env, jclass clazz, jint location, jint v0)
{
    glUniform1i(
        (GLint)location,
        (GLint)v0);
}

// void glUniform1iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform1iv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1iv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform1iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform1iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform1iv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1iv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform1iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
// public static native void glUniform2f(int location, float v0, float v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2f(JNIEnv* env, jclass clazz, jint location, jfloat v0, jfloat v1)
{
    glUniform2f(
        (GLint)location,
        (GLfloat)v0,
        (GLfloat)v1);
}

// void glUniform2fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform2fv(int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2fv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform2fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform2fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform2fv(int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2fv__II_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform2fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform2i(GLint location, GLint v0, GLint v1);
// public static native void glUniform2i(int location, int v0, int v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2i(JNIEnv* env, jclass clazz, jint location, jint v0, jint v1)
{
    glUniform2i(
        (GLint)location,
        (GLint)v0,
        (GLint)v1);
}

// void glUniform2iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform2iv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2iv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform2iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform2iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform2iv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2iv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform2iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
// public static native void glUniform3f(int location, float v0, float v1, float v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3f(JNIEnv* env, jclass clazz, jint location, jfloat v0, jfloat v1, jfloat v2)
{
    glUniform3f(
        (GLint)location,
        (GLfloat)v0,
        (GLfloat)v1,
        (GLfloat)v2);
}

// void glUniform3fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform3fv(int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3fv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform3fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform3fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform3fv(int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3fv__II_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform3fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
// public static native void glUniform3i(int location, int v0, int v1, int v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3i(JNIEnv* env, jclass clazz, jint location, jint v0, jint v1, jint v2)
{
    glUniform3i(
        (GLint)location,
        (GLint)v0,
        (GLint)v1,
        (GLint)v2);
}

// void glUniform3iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform3iv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3iv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform3iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform3iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform3iv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3iv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform3iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
// public static native void glUniform4f(int location, float v0, float v1, float v2, float v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4f(JNIEnv* env, jclass clazz, jint location, jfloat v0, jfloat v1, jfloat v2, jfloat v3)
{
    glUniform4f(
        (GLint)location,
        (GLfloat)v0,
        (GLfloat)v1,
        (GLfloat)v2,
        (GLfloat)v3);
}

// void glUniform4fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform4fv(int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4fv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform4fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform4fv(GLint location, GLsizei count, GLfloat* value);
// public static native void glUniform4fv(int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4fv__II_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform4fv(
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
// public static native void glUniform4i(int location, int v0, int v1, int v2, int v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4i(JNIEnv* env, jclass clazz, jint location, jint v0, jint v1, jint v2, jint v3)
{
    glUniform4i(
        (GLint)location,
        (GLint)v0,
        (GLint)v1,
        (GLint)v2,
        (GLint)v3);
}

// void glUniform4iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform4iv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4iv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform4iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform4iv(GLint location, GLsizei count, GLint* value);
// public static native void glUniform4iv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4iv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform4iv(
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix2fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix2fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix2fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix2fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix3fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix3fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix3fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix3fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix4fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix4fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix4fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix4fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUseProgram(GLuint program);
// public static native void glUseProgram(int program);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUseProgram(JNIEnv* env, jclass clazz, jint program)
{
    glUseProgram(
        (GLuint)program);
}

// void glValidateProgram(GLuint program);
// public static native void glValidateProgram(int program);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glValidateProgram(JNIEnv* env, jclass clazz, jint program)
{
    glValidateProgram(
        (GLuint)program);
}

// void glVertexAttrib1d(GLuint index, GLdouble x);
// public static native void glVertexAttrib1d(int index, double x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1d(JNIEnv* env, jclass clazz, jint index, jdouble x)
{
    glVertexAttrib1d(
        (GLuint)index,
        (GLdouble)x);
}

// void glVertexAttrib1dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib1dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib1dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib1dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib1dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib1dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib1f(GLuint index, GLfloat x);
// public static native void glVertexAttrib1f(int index, float x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1f(JNIEnv* env, jclass clazz, jint index, jfloat x)
{
    glVertexAttrib1f(
        (GLuint)index,
        (GLfloat)x);
}

// void glVertexAttrib1fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib1fv(int index, FloatBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1fv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib1fv(
        (GLuint)index,
        (GLfloat*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib1fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib1fv(int index, float[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1fv__I_3FI(JNIEnv* env, jclass clazz, jint index, jfloatArray v, jint vOffset)
{
    jfloat* j_v = v ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib1fv(
        (GLuint)index,
        (GLfloat*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib1s(GLuint index, GLshort x);
// public static native void glVertexAttrib1s(int index, short x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1s(JNIEnv* env, jclass clazz, jint index, jshort x)
{
    glVertexAttrib1s(
        (GLuint)index,
        (GLshort)x);
}

// void glVertexAttrib1sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib1sv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1sv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib1sv(
        (GLuint)index,
        (GLshort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib1sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib1sv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib1sv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib1sv(
        (GLuint)index,
        (GLshort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
// public static native void glVertexAttrib2d(int index, double x, double y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2d(JNIEnv* env, jclass clazz, jint index, jdouble x, jdouble y)
{
    glVertexAttrib2d(
        (GLuint)index,
        (GLdouble)x,
        (GLdouble)y);
}

// void glVertexAttrib2dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib2dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib2dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib2dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib2dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib2dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
// public static native void glVertexAttrib2f(int index, float x, float y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2f(JNIEnv* env, jclass clazz, jint index, jfloat x, jfloat y)
{
    glVertexAttrib2f(
        (GLuint)index,
        (GLfloat)x,
        (GLfloat)y);
}

// void glVertexAttrib2fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib2fv(int index, FloatBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2fv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib2fv(
        (GLuint)index,
        (GLfloat*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib2fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib2fv(int index, float[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2fv__I_3FI(JNIEnv* env, jclass clazz, jint index, jfloatArray v, jint vOffset)
{
    jfloat* j_v = v ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib2fv(
        (GLuint)index,
        (GLfloat*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
// public static native void glVertexAttrib2s(int index, short x, short y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2s(JNIEnv* env, jclass clazz, jint index, jshort x, jshort y)
{
    glVertexAttrib2s(
        (GLuint)index,
        (GLshort)x,
        (GLshort)y);
}

// void glVertexAttrib2sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib2sv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2sv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib2sv(
        (GLuint)index,
        (GLshort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib2sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib2sv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib2sv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib2sv(
        (GLuint)index,
        (GLshort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
// public static native void glVertexAttrib3d(int index, double x, double y, double z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3d(JNIEnv* env, jclass clazz, jint index, jdouble x, jdouble y, jdouble z)
{
    glVertexAttrib3d(
        (GLuint)index,
        (GLdouble)x,
        (GLdouble)y,
        (GLdouble)z);
}

// void glVertexAttrib3dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib3dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib3dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib3dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib3dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib3dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
// public static native void glVertexAttrib3f(int index, float x, float y, float z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3f(JNIEnv* env, jclass clazz, jint index, jfloat x, jfloat y, jfloat z)
{
    glVertexAttrib3f(
        (GLuint)index,
        (GLfloat)x,
        (GLfloat)y,
        (GLfloat)z);
}

// void glVertexAttrib3fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib3fv(int index, FloatBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3fv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib3fv(
        (GLuint)index,
        (GLfloat*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib3fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib3fv(int index, float[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3fv__I_3FI(JNIEnv* env, jclass clazz, jint index, jfloatArray v, jint vOffset)
{
    jfloat* j_v = v ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib3fv(
        (GLuint)index,
        (GLfloat*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
// public static native void glVertexAttrib3s(int index, short x, short y, short z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3s(JNIEnv* env, jclass clazz, jint index, jshort x, jshort y, jshort z)
{
    glVertexAttrib3s(
        (GLuint)index,
        (GLshort)x,
        (GLshort)y,
        (GLshort)z);
}

// void glVertexAttrib3sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib3sv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3sv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib3sv(
        (GLuint)index,
        (GLshort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib3sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib3sv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib3sv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib3sv(
        (GLuint)index,
        (GLshort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4Nbv(GLuint index, GLbyte* v);
// public static native void glVertexAttrib4Nbv(int index, ByteBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nbv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4Nbv(
        (GLuint)index,
        (GLbyte*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4Nbv(GLuint index, GLbyte* v);
// public static native void glVertexAttrib4Nbv(int index, byte[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nbv__I_3BI(JNIEnv* env, jclass clazz, jint index, jbyteArray v, jint vOffset)
{
    jbyte* j_v = v ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4Nbv(
        (GLuint)index,
        (GLbyte*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4Niv(GLuint index, GLint* v);
// public static native void glVertexAttrib4Niv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Niv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4Niv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4Niv(GLuint index, GLint* v);
// public static native void glVertexAttrib4Niv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Niv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4Niv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4Nsv(GLuint index, GLshort* v);
// public static native void glVertexAttrib4Nsv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nsv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4Nsv(
        (GLuint)index,
        (GLshort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4Nsv(GLuint index, GLshort* v);
// public static native void glVertexAttrib4Nsv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nsv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4Nsv(
        (GLuint)index,
        (GLshort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
// public static native void glVertexAttrib4Nub(int index, byte x, byte y, byte z, byte w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nub(JNIEnv* env, jclass clazz, jint index, jbyte x, jbyte y, jbyte z, jbyte w)
{
    glVertexAttrib4Nub(
        (GLuint)index,
        (GLubyte)x,
        (GLubyte)y,
        (GLubyte)z,
        (GLubyte)w);
}

// void glVertexAttrib4Nubv(GLuint index, GLubyte* v);
// public static native void glVertexAttrib4Nubv(int index, ByteBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nubv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4Nubv(
        (GLuint)index,
        (GLubyte*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4Nubv(GLuint index, GLubyte* v);
// public static native void glVertexAttrib4Nubv(int index, byte[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nubv__I_3BI(JNIEnv* env, jclass clazz, jint index, jbyteArray v, jint vOffset)
{
    jbyte* j_v = v ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4Nubv(
        (GLuint)index,
        (GLubyte*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4Nuiv(GLuint index, GLuint* v);
// public static native void glVertexAttrib4Nuiv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nuiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4Nuiv(
        (GLuint)index,
        (GLuint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4Nuiv(GLuint index, GLuint* v);
// public static native void glVertexAttrib4Nuiv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nuiv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4Nuiv(
        (GLuint)index,
        (GLuint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4Nusv(GLuint index, GLushort* v);
// public static native void glVertexAttrib4Nusv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nusv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4Nusv(
        (GLuint)index,
        (GLushort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4Nusv(GLuint index, GLushort* v);
// public static native void glVertexAttrib4Nusv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4Nusv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4Nusv(
        (GLuint)index,
        (GLushort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4bv(GLuint index, GLbyte* v);
// public static native void glVertexAttrib4bv(int index, ByteBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4bv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4bv(
        (GLuint)index,
        (GLbyte*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4bv(GLuint index, GLbyte* v);
// public static native void glVertexAttrib4bv(int index, byte[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4bv__I_3BI(JNIEnv* env, jclass clazz, jint index, jbyteArray v, jint vOffset)
{
    jbyte* j_v = v ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4bv(
        (GLuint)index,
        (GLbyte*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
// public static native void glVertexAttrib4d(int index, double x, double y, double z, double w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4d(JNIEnv* env, jclass clazz, jint index, jdouble x, jdouble y, jdouble z, jdouble w)
{
    glVertexAttrib4d(
        (GLuint)index,
        (GLdouble)x,
        (GLdouble)y,
        (GLdouble)z,
        (GLdouble)w);
}

// void glVertexAttrib4dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib4dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4dv(GLuint index, GLdouble* v);
// public static native void glVertexAttrib4dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
// public static native void glVertexAttrib4f(int index, float x, float y, float z, float w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4f(JNIEnv* env, jclass clazz, jint index, jfloat x, jfloat y, jfloat z, jfloat w)
{
    glVertexAttrib4f(
        (GLuint)index,
        (GLfloat)x,
        (GLfloat)y,
        (GLfloat)z,
        (GLfloat)w);
}

// void glVertexAttrib4fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib4fv(int index, FloatBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4fv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4fv(
        (GLuint)index,
        (GLfloat*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4fv(GLuint index, GLfloat* v);
// public static native void glVertexAttrib4fv(int index, float[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4fv__I_3FI(JNIEnv* env, jclass clazz, jint index, jfloatArray v, jint vOffset)
{
    jfloat* j_v = v ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4fv(
        (GLuint)index,
        (GLfloat*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4iv(GLuint index, GLint* v);
// public static native void glVertexAttrib4iv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4iv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4iv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4iv(GLuint index, GLint* v);
// public static native void glVertexAttrib4iv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4iv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4iv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
// public static native void glVertexAttrib4s(int index, short x, short y, short z, short w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4s(JNIEnv* env, jclass clazz, jint index, jshort x, jshort y, jshort z, jshort w)
{
    glVertexAttrib4s(
        (GLuint)index,
        (GLshort)x,
        (GLshort)y,
        (GLshort)z,
        (GLshort)w);
}

// void glVertexAttrib4sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib4sv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4sv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4sv(
        (GLuint)index,
        (GLshort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4sv(GLuint index, GLshort* v);
// public static native void glVertexAttrib4sv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4sv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4sv(
        (GLuint)index,
        (GLshort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4ubv(GLuint index, GLubyte* v);
// public static native void glVertexAttrib4ubv(int index, ByteBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4ubv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4ubv(
        (GLuint)index,
        (GLubyte*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4ubv(GLuint index, GLubyte* v);
// public static native void glVertexAttrib4ubv(int index, byte[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4ubv__I_3BI(JNIEnv* env, jclass clazz, jint index, jbyteArray v, jint vOffset)
{
    jbyte* j_v = v ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4ubv(
        (GLuint)index,
        (GLubyte*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4uiv(GLuint index, GLuint* v);
// public static native void glVertexAttrib4uiv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4uiv(
        (GLuint)index,
        (GLuint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4uiv(GLuint index, GLuint* v);
// public static native void glVertexAttrib4uiv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4uiv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4uiv(
        (GLuint)index,
        (GLuint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttrib4usv(GLuint index, GLushort* v);
// public static native void glVertexAttrib4usv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4usv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttrib4usv(
        (GLuint)index,
        (GLushort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttrib4usv(GLuint index, GLushort* v);
// public static native void glVertexAttrib4usv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttrib4usv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttrib4usv(
        (GLuint)index,
        (GLushort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* pointer);
// public static native void glVertexAttribPointer(int index, int size, int type, boolean normalized, int stride, Buffer pointer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribPointer__IIIZILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint index, jint size, jint type, jboolean normalized, jint stride, jobject pointer)
{
    glVertexAttribPointer(
        (GLuint)index,
        (GLint)size,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLsizei)stride,
        (GLvoid*)(pointer ? (*env)->GetDirectBufferAddress(env, pointer) : 0));
}

// void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* pointer);
// public static native void glVertexAttribPointer(int index, int size, int type, boolean normalized, int stride, long pointer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribPointer__IIIZIJ(JNIEnv* env, jclass clazz, jint index, jint size, jint type, jboolean normalized, jint stride, jlong pointer)
{
    glVertexAttribPointer(
        (GLuint)index,
        (GLint)size,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLsizei)stride,
        (GLvoid*)long2Ptr(pointer));
}

// void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix2x3fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x3fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix2x3fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix2x3fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x3fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix2x3fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix2x4fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x4fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix2x4fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix2x4fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x4fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix2x4fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix3x2fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x2fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix3x2fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix3x2fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x2fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix3x2fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix3x4fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x4fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix3x4fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix3x4fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x4fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix3x4fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix4x2fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x2fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix4x2fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix4x2fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x2fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix4x2fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix4x3fv(int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x3fv__IIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix4x3fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glUniformMatrix4x3fv(int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x3fv__IIZ_3FI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix4x3fv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glBeginConditionalRender(GLuint id, GLenum mode);
// public static native void glBeginConditionalRender(int id, int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBeginConditionalRender(JNIEnv* env, jclass clazz, jint id, jint mode)
{
    glBeginConditionalRender(
        (GLuint)id,
        (GLenum)mode);
}

// void glBeginTransformFeedback(GLenum primitiveMode);
// public static native void glBeginTransformFeedback(int primitiveMode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBeginTransformFeedback(JNIEnv* env, jclass clazz, jint primitiveMode)
{
    glBeginTransformFeedback(
        (GLenum)primitiveMode);
}

// void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
// public static native void glBindBufferBase(int target, int index, int buffer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindBufferBase(JNIEnv* env, jclass clazz, jint target, jint index, jint buffer)
{
    glBindBufferBase(
        (GLenum)target,
        (GLuint)index,
        (GLuint)buffer);
}

// void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
// public static native void glBindBufferRange(int target, int index, int buffer, int offset, int size);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindBufferRange(JNIEnv* env, jclass clazz, jint target, jint index, jint buffer, jint offset, jint size)
{
    glBindBufferRange(
        (GLenum)target,
        (GLuint)index,
        (GLuint)buffer,
        (GLintptr)offset,
        (GLsizeiptr)size);
}

// void glBindFragDataLocation(GLuint program, GLuint color, GLchar* name);
// public static native void glBindFragDataLocation(int program, int color, String name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindFragDataLocation(JNIEnv* env, jclass clazz, jint program, jint color, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    glBindFragDataLocation(
        (GLuint)program,
        (GLuint)color,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
}

// void glBindFramebuffer(GLenum target, GLuint framebuffer);
// public static native void glBindFramebuffer(int target, int framebuffer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindFramebuffer(JNIEnv* env, jclass clazz, jint target, jint framebuffer)
{
    glBindFramebuffer(
        (GLenum)target,
        (GLuint)framebuffer);
}

// void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
// public static native void glBindRenderbuffer(int target, int renderbuffer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindRenderbuffer(JNIEnv* env, jclass clazz, jint target, jint renderbuffer)
{
    glBindRenderbuffer(
        (GLenum)target,
        (GLuint)renderbuffer);
}

// void glBindVertexArray(GLuint array);
// public static native void glBindVertexArray(int array);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindVertexArray(JNIEnv* env, jclass clazz, jint array)
{
    glBindVertexArray(
        (GLuint)array);
}

// void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
// public static native void glBlitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, int mask, int filter);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlitFramebuffer(JNIEnv* env, jclass clazz, jint srcX0, jint srcY0, jint srcX1, jint srcY1, jint dstX0, jint dstY0, jint dstX1, jint dstY1, jint mask, jint filter)
{
    glBlitFramebuffer(
        (GLint)srcX0,
        (GLint)srcY0,
        (GLint)srcX1,
        (GLint)srcY1,
        (GLint)dstX0,
        (GLint)dstY0,
        (GLint)dstX1,
        (GLint)dstY1,
        (GLbitfield)mask,
        (GLenum)filter);
}

// GLenum glCheckFramebufferStatus(GLenum target);
// public static native int glCheckFramebufferStatus(int target);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCheckFramebufferStatus(JNIEnv* env, jclass clazz, jint target)
{
    return (jint)
        glCheckFramebufferStatus(
        (GLenum)target);
}

// void glClampColor(GLenum target, GLenum clamp);
// public static native void glClampColor(int target, int clamp);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClampColor(JNIEnv* env, jclass clazz, jint target, jint clamp)
{
    glClampColor(
        (GLenum)target,
        (GLenum)clamp);
}

// void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
// public static native void glClearBufferfi(int buffer, int drawbuffer, float depth, int stencil);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferfi(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jfloat depth, jint stencil)
{
    glClearBufferfi(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLfloat)depth,
        (GLint)stencil);
}

// void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat* value);
// public static native void glClearBufferfv(int buffer, int drawbuffer, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jobject value)
{
    glClearBufferfv(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat* value);
// public static native void glClearBufferfv(int buffer, int drawbuffer, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferfv__II_3FI(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glClearBufferfv(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint* value);
// public static native void glClearBufferiv(int buffer, int drawbuffer, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jobject value)
{
    glClearBufferiv(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint* value);
// public static native void glClearBufferiv(int buffer, int drawbuffer, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferiv__II_3II(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glClearBufferiv(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint* value);
// public static native void glClearBufferuiv(int buffer, int drawbuffer, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jobject value)
{
    glClearBufferuiv(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint* value);
// public static native void glClearBufferuiv(int buffer, int drawbuffer, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearBufferuiv__II_3II(JNIEnv* env, jclass clazz, jint buffer, jint drawbuffer, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glClearBufferuiv(
        (GLenum)buffer,
        (GLint)drawbuffer,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
// public static native void glColorMaski(int index, boolean r, boolean g, boolean b, boolean a);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorMaski(JNIEnv* env, jclass clazz, jint index, jboolean r, jboolean g, jboolean b, jboolean a)
{
    glColorMaski(
        (GLuint)index,
        (GLboolean)(r == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLboolean)(g == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLboolean)(b == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLboolean)(a == JNI_TRUE ? GL_TRUE : GL_FALSE));
}

// void glDeleteFramebuffers(GLsizei n, GLuint* framebuffers);
// public static native void glDeleteFramebuffers(int n, IntBuffer framebuffers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteFramebuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject framebuffers)
{
    glDeleteFramebuffers(
        (GLsizei)n,
        (GLuint*)(framebuffers ? (*env)->GetDirectBufferAddress(env, framebuffers) : 0));
}

// void glDeleteFramebuffers(GLsizei n, GLuint* framebuffers);
// public static native void glDeleteFramebuffers(int n, int[] framebuffers, int framebuffersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteFramebuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray framebuffers, jint framebuffersOffset)
{
    jint* j_framebuffers = framebuffers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, framebuffers, 0)) : 0;
    glDeleteFramebuffers(
        (GLsizei)n,
        (GLuint*)(j_framebuffers + framebuffersOffset));
    if(framebuffers) (*env)->ReleasePrimitiveArrayCritical(env, framebuffers, j_framebuffers, 0);
}

// void glDeleteRenderbuffers(GLsizei n, GLuint* renderbuffers);
// public static native void glDeleteRenderbuffers(int n, IntBuffer renderbuffers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteRenderbuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject renderbuffers)
{
    glDeleteRenderbuffers(
        (GLsizei)n,
        (GLuint*)(renderbuffers ? (*env)->GetDirectBufferAddress(env, renderbuffers) : 0));
}

// void glDeleteRenderbuffers(GLsizei n, GLuint* renderbuffers);
// public static native void glDeleteRenderbuffers(int n, int[] renderbuffers, int renderbuffersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteRenderbuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray renderbuffers, jint renderbuffersOffset)
{
    jint* j_renderbuffers = renderbuffers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, renderbuffers, 0)) : 0;
    glDeleteRenderbuffers(
        (GLsizei)n,
        (GLuint*)(j_renderbuffers + renderbuffersOffset));
    if(renderbuffers) (*env)->ReleasePrimitiveArrayCritical(env, renderbuffers, j_renderbuffers, 0);
}

// void glDeleteVertexArrays(GLsizei n, GLuint* arrays);
// public static native void glDeleteVertexArrays(int n, IntBuffer arrays);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteVertexArrays__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject arrays)
{
    glDeleteVertexArrays(
        (GLsizei)n,
        (GLuint*)(arrays ? (*env)->GetDirectBufferAddress(env, arrays) : 0));
}

// void glDeleteVertexArrays(GLsizei n, GLuint* arrays);
// public static native void glDeleteVertexArrays(int n, int[] arrays, int arraysOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteVertexArrays__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray arrays, jint arraysOffset)
{
    jint* j_arrays = arrays ? (jint*)((*env)->GetPrimitiveArrayCritical(env, arrays, 0)) : 0;
    glDeleteVertexArrays(
        (GLsizei)n,
        (GLuint*)(j_arrays + arraysOffset));
    if(arrays) (*env)->ReleasePrimitiveArrayCritical(env, arrays, j_arrays, 0);
}

// void glDisablei(GLenum target, GLuint index);
// public static native void glDisablei(int target, int index);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDisablei(JNIEnv* env, jclass clazz, jint target, jint index)
{
    glDisablei(
        (GLenum)target,
        (GLuint)index);
}

// void glEnablei(GLenum target, GLuint index);
// public static native void glEnablei(int target, int index);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEnablei(JNIEnv* env, jclass clazz, jint target, jint index)
{
    glEnablei(
        (GLenum)target,
        (GLuint)index);
}

// void glEndConditionalRender();
// public static native void glEndConditionalRender();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEndConditionalRender(JNIEnv* env, jclass clazz)
{
    glEndConditionalRender();
}

// void glEndTransformFeedback();
// public static native void glEndTransformFeedback();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEndTransformFeedback(JNIEnv* env, jclass clazz)
{
    glEndTransformFeedback();
}

// void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
// public static native void glFramebufferRenderbuffer(int target, int attachment, int renderbuffertarget, int renderbuffer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFramebufferRenderbuffer(JNIEnv* env, jclass clazz, jint target, jint attachment, jint renderbuffertarget, jint renderbuffer)
{
    glFramebufferRenderbuffer(
        (GLenum)target,
        (GLenum)attachment,
        (GLenum)renderbuffertarget,
        (GLuint)renderbuffer);
}

// void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
// public static native void glFramebufferTexture1D(int target, int attachment, int textarget, int texture, int level);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFramebufferTexture1D(JNIEnv* env, jclass clazz, jint target, jint attachment, jint textarget, jint texture, jint level)
{
    glFramebufferTexture1D(
        (GLenum)target,
        (GLenum)attachment,
        (GLenum)textarget,
        (GLuint)texture,
        (GLint)level);
}

// void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
// public static native void glFramebufferTexture2D(int target, int attachment, int textarget, int texture, int level);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFramebufferTexture2D(JNIEnv* env, jclass clazz, jint target, jint attachment, jint textarget, jint texture, jint level)
{
    glFramebufferTexture2D(
        (GLenum)target,
        (GLenum)attachment,
        (GLenum)textarget,
        (GLuint)texture,
        (GLint)level);
}

// void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
// public static native void glFramebufferTexture3D(int target, int attachment, int textarget, int texture, int level, int zoffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFramebufferTexture3D(JNIEnv* env, jclass clazz, jint target, jint attachment, jint textarget, jint texture, jint level, jint zoffset)
{
    glFramebufferTexture3D(
        (GLenum)target,
        (GLenum)attachment,
        (GLenum)textarget,
        (GLuint)texture,
        (GLint)level,
        (GLint)zoffset);
}

// void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
// public static native void glFramebufferTextureLayer(int target, int attachment, int texture, int level, int layer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFramebufferTextureLayer(JNIEnv* env, jclass clazz, jint target, jint attachment, jint texture, jint level, jint layer)
{
    glFramebufferTextureLayer(
        (GLenum)target,
        (GLenum)attachment,
        (GLuint)texture,
        (GLint)level,
        (GLint)layer);
}

// void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
// public static native void glGenFramebuffers(int n, IntBuffer framebuffers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenFramebuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject framebuffers)
{
    glGenFramebuffers(
        (GLsizei)n,
        (GLuint*)(framebuffers ? (*env)->GetDirectBufferAddress(env, framebuffers) : 0));
}

// void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
// public static native void glGenFramebuffers(int n, int[] framebuffers, int framebuffersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenFramebuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray framebuffers, jint framebuffersOffset)
{
    jint* j_framebuffers = framebuffers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, framebuffers, 0)) : 0;
    glGenFramebuffers(
        (GLsizei)n,
        (GLuint*)(j_framebuffers + framebuffersOffset));
    if(framebuffers) (*env)->ReleasePrimitiveArrayCritical(env, framebuffers, j_framebuffers, 0);
}

// void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
// public static native void glGenRenderbuffers(int n, IntBuffer renderbuffers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenRenderbuffers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject renderbuffers)
{
    glGenRenderbuffers(
        (GLsizei)n,
        (GLuint*)(renderbuffers ? (*env)->GetDirectBufferAddress(env, renderbuffers) : 0));
}

// void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
// public static native void glGenRenderbuffers(int n, int[] renderbuffers, int renderbuffersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenRenderbuffers__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray renderbuffers, jint renderbuffersOffset)
{
    jint* j_renderbuffers = renderbuffers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, renderbuffers, 0)) : 0;
    glGenRenderbuffers(
        (GLsizei)n,
        (GLuint*)(j_renderbuffers + renderbuffersOffset));
    if(renderbuffers) (*env)->ReleasePrimitiveArrayCritical(env, renderbuffers, j_renderbuffers, 0);
}

// void glGenVertexArrays(GLsizei n, GLuint* arrays);
// public static native void glGenVertexArrays(int n, IntBuffer arrays);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenVertexArrays__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject arrays)
{
    glGenVertexArrays(
        (GLsizei)n,
        (GLuint*)(arrays ? (*env)->GetDirectBufferAddress(env, arrays) : 0));
}

// void glGenVertexArrays(GLsizei n, GLuint* arrays);
// public static native void glGenVertexArrays(int n, int[] arrays, int arraysOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenVertexArrays__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray arrays, jint arraysOffset)
{
    jint* j_arrays = arrays ? (jint*)((*env)->GetPrimitiveArrayCritical(env, arrays, 0)) : 0;
    glGenVertexArrays(
        (GLsizei)n,
        (GLuint*)(j_arrays + arraysOffset));
    if(arrays) (*env)->ReleasePrimitiveArrayCritical(env, arrays, j_arrays, 0);
}

// void glGenerateMipmap(GLenum target);
// public static native void glGenerateMipmap(int target);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenerateMipmap(JNIEnv* env, jclass clazz, jint target)
{
    glGenerateMipmap(
        (GLenum)target);
}

// void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data);
// public static native void glGetBooleani_v(int target, int index, ByteBuffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBooleani_1v__IILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint target, jint index, jobject data)
{
    glGetBooleani_v(
        (GLenum)target,
        (GLuint)index,
        (GLboolean*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data);
// public static native void glGetBooleani_v(int target, int index, byte[] data, int dataOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBooleani_1v__II_3BI(JNIEnv* env, jclass clazz, jint target, jint index, jbyteArray data, jint dataOffset)
{
    jbyte* j_data = data ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, data, 0)) : 0;
    glGetBooleani_v(
        (GLenum)target,
        (GLuint)index,
        (GLboolean*)(j_data + dataOffset));
    if(data) (*env)->ReleasePrimitiveArrayCritical(env, data, j_data, 0);
}

// GLint glGetFragDataLocation(GLuint program, GLchar* name);
// public static native int glGetFragDataLocation(int program, String name);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFragDataLocation(JNIEnv* env, jclass clazz, jint program, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    GLint ret = (GLint)
        glGetFragDataLocation(
        (GLuint)program,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
    return (jint)ret;
}

// void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
// public static native void glGetFramebufferAttachmentParameteriv(int target, int attachment, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFramebufferAttachmentParameteriv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint attachment, jint pname, jobject params)
{
    glGetFramebufferAttachmentParameteriv(
        (GLenum)target,
        (GLenum)attachment,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
// public static native void glGetFramebufferAttachmentParameteriv(int target, int attachment, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFramebufferAttachmentParameteriv__III_3II(JNIEnv* env, jclass clazz, jint target, jint attachment, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetFramebufferAttachmentParameteriv(
        (GLenum)target,
        (GLenum)attachment,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetIntegeri_v(GLenum target, GLuint index, GLint* data);
// public static native void glGetIntegeri_v(int target, int index, IntBuffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetIntegeri_1v__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint index, jobject data)
{
    glGetIntegeri_v(
        (GLenum)target,
        (GLuint)index,
        (GLint*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glGetIntegeri_v(GLenum target, GLuint index, GLint* data);
// public static native void glGetIntegeri_v(int target, int index, int[] data, int dataOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetIntegeri_1v__II_3II(JNIEnv* env, jclass clazz, jint target, jint index, jintArray data, jint dataOffset)
{
    jint* j_data = data ? (jint*)((*env)->GetPrimitiveArrayCritical(env, data, 0)) : 0;
    glGetIntegeri_v(
        (GLenum)target,
        (GLuint)index,
        (GLint*)(j_data + dataOffset));
    if(data) (*env)->ReleasePrimitiveArrayCritical(env, data, j_data, 0);
}

// void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetRenderbufferParameteriv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetRenderbufferParameteriv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetRenderbufferParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetRenderbufferParameteriv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetRenderbufferParameteriv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetRenderbufferParameteriv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLubyte* glGetStringi(GLenum name, GLuint index);
// public static native String glGetStringi(int name, int index);
JNIEXPORT jstring JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetStringi(JNIEnv* env, jclass clazz, jint name, jint index)
{
    GLubyte* ret = (GLubyte*)
        glGetStringi(
        (GLenum)name,
        (GLuint)index);
    return (*env)->NewStringUTF(env, (char*)ret);
}

// void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetTexParameterIiv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameterIiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetTexParameterIiv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params);
// public static native void glGetTexParameterIiv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameterIiv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetTexParameterIiv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
// public static native void glGetTexParameterIuiv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameterIuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetTexParameterIuiv(
        (GLenum)target,
        (GLenum)pname,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
// public static native void glGetTexParameterIuiv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTexParameterIuiv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetTexParameterIuiv(
        (GLenum)target,
        (GLenum)pname,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
// public static native void glGetTransformFeedbackVarying(int program, int index, int bufSize, IntBuffer length, IntBuffer size, IntBuffer type, String name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTransformFeedbackVarying__IIILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_lang_String_2(JNIEnv* env, jclass clazz, jint program, jint index, jint bufSize, jobject length, jobject size, jobject type, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    glGetTransformFeedbackVarying(
        (GLuint)program,
        (GLuint)index,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLsizei*)(size ? (*env)->GetDirectBufferAddress(env, size) : 0),
        (GLenum*)(type ? (*env)->GetDirectBufferAddress(env, type) : 0),
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
}

// void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
// public static native void glGetTransformFeedbackVarying(int program, int index, int bufSize, int[] length, int lengthOffset, int[] size, int sizeOffset, int[] type, int typeOffset, String name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetTransformFeedbackVarying__III_3II_3II_3IILjava_lang_String_2(JNIEnv* env, jclass clazz, jint program, jint index, jint bufSize, jintArray length, jint lengthOffset, jintArray size, jint sizeOffset, jintArray type, jint typeOffset, jstring name)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jint* j_size = size ? (jint*)((*env)->GetPrimitiveArrayCritical(env, size, 0)) : 0;
    jint* j_type = type ? (jint*)((*env)->GetPrimitiveArrayCritical(env, type, 0)) : 0;
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    glGetTransformFeedbackVarying(
        (GLuint)program,
        (GLuint)index,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLsizei*)(j_size + sizeOffset),
        (GLenum*)(j_type + typeOffset),
        (GLchar*)j_name);
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(size) (*env)->ReleasePrimitiveArrayCritical(env, size, j_size, 0);
    if(type) (*env)->ReleasePrimitiveArrayCritical(env, type, j_type, 0);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
}

// void glGetUniformuiv(GLuint program, GLint location, GLuint* params);
// public static native void glGetUniformuiv(int program, int location, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jobject params)
{
    glGetUniformuiv(
        (GLuint)program,
        (GLint)location,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetUniformuiv(GLuint program, GLint location, GLuint* params);
// public static native void glGetUniformuiv(int program, int location, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformuiv__II_3II(JNIEnv* env, jclass clazz, jint program, jint location, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetUniformuiv(
        (GLuint)program,
        (GLint)location,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params);
// public static native void glGetVertexAttribIiv(int index, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribIiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint pname, jobject params)
{
    glGetVertexAttribIiv(
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params);
// public static native void glGetVertexAttribIiv(int index, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribIiv__II_3II(JNIEnv* env, jclass clazz, jint index, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetVertexAttribIiv(
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params);
// public static native void glGetVertexAttribIuiv(int index, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribIuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint pname, jobject params)
{
    glGetVertexAttribIuiv(
        (GLuint)index,
        (GLenum)pname,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params);
// public static native void glGetVertexAttribIuiv(int index, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribIuiv__II_3II(JNIEnv* env, jclass clazz, jint index, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetVertexAttribIuiv(
        (GLuint)index,
        (GLenum)pname,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLboolean glIsEnabledi(GLenum target, GLuint index);
// public static native boolean glIsEnabledi(int target, int index);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsEnabledi(JNIEnv* env, jclass clazz, jint target, jint index)
{
    GLboolean ret = (GLboolean)
        glIsEnabledi(
        (GLenum)target,
        (GLuint)index);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// GLboolean glIsFramebuffer(GLuint framebuffer);
// public static native boolean glIsFramebuffer(int framebuffer);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsFramebuffer(JNIEnv* env, jclass clazz, jint framebuffer)
{
    GLboolean ret = (GLboolean)
        glIsFramebuffer(
        (GLuint)framebuffer);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// GLboolean glIsRenderbuffer(GLuint renderbuffer);
// public static native boolean glIsRenderbuffer(int renderbuffer);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsRenderbuffer(JNIEnv* env, jclass clazz, jint renderbuffer)
{
    GLboolean ret = (GLboolean)
        glIsRenderbuffer(
        (GLuint)renderbuffer);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// GLboolean glIsVertexArray(GLuint array);
// public static native boolean glIsVertexArray(int array);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsVertexArray(JNIEnv* env, jclass clazz, jint array)
{
    GLboolean ret = (GLboolean)
        glIsVertexArray(
        (GLuint)array);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
// public static native void glRenderbufferStorage(int target, int internalformat, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glRenderbufferStorage(JNIEnv* env, jclass clazz, jint target, jint internalformat, jint width, jint height)
{
    glRenderbufferStorage(
        (GLenum)target,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLsizei)height);
}

// void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
// public static native void glRenderbufferStorageMultisample(int target, int samples, int internalformat, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glRenderbufferStorageMultisample(JNIEnv* env, jclass clazz, jint target, jint samples, jint internalformat, jint width, jint height)
{
    glRenderbufferStorageMultisample(
        (GLenum)target,
        (GLsizei)samples,
        (GLenum)internalformat,
        (GLsizei)width,
        (GLsizei)height);
}

// void glTexParameterIiv(GLenum target, GLenum pname, GLint* params);
// public static native void glTexParameterIiv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterIiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glTexParameterIiv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glTexParameterIiv(GLenum target, GLenum pname, GLint* params);
// public static native void glTexParameterIiv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterIiv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glTexParameterIiv(
        (GLenum)target,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
// public static native void glTexParameterIuiv(int target, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterIuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glTexParameterIuiv(
        (GLenum)target,
        (GLenum)pname,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
// public static native void glTexParameterIuiv(int target, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexParameterIuiv__II_3II(JNIEnv* env, jclass clazz, jint target, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glTexParameterIuiv(
        (GLenum)target,
        (GLenum)pname,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar** varyings, GLenum bufferMode);
// public static native void glTransformFeedbackVaryings(int program, int count, String[] varyings, int bufferMode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTransformFeedbackVaryings(JNIEnv* env, jclass clazz, jint program, jint count, jobjectArray varyings, jint bufferMode)
{
    const char** j_varyings = newNativeStringArray(env, varyings);
    glTransformFeedbackVaryings(
        (GLuint)program,
        (GLsizei)count,
        (const GLchar**)j_varyings,
        (GLenum)bufferMode);
    freeNativeStringArray(j_varyings);
}

// void glUniform1ui(GLint location, GLuint v0);
// public static native void glUniform1ui(int location, int v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1ui(JNIEnv* env, jclass clazz, jint location, jint v0)
{
    glUniform1ui(
        (GLint)location,
        (GLuint)v0);
}

// void glUniform1uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform1uiv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform1uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform1uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform1uiv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1uiv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform1uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform2ui(GLint location, GLuint v0, GLuint v1);
// public static native void glUniform2ui(int location, int v0, int v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2ui(JNIEnv* env, jclass clazz, jint location, jint v0, jint v1)
{
    glUniform2ui(
        (GLint)location,
        (GLuint)v0,
        (GLuint)v1);
}

// void glUniform2uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform2uiv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform2uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform2uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform2uiv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2uiv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform2uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
// public static native void glUniform3ui(int location, int v0, int v1, int v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3ui(JNIEnv* env, jclass clazz, jint location, jint v0, jint v1, jint v2)
{
    glUniform3ui(
        (GLint)location,
        (GLuint)v0,
        (GLuint)v1,
        (GLuint)v2);
}

// void glUniform3uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform3uiv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform3uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform3uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform3uiv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3uiv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform3uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
// public static native void glUniform4ui(int location, int v0, int v1, int v2, int v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4ui(JNIEnv* env, jclass clazz, jint location, jint v0, jint v1, jint v2, jint v3)
{
    glUniform4ui(
        (GLint)location,
        (GLuint)v0,
        (GLuint)v1,
        (GLuint)v2,
        (GLuint)v3);
}

// void glUniform4uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform4uiv(int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform4uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform4uiv(GLint location, GLsizei count, GLuint* value);
// public static native void glUniform4uiv(int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4uiv__II_3II(JNIEnv* env, jclass clazz, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform4uiv(
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexAttribI1i(GLuint index, GLint x);
// public static native void glVertexAttribI1i(int index, int x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI1i(JNIEnv* env, jclass clazz, jint index, jint x)
{
    glVertexAttribI1i(
        (GLuint)index,
        (GLint)x);
}

// void glVertexAttribI1iv(GLuint index, GLint* v);
// public static native void glVertexAttribI1iv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI1iv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI1iv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI1iv(GLuint index, GLint* v);
// public static native void glVertexAttribI1iv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI1iv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI1iv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI1ui(GLuint index, GLuint x);
// public static native void glVertexAttribI1ui(int index, int x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI1ui(JNIEnv* env, jclass clazz, jint index, jint x)
{
    glVertexAttribI1ui(
        (GLuint)index,
        (GLuint)x);
}

// void glVertexAttribI1uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI1uiv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI1uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI1uiv(
        (GLuint)index,
        (GLuint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI1uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI1uiv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI1uiv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI1uiv(
        (GLuint)index,
        (GLuint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI2i(GLuint index, GLint x, GLint y);
// public static native void glVertexAttribI2i(int index, int x, int y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI2i(JNIEnv* env, jclass clazz, jint index, jint x, jint y)
{
    glVertexAttribI2i(
        (GLuint)index,
        (GLint)x,
        (GLint)y);
}

// void glVertexAttribI2iv(GLuint index, GLint* v);
// public static native void glVertexAttribI2iv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI2iv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI2iv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI2iv(GLuint index, GLint* v);
// public static native void glVertexAttribI2iv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI2iv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI2iv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
// public static native void glVertexAttribI2ui(int index, int x, int y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI2ui(JNIEnv* env, jclass clazz, jint index, jint x, jint y)
{
    glVertexAttribI2ui(
        (GLuint)index,
        (GLuint)x,
        (GLuint)y);
}

// void glVertexAttribI2uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI2uiv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI2uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI2uiv(
        (GLuint)index,
        (GLuint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI2uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI2uiv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI2uiv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI2uiv(
        (GLuint)index,
        (GLuint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
// public static native void glVertexAttribI3i(int index, int x, int y, int z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI3i(JNIEnv* env, jclass clazz, jint index, jint x, jint y, jint z)
{
    glVertexAttribI3i(
        (GLuint)index,
        (GLint)x,
        (GLint)y,
        (GLint)z);
}

// void glVertexAttribI3iv(GLuint index, GLint* v);
// public static native void glVertexAttribI3iv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI3iv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI3iv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI3iv(GLuint index, GLint* v);
// public static native void glVertexAttribI3iv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI3iv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI3iv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
// public static native void glVertexAttribI3ui(int index, int x, int y, int z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI3ui(JNIEnv* env, jclass clazz, jint index, jint x, jint y, jint z)
{
    glVertexAttribI3ui(
        (GLuint)index,
        (GLuint)x,
        (GLuint)y,
        (GLuint)z);
}

// void glVertexAttribI3uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI3uiv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI3uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI3uiv(
        (GLuint)index,
        (GLuint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI3uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI3uiv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI3uiv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI3uiv(
        (GLuint)index,
        (GLuint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI4bv(GLuint index, GLbyte* v);
// public static native void glVertexAttribI4bv(int index, ByteBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4bv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI4bv(
        (GLuint)index,
        (GLbyte*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI4bv(GLuint index, GLbyte* v);
// public static native void glVertexAttribI4bv(int index, byte[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4bv__I_3BI(JNIEnv* env, jclass clazz, jint index, jbyteArray v, jint vOffset)
{
    jbyte* j_v = v ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI4bv(
        (GLuint)index,
        (GLbyte*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
// public static native void glVertexAttribI4i(int index, int x, int y, int z, int w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4i(JNIEnv* env, jclass clazz, jint index, jint x, jint y, jint z, jint w)
{
    glVertexAttribI4i(
        (GLuint)index,
        (GLint)x,
        (GLint)y,
        (GLint)z,
        (GLint)w);
}

// void glVertexAttribI4iv(GLuint index, GLint* v);
// public static native void glVertexAttribI4iv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4iv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI4iv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI4iv(GLuint index, GLint* v);
// public static native void glVertexAttribI4iv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4iv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI4iv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI4sv(GLuint index, GLshort* v);
// public static native void glVertexAttribI4sv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4sv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI4sv(
        (GLuint)index,
        (GLshort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI4sv(GLuint index, GLshort* v);
// public static native void glVertexAttribI4sv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4sv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI4sv(
        (GLuint)index,
        (GLshort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI4ubv(GLuint index, GLubyte* v);
// public static native void glVertexAttribI4ubv(int index, ByteBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4ubv__ILjava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI4ubv(
        (GLuint)index,
        (GLubyte*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI4ubv(GLuint index, GLubyte* v);
// public static native void glVertexAttribI4ubv(int index, byte[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4ubv__I_3BI(JNIEnv* env, jclass clazz, jint index, jbyteArray v, jint vOffset)
{
    jbyte* j_v = v ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI4ubv(
        (GLuint)index,
        (GLubyte*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
// public static native void glVertexAttribI4ui(int index, int x, int y, int z, int w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4ui(JNIEnv* env, jclass clazz, jint index, jint x, jint y, jint z, jint w)
{
    glVertexAttribI4ui(
        (GLuint)index,
        (GLuint)x,
        (GLuint)y,
        (GLuint)z,
        (GLuint)w);
}

// void glVertexAttribI4uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI4uiv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI4uiv(
        (GLuint)index,
        (GLuint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI4uiv(GLuint index, GLuint* v);
// public static native void glVertexAttribI4uiv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4uiv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI4uiv(
        (GLuint)index,
        (GLuint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribI4usv(GLuint index, GLushort* v);
// public static native void glVertexAttribI4usv(int index, ShortBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4usv__ILjava_nio_ShortBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribI4usv(
        (GLuint)index,
        (GLushort*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribI4usv(GLuint index, GLushort* v);
// public static native void glVertexAttribI4usv(int index, short[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribI4usv__I_3SI(JNIEnv* env, jclass clazz, jint index, jshortArray v, jint vOffset)
{
    jshort* j_v = v ? (jshort*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribI4usv(
        (GLuint)index,
        (GLushort*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
// public static native void glVertexAttribIPointer(int index, int size, int type, int stride, Buffer pointer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribIPointer__IIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint index, jint size, jint type, jint stride, jobject pointer)
{
    glVertexAttribIPointer(
        (GLuint)index,
        (GLint)size,
        (GLenum)type,
        (GLsizei)stride,
        (GLvoid*)(pointer ? (*env)->GetDirectBufferAddress(env, pointer) : 0));
}

// void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
// public static native void glVertexAttribIPointer(int index, int size, int type, int stride, long pointer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribIPointer__IIIIJ(JNIEnv* env, jclass clazz, jint index, jint size, jint type, jint stride, jlong pointer)
{
    glVertexAttribIPointer(
        (GLuint)index,
        (GLint)size,
        (GLenum)type,
        (GLsizei)stride,
        (GLvoid*)long2Ptr(pointer));
}

// void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
// public static native void glCopyBufferSubData(int readTarget, int writeTarget, int readOffset, int writeOffset, int size);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCopyBufferSubData(JNIEnv* env, jclass clazz, jint readTarget, jint writeTarget, jint readOffset, jint writeOffset, jint size)
{
    glCopyBufferSubData(
        (GLenum)readTarget,
        (GLenum)writeTarget,
        (GLintptr)readOffset,
        (GLintptr)writeOffset,
        (GLsizeiptr)size);
}

// void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
// public static native void glDrawArraysInstanced(int mode, int first, int count, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawArraysInstanced(JNIEnv* env, jclass clazz, jint mode, jint first, jint count, jint primcount)
{
    glDrawArraysInstanced(
        (GLenum)mode,
        (GLint)first,
        (GLsizei)count,
        (GLsizei)primcount);
}

// void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount);
// public static native void glDrawElementsInstanced(int mode, int count, int type, Buffer indices, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsInstanced__IIILjava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jobject indices, jint primcount)
{
    glDrawElementsInstanced(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0),
        (GLsizei)primcount);
}

// void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount);
// public static native void glDrawElementsInstanced(int mode, int count, int type, long indices, int primcount);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsInstanced__IIIJI(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jlong indices, jint primcount)
{
    glDrawElementsInstanced(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)long2Ptr(indices),
        (GLsizei)primcount);
}

// void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
// public static native void glGetActiveUniformBlockName(int program, int uniformBlockIndex, int bufSize, IntBuffer length, ByteBuffer uniformBlockName);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformBlockName__IIILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint uniformBlockIndex, jint bufSize, jobject length, jobject uniformBlockName)
{
    glGetActiveUniformBlockName(
        (GLuint)program,
        (GLuint)uniformBlockIndex,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(uniformBlockName ? (*env)->GetDirectBufferAddress(env, uniformBlockName) : 0));
}

// void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
// public static native void glGetActiveUniformBlockName(int program, int uniformBlockIndex, int bufSize, int[] length, int lengthOffset, byte[] uniformBlockName, int uniformBlockNameOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformBlockName__III_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint uniformBlockIndex, jint bufSize, jintArray length, jint lengthOffset, jbyteArray uniformBlockName, jint uniformBlockNameOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_uniformBlockName = uniformBlockName ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, uniformBlockName, 0)) : 0;
    glGetActiveUniformBlockName(
        (GLuint)program,
        (GLuint)uniformBlockIndex,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_uniformBlockName + uniformBlockNameOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(uniformBlockName) (*env)->ReleasePrimitiveArrayCritical(env, uniformBlockName, j_uniformBlockName, 0);
}

// void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
// public static native void glGetActiveUniformBlockiv(int program, int uniformBlockIndex, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformBlockiv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint uniformBlockIndex, jint pname, jobject params)
{
    glGetActiveUniformBlockiv(
        (GLuint)program,
        (GLuint)uniformBlockIndex,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
// public static native void glGetActiveUniformBlockiv(int program, int uniformBlockIndex, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformBlockiv__III_3II(JNIEnv* env, jclass clazz, jint program, jint uniformBlockIndex, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetActiveUniformBlockiv(
        (GLuint)program,
        (GLuint)uniformBlockIndex,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
// public static native void glGetActiveUniformName(int program, int uniformIndex, int bufSize, IntBuffer length, ByteBuffer uniformName);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformName__IIILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint uniformIndex, jint bufSize, jobject length, jobject uniformName)
{
    glGetActiveUniformName(
        (GLuint)program,
        (GLuint)uniformIndex,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(uniformName ? (*env)->GetDirectBufferAddress(env, uniformName) : 0));
}

// void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
// public static native void glGetActiveUniformName(int program, int uniformIndex, int bufSize, int[] length, int lengthOffset, byte[] uniformName, int uniformNameOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformName__III_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint uniformIndex, jint bufSize, jintArray length, jint lengthOffset, jbyteArray uniformName, jint uniformNameOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_uniformName = uniformName ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, uniformName, 0)) : 0;
    glGetActiveUniformName(
        (GLuint)program,
        (GLuint)uniformIndex,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_uniformName + uniformNameOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(uniformName) (*env)->ReleasePrimitiveArrayCritical(env, uniformName, j_uniformName, 0);
}

// void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint* uniformIndices, GLenum pname, GLint* params);
// public static native void glGetActiveUniformsiv(int program, int uniformCount, IntBuffer uniformIndices, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformsiv__IILjava_nio_IntBuffer_2ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint uniformCount, jobject uniformIndices, jint pname, jobject params)
{
    glGetActiveUniformsiv(
        (GLuint)program,
        (GLsizei)uniformCount,
        (GLuint*)(uniformIndices ? (*env)->GetDirectBufferAddress(env, uniformIndices) : 0),
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint* uniformIndices, GLenum pname, GLint* params);
// public static native void glGetActiveUniformsiv(int program, int uniformCount, int[] uniformIndices, int uniformIndicesOffset, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveUniformsiv__II_3III_3II(JNIEnv* env, jclass clazz, jint program, jint uniformCount, jintArray uniformIndices, jint uniformIndicesOffset, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_uniformIndices = uniformIndices ? (jint*)((*env)->GetPrimitiveArrayCritical(env, uniformIndices, 0)) : 0;
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetActiveUniformsiv(
        (GLuint)program,
        (GLsizei)uniformCount,
        (GLuint*)(j_uniformIndices + uniformIndicesOffset),
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(uniformIndices) (*env)->ReleasePrimitiveArrayCritical(env, uniformIndices, j_uniformIndices, 0);
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLuint glGetUniformBlockIndex(GLuint program, GLchar* uniformBlockName);
// public static native int glGetUniformBlockIndex(int program, String uniformBlockName);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformBlockIndex(JNIEnv* env, jclass clazz, jint program, jstring uniformBlockName)
{
    const char* j_uniformBlockName = (*env)->GetStringUTFChars(env, uniformBlockName, 0);
    GLuint ret = (GLuint)
        glGetUniformBlockIndex(
        (GLuint)program,
        (GLchar*)j_uniformBlockName);
    (*env)->ReleaseStringUTFChars(env, uniformBlockName, j_uniformBlockName);
    return (jint)ret;
}

// void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar** uniformNames, GLuint* uniformIndices);
// public static native void glGetUniformIndices(int program, int uniformCount, String[] uniformNames, IntBuffer uniformIndices);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformIndices__II_3Ljava_lang_String_2Ljava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint uniformCount, jobjectArray uniformNames, jobject uniformIndices)
{
    const char** j_uniformNames = newNativeStringArray(env, uniformNames);
    glGetUniformIndices(
        (GLuint)program,
        (GLsizei)uniformCount,
        (const GLchar**)j_uniformNames,
        (GLuint*)(uniformIndices ? (*env)->GetDirectBufferAddress(env, uniformIndices) : 0));
    freeNativeStringArray(j_uniformNames);
}

// void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar** uniformNames, GLuint* uniformIndices);
// public static native void glGetUniformIndices(int program, int uniformCount, String[] uniformNames, int[] uniformIndices, int uniformIndicesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformIndices__II_3Ljava_lang_String_2_3II(JNIEnv* env, jclass clazz, jint program, jint uniformCount, jobjectArray uniformNames, jintArray uniformIndices, jint uniformIndicesOffset)
{
    const char** j_uniformNames = newNativeStringArray(env, uniformNames);
    jint* j_uniformIndices = uniformIndices ? (jint*)((*env)->GetPrimitiveArrayCritical(env, uniformIndices, 0)) : 0;
    glGetUniformIndices(
        (GLuint)program,
        (GLsizei)uniformCount,
        (const GLchar**)j_uniformNames,
        (GLuint*)(j_uniformIndices + uniformIndicesOffset));
    freeNativeStringArray(j_uniformNames);
    if(uniformIndices) (*env)->ReleasePrimitiveArrayCritical(env, uniformIndices, j_uniformIndices, 0);
}

// void glPrimitiveRestartIndex(GLuint index);
// public static native void glPrimitiveRestartIndex(int index);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPrimitiveRestartIndex(JNIEnv* env, jclass clazz, jint index)
{
    glPrimitiveRestartIndex(
        (GLuint)index);
}

// void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
// public static native void glTexBuffer(int target, int internalformat, int buffer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexBuffer(JNIEnv* env, jclass clazz, jint target, jint internalformat, jint buffer)
{
    glTexBuffer(
        (GLenum)target,
        (GLenum)internalformat,
        (GLuint)buffer);
}

// void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
// public static native void glUniformBlockBinding(int program, int uniformBlockIndex, int uniformBlockBinding);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformBlockBinding(JNIEnv* env, jclass clazz, jint program, jint uniformBlockIndex, jint uniformBlockBinding)
{
    glUniformBlockBinding(
        (GLuint)program,
        (GLuint)uniformBlockIndex,
        (GLuint)uniformBlockBinding);
}

// void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex);
// public static native void glDrawElementsBaseVertex(int mode, int count, int type, Buffer indices, int basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsBaseVertex__IIILjava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jobject indices, jint basevertex)
{
    glDrawElementsBaseVertex(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0),
        (GLint)basevertex);
}

// void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex);
// public static native void glDrawElementsBaseVertex(int mode, int count, int type, long indices, int basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsBaseVertex__IIIJI(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jlong indices, jint basevertex)
{
    glDrawElementsBaseVertex(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)long2Ptr(indices),
        (GLint)basevertex);
}

// void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint basevertex);
// public static native void glDrawElementsInstancedBaseVertex(int mode, int count, int type, Buffer indices, int primcount, int basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsInstancedBaseVertex__IIILjava_nio_Buffer_2II(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jobject indices, jint primcount, jint basevertex)
{
    glDrawElementsInstancedBaseVertex(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0),
        (GLsizei)primcount,
        (GLint)basevertex);
}

// void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint basevertex);
// public static native void glDrawElementsInstancedBaseVertex(int mode, int count, int type, long indices, int primcount, int basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsInstancedBaseVertex__IIIJII(JNIEnv* env, jclass clazz, jint mode, jint count, jint type, jlong indices, jint primcount, jint basevertex)
{
    glDrawElementsInstancedBaseVertex(
        (GLenum)mode,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)long2Ptr(indices),
        (GLsizei)primcount,
        (GLint)basevertex);
}

// void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex);
// public static native void glDrawRangeElementsBaseVertex(int mode, int start, int end, int count, int type, Buffer indices, int basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawRangeElementsBaseVertex__IIIIILjava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint mode, jint start, jint end, jint count, jint type, jobject indices, jint basevertex)
{
    glDrawRangeElementsBaseVertex(
        (GLenum)mode,
        (GLuint)start,
        (GLuint)end,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0),
        (GLint)basevertex);
}

// void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex);
// public static native void glDrawRangeElementsBaseVertex(int mode, int start, int end, int count, int type, long indices, int basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawRangeElementsBaseVertex__IIIIIJI(JNIEnv* env, jclass clazz, jint mode, jint start, jint end, jint count, jint type, jlong indices, jint basevertex)
{
    glDrawRangeElementsBaseVertex(
        (GLenum)mode,
        (GLuint)start,
        (GLuint)end,
        (GLsizei)count,
        (GLenum)type,
        (GLvoid*)long2Ptr(indices),
        (GLint)basevertex);
}

// void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
// public static native void glFramebufferTexture(int target, int attachment, int texture, int level);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glFramebufferTexture(JNIEnv* env, jclass clazz, jint target, jint attachment, jint texture, jint level)
{
    glFramebufferTexture(
        (GLenum)target,
        (GLenum)attachment,
        (GLuint)texture,
        (GLint)level);
}

// void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params);
// public static native void glGetBufferParameteri64v(int target, int pname, LongBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBufferParameteri64v__IILjava_nio_LongBuffer_2(JNIEnv* env, jclass clazz, jint target, jint pname, jobject params)
{
    glGetBufferParameteri64v(
        (GLenum)target,
        (GLenum)pname,
        (GLint64*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params);
// public static native void glGetBufferParameteri64v(int target, int pname, long[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetBufferParameteri64v__II_3JI(JNIEnv* env, jclass clazz, jint target, jint pname, jlongArray params, jint paramsOffset)
{
    jlong* j_params = params ? (jlong*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetBufferParameteri64v(
        (GLenum)target,
        (GLenum)pname,
        (GLint64*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data);
// public static native void glGetInteger64i_v(int target, int index, LongBuffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetInteger64i_1v__IILjava_nio_LongBuffer_2(JNIEnv* env, jclass clazz, jint target, jint index, jobject data)
{
    glGetInteger64i_v(
        (GLenum)target,
        (GLuint)index,
        (GLint64*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data);
// public static native void glGetInteger64i_v(int target, int index, long[] data, int dataOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetInteger64i_1v__II_3JI(JNIEnv* env, jclass clazz, jint target, jint index, jlongArray data, jint dataOffset)
{
    jlong* j_data = data ? (jlong*)((*env)->GetPrimitiveArrayCritical(env, data, 0)) : 0;
    glGetInteger64i_v(
        (GLenum)target,
        (GLuint)index,
        (GLint64*)(j_data + dataOffset));
    if(data) (*env)->ReleasePrimitiveArrayCritical(env, data, j_data, 0);
}

// void glGetInteger64v(GLenum pname, GLint64* params);
// public static native void glGetInteger64v(int pname, LongBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetInteger64v__ILjava_nio_LongBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject params)
{
    glGetInteger64v(
        (GLenum)pname,
        (GLint64*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetInteger64v(GLenum pname, GLint64* params);
// public static native void glGetInteger64v(int pname, long[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetInteger64v__I_3JI(JNIEnv* env, jclass clazz, jint pname, jlongArray params, jint paramsOffset)
{
    jlong* j_params = params ? (jlong*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetInteger64v(
        (GLenum)pname,
        (GLint64*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
// public static native void glGetMultisamplefv(int pname, int index, FloatBuffer val);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetMultisamplefv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint pname, jint index, jobject val)
{
    glGetMultisamplefv(
        (GLenum)pname,
        (GLuint)index,
        (GLfloat*)(val ? (*env)->GetDirectBufferAddress(env, val) : 0));
}

// void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
// public static native void glGetMultisamplefv(int pname, int index, float[] val, int valOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetMultisamplefv__II_3FI(JNIEnv* env, jclass clazz, jint pname, jint index, jfloatArray val, jint valOffset)
{
    jfloat* j_val = val ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, val, 0)) : 0;
    glGetMultisamplefv(
        (GLenum)pname,
        (GLuint)index,
        (GLfloat*)(j_val + valOffset));
    if(val) (*env)->ReleasePrimitiveArrayCritical(env, val, j_val, 0);
}

// void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount, GLint* basevertex);
// public static native void glMultiDrawElementsBaseVertex(int mode, IntBuffer count, int type, Buffer[] indices, int primcount, IntBuffer basevertex);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiDrawElementsBaseVertex__ILjava_nio_IntBuffer_2I_3Ljava_nio_Buffer_2ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint mode, jobject count, jint type, jobjectArray indices, jint primcount, jobject basevertex)
{
    void** j_indices = newNativeBufferArray(env, indices);
    glMultiDrawElementsBaseVertex(
        (GLenum)mode,
        (GLsizei*)(count ? (*env)->GetDirectBufferAddress(env, count) : 0),
        (GLenum)type,
        (const GLvoid**)j_indices,
        (GLsizei)primcount,
        (GLint*)(basevertex ? (*env)->GetDirectBufferAddress(env, basevertex) : 0));
    freeNativeBufferArray(j_indices);
}

// void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount, GLint* basevertex);
// public static native void glMultiDrawElementsBaseVertex(int mode, int[] count, int countOffset, int type, Buffer[] indices, int primcount, int[] basevertex, int basevertexOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiDrawElementsBaseVertex__I_3III_3Ljava_nio_Buffer_2I_3II(JNIEnv* env, jclass clazz, jint mode, jintArray count, jint countOffset, jint type, jobjectArray indices, jint primcount, jintArray basevertex, jint basevertexOffset)
{
    jint* j_count = count ? (jint*)((*env)->GetPrimitiveArrayCritical(env, count, 0)) : 0;
    void** j_indices = newNativeBufferArray(env, indices);
    jint* j_basevertex = basevertex ? (jint*)((*env)->GetPrimitiveArrayCritical(env, basevertex, 0)) : 0;
    glMultiDrawElementsBaseVertex(
        (GLenum)mode,
        (GLsizei*)(j_count + countOffset),
        (GLenum)type,
        (const GLvoid**)j_indices,
        (GLsizei)primcount,
        (GLint*)(j_basevertex + basevertexOffset));
    if(count) (*env)->ReleasePrimitiveArrayCritical(env, count, j_count, 0);
    freeNativeBufferArray(j_indices);
    if(basevertex) (*env)->ReleasePrimitiveArrayCritical(env, basevertex, j_basevertex, 0);
}

// void glProvokingVertex(GLenum mode);
// public static native void glProvokingVertex(int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProvokingVertex(JNIEnv* env, jclass clazz, jint mode)
{
    glProvokingVertex(
        (GLenum)mode);
}

// void glSampleMaski(GLuint index, GLbitfield mask);
// public static native void glSampleMaski(int index, int mask);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSampleMaski(JNIEnv* env, jclass clazz, jint index, jint mask)
{
    glSampleMaski(
        (GLuint)index,
        (GLbitfield)mask);
}

// void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
// public static native void glTexImage2DMultisample(int target, int samples, int internalformat, int width, int height, boolean fixedsamplelocations);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage2DMultisample(JNIEnv* env, jclass clazz, jint target, jint samples, jint internalformat, jint width, jint height, jboolean fixedsamplelocations)
{
    glTexImage2DMultisample(
        (GLenum)target,
        (GLsizei)samples,
        (GLint)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLboolean)(fixedsamplelocations == JNI_TRUE ? GL_TRUE : GL_FALSE));
}

// void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
// public static native void glTexImage3DMultisample(int target, int samples, int internalformat, int width, int height, int depth, boolean fixedsamplelocations);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexImage3DMultisample(JNIEnv* env, jclass clazz, jint target, jint samples, jint internalformat, jint width, jint height, jint depth, jboolean fixedsamplelocations)
{
    glTexImage3DMultisample(
        (GLenum)target,
        (GLsizei)samples,
        (GLint)internalformat,
        (GLsizei)width,
        (GLsizei)height,
        (GLsizei)depth,
        (GLboolean)(fixedsamplelocations == JNI_TRUE ? GL_TRUE : GL_FALSE));
}

// void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar* name);
// public static native void glBindFragDataLocationIndexed(int program, int colorNumber, int index, String name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindFragDataLocationIndexed(JNIEnv* env, jclass clazz, jint program, jint colorNumber, jint index, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    glBindFragDataLocationIndexed(
        (GLuint)program,
        (GLuint)colorNumber,
        (GLuint)index,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
}

// void glBindSampler(GLuint unit, GLuint sampler);
// public static native void glBindSampler(int unit, int sampler);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindSampler(JNIEnv* env, jclass clazz, jint unit, jint sampler)
{
    glBindSampler(
        (GLuint)unit,
        (GLuint)sampler);
}

// void glColorP3ui(GLenum type, GLuint color);
// public static native void glColorP3ui(int type, int color);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorP3ui(JNIEnv* env, jclass clazz, jint type, jint color)
{
    glColorP3ui(
        (GLenum)type,
        (GLuint)color);
}

// void glColorP3uiv(GLenum type, GLuint* color);
// public static native void glColorP3uiv(int type, IntBuffer color);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorP3uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject color)
{
    glColorP3uiv(
        (GLenum)type,
        (GLuint*)(color ? (*env)->GetDirectBufferAddress(env, color) : 0));
}

// void glColorP3uiv(GLenum type, GLuint* color);
// public static native void glColorP3uiv(int type, int[] color, int colorOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorP3uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray color, jint colorOffset)
{
    jint* j_color = color ? (jint*)((*env)->GetPrimitiveArrayCritical(env, color, 0)) : 0;
    glColorP3uiv(
        (GLenum)type,
        (GLuint*)(j_color + colorOffset));
    if(color) (*env)->ReleasePrimitiveArrayCritical(env, color, j_color, 0);
}

// void glColorP4ui(GLenum type, GLuint color);
// public static native void glColorP4ui(int type, int color);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorP4ui(JNIEnv* env, jclass clazz, jint type, jint color)
{
    glColorP4ui(
        (GLenum)type,
        (GLuint)color);
}

// void glColorP4uiv(GLenum type, GLuint* color);
// public static native void glColorP4uiv(int type, IntBuffer color);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorP4uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject color)
{
    glColorP4uiv(
        (GLenum)type,
        (GLuint*)(color ? (*env)->GetDirectBufferAddress(env, color) : 0));
}

// void glColorP4uiv(GLenum type, GLuint* color);
// public static native void glColorP4uiv(int type, int[] color, int colorOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glColorP4uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray color, jint colorOffset)
{
    jint* j_color = color ? (jint*)((*env)->GetPrimitiveArrayCritical(env, color, 0)) : 0;
    glColorP4uiv(
        (GLenum)type,
        (GLuint*)(j_color + colorOffset));
    if(color) (*env)->ReleasePrimitiveArrayCritical(env, color, j_color, 0);
}

// void glDeleteSamplers(GLsizei count, GLuint* samplers);
// public static native void glDeleteSamplers(int count, IntBuffer samplers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteSamplers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint count, jobject samplers)
{
    glDeleteSamplers(
        (GLsizei)count,
        (GLuint*)(samplers ? (*env)->GetDirectBufferAddress(env, samplers) : 0));
}

// void glDeleteSamplers(GLsizei count, GLuint* samplers);
// public static native void glDeleteSamplers(int count, int[] samplers, int samplersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteSamplers__I_3II(JNIEnv* env, jclass clazz, jint count, jintArray samplers, jint samplersOffset)
{
    jint* j_samplers = samplers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, samplers, 0)) : 0;
    glDeleteSamplers(
        (GLsizei)count,
        (GLuint*)(j_samplers + samplersOffset));
    if(samplers) (*env)->ReleasePrimitiveArrayCritical(env, samplers, j_samplers, 0);
}

// void glGenSamplers(GLsizei count, GLuint* samplers);
// public static native void glGenSamplers(int count, IntBuffer samplers);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenSamplers__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint count, jobject samplers)
{
    glGenSamplers(
        (GLsizei)count,
        (GLuint*)(samplers ? (*env)->GetDirectBufferAddress(env, samplers) : 0));
}

// void glGenSamplers(GLsizei count, GLuint* samplers);
// public static native void glGenSamplers(int count, int[] samplers, int samplersOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenSamplers__I_3II(JNIEnv* env, jclass clazz, jint count, jintArray samplers, jint samplersOffset)
{
    jint* j_samplers = samplers ? (jint*)((*env)->GetPrimitiveArrayCritical(env, samplers, 0)) : 0;
    glGenSamplers(
        (GLsizei)count,
        (GLuint*)(j_samplers + samplersOffset));
    if(samplers) (*env)->ReleasePrimitiveArrayCritical(env, samplers, j_samplers, 0);
}

// GLint glGetFragDataIndex(GLuint program, GLchar* name);
// public static native int glGetFragDataIndex(int program, String name);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFragDataIndex(JNIEnv* env, jclass clazz, jint program, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    GLint ret = (GLint)
        glGetFragDataIndex(
        (GLuint)program,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
    return (jint)ret;
}

// void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params);
// public static native void glGetQueryObjecti64v(int id, int pname, LongBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjecti64v__IILjava_nio_LongBuffer_2(JNIEnv* env, jclass clazz, jint id, jint pname, jobject params)
{
    glGetQueryObjecti64v(
        (GLuint)id,
        (GLenum)pname,
        (GLint64*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params);
// public static native void glGetQueryObjecti64v(int id, int pname, long[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjecti64v__II_3JI(JNIEnv* env, jclass clazz, jint id, jint pname, jlongArray params, jint paramsOffset)
{
    jlong* j_params = params ? (jlong*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetQueryObjecti64v(
        (GLuint)id,
        (GLenum)pname,
        (GLint64*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params);
// public static native void glGetQueryObjectui64v(int id, int pname, LongBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjectui64v__IILjava_nio_LongBuffer_2(JNIEnv* env, jclass clazz, jint id, jint pname, jobject params)
{
    glGetQueryObjectui64v(
        (GLuint)id,
        (GLenum)pname,
        (GLuint64*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params);
// public static native void glGetQueryObjectui64v(int id, int pname, long[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryObjectui64v__II_3JI(JNIEnv* env, jclass clazz, jint id, jint pname, jlongArray params, jint paramsOffset)
{
    jlong* j_params = params ? (jlong*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetQueryObjectui64v(
        (GLuint)id,
        (GLenum)pname,
        (GLuint64*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params);
// public static native void glGetSamplerParameterIiv(int sampler, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameterIiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject params)
{
    glGetSamplerParameterIiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params);
// public static native void glGetSamplerParameterIiv(int sampler, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameterIiv__II_3II(JNIEnv* env, jclass clazz, jint sampler, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetSamplerParameterIiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

#ifndef MACOS
// void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params);
// public static native void glGetSamplerParameterIuiv(int sampler, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameterIuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject params)
{
    glGetSamplerParameterIuiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params);
// public static native void glGetSamplerParameterIuiv(int sampler, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameterIuiv__II_3II(JNIEnv* env, jclass clazz, jint sampler, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetSamplerParameterIuiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}
#endif

// void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params);
// public static native void glGetSamplerParameterfv(int sampler, int pname, FloatBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameterfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject params)
{
    glGetSamplerParameterfv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLfloat*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params);
// public static native void glGetSamplerParameterfv(int sampler, int pname, float[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameterfv__II_3FI(JNIEnv* env, jclass clazz, jint sampler, jint pname, jfloatArray params, jint paramsOffset)
{
    jfloat* j_params = params ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetSamplerParameterfv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLfloat*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params);
// public static native void glGetSamplerParameteriv(int sampler, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameteriv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject params)
{
    glGetSamplerParameteriv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params);
// public static native void glGetSamplerParameteriv(int sampler, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSamplerParameteriv__II_3II(JNIEnv* env, jclass clazz, jint sampler, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetSamplerParameteriv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLboolean glIsSampler(GLuint sampler);
// public static native boolean glIsSampler(int sampler);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsSampler(JNIEnv* env, jclass clazz, jint sampler)
{
    GLboolean ret = (GLboolean)
        glIsSampler(
        (GLuint)sampler);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
// public static native void glMultiTexCoordP1ui(int texture, int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP1ui(JNIEnv* env, jclass clazz, jint texture, jint type, jint coords)
{
    glMultiTexCoordP1ui(
        (GLenum)texture,
        (GLenum)type,
        (GLuint)coords);
}

// void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP1uiv(int texture, int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP1uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint texture, jint type, jobject coords)
{
    glMultiTexCoordP1uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP1uiv(int texture, int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP1uiv__II_3II(JNIEnv* env, jclass clazz, jint texture, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glMultiTexCoordP1uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
// public static native void glMultiTexCoordP2ui(int texture, int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP2ui(JNIEnv* env, jclass clazz, jint texture, jint type, jint coords)
{
    glMultiTexCoordP2ui(
        (GLenum)texture,
        (GLenum)type,
        (GLuint)coords);
}

// void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP2uiv(int texture, int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP2uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint texture, jint type, jobject coords)
{
    glMultiTexCoordP2uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP2uiv(int texture, int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP2uiv__II_3II(JNIEnv* env, jclass clazz, jint texture, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glMultiTexCoordP2uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
// public static native void glMultiTexCoordP3ui(int texture, int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP3ui(JNIEnv* env, jclass clazz, jint texture, jint type, jint coords)
{
    glMultiTexCoordP3ui(
        (GLenum)texture,
        (GLenum)type,
        (GLuint)coords);
}

// void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP3uiv(int texture, int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP3uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint texture, jint type, jobject coords)
{
    glMultiTexCoordP3uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP3uiv(int texture, int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP3uiv__II_3II(JNIEnv* env, jclass clazz, jint texture, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glMultiTexCoordP3uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
// public static native void glMultiTexCoordP4ui(int texture, int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP4ui(JNIEnv* env, jclass clazz, jint texture, jint type, jint coords)
{
    glMultiTexCoordP4ui(
        (GLenum)texture,
        (GLenum)type,
        (GLuint)coords);
}

// void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP4uiv(int texture, int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP4uiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint texture, jint type, jobject coords)
{
    glMultiTexCoordP4uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint* coords);
// public static native void glMultiTexCoordP4uiv(int texture, int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMultiTexCoordP4uiv__II_3II(JNIEnv* env, jclass clazz, jint texture, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glMultiTexCoordP4uiv(
        (GLenum)texture,
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glNormalP3ui(GLenum type, GLuint coords);
// public static native void glNormalP3ui(int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glNormalP3ui(JNIEnv* env, jclass clazz, jint type, jint coords)
{
    glNormalP3ui(
        (GLenum)type,
        (GLuint)coords);
}

// void glNormalP3uiv(GLenum type, GLuint* coords);
// public static native void glNormalP3uiv(int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glNormalP3uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject coords)
{
    glNormalP3uiv(
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glNormalP3uiv(GLenum type, GLuint* coords);
// public static native void glNormalP3uiv(int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glNormalP3uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glNormalP3uiv(
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glQueryCounter(GLuint id, GLenum target);
// public static native void glQueryCounter(int id, int target);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glQueryCounter(JNIEnv* env, jclass clazz, jint id, jint target)
{
    glQueryCounter(
        (GLuint)id,
        (GLenum)target);
}

// void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* param);
// public static native void glSamplerParameterIiv(int sampler, int pname, IntBuffer param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterIiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject param)
{
    glSamplerParameterIiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(param ? (*env)->GetDirectBufferAddress(env, param) : 0));
}

// void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* param);
// public static native void glSamplerParameterIiv(int sampler, int pname, int[] param, int paramOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterIiv__II_3II(JNIEnv* env, jclass clazz, jint sampler, jint pname, jintArray param, jint paramOffset)
{
    jint* j_param = param ? (jint*)((*env)->GetPrimitiveArrayCritical(env, param, 0)) : 0;
    glSamplerParameterIiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(j_param + paramOffset));
    if(param) (*env)->ReleasePrimitiveArrayCritical(env, param, j_param, 0);
}

// void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* param);
// public static native void glSamplerParameterIuiv(int sampler, int pname, IntBuffer param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterIuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject param)
{
    glSamplerParameterIuiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLuint*)(param ? (*env)->GetDirectBufferAddress(env, param) : 0));
}

// void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* param);
// public static native void glSamplerParameterIuiv(int sampler, int pname, int[] param, int paramOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterIuiv__II_3II(JNIEnv* env, jclass clazz, jint sampler, jint pname, jintArray param, jint paramOffset)
{
    jint* j_param = param ? (jint*)((*env)->GetPrimitiveArrayCritical(env, param, 0)) : 0;
    glSamplerParameterIuiv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLuint*)(j_param + paramOffset));
    if(param) (*env)->ReleasePrimitiveArrayCritical(env, param, j_param, 0);
}

// void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
// public static native void glSamplerParameterf(int sampler, int pname, float param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterf(JNIEnv* env, jclass clazz, jint sampler, jint pname, jfloat param)
{
    glSamplerParameterf(
        (GLuint)sampler,
        (GLenum)pname,
        (GLfloat)param);
}

// void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* param);
// public static native void glSamplerParameterfv(int sampler, int pname, FloatBuffer param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterfv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject param)
{
    glSamplerParameterfv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLfloat*)(param ? (*env)->GetDirectBufferAddress(env, param) : 0));
}

// void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* param);
// public static native void glSamplerParameterfv(int sampler, int pname, float[] param, int paramOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameterfv__II_3FI(JNIEnv* env, jclass clazz, jint sampler, jint pname, jfloatArray param, jint paramOffset)
{
    jfloat* j_param = param ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, param, 0)) : 0;
    glSamplerParameterfv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLfloat*)(j_param + paramOffset));
    if(param) (*env)->ReleasePrimitiveArrayCritical(env, param, j_param, 0);
}

// void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
// public static native void glSamplerParameteri(int sampler, int pname, int param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameteri(JNIEnv* env, jclass clazz, jint sampler, jint pname, jint param)
{
    glSamplerParameteri(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint)param);
}

// void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint* param);
// public static native void glSamplerParameteriv(int sampler, int pname, IntBuffer param);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameteriv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint sampler, jint pname, jobject param)
{
    glSamplerParameteriv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(param ? (*env)->GetDirectBufferAddress(env, param) : 0));
}

// void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint* param);
// public static native void glSamplerParameteriv(int sampler, int pname, int[] param, int paramOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSamplerParameteriv__II_3II(JNIEnv* env, jclass clazz, jint sampler, jint pname, jintArray param, jint paramOffset)
{
    jint* j_param = param ? (jint*)((*env)->GetPrimitiveArrayCritical(env, param, 0)) : 0;
    glSamplerParameteriv(
        (GLuint)sampler,
        (GLenum)pname,
        (GLint*)(j_param + paramOffset));
    if(param) (*env)->ReleasePrimitiveArrayCritical(env, param, j_param, 0);
}

// void glSecondaryColorP3ui(GLenum type, GLuint color);
// public static native void glSecondaryColorP3ui(int type, int color);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSecondaryColorP3ui(JNIEnv* env, jclass clazz, jint type, jint color)
{
    glSecondaryColorP3ui(
        (GLenum)type,
        (GLuint)color);
}

// void glSecondaryColorP3uiv(GLenum type, GLuint* color);
// public static native void glSecondaryColorP3uiv(int type, IntBuffer color);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSecondaryColorP3uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject color)
{
    glSecondaryColorP3uiv(
        (GLenum)type,
        (GLuint*)(color ? (*env)->GetDirectBufferAddress(env, color) : 0));
}

// void glSecondaryColorP3uiv(GLenum type, GLuint* color);
// public static native void glSecondaryColorP3uiv(int type, int[] color, int colorOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glSecondaryColorP3uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray color, jint colorOffset)
{
    jint* j_color = color ? (jint*)((*env)->GetPrimitiveArrayCritical(env, color, 0)) : 0;
    glSecondaryColorP3uiv(
        (GLenum)type,
        (GLuint*)(j_color + colorOffset));
    if(color) (*env)->ReleasePrimitiveArrayCritical(env, color, j_color, 0);
}

// void glTexCoordP1ui(GLenum type, GLuint coords);
// public static native void glTexCoordP1ui(int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP1ui(JNIEnv* env, jclass clazz, jint type, jint coords)
{
    glTexCoordP1ui(
        (GLenum)type,
        (GLuint)coords);
}

// void glTexCoordP1uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP1uiv(int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP1uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject coords)
{
    glTexCoordP1uiv(
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glTexCoordP1uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP1uiv(int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP1uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glTexCoordP1uiv(
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glTexCoordP2ui(GLenum type, GLuint coords);
// public static native void glTexCoordP2ui(int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP2ui(JNIEnv* env, jclass clazz, jint type, jint coords)
{
    glTexCoordP2ui(
        (GLenum)type,
        (GLuint)coords);
}

// void glTexCoordP2uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP2uiv(int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP2uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject coords)
{
    glTexCoordP2uiv(
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glTexCoordP2uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP2uiv(int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP2uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glTexCoordP2uiv(
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glTexCoordP3ui(GLenum type, GLuint coords);
// public static native void glTexCoordP3ui(int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP3ui(JNIEnv* env, jclass clazz, jint type, jint coords)
{
    glTexCoordP3ui(
        (GLenum)type,
        (GLuint)coords);
}

// void glTexCoordP3uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP3uiv(int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP3uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject coords)
{
    glTexCoordP3uiv(
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glTexCoordP3uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP3uiv(int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP3uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glTexCoordP3uiv(
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

// void glTexCoordP4ui(GLenum type, GLuint coords);
// public static native void glTexCoordP4ui(int type, int coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP4ui(JNIEnv* env, jclass clazz, jint type, jint coords)
{
    glTexCoordP4ui(
        (GLenum)type,
        (GLuint)coords);
}

// void glTexCoordP4uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP4uiv(int type, IntBuffer coords);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP4uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject coords)
{
    glTexCoordP4uiv(
        (GLenum)type,
        (GLuint*)(coords ? (*env)->GetDirectBufferAddress(env, coords) : 0));
}

// void glTexCoordP4uiv(GLenum type, GLuint* coords);
// public static native void glTexCoordP4uiv(int type, int[] coords, int coordsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glTexCoordP4uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray coords, jint coordsOffset)
{
    jint* j_coords = coords ? (jint*)((*env)->GetPrimitiveArrayCritical(env, coords, 0)) : 0;
    glTexCoordP4uiv(
        (GLenum)type,
        (GLuint*)(j_coords + coordsOffset));
    if(coords) (*env)->ReleasePrimitiveArrayCritical(env, coords, j_coords, 0);
}

#ifndef MACOS
// void glVertexAttribDivisor(GLuint index, GLuint divisor);
// public static native void glVertexAttribDivisor(int index, int divisor);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribDivisor(JNIEnv* env, jclass clazz, jint index, jint divisor)
{
    glVertexAttribDivisor(
        (GLuint)index,
        (GLuint)divisor);
}
#endif

// void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
// public static native void glVertexAttribP1ui(int index, int type, boolean normalized, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP1ui(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jint value)
{
    glVertexAttribP1ui(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint)value);
}

// void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP1uiv(int index, int type, boolean normalized, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP1uiv__IIZLjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jobject value)
{
    glVertexAttribP1uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP1uiv(int index, int type, boolean normalized, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP1uiv__IIZ_3II(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexAttribP1uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
// public static native void glVertexAttribP2ui(int index, int type, boolean normalized, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP2ui(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jint value)
{
    glVertexAttribP2ui(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint)value);
}

// void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP2uiv(int index, int type, boolean normalized, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP2uiv__IIZLjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jobject value)
{
    glVertexAttribP2uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP2uiv(int index, int type, boolean normalized, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP2uiv__IIZ_3II(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexAttribP2uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
// public static native void glVertexAttribP3ui(int index, int type, boolean normalized, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP3ui(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jint value)
{
    glVertexAttribP3ui(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint)value);
}

// void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP3uiv(int index, int type, boolean normalized, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP3uiv__IIZLjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jobject value)
{
    glVertexAttribP3uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP3uiv(int index, int type, boolean normalized, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP3uiv__IIZ_3II(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexAttribP3uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
// public static native void glVertexAttribP4ui(int index, int type, boolean normalized, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP4ui(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jint value)
{
    glVertexAttribP4ui(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint)value);
}

// void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP4uiv(int index, int type, boolean normalized, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP4uiv__IIZLjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jobject value)
{
    glVertexAttribP4uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
// public static native void glVertexAttribP4uiv(int index, int type, boolean normalized, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribP4uiv__IIZ_3II(JNIEnv* env, jclass clazz, jint index, jint type, jboolean normalized, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexAttribP4uiv(
        (GLuint)index,
        (GLenum)type,
        (GLboolean)(normalized == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexP2ui(GLenum type, GLuint value);
// public static native void glVertexP2ui(int type, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP2ui(JNIEnv* env, jclass clazz, jint type, jint value)
{
    glVertexP2ui(
        (GLenum)type,
        (GLuint)value);
}

// void glVertexP2uiv(GLenum type, GLuint* value);
// public static native void glVertexP2uiv(int type, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP2uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject value)
{
    glVertexP2uiv(
        (GLenum)type,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexP2uiv(GLenum type, GLuint* value);
// public static native void glVertexP2uiv(int type, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP2uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexP2uiv(
        (GLenum)type,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexP3ui(GLenum type, GLuint value);
// public static native void glVertexP3ui(int type, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP3ui(JNIEnv* env, jclass clazz, jint type, jint value)
{
    glVertexP3ui(
        (GLenum)type,
        (GLuint)value);
}

// void glVertexP3uiv(GLenum type, GLuint* value);
// public static native void glVertexP3uiv(int type, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP3uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject value)
{
    glVertexP3uiv(
        (GLenum)type,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexP3uiv(GLenum type, GLuint* value);
// public static native void glVertexP3uiv(int type, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP3uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexP3uiv(
        (GLenum)type,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glVertexP4ui(GLenum type, GLuint value);
// public static native void glVertexP4ui(int type, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP4ui(JNIEnv* env, jclass clazz, jint type, jint value)
{
    glVertexP4ui(
        (GLenum)type,
        (GLuint)value);
}

// void glVertexP4uiv(GLenum type, GLuint* value);
// public static native void glVertexP4uiv(int type, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP4uiv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint type, jobject value)
{
    glVertexP4uiv(
        (GLenum)type,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glVertexP4uiv(GLenum type, GLuint* value);
// public static native void glVertexP4uiv(int type, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexP4uiv__I_3II(JNIEnv* env, jclass clazz, jint type, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glVertexP4uiv(
        (GLenum)type,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
// public static native void glBeginQueryIndexed(int target, int index, int id);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBeginQueryIndexed(JNIEnv* env, jclass clazz, jint target, jint index, jint id)
{
    glBeginQueryIndexed(
        (GLenum)target,
        (GLuint)index,
        (GLuint)id);
}

// void glBindTransformFeedback(GLenum target, GLuint id);
// public static native void glBindTransformFeedback(int target, int id);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindTransformFeedback(JNIEnv* env, jclass clazz, jint target, jint id)
{
    glBindTransformFeedback(
        (GLenum)target,
        (GLuint)id);
}

// void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
// public static native void glBlendEquationSeparatei(int buf, int modeRGB, int modeAlpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendEquationSeparatei(JNIEnv* env, jclass clazz, jint buf, jint modeRGB, jint modeAlpha)
{
    glBlendEquationSeparatei(
        (GLuint)buf,
        (GLenum)modeRGB,
        (GLenum)modeAlpha);
}

// void glBlendEquationi(GLuint buf, GLenum mode);
// public static native void glBlendEquationi(int buf, int mode);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendEquationi(JNIEnv* env, jclass clazz, jint buf, jint mode)
{
    glBlendEquationi(
        (GLuint)buf,
        (GLenum)mode);
}

// void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
// public static native void glBlendFuncSeparatei(int buf, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendFuncSeparatei(JNIEnv* env, jclass clazz, jint buf, jint srcRGB, jint dstRGB, jint srcAlpha, jint dstAlpha)
{
    glBlendFuncSeparatei(
        (GLuint)buf,
        (GLenum)srcRGB,
        (GLenum)dstRGB,
        (GLenum)srcAlpha,
        (GLenum)dstAlpha);
}

// void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
// public static native void glBlendFunci(int buf, int src, int dst);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBlendFunci(JNIEnv* env, jclass clazz, jint buf, jint src, jint dst)
{
    glBlendFunci(
        (GLuint)buf,
        (GLenum)src,
        (GLenum)dst);
}

// void glDeleteTransformFeedbacks(GLsizei n, GLuint* ids);
// public static native void glDeleteTransformFeedbacks(int n, IntBuffer ids);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteTransformFeedbacks__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject ids)
{
    glDeleteTransformFeedbacks(
        (GLsizei)n,
        (GLuint*)(ids ? (*env)->GetDirectBufferAddress(env, ids) : 0));
}

// void glDeleteTransformFeedbacks(GLsizei n, GLuint* ids);
// public static native void glDeleteTransformFeedbacks(int n, int[] ids, int idsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteTransformFeedbacks__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray ids, jint idsOffset)
{
    jint* j_ids = ids ? (jint*)((*env)->GetPrimitiveArrayCritical(env, ids, 0)) : 0;
    glDeleteTransformFeedbacks(
        (GLsizei)n,
        (GLuint*)(j_ids + idsOffset));
    if(ids) (*env)->ReleasePrimitiveArrayCritical(env, ids, j_ids, 0);
}

// void glDrawArraysIndirect(GLenum mode, GLvoid* indirect);
// public static native void glDrawArraysIndirect(int mode, Buffer indirect);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawArraysIndirect__ILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint mode, jobject indirect)
{
    glDrawArraysIndirect(
        (GLenum)mode,
        (GLvoid*)(indirect ? (*env)->GetDirectBufferAddress(env, indirect) : 0));
}

// void glDrawArraysIndirect(GLenum mode, GLvoid* indirect);
// public static native void glDrawArraysIndirect(int mode, long indirect);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawArraysIndirect__IJ(JNIEnv* env, jclass clazz, jint mode, jlong indirect)
{
    glDrawArraysIndirect(
        (GLenum)mode,
        (GLvoid*)long2Ptr(indirect));
}

// void glDrawElementsIndirect(GLenum mode, GLenum type, GLvoid* indirect);
// public static native void glDrawElementsIndirect(int mode, int type, Buffer indirect);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsIndirect__IILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint mode, jint type, jobject indirect)
{
    glDrawElementsIndirect(
        (GLenum)mode,
        (GLenum)type,
        (GLvoid*)(indirect ? (*env)->GetDirectBufferAddress(env, indirect) : 0));
}

// void glDrawElementsIndirect(GLenum mode, GLenum type, GLvoid* indirect);
// public static native void glDrawElementsIndirect(int mode, int type, long indirect);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawElementsIndirect__IIJ(JNIEnv* env, jclass clazz, jint mode, jint type, jlong indirect)
{
    glDrawElementsIndirect(
        (GLenum)mode,
        (GLenum)type,
        (GLvoid*)long2Ptr(indirect));
}

// void glDrawTransformFeedback(GLenum mode, GLuint id);
// public static native void glDrawTransformFeedback(int mode, int id);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawTransformFeedback(JNIEnv* env, jclass clazz, jint mode, jint id)
{
    glDrawTransformFeedback(
        (GLenum)mode,
        (GLuint)id);
}

// void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
// public static native void glDrawTransformFeedbackStream(int mode, int id, int stream);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDrawTransformFeedbackStream(JNIEnv* env, jclass clazz, jint mode, jint id, jint stream)
{
    glDrawTransformFeedbackStream(
        (GLenum)mode,
        (GLuint)id,
        (GLuint)stream);
}

// void glEndQueryIndexed(GLenum target, GLuint index);
// public static native void glEndQueryIndexed(int target, int index);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glEndQueryIndexed(JNIEnv* env, jclass clazz, jint target, jint index)
{
    glEndQueryIndexed(
        (GLenum)target,
        (GLuint)index);
}

// void glGenTransformFeedbacks(GLsizei n, GLuint* ids);
// public static native void glGenTransformFeedbacks(int n, IntBuffer ids);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenTransformFeedbacks__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject ids)
{
    glGenTransformFeedbacks(
        (GLsizei)n,
        (GLuint*)(ids ? (*env)->GetDirectBufferAddress(env, ids) : 0));
}

// void glGenTransformFeedbacks(GLsizei n, GLuint* ids);
// public static native void glGenTransformFeedbacks(int n, int[] ids, int idsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenTransformFeedbacks__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray ids, jint idsOffset)
{
    jint* j_ids = ids ? (jint*)((*env)->GetPrimitiveArrayCritical(env, ids, 0)) : 0;
    glGenTransformFeedbacks(
        (GLsizei)n,
        (GLuint*)(j_ids + idsOffset));
    if(ids) (*env)->ReleasePrimitiveArrayCritical(env, ids, j_ids, 0);
}

// void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
// public static native void glGetActiveSubroutineName(int program, int shadertype, int index, int bufsize, IntBuffer length, ByteBuffer name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveSubroutineName__IIIILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint index, jint bufsize, jobject length, jobject name)
{
    glGetActiveSubroutineName(
        (GLuint)program,
        (GLenum)shadertype,
        (GLuint)index,
        (GLsizei)bufsize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(name ? (*env)->GetDirectBufferAddress(env, name) : 0));
}

// void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
// public static native void glGetActiveSubroutineName(int program, int shadertype, int index, int bufsize, int[] length, int lengthOffset, byte[] name, int nameOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveSubroutineName__IIII_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint index, jint bufsize, jintArray length, jint lengthOffset, jbyteArray name, jint nameOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_name = name ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, name, 0)) : 0;
    glGetActiveSubroutineName(
        (GLuint)program,
        (GLenum)shadertype,
        (GLuint)index,
        (GLsizei)bufsize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_name + nameOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(name) (*env)->ReleasePrimitiveArrayCritical(env, name, j_name, 0);
}

// void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
// public static native void glGetActiveSubroutineUniformName(int program, int shadertype, int index, int bufsize, IntBuffer length, ByteBuffer name);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveSubroutineUniformName__IIIILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint index, jint bufsize, jobject length, jobject name)
{
    glGetActiveSubroutineUniformName(
        (GLuint)program,
        (GLenum)shadertype,
        (GLuint)index,
        (GLsizei)bufsize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(name ? (*env)->GetDirectBufferAddress(env, name) : 0));
}

// void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
// public static native void glGetActiveSubroutineUniformName(int program, int shadertype, int index, int bufsize, int[] length, int lengthOffset, byte[] name, int nameOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveSubroutineUniformName__IIII_3II_3BI(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint index, jint bufsize, jintArray length, jint lengthOffset, jbyteArray name, jint nameOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_name = name ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, name, 0)) : 0;
    glGetActiveSubroutineUniformName(
        (GLuint)program,
        (GLenum)shadertype,
        (GLuint)index,
        (GLsizei)bufsize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_name + nameOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(name) (*env)->ReleasePrimitiveArrayCritical(env, name, j_name, 0);
}

// void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
// public static native void glGetActiveSubroutineUniformiv(int program, int shadertype, int index, int pname, IntBuffer values);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveSubroutineUniformiv__IIIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint index, jint pname, jobject values)
{
    glGetActiveSubroutineUniformiv(
        (GLuint)program,
        (GLenum)shadertype,
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(values ? (*env)->GetDirectBufferAddress(env, values) : 0));
}

// void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
// public static native void glGetActiveSubroutineUniformiv(int program, int shadertype, int index, int pname, int[] values, int valuesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetActiveSubroutineUniformiv__IIII_3II(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint index, jint pname, jintArray values, jint valuesOffset)
{
    jint* j_values = values ? (jint*)((*env)->GetPrimitiveArrayCritical(env, values, 0)) : 0;
    glGetActiveSubroutineUniformiv(
        (GLuint)program,
        (GLenum)shadertype,
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(j_values + valuesOffset));
    if(values) (*env)->ReleasePrimitiveArrayCritical(env, values, j_values, 0);
}

// void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
// public static native void glGetProgramStageiv(int program, int shadertype, int pname, IntBuffer values);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramStageiv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint pname, jobject values)
{
    glGetProgramStageiv(
        (GLuint)program,
        (GLenum)shadertype,
        (GLenum)pname,
        (GLint*)(values ? (*env)->GetDirectBufferAddress(env, values) : 0));
}

// void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
// public static native void glGetProgramStageiv(int program, int shadertype, int pname, int[] values, int valuesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramStageiv__III_3II(JNIEnv* env, jclass clazz, jint program, jint shadertype, jint pname, jintArray values, jint valuesOffset)
{
    jint* j_values = values ? (jint*)((*env)->GetPrimitiveArrayCritical(env, values, 0)) : 0;
    glGetProgramStageiv(
        (GLuint)program,
        (GLenum)shadertype,
        (GLenum)pname,
        (GLint*)(j_values + valuesOffset));
    if(values) (*env)->ReleasePrimitiveArrayCritical(env, values, j_values, 0);
}

// void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params);
// public static native void glGetQueryIndexediv(int target, int index, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryIndexediv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint target, jint index, jint pname, jobject params)
{
    glGetQueryIndexediv(
        (GLenum)target,
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params);
// public static native void glGetQueryIndexediv(int target, int index, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetQueryIndexediv__III_3II(JNIEnv* env, jclass clazz, jint target, jint index, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetQueryIndexediv(
        (GLenum)target,
        (GLuint)index,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar* name);
// public static native int glGetSubroutineIndex(int program, int shadertype, String name);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSubroutineIndex(JNIEnv* env, jclass clazz, jint program, jint shadertype, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    GLuint ret = (GLuint)
        glGetSubroutineIndex(
        (GLuint)program,
        (GLenum)shadertype,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
    return (jint)ret;
}

// GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar* name);
// public static native int glGetSubroutineUniformLocation(int program, int shadertype, String name);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetSubroutineUniformLocation(JNIEnv* env, jclass clazz, jint program, jint shadertype, jstring name)
{
    const char* j_name = (*env)->GetStringUTFChars(env, name, 0);
    GLint ret = (GLint)
        glGetSubroutineUniformLocation(
        (GLuint)program,
        (GLenum)shadertype,
        (GLchar*)j_name);
    (*env)->ReleaseStringUTFChars(env, name, j_name);
    return (jint)ret;
}

// void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params);
// public static native void glGetUniformSubroutineuiv(int shadertype, int location, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformSubroutineuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint shadertype, jint location, jobject params)
{
    glGetUniformSubroutineuiv(
        (GLenum)shadertype,
        (GLint)location,
        (GLuint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params);
// public static native void glGetUniformSubroutineuiv(int shadertype, int location, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformSubroutineuiv__II_3II(JNIEnv* env, jclass clazz, jint shadertype, jint location, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetUniformSubroutineuiv(
        (GLenum)shadertype,
        (GLint)location,
        (GLuint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetUniformdv(GLuint program, GLint location, GLdouble* params);
// public static native void glGetUniformdv(int program, int location, DoubleBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformdv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jobject params)
{
    glGetUniformdv(
        (GLuint)program,
        (GLint)location,
        (GLdouble*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetUniformdv(GLuint program, GLint location, GLdouble* params);
// public static native void glGetUniformdv(int program, int location, double[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetUniformdv__II_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jdoubleArray params, jint paramsOffset)
{
    jdouble* j_params = params ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetUniformdv(
        (GLuint)program,
        (GLint)location,
        (GLdouble*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLboolean glIsTransformFeedback(GLuint id);
// public static native boolean glIsTransformFeedback(int id);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsTransformFeedback(JNIEnv* env, jclass clazz, jint id)
{
    GLboolean ret = (GLboolean)
        glIsTransformFeedback(
        (GLuint)id);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glMinSampleShading(GLclampf value);
// public static native void glMinSampleShading(float value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glMinSampleShading(JNIEnv* env, jclass clazz, jfloat value)
{
    glMinSampleShading(
        (GLclampf)value);
}

// void glPatchParameterfv(GLenum pname, GLfloat* values);
// public static native void glPatchParameterfv(int pname, FloatBuffer values);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPatchParameterfv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint pname, jobject values)
{
    glPatchParameterfv(
        (GLenum)pname,
        (GLfloat*)(values ? (*env)->GetDirectBufferAddress(env, values) : 0));
}

// void glPatchParameterfv(GLenum pname, GLfloat* values);
// public static native void glPatchParameterfv(int pname, float[] values, int valuesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPatchParameterfv__I_3FI(JNIEnv* env, jclass clazz, jint pname, jfloatArray values, jint valuesOffset)
{
    jfloat* j_values = values ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, values, 0)) : 0;
    glPatchParameterfv(
        (GLenum)pname,
        (GLfloat*)(j_values + valuesOffset));
    if(values) (*env)->ReleasePrimitiveArrayCritical(env, values, j_values, 0);
}

// void glPatchParameteri(GLenum pname, GLint value);
// public static native void glPatchParameteri(int pname, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPatchParameteri(JNIEnv* env, jclass clazz, jint pname, jint value)
{
    glPatchParameteri(
        (GLenum)pname,
        (GLint)value);
}

// void glPauseTransformFeedback();
// public static native void glPauseTransformFeedback();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glPauseTransformFeedback(JNIEnv* env, jclass clazz)
{
    glPauseTransformFeedback();
}

// void glResumeTransformFeedback();
// public static native void glResumeTransformFeedback();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glResumeTransformFeedback(JNIEnv* env, jclass clazz)
{
    glResumeTransformFeedback();
}

// void glUniform1d(GLint location, GLdouble x);
// public static native void glUniform1d(int location, double x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1d(JNIEnv* env, jclass clazz, jint location, jdouble x)
{
    glUniform1d(
        (GLint)location,
        (GLdouble)x);
}

// void glUniform1dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform1dv(int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1dv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform1dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform1dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform1dv(int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform1dv__II_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform1dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform2d(GLint location, GLdouble x, GLdouble y);
// public static native void glUniform2d(int location, double x, double y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2d(JNIEnv* env, jclass clazz, jint location, jdouble x, jdouble y)
{
    glUniform2d(
        (GLint)location,
        (GLdouble)x,
        (GLdouble)y);
}

// void glUniform2dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform2dv(int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2dv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform2dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform2dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform2dv(int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform2dv__II_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform2dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
// public static native void glUniform3d(int location, double x, double y, double z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3d(JNIEnv* env, jclass clazz, jint location, jdouble x, jdouble y, jdouble z)
{
    glUniform3d(
        (GLint)location,
        (GLdouble)x,
        (GLdouble)y,
        (GLdouble)z);
}

// void glUniform3dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform3dv(int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3dv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform3dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform3dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform3dv(int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform3dv__II_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform3dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
// public static native void glUniform4d(int location, double x, double y, double z, double w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4d(JNIEnv* env, jclass clazz, jint location, jdouble x, jdouble y, jdouble z, jdouble w)
{
    glUniform4d(
        (GLint)location,
        (GLdouble)x,
        (GLdouble)y,
        (GLdouble)z,
        (GLdouble)w);
}

// void glUniform4dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform4dv(int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4dv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jobject value)
{
    glUniform4dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniform4dv(GLint location, GLsizei count, GLdouble* value);
// public static native void glUniform4dv(int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniform4dv__II_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniform4dv(
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix2dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix2dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix2dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix2dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix2x3dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x3dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix2x3dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix2x3dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x3dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix2x3dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix2x4dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x4dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix2x4dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix2x4dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix2x4dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix2x4dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix3dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix3dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix3dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix3dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix3x2dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x2dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix3x2dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix3x2dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x2dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix3x2dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix3x4dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x4dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix3x4dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix3x4dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix3x4dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix3x4dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix4dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix4dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix4dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix4dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix4x2dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x2dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix4x2dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix4x2dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x2dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix4x2dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix4x3dv(int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x3dv__IIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jobject value)
{
    glUniformMatrix4x3dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glUniformMatrix4x3dv(int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformMatrix4x3dv__IIZ_3DI(JNIEnv* env, jclass clazz, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glUniformMatrix4x3dv(
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint* indices);
// public static native void glUniformSubroutinesuiv(int shadertype, int count, IntBuffer indices);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformSubroutinesuiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint shadertype, jint count, jobject indices)
{
    glUniformSubroutinesuiv(
        (GLenum)shadertype,
        (GLsizei)count,
        (GLuint*)(indices ? (*env)->GetDirectBufferAddress(env, indices) : 0));
}

// void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint* indices);
// public static native void glUniformSubroutinesuiv(int shadertype, int count, int[] indices, int indicesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUniformSubroutinesuiv__II_3II(JNIEnv* env, jclass clazz, jint shadertype, jint count, jintArray indices, jint indicesOffset)
{
    jint* j_indices = indices ? (jint*)((*env)->GetPrimitiveArrayCritical(env, indices, 0)) : 0;
    glUniformSubroutinesuiv(
        (GLenum)shadertype,
        (GLsizei)count,
        (GLuint*)(j_indices + indicesOffset));
    if(indices) (*env)->ReleasePrimitiveArrayCritical(env, indices, j_indices, 0);
}

// void glActiveShaderProgram(GLuint pipeline, GLuint program);
// public static native void glActiveShaderProgram(int pipeline, int program);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glActiveShaderProgram(JNIEnv* env, jclass clazz, jint pipeline, jint program)
{
    glActiveShaderProgram(
        (GLuint)pipeline,
        (GLuint)program);
}

// void glBindProgramPipeline(GLuint pipeline);
// public static native void glBindProgramPipeline(int pipeline);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glBindProgramPipeline(JNIEnv* env, jclass clazz, jint pipeline)
{
    glBindProgramPipeline(
        (GLuint)pipeline);
}

// void glClearDepthf(GLclampf d);
// public static native void glClearDepthf(float d);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glClearDepthf(JNIEnv* env, jclass clazz, jfloat d)
{
    glClearDepthf(
        (GLclampf)d);
}

// GLuint glCreateShaderProgramv(GLenum type, GLsizei count, GLchar** strings);
// public static native int glCreateShaderProgramv(int type, int count, String[] strings);
JNIEXPORT jint JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glCreateShaderProgramv(JNIEnv* env, jclass clazz, jint type, jint count, jobjectArray strings)
{
    const char** j_strings = newNativeStringArray(env, strings);
    GLuint ret = (GLuint)
        glCreateShaderProgramv(
        (GLenum)type,
        (GLsizei)count,
        (const GLchar**)j_strings);
    freeNativeStringArray(j_strings);
    return (jint)ret;
}

// void glDeleteProgramPipelines(GLsizei n, GLuint* pipelines);
// public static native void glDeleteProgramPipelines(int n, IntBuffer pipelines);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteProgramPipelines__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject pipelines)
{
    glDeleteProgramPipelines(
        (GLsizei)n,
        (GLuint*)(pipelines ? (*env)->GetDirectBufferAddress(env, pipelines) : 0));
}

// void glDeleteProgramPipelines(GLsizei n, GLuint* pipelines);
// public static native void glDeleteProgramPipelines(int n, int[] pipelines, int pipelinesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDeleteProgramPipelines__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray pipelines, jint pipelinesOffset)
{
    jint* j_pipelines = pipelines ? (jint*)((*env)->GetPrimitiveArrayCritical(env, pipelines, 0)) : 0;
    glDeleteProgramPipelines(
        (GLsizei)n,
        (GLuint*)(j_pipelines + pipelinesOffset));
    if(pipelines) (*env)->ReleasePrimitiveArrayCritical(env, pipelines, j_pipelines, 0);
}

// void glDepthRangeArrayv(GLuint first, GLsizei count, GLclampd* v);
// public static native void glDepthRangeArrayv(int first, int count, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthRangeArrayv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint first, jint count, jobject v)
{
    glDepthRangeArrayv(
        (GLuint)first,
        (GLsizei)count,
        (GLclampd*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glDepthRangeArrayv(GLuint first, GLsizei count, GLclampd* v);
// public static native void glDepthRangeArrayv(int first, int count, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthRangeArrayv__II_3DI(JNIEnv* env, jclass clazz, jint first, jint count, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glDepthRangeArrayv(
        (GLuint)first,
        (GLsizei)count,
        (GLclampd*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f);
// public static native void glDepthRangeIndexed(int index, double n, double f);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthRangeIndexed(JNIEnv* env, jclass clazz, jint index, jdouble n, jdouble f)
{
    glDepthRangeIndexed(
        (GLuint)index,
        (GLclampd)n,
        (GLclampd)f);
}

// void glDepthRangef(GLclampf n, GLclampf f);
// public static native void glDepthRangef(float n, float f);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glDepthRangef(JNIEnv* env, jclass clazz, jfloat n, jfloat f)
{
    glDepthRangef(
        (GLclampf)n,
        (GLclampf)f);
}

// void glGenProgramPipelines(GLsizei n, GLuint* pipelines);
// public static native void glGenProgramPipelines(int n, IntBuffer pipelines);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenProgramPipelines__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint n, jobject pipelines)
{
    glGenProgramPipelines(
        (GLsizei)n,
        (GLuint*)(pipelines ? (*env)->GetDirectBufferAddress(env, pipelines) : 0));
}

// void glGenProgramPipelines(GLsizei n, GLuint* pipelines);
// public static native void glGenProgramPipelines(int n, int[] pipelines, int pipelinesOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGenProgramPipelines__I_3II(JNIEnv* env, jclass clazz, jint n, jintArray pipelines, jint pipelinesOffset)
{
    jint* j_pipelines = pipelines ? (jint*)((*env)->GetPrimitiveArrayCritical(env, pipelines, 0)) : 0;
    glGenProgramPipelines(
        (GLsizei)n,
        (GLuint*)(j_pipelines + pipelinesOffset));
    if(pipelines) (*env)->ReleasePrimitiveArrayCritical(env, pipelines, j_pipelines, 0);
}

// void glGetDoublei_v(GLenum target, GLuint index, GLdouble* data);
// public static native void glGetDoublei_v(int target, int index, DoubleBuffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetDoublei_1v__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint target, jint index, jobject data)
{
    glGetDoublei_v(
        (GLenum)target,
        (GLuint)index,
        (GLdouble*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glGetDoublei_v(GLenum target, GLuint index, GLdouble* data);
// public static native void glGetDoublei_v(int target, int index, double[] data, int dataOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetDoublei_1v__II_3DI(JNIEnv* env, jclass clazz, jint target, jint index, jdoubleArray data, jint dataOffset)
{
    jdouble* j_data = data ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, data, 0)) : 0;
    glGetDoublei_v(
        (GLenum)target,
        (GLuint)index,
        (GLdouble*)(j_data + dataOffset));
    if(data) (*env)->ReleasePrimitiveArrayCritical(env, data, j_data, 0);
}

// void glGetFloati_v(GLenum target, GLuint index, GLfloat* data);
// public static native void glGetFloati_v(int target, int index, FloatBuffer data);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFloati_1v__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint target, jint index, jobject data)
{
    glGetFloati_v(
        (GLenum)target,
        (GLuint)index,
        (GLfloat*)(data ? (*env)->GetDirectBufferAddress(env, data) : 0));
}

// void glGetFloati_v(GLenum target, GLuint index, GLfloat* data);
// public static native void glGetFloati_v(int target, int index, float[] data, int dataOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetFloati_1v__II_3FI(JNIEnv* env, jclass clazz, jint target, jint index, jfloatArray data, jint dataOffset)
{
    jfloat* j_data = data ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, data, 0)) : 0;
    glGetFloati_v(
        (GLenum)target,
        (GLuint)index,
        (GLfloat*)(j_data + dataOffset));
    if(data) (*env)->ReleasePrimitiveArrayCritical(env, data, j_data, 0);
}

// void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
// public static native void glGetProgramBinary(int program, int bufSize, IntBuffer length, IntBuffer binaryFormat, Buffer binary);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramBinary__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint program, jint bufSize, jobject length, jobject binaryFormat, jobject binary)
{
    glGetProgramBinary(
        (GLuint)program,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLenum*)(binaryFormat ? (*env)->GetDirectBufferAddress(env, binaryFormat) : 0),
        (GLvoid*)(binary ? (*env)->GetDirectBufferAddress(env, binary) : 0));
}

// void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
// public static native void glGetProgramBinary(int program, int bufSize, int[] length, int lengthOffset, int[] binaryFormat, int binaryFormatOffset, long binary);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramBinary__II_3II_3IIJ(JNIEnv* env, jclass clazz, jint program, jint bufSize, jintArray length, jint lengthOffset, jintArray binaryFormat, jint binaryFormatOffset, jlong binary)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jint* j_binaryFormat = binaryFormat ? (jint*)((*env)->GetPrimitiveArrayCritical(env, binaryFormat, 0)) : 0;
    glGetProgramBinary(
        (GLuint)program,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLenum*)(j_binaryFormat + binaryFormatOffset),
        (GLvoid*)long2Ptr(binary));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(binaryFormat) (*env)->ReleasePrimitiveArrayCritical(env, binaryFormat, j_binaryFormat, 0);
}

// void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
// public static native void glGetProgramPipelineInfoLog(int pipeline, int bufSize, IntBuffer length, ByteBuffer infoLog);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramPipelineInfoLog__IILjava_nio_IntBuffer_2Ljava_nio_ByteBuffer_2(JNIEnv* env, jclass clazz, jint pipeline, jint bufSize, jobject length, jobject infoLog)
{
    glGetProgramPipelineInfoLog(
        (GLuint)pipeline,
        (GLsizei)bufSize,
        (GLsizei*)(length ? (*env)->GetDirectBufferAddress(env, length) : 0),
        (GLchar*)(infoLog ? (*env)->GetDirectBufferAddress(env, infoLog) : 0));
}

// void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
// public static native void glGetProgramPipelineInfoLog(int pipeline, int bufSize, int[] length, int lengthOffset, byte[] infoLog, int infoLogOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramPipelineInfoLog__II_3II_3BI(JNIEnv* env, jclass clazz, jint pipeline, jint bufSize, jintArray length, jint lengthOffset, jbyteArray infoLog, jint infoLogOffset)
{
    jint* j_length = length ? (jint*)((*env)->GetPrimitiveArrayCritical(env, length, 0)) : 0;
    jbyte* j_infoLog = infoLog ? (jbyte*)((*env)->GetPrimitiveArrayCritical(env, infoLog, 0)) : 0;
    glGetProgramPipelineInfoLog(
        (GLuint)pipeline,
        (GLsizei)bufSize,
        (GLsizei*)(j_length + lengthOffset),
        (GLchar*)(j_infoLog + infoLogOffset));
    if(length) (*env)->ReleasePrimitiveArrayCritical(env, length, j_length, 0);
    if(infoLog) (*env)->ReleasePrimitiveArrayCritical(env, infoLog, j_infoLog, 0);
}

// void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params);
// public static native void glGetProgramPipelineiv(int pipeline, int pname, IntBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramPipelineiv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint pipeline, jint pname, jobject params)
{
    glGetProgramPipelineiv(
        (GLuint)pipeline,
        (GLenum)pname,
        (GLint*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params);
// public static native void glGetProgramPipelineiv(int pipeline, int pname, int[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetProgramPipelineiv__II_3II(JNIEnv* env, jclass clazz, jint pipeline, jint pname, jintArray params, jint paramsOffset)
{
    jint* j_params = params ? (jint*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetProgramPipelineiv(
        (GLuint)pipeline,
        (GLenum)pname,
        (GLint*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
// public static native void glGetShaderPrecisionFormat(int shadertype, int precisiontype, IntBuffer range, IntBuffer precision);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderPrecisionFormat__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint shadertype, jint precisiontype, jobject range, jobject precision)
{
    glGetShaderPrecisionFormat(
        (GLenum)shadertype,
        (GLenum)precisiontype,
        (GLint*)(range ? (*env)->GetDirectBufferAddress(env, range) : 0),
        (GLint*)(precision ? (*env)->GetDirectBufferAddress(env, precision) : 0));
}

// void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
// public static native void glGetShaderPrecisionFormat(int shadertype, int precisiontype, int[] range, int rangeOffset, int[] precision, int precisionOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetShaderPrecisionFormat__II_3II_3II(JNIEnv* env, jclass clazz, jint shadertype, jint precisiontype, jintArray range, jint rangeOffset, jintArray precision, jint precisionOffset)
{
    jint* j_range = range ? (jint*)((*env)->GetPrimitiveArrayCritical(env, range, 0)) : 0;
    jint* j_precision = precision ? (jint*)((*env)->GetPrimitiveArrayCritical(env, precision, 0)) : 0;
    glGetShaderPrecisionFormat(
        (GLenum)shadertype,
        (GLenum)precisiontype,
        (GLint*)(j_range + rangeOffset),
        (GLint*)(j_precision + precisionOffset));
    if(range) (*env)->ReleasePrimitiveArrayCritical(env, range, j_range, 0);
    if(precision) (*env)->ReleasePrimitiveArrayCritical(env, precision, j_precision, 0);
}

// void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params);
// public static native void glGetVertexAttribLdv(int index, int pname, DoubleBuffer params);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribLdv__IILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jint pname, jobject params)
{
    glGetVertexAttribLdv(
        (GLuint)index,
        (GLenum)pname,
        (GLdouble*)(params ? (*env)->GetDirectBufferAddress(env, params) : 0));
}

// void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params);
// public static native void glGetVertexAttribLdv(int index, int pname, double[] params, int paramsOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glGetVertexAttribLdv__II_3DI(JNIEnv* env, jclass clazz, jint index, jint pname, jdoubleArray params, jint paramsOffset)
{
    jdouble* j_params = params ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, params, 0)) : 0;
    glGetVertexAttribLdv(
        (GLuint)index,
        (GLenum)pname,
        (GLdouble*)(j_params + paramsOffset));
    if(params) (*env)->ReleasePrimitiveArrayCritical(env, params, j_params, 0);
}

// GLboolean glIsProgramPipeline(GLuint pipeline);
// public static native boolean glIsProgramPipeline(int pipeline);
JNIEXPORT jboolean JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glIsProgramPipeline(JNIEnv* env, jclass clazz, jint pipeline)
{
    GLboolean ret = (GLboolean)
        glIsProgramPipeline(
        (GLuint)pipeline);
    return ret == GL_TRUE ? JNI_TRUE : JNI_FALSE;
}

// void glProgramBinary(GLuint program, GLenum binaryFormat, GLvoid* binary, GLsizei length);
// public static native void glProgramBinary(int program, int binaryFormat, Buffer binary, int length);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramBinary__IILjava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint program, jint binaryFormat, jobject binary, jint length)
{
    glProgramBinary(
        (GLuint)program,
        (GLenum)binaryFormat,
        (GLvoid*)(binary ? (*env)->GetDirectBufferAddress(env, binary) : 0),
        (GLsizei)length);
}

// void glProgramBinary(GLuint program, GLenum binaryFormat, GLvoid* binary, GLsizei length);
// public static native void glProgramBinary(int program, int binaryFormat, long binary, int length);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramBinary__IIJI(JNIEnv* env, jclass clazz, jint program, jint binaryFormat, jlong binary, jint length)
{
    glProgramBinary(
        (GLuint)program,
        (GLenum)binaryFormat,
        (GLvoid*)long2Ptr(binary),
        (GLsizei)length);
}

// void glProgramParameteri(GLuint program, GLenum pname, GLint value);
// public static native void glProgramParameteri(int program, int pname, int value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramParameteri(JNIEnv* env, jclass clazz, jint program, jint pname, jint value)
{
    glProgramParameteri(
        (GLuint)program,
        (GLenum)pname,
        (GLint)value);
}

// void glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
// public static native void glProgramUniform1d(int program, int location, double v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1d(JNIEnv* env, jclass clazz, jint program, jint location, jdouble v0)
{
    glProgramUniform1d(
        (GLuint)program,
        (GLint)location,
        (GLdouble)v0);
}

// void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform1dv(int program, int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1dv__IIILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform1dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform1dv(int program, int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1dv__III_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform1dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
// public static native void glProgramUniform1f(int program, int location, float v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1f(JNIEnv* env, jclass clazz, jint program, jint location, jfloat v0)
{
    glProgramUniform1f(
        (GLuint)program,
        (GLint)location,
        (GLfloat)v0);
}

// void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform1fv(int program, int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1fv__IIILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform1fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform1fv(int program, int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1fv__III_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform1fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform1i(GLuint program, GLint location, GLint v0);
// public static native void glProgramUniform1i(int program, int location, int v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1i(JNIEnv* env, jclass clazz, jint program, jint location, jint v0)
{
    glProgramUniform1i(
        (GLuint)program,
        (GLint)location,
        (GLint)v0);
}

// void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform1iv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1iv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform1iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform1iv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1iv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform1iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
// public static native void glProgramUniform1ui(int program, int location, int v0);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1ui(JNIEnv* env, jclass clazz, jint program, jint location, jint v0)
{
    glProgramUniform1ui(
        (GLuint)program,
        (GLint)location,
        (GLuint)v0);
}

// void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform1uiv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1uiv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform1uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform1uiv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform1uiv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform1uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
// public static native void glProgramUniform2d(int program, int location, double v0, double v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2d(JNIEnv* env, jclass clazz, jint program, jint location, jdouble v0, jdouble v1)
{
    glProgramUniform2d(
        (GLuint)program,
        (GLint)location,
        (GLdouble)v0,
        (GLdouble)v1);
}

// void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform2dv(int program, int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2dv__IIILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform2dv(int program, int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2dv__III_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
// public static native void glProgramUniform2f(int program, int location, float v0, float v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2f(JNIEnv* env, jclass clazz, jint program, jint location, jfloat v0, jfloat v1)
{
    glProgramUniform2f(
        (GLuint)program,
        (GLint)location,
        (GLfloat)v0,
        (GLfloat)v1);
}

// void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform2fv(int program, int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2fv__IIILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform2fv(int program, int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2fv__III_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
// public static native void glProgramUniform2i(int program, int location, int v0, int v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2i(JNIEnv* env, jclass clazz, jint program, jint location, jint v0, jint v1)
{
    glProgramUniform2i(
        (GLuint)program,
        (GLint)location,
        (GLint)v0,
        (GLint)v1);
}

// void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform2iv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2iv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform2iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform2iv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2iv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform2iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
// public static native void glProgramUniform2ui(int program, int location, int v0, int v1);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2ui(JNIEnv* env, jclass clazz, jint program, jint location, jint v0, jint v1)
{
    glProgramUniform2ui(
        (GLuint)program,
        (GLint)location,
        (GLuint)v0,
        (GLuint)v1);
}

// void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform2uiv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2uiv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform2uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform2uiv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform2uiv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform2uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
// public static native void glProgramUniform3d(int program, int location, double v0, double v1, double v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3d(JNIEnv* env, jclass clazz, jint program, jint location, jdouble v0, jdouble v1, jdouble v2)
{
    glProgramUniform3d(
        (GLuint)program,
        (GLint)location,
        (GLdouble)v0,
        (GLdouble)v1,
        (GLdouble)v2);
}

// void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform3dv(int program, int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3dv__IIILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform3dv(int program, int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3dv__III_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
// public static native void glProgramUniform3f(int program, int location, float v0, float v1, float v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3f(JNIEnv* env, jclass clazz, jint program, jint location, jfloat v0, jfloat v1, jfloat v2)
{
    glProgramUniform3f(
        (GLuint)program,
        (GLint)location,
        (GLfloat)v0,
        (GLfloat)v1,
        (GLfloat)v2);
}

// void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform3fv(int program, int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3fv__IIILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform3fv(int program, int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3fv__III_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
// public static native void glProgramUniform3i(int program, int location, int v0, int v1, int v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3i(JNIEnv* env, jclass clazz, jint program, jint location, jint v0, jint v1, jint v2)
{
    glProgramUniform3i(
        (GLuint)program,
        (GLint)location,
        (GLint)v0,
        (GLint)v1,
        (GLint)v2);
}

// void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform3iv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3iv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform3iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform3iv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3iv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform3iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
// public static native void glProgramUniform3ui(int program, int location, int v0, int v1, int v2);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3ui(JNIEnv* env, jclass clazz, jint program, jint location, jint v0, jint v1, jint v2)
{
    glProgramUniform3ui(
        (GLuint)program,
        (GLint)location,
        (GLuint)v0,
        (GLuint)v1,
        (GLuint)v2);
}

// void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform3uiv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3uiv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform3uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform3uiv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform3uiv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform3uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
// public static native void glProgramUniform4d(int program, int location, double v0, double v1, double v2, double v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4d(JNIEnv* env, jclass clazz, jint program, jint location, jdouble v0, jdouble v1, jdouble v2, jdouble v3)
{
    glProgramUniform4d(
        (GLuint)program,
        (GLint)location,
        (GLdouble)v0,
        (GLdouble)v1,
        (GLdouble)v2,
        (GLdouble)v3);
}

// void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform4dv(int program, int location, int count, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4dv__IIILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
// public static native void glProgramUniform4dv(int program, int location, int count, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4dv__III_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
// public static native void glProgramUniform4f(int program, int location, float v0, float v1, float v2, float v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4f(JNIEnv* env, jclass clazz, jint program, jint location, jfloat v0, jfloat v1, jfloat v2, jfloat v3)
{
    glProgramUniform4f(
        (GLuint)program,
        (GLint)location,
        (GLfloat)v0,
        (GLfloat)v1,
        (GLfloat)v2,
        (GLfloat)v3);
}

// void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform4fv(int program, int location, int count, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4fv__IIILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
// public static native void glProgramUniform4fv(int program, int location, int count, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4fv__III_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
// public static native void glProgramUniform4i(int program, int location, int v0, int v1, int v2, int v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4i(JNIEnv* env, jclass clazz, jint program, jint location, jint v0, jint v1, jint v2, jint v3)
{
    glProgramUniform4i(
        (GLuint)program,
        (GLint)location,
        (GLint)v0,
        (GLint)v1,
        (GLint)v2,
        (GLint)v3);
}

// void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform4iv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4iv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform4iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint* value);
// public static native void glProgramUniform4iv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4iv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform4iv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
// public static native void glProgramUniform4ui(int program, int location, int v0, int v1, int v2, int v3);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4ui(JNIEnv* env, jclass clazz, jint program, jint location, jint v0, jint v1, jint v2, jint v3)
{
    glProgramUniform4ui(
        (GLuint)program,
        (GLint)location,
        (GLuint)v0,
        (GLuint)v1,
        (GLuint)v2,
        (GLuint)v3);
}

// void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform4uiv(int program, int location, int count, IntBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4uiv__IIILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jobject value)
{
    glProgramUniform4uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
// public static native void glProgramUniform4uiv(int program, int location, int count, int[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniform4uiv__III_3II(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jintArray value, jint valueOffset)
{
    jint* j_value = value ? (jint*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniform4uiv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLuint*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix2dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix2dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix2fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix2fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix2x3dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x3dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix2x3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix2x3dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x3dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix2x3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix2x3fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x3fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix2x3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix2x3fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x3fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix2x3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix2x4dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x4dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix2x4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix2x4dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x4dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix2x4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix2x4fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x4fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix2x4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix2x4fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix2x4fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix2x4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix3dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix3dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix3fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix3fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix3x2dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x2dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix3x2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix3x2dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x2dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix3x2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix3x2fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x2fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix3x2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix3x2fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x2fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix3x2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix3x4dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x4dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix3x4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix3x4dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x4dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix3x4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix3x4fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x4fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix3x4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix3x4fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix3x4fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix3x4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix4dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix4dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix4dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix4fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix4fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix4fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix4x2dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x2dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix4x2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix4x2dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x2dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix4x2dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix4x2fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x2fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix4x2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix4x2fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x2fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix4x2fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix4x3dv(int program, int location, int count, boolean transpose, DoubleBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x3dv__IIIZLjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix4x3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
// public static native void glProgramUniformMatrix4x3dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x3dv__IIIZ_3DI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jdoubleArray value, jint valueOffset)
{
    jdouble* j_value = value ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix4x3dv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLdouble*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix4x3fv(int program, int location, int count, boolean transpose, FloatBuffer value);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x3fv__IIIZLjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jobject value)
{
    glProgramUniformMatrix4x3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(value ? (*env)->GetDirectBufferAddress(env, value) : 0));
}

// void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
// public static native void glProgramUniformMatrix4x3fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glProgramUniformMatrix4x3fv__IIIZ_3FI(JNIEnv* env, jclass clazz, jint program, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
{
    jfloat* j_value = value ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, value, 0)) : 0;
    glProgramUniformMatrix4x3fv(
        (GLuint)program,
        (GLint)location,
        (GLsizei)count,
        (GLboolean)(transpose == JNI_TRUE ? GL_TRUE : GL_FALSE),
        (GLfloat*)(j_value + valueOffset));
    if(value) (*env)->ReleasePrimitiveArrayCritical(env, value, j_value, 0);
}

// void glReleaseShaderCompiler();
// public static native void glReleaseShaderCompiler();
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glReleaseShaderCompiler(JNIEnv* env, jclass clazz)
{
    glReleaseShaderCompiler();
}

// void glScissorArrayv(GLuint first, GLsizei count, GLint* v);
// public static native void glScissorArrayv(int first, int count, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glScissorArrayv__IILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint first, jint count, jobject v)
{
    glScissorArrayv(
        (GLuint)first,
        (GLsizei)count,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glScissorArrayv(GLuint first, GLsizei count, GLint* v);
// public static native void glScissorArrayv(int first, int count, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glScissorArrayv__II_3II(JNIEnv* env, jclass clazz, jint first, jint count, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glScissorArrayv(
        (GLuint)first,
        (GLsizei)count,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
// public static native void glScissorIndexed(int index, int left, int bottom, int width, int height);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glScissorIndexed(JNIEnv* env, jclass clazz, jint index, jint left, jint bottom, jint width, jint height)
{
    glScissorIndexed(
        (GLuint)index,
        (GLint)left,
        (GLint)bottom,
        (GLsizei)width,
        (GLsizei)height);
}

// void glScissorIndexedv(GLuint index, GLint* v);
// public static native void glScissorIndexedv(int index, IntBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glScissorIndexedv__ILjava_nio_IntBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glScissorIndexedv(
        (GLuint)index,
        (GLint*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glScissorIndexedv(GLuint index, GLint* v);
// public static native void glScissorIndexedv(int index, int[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glScissorIndexedv__I_3II(JNIEnv* env, jclass clazz, jint index, jintArray v, jint vOffset)
{
    jint* j_v = v ? (jint*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glScissorIndexedv(
        (GLuint)index,
        (GLint*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glShaderBinary(GLsizei count, GLuint* shaders, GLenum binaryformat, GLvoid* binary, GLsizei length);
// public static native void glShaderBinary(int count, IntBuffer shaders, int binaryformat, Buffer binary, int length);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glShaderBinary__ILjava_nio_IntBuffer_2ILjava_nio_Buffer_2I(JNIEnv* env, jclass clazz, jint count, jobject shaders, jint binaryformat, jobject binary, jint length)
{
    glShaderBinary(
        (GLsizei)count,
        (GLuint*)(shaders ? (*env)->GetDirectBufferAddress(env, shaders) : 0),
        (GLenum)binaryformat,
        (GLvoid*)(binary ? (*env)->GetDirectBufferAddress(env, binary) : 0),
        (GLsizei)length);
}

// void glShaderBinary(GLsizei count, GLuint* shaders, GLenum binaryformat, GLvoid* binary, GLsizei length);
// public static native void glShaderBinary(int count, int[] shaders, int shadersOffset, int binaryformat, long binary, int length);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glShaderBinary__I_3IIIJI(JNIEnv* env, jclass clazz, jint count, jintArray shaders, jint shadersOffset, jint binaryformat, jlong binary, jint length)
{
    jint* j_shaders = shaders ? (jint*)((*env)->GetPrimitiveArrayCritical(env, shaders, 0)) : 0;
    glShaderBinary(
        (GLsizei)count,
        (GLuint*)(j_shaders + shadersOffset),
        (GLenum)binaryformat,
        (GLvoid*)long2Ptr(binary),
        (GLsizei)length);
    if(shaders) (*env)->ReleasePrimitiveArrayCritical(env, shaders, j_shaders, 0);
}

// void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
// public static native void glUseProgramStages(int pipeline, int stages, int program);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glUseProgramStages(JNIEnv* env, jclass clazz, jint pipeline, jint stages, jint program)
{
    glUseProgramStages(
        (GLuint)pipeline,
        (GLbitfield)stages,
        (GLuint)program);
}

// void glValidateProgramPipeline(GLuint pipeline);
// public static native void glValidateProgramPipeline(int pipeline);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glValidateProgramPipeline(JNIEnv* env, jclass clazz, jint pipeline)
{
    glValidateProgramPipeline(
        (GLuint)pipeline);
}

// void glVertexAttribL1d(GLuint index, GLdouble x);
// public static native void glVertexAttribL1d(int index, double x);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL1d(JNIEnv* env, jclass clazz, jint index, jdouble x)
{
    glVertexAttribL1d(
        (GLuint)index,
        (GLdouble)x);
}

// void glVertexAttribL1dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL1dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL1dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribL1dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribL1dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL1dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL1dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribL1dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
// public static native void glVertexAttribL2d(int index, double x, double y);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL2d(JNIEnv* env, jclass clazz, jint index, jdouble x, jdouble y)
{
    glVertexAttribL2d(
        (GLuint)index,
        (GLdouble)x,
        (GLdouble)y);
}

// void glVertexAttribL2dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL2dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL2dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribL2dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribL2dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL2dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL2dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribL2dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
// public static native void glVertexAttribL3d(int index, double x, double y, double z);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL3d(JNIEnv* env, jclass clazz, jint index, jdouble x, jdouble y, jdouble z)
{
    glVertexAttribL3d(
        (GLuint)index,
        (GLdouble)x,
        (GLdouble)y,
        (GLdouble)z);
}

// void glVertexAttribL3dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL3dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL3dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribL3dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribL3dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL3dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL3dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribL3dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
// public static native void glVertexAttribL4d(int index, double x, double y, double z, double w);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL4d(JNIEnv* env, jclass clazz, jint index, jdouble x, jdouble y, jdouble z, jdouble w)
{
    glVertexAttribL4d(
        (GLuint)index,
        (GLdouble)x,
        (GLdouble)y,
        (GLdouble)z,
        (GLdouble)w);
}

// void glVertexAttribL4dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL4dv(int index, DoubleBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL4dv__ILjava_nio_DoubleBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glVertexAttribL4dv(
        (GLuint)index,
        (GLdouble*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glVertexAttribL4dv(GLuint index, GLdouble* v);
// public static native void glVertexAttribL4dv(int index, double[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribL4dv__I_3DI(JNIEnv* env, jclass clazz, jint index, jdoubleArray v, jint vOffset)
{
    jdouble* j_v = v ? (jdouble*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glVertexAttribL4dv(
        (GLuint)index,
        (GLdouble*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
// public static native void glVertexAttribLPointer(int index, int size, int type, int stride, Buffer pointer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribLPointer__IIIILjava_nio_Buffer_2(JNIEnv* env, jclass clazz, jint index, jint size, jint type, jint stride, jobject pointer)
{
    glVertexAttribLPointer(
        (GLuint)index,
        (GLint)size,
        (GLenum)type,
        (GLsizei)stride,
        (GLvoid*)(pointer ? (*env)->GetDirectBufferAddress(env, pointer) : 0));
}

// void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
// public static native void glVertexAttribLPointer(int index, int size, int type, int stride, long pointer);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glVertexAttribLPointer__IIIIJ(JNIEnv* env, jclass clazz, jint index, jint size, jint type, jint stride, jlong pointer)
{
    glVertexAttribLPointer(
        (GLuint)index,
        (GLint)size,
        (GLenum)type,
        (GLsizei)stride,
        (GLvoid*)long2Ptr(pointer));
}

// void glViewportArrayv(GLuint first, GLsizei count, GLfloat* v);
// public static native void glViewportArrayv(int first, int count, FloatBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glViewportArrayv__IILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint first, jint count, jobject v)
{
    glViewportArrayv(
        (GLuint)first,
        (GLsizei)count,
        (GLfloat*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glViewportArrayv(GLuint first, GLsizei count, GLfloat* v);
// public static native void glViewportArrayv(int first, int count, float[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glViewportArrayv__II_3FI(JNIEnv* env, jclass clazz, jint first, jint count, jfloatArray v, jint vOffset)
{
    jfloat* j_v = v ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glViewportArrayv(
        (GLuint)first,
        (GLsizei)count,
        (GLfloat*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

// void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
// public static native void glViewportIndexedf(int index, float x, float y, float w, float h);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glViewportIndexedf(JNIEnv* env, jclass clazz, jint index, jfloat x, jfloat y, jfloat w, jfloat h)
{
    glViewportIndexedf(
        (GLuint)index,
        (GLfloat)x,
        (GLfloat)y,
        (GLfloat)w,
        (GLfloat)h);
}

// void glViewportIndexedfv(GLuint index, GLfloat* v);
// public static native void glViewportIndexedfv(int index, FloatBuffer v);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glViewportIndexedfv__ILjava_nio_FloatBuffer_2(JNIEnv* env, jclass clazz, jint index, jobject v)
{
    glViewportIndexedfv(
        (GLuint)index,
        (GLfloat*)(v ? (*env)->GetDirectBufferAddress(env, v) : 0));
}

// void glViewportIndexedfv(GLuint index, GLfloat* v);
// public static native void glViewportIndexedfv(int index, float[] v, int vOffset);
JNIEXPORT void JNICALL Java_com_github_rjeschke_njsdl_gl_GL_glViewportIndexedfv__I_3FI(JNIEnv* env, jclass clazz, jint index, jfloatArray v, jint vOffset)
{
    jfloat* j_v = v ? (jfloat*)((*env)->GetPrimitiveArrayCritical(env, v, 0)) : 0;
    glViewportIndexedfv(
        (GLuint)index,
        (GLfloat*)(j_v + vOffset));
    if(v) (*env)->ReleasePrimitiveArrayCritical(env, v, j_v, 0);
}

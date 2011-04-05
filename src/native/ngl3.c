#include "gl3.h"

void *ngl3Funcs[435];
char* ngl3Names =
    "glBlendColor\x0"
    "glBlendEquation\x0"
    "glCopyTexSubImage3D\x0"
    "glDrawRangeElements\x0"
    "glTexImage3D\x0"
    "glTexSubImage3D\x0"
    "glActiveTexture\x0"
    "glCompressedTexImage1D\x0"
    "glCompressedTexImage2D\x0"
    "glCompressedTexImage3D\x0"
    "glCompressedTexSubImage1D\x0"
    "glCompressedTexSubImage2D\x0"
    "glCompressedTexSubImage3D\x0"
    "glGetCompressedTexImage\x0"
    "glSampleCoverage\x0"
    "glBlendFuncSeparate\x0"
    "glMultiDrawArrays\x0"
    "glMultiDrawElements\x0"
    "glPointParameterf\x0"
    "glPointParameterfv\x0"
    "glPointParameteri\x0"
    "glPointParameteriv\x0"
    "glBeginQuery\x0"
    "glBindBuffer\x0"
    "glBufferData\x0"
    "glBufferSubData\x0"
    "glDeleteBuffers\x0"
    "glDeleteQueries\x0"
    "glEndQuery\x0"
    "glGenBuffers\x0"
    "glGenQueries\x0"
    "glGetBufferParameteriv\x0"
    "glGetBufferSubData\x0"
    "glGetQueryObjectiv\x0"
    "glGetQueryObjectuiv\x0"
    "glGetQueryiv\x0"
    "glIsBuffer\x0"
    "glIsQuery\x0"
    "glAttachShader\x0"
    "glBindAttribLocation\x0"
    "glBlendEquationSeparate\x0"
    "glCompileShader\x0"
    "glCreateProgram\x0"
    "glCreateShader\x0"
    "glDeleteProgram\x0"
    "glDeleteShader\x0"
    "glDetachShader\x0"
    "glDisableVertexAttribArray\x0"
    "glDrawBuffers\x0"
    "glEnableVertexAttribArray\x0"
    "glGetActiveAttrib\x0"
    "glGetActiveUniform\x0"
    "glGetAttachedShaders\x0"
    "glGetAttribLocation\x0"
    "glGetProgramInfoLog\x0"
    "glGetProgramiv\x0"
    "glGetShaderInfoLog\x0"
    "glGetShaderSource\x0"
    "glGetShaderiv\x0"
    "glGetUniformLocation\x0"
    "glGetUniformfv\x0"
    "glGetUniformiv\x0"
    "glGetVertexAttribdv\x0"
    "glGetVertexAttribfv\x0"
    "glGetVertexAttribiv\x0"
    "glIsProgram\x0"
    "glIsShader\x0"
    "glLinkProgram\x0"
    "glShaderSource\x0"
    "glStencilFuncSeparate\x0"
    "glStencilMaskSeparate\x0"
    "glStencilOpSeparate\x0"
    "glUniform1f\x0"
    "glUniform1fv\x0"
    "glUniform1i\x0"
    "glUniform1iv\x0"
    "glUniform2f\x0"
    "glUniform2fv\x0"
    "glUniform2i\x0"
    "glUniform2iv\x0"
    "glUniform3f\x0"
    "glUniform3fv\x0"
    "glUniform3i\x0"
    "glUniform3iv\x0"
    "glUniform4f\x0"
    "glUniform4fv\x0"
    "glUniform4i\x0"
    "glUniform4iv\x0"
    "glUniformMatrix2fv\x0"
    "glUniformMatrix3fv\x0"
    "glUniformMatrix4fv\x0"
    "glUseProgram\x0"
    "glValidateProgram\x0"
    "glVertexAttrib1d\x0"
    "glVertexAttrib1dv\x0"
    "glVertexAttrib1f\x0"
    "glVertexAttrib1fv\x0"
    "glVertexAttrib1s\x0"
    "glVertexAttrib1sv\x0"
    "glVertexAttrib2d\x0"
    "glVertexAttrib2dv\x0"
    "glVertexAttrib2f\x0"
    "glVertexAttrib2fv\x0"
    "glVertexAttrib2s\x0"
    "glVertexAttrib2sv\x0"
    "glVertexAttrib3d\x0"
    "glVertexAttrib3dv\x0"
    "glVertexAttrib3f\x0"
    "glVertexAttrib3fv\x0"
    "glVertexAttrib3s\x0"
    "glVertexAttrib3sv\x0"
    "glVertexAttrib4Nbv\x0"
    "glVertexAttrib4Niv\x0"
    "glVertexAttrib4Nsv\x0"
    "glVertexAttrib4Nub\x0"
    "glVertexAttrib4Nubv\x0"
    "glVertexAttrib4Nuiv\x0"
    "glVertexAttrib4Nusv\x0"
    "glVertexAttrib4bv\x0"
    "glVertexAttrib4d\x0"
    "glVertexAttrib4dv\x0"
    "glVertexAttrib4f\x0"
    "glVertexAttrib4fv\x0"
    "glVertexAttrib4iv\x0"
    "glVertexAttrib4s\x0"
    "glVertexAttrib4sv\x0"
    "glVertexAttrib4ubv\x0"
    "glVertexAttrib4uiv\x0"
    "glVertexAttrib4usv\x0"
    "glVertexAttribPointer\x0"
    "glUniformMatrix2x3fv\x0"
    "glUniformMatrix2x4fv\x0"
    "glUniformMatrix3x2fv\x0"
    "glUniformMatrix3x4fv\x0"
    "glUniformMatrix4x2fv\x0"
    "glUniformMatrix4x3fv\x0"
    "glBeginConditionalRender\x0"
    "glBeginTransformFeedback\x0"
    "glBindBufferBase\x0"
    "glBindBufferRange\x0"
    "glBindFragDataLocation\x0"
    "glBindFramebuffer\x0"
    "glBindRenderbuffer\x0"
    "glBindVertexArray\x0"
    "glBlitFramebuffer\x0"
    "glCheckFramebufferStatus\x0"
    "glClampColor\x0"
    "glClearBufferfi\x0"
    "glClearBufferfv\x0"
    "glClearBufferiv\x0"
    "glClearBufferuiv\x0"
    "glColorMaski\x0"
    "glDeleteFramebuffers\x0"
    "glDeleteRenderbuffers\x0"
    "glDeleteVertexArrays\x0"
    "glDisablei\x0"
    "glEnablei\x0"
    "glEndConditionalRender\x0"
    "glEndTransformFeedback\x0"
    "glFramebufferRenderbuffer\x0"
    "glFramebufferTexture1D\x0"
    "glFramebufferTexture2D\x0"
    "glFramebufferTexture3D\x0"
    "glFramebufferTextureLayer\x0"
    "glGenFramebuffers\x0"
    "glGenRenderbuffers\x0"
    "glGenVertexArrays\x0"
    "glGenerateMipmap\x0"
    "glGetBooleani_v\x0"
    "glGetFragDataLocation\x0"
    "glGetFramebufferAttachmentParameteriv\x0"
    "glGetIntegeri_v\x0"
    "glGetRenderbufferParameteriv\x0"
    "glGetStringi\x0"
    "glGetTexParameterIiv\x0"
    "glGetTexParameterIuiv\x0"
    "glGetTransformFeedbackVarying\x0"
    "glGetUniformuiv\x0"
    "glGetVertexAttribIiv\x0"
    "glGetVertexAttribIuiv\x0"
    "glIsEnabledi\x0"
    "glIsFramebuffer\x0"
    "glIsRenderbuffer\x0"
    "glIsVertexArray\x0"
    "glRenderbufferStorage\x0"
    "glRenderbufferStorageMultisample\x0"
    "glTexParameterIiv\x0"
    "glTexParameterIuiv\x0"
    "glTransformFeedbackVaryings\x0"
    "glUniform1ui\x0"
    "glUniform1uiv\x0"
    "glUniform2ui\x0"
    "glUniform2uiv\x0"
    "glUniform3ui\x0"
    "glUniform3uiv\x0"
    "glUniform4ui\x0"
    "glUniform4uiv\x0"
    "glVertexAttribI1i\x0"
    "glVertexAttribI1iv\x0"
    "glVertexAttribI1ui\x0"
    "glVertexAttribI1uiv\x0"
    "glVertexAttribI2i\x0"
    "glVertexAttribI2iv\x0"
    "glVertexAttribI2ui\x0"
    "glVertexAttribI2uiv\x0"
    "glVertexAttribI3i\x0"
    "glVertexAttribI3iv\x0"
    "glVertexAttribI3ui\x0"
    "glVertexAttribI3uiv\x0"
    "glVertexAttribI4bv\x0"
    "glVertexAttribI4i\x0"
    "glVertexAttribI4iv\x0"
    "glVertexAttribI4sv\x0"
    "glVertexAttribI4ubv\x0"
    "glVertexAttribI4ui\x0"
    "glVertexAttribI4uiv\x0"
    "glVertexAttribI4usv\x0"
    "glVertexAttribIPointer\x0"
    "glCopyBufferSubData\x0"
    "glDrawArraysInstanced\x0"
    "glDrawElementsInstanced\x0"
    "glGetActiveUniformBlockName\x0"
    "glGetActiveUniformBlockiv\x0"
    "glGetActiveUniformName\x0"
    "glGetActiveUniformsiv\x0"
    "glGetUniformBlockIndex\x0"
    "glGetUniformIndices\x0"
    "glPrimitiveRestartIndex\x0"
    "glTexBuffer\x0"
    "glUniformBlockBinding\x0"
    "glDrawElementsBaseVertex\x0"
    "glDrawElementsInstancedBaseVertex\x0"
    "glDrawRangeElementsBaseVertex\x0"
    "glFramebufferTexture\x0"
    "glGetBufferParameteri64v\x0"
    "glGetInteger64i_v\x0"
    "glGetInteger64v\x0"
    "glGetMultisamplefv\x0"
    "glMultiDrawElementsBaseVertex\x0"
    "glProvokingVertex\x0"
    "glSampleMaski\x0"
    "glTexImage2DMultisample\x0"
    "glTexImage3DMultisample\x0"
    "glBindFragDataLocationIndexed\x0"
    "glBindSampler\x0"
    "glColorP3ui\x0"
    "glColorP3uiv\x0"
    "glColorP4ui\x0"
    "glColorP4uiv\x0"
    "glDeleteSamplers\x0"
    "glGenSamplers\x0"
    "glGetFragDataIndex\x0"
    "glGetQueryObjecti64v\x0"
    "glGetQueryObjectui64v\x0"
    "glGetSamplerParameterIiv\x0"
    "glGetSamplerParameterIuiv\x0"
    "glGetSamplerParameterfv\x0"
    "glGetSamplerParameteriv\x0"
    "glIsSampler\x0"
    "glMultiTexCoordP1ui\x0"
    "glMultiTexCoordP1uiv\x0"
    "glMultiTexCoordP2ui\x0"
    "glMultiTexCoordP2uiv\x0"
    "glMultiTexCoordP3ui\x0"
    "glMultiTexCoordP3uiv\x0"
    "glMultiTexCoordP4ui\x0"
    "glMultiTexCoordP4uiv\x0"
    "glNormalP3ui\x0"
    "glNormalP3uiv\x0"
    "glQueryCounter\x0"
    "glSamplerParameterIiv\x0"
    "glSamplerParameterIuiv\x0"
    "glSamplerParameterf\x0"
    "glSamplerParameterfv\x0"
    "glSamplerParameteri\x0"
    "glSamplerParameteriv\x0"
    "glSecondaryColorP3ui\x0"
    "glSecondaryColorP3uiv\x0"
    "glTexCoordP1ui\x0"
    "glTexCoordP1uiv\x0"
    "glTexCoordP2ui\x0"
    "glTexCoordP2uiv\x0"
    "glTexCoordP3ui\x0"
    "glTexCoordP3uiv\x0"
    "glTexCoordP4ui\x0"
    "glTexCoordP4uiv\x0"
    "glVertexAttribDivisor\x0"
    "glVertexAttribP1ui\x0"
    "glVertexAttribP1uiv\x0"
    "glVertexAttribP2ui\x0"
    "glVertexAttribP2uiv\x0"
    "glVertexAttribP3ui\x0"
    "glVertexAttribP3uiv\x0"
    "glVertexAttribP4ui\x0"
    "glVertexAttribP4uiv\x0"
    "glVertexP2ui\x0"
    "glVertexP2uiv\x0"
    "glVertexP3ui\x0"
    "glVertexP3uiv\x0"
    "glVertexP4ui\x0"
    "glVertexP4uiv\x0"
    "glBeginQueryIndexed\x0"
    "glBindTransformFeedback\x0"
    "glBlendEquationSeparatei\x0"
    "glBlendEquationi\x0"
    "glBlendFuncSeparatei\x0"
    "glBlendFunci\x0"
    "glDeleteTransformFeedbacks\x0"
    "glDrawArraysIndirect\x0"
    "glDrawElementsIndirect\x0"
    "glDrawTransformFeedback\x0"
    "glDrawTransformFeedbackStream\x0"
    "glEndQueryIndexed\x0"
    "glGenTransformFeedbacks\x0"
    "glGetActiveSubroutineName\x0"
    "glGetActiveSubroutineUniformName\x0"
    "glGetActiveSubroutineUniformiv\x0"
    "glGetProgramStageiv\x0"
    "glGetQueryIndexediv\x0"
    "glGetSubroutineIndex\x0"
    "glGetSubroutineUniformLocation\x0"
    "glGetUniformSubroutineuiv\x0"
    "glGetUniformdv\x0"
    "glIsTransformFeedback\x0"
    "glMinSampleShading\x0"
    "glPatchParameterfv\x0"
    "glPatchParameteri\x0"
    "glPauseTransformFeedback\x0"
    "glResumeTransformFeedback\x0"
    "glUniform1d\x0"
    "glUniform1dv\x0"
    "glUniform2d\x0"
    "glUniform2dv\x0"
    "glUniform3d\x0"
    "glUniform3dv\x0"
    "glUniform4d\x0"
    "glUniform4dv\x0"
    "glUniformMatrix2dv\x0"
    "glUniformMatrix2x3dv\x0"
    "glUniformMatrix2x4dv\x0"
    "glUniformMatrix3dv\x0"
    "glUniformMatrix3x2dv\x0"
    "glUniformMatrix3x4dv\x0"
    "glUniformMatrix4dv\x0"
    "glUniformMatrix4x2dv\x0"
    "glUniformMatrix4x3dv\x0"
    "glUniformSubroutinesuiv\x0"
    "glActiveShaderProgram\x0"
    "glBindProgramPipeline\x0"
    "glClearDepthf\x0"
    "glCreateShaderProgramv\x0"
    "glDeleteProgramPipelines\x0"
    "glDepthRangeArrayv\x0"
    "glDepthRangeIndexed\x0"
    "glDepthRangef\x0"
    "glGenProgramPipelines\x0"
    "glGetDoublei_v\x0"
    "glGetFloati_v\x0"
    "glGetProgramBinary\x0"
    "glGetProgramPipelineInfoLog\x0"
    "glGetProgramPipelineiv\x0"
    "glGetShaderPrecisionFormat\x0"
    "glGetVertexAttribLdv\x0"
    "glIsProgramPipeline\x0"
    "glProgramBinary\x0"
    "glProgramParameteri\x0"
    "glProgramUniform1d\x0"
    "glProgramUniform1dv\x0"
    "glProgramUniform1f\x0"
    "glProgramUniform1fv\x0"
    "glProgramUniform1i\x0"
    "glProgramUniform1iv\x0"
    "glProgramUniform1ui\x0"
    "glProgramUniform1uiv\x0"
    "glProgramUniform2d\x0"
    "glProgramUniform2dv\x0"
    "glProgramUniform2f\x0"
    "glProgramUniform2fv\x0"
    "glProgramUniform2i\x0"
    "glProgramUniform2iv\x0"
    "glProgramUniform2ui\x0"
    "glProgramUniform2uiv\x0"
    "glProgramUniform3d\x0"
    "glProgramUniform3dv\x0"
    "glProgramUniform3f\x0"
    "glProgramUniform3fv\x0"
    "glProgramUniform3i\x0"
    "glProgramUniform3iv\x0"
    "glProgramUniform3ui\x0"
    "glProgramUniform3uiv\x0"
    "glProgramUniform4d\x0"
    "glProgramUniform4dv\x0"
    "glProgramUniform4f\x0"
    "glProgramUniform4fv\x0"
    "glProgramUniform4i\x0"
    "glProgramUniform4iv\x0"
    "glProgramUniform4ui\x0"
    "glProgramUniform4uiv\x0"
    "glProgramUniformMatrix2dv\x0"
    "glProgramUniformMatrix2fv\x0"
    "glProgramUniformMatrix2x3dv\x0"
    "glProgramUniformMatrix2x3fv\x0"
    "glProgramUniformMatrix2x4dv\x0"
    "glProgramUniformMatrix2x4fv\x0"
    "glProgramUniformMatrix3dv\x0"
    "glProgramUniformMatrix3fv\x0"
    "glProgramUniformMatrix3x2dv\x0"
    "glProgramUniformMatrix3x2fv\x0"
    "glProgramUniformMatrix3x4dv\x0"
    "glProgramUniformMatrix3x4fv\x0"
    "glProgramUniformMatrix4dv\x0"
    "glProgramUniformMatrix4fv\x0"
    "glProgramUniformMatrix4x2dv\x0"
    "glProgramUniformMatrix4x2fv\x0"
    "glProgramUniformMatrix4x3dv\x0"
    "glProgramUniformMatrix4x3fv\x0"
    "glReleaseShaderCompiler\x0"
    "glScissorArrayv\x0"
    "glScissorIndexed\x0"
    "glScissorIndexedv\x0"
    "glShaderBinary\x0"
    "glUseProgramStages\x0"
    "glValidateProgramPipeline\x0"
    "glVertexAttribL1d\x0"
    "glVertexAttribL1dv\x0"
    "glVertexAttribL2d\x0"
    "glVertexAttribL2dv\x0"
    "glVertexAttribL3d\x0"
    "glVertexAttribL3dv\x0"
    "glVertexAttribL4d\x0"
    "glVertexAttribL4dv\x0"
    "glVertexAttribLPointer\x0"
    "glViewportArrayv\x0"
    "glViewportIndexedf\x0"
    "glViewportIndexedfv\x0";
/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.DoubleBuffer;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;
import java.nio.ShortBuffer;

public class GL
{
    private GL() { /* */ }
    
    public final static int GL_ACTIVE_ATTRIBUTES                                 = 0x00008B89;
    public final static int GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                       = 0x00008B8A;
    public final static int GL_ACTIVE_PROGRAM                                    = 0x00008259;
    public final static int GL_ACTIVE_SUBROUTINES                                = 0x00008DE5;
    public final static int GL_ACTIVE_SUBROUTINE_MAX_LENGTH                      = 0x00008E48;
    public final static int GL_ACTIVE_SUBROUTINE_UNIFORMS                        = 0x00008DE6;
    public final static int GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS               = 0x00008E47;
    public final static int GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH              = 0x00008E49;
    public final static int GL_ACTIVE_TEXTURE                                    = 0x000084E0;
    public final static int GL_ACTIVE_UNIFORMS                                   = 0x00008B86;
    public final static int GL_ACTIVE_UNIFORM_BLOCKS                             = 0x00008A36;
    public final static int GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH              = 0x00008A35;
    public final static int GL_ACTIVE_UNIFORM_MAX_LENGTH                         = 0x00008B87;
    public final static int GL_ALIASED_LINE_WIDTH_RANGE                          = 0x0000846E;
    public final static int GL_ALL_SHADER_BITS                                   = 0xFFFFFFFF;
    public final static int GL_ALPHA                                             = 0x00001906;
    public final static int GL_ALREADY_SIGNALED                                  = 0x0000911A;
    public final static int GL_ALWAYS                                            = 0x00000207;
    public final static int GL_AND                                               = 0x00001501;
    public final static int GL_AND_INVERTED                                      = 0x00001504;
    public final static int GL_AND_REVERSE                                       = 0x00001502;
    public final static int GL_ANY_SAMPLES_PASSED                                = 0x00008C2F;
    public final static int GL_ARRAY_BUFFER                                      = 0x00008892;
    public final static int GL_ARRAY_BUFFER_BINDING                              = 0x00008894;
    public final static int GL_ATTACHED_SHADERS                                  = 0x00008B85;
    public final static int GL_BACK                                              = 0x00000405;
    public final static int GL_BACK_LEFT                                         = 0x00000402;
    public final static int GL_BACK_RIGHT                                        = 0x00000403;
    public final static int GL_BGR                                               = 0x000080E0;
    public final static int GL_BGRA                                              = 0x000080E1;
    public final static int GL_BGRA_INTEGER                                      = 0x00008D9B;
    public final static int GL_BGR_INTEGER                                       = 0x00008D9A;
    public final static int GL_BLEND                                             = 0x00000BE2;
    public final static int GL_BLEND_COLOR                                       = 0x00008005;
    public final static int GL_BLEND_DST                                         = 0x00000BE0;
    public final static int GL_BLEND_DST_ALPHA                                   = 0x000080CA;
    public final static int GL_BLEND_DST_RGB                                     = 0x000080C8;
    public final static int GL_BLEND_EQUATION                                    = 0x00008009;
    public final static int GL_BLEND_EQUATION_ALPHA                              = 0x0000883D;
    public final static int GL_BLEND_EQUATION_RGB                                = 0x00008009;
    public final static int GL_BLEND_SRC                                         = 0x00000BE1;
    public final static int GL_BLEND_SRC_ALPHA                                   = 0x000080CB;
    public final static int GL_BLEND_SRC_RGB                                     = 0x000080C9;
    public final static int GL_BLUE                                              = 0x00001905;
    public final static int GL_BLUE_INTEGER                                      = 0x00008D96;
    public final static int GL_BOOL                                              = 0x00008B56;
    public final static int GL_BOOL_VEC2                                         = 0x00008B57;
    public final static int GL_BOOL_VEC3                                         = 0x00008B58;
    public final static int GL_BOOL_VEC4                                         = 0x00008B59;
    public final static int GL_BUFFER_ACCESS                                     = 0x000088BB;
    public final static int GL_BUFFER_ACCESS_FLAGS                               = 0x0000911F;
    public final static int GL_BUFFER_MAPPED                                     = 0x000088BC;
    public final static int GL_BUFFER_MAP_LENGTH                                 = 0x00009120;
    public final static int GL_BUFFER_MAP_OFFSET                                 = 0x00009121;
    public final static int GL_BUFFER_MAP_POINTER                                = 0x000088BD;
    public final static int GL_BUFFER_SIZE                                       = 0x00008764;
    public final static int GL_BUFFER_USAGE                                      = 0x00008765;
    public final static int GL_BYTE                                              = 0x00001400;
    public final static int GL_CCW                                               = 0x00000901;
    public final static int GL_CLAMP_READ_COLOR                                  = 0x0000891C;
    public final static int GL_CLAMP_TO_BORDER                                   = 0x0000812D;
    public final static int GL_CLAMP_TO_EDGE                                     = 0x0000812F;
    public final static int GL_CLEAR                                             = 0x00001500;
    public final static int GL_CLIP_DISTANCE0                                    = 0x00003000;
    public final static int GL_CLIP_DISTANCE1                                    = 0x00003001;
    public final static int GL_CLIP_DISTANCE2                                    = 0x00003002;
    public final static int GL_CLIP_DISTANCE3                                    = 0x00003003;
    public final static int GL_CLIP_DISTANCE4                                    = 0x00003004;
    public final static int GL_CLIP_DISTANCE5                                    = 0x00003005;
    public final static int GL_CLIP_DISTANCE6                                    = 0x00003006;
    public final static int GL_CLIP_DISTANCE7                                    = 0x00003007;
    public final static int GL_COLOR                                             = 0x00001800;
    public final static int GL_COLOR_ATTACHMENT0                                 = 0x00008CE0;
    public final static int GL_COLOR_ATTACHMENT1                                 = 0x00008CE1;
    public final static int GL_COLOR_ATTACHMENT10                                = 0x00008CEA;
    public final static int GL_COLOR_ATTACHMENT11                                = 0x00008CEB;
    public final static int GL_COLOR_ATTACHMENT12                                = 0x00008CEC;
    public final static int GL_COLOR_ATTACHMENT13                                = 0x00008CED;
    public final static int GL_COLOR_ATTACHMENT14                                = 0x00008CEE;
    public final static int GL_COLOR_ATTACHMENT15                                = 0x00008CEF;
    public final static int GL_COLOR_ATTACHMENT2                                 = 0x00008CE2;
    public final static int GL_COLOR_ATTACHMENT3                                 = 0x00008CE3;
    public final static int GL_COLOR_ATTACHMENT4                                 = 0x00008CE4;
    public final static int GL_COLOR_ATTACHMENT5                                 = 0x00008CE5;
    public final static int GL_COLOR_ATTACHMENT6                                 = 0x00008CE6;
    public final static int GL_COLOR_ATTACHMENT7                                 = 0x00008CE7;
    public final static int GL_COLOR_ATTACHMENT8                                 = 0x00008CE8;
    public final static int GL_COLOR_ATTACHMENT9                                 = 0x00008CE9;
    public final static int GL_COLOR_BUFFER_BIT                                  = 0x00004000;
    public final static int GL_COLOR_CLEAR_VALUE                                 = 0x00000C22;
    public final static int GL_COLOR_LOGIC_OP                                    = 0x00000BF2;
    public final static int GL_COLOR_WRITEMASK                                   = 0x00000C23;
    public final static int GL_COMPARE_REF_TO_TEXTURE                            = 0x0000884E;
    public final static int GL_COMPATIBLE_SUBROUTINES                            = 0x00008E4B;
    public final static int GL_COMPILE_STATUS                                    = 0x00008B81;
    public final static int GL_COMPRESSED_RED                                    = 0x00008225;
    public final static int GL_COMPRESSED_RED_RGTC1                              = 0x00008DBB;
    public final static int GL_COMPRESSED_RG                                     = 0x00008226;
    public final static int GL_COMPRESSED_RGB                                    = 0x000084ED;
    public final static int GL_COMPRESSED_RGBA                                   = 0x000084EE;
    public final static int GL_COMPRESSED_RGBA_BPTC_UNORM_ARB                    = 0x00008E8C;
    public final static int GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB              = 0x00008E8E;
    public final static int GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB            = 0x00008E8F;
    public final static int GL_COMPRESSED_RG_RGTC2                               = 0x00008DBD;
    public final static int GL_COMPRESSED_SIGNED_RED_RGTC1                       = 0x00008DBC;
    public final static int GL_COMPRESSED_SIGNED_RG_RGTC2                        = 0x00008DBE;
    public final static int GL_COMPRESSED_SRGB                                   = 0x00008C48;
    public final static int GL_COMPRESSED_SRGB_ALPHA                             = 0x00008C49;
    public final static int GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB              = 0x00008E8D;
    public final static int GL_COMPRESSED_TEXTURE_FORMATS                        = 0x000086A3;
    public final static int GL_CONDITION_SATISFIED                               = 0x0000911C;
    public final static int GL_CONSTANT_ALPHA                                    = 0x00008003;
    public final static int GL_CONSTANT_COLOR                                    = 0x00008001;
    public final static int GL_CONTEXT_COMPATIBILITY_PROFILE_BIT                 = 0x00000002;
    public final static int GL_CONTEXT_CORE_PROFILE_BIT                          = 0x00000001;
    public final static int GL_CONTEXT_FLAGS                                     = 0x0000821E;
    public final static int GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT               = 0x00000001;
    public final static int GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB                = 0x00000004;
    public final static int GL_CONTEXT_PROFILE_MASK                              = 0x00009126;
    public final static int GL_COPY                                              = 0x00001503;
    public final static int GL_COPY_INVERTED                                     = 0x0000150C;
    public final static int GL_COPY_READ_BUFFER                                  = 0x00008F36;
    public final static int GL_COPY_WRITE_BUFFER                                 = 0x00008F37;
    public final static int GL_CULL_FACE                                         = 0x00000B44;
    public final static int GL_CULL_FACE_MODE                                    = 0x00000B45;
    public final static int GL_CURRENT_PROGRAM                                   = 0x00008B8D;
    public final static int GL_CURRENT_QUERY                                     = 0x00008865;
    public final static int GL_CURRENT_VERTEX_ATTRIB                             = 0x00008626;
    public final static int GL_CW                                                = 0x00000900;
    public final static int GL_DEBUG_CALLBACK_FUNCTION_ARB                       = 0x00008244;
    public final static int GL_DEBUG_CALLBACK_USER_PARAM_ARB                     = 0x00008245;
    public final static int GL_DEBUG_LOGGED_MESSAGES_ARB                         = 0x00009145;
    public final static int GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB              = 0x00008243;
    public final static int GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB                      = 0x00008242;
    public final static int GL_DEBUG_SEVERITY_HIGH_ARB                           = 0x00009146;
    public final static int GL_DEBUG_SEVERITY_LOW_ARB                            = 0x00009148;
    public final static int GL_DEBUG_SEVERITY_MEDIUM_ARB                         = 0x00009147;
    public final static int GL_DEBUG_SOURCE_API_ARB                              = 0x00008246;
    public final static int GL_DEBUG_SOURCE_APPLICATION_ARB                      = 0x0000824A;
    public final static int GL_DEBUG_SOURCE_OTHER_ARB                            = 0x0000824B;
    public final static int GL_DEBUG_SOURCE_SHADER_COMPILER_ARB                  = 0x00008248;
    public final static int GL_DEBUG_SOURCE_THIRD_PARTY_ARB                      = 0x00008249;
    public final static int GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB                    = 0x00008247;
    public final static int GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB                = 0x0000824D;
    public final static int GL_DEBUG_TYPE_ERROR_ARB                              = 0x0000824C;
    public final static int GL_DEBUG_TYPE_OTHER_ARB                              = 0x00008251;
    public final static int GL_DEBUG_TYPE_PERFORMANCE_ARB                        = 0x00008250;
    public final static int GL_DEBUG_TYPE_PORTABILITY_ARB                        = 0x0000824F;
    public final static int GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB                 = 0x0000824E;
    public final static int GL_DECR                                              = 0x00001E03;
    public final static int GL_DECR_WRAP                                         = 0x00008508;
    public final static int GL_DELETE_STATUS                                     = 0x00008B80;
    public final static int GL_DEPTH                                             = 0x00001801;
    public final static int GL_DEPTH24_STENCIL8                                  = 0x000088F0;
    public final static int GL_DEPTH32F_STENCIL8                                 = 0x00008CAD;
    public final static int GL_DEPTH_ATTACHMENT                                  = 0x00008D00;
    public final static int GL_DEPTH_BUFFER                                      = 0x00008223;
    public final static int GL_DEPTH_BUFFER_BIT                                  = 0x00000100;
    public final static int GL_DEPTH_CLAMP                                       = 0x0000864F;
    public final static int GL_DEPTH_CLEAR_VALUE                                 = 0x00000B73;
    public final static int GL_DEPTH_COMPONENT                                   = 0x00001902;
    public final static int GL_DEPTH_COMPONENT16                                 = 0x000081A5;
    public final static int GL_DEPTH_COMPONENT24                                 = 0x000081A6;
    public final static int GL_DEPTH_COMPONENT32                                 = 0x000081A7;
    public final static int GL_DEPTH_COMPONENT32F                                = 0x00008CAC;
    public final static int GL_DEPTH_FUNC                                        = 0x00000B74;
    public final static int GL_DEPTH_RANGE                                       = 0x00000B70;
    public final static int GL_DEPTH_STENCIL                                     = 0x000084F9;
    public final static int GL_DEPTH_STENCIL_ATTACHMENT                          = 0x0000821A;
    public final static int GL_DEPTH_TEST                                        = 0x00000B71;
    public final static int GL_DEPTH_WRITEMASK                                   = 0x00000B72;
    public final static int GL_DITHER                                            = 0x00000BD0;
    public final static int GL_DONT_CARE                                         = 0x00001100;
    public final static int GL_DOUBLE                                            = 0x0000140A;
    public final static int GL_DOUBLEBUFFER                                      = 0x00000C32;
    public final static int GL_DOUBLE_MAT2                                       = 0x00008F46;
    public final static int GL_DOUBLE_MAT2x3                                     = 0x00008F49;
    public final static int GL_DOUBLE_MAT2x4                                     = 0x00008F4A;
    public final static int GL_DOUBLE_MAT3                                       = 0x00008F47;
    public final static int GL_DOUBLE_MAT3x2                                     = 0x00008F4B;
    public final static int GL_DOUBLE_MAT3x4                                     = 0x00008F4C;
    public final static int GL_DOUBLE_MAT4                                       = 0x00008F48;
    public final static int GL_DOUBLE_MAT4x2                                     = 0x00008F4D;
    public final static int GL_DOUBLE_MAT4x3                                     = 0x00008F4E;
    public final static int GL_DOUBLE_VEC2                                       = 0x00008FFC;
    public final static int GL_DOUBLE_VEC3                                       = 0x00008FFD;
    public final static int GL_DOUBLE_VEC4                                       = 0x00008FFE;
    public final static int GL_DRAW_BUFFER                                       = 0x00000C01;
    public final static int GL_DRAW_BUFFER0                                      = 0x00008825;
    public final static int GL_DRAW_BUFFER1                                      = 0x00008826;
    public final static int GL_DRAW_BUFFER10                                     = 0x0000882F;
    public final static int GL_DRAW_BUFFER11                                     = 0x00008830;
    public final static int GL_DRAW_BUFFER12                                     = 0x00008831;
    public final static int GL_DRAW_BUFFER13                                     = 0x00008832;
    public final static int GL_DRAW_BUFFER14                                     = 0x00008833;
    public final static int GL_DRAW_BUFFER15                                     = 0x00008834;
    public final static int GL_DRAW_BUFFER2                                      = 0x00008827;
    public final static int GL_DRAW_BUFFER3                                      = 0x00008828;
    public final static int GL_DRAW_BUFFER4                                      = 0x00008829;
    public final static int GL_DRAW_BUFFER5                                      = 0x0000882A;
    public final static int GL_DRAW_BUFFER6                                      = 0x0000882B;
    public final static int GL_DRAW_BUFFER7                                      = 0x0000882C;
    public final static int GL_DRAW_BUFFER8                                      = 0x0000882D;
    public final static int GL_DRAW_BUFFER9                                      = 0x0000882E;
    public final static int GL_DRAW_FRAMEBUFFER                                  = 0x00008CA9;
    public final static int GL_DRAW_FRAMEBUFFER_BINDING                          = 0x00008CA6;
    public final static int GL_DRAW_INDIRECT_BUFFER                              = 0x00008F3F;
    public final static int GL_DRAW_INDIRECT_BUFFER_BINDING                      = 0x00008F43;
    public final static int GL_DST_ALPHA                                         = 0x00000304;
    public final static int GL_DST_COLOR                                         = 0x00000306;
    public final static int GL_DYNAMIC_COPY                                      = 0x000088EA;
    public final static int GL_DYNAMIC_DRAW                                      = 0x000088E8;
    public final static int GL_DYNAMIC_READ                                      = 0x000088E9;
    public final static int GL_ELEMENT_ARRAY_BUFFER                              = 0x00008893;
    public final static int GL_ELEMENT_ARRAY_BUFFER_BINDING                      = 0x00008895;
    public final static int GL_EQUAL                                             = 0x00000202;
    public final static int GL_EQUIV                                             = 0x00001509;
    public final static int GL_EXTENSIONS                                        = 0x00001F03;
    public final static int GL_FALSE                                             = 0x00000000;
    public final static int GL_FASTEST                                           = 0x00001101;
    public final static int GL_FILL                                              = 0x00001B02;
    public final static int GL_FIRST_VERTEX_CONVENTION                           = 0x00008E4D;
    public final static int GL_FIXED                                             = 0x0000140C;
    public final static int GL_FIXED_ONLY                                        = 0x0000891D;
    public final static int GL_FLOAT                                             = 0x00001406;
    public final static int GL_FLOAT_32_UNSIGNED_INT_24_8_REV                    = 0x00008DAD;
    public final static int GL_FLOAT_MAT2                                        = 0x00008B5A;
    public final static int GL_FLOAT_MAT2x3                                      = 0x00008B65;
    public final static int GL_FLOAT_MAT2x4                                      = 0x00008B66;
    public final static int GL_FLOAT_MAT3                                        = 0x00008B5B;
    public final static int GL_FLOAT_MAT3x2                                      = 0x00008B67;
    public final static int GL_FLOAT_MAT3x4                                      = 0x00008B68;
    public final static int GL_FLOAT_MAT4                                        = 0x00008B5C;
    public final static int GL_FLOAT_MAT4x2                                      = 0x00008B69;
    public final static int GL_FLOAT_MAT4x3                                      = 0x00008B6A;
    public final static int GL_FLOAT_VEC2                                        = 0x00008B50;
    public final static int GL_FLOAT_VEC3                                        = 0x00008B51;
    public final static int GL_FLOAT_VEC4                                        = 0x00008B52;
    public final static int GL_FRACTIONAL_EVEN                                   = 0x00008E7C;
    public final static int GL_FRACTIONAL_ODD                                    = 0x00008E7B;
    public final static int GL_FRAGMENT_INTERPOLATION_OFFSET_BITS                = 0x00008E5D;
    public final static int GL_FRAGMENT_SHADER                                   = 0x00008B30;
    public final static int GL_FRAGMENT_SHADER_BIT                               = 0x00000002;
    public final static int GL_FRAGMENT_SHADER_DERIVATIVE_HINT                   = 0x00008B8B;
    public final static int GL_FRAMEBUFFER                                       = 0x00008D40;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                 = 0x00008215;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                  = 0x00008214;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING             = 0x00008210;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE             = 0x00008211;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                 = 0x00008216;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                 = 0x00008213;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_LAYERED                    = 0x00008DA7;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME                = 0x00008CD1;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE                = 0x00008CD0;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                   = 0x00008212;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE               = 0x00008217;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE      = 0x00008CD3;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER              = 0x00008CD4;
    public final static int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL              = 0x00008CD2;
    public final static int GL_FRAMEBUFFER_BINDING                               = 0x00008CA6;
    public final static int GL_FRAMEBUFFER_COMPLETE                              = 0x00008CD5;
    public final static int GL_FRAMEBUFFER_DEFAULT                               = 0x00008218;
    public final static int GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                 = 0x00008CD6;
    public final static int GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER                = 0x00008CDB;
    public final static int GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS              = 0x00008DA8;
    public final static int GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT         = 0x00008CD7;
    public final static int GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE                = 0x00008D56;
    public final static int GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER                = 0x00008CDC;
    public final static int GL_FRAMEBUFFER_SRGB                                  = 0x00008DB9;
    public final static int GL_FRAMEBUFFER_UNDEFINED                             = 0x00008219;
    public final static int GL_FRAMEBUFFER_UNSUPPORTED                           = 0x00008CDD;
    public final static int GL_FRONT                                             = 0x00000404;
    public final static int GL_FRONT_AND_BACK                                    = 0x00000408;
    public final static int GL_FRONT_FACE                                        = 0x00000B46;
    public final static int GL_FRONT_LEFT                                        = 0x00000400;
    public final static int GL_FRONT_RIGHT                                       = 0x00000401;
    public final static int GL_FUNC_ADD                                          = 0x00008006;
    public final static int GL_FUNC_REVERSE_SUBTRACT                             = 0x0000800B;
    public final static int GL_FUNC_SUBTRACT                                     = 0x0000800A;
    public final static int GL_GEOMETRY_INPUT_TYPE                               = 0x00008917;
    public final static int GL_GEOMETRY_OUTPUT_TYPE                              = 0x00008918;
    public final static int GL_GEOMETRY_SHADER                                   = 0x00008DD9;
    public final static int GL_GEOMETRY_SHADER_BIT                               = 0x00000004;
    public final static int GL_GEOMETRY_SHADER_INVOCATIONS                       = 0x0000887F;
    public final static int GL_GEOMETRY_VERTICES_OUT                             = 0x00008916;
    public final static int GL_GEQUAL                                            = 0x00000206;
    public final static int GL_GREATER                                           = 0x00000204;
    public final static int GL_GREEN                                             = 0x00001904;
    public final static int GL_GREEN_INTEGER                                     = 0x00008D95;
    public final static int GL_GUILTY_CONTEXT_RESET_ARB                          = 0x00008253;
    public final static int GL_HALF_FLOAT                                        = 0x0000140B;
    public final static int GL_HIGH_FLOAT                                        = 0x00008DF2;
    public final static int GL_HIGH_INT                                          = 0x00008DF5;
    public final static int GL_IMPLEMENTATION_COLOR_READ_FORMAT                  = 0x00008B9B;
    public final static int GL_IMPLEMENTATION_COLOR_READ_TYPE                    = 0x00008B9A;
    public final static int GL_INCR                                              = 0x00001E02;
    public final static int GL_INCR_WRAP                                         = 0x00008507;
    public final static int GL_INFO_LOG_LENGTH                                   = 0x00008B84;
    public final static int GL_INNOCENT_CONTEXT_RESET_ARB                        = 0x00008254;
    public final static int GL_INT                                               = 0x00001404;
    public final static int GL_INTERLEAVED_ATTRIBS                               = 0x00008C8C;
    public final static int GL_INT_2_10_10_10_REV                                = 0x00008D9F;
    public final static int GL_INT_SAMPLER_1D                                    = 0x00008DC9;
    public final static int GL_INT_SAMPLER_1D_ARRAY                              = 0x00008DCE;
    public final static int GL_INT_SAMPLER_2D                                    = 0x00008DCA;
    public final static int GL_INT_SAMPLER_2D_ARRAY                              = 0x00008DCF;
    public final static int GL_INT_SAMPLER_2D_MULTISAMPLE                        = 0x00009109;
    public final static int GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                  = 0x0000910C;
    public final static int GL_INT_SAMPLER_2D_RECT                               = 0x00008DCD;
    public final static int GL_INT_SAMPLER_3D                                    = 0x00008DCB;
    public final static int GL_INT_SAMPLER_BUFFER                                = 0x00008DD0;
    public final static int GL_INT_SAMPLER_CUBE                                  = 0x00008DCC;
    public final static int GL_INT_SAMPLER_CUBE_MAP_ARRAY                        = 0x0000900E;
    public final static int GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB                    = 0x0000900E;
    public final static int GL_INT_VEC2                                          = 0x00008B53;
    public final static int GL_INT_VEC3                                          = 0x00008B54;
    public final static int GL_INT_VEC4                                          = 0x00008B55;
    public final static int GL_INVALID_ENUM                                      = 0x00000500;
    public final static int GL_INVALID_FRAMEBUFFER_OPERATION                     = 0x00000506;
    public final static int GL_INVALID_INDEX                                     = 0xFFFFFFFF;
    public final static int GL_INVALID_OPERATION                                 = 0x00000502;
    public final static int GL_INVALID_VALUE                                     = 0x00000501;
    public final static int GL_INVERT                                            = 0x0000150A;
    public final static int GL_ISOLINES                                          = 0x00008E7A;
    public final static int GL_KEEP                                              = 0x00001E00;
    public final static int GL_LAST_VERTEX_CONVENTION                            = 0x00008E4E;
    public final static int GL_LAYER_PROVOKING_VERTEX                            = 0x0000825E;
    public final static int GL_LEFT                                              = 0x00000406;
    public final static int GL_LEQUAL                                            = 0x00000203;
    public final static int GL_LESS                                              = 0x00000201;
    public final static int GL_LINE                                              = 0x00001B01;
    public final static int GL_LINEAR                                            = 0x00002601;
    public final static int GL_LINEAR_MIPMAP_LINEAR                              = 0x00002703;
    public final static int GL_LINEAR_MIPMAP_NEAREST                             = 0x00002701;
    public final static int GL_LINES                                             = 0x00000001;
    public final static int GL_LINES_ADJACENCY                                   = 0x0000000A;
    public final static int GL_LINE_LOOP                                         = 0x00000002;
    public final static int GL_LINE_SMOOTH                                       = 0x00000B20;
    public final static int GL_LINE_SMOOTH_HINT                                  = 0x00000C52;
    public final static int GL_LINE_STRIP                                        = 0x00000003;
    public final static int GL_LINE_STRIP_ADJACENCY                              = 0x0000000B;
    public final static int GL_LINE_WIDTH                                        = 0x00000B21;
    public final static int GL_LINE_WIDTH_GRANULARITY                            = 0x00000B23;
    public final static int GL_LINE_WIDTH_RANGE                                  = 0x00000B22;
    public final static int GL_LINK_STATUS                                       = 0x00008B82;
    public final static int GL_LOGIC_OP_MODE                                     = 0x00000BF0;
    public final static int GL_LOSE_CONTEXT_ON_RESET_ARB                         = 0x00008252;
    public final static int GL_LOWER_LEFT                                        = 0x00008CA1;
    public final static int GL_LOW_FLOAT                                         = 0x00008DF0;
    public final static int GL_LOW_INT                                           = 0x00008DF3;
    public final static int GL_MAJOR_VERSION                                     = 0x0000821B;
    public final static int GL_MAP_FLUSH_EXPLICIT_BIT                            = 0x00000010;
    public final static int GL_MAP_INVALIDATE_BUFFER_BIT                         = 0x00000008;
    public final static int GL_MAP_INVALIDATE_RANGE_BIT                          = 0x00000004;
    public final static int GL_MAP_READ_BIT                                      = 0x00000001;
    public final static int GL_MAP_UNSYNCHRONIZED_BIT                            = 0x00000020;
    public final static int GL_MAP_WRITE_BIT                                     = 0x00000002;
    public final static int GL_MAX                                               = 0x00008008;
    public final static int GL_MAX_3D_TEXTURE_SIZE                               = 0x00008073;
    public final static int GL_MAX_ARRAY_TEXTURE_LAYERS                          = 0x000088FF;
    public final static int GL_MAX_CLIP_DISTANCES                                = 0x00000D32;
    public final static int GL_MAX_COLOR_ATTACHMENTS                             = 0x00008CDF;
    public final static int GL_MAX_COLOR_TEXTURE_SAMPLES                         = 0x0000910E;
    public final static int GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS          = 0x00008A33;
    public final static int GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS          = 0x00008A32;
    public final static int GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS      = 0x00008E1E;
    public final static int GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS   = 0x00008E1F;
    public final static int GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS                  = 0x00008B4D;
    public final static int GL_MAX_COMBINED_UNIFORM_BLOCKS                       = 0x00008A2E;
    public final static int GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS            = 0x00008A31;
    public final static int GL_MAX_CUBE_MAP_TEXTURE_SIZE                         = 0x0000851C;
    public final static int GL_MAX_DEBUG_LOGGED_MESSAGES_ARB                     = 0x00009144;
    public final static int GL_MAX_DEBUG_MESSAGE_LENGTH_ARB                      = 0x00009143;
    public final static int GL_MAX_DEPTH_TEXTURE_SAMPLES                         = 0x0000910F;
    public final static int GL_MAX_DRAW_BUFFERS                                  = 0x00008824;
    public final static int GL_MAX_DUAL_SOURCE_DRAW_BUFFERS                      = 0x000088FC;
    public final static int GL_MAX_ELEMENTS_INDICES                              = 0x000080E9;
    public final static int GL_MAX_ELEMENTS_VERTICES                             = 0x000080E8;
    public final static int GL_MAX_FRAGMENT_INPUT_COMPONENTS                     = 0x00009125;
    public final static int GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                 = 0x00008E5C;
    public final static int GL_MAX_FRAGMENT_UNIFORM_BLOCKS                       = 0x00008A2D;
    public final static int GL_MAX_FRAGMENT_UNIFORM_COMPONENTS                   = 0x00008B49;
    public final static int GL_MAX_FRAGMENT_UNIFORM_VECTORS                      = 0x00008DFD;
    public final static int GL_MAX_GEOMETRY_INPUT_COMPONENTS                     = 0x00009123;
    public final static int GL_MAX_GEOMETRY_OUTPUT_COMPONENTS                    = 0x00009124;
    public final static int GL_MAX_GEOMETRY_OUTPUT_VERTICES                      = 0x00008DE0;
    public final static int GL_MAX_GEOMETRY_SHADER_INVOCATIONS                   = 0x00008E5A;
    public final static int GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS                  = 0x00008C29;
    public final static int GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS              = 0x00008DE1;
    public final static int GL_MAX_GEOMETRY_UNIFORM_BLOCKS                       = 0x00008A2C;
    public final static int GL_MAX_GEOMETRY_UNIFORM_COMPONENTS                   = 0x00008DDF;
    public final static int GL_MAX_INTEGER_SAMPLES                               = 0x00009110;
    public final static int GL_MAX_PATCH_VERTICES                                = 0x00008E7D;
    public final static int GL_MAX_PROGRAM_TEXEL_OFFSET                          = 0x00008905;
    public final static int GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET                 = 0x00008E5F;
    public final static int GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB             = 0x00008E5F;
    public final static int GL_MAX_RECTANGLE_TEXTURE_SIZE                        = 0x000084F8;
    public final static int GL_MAX_RENDERBUFFER_SIZE                             = 0x000084E8;
    public final static int GL_MAX_SAMPLES                                       = 0x00008D57;
    public final static int GL_MAX_SAMPLE_MASK_WORDS                             = 0x00008E59;
    public final static int GL_MAX_SERVER_WAIT_TIMEOUT                           = 0x00009111;
    public final static int GL_MAX_SUBROUTINES                                   = 0x00008DE7;
    public final static int GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                  = 0x00008DE8;
    public final static int GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                 = 0x0000886C;
    public final static int GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS                = 0x00008E83;
    public final static int GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS              = 0x00008E81;
    public final static int GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS          = 0x00008E85;
    public final static int GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                   = 0x00008E89;
    public final static int GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS               = 0x00008E7F;
    public final static int GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS              = 0x0000886D;
    public final static int GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS             = 0x00008E86;
    public final static int GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS           = 0x00008E82;
    public final static int GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS                = 0x00008E8A;
    public final static int GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS            = 0x00008E80;
    public final static int GL_MAX_TESS_GEN_LEVEL                                = 0x00008E7E;
    public final static int GL_MAX_TESS_PATCH_COMPONENTS                         = 0x00008E84;
    public final static int GL_MAX_TEXTURE_BUFFER_SIZE                           = 0x00008C2B;
    public final static int GL_MAX_TEXTURE_IMAGE_UNITS                           = 0x00008872;
    public final static int GL_MAX_TEXTURE_LOD_BIAS                              = 0x000084FD;
    public final static int GL_MAX_TEXTURE_SIZE                                  = 0x00000D33;
    public final static int GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                    = 0x00008E70;
    public final static int GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS     = 0x00008C8A;
    public final static int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS           = 0x00008C8B;
    public final static int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS        = 0x00008C80;
    public final static int GL_MAX_UNIFORM_BLOCK_SIZE                            = 0x00008A30;
    public final static int GL_MAX_UNIFORM_BUFFER_BINDINGS                       = 0x00008A2F;
    public final static int GL_MAX_VARYING_COMPONENTS                            = 0x00008B4B;
    public final static int GL_MAX_VARYING_FLOATS                                = 0x00008B4B;
    public final static int GL_MAX_VARYING_VECTORS                               = 0x00008DFC;
    public final static int GL_MAX_VERTEX_ATTRIBS                                = 0x00008869;
    public final static int GL_MAX_VERTEX_OUTPUT_COMPONENTS                      = 0x00009122;
    public final static int GL_MAX_VERTEX_STREAMS                                = 0x00008E71;
    public final static int GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                    = 0x00008B4C;
    public final static int GL_MAX_VERTEX_UNIFORM_BLOCKS                         = 0x00008A2B;
    public final static int GL_MAX_VERTEX_UNIFORM_COMPONENTS                     = 0x00008B4A;
    public final static int GL_MAX_VERTEX_UNIFORM_VECTORS                        = 0x00008DFB;
    public final static int GL_MAX_VIEWPORTS                                     = 0x0000825B;
    public final static int GL_MAX_VIEWPORT_DIMS                                 = 0x00000D3A;
    public final static int GL_MEDIUM_FLOAT                                      = 0x00008DF1;
    public final static int GL_MEDIUM_INT                                        = 0x00008DF4;
    public final static int GL_MIN                                               = 0x00008007;
    public final static int GL_MINOR_VERSION                                     = 0x0000821C;
    public final static int GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                 = 0x00008E5B;
    public final static int GL_MIN_PROGRAM_TEXEL_OFFSET                          = 0x00008904;
    public final static int GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET                 = 0x00008E5E;
    public final static int GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB             = 0x00008E5E;
    public final static int GL_MIN_SAMPLE_SHADING_VALUE                          = 0x00008C37;
    public final static int GL_MIN_SAMPLE_SHADING_VALUE_ARB                      = 0x00008C37;
    public final static int GL_MIRRORED_REPEAT                                   = 0x00008370;
    public final static int GL_MULTISAMPLE                                       = 0x0000809D;
    public final static int GL_NAMED_STRING_LENGTH_ARB                           = 0x00008DE9;
    public final static int GL_NAMED_STRING_TYPE_ARB                             = 0x00008DEA;
    public final static int GL_NAND                                              = 0x0000150E;
    public final static int GL_NEAREST                                           = 0x00002600;
    public final static int GL_NEAREST_MIPMAP_LINEAR                             = 0x00002702;
    public final static int GL_NEAREST_MIPMAP_NEAREST                            = 0x00002700;
    public final static int GL_NEVER                                             = 0x00000200;
    public final static int GL_NICEST                                            = 0x00001102;
    public final static int GL_NONE                                              = 0x00000000;
    public final static int GL_NOOP                                              = 0x00001505;
    public final static int GL_NOR                                               = 0x00001508;
    public final static int GL_NOTEQUAL                                          = 0x00000205;
    public final static int GL_NO_ERROR                                          = 0x00000000;
    public final static int GL_NO_RESET_NOTIFICATION_ARB                         = 0x00008261;
    public final static int GL_NUM_COMPATIBLE_SUBROUTINES                        = 0x00008E4A;
    public final static int GL_NUM_COMPRESSED_TEXTURE_FORMATS                    = 0x000086A2;
    public final static int GL_NUM_EXTENSIONS                                    = 0x0000821D;
    public final static int GL_NUM_PROGRAM_BINARY_FORMATS                        = 0x000087FE;
    public final static int GL_NUM_SHADER_BINARY_FORMATS                         = 0x00008DF9;
    public final static int GL_OBJECT_TYPE                                       = 0x00009112;
    public final static int GL_ONE                                               = 0x00000001;
    public final static int GL_ONE_MINUS_CONSTANT_ALPHA                          = 0x00008004;
    public final static int GL_ONE_MINUS_CONSTANT_COLOR                          = 0x00008002;
    public final static int GL_ONE_MINUS_DST_ALPHA                               = 0x00000305;
    public final static int GL_ONE_MINUS_DST_COLOR                               = 0x00000307;
    public final static int GL_ONE_MINUS_SRC1_ALPHA                              = 0x000088FB;
    public final static int GL_ONE_MINUS_SRC1_COLOR                              = 0x000088FA;
    public final static int GL_ONE_MINUS_SRC_ALPHA                               = 0x00000303;
    public final static int GL_ONE_MINUS_SRC_COLOR                               = 0x00000301;
    public final static int GL_OR                                                = 0x00001507;
    public final static int GL_OR_INVERTED                                       = 0x0000150D;
    public final static int GL_OR_REVERSE                                        = 0x0000150B;
    public final static int GL_OUT_OF_MEMORY                                     = 0x00000505;
    public final static int GL_PACK_ALIGNMENT                                    = 0x00000D05;
    public final static int GL_PACK_IMAGE_HEIGHT                                 = 0x0000806C;
    public final static int GL_PACK_LSB_FIRST                                    = 0x00000D01;
    public final static int GL_PACK_ROW_LENGTH                                   = 0x00000D02;
    public final static int GL_PACK_SKIP_IMAGES                                  = 0x0000806B;
    public final static int GL_PACK_SKIP_PIXELS                                  = 0x00000D04;
    public final static int GL_PACK_SKIP_ROWS                                    = 0x00000D03;
    public final static int GL_PACK_SWAP_BYTES                                   = 0x00000D00;
    public final static int GL_PATCHES                                           = 0x0000000E;
    public final static int GL_PATCH_DEFAULT_INNER_LEVEL                         = 0x00008E73;
    public final static int GL_PATCH_DEFAULT_OUTER_LEVEL                         = 0x00008E74;
    public final static int GL_PATCH_VERTICES                                    = 0x00008E72;
    public final static int GL_PIXEL_PACK_BUFFER                                 = 0x000088EB;
    public final static int GL_PIXEL_PACK_BUFFER_BINDING                         = 0x000088ED;
    public final static int GL_PIXEL_UNPACK_BUFFER                               = 0x000088EC;
    public final static int GL_PIXEL_UNPACK_BUFFER_BINDING                       = 0x000088EF;
    public final static int GL_POINT                                             = 0x00001B00;
    public final static int GL_POINTS                                            = 0x00000000;
    public final static int GL_POINT_FADE_THRESHOLD_SIZE                         = 0x00008128;
    public final static int GL_POINT_SIZE                                        = 0x00000B11;
    public final static int GL_POINT_SIZE_GRANULARITY                            = 0x00000B13;
    public final static int GL_POINT_SIZE_RANGE                                  = 0x00000B12;
    public final static int GL_POINT_SPRITE_COORD_ORIGIN                         = 0x00008CA0;
    public final static int GL_POLYGON_OFFSET_FACTOR                             = 0x00008038;
    public final static int GL_POLYGON_OFFSET_FILL                               = 0x00008037;
    public final static int GL_POLYGON_OFFSET_LINE                               = 0x00002A02;
    public final static int GL_POLYGON_OFFSET_POINT                              = 0x00002A01;
    public final static int GL_POLYGON_OFFSET_UNITS                              = 0x00002A00;
    public final static int GL_POLYGON_SMOOTH                                    = 0x00000B41;
    public final static int GL_POLYGON_SMOOTH_HINT                               = 0x00000C53;
    public final static int GL_PRIMITIVES_GENERATED                              = 0x00008C87;
    public final static int GL_PRIMITIVE_RESTART                                 = 0x00008F9D;
    public final static int GL_PRIMITIVE_RESTART_INDEX                           = 0x00008F9E;
    public final static int GL_PROGRAM_BINARY_FORMATS                            = 0x000087FF;
    public final static int GL_PROGRAM_BINARY_LENGTH                             = 0x00008741;
    public final static int GL_PROGRAM_BINARY_RETRIEVABLE_HINT                   = 0x00008257;
    public final static int GL_PROGRAM_PIPELINE_BINDING                          = 0x0000825A;
    public final static int GL_PROGRAM_POINT_SIZE                                = 0x00008642;
    public final static int GL_PROGRAM_SEPARABLE                                 = 0x00008258;
    public final static int GL_PROVOKING_VERTEX                                  = 0x00008E4F;
    public final static int GL_PROXY_TEXTURE_1D                                  = 0x00008063;
    public final static int GL_PROXY_TEXTURE_1D_ARRAY                            = 0x00008C19;
    public final static int GL_PROXY_TEXTURE_2D                                  = 0x00008064;
    public final static int GL_PROXY_TEXTURE_2D_ARRAY                            = 0x00008C1B;
    public final static int GL_PROXY_TEXTURE_2D_MULTISAMPLE                      = 0x00009101;
    public final static int GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY                = 0x00009103;
    public final static int GL_PROXY_TEXTURE_3D                                  = 0x00008070;
    public final static int GL_PROXY_TEXTURE_CUBE_MAP                            = 0x0000851B;
    public final static int GL_PROXY_TEXTURE_CUBE_MAP_ARRAY                      = 0x0000900B;
    public final static int GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB                  = 0x0000900B;
    public final static int GL_PROXY_TEXTURE_RECTANGLE                           = 0x000084F7;
    public final static int GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION          = 0x00008E4C;
    public final static int GL_QUERY_BY_REGION_NO_WAIT                           = 0x00008E16;
    public final static int GL_QUERY_BY_REGION_WAIT                              = 0x00008E15;
    public final static int GL_QUERY_COUNTER_BITS                                = 0x00008864;
    public final static int GL_QUERY_NO_WAIT                                     = 0x00008E14;
    public final static int GL_QUERY_RESULT                                      = 0x00008866;
    public final static int GL_QUERY_RESULT_AVAILABLE                            = 0x00008867;
    public final static int GL_QUERY_WAIT                                        = 0x00008E13;
    public final static int GL_R11F_G11F_B10F                                    = 0x00008C3A;
    public final static int GL_R16                                               = 0x0000822A;
    public final static int GL_R16F                                              = 0x0000822D;
    public final static int GL_R16I                                              = 0x00008233;
    public final static int GL_R16UI                                             = 0x00008234;
    public final static int GL_R16_SNORM                                         = 0x00008F98;
    public final static int GL_R32F                                              = 0x0000822E;
    public final static int GL_R32I                                              = 0x00008235;
    public final static int GL_R32UI                                             = 0x00008236;
    public final static int GL_R3_G3_B2                                          = 0x00002A10;
    public final static int GL_R8                                                = 0x00008229;
    public final static int GL_R8I                                               = 0x00008231;
    public final static int GL_R8UI                                              = 0x00008232;
    public final static int GL_R8_SNORM                                          = 0x00008F94;
    public final static int GL_RASTERIZER_DISCARD                                = 0x00008C89;
    public final static int GL_READ_BUFFER                                       = 0x00000C02;
    public final static int GL_READ_FRAMEBUFFER                                  = 0x00008CA8;
    public final static int GL_READ_FRAMEBUFFER_BINDING                          = 0x00008CAA;
    public final static int GL_READ_ONLY                                         = 0x000088B8;
    public final static int GL_READ_WRITE                                        = 0x000088BA;
    public final static int GL_RED                                               = 0x00001903;
    public final static int GL_RED_INTEGER                                       = 0x00008D94;
    public final static int GL_RED_SNORM                                         = 0x00008F90;
    public final static int GL_RENDERBUFFER                                      = 0x00008D41;
    public final static int GL_RENDERBUFFER_ALPHA_SIZE                           = 0x00008D53;
    public final static int GL_RENDERBUFFER_BINDING                              = 0x00008CA7;
    public final static int GL_RENDERBUFFER_BLUE_SIZE                            = 0x00008D52;
    public final static int GL_RENDERBUFFER_DEPTH_SIZE                           = 0x00008D54;
    public final static int GL_RENDERBUFFER_GREEN_SIZE                           = 0x00008D51;
    public final static int GL_RENDERBUFFER_HEIGHT                               = 0x00008D43;
    public final static int GL_RENDERBUFFER_INTERNAL_FORMAT                      = 0x00008D44;
    public final static int GL_RENDERBUFFER_RED_SIZE                             = 0x00008D50;
    public final static int GL_RENDERBUFFER_SAMPLES                              = 0x00008CAB;
    public final static int GL_RENDERBUFFER_STENCIL_SIZE                         = 0x00008D55;
    public final static int GL_RENDERBUFFER_WIDTH                                = 0x00008D42;
    public final static int GL_RENDERER                                          = 0x00001F01;
    public final static int GL_REPEAT                                            = 0x00002901;
    public final static int GL_REPLACE                                           = 0x00001E01;
    public final static int GL_RESET_NOTIFICATION_STRATEGY_ARB                   = 0x00008256;
    public final static int GL_RG                                                = 0x00008227;
    public final static int GL_RG16                                              = 0x0000822C;
    public final static int GL_RG16F                                             = 0x0000822F;
    public final static int GL_RG16I                                             = 0x00008239;
    public final static int GL_RG16UI                                            = 0x0000823A;
    public final static int GL_RG16_SNORM                                        = 0x00008F99;
    public final static int GL_RG32F                                             = 0x00008230;
    public final static int GL_RG32I                                             = 0x0000823B;
    public final static int GL_RG32UI                                            = 0x0000823C;
    public final static int GL_RG8                                               = 0x0000822B;
    public final static int GL_RG8I                                              = 0x00008237;
    public final static int GL_RG8UI                                             = 0x00008238;
    public final static int GL_RG8_SNORM                                         = 0x00008F95;
    public final static int GL_RGB                                               = 0x00001907;
    public final static int GL_RGB10                                             = 0x00008052;
    public final static int GL_RGB10_A2                                          = 0x00008059;
    public final static int GL_RGB10_A2UI                                        = 0x0000906F;
    public final static int GL_RGB12                                             = 0x00008053;
    public final static int GL_RGB16                                             = 0x00008054;
    public final static int GL_RGB16F                                            = 0x0000881B;
    public final static int GL_RGB16I                                            = 0x00008D89;
    public final static int GL_RGB16UI                                           = 0x00008D77;
    public final static int GL_RGB16_SNORM                                       = 0x00008F9A;
    public final static int GL_RGB32F                                            = 0x00008815;
    public final static int GL_RGB32I                                            = 0x00008D83;
    public final static int GL_RGB32UI                                           = 0x00008D71;
    public final static int GL_RGB4                                              = 0x0000804F;
    public final static int GL_RGB5                                              = 0x00008050;
    public final static int GL_RGB5_A1                                           = 0x00008057;
    public final static int GL_RGB8                                              = 0x00008051;
    public final static int GL_RGB8I                                             = 0x00008D8F;
    public final static int GL_RGB8UI                                            = 0x00008D7D;
    public final static int GL_RGB8_SNORM                                        = 0x00008F96;
    public final static int GL_RGB9_E5                                           = 0x00008C3D;
    public final static int GL_RGBA                                              = 0x00001908;
    public final static int GL_RGBA12                                            = 0x0000805A;
    public final static int GL_RGBA16                                            = 0x0000805B;
    public final static int GL_RGBA16F                                           = 0x0000881A;
    public final static int GL_RGBA16I                                           = 0x00008D88;
    public final static int GL_RGBA16UI                                          = 0x00008D76;
    public final static int GL_RGBA16_SNORM                                      = 0x00008F9B;
    public final static int GL_RGBA2                                             = 0x00008055;
    public final static int GL_RGBA32F                                           = 0x00008814;
    public final static int GL_RGBA32I                                           = 0x00008D82;
    public final static int GL_RGBA32UI                                          = 0x00008D70;
    public final static int GL_RGBA4                                             = 0x00008056;
    public final static int GL_RGBA8                                             = 0x00008058;
    public final static int GL_RGBA8I                                            = 0x00008D8E;
    public final static int GL_RGBA8UI                                           = 0x00008D7C;
    public final static int GL_RGBA8_SNORM                                       = 0x00008F97;
    public final static int GL_RGBA_INTEGER                                      = 0x00008D99;
    public final static int GL_RGBA_SNORM                                        = 0x00008F93;
    public final static int GL_RGB_INTEGER                                       = 0x00008D98;
    public final static int GL_RGB_SNORM                                         = 0x00008F92;
    public final static int GL_RG_INTEGER                                        = 0x00008228;
    public final static int GL_RG_SNORM                                          = 0x00008F91;
    public final static int GL_RIGHT                                             = 0x00000407;
    public final static int GL_SAMPLER_1D                                        = 0x00008B5D;
    public final static int GL_SAMPLER_1D_ARRAY                                  = 0x00008DC0;
    public final static int GL_SAMPLER_1D_ARRAY_SHADOW                           = 0x00008DC3;
    public final static int GL_SAMPLER_1D_SHADOW                                 = 0x00008B61;
    public final static int GL_SAMPLER_2D                                        = 0x00008B5E;
    public final static int GL_SAMPLER_2D_ARRAY                                  = 0x00008DC1;
    public final static int GL_SAMPLER_2D_ARRAY_SHADOW                           = 0x00008DC4;
    public final static int GL_SAMPLER_2D_MULTISAMPLE                            = 0x00009108;
    public final static int GL_SAMPLER_2D_MULTISAMPLE_ARRAY                      = 0x0000910B;
    public final static int GL_SAMPLER_2D_RECT                                   = 0x00008B63;
    public final static int GL_SAMPLER_2D_RECT_SHADOW                            = 0x00008B64;
    public final static int GL_SAMPLER_2D_SHADOW                                 = 0x00008B62;
    public final static int GL_SAMPLER_3D                                        = 0x00008B5F;
    public final static int GL_SAMPLER_BINDING                                   = 0x00008919;
    public final static int GL_SAMPLER_BUFFER                                    = 0x00008DC2;
    public final static int GL_SAMPLER_CUBE                                      = 0x00008B60;
    public final static int GL_SAMPLER_CUBE_MAP_ARRAY                            = 0x0000900C;
    public final static int GL_SAMPLER_CUBE_MAP_ARRAY_ARB                        = 0x0000900C;
    public final static int GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                     = 0x0000900D;
    public final static int GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB                 = 0x0000900D;
    public final static int GL_SAMPLER_CUBE_SHADOW                               = 0x00008DC5;
    public final static int GL_SAMPLES                                           = 0x000080A9;
    public final static int GL_SAMPLES_PASSED                                    = 0x00008914;
    public final static int GL_SAMPLE_ALPHA_TO_COVERAGE                          = 0x0000809E;
    public final static int GL_SAMPLE_ALPHA_TO_ONE                               = 0x0000809F;
    public final static int GL_SAMPLE_BUFFERS                                    = 0x000080A8;
    public final static int GL_SAMPLE_COVERAGE                                   = 0x000080A0;
    public final static int GL_SAMPLE_COVERAGE_INVERT                            = 0x000080AB;
    public final static int GL_SAMPLE_COVERAGE_VALUE                             = 0x000080AA;
    public final static int GL_SAMPLE_MASK                                       = 0x00008E51;
    public final static int GL_SAMPLE_MASK_VALUE                                 = 0x00008E52;
    public final static int GL_SAMPLE_POSITION                                   = 0x00008E50;
    public final static int GL_SAMPLE_SHADING                                    = 0x00008C36;
    public final static int GL_SAMPLE_SHADING_ARB                                = 0x00008C36;
    public final static int GL_SCISSOR_BOX                                       = 0x00000C10;
    public final static int GL_SCISSOR_TEST                                      = 0x00000C11;
    public final static int GL_SEPARATE_ATTRIBS                                  = 0x00008C8D;
    public final static int GL_SET                                               = 0x0000150F;
    public final static int GL_SHADER_COMPILER                                   = 0x00008DFA;
    public final static int GL_SHADER_INCLUDE_ARB                                = 0x00008DAE;
    public final static int GL_SHADER_SOURCE_LENGTH                              = 0x00008B88;
    public final static int GL_SHADER_TYPE                                       = 0x00008B4F;
    public final static int GL_SHADING_LANGUAGE_VERSION                          = 0x00008B8C;
    public final static int GL_SHORT                                             = 0x00001402;
    public final static int GL_SIGNALED                                          = 0x00009119;
    public final static int GL_SIGNED_NORMALIZED                                 = 0x00008F9C;
    public final static int GL_SMOOTH_LINE_WIDTH_GRANULARITY                     = 0x00000B23;
    public final static int GL_SMOOTH_LINE_WIDTH_RANGE                           = 0x00000B22;
    public final static int GL_SMOOTH_POINT_SIZE_GRANULARITY                     = 0x00000B13;
    public final static int GL_SMOOTH_POINT_SIZE_RANGE                           = 0x00000B12;
    public final static int GL_SRC1_COLOR                                        = 0x000088F9;
    public final static int GL_SRC_ALPHA                                         = 0x00000302;
    public final static int GL_SRC_ALPHA_SATURATE                                = 0x00000308;
    public final static int GL_SRC_COLOR                                         = 0x00000300;
    public final static int GL_SRGB                                              = 0x00008C40;
    public final static int GL_SRGB8                                             = 0x00008C41;
    public final static int GL_SRGB8_ALPHA8                                      = 0x00008C43;
    public final static int GL_SRGB_ALPHA                                        = 0x00008C42;
    public final static int GL_STATIC_COPY                                       = 0x000088E6;
    public final static int GL_STATIC_DRAW                                       = 0x000088E4;
    public final static int GL_STATIC_READ                                       = 0x000088E5;
    public final static int GL_STENCIL                                           = 0x00001802;
    public final static int GL_STENCIL_ATTACHMENT                                = 0x00008D20;
    public final static int GL_STENCIL_BACK_FAIL                                 = 0x00008801;
    public final static int GL_STENCIL_BACK_FUNC                                 = 0x00008800;
    public final static int GL_STENCIL_BACK_PASS_DEPTH_FAIL                      = 0x00008802;
    public final static int GL_STENCIL_BACK_PASS_DEPTH_PASS                      = 0x00008803;
    public final static int GL_STENCIL_BACK_REF                                  = 0x00008CA3;
    public final static int GL_STENCIL_BACK_VALUE_MASK                           = 0x00008CA4;
    public final static int GL_STENCIL_BACK_WRITEMASK                            = 0x00008CA5;
    public final static int GL_STENCIL_BUFFER                                    = 0x00008224;
    public final static int GL_STENCIL_BUFFER_BIT                                = 0x00000400;
    public final static int GL_STENCIL_CLEAR_VALUE                               = 0x00000B91;
    public final static int GL_STENCIL_FAIL                                      = 0x00000B94;
    public final static int GL_STENCIL_FUNC                                      = 0x00000B92;
    public final static int GL_STENCIL_INDEX                                     = 0x00001901;
    public final static int GL_STENCIL_INDEX1                                    = 0x00008D46;
    public final static int GL_STENCIL_INDEX16                                   = 0x00008D49;
    public final static int GL_STENCIL_INDEX4                                    = 0x00008D47;
    public final static int GL_STENCIL_INDEX8                                    = 0x00008D48;
    public final static int GL_STENCIL_PASS_DEPTH_FAIL                           = 0x00000B95;
    public final static int GL_STENCIL_PASS_DEPTH_PASS                           = 0x00000B96;
    public final static int GL_STENCIL_REF                                       = 0x00000B97;
    public final static int GL_STENCIL_TEST                                      = 0x00000B90;
    public final static int GL_STENCIL_VALUE_MASK                                = 0x00000B93;
    public final static int GL_STENCIL_WRITEMASK                                 = 0x00000B98;
    public final static int GL_STEREO                                            = 0x00000C33;
    public final static int GL_STREAM_COPY                                       = 0x000088E2;
    public final static int GL_STREAM_DRAW                                       = 0x000088E0;
    public final static int GL_STREAM_READ                                       = 0x000088E1;
    public final static int GL_SUBPIXEL_BITS                                     = 0x00000D50;
    public final static int GL_SYNC_CL_EVENT_ARB                                 = 0x00008240;
    public final static int GL_SYNC_CL_EVENT_COMPLETE_ARB                        = 0x00008241;
    public final static int GL_SYNC_CONDITION                                    = 0x00009113;
    public final static int GL_SYNC_FENCE                                        = 0x00009116;
    public final static int GL_SYNC_FLAGS                                        = 0x00009115;
    public final static int GL_SYNC_FLUSH_COMMANDS_BIT                           = 0x00000001;
    public final static int GL_SYNC_GPU_COMMANDS_COMPLETE                        = 0x00009117;
    public final static int GL_SYNC_STATUS                                       = 0x00009114;
    public final static int GL_TESS_CONTROL_OUTPUT_VERTICES                      = 0x00008E75;
    public final static int GL_TESS_CONTROL_SHADER                               = 0x00008E88;
    public final static int GL_TESS_CONTROL_SHADER_BIT                           = 0x00000008;
    public final static int GL_TESS_EVALUATION_SHADER                            = 0x00008E87;
    public final static int GL_TESS_EVALUATION_SHADER_BIT                        = 0x00000010;
    public final static int GL_TESS_GEN_MODE                                     = 0x00008E76;
    public final static int GL_TESS_GEN_POINT_MODE                               = 0x00008E79;
    public final static int GL_TESS_GEN_SPACING                                  = 0x00008E77;
    public final static int GL_TESS_GEN_VERTEX_ORDER                             = 0x00008E78;
    public final static int GL_TEXTURE                                           = 0x00001702;
    public final static int GL_TEXTURE0                                          = 0x000084C0;
    public final static int GL_TEXTURE1                                          = 0x000084C1;
    public final static int GL_TEXTURE10                                         = 0x000084CA;
    public final static int GL_TEXTURE11                                         = 0x000084CB;
    public final static int GL_TEXTURE12                                         = 0x000084CC;
    public final static int GL_TEXTURE13                                         = 0x000084CD;
    public final static int GL_TEXTURE14                                         = 0x000084CE;
    public final static int GL_TEXTURE15                                         = 0x000084CF;
    public final static int GL_TEXTURE16                                         = 0x000084D0;
    public final static int GL_TEXTURE17                                         = 0x000084D1;
    public final static int GL_TEXTURE18                                         = 0x000084D2;
    public final static int GL_TEXTURE19                                         = 0x000084D3;
    public final static int GL_TEXTURE2                                          = 0x000084C2;
    public final static int GL_TEXTURE20                                         = 0x000084D4;
    public final static int GL_TEXTURE21                                         = 0x000084D5;
    public final static int GL_TEXTURE22                                         = 0x000084D6;
    public final static int GL_TEXTURE23                                         = 0x000084D7;
    public final static int GL_TEXTURE24                                         = 0x000084D8;
    public final static int GL_TEXTURE25                                         = 0x000084D9;
    public final static int GL_TEXTURE26                                         = 0x000084DA;
    public final static int GL_TEXTURE27                                         = 0x000084DB;
    public final static int GL_TEXTURE28                                         = 0x000084DC;
    public final static int GL_TEXTURE29                                         = 0x000084DD;
    public final static int GL_TEXTURE3                                          = 0x000084C3;
    public final static int GL_TEXTURE30                                         = 0x000084DE;
    public final static int GL_TEXTURE31                                         = 0x000084DF;
    public final static int GL_TEXTURE4                                          = 0x000084C4;
    public final static int GL_TEXTURE5                                          = 0x000084C5;
    public final static int GL_TEXTURE6                                          = 0x000084C6;
    public final static int GL_TEXTURE7                                          = 0x000084C7;
    public final static int GL_TEXTURE8                                          = 0x000084C8;
    public final static int GL_TEXTURE9                                          = 0x000084C9;
    public final static int GL_TEXTURE_1D                                        = 0x00000DE0;
    public final static int GL_TEXTURE_1D_ARRAY                                  = 0x00008C18;
    public final static int GL_TEXTURE_2D                                        = 0x00000DE1;
    public final static int GL_TEXTURE_2D_ARRAY                                  = 0x00008C1A;
    public final static int GL_TEXTURE_2D_MULTISAMPLE                            = 0x00009100;
    public final static int GL_TEXTURE_2D_MULTISAMPLE_ARRAY                      = 0x00009102;
    public final static int GL_TEXTURE_3D                                        = 0x0000806F;
    public final static int GL_TEXTURE_ALPHA_SIZE                                = 0x0000805F;
    public final static int GL_TEXTURE_ALPHA_TYPE                                = 0x00008C13;
    public final static int GL_TEXTURE_BASE_LEVEL                                = 0x0000813C;
    public final static int GL_TEXTURE_BINDING_1D                                = 0x00008068;
    public final static int GL_TEXTURE_BINDING_1D_ARRAY                          = 0x00008C1C;
    public final static int GL_TEXTURE_BINDING_2D                                = 0x00008069;
    public final static int GL_TEXTURE_BINDING_2D_ARRAY                          = 0x00008C1D;
    public final static int GL_TEXTURE_BINDING_2D_MULTISAMPLE                    = 0x00009104;
    public final static int GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY              = 0x00009105;
    public final static int GL_TEXTURE_BINDING_3D                                = 0x0000806A;
    public final static int GL_TEXTURE_BINDING_BUFFER                            = 0x00008C2C;
    public final static int GL_TEXTURE_BINDING_CUBE_MAP                          = 0x00008514;
    public final static int GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                    = 0x0000900A;
    public final static int GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB                = 0x0000900A;
    public final static int GL_TEXTURE_BINDING_RECTANGLE                         = 0x000084F6;
    public final static int GL_TEXTURE_BLUE_SIZE                                 = 0x0000805E;
    public final static int GL_TEXTURE_BLUE_TYPE                                 = 0x00008C12;
    public final static int GL_TEXTURE_BORDER_COLOR                              = 0x00001004;
    public final static int GL_TEXTURE_BUFFER                                    = 0x00008C2A;
    public final static int GL_TEXTURE_BUFFER_DATA_STORE_BINDING                 = 0x00008C2D;
    public final static int GL_TEXTURE_BUFFER_FORMAT                             = 0x00008C2E;
    public final static int GL_TEXTURE_COMPARE_FUNC                              = 0x0000884D;
    public final static int GL_TEXTURE_COMPARE_MODE                              = 0x0000884C;
    public final static int GL_TEXTURE_COMPRESSED                                = 0x000086A1;
    public final static int GL_TEXTURE_COMPRESSED_IMAGE_SIZE                     = 0x000086A0;
    public final static int GL_TEXTURE_COMPRESSION_HINT                          = 0x000084EF;
    public final static int GL_TEXTURE_CUBE_MAP                                  = 0x00008513;
    public final static int GL_TEXTURE_CUBE_MAP_ARRAY                            = 0x00009009;
    public final static int GL_TEXTURE_CUBE_MAP_ARRAY_ARB                        = 0x00009009;
    public final static int GL_TEXTURE_CUBE_MAP_NEGATIVE_X                       = 0x00008516;
    public final static int GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                       = 0x00008518;
    public final static int GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                       = 0x0000851A;
    public final static int GL_TEXTURE_CUBE_MAP_POSITIVE_X                       = 0x00008515;
    public final static int GL_TEXTURE_CUBE_MAP_POSITIVE_Y                       = 0x00008517;
    public final static int GL_TEXTURE_CUBE_MAP_POSITIVE_Z                       = 0x00008519;
    public final static int GL_TEXTURE_CUBE_MAP_SEAMLESS                         = 0x0000884F;
    public final static int GL_TEXTURE_DEPTH                                     = 0x00008071;
    public final static int GL_TEXTURE_DEPTH_SIZE                                = 0x0000884A;
    public final static int GL_TEXTURE_DEPTH_TYPE                                = 0x00008C16;
    public final static int GL_TEXTURE_FIXED_SAMPLE_LOCATIONS                    = 0x00009107;
    public final static int GL_TEXTURE_GREEN_SIZE                                = 0x0000805D;
    public final static int GL_TEXTURE_GREEN_TYPE                                = 0x00008C11;
    public final static int GL_TEXTURE_HEIGHT                                    = 0x00001001;
    public final static int GL_TEXTURE_INTERNAL_FORMAT                           = 0x00001003;
    public final static int GL_TEXTURE_LOD_BIAS                                  = 0x00008501;
    public final static int GL_TEXTURE_MAG_FILTER                                = 0x00002800;
    public final static int GL_TEXTURE_MAX_LEVEL                                 = 0x0000813D;
    public final static int GL_TEXTURE_MAX_LOD                                   = 0x0000813B;
    public final static int GL_TEXTURE_MIN_FILTER                                = 0x00002801;
    public final static int GL_TEXTURE_MIN_LOD                                   = 0x0000813A;
    public final static int GL_TEXTURE_RECTANGLE                                 = 0x000084F5;
    public final static int GL_TEXTURE_RED_SIZE                                  = 0x0000805C;
    public final static int GL_TEXTURE_RED_TYPE                                  = 0x00008C10;
    public final static int GL_TEXTURE_SAMPLES                                   = 0x00009106;
    public final static int GL_TEXTURE_SHARED_SIZE                               = 0x00008C3F;
    public final static int GL_TEXTURE_STENCIL_SIZE                              = 0x000088F1;
    public final static int GL_TEXTURE_SWIZZLE_A                                 = 0x00008E45;
    public final static int GL_TEXTURE_SWIZZLE_B                                 = 0x00008E44;
    public final static int GL_TEXTURE_SWIZZLE_G                                 = 0x00008E43;
    public final static int GL_TEXTURE_SWIZZLE_R                                 = 0x00008E42;
    public final static int GL_TEXTURE_SWIZZLE_RGBA                              = 0x00008E46;
    public final static int GL_TEXTURE_WIDTH                                     = 0x00001000;
    public final static int GL_TEXTURE_WRAP_R                                    = 0x00008072;
    public final static int GL_TEXTURE_WRAP_S                                    = 0x00002802;
    public final static int GL_TEXTURE_WRAP_T                                    = 0x00002803;
    public final static int GL_TIMEOUT_EXPIRED                                   = 0x0000911B;
    public final static int GL_TIMEOUT_IGNORED                                   = 0xFFFFFFFF;
    public final static int GL_TIMESTAMP                                         = 0x00008E28;
    public final static int GL_TIME_ELAPSED                                      = 0x000088BF;
    public final static int GL_TRANSFORM_FEEDBACK                                = 0x00008E22;
    public final static int GL_TRANSFORM_FEEDBACK_BINDING                        = 0x00008E25;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER                         = 0x00008C8E;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                  = 0x00008E24;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER_BINDING                 = 0x00008C8F;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER_MODE                    = 0x00008C7F;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                  = 0x00008E23;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                    = 0x00008C85;
    public final static int GL_TRANSFORM_FEEDBACK_BUFFER_START                   = 0x00008C84;
    public final static int GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN             = 0x00008C88;
    public final static int GL_TRANSFORM_FEEDBACK_VARYINGS                       = 0x00008C83;
    public final static int GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH             = 0x00008C76;
    public final static int GL_TRIANGLES                                         = 0x00000004;
    public final static int GL_TRIANGLES_ADJACENCY                               = 0x0000000C;
    public final static int GL_TRIANGLE_FAN                                      = 0x00000006;
    public final static int GL_TRIANGLE_STRIP                                    = 0x00000005;
    public final static int GL_TRIANGLE_STRIP_ADJACENCY                          = 0x0000000D;
    public final static int GL_TRUE                                              = 0x00000001;
    public final static int GL_UNDEFINED_VERTEX                                  = 0x00008260;
    public final static int GL_UNIFORM_ARRAY_STRIDE                              = 0x00008A3C;
    public final static int GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                     = 0x00008A42;
    public final static int GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES              = 0x00008A43;
    public final static int GL_UNIFORM_BLOCK_BINDING                             = 0x00008A3F;
    public final static int GL_UNIFORM_BLOCK_DATA_SIZE                           = 0x00008A40;
    public final static int GL_UNIFORM_BLOCK_INDEX                               = 0x00008A3A;
    public final static int GL_UNIFORM_BLOCK_NAME_LENGTH                         = 0x00008A41;
    public final static int GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER       = 0x00008A46;
    public final static int GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER       = 0x00008A45;
    public final static int GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER   = 0x000084F0;
    public final static int GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x000084F1;
    public final static int GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER         = 0x00008A44;
    public final static int GL_UNIFORM_BUFFER                                    = 0x00008A11;
    public final static int GL_UNIFORM_BUFFER_BINDING                            = 0x00008A28;
    public final static int GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT                   = 0x00008A34;
    public final static int GL_UNIFORM_BUFFER_SIZE                               = 0x00008A2A;
    public final static int GL_UNIFORM_BUFFER_START                              = 0x00008A29;
    public final static int GL_UNIFORM_IS_ROW_MAJOR                              = 0x00008A3E;
    public final static int GL_UNIFORM_MATRIX_STRIDE                             = 0x00008A3D;
    public final static int GL_UNIFORM_NAME_LENGTH                               = 0x00008A39;
    public final static int GL_UNIFORM_OFFSET                                    = 0x00008A3B;
    public final static int GL_UNIFORM_SIZE                                      = 0x00008A38;
    public final static int GL_UNIFORM_TYPE                                      = 0x00008A37;
    public final static int GL_UNKNOWN_CONTEXT_RESET_ARB                         = 0x00008255;
    public final static int GL_UNPACK_ALIGNMENT                                  = 0x00000CF5;
    public final static int GL_UNPACK_IMAGE_HEIGHT                               = 0x0000806E;
    public final static int GL_UNPACK_LSB_FIRST                                  = 0x00000CF1;
    public final static int GL_UNPACK_ROW_LENGTH                                 = 0x00000CF2;
    public final static int GL_UNPACK_SKIP_IMAGES                                = 0x0000806D;
    public final static int GL_UNPACK_SKIP_PIXELS                                = 0x00000CF4;
    public final static int GL_UNPACK_SKIP_ROWS                                  = 0x00000CF3;
    public final static int GL_UNPACK_SWAP_BYTES                                 = 0x00000CF0;
    public final static int GL_UNSIGNALED                                        = 0x00009118;
    public final static int GL_UNSIGNED_BYTE                                     = 0x00001401;
    public final static int GL_UNSIGNED_BYTE_2_3_3_REV                           = 0x00008362;
    public final static int GL_UNSIGNED_BYTE_3_3_2                               = 0x00008032;
    public final static int GL_UNSIGNED_INT                                      = 0x00001405;
    public final static int GL_UNSIGNED_INT_10F_11F_11F_REV                      = 0x00008C3B;
    public final static int GL_UNSIGNED_INT_10_10_10_2                           = 0x00008036;
    public final static int GL_UNSIGNED_INT_24_8                                 = 0x000084FA;
    public final static int GL_UNSIGNED_INT_2_10_10_10_REV                       = 0x00008368;
    public final static int GL_UNSIGNED_INT_5_9_9_9_REV                          = 0x00008C3E;
    public final static int GL_UNSIGNED_INT_8_8_8_8                              = 0x00008035;
    public final static int GL_UNSIGNED_INT_8_8_8_8_REV                          = 0x00008367;
    public final static int GL_UNSIGNED_INT_SAMPLER_1D                           = 0x00008DD1;
    public final static int GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                     = 0x00008DD6;
    public final static int GL_UNSIGNED_INT_SAMPLER_2D                           = 0x00008DD2;
    public final static int GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                     = 0x00008DD7;
    public final static int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE               = 0x0000910A;
    public final static int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY         = 0x0000910D;
    public final static int GL_UNSIGNED_INT_SAMPLER_2D_RECT                      = 0x00008DD5;
    public final static int GL_UNSIGNED_INT_SAMPLER_3D                           = 0x00008DD3;
    public final static int GL_UNSIGNED_INT_SAMPLER_BUFFER                       = 0x00008DD8;
    public final static int GL_UNSIGNED_INT_SAMPLER_CUBE                         = 0x00008DD4;
    public final static int GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY               = 0x0000900F;
    public final static int GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB           = 0x0000900F;
    public final static int GL_UNSIGNED_INT_VEC2                                 = 0x00008DC6;
    public final static int GL_UNSIGNED_INT_VEC3                                 = 0x00008DC7;
    public final static int GL_UNSIGNED_INT_VEC4                                 = 0x00008DC8;
    public final static int GL_UNSIGNED_NORMALIZED                               = 0x00008C17;
    public final static int GL_UNSIGNED_SHORT                                    = 0x00001403;
    public final static int GL_UNSIGNED_SHORT_1_5_5_5_REV                        = 0x00008366;
    public final static int GL_UNSIGNED_SHORT_4_4_4_4                            = 0x00008033;
    public final static int GL_UNSIGNED_SHORT_4_4_4_4_REV                        = 0x00008365;
    public final static int GL_UNSIGNED_SHORT_5_5_5_1                            = 0x00008034;
    public final static int GL_UNSIGNED_SHORT_5_6_5                              = 0x00008363;
    public final static int GL_UNSIGNED_SHORT_5_6_5_REV                          = 0x00008364;
    public final static int GL_UPPER_LEFT                                        = 0x00008CA2;
    public final static int GL_VALIDATE_STATUS                                   = 0x00008B83;
    public final static int GL_VENDOR                                            = 0x00001F00;
    public final static int GL_VERSION                                           = 0x00001F02;
    public final static int GL_VERTEX_ARRAY_BINDING                              = 0x000085B5;
    public final static int GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING                = 0x0000889F;
    public final static int GL_VERTEX_ATTRIB_ARRAY_DIVISOR                       = 0x000088FE;
    public final static int GL_VERTEX_ATTRIB_ARRAY_ENABLED                       = 0x00008622;
    public final static int GL_VERTEX_ATTRIB_ARRAY_INTEGER                       = 0x000088FD;
    public final static int GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                    = 0x0000886A;
    public final static int GL_VERTEX_ATTRIB_ARRAY_POINTER                       = 0x00008645;
    public final static int GL_VERTEX_ATTRIB_ARRAY_SIZE                          = 0x00008623;
    public final static int GL_VERTEX_ATTRIB_ARRAY_STRIDE                        = 0x00008624;
    public final static int GL_VERTEX_ATTRIB_ARRAY_TYPE                          = 0x00008625;
    public final static int GL_VERTEX_PROGRAM_POINT_SIZE                         = 0x00008642;
    public final static int GL_VERTEX_SHADER                                     = 0x00008B31;
    public final static int GL_VERTEX_SHADER_BIT                                 = 0x00000001;
    public final static int GL_VIEWPORT                                          = 0x00000BA2;
    public final static int GL_VIEWPORT_BOUNDS_RANGE                             = 0x0000825D;
    public final static int GL_VIEWPORT_INDEX_PROVOKING_VERTEX                   = 0x0000825F;
    public final static int GL_VIEWPORT_SUBPIXEL_BITS                            = 0x0000825C;
    public final static int GL_WAIT_FAILED                                       = 0x0000911D;
    public final static int GL_WRITE_ONLY                                        = 0x000088B9;
    public final static int GL_XOR                                               = 0x00001506;
    public final static int GL_ZERO                                              = 0x00000000;

    /**
    * GL 1.0
    * @param sfactor
    * @param dfactor
    */
    // void glBlendFunc(GLenum sfactor, GLenum dfactor);
    public static native void glBlendFunc(int sfactor, int dfactor);

    /**
    * GL 1.0
    * @param mask
    */
    // void glClear(GLbitfield mask);
    public static native void glClear(int mask);

    /**
    * GL 1.0
    * @param red
    * @param green
    * @param blue
    * @param alpha
    */
    // void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    public static native void glClearColor(float red, float green, float blue, float alpha);

    /**
    * GL 1.0
    * @param depth
    */
    // void glClearDepth(GLclampd depth);
    public static native void glClearDepth(double depth);

    /**
    * GL 1.0
    * @param s
    */
    // void glClearStencil(GLint s);
    public static native void glClearStencil(int s);

    /**
    * GL 1.0
    * @param red
    * @param green
    * @param blue
    * @param alpha
    */
    // void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    public static native void glColorMask(boolean red, boolean green, boolean blue, boolean alpha);

    /**
    * GL 1.0
    * @param mode
    */
    // void glCullFace(GLenum mode);
    public static native void glCullFace(int mode);

    /**
    * GL 1.0
    * @param func
    */
    // void glDepthFunc(GLenum func);
    public static native void glDepthFunc(int func);

    /**
    * GL 1.0
    * @param flag
    */
    // void glDepthMask(GLboolean flag);
    public static native void glDepthMask(boolean flag);

    /**
    * GL 1.0
    * @param near
    * @param far
    */
    // void glDepthRange(GLclampd near, GLclampd far);
    public static native void glDepthRange(double near, double far);

    /**
    * GL 1.0
    * @param cap
    */
    // void glDisable(GLenum cap);
    public static native void glDisable(int cap);

    /**
    * GL 1.0
    * @param mode
    */
    // void glDrawBuffer(GLenum mode);
    public static native void glDrawBuffer(int mode);

    /**
    * GL 1.0
    * @param cap
    */
    // void glEnable(GLenum cap);
    public static native void glEnable(int cap);

    /**
    * GL 1.0
    */
    // void glFinish();
    public static native void glFinish();

    /**
    * GL 1.0
    */
    // void glFlush();
    public static native void glFlush();

    /**
    * GL 1.0
    * @param mode
    */
    // void glFrontFace(GLenum mode);
    public static native void glFrontFace(int mode);

    /**
    * GL 1.0
    * @param pname
    * @param params
    */
    // void glGetBooleanv(GLenum pname, GLboolean* params);
    public static native void glGetBooleanv(int pname, ByteBuffer params);

    /**
    * GL 1.0
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetBooleanv(int pname, byte[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param pname
    * @param params
    */
    // void glGetDoublev(GLenum pname, GLdouble* params);
    public static native void glGetDoublev(int pname, DoubleBuffer params);

    /**
    * GL 1.0
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetDoublev(int pname, double[] params, int paramsOffset);

    /**
    * GL 1.0
    */
    // GLenum glGetError();
    public static native int glGetError();

    /**
    * GL 1.0
    * @param pname
    * @param params
    */
    // void glGetFloatv(GLenum pname, GLfloat* params);
    public static native void glGetFloatv(int pname, FloatBuffer params);

    /**
    * GL 1.0
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetFloatv(int pname, float[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param pname
    * @param params
    */
    // void glGetIntegerv(GLenum pname, GLint* params);
    public static native void glGetIntegerv(int pname, IntBuffer params);

    /**
    * GL 1.0
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetIntegerv(int pname, int[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param name
    */
    // GLubyte* glGetString(GLenum name);
    public static native String glGetString(int name);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param format
    * @param type
    * @param pixels
    */
    // void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glGetTexImage(int target, int level, int format, int type, Buffer pixels);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glGetTexImage(int target, int level, int format, int type, long pixels);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param pname
    * @param params
    */
    // void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
    public static native void glGetTexLevelParameterfv(int target, int level, int pname, FloatBuffer params);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetTexLevelParameterfv(int target, int level, int pname, float[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param pname
    * @param params
    */
    // void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
    public static native void glGetTexLevelParameteriv(int target, int level, int pname, IntBuffer params);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetTexLevelParameteriv(int target, int level, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    */
    // void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
    public static native void glGetTexParameterfv(int target, int pname, FloatBuffer params);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetTexParameterfv(int target, int pname, float[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    */
    // void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
    public static native void glGetTexParameteriv(int target, int pname, IntBuffer params);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetTexParameteriv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param target
    * @param mode
    */
    // void glHint(GLenum target, GLenum mode);
    public static native void glHint(int target, int mode);

    /**
    * GL 1.0
    * @param cap
    */
    // GLboolean glIsEnabled(GLenum cap);
    public static native boolean glIsEnabled(int cap);

    /**
    * GL 1.0
    * @param width
    */
    // void glLineWidth(GLfloat width);
    public static native void glLineWidth(float width);

    /**
    * GL 1.0
    * @param opcode
    */
    // void glLogicOp(GLenum opcode);
    public static native void glLogicOp(int opcode);

    /**
    * GL 1.0
    * @param pname
    * @param param
    */
    // void glPixelStoref(GLenum pname, GLfloat param);
    public static native void glPixelStoref(int pname, float param);

    /**
    * GL 1.0
    * @param pname
    * @param param
    */
    // void glPixelStorei(GLenum pname, GLint param);
    public static native void glPixelStorei(int pname, int param);

    /**
    * GL 1.0
    * @param size
    */
    // void glPointSize(GLfloat size);
    public static native void glPointSize(float size);

    /**
    * GL 1.0
    * @param face
    * @param mode
    */
    // void glPolygonMode(GLenum face, GLenum mode);
    public static native void glPolygonMode(int face, int mode);

    /**
    * GL 1.0
    * @param mode
    */
    // void glReadBuffer(GLenum mode);
    public static native void glReadBuffer(int mode);

    /**
    * GL 1.0
    * @param x
    * @param y
    * @param width
    * @param height
    * @param format
    * @param type
    * @param pixels
    */
    // void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glReadPixels(int x, int y, int width, int height, int format, int type, Buffer pixels);

    /**
    * GL 1.0
    * @param x
    * @param y
    * @param width
    * @param height
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glReadPixels(int x, int y, int width, int height, int format, int type, long pixels);

    /**
    * GL 1.0
    * @param x
    * @param y
    * @param width
    * @param height
    */
    // void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
    public static native void glScissor(int x, int y, int width, int height);

    /**
    * GL 1.0
    * @param func
    * @param ref
    * @param mask
    */
    // void glStencilFunc(GLenum func, GLint ref, GLuint mask);
    public static native void glStencilFunc(int func, int ref, int mask);

    /**
    * GL 1.0
    * @param mask
    */
    // void glStencilMask(GLuint mask);
    public static native void glStencilMask(int mask);

    /**
    * GL 1.0
    * @param fail
    * @param zfail
    * @param zpass
    */
    // void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    public static native void glStencilOp(int fail, int zfail, int zpass);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param border
    * @param format
    * @param type
    * @param pixels
    */
    // void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glTexImage1D(int target, int level, int internalformat, int width, int border, int format, int type, Buffer pixels);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param border
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glTexImage1D(int target, int level, int internalformat, int width, int border, int format, int type, long pixels);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param border
    * @param format
    * @param type
    * @param pixels
    */
    // void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glTexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, Buffer pixels);

    /**
    * GL 1.0
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param border
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glTexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, long pixels);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param param
    */
    // void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
    public static native void glTexParameterf(int target, int pname, float param);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    */
    // void glTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
    public static native void glTexParameterfv(int target, int pname, FloatBuffer params);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glTexParameterfv(int target, int pname, float[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param param
    */
    // void glTexParameteri(GLenum target, GLenum pname, GLint param);
    public static native void glTexParameteri(int target, int pname, int param);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    */
    // void glTexParameteriv(GLenum target, GLenum pname, GLint* params);
    public static native void glTexParameteriv(int target, int pname, IntBuffer params);

    /**
    * GL 1.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glTexParameteriv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.0
    * @param x
    * @param y
    * @param width
    * @param height
    */
    // void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
    public static native void glViewport(int x, int y, int width, int height);

    /**
    * GL 1.1
    * @param target
    * @param texture
    */
    // void glBindTexture(GLenum target, GLuint texture);
    public static native void glBindTexture(int target, int texture);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param internalformat
    * @param x
    * @param y
    * @param width
    * @param border
    */
    // void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    public static native void glCopyTexImage1D(int target, int level, int internalformat, int x, int y, int width, int border);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param internalformat
    * @param x
    * @param y
    * @param width
    * @param height
    * @param border
    */
    // void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    public static native void glCopyTexImage2D(int target, int level, int internalformat, int x, int y, int width, int height, int border);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param xoffset
    * @param x
    * @param y
    * @param width
    */
    // void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    public static native void glCopyTexSubImage1D(int target, int level, int xoffset, int x, int y, int width);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param x
    * @param y
    * @param width
    * @param height
    */
    // void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    public static native void glCopyTexSubImage2D(int target, int level, int xoffset, int yoffset, int x, int y, int width, int height);

    /**
    * GL 1.1
    * @param n
    * @param textures
    */
    // void glDeleteTextures(GLsizei n, GLuint* textures);
    public static native void glDeleteTextures(int n, IntBuffer textures);

    /**
    * GL 1.1
    * @param n
    * @param textures
    * @param texturesOffset
    */
    public static native void glDeleteTextures(int n, int[] textures, int texturesOffset);

    /**
    * GL 1.1
    * @param mode
    * @param first
    * @param count
    */
    // void glDrawArrays(GLenum mode, GLint first, GLsizei count);
    public static native void glDrawArrays(int mode, int first, int count);

    /**
    * GL 1.1
    * @param mode
    * @param count
    * @param type
    * @param indices
    */
    // void glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid* indices);
    public static native void glDrawElements(int mode, int count, int type, Buffer indices);

    /**
    * GL 1.1
    * @param mode
    * @param count
    * @param type
    * @param indices
    */
    public static native void glDrawElements(int mode, int count, int type, long indices);

    /**
    * GL 1.1
    * @param n
    * @param textures
    */
    // void glGenTextures(GLsizei n, GLuint* textures);
    public static native void glGenTextures(int n, IntBuffer textures);

    /**
    * GL 1.1
    * @param n
    * @param textures
    * @param texturesOffset
    */
    public static native void glGenTextures(int n, int[] textures, int texturesOffset);

    /**
    * GL 1.1
    * @param texture
    */
    // GLboolean glIsTexture(GLuint texture);
    public static native boolean glIsTexture(int texture);

    /**
    * GL 1.1
    * @param factor
    * @param units
    */
    // void glPolygonOffset(GLfloat factor, GLfloat units);
    public static native void glPolygonOffset(float factor, float units);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param xoffset
    * @param width
    * @param format
    * @param type
    * @param pixels
    */
    // void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glTexSubImage1D(int target, int level, int xoffset, int width, int format, int type, Buffer pixels);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param xoffset
    * @param width
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glTexSubImage1D(int target, int level, int xoffset, int width, int format, int type, long pixels);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param width
    * @param height
    * @param format
    * @param type
    * @param pixels
    */
    // void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int type, Buffer pixels);

    /**
    * GL 1.1
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param width
    * @param height
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int type, long pixels);

    /**
    * GL 1.2
    * @param red
    * @param green
    * @param blue
    * @param alpha
    */
    // void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    public static native void glBlendColor(float red, float green, float blue, float alpha);

    /**
    * GL 1.2
    * @param mode
    */
    // void glBlendEquation(GLenum mode);
    public static native void glBlendEquation(int mode);

    /**
    * GL 1.2
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param zoffset
    * @param x
    * @param y
    * @param width
    * @param height
    */
    // void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    public static native void glCopyTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);

    /**
    * GL 1.2
    * @param mode
    * @param start
    * @param end
    * @param count
    * @param type
    * @param indices
    */
    // void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices);
    public static native void glDrawRangeElements(int mode, int start, int end, int count, int type, Buffer indices);

    /**
    * GL 1.2
    * @param mode
    * @param start
    * @param end
    * @param count
    * @param type
    * @param indices
    */
    public static native void glDrawRangeElements(int mode, int start, int end, int count, int type, long indices);

    /**
    * GL 1.2
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param depth
    * @param border
    * @param format
    * @param type
    * @param pixels
    */
    // void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int format, int type, Buffer pixels);

    /**
    * GL 1.2
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param depth
    * @param border
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int format, int type, long pixels);

    /**
    * GL 1.2
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param zoffset
    * @param width
    * @param height
    * @param depth
    * @param format
    * @param type
    * @param pixels
    */
    // void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid* pixels);
    public static native void glTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int type, Buffer pixels);

    /**
    * GL 1.2
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param zoffset
    * @param width
    * @param height
    * @param depth
    * @param format
    * @param type
    * @param pixels
    */
    public static native void glTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int type, long pixels);

    /**
    * GL 1.3
    * @param texture
    */
    // void glActiveTexture(GLenum texture);
    public static native void glActiveTexture(int texture);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param border
    * @param imageSize
    * @param data
    */
    // void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid* data);
    public static native void glCompressedTexImage1D(int target, int level, int internalformat, int width, int border, int imageSize, Buffer data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param border
    * @param imageSize
    * @param data
    */
    public static native void glCompressedTexImage1D(int target, int level, int internalformat, int width, int border, int imageSize, long data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param border
    * @param imageSize
    * @param data
    */
    // void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid* data);
    public static native void glCompressedTexImage2D(int target, int level, int internalformat, int width, int height, int border, int imageSize, Buffer data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param border
    * @param imageSize
    * @param data
    */
    public static native void glCompressedTexImage2D(int target, int level, int internalformat, int width, int height, int border, int imageSize, long data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param depth
    * @param border
    * @param imageSize
    * @param data
    */
    // void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid* data);
    public static native void glCompressedTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int imageSize, Buffer data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param internalformat
    * @param width
    * @param height
    * @param depth
    * @param border
    * @param imageSize
    * @param data
    */
    public static native void glCompressedTexImage3D(int target, int level, int internalformat, int width, int height, int depth, int border, int imageSize, long data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param xoffset
    * @param width
    * @param format
    * @param imageSize
    * @param data
    */
    // void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid* data);
    public static native void glCompressedTexSubImage1D(int target, int level, int xoffset, int width, int format, int imageSize, Buffer data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param xoffset
    * @param width
    * @param format
    * @param imageSize
    * @param data
    */
    public static native void glCompressedTexSubImage1D(int target, int level, int xoffset, int width, int format, int imageSize, long data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param width
    * @param height
    * @param format
    * @param imageSize
    * @param data
    */
    // void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid* data);
    public static native void glCompressedTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int imageSize, Buffer data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param width
    * @param height
    * @param format
    * @param imageSize
    * @param data
    */
    public static native void glCompressedTexSubImage2D(int target, int level, int xoffset, int yoffset, int width, int height, int format, int imageSize, long data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param zoffset
    * @param width
    * @param height
    * @param depth
    * @param format
    * @param imageSize
    * @param data
    */
    // void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid* data);
    public static native void glCompressedTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int imageSize, Buffer data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param xoffset
    * @param yoffset
    * @param zoffset
    * @param width
    * @param height
    * @param depth
    * @param format
    * @param imageSize
    * @param data
    */
    public static native void glCompressedTexSubImage3D(int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int format, int imageSize, long data);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param img
    */
    // void glGetCompressedTexImage(GLenum target, GLint level, GLvoid* img);
    public static native void glGetCompressedTexImage(int target, int level, Buffer img);

    /**
    * GL 1.3
    * @param target
    * @param level
    * @param img
    */
    public static native void glGetCompressedTexImage(int target, int level, long img);

    /**
    * GL 1.3
    * @param value
    * @param invert
    */
    // void glSampleCoverage(GLclampf value, GLboolean invert);
    public static native void glSampleCoverage(float value, boolean invert);

    /**
    * GL 1.4
    * @param sfactorRGB
    * @param dfactorRGB
    * @param sfactorAlpha
    * @param dfactorAlpha
    */
    // void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    public static native void glBlendFuncSeparate(int sfactorRGB, int dfactorRGB, int sfactorAlpha, int dfactorAlpha);

    /**
    * GL 1.4
    * @param mode
    * @param first
    * @param count
    * @param primcount
    */
    // void glMultiDrawArrays(GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
    public static native void glMultiDrawArrays(int mode, IntBuffer first, IntBuffer count, int primcount);

    /**
    * GL 1.4
    * @param mode
    * @param first
    * @param firstOffset
    * @param count
    * @param countOffset
    * @param primcount
    */
    public static native void glMultiDrawArrays(int mode, int[] first, int firstOffset, int[] count, int countOffset, int primcount);

    /**
    * GL 1.4
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param primcount
    */
    // void glMultiDrawElements(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount);
    public static native void glMultiDrawElements(int mode, IntBuffer count, int type, Buffer[] indices, int primcount);

    /**
    * GL 1.4
    * @param mode
    * @param count
    * @param countOffset
    * @param type
    * @param indices
    * @param primcount
    */
    public static native void glMultiDrawElements(int mode, int[] count, int countOffset, int type, Buffer[] indices, int primcount);

    /**
    * GL 1.4
    * @param pname
    * @param param
    */
    // void glPointParameterf(GLenum pname, GLfloat param);
    public static native void glPointParameterf(int pname, float param);

    /**
    * GL 1.4
    * @param pname
    * @param params
    */
    // void glPointParameterfv(GLenum pname, GLfloat* params);
    public static native void glPointParameterfv(int pname, FloatBuffer params);

    /**
    * GL 1.4
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glPointParameterfv(int pname, float[] params, int paramsOffset);

    /**
    * GL 1.4
    * @param pname
    * @param param
    */
    // void glPointParameteri(GLenum pname, GLint param);
    public static native void glPointParameteri(int pname, int param);

    /**
    * GL 1.4
    * @param pname
    * @param params
    */
    // void glPointParameteriv(GLenum pname, GLint* params);
    public static native void glPointParameteriv(int pname, IntBuffer params);

    /**
    * GL 1.4
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glPointParameteriv(int pname, int[] params, int paramsOffset);

    /**
    * GL 1.5
    * @param target
    * @param id
    */
    // void glBeginQuery(GLenum target, GLuint id);
    public static native void glBeginQuery(int target, int id);

    /**
    * GL 1.5
    * @param target
    * @param buffer
    */
    // void glBindBuffer(GLenum target, GLuint buffer);
    public static native void glBindBuffer(int target, int buffer);

    /**
    * GL 1.5
    * @param target
    * @param size
    * @param data
    * @param usage
    */
    // void glBufferData(GLenum target, GLsizeiptr size, GLvoid* data, GLenum usage);
    public static native void glBufferData(int target, int size, Buffer data, int usage);

    /**
    * GL 1.5
    * @param target
    * @param size
    * @param data
    * @param usage
    */
    public static native void glBufferData(int target, int size, long data, int usage);

    /**
    * GL 1.5
    * @param target
    * @param offset
    * @param size
    * @param data
    */
    // void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
    public static native void glBufferSubData(int target, int offset, int size, Buffer data);

    /**
    * GL 1.5
    * @param target
    * @param offset
    * @param size
    * @param data
    */
    public static native void glBufferSubData(int target, int offset, int size, long data);

    /**
    * GL 1.5
    * @param n
    * @param buffers
    */
    // void glDeleteBuffers(GLsizei n, GLuint* buffers);
    public static native void glDeleteBuffers(int n, IntBuffer buffers);

    /**
    * GL 1.5
    * @param n
    * @param buffers
    * @param buffersOffset
    */
    public static native void glDeleteBuffers(int n, int[] buffers, int buffersOffset);

    /**
    * GL 1.5
    * @param n
    * @param ids
    */
    // void glDeleteQueries(GLsizei n, GLuint* ids);
    public static native void glDeleteQueries(int n, IntBuffer ids);

    /**
    * GL 1.5
    * @param n
    * @param ids
    * @param idsOffset
    */
    public static native void glDeleteQueries(int n, int[] ids, int idsOffset);

    /**
    * GL 1.5
    * @param target
    */
    // void glEndQuery(GLenum target);
    public static native void glEndQuery(int target);

    /**
    * GL 1.5
    * @param n
    * @param buffers
    */
    // void glGenBuffers(GLsizei n, GLuint* buffers);
    public static native void glGenBuffers(int n, IntBuffer buffers);

    /**
    * GL 1.5
    * @param n
    * @param buffers
    * @param buffersOffset
    */
    public static native void glGenBuffers(int n, int[] buffers, int buffersOffset);

    /**
    * GL 1.5
    * @param n
    * @param ids
    */
    // void glGenQueries(GLsizei n, GLuint* ids);
    public static native void glGenQueries(int n, IntBuffer ids);

    /**
    * GL 1.5
    * @param n
    * @param ids
    * @param idsOffset
    */
    public static native void glGenQueries(int n, int[] ids, int idsOffset);

    /**
    * GL 1.5
    * @param target
    * @param pname
    * @param params
    */
    // void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
    public static native void glGetBufferParameteriv(int target, int pname, IntBuffer params);

    /**
    * GL 1.5
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetBufferParameteriv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.5
    * @param target
    * @param offset
    * @param size
    * @param data
    */
    // void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
    public static native void glGetBufferSubData(int target, int offset, int size, Buffer data);

    /**
    * GL 1.5
    * @param target
    * @param offset
    * @param size
    * @param data
    */
    public static native void glGetBufferSubData(int target, int offset, int size, long data);

    /**
    * GL 1.5
    * @param id
    * @param pname
    * @param params
    */
    // void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params);
    public static native void glGetQueryObjectiv(int id, int pname, IntBuffer params);

    /**
    * GL 1.5
    * @param id
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetQueryObjectiv(int id, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.5
    * @param id
    * @param pname
    * @param params
    */
    // void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params);
    public static native void glGetQueryObjectuiv(int id, int pname, IntBuffer params);

    /**
    * GL 1.5
    * @param id
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetQueryObjectuiv(int id, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.5
    * @param target
    * @param pname
    * @param params
    */
    // void glGetQueryiv(GLenum target, GLenum pname, GLint* params);
    public static native void glGetQueryiv(int target, int pname, IntBuffer params);

    /**
    * GL 1.5
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetQueryiv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 1.5
    * @param buffer
    */
    // GLboolean glIsBuffer(GLuint buffer);
    public static native boolean glIsBuffer(int buffer);

    /**
    * GL 1.5
    * @param id
    */
    // GLboolean glIsQuery(GLuint id);
    public static native boolean glIsQuery(int id);

    /**
    * GL 2.0
    * @param program
    * @param shader
    */
    // void glAttachShader(GLuint program, GLuint shader);
    public static native void glAttachShader(int program, int shader);

    /**
    * GL 2.0
    * @param program
    * @param index
    * @param name
    */
    // void glBindAttribLocation(GLuint program, GLuint index, GLchar* name);
    public static native void glBindAttribLocation(int program, int index, String name);

    /**
    * GL 2.0
    * @param modeRGB
    * @param modeAlpha
    */
    // void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
    public static native void glBlendEquationSeparate(int modeRGB, int modeAlpha);

    /**
    * GL 2.0
    * @param shader
    */
    // void glCompileShader(GLuint shader);
    public static native void glCompileShader(int shader);

    /**
    * GL 2.0
    */
    // GLuint glCreateProgram();
    public static native int glCreateProgram();

    /**
    * GL 2.0
    * @param type
    */
    // GLuint glCreateShader(GLenum type);
    public static native int glCreateShader(int type);

    /**
    * GL 2.0
    * @param program
    */
    // void glDeleteProgram(GLuint program);
    public static native void glDeleteProgram(int program);

    /**
    * GL 2.0
    * @param shader
    */
    // void glDeleteShader(GLuint shader);
    public static native void glDeleteShader(int shader);

    /**
    * GL 2.0
    * @param program
    * @param shader
    */
    // void glDetachShader(GLuint program, GLuint shader);
    public static native void glDetachShader(int program, int shader);

    /**
    * GL 2.0
    * @param index
    */
    // void glDisableVertexAttribArray(GLuint index);
    public static native void glDisableVertexAttribArray(int index);

    /**
    * GL 2.0
    * @param n
    * @param bufs
    */
    // void glDrawBuffers(GLsizei n, GLenum* bufs);
    public static native void glDrawBuffers(int n, IntBuffer bufs);

    /**
    * GL 2.0
    * @param n
    * @param bufs
    * @param bufsOffset
    */
    public static native void glDrawBuffers(int n, int[] bufs, int bufsOffset);

    /**
    * GL 2.0
    * @param index
    */
    // void glEnableVertexAttribArray(GLuint index);
    public static native void glEnableVertexAttribArray(int index);

    /**
    * GL 2.0
    * @param program
    * @param index
    * @param bufSize
    * @param length
    * @param size
    * @param type
    * @param name
    */
    // void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    public static native void glGetActiveAttrib(int program, int index, int bufSize, IntBuffer length, IntBuffer size, IntBuffer type, ByteBuffer name);

    /**
    * GL 2.0
    * @param program
    * @param index
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param size
    * @param sizeOffset
    * @param type
    * @param typeOffset
    * @param name
    * @param nameOffset
    */
    public static native void glGetActiveAttrib(int program, int index, int bufSize, int[] length, int lengthOffset, int[] size, int sizeOffset, int[] type, int typeOffset, byte[] name, int nameOffset);

    /**
    * GL 2.0
    * @param program
    * @param index
    * @param bufSize
    * @param length
    * @param size
    * @param type
    * @param name
    */
    // void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    public static native void glGetActiveUniform(int program, int index, int bufSize, IntBuffer length, IntBuffer size, IntBuffer type, ByteBuffer name);

    /**
    * GL 2.0
    * @param program
    * @param index
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param size
    * @param sizeOffset
    * @param type
    * @param typeOffset
    * @param name
    * @param nameOffset
    */
    public static native void glGetActiveUniform(int program, int index, int bufSize, int[] length, int lengthOffset, int[] size, int sizeOffset, int[] type, int typeOffset, byte[] name, int nameOffset);

    /**
    * GL 2.0
    * @param program
    * @param maxCount
    * @param count
    * @param obj
    */
    // void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* obj);
    public static native void glGetAttachedShaders(int program, int maxCount, IntBuffer count, IntBuffer obj);

    /**
    * GL 2.0
    * @param program
    * @param maxCount
    * @param count
    * @param countOffset
    * @param obj
    * @param objOffset
    */
    public static native void glGetAttachedShaders(int program, int maxCount, int[] count, int countOffset, int[] obj, int objOffset);

    /**
    * GL 2.0
    * @param program
    * @param name
    */
    // GLint glGetAttribLocation(GLuint program, GLchar* name);
    public static native int glGetAttribLocation(int program, String name);

    /**
    * GL 2.0
    * @param program
    * @param bufSize
    * @param length
    * @param infoLog
    */
    // void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
    public static native void glGetProgramInfoLog(int program, int bufSize, IntBuffer length, ByteBuffer infoLog);

    /**
    * GL 2.0
    * @param program
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param infoLog
    * @param infoLogOffset
    */
    public static native void glGetProgramInfoLog(int program, int bufSize, int[] length, int lengthOffset, byte[] infoLog, int infoLogOffset);

    /**
    * GL 2.0
    * @param program
    * @param pname
    * @param params
    */
    // void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
    public static native void glGetProgramiv(int program, int pname, IntBuffer params);

    /**
    * GL 2.0
    * @param program
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetProgramiv(int program, int pname, int[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param shader
    * @param bufSize
    * @param length
    * @param infoLog
    */
    // void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
    public static native void glGetShaderInfoLog(int shader, int bufSize, IntBuffer length, ByteBuffer infoLog);

    /**
    * GL 2.0
    * @param shader
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param infoLog
    * @param infoLogOffset
    */
    public static native void glGetShaderInfoLog(int shader, int bufSize, int[] length, int lengthOffset, byte[] infoLog, int infoLogOffset);

    /**
    * GL 2.0
    * @param shader
    * @param bufSize
    * @param length
    * @param source
    */
    // void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
    public static native void glGetShaderSource(int shader, int bufSize, IntBuffer length, ByteBuffer source);

    /**
    * GL 2.0
    * @param shader
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param source
    * @param sourceOffset
    */
    public static native void glGetShaderSource(int shader, int bufSize, int[] length, int lengthOffset, byte[] source, int sourceOffset);

    /**
    * GL 2.0
    * @param shader
    * @param pname
    * @param params
    */
    // void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
    public static native void glGetShaderiv(int shader, int pname, IntBuffer params);

    /**
    * GL 2.0
    * @param shader
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetShaderiv(int shader, int pname, int[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param program
    * @param name
    */
    // GLint glGetUniformLocation(GLuint program, GLchar* name);
    public static native int glGetUniformLocation(int program, String name);

    /**
    * GL 2.0
    * @param program
    * @param location
    * @param params
    */
    // void glGetUniformfv(GLuint program, GLint location, GLfloat* params);
    public static native void glGetUniformfv(int program, int location, FloatBuffer params);

    /**
    * GL 2.0
    * @param program
    * @param location
    * @param params
    * @param paramsOffset
    */
    public static native void glGetUniformfv(int program, int location, float[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param program
    * @param location
    * @param params
    */
    // void glGetUniformiv(GLuint program, GLint location, GLint* params);
    public static native void glGetUniformiv(int program, int location, IntBuffer params);

    /**
    * GL 2.0
    * @param program
    * @param location
    * @param params
    * @param paramsOffset
    */
    public static native void glGetUniformiv(int program, int location, int[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param index
    * @param pname
    * @param params
    */
    // void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params);
    public static native void glGetVertexAttribdv(int index, int pname, DoubleBuffer params);

    /**
    * GL 2.0
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetVertexAttribdv(int index, int pname, double[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param index
    * @param pname
    * @param params
    */
    // void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
    public static native void glGetVertexAttribfv(int index, int pname, FloatBuffer params);

    /**
    * GL 2.0
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetVertexAttribfv(int index, int pname, float[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param index
    * @param pname
    * @param params
    */
    // void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
    public static native void glGetVertexAttribiv(int index, int pname, IntBuffer params);

    /**
    * GL 2.0
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetVertexAttribiv(int index, int pname, int[] params, int paramsOffset);

    /**
    * GL 2.0
    * @param program
    */
    // GLboolean glIsProgram(GLuint program);
    public static native boolean glIsProgram(int program);

    /**
    * GL 2.0
    * @param shader
    */
    // GLboolean glIsShader(GLuint shader);
    public static native boolean glIsShader(int shader);

    /**
    * GL 2.0
    * @param program
    */
    // void glLinkProgram(GLuint program);
    public static native void glLinkProgram(int program);

    /**
    * GL 2.0
    * @param shader
    * @param count
    * @param string
    * @param length
    */
    // void glShaderSource(GLuint shader, GLsizei count, GLchar** string, GLint* length);
    public static native void glShaderSource(int shader, int count, String[] string, IntBuffer length);

    /**
    * GL 2.0
    * @param shader
    * @param count
    * @param string
    * @param length
    * @param lengthOffset
    */
    public static native void glShaderSource(int shader, int count, String[] string, int[] length, int lengthOffset);

    /**
    * GL 2.0
    * @param face
    * @param func
    * @param ref
    * @param mask
    */
    // void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
    public static native void glStencilFuncSeparate(int face, int func, int ref, int mask);

    /**
    * GL 2.0
    * @param face
    * @param mask
    */
    // void glStencilMaskSeparate(GLenum face, GLuint mask);
    public static native void glStencilMaskSeparate(int face, int mask);

    /**
    * GL 2.0
    * @param face
    * @param sfail
    * @param dpfail
    * @param dppass
    */
    // void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    public static native void glStencilOpSeparate(int face, int sfail, int dpfail, int dppass);

    /**
    * GL 2.0
    * @param location
    * @param v0
    */
    // void glUniform1f(GLint location, GLfloat v0);
    public static native void glUniform1f(int location, float v0);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform1fv(GLint location, GLsizei count, GLfloat* value);
    public static native void glUniform1fv(int location, int count, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform1fv(int location, int count, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    */
    // void glUniform1i(GLint location, GLint v0);
    public static native void glUniform1i(int location, int v0);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform1iv(GLint location, GLsizei count, GLint* value);
    public static native void glUniform1iv(int location, int count, IntBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform1iv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    * @param v1
    */
    // void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
    public static native void glUniform2f(int location, float v0, float v1);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform2fv(GLint location, GLsizei count, GLfloat* value);
    public static native void glUniform2fv(int location, int count, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform2fv(int location, int count, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    * @param v1
    */
    // void glUniform2i(GLint location, GLint v0, GLint v1);
    public static native void glUniform2i(int location, int v0, int v1);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform2iv(GLint location, GLsizei count, GLint* value);
    public static native void glUniform2iv(int location, int count, IntBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform2iv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    public static native void glUniform3f(int location, float v0, float v1, float v2);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform3fv(GLint location, GLsizei count, GLfloat* value);
    public static native void glUniform3fv(int location, int count, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform3fv(int location, int count, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
    public static native void glUniform3i(int location, int v0, int v1, int v2);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform3iv(GLint location, GLsizei count, GLint* value);
    public static native void glUniform3iv(int location, int count, IntBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform3iv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    public static native void glUniform4f(int location, float v0, float v1, float v2, float v3);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform4fv(GLint location, GLsizei count, GLfloat* value);
    public static native void glUniform4fv(int location, int count, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform4fv(int location, int count, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    public static native void glUniform4i(int location, int v0, int v1, int v2, int v3);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform4iv(GLint location, GLsizei count, GLint* value);
    public static native void glUniform4iv(int location, int count, IntBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform4iv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix2fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix2fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix3fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix3fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix4fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix4fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.0
    * @param program
    */
    // void glUseProgram(GLuint program);
    public static native void glUseProgram(int program);

    /**
    * GL 2.0
    * @param program
    */
    // void glValidateProgram(GLuint program);
    public static native void glValidateProgram(int program);

    /**
    * GL 2.0
    * @param index
    * @param x
    */
    // void glVertexAttrib1d(GLuint index, GLdouble x);
    public static native void glVertexAttrib1d(int index, double x);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib1dv(GLuint index, GLdouble* v);
    public static native void glVertexAttrib1dv(int index, DoubleBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib1dv(int index, double[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    */
    // void glVertexAttrib1f(GLuint index, GLfloat x);
    public static native void glVertexAttrib1f(int index, float x);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib1fv(GLuint index, GLfloat* v);
    public static native void glVertexAttrib1fv(int index, FloatBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib1fv(int index, float[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    */
    // void glVertexAttrib1s(GLuint index, GLshort x);
    public static native void glVertexAttrib1s(int index, short x);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib1sv(GLuint index, GLshort* v);
    public static native void glVertexAttrib1sv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib1sv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    */
    // void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
    public static native void glVertexAttrib2d(int index, double x, double y);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib2dv(GLuint index, GLdouble* v);
    public static native void glVertexAttrib2dv(int index, DoubleBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib2dv(int index, double[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    */
    // void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
    public static native void glVertexAttrib2f(int index, float x, float y);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib2fv(GLuint index, GLfloat* v);
    public static native void glVertexAttrib2fv(int index, FloatBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib2fv(int index, float[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    */
    // void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
    public static native void glVertexAttrib2s(int index, short x, short y);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib2sv(GLuint index, GLshort* v);
    public static native void glVertexAttrib2sv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib2sv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    */
    // void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
    public static native void glVertexAttrib3d(int index, double x, double y, double z);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib3dv(GLuint index, GLdouble* v);
    public static native void glVertexAttrib3dv(int index, DoubleBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib3dv(int index, double[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    */
    // void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
    public static native void glVertexAttrib3f(int index, float x, float y, float z);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib3fv(GLuint index, GLfloat* v);
    public static native void glVertexAttrib3fv(int index, FloatBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib3fv(int index, float[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    */
    // void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
    public static native void glVertexAttrib3s(int index, short x, short y, short z);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib3sv(GLuint index, GLshort* v);
    public static native void glVertexAttrib3sv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib3sv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4Nbv(GLuint index, GLbyte* v);
    public static native void glVertexAttrib4Nbv(int index, ByteBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4Nbv(int index, byte[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4Niv(GLuint index, GLint* v);
    public static native void glVertexAttrib4Niv(int index, IntBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4Niv(int index, int[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4Nsv(GLuint index, GLshort* v);
    public static native void glVertexAttrib4Nsv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4Nsv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    public static native void glVertexAttrib4Nub(int index, byte x, byte y, byte z, byte w);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4Nubv(GLuint index, GLubyte* v);
    public static native void glVertexAttrib4Nubv(int index, ByteBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4Nubv(int index, byte[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4Nuiv(GLuint index, GLuint* v);
    public static native void glVertexAttrib4Nuiv(int index, IntBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4Nuiv(int index, int[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4Nusv(GLuint index, GLushort* v);
    public static native void glVertexAttrib4Nusv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4Nusv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4bv(GLuint index, GLbyte* v);
    public static native void glVertexAttrib4bv(int index, ByteBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4bv(int index, byte[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    public static native void glVertexAttrib4d(int index, double x, double y, double z, double w);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4dv(GLuint index, GLdouble* v);
    public static native void glVertexAttrib4dv(int index, DoubleBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4dv(int index, double[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    public static native void glVertexAttrib4f(int index, float x, float y, float z, float w);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4fv(GLuint index, GLfloat* v);
    public static native void glVertexAttrib4fv(int index, FloatBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4fv(int index, float[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4iv(GLuint index, GLint* v);
    public static native void glVertexAttrib4iv(int index, IntBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4iv(int index, int[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    public static native void glVertexAttrib4s(int index, short x, short y, short z, short w);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4sv(GLuint index, GLshort* v);
    public static native void glVertexAttrib4sv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4sv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4ubv(GLuint index, GLubyte* v);
    public static native void glVertexAttrib4ubv(int index, ByteBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4ubv(int index, byte[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4uiv(GLuint index, GLuint* v);
    public static native void glVertexAttrib4uiv(int index, IntBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4uiv(int index, int[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param v
    */
    // void glVertexAttrib4usv(GLuint index, GLushort* v);
    public static native void glVertexAttrib4usv(int index, ShortBuffer v);

    /**
    * GL 2.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttrib4usv(int index, short[] v, int vOffset);

    /**
    * GL 2.0
    * @param index
    * @param size
    * @param type
    * @param normalized
    * @param stride
    * @param pointer
    */
    // void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* pointer);
    public static native void glVertexAttribPointer(int index, int size, int type, boolean normalized, int stride, Buffer pointer);

    /**
    * GL 2.0
    * @param index
    * @param size
    * @param type
    * @param normalized
    * @param stride
    * @param pointer
    */
    public static native void glVertexAttribPointer(int index, int size, int type, boolean normalized, int stride, long pointer);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix2x3fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix2x3fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix2x4fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix2x4fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix3x2fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix3x2fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix3x4fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix3x4fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix4x2fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix4x2fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glUniformMatrix4x3fv(int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 2.1
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix4x3fv(int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 3.0
    * @param id
    * @param mode
    */
    // void glBeginConditionalRender(GLuint id, GLenum mode);
    public static native void glBeginConditionalRender(int id, int mode);

    /**
    * GL 3.0
    * @param primitiveMode
    */
    // void glBeginTransformFeedback(GLenum primitiveMode);
    public static native void glBeginTransformFeedback(int primitiveMode);

    /**
    * GL 3.0
    * @param target
    * @param index
    * @param buffer
    */
    // void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
    public static native void glBindBufferBase(int target, int index, int buffer);

    /**
    * GL 3.0
    * @param target
    * @param index
    * @param buffer
    * @param offset
    * @param size
    */
    // void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    public static native void glBindBufferRange(int target, int index, int buffer, int offset, int size);

    /**
    * GL 3.0
    * @param program
    * @param color
    * @param name
    */
    // void glBindFragDataLocation(GLuint program, GLuint color, GLchar* name);
    public static native void glBindFragDataLocation(int program, int color, String name);

    /**
    * GL 3.0
    * @param target
    * @param framebuffer
    */
    // void glBindFramebuffer(GLenum target, GLuint framebuffer);
    public static native void glBindFramebuffer(int target, int framebuffer);

    /**
    * GL 3.0
    * @param target
    * @param renderbuffer
    */
    // void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
    public static native void glBindRenderbuffer(int target, int renderbuffer);

    /**
    * GL 3.0
    * @param array
    */
    // void glBindVertexArray(GLuint array);
    public static native void glBindVertexArray(int array);

    /**
    * GL 3.0
    * @param srcX0
    * @param srcY0
    * @param srcX1
    * @param srcY1
    * @param dstX0
    * @param dstY0
    * @param dstX1
    * @param dstY1
    * @param mask
    * @param filter
    */
    // void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    public static native void glBlitFramebuffer(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, int mask, int filter);

    /**
    * GL 3.0
    * @param target
    */
    // GLenum glCheckFramebufferStatus(GLenum target);
    public static native int glCheckFramebufferStatus(int target);

    /**
    * GL 3.0
    * @param target
    * @param clamp
    */
    // void glClampColor(GLenum target, GLenum clamp);
    public static native void glClampColor(int target, int clamp);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param depth
    * @param stencil
    */
    // void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    public static native void glClearBufferfi(int buffer, int drawbuffer, float depth, int stencil);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param value
    */
    // void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat* value);
    public static native void glClearBufferfv(int buffer, int drawbuffer, FloatBuffer value);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param value
    * @param valueOffset
    */
    public static native void glClearBufferfv(int buffer, int drawbuffer, float[] value, int valueOffset);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param value
    */
    // void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint* value);
    public static native void glClearBufferiv(int buffer, int drawbuffer, IntBuffer value);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param value
    * @param valueOffset
    */
    public static native void glClearBufferiv(int buffer, int drawbuffer, int[] value, int valueOffset);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param value
    */
    // void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint* value);
    public static native void glClearBufferuiv(int buffer, int drawbuffer, IntBuffer value);

    /**
    * GL 3.0
    * @param buffer
    * @param drawbuffer
    * @param value
    * @param valueOffset
    */
    public static native void glClearBufferuiv(int buffer, int drawbuffer, int[] value, int valueOffset);

    /**
    * GL 3.0
    * @param index
    * @param r
    * @param g
    * @param b
    * @param a
    */
    // void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    public static native void glColorMaski(int index, boolean r, boolean g, boolean b, boolean a);

    /**
    * GL 3.0
    * @param n
    * @param framebuffers
    */
    // void glDeleteFramebuffers(GLsizei n, GLuint* framebuffers);
    public static native void glDeleteFramebuffers(int n, IntBuffer framebuffers);

    /**
    * GL 3.0
    * @param n
    * @param framebuffers
    * @param framebuffersOffset
    */
    public static native void glDeleteFramebuffers(int n, int[] framebuffers, int framebuffersOffset);

    /**
    * GL 3.0
    * @param n
    * @param renderbuffers
    */
    // void glDeleteRenderbuffers(GLsizei n, GLuint* renderbuffers);
    public static native void glDeleteRenderbuffers(int n, IntBuffer renderbuffers);

    /**
    * GL 3.0
    * @param n
    * @param renderbuffers
    * @param renderbuffersOffset
    */
    public static native void glDeleteRenderbuffers(int n, int[] renderbuffers, int renderbuffersOffset);

    /**
    * GL 3.0
    * @param n
    * @param arrays
    */
    // void glDeleteVertexArrays(GLsizei n, GLuint* arrays);
    public static native void glDeleteVertexArrays(int n, IntBuffer arrays);

    /**
    * GL 3.0
    * @param n
    * @param arrays
    * @param arraysOffset
    */
    public static native void glDeleteVertexArrays(int n, int[] arrays, int arraysOffset);

    /**
    * GL 3.0
    * @param target
    * @param index
    */
    // void glDisablei(GLenum target, GLuint index);
    public static native void glDisablei(int target, int index);

    /**
    * GL 3.0
    * @param target
    * @param index
    */
    // void glEnablei(GLenum target, GLuint index);
    public static native void glEnablei(int target, int index);

    /**
    * GL 3.0
    */
    // void glEndConditionalRender();
    public static native void glEndConditionalRender();

    /**
    * GL 3.0
    */
    // void glEndTransformFeedback();
    public static native void glEndTransformFeedback();

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param renderbuffertarget
    * @param renderbuffer
    */
    // void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    public static native void glFramebufferRenderbuffer(int target, int attachment, int renderbuffertarget, int renderbuffer);

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param textarget
    * @param texture
    * @param level
    */
    // void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    public static native void glFramebufferTexture1D(int target, int attachment, int textarget, int texture, int level);

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param textarget
    * @param texture
    * @param level
    */
    // void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    public static native void glFramebufferTexture2D(int target, int attachment, int textarget, int texture, int level);

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param textarget
    * @param texture
    * @param level
    * @param zoffset
    */
    // void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    public static native void glFramebufferTexture3D(int target, int attachment, int textarget, int texture, int level, int zoffset);

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param texture
    * @param level
    * @param layer
    */
    // void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    public static native void glFramebufferTextureLayer(int target, int attachment, int texture, int level, int layer);

    /**
    * GL 3.0
    * @param n
    * @param framebuffers
    */
    // void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
    public static native void glGenFramebuffers(int n, IntBuffer framebuffers);

    /**
    * GL 3.0
    * @param n
    * @param framebuffers
    * @param framebuffersOffset
    */
    public static native void glGenFramebuffers(int n, int[] framebuffers, int framebuffersOffset);

    /**
    * GL 3.0
    * @param n
    * @param renderbuffers
    */
    // void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers);
    public static native void glGenRenderbuffers(int n, IntBuffer renderbuffers);

    /**
    * GL 3.0
    * @param n
    * @param renderbuffers
    * @param renderbuffersOffset
    */
    public static native void glGenRenderbuffers(int n, int[] renderbuffers, int renderbuffersOffset);

    /**
    * GL 3.0
    * @param n
    * @param arrays
    */
    // void glGenVertexArrays(GLsizei n, GLuint* arrays);
    public static native void glGenVertexArrays(int n, IntBuffer arrays);

    /**
    * GL 3.0
    * @param n
    * @param arrays
    * @param arraysOffset
    */
    public static native void glGenVertexArrays(int n, int[] arrays, int arraysOffset);

    /**
    * GL 3.0
    * @param target
    */
    // void glGenerateMipmap(GLenum target);
    public static native void glGenerateMipmap(int target);

    /**
    * GL 3.0
    * @param target
    * @param index
    * @param data
    */
    // void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data);
    public static native void glGetBooleani_v(int target, int index, ByteBuffer data);

    /**
    * GL 3.0
    * @param target
    * @param index
    * @param data
    * @param dataOffset
    */
    public static native void glGetBooleani_v(int target, int index, byte[] data, int dataOffset);

    /**
    * GL 3.0
    * @param program
    * @param name
    */
    // GLint glGetFragDataLocation(GLuint program, GLchar* name);
    public static native int glGetFragDataLocation(int program, String name);

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param pname
    * @param params
    */
    // void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
    public static native void glGetFramebufferAttachmentParameteriv(int target, int attachment, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param target
    * @param attachment
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetFramebufferAttachmentParameteriv(int target, int attachment, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param target
    * @param index
    * @param data
    */
    // void glGetIntegeri_v(GLenum target, GLuint index, GLint* data);
    public static native void glGetIntegeri_v(int target, int index, IntBuffer data);

    /**
    * GL 3.0
    * @param target
    * @param index
    * @param data
    * @param dataOffset
    */
    public static native void glGetIntegeri_v(int target, int index, int[] data, int dataOffset);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    */
    // void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
    public static native void glGetRenderbufferParameteriv(int target, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetRenderbufferParameteriv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param name
    * @param index
    */
    // GLubyte* glGetStringi(GLenum name, GLuint index);
    public static native String glGetStringi(int name, int index);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    */
    // void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params);
    public static native void glGetTexParameterIiv(int target, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetTexParameterIiv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    */
    // void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
    public static native void glGetTexParameterIuiv(int target, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetTexParameterIuiv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param program
    * @param index
    * @param bufSize
    * @param length
    * @param size
    * @param type
    * @param name
    */
    // void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
    public static native void glGetTransformFeedbackVarying(int program, int index, int bufSize, IntBuffer length, IntBuffer size, IntBuffer type, String name);

    /**
    * GL 3.0
    * @param program
    * @param index
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param size
    * @param sizeOffset
    * @param type
    * @param typeOffset
    * @param name
    */
    public static native void glGetTransformFeedbackVarying(int program, int index, int bufSize, int[] length, int lengthOffset, int[] size, int sizeOffset, int[] type, int typeOffset, String name);

    /**
    * GL 3.0
    * @param program
    * @param location
    * @param params
    */
    // void glGetUniformuiv(GLuint program, GLint location, GLuint* params);
    public static native void glGetUniformuiv(int program, int location, IntBuffer params);

    /**
    * GL 3.0
    * @param program
    * @param location
    * @param params
    * @param paramsOffset
    */
    public static native void glGetUniformuiv(int program, int location, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param index
    * @param pname
    * @param params
    */
    // void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params);
    public static native void glGetVertexAttribIiv(int index, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetVertexAttribIiv(int index, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param index
    * @param pname
    * @param params
    */
    // void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params);
    public static native void glGetVertexAttribIuiv(int index, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetVertexAttribIuiv(int index, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param target
    * @param index
    */
    // GLboolean glIsEnabledi(GLenum target, GLuint index);
    public static native boolean glIsEnabledi(int target, int index);

    /**
    * GL 3.0
    * @param framebuffer
    */
    // GLboolean glIsFramebuffer(GLuint framebuffer);
    public static native boolean glIsFramebuffer(int framebuffer);

    /**
    * GL 3.0
    * @param renderbuffer
    */
    // GLboolean glIsRenderbuffer(GLuint renderbuffer);
    public static native boolean glIsRenderbuffer(int renderbuffer);

    /**
    * GL 3.0
    * @param array
    */
    // GLboolean glIsVertexArray(GLuint array);
    public static native boolean glIsVertexArray(int array);

    /**
    * GL 3.0
    * @param target
    * @param internalformat
    * @param width
    * @param height
    */
    // void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    public static native void glRenderbufferStorage(int target, int internalformat, int width, int height);

    /**
    * GL 3.0
    * @param target
    * @param samples
    * @param internalformat
    * @param width
    * @param height
    */
    // void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    public static native void glRenderbufferStorageMultisample(int target, int samples, int internalformat, int width, int height);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    */
    // void glTexParameterIiv(GLenum target, GLenum pname, GLint* params);
    public static native void glTexParameterIiv(int target, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glTexParameterIiv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    */
    // void glTexParameterIuiv(GLenum target, GLenum pname, GLuint* params);
    public static native void glTexParameterIuiv(int target, int pname, IntBuffer params);

    /**
    * GL 3.0
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glTexParameterIuiv(int target, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.0
    * @param program
    * @param count
    * @param varyings
    * @param bufferMode
    */
    // void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar** varyings, GLenum bufferMode);
    public static native void glTransformFeedbackVaryings(int program, int count, String[] varyings, int bufferMode);

    /**
    * GL 3.0
    * @param location
    * @param v0
    */
    // void glUniform1ui(GLint location, GLuint v0);
    public static native void glUniform1ui(int location, int v0);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform1uiv(GLint location, GLsizei count, GLuint* value);
    public static native void glUniform1uiv(int location, int count, IntBuffer value);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform1uiv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 3.0
    * @param location
    * @param v0
    * @param v1
    */
    // void glUniform2ui(GLint location, GLuint v0, GLuint v1);
    public static native void glUniform2ui(int location, int v0, int v1);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform2uiv(GLint location, GLsizei count, GLuint* value);
    public static native void glUniform2uiv(int location, int count, IntBuffer value);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform2uiv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 3.0
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
    public static native void glUniform3ui(int location, int v0, int v1, int v2);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform3uiv(GLint location, GLsizei count, GLuint* value);
    public static native void glUniform3uiv(int location, int count, IntBuffer value);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform3uiv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 3.0
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    public static native void glUniform4ui(int location, int v0, int v1, int v2, int v3);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform4uiv(GLint location, GLsizei count, GLuint* value);
    public static native void glUniform4uiv(int location, int count, IntBuffer value);

    /**
    * GL 3.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform4uiv(int location, int count, int[] value, int valueOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    */
    // void glVertexAttribI1i(GLuint index, GLint x);
    public static native void glVertexAttribI1i(int index, int x);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI1iv(GLuint index, GLint* v);
    public static native void glVertexAttribI1iv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI1iv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    */
    // void glVertexAttribI1ui(GLuint index, GLuint x);
    public static native void glVertexAttribI1ui(int index, int x);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI1uiv(GLuint index, GLuint* v);
    public static native void glVertexAttribI1uiv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI1uiv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    * @param y
    */
    // void glVertexAttribI2i(GLuint index, GLint x, GLint y);
    public static native void glVertexAttribI2i(int index, int x, int y);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI2iv(GLuint index, GLint* v);
    public static native void glVertexAttribI2iv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI2iv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    * @param y
    */
    // void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
    public static native void glVertexAttribI2ui(int index, int x, int y);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI2uiv(GLuint index, GLuint* v);
    public static native void glVertexAttribI2uiv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI2uiv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    * @param y
    * @param z
    */
    // void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
    public static native void glVertexAttribI3i(int index, int x, int y, int z);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI3iv(GLuint index, GLint* v);
    public static native void glVertexAttribI3iv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI3iv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    * @param y
    * @param z
    */
    // void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
    public static native void glVertexAttribI3ui(int index, int x, int y, int z);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI3uiv(GLuint index, GLuint* v);
    public static native void glVertexAttribI3uiv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI3uiv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI4bv(GLuint index, GLbyte* v);
    public static native void glVertexAttribI4bv(int index, ByteBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI4bv(int index, byte[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
    public static native void glVertexAttribI4i(int index, int x, int y, int z, int w);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI4iv(GLuint index, GLint* v);
    public static native void glVertexAttribI4iv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI4iv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI4sv(GLuint index, GLshort* v);
    public static native void glVertexAttribI4sv(int index, ShortBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI4sv(int index, short[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI4ubv(GLuint index, GLubyte* v);
    public static native void glVertexAttribI4ubv(int index, ByteBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI4ubv(int index, byte[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    public static native void glVertexAttribI4ui(int index, int x, int y, int z, int w);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI4uiv(GLuint index, GLuint* v);
    public static native void glVertexAttribI4uiv(int index, IntBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI4uiv(int index, int[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param v
    */
    // void glVertexAttribI4usv(GLuint index, GLushort* v);
    public static native void glVertexAttribI4usv(int index, ShortBuffer v);

    /**
    * GL 3.0
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribI4usv(int index, short[] v, int vOffset);

    /**
    * GL 3.0
    * @param index
    * @param size
    * @param type
    * @param stride
    * @param pointer
    */
    // void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
    public static native void glVertexAttribIPointer(int index, int size, int type, int stride, Buffer pointer);

    /**
    * GL 3.0
    * @param index
    * @param size
    * @param type
    * @param stride
    * @param pointer
    */
    public static native void glVertexAttribIPointer(int index, int size, int type, int stride, long pointer);

    /**
    * GL 3.1
    * @param readTarget
    * @param writeTarget
    * @param readOffset
    * @param writeOffset
    * @param size
    */
    // void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    public static native void glCopyBufferSubData(int readTarget, int writeTarget, int readOffset, int writeOffset, int size);

    /**
    * GL 3.1
    * @param mode
    * @param first
    * @param count
    * @param primcount
    */
    // void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
    public static native void glDrawArraysInstanced(int mode, int first, int count, int primcount);

    /**
    * GL 3.1
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param primcount
    */
    // void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount);
    public static native void glDrawElementsInstanced(int mode, int count, int type, Buffer indices, int primcount);

    /**
    * GL 3.1
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param primcount
    */
    public static native void glDrawElementsInstanced(int mode, int count, int type, long indices, int primcount);

    /**
    * GL 3.1
    * @param program
    * @param uniformBlockIndex
    * @param bufSize
    * @param length
    * @param uniformBlockName
    */
    // void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
    public static native void glGetActiveUniformBlockName(int program, int uniformBlockIndex, int bufSize, IntBuffer length, ByteBuffer uniformBlockName);

    /**
    * GL 3.1
    * @param program
    * @param uniformBlockIndex
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param uniformBlockName
    * @param uniformBlockNameOffset
    */
    public static native void glGetActiveUniformBlockName(int program, int uniformBlockIndex, int bufSize, int[] length, int lengthOffset, byte[] uniformBlockName, int uniformBlockNameOffset);

    /**
    * GL 3.1
    * @param program
    * @param uniformBlockIndex
    * @param pname
    * @param params
    */
    // void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
    public static native void glGetActiveUniformBlockiv(int program, int uniformBlockIndex, int pname, IntBuffer params);

    /**
    * GL 3.1
    * @param program
    * @param uniformBlockIndex
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetActiveUniformBlockiv(int program, int uniformBlockIndex, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.1
    * @param program
    * @param uniformIndex
    * @param bufSize
    * @param length
    * @param uniformName
    */
    // void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
    public static native void glGetActiveUniformName(int program, int uniformIndex, int bufSize, IntBuffer length, ByteBuffer uniformName);

    /**
    * GL 3.1
    * @param program
    * @param uniformIndex
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param uniformName
    * @param uniformNameOffset
    */
    public static native void glGetActiveUniformName(int program, int uniformIndex, int bufSize, int[] length, int lengthOffset, byte[] uniformName, int uniformNameOffset);

    /**
    * GL 3.1
    * @param program
    * @param uniformCount
    * @param uniformIndices
    * @param pname
    * @param params
    */
    // void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint* uniformIndices, GLenum pname, GLint* params);
    public static native void glGetActiveUniformsiv(int program, int uniformCount, IntBuffer uniformIndices, int pname, IntBuffer params);

    /**
    * GL 3.1
    * @param program
    * @param uniformCount
    * @param uniformIndices
    * @param uniformIndicesOffset
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetActiveUniformsiv(int program, int uniformCount, int[] uniformIndices, int uniformIndicesOffset, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.1
    * @param program
    * @param uniformBlockName
    */
    // GLuint glGetUniformBlockIndex(GLuint program, GLchar* uniformBlockName);
    public static native int glGetUniformBlockIndex(int program, String uniformBlockName);

    /**
    * GL 3.1
    * @param program
    * @param uniformCount
    * @param uniformNames
    * @param uniformIndices
    */
    // void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar** uniformNames, GLuint* uniformIndices);
    public static native void glGetUniformIndices(int program, int uniformCount, String[] uniformNames, IntBuffer uniformIndices);

    /**
    * GL 3.1
    * @param program
    * @param uniformCount
    * @param uniformNames
    * @param uniformIndices
    * @param uniformIndicesOffset
    */
    public static native void glGetUniformIndices(int program, int uniformCount, String[] uniformNames, int[] uniformIndices, int uniformIndicesOffset);

    /**
    * GL 3.1
    * @param index
    */
    // void glPrimitiveRestartIndex(GLuint index);
    public static native void glPrimitiveRestartIndex(int index);

    /**
    * GL 3.1
    * @param target
    * @param internalformat
    * @param buffer
    */
    // void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
    public static native void glTexBuffer(int target, int internalformat, int buffer);

    /**
    * GL 3.1
    * @param program
    * @param uniformBlockIndex
    * @param uniformBlockBinding
    */
    // void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
    public static native void glUniformBlockBinding(int program, int uniformBlockIndex, int uniformBlockBinding);

    /**
    * GL 3.2
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param basevertex
    */
    // void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex);
    public static native void glDrawElementsBaseVertex(int mode, int count, int type, Buffer indices, int basevertex);

    /**
    * GL 3.2
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param basevertex
    */
    public static native void glDrawElementsBaseVertex(int mode, int count, int type, long indices, int basevertex);

    /**
    * GL 3.2
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param primcount
    * @param basevertex
    */
    // void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint basevertex);
    public static native void glDrawElementsInstancedBaseVertex(int mode, int count, int type, Buffer indices, int primcount, int basevertex);

    /**
    * GL 3.2
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param primcount
    * @param basevertex
    */
    public static native void glDrawElementsInstancedBaseVertex(int mode, int count, int type, long indices, int primcount, int basevertex);

    /**
    * GL 3.2
    * @param mode
    * @param start
    * @param end
    * @param count
    * @param type
    * @param indices
    * @param basevertex
    */
    // void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid* indices, GLint basevertex);
    public static native void glDrawRangeElementsBaseVertex(int mode, int start, int end, int count, int type, Buffer indices, int basevertex);

    /**
    * GL 3.2
    * @param mode
    * @param start
    * @param end
    * @param count
    * @param type
    * @param indices
    * @param basevertex
    */
    public static native void glDrawRangeElementsBaseVertex(int mode, int start, int end, int count, int type, long indices, int basevertex);

    /**
    * GL 3.2
    * @param target
    * @param attachment
    * @param texture
    * @param level
    */
    // void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
    public static native void glFramebufferTexture(int target, int attachment, int texture, int level);

    /**
    * GL 3.2
    * @param target
    * @param pname
    * @param params
    */
    // void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params);
    public static native void glGetBufferParameteri64v(int target, int pname, LongBuffer params);

    /**
    * GL 3.2
    * @param target
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetBufferParameteri64v(int target, int pname, long[] params, int paramsOffset);

    /**
    * GL 3.2
    * @param target
    * @param index
    * @param data
    */
    // void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data);
    public static native void glGetInteger64i_v(int target, int index, LongBuffer data);

    /**
    * GL 3.2
    * @param target
    * @param index
    * @param data
    * @param dataOffset
    */
    public static native void glGetInteger64i_v(int target, int index, long[] data, int dataOffset);

    /**
    * GL 3.2
    * @param pname
    * @param params
    */
    // void glGetInteger64v(GLenum pname, GLint64* params);
    public static native void glGetInteger64v(int pname, LongBuffer params);

    /**
    * GL 3.2
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetInteger64v(int pname, long[] params, int paramsOffset);

    /**
    * GL 3.2
    * @param pname
    * @param index
    * @param val
    */
    // void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val);
    public static native void glGetMultisamplefv(int pname, int index, FloatBuffer val);

    /**
    * GL 3.2
    * @param pname
    * @param index
    * @param val
    * @param valOffset
    */
    public static native void glGetMultisamplefv(int pname, int index, float[] val, int valOffset);

    /**
    * GL 3.2
    * @param mode
    * @param count
    * @param type
    * @param indices
    * @param primcount
    * @param basevertex
    */
    // void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei* count, GLenum type, GLvoid** indices, GLsizei primcount, GLint* basevertex);
    public static native void glMultiDrawElementsBaseVertex(int mode, IntBuffer count, int type, Buffer[] indices, int primcount, IntBuffer basevertex);

    /**
    * GL 3.2
    * @param mode
    * @param count
    * @param countOffset
    * @param type
    * @param indices
    * @param primcount
    * @param basevertex
    * @param basevertexOffset
    */
    public static native void glMultiDrawElementsBaseVertex(int mode, int[] count, int countOffset, int type, Buffer[] indices, int primcount, int[] basevertex, int basevertexOffset);

    /**
    * GL 3.2
    * @param mode
    */
    // void glProvokingVertex(GLenum mode);
    public static native void glProvokingVertex(int mode);

    /**
    * GL 3.2
    * @param index
    * @param mask
    */
    // void glSampleMaski(GLuint index, GLbitfield mask);
    public static native void glSampleMaski(int index, int mask);

    /**
    * GL 3.2
    * @param target
    * @param samples
    * @param internalformat
    * @param width
    * @param height
    * @param fixedsamplelocations
    */
    // void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    public static native void glTexImage2DMultisample(int target, int samples, int internalformat, int width, int height, boolean fixedsamplelocations);

    /**
    * GL 3.2
    * @param target
    * @param samples
    * @param internalformat
    * @param width
    * @param height
    * @param depth
    * @param fixedsamplelocations
    */
    // void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    public static native void glTexImage3DMultisample(int target, int samples, int internalformat, int width, int height, int depth, boolean fixedsamplelocations);

    /**
    * GL 3.3
    * @param program
    * @param colorNumber
    * @param index
    * @param name
    */
    // void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar* name);
    public static native void glBindFragDataLocationIndexed(int program, int colorNumber, int index, String name);

    /**
    * GL 3.3
    * @param unit
    * @param sampler
    */
    // void glBindSampler(GLuint unit, GLuint sampler);
    public static native void glBindSampler(int unit, int sampler);

    /**
    * GL 3.3
    * @param type
    * @param color
    */
    // void glColorP3ui(GLenum type, GLuint color);
    public static native void glColorP3ui(int type, int color);

    /**
    * GL 3.3
    * @param type
    * @param color
    */
    // void glColorP3uiv(GLenum type, GLuint* color);
    public static native void glColorP3uiv(int type, IntBuffer color);

    /**
    * GL 3.3
    * @param type
    * @param color
    * @param colorOffset
    */
    public static native void glColorP3uiv(int type, int[] color, int colorOffset);

    /**
    * GL 3.3
    * @param type
    * @param color
    */
    // void glColorP4ui(GLenum type, GLuint color);
    public static native void glColorP4ui(int type, int color);

    /**
    * GL 3.3
    * @param type
    * @param color
    */
    // void glColorP4uiv(GLenum type, GLuint* color);
    public static native void glColorP4uiv(int type, IntBuffer color);

    /**
    * GL 3.3
    * @param type
    * @param color
    * @param colorOffset
    */
    public static native void glColorP4uiv(int type, int[] color, int colorOffset);

    /**
    * GL 3.3
    * @param count
    * @param samplers
    */
    // void glDeleteSamplers(GLsizei count, GLuint* samplers);
    public static native void glDeleteSamplers(int count, IntBuffer samplers);

    /**
    * GL 3.3
    * @param count
    * @param samplers
    * @param samplersOffset
    */
    public static native void glDeleteSamplers(int count, int[] samplers, int samplersOffset);

    /**
    * GL 3.3
    * @param count
    * @param samplers
    */
    // void glGenSamplers(GLsizei count, GLuint* samplers);
    public static native void glGenSamplers(int count, IntBuffer samplers);

    /**
    * GL 3.3
    * @param count
    * @param samplers
    * @param samplersOffset
    */
    public static native void glGenSamplers(int count, int[] samplers, int samplersOffset);

    /**
    * GL 3.3
    * @param program
    * @param name
    */
    // GLint glGetFragDataIndex(GLuint program, GLchar* name);
    public static native int glGetFragDataIndex(int program, String name);

    /**
    * GL 3.3
    * @param id
    * @param pname
    * @param params
    */
    // void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params);
    public static native void glGetQueryObjecti64v(int id, int pname, LongBuffer params);

    /**
    * GL 3.3
    * @param id
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetQueryObjecti64v(int id, int pname, long[] params, int paramsOffset);

    /**
    * GL 3.3
    * @param id
    * @param pname
    * @param params
    */
    // void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params);
    public static native void glGetQueryObjectui64v(int id, int pname, LongBuffer params);

    /**
    * GL 3.3
    * @param id
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetQueryObjectui64v(int id, int pname, long[] params, int paramsOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    */
    // void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params);
    public static native void glGetSamplerParameterIiv(int sampler, int pname, IntBuffer params);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetSamplerParameterIiv(int sampler, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    */
    // void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params);
    public static native void glGetSamplerParameterIuiv(int sampler, int pname, IntBuffer params);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetSamplerParameterIuiv(int sampler, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    */
    // void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params);
    public static native void glGetSamplerParameterfv(int sampler, int pname, FloatBuffer params);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetSamplerParameterfv(int sampler, int pname, float[] params, int paramsOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    */
    // void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params);
    public static native void glGetSamplerParameteriv(int sampler, int pname, IntBuffer params);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetSamplerParameteriv(int sampler, int pname, int[] params, int paramsOffset);

    /**
    * GL 3.3
    * @param sampler
    */
    // GLboolean glIsSampler(GLuint sampler);
    public static native boolean glIsSampler(int sampler);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
    public static native void glMultiTexCoordP1ui(int texture, int type, int coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint* coords);
    public static native void glMultiTexCoordP1uiv(int texture, int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glMultiTexCoordP1uiv(int texture, int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
    public static native void glMultiTexCoordP2ui(int texture, int type, int coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint* coords);
    public static native void glMultiTexCoordP2uiv(int texture, int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glMultiTexCoordP2uiv(int texture, int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
    public static native void glMultiTexCoordP3ui(int texture, int type, int coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint* coords);
    public static native void glMultiTexCoordP3uiv(int texture, int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glMultiTexCoordP3uiv(int texture, int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
    public static native void glMultiTexCoordP4ui(int texture, int type, int coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    */
    // void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint* coords);
    public static native void glMultiTexCoordP4uiv(int texture, int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param texture
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glMultiTexCoordP4uiv(int texture, int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glNormalP3ui(GLenum type, GLuint coords);
    public static native void glNormalP3ui(int type, int coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glNormalP3uiv(GLenum type, GLuint* coords);
    public static native void glNormalP3uiv(int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glNormalP3uiv(int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param id
    * @param target
    */
    // void glQueryCounter(GLuint id, GLenum target);
    public static native void glQueryCounter(int id, int target);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    */
    // void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* param);
    public static native void glSamplerParameterIiv(int sampler, int pname, IntBuffer param);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    * @param paramOffset
    */
    public static native void glSamplerParameterIiv(int sampler, int pname, int[] param, int paramOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    */
    // void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* param);
    public static native void glSamplerParameterIuiv(int sampler, int pname, IntBuffer param);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    * @param paramOffset
    */
    public static native void glSamplerParameterIuiv(int sampler, int pname, int[] param, int paramOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    */
    // void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
    public static native void glSamplerParameterf(int sampler, int pname, float param);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    */
    // void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* param);
    public static native void glSamplerParameterfv(int sampler, int pname, FloatBuffer param);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    * @param paramOffset
    */
    public static native void glSamplerParameterfv(int sampler, int pname, float[] param, int paramOffset);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    */
    // void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
    public static native void glSamplerParameteri(int sampler, int pname, int param);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    */
    // void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint* param);
    public static native void glSamplerParameteriv(int sampler, int pname, IntBuffer param);

    /**
    * GL 3.3
    * @param sampler
    * @param pname
    * @param param
    * @param paramOffset
    */
    public static native void glSamplerParameteriv(int sampler, int pname, int[] param, int paramOffset);

    /**
    * GL 3.3
    * @param type
    * @param color
    */
    // void glSecondaryColorP3ui(GLenum type, GLuint color);
    public static native void glSecondaryColorP3ui(int type, int color);

    /**
    * GL 3.3
    * @param type
    * @param color
    */
    // void glSecondaryColorP3uiv(GLenum type, GLuint* color);
    public static native void glSecondaryColorP3uiv(int type, IntBuffer color);

    /**
    * GL 3.3
    * @param type
    * @param color
    * @param colorOffset
    */
    public static native void glSecondaryColorP3uiv(int type, int[] color, int colorOffset);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP1ui(GLenum type, GLuint coords);
    public static native void glTexCoordP1ui(int type, int coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP1uiv(GLenum type, GLuint* coords);
    public static native void glTexCoordP1uiv(int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glTexCoordP1uiv(int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP2ui(GLenum type, GLuint coords);
    public static native void glTexCoordP2ui(int type, int coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP2uiv(GLenum type, GLuint* coords);
    public static native void glTexCoordP2uiv(int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glTexCoordP2uiv(int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP3ui(GLenum type, GLuint coords);
    public static native void glTexCoordP3ui(int type, int coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP3uiv(GLenum type, GLuint* coords);
    public static native void glTexCoordP3uiv(int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glTexCoordP3uiv(int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP4ui(GLenum type, GLuint coords);
    public static native void glTexCoordP4ui(int type, int coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    */
    // void glTexCoordP4uiv(GLenum type, GLuint* coords);
    public static native void glTexCoordP4uiv(int type, IntBuffer coords);

    /**
    * GL 3.3
    * @param type
    * @param coords
    * @param coordsOffset
    */
    public static native void glTexCoordP4uiv(int type, int[] coords, int coordsOffset);

    /**
    * GL 3.3
    * @param index
    * @param divisor
    */
    // void glVertexAttribDivisor(GLuint index, GLuint divisor);
    public static native void glVertexAttribDivisor(int index, int divisor);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    public static native void glVertexAttribP1ui(int index, int type, boolean normalized, int value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
    public static native void glVertexAttribP1uiv(int index, int type, boolean normalized, IntBuffer value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    * @param valueOffset
    */
    public static native void glVertexAttribP1uiv(int index, int type, boolean normalized, int[] value, int valueOffset);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    public static native void glVertexAttribP2ui(int index, int type, boolean normalized, int value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
    public static native void glVertexAttribP2uiv(int index, int type, boolean normalized, IntBuffer value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    * @param valueOffset
    */
    public static native void glVertexAttribP2uiv(int index, int type, boolean normalized, int[] value, int valueOffset);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    public static native void glVertexAttribP3ui(int index, int type, boolean normalized, int value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
    public static native void glVertexAttribP3uiv(int index, int type, boolean normalized, IntBuffer value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    * @param valueOffset
    */
    public static native void glVertexAttribP3uiv(int index, int type, boolean normalized, int[] value, int valueOffset);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
    public static native void glVertexAttribP4ui(int index, int type, boolean normalized, int value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    */
    // void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint* value);
    public static native void glVertexAttribP4uiv(int index, int type, boolean normalized, IntBuffer value);

    /**
    * GL 3.3
    * @param index
    * @param type
    * @param normalized
    * @param value
    * @param valueOffset
    */
    public static native void glVertexAttribP4uiv(int index, int type, boolean normalized, int[] value, int valueOffset);

    /**
    * GL 3.3
    * @param type
    * @param value
    */
    // void glVertexP2ui(GLenum type, GLuint value);
    public static native void glVertexP2ui(int type, int value);

    /**
    * GL 3.3
    * @param type
    * @param value
    */
    // void glVertexP2uiv(GLenum type, GLuint* value);
    public static native void glVertexP2uiv(int type, IntBuffer value);

    /**
    * GL 3.3
    * @param type
    * @param value
    * @param valueOffset
    */
    public static native void glVertexP2uiv(int type, int[] value, int valueOffset);

    /**
    * GL 3.3
    * @param type
    * @param value
    */
    // void glVertexP3ui(GLenum type, GLuint value);
    public static native void glVertexP3ui(int type, int value);

    /**
    * GL 3.3
    * @param type
    * @param value
    */
    // void glVertexP3uiv(GLenum type, GLuint* value);
    public static native void glVertexP3uiv(int type, IntBuffer value);

    /**
    * GL 3.3
    * @param type
    * @param value
    * @param valueOffset
    */
    public static native void glVertexP3uiv(int type, int[] value, int valueOffset);

    /**
    * GL 3.3
    * @param type
    * @param value
    */
    // void glVertexP4ui(GLenum type, GLuint value);
    public static native void glVertexP4ui(int type, int value);

    /**
    * GL 3.3
    * @param type
    * @param value
    */
    // void glVertexP4uiv(GLenum type, GLuint* value);
    public static native void glVertexP4uiv(int type, IntBuffer value);

    /**
    * GL 3.3
    * @param type
    * @param value
    * @param valueOffset
    */
    public static native void glVertexP4uiv(int type, int[] value, int valueOffset);

    /**
    * GL 4.0
    * @param target
    * @param index
    * @param id
    */
    // void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
    public static native void glBeginQueryIndexed(int target, int index, int id);

    /**
    * GL 4.0
    * @param target
    * @param id
    */
    // void glBindTransformFeedback(GLenum target, GLuint id);
    public static native void glBindTransformFeedback(int target, int id);

    /**
    * GL 4.0
    * @param buf
    * @param modeRGB
    * @param modeAlpha
    */
    // void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    public static native void glBlendEquationSeparatei(int buf, int modeRGB, int modeAlpha);

    /**
    * GL 4.0
    * @param buf
    * @param mode
    */
    // void glBlendEquationi(GLuint buf, GLenum mode);
    public static native void glBlendEquationi(int buf, int mode);

    /**
    * GL 4.0
    * @param buf
    * @param srcRGB
    * @param dstRGB
    * @param srcAlpha
    * @param dstAlpha
    */
    // void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    public static native void glBlendFuncSeparatei(int buf, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);

    /**
    * GL 4.0
    * @param buf
    * @param src
    * @param dst
    */
    // void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
    public static native void glBlendFunci(int buf, int src, int dst);

    /**
    * GL 4.0
    * @param n
    * @param ids
    */
    // void glDeleteTransformFeedbacks(GLsizei n, GLuint* ids);
    public static native void glDeleteTransformFeedbacks(int n, IntBuffer ids);

    /**
    * GL 4.0
    * @param n
    * @param ids
    * @param idsOffset
    */
    public static native void glDeleteTransformFeedbacks(int n, int[] ids, int idsOffset);

    /**
    * GL 4.0
    * @param mode
    * @param indirect
    */
    // void glDrawArraysIndirect(GLenum mode, GLvoid* indirect);
    public static native void glDrawArraysIndirect(int mode, Buffer indirect);

    /**
    * GL 4.0
    * @param mode
    * @param indirect
    */
    public static native void glDrawArraysIndirect(int mode, long indirect);

    /**
    * GL 4.0
    * @param mode
    * @param type
    * @param indirect
    */
    // void glDrawElementsIndirect(GLenum mode, GLenum type, GLvoid* indirect);
    public static native void glDrawElementsIndirect(int mode, int type, Buffer indirect);

    /**
    * GL 4.0
    * @param mode
    * @param type
    * @param indirect
    */
    public static native void glDrawElementsIndirect(int mode, int type, long indirect);

    /**
    * GL 4.0
    * @param mode
    * @param id
    */
    // void glDrawTransformFeedback(GLenum mode, GLuint id);
    public static native void glDrawTransformFeedback(int mode, int id);

    /**
    * GL 4.0
    * @param mode
    * @param id
    * @param stream
    */
    // void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
    public static native void glDrawTransformFeedbackStream(int mode, int id, int stream);

    /**
    * GL 4.0
    * @param target
    * @param index
    */
    // void glEndQueryIndexed(GLenum target, GLuint index);
    public static native void glEndQueryIndexed(int target, int index);

    /**
    * GL 4.0
    * @param n
    * @param ids
    */
    // void glGenTransformFeedbacks(GLsizei n, GLuint* ids);
    public static native void glGenTransformFeedbacks(int n, IntBuffer ids);

    /**
    * GL 4.0
    * @param n
    * @param ids
    * @param idsOffset
    */
    public static native void glGenTransformFeedbacks(int n, int[] ids, int idsOffset);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param index
    * @param bufsize
    * @param length
    * @param name
    */
    // void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
    public static native void glGetActiveSubroutineName(int program, int shadertype, int index, int bufsize, IntBuffer length, ByteBuffer name);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param index
    * @param bufsize
    * @param length
    * @param lengthOffset
    * @param name
    * @param nameOffset
    */
    public static native void glGetActiveSubroutineName(int program, int shadertype, int index, int bufsize, int[] length, int lengthOffset, byte[] name, int nameOffset);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param index
    * @param bufsize
    * @param length
    * @param name
    */
    // void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
    public static native void glGetActiveSubroutineUniformName(int program, int shadertype, int index, int bufsize, IntBuffer length, ByteBuffer name);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param index
    * @param bufsize
    * @param length
    * @param lengthOffset
    * @param name
    * @param nameOffset
    */
    public static native void glGetActiveSubroutineUniformName(int program, int shadertype, int index, int bufsize, int[] length, int lengthOffset, byte[] name, int nameOffset);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param index
    * @param pname
    * @param values
    */
    // void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
    public static native void glGetActiveSubroutineUniformiv(int program, int shadertype, int index, int pname, IntBuffer values);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param index
    * @param pname
    * @param values
    * @param valuesOffset
    */
    public static native void glGetActiveSubroutineUniformiv(int program, int shadertype, int index, int pname, int[] values, int valuesOffset);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param pname
    * @param values
    */
    // void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
    public static native void glGetProgramStageiv(int program, int shadertype, int pname, IntBuffer values);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param pname
    * @param values
    * @param valuesOffset
    */
    public static native void glGetProgramStageiv(int program, int shadertype, int pname, int[] values, int valuesOffset);

    /**
    * GL 4.0
    * @param target
    * @param index
    * @param pname
    * @param params
    */
    // void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params);
    public static native void glGetQueryIndexediv(int target, int index, int pname, IntBuffer params);

    /**
    * GL 4.0
    * @param target
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetQueryIndexediv(int target, int index, int pname, int[] params, int paramsOffset);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param name
    */
    // GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar* name);
    public static native int glGetSubroutineIndex(int program, int shadertype, String name);

    /**
    * GL 4.0
    * @param program
    * @param shadertype
    * @param name
    */
    // GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar* name);
    public static native int glGetSubroutineUniformLocation(int program, int shadertype, String name);

    /**
    * GL 4.0
    * @param shadertype
    * @param location
    * @param params
    */
    // void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params);
    public static native void glGetUniformSubroutineuiv(int shadertype, int location, IntBuffer params);

    /**
    * GL 4.0
    * @param shadertype
    * @param location
    * @param params
    * @param paramsOffset
    */
    public static native void glGetUniformSubroutineuiv(int shadertype, int location, int[] params, int paramsOffset);

    /**
    * GL 4.0
    * @param program
    * @param location
    * @param params
    */
    // void glGetUniformdv(GLuint program, GLint location, GLdouble* params);
    public static native void glGetUniformdv(int program, int location, DoubleBuffer params);

    /**
    * GL 4.0
    * @param program
    * @param location
    * @param params
    * @param paramsOffset
    */
    public static native void glGetUniformdv(int program, int location, double[] params, int paramsOffset);

    /**
    * GL 4.0
    * @param id
    */
    // GLboolean glIsTransformFeedback(GLuint id);
    public static native boolean glIsTransformFeedback(int id);

    /**
    * GL 4.0
    * @param value
    */
    // void glMinSampleShading(GLclampf value);
    public static native void glMinSampleShading(float value);

    /**
    * GL 4.0
    * @param pname
    * @param values
    */
    // void glPatchParameterfv(GLenum pname, GLfloat* values);
    public static native void glPatchParameterfv(int pname, FloatBuffer values);

    /**
    * GL 4.0
    * @param pname
    * @param values
    * @param valuesOffset
    */
    public static native void glPatchParameterfv(int pname, float[] values, int valuesOffset);

    /**
    * GL 4.0
    * @param pname
    * @param value
    */
    // void glPatchParameteri(GLenum pname, GLint value);
    public static native void glPatchParameteri(int pname, int value);

    /**
    * GL 4.0
    */
    // void glPauseTransformFeedback();
    public static native void glPauseTransformFeedback();

    /**
    * GL 4.0
    */
    // void glResumeTransformFeedback();
    public static native void glResumeTransformFeedback();

    /**
    * GL 4.0
    * @param location
    * @param x
    */
    // void glUniform1d(GLint location, GLdouble x);
    public static native void glUniform1d(int location, double x);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform1dv(GLint location, GLsizei count, GLdouble* value);
    public static native void glUniform1dv(int location, int count, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform1dv(int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param x
    * @param y
    */
    // void glUniform2d(GLint location, GLdouble x, GLdouble y);
    public static native void glUniform2d(int location, double x, double y);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform2dv(GLint location, GLsizei count, GLdouble* value);
    public static native void glUniform2dv(int location, int count, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform2dv(int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param x
    * @param y
    * @param z
    */
    // void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
    public static native void glUniform3d(int location, double x, double y, double z);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform3dv(GLint location, GLsizei count, GLdouble* value);
    public static native void glUniform3dv(int location, int count, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform3dv(int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    public static native void glUniform4d(int location, double x, double y, double z, double w);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    */
    // void glUniform4dv(GLint location, GLsizei count, GLdouble* value);
    public static native void glUniform4dv(int location, int count, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glUniform4dv(int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix2dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix2dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix2x3dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix2x3dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix2x4dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix2x4dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix3dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix3dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix3x2dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix3x2dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix3x4dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix3x4dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix4dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix4dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix4x2dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix4x2dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glUniformMatrix4x3dv(int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.0
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glUniformMatrix4x3dv(int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.0
    * @param shadertype
    * @param count
    * @param indices
    */
    // void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint* indices);
    public static native void glUniformSubroutinesuiv(int shadertype, int count, IntBuffer indices);

    /**
    * GL 4.0
    * @param shadertype
    * @param count
    * @param indices
    * @param indicesOffset
    */
    public static native void glUniformSubroutinesuiv(int shadertype, int count, int[] indices, int indicesOffset);

    /**
    * GL 4.1
    * @param pipeline
    * @param program
    */
    // void glActiveShaderProgram(GLuint pipeline, GLuint program);
    public static native void glActiveShaderProgram(int pipeline, int program);

    /**
    * GL 4.1
    * @param pipeline
    */
    // void glBindProgramPipeline(GLuint pipeline);
    public static native void glBindProgramPipeline(int pipeline);

    /**
    * GL 4.1
    * @param d
    */
    // void glClearDepthf(GLclampf d);
    public static native void glClearDepthf(float d);

    /**
    * GL 4.1
    * @param type
    * @param count
    * @param strings
    */
    // GLuint glCreateShaderProgramv(GLenum type, GLsizei count, GLchar** strings);
    public static native int glCreateShaderProgramv(int type, int count, String[] strings);

    /**
    * GL 4.1
    * @param n
    * @param pipelines
    */
    // void glDeleteProgramPipelines(GLsizei n, GLuint* pipelines);
    public static native void glDeleteProgramPipelines(int n, IntBuffer pipelines);

    /**
    * GL 4.1
    * @param n
    * @param pipelines
    * @param pipelinesOffset
    */
    public static native void glDeleteProgramPipelines(int n, int[] pipelines, int pipelinesOffset);

    /**
    * GL 4.1
    * @param first
    * @param count
    * @param v
    */
    // void glDepthRangeArrayv(GLuint first, GLsizei count, GLclampd* v);
    public static native void glDepthRangeArrayv(int first, int count, DoubleBuffer v);

    /**
    * GL 4.1
    * @param first
    * @param count
    * @param v
    * @param vOffset
    */
    public static native void glDepthRangeArrayv(int first, int count, double[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param n
    * @param f
    */
    // void glDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f);
    public static native void glDepthRangeIndexed(int index, double n, double f);

    /**
    * GL 4.1
    * @param n
    * @param f
    */
    // void glDepthRangef(GLclampf n, GLclampf f);
    public static native void glDepthRangef(float n, float f);

    /**
    * GL 4.1
    * @param n
    * @param pipelines
    */
    // void glGenProgramPipelines(GLsizei n, GLuint* pipelines);
    public static native void glGenProgramPipelines(int n, IntBuffer pipelines);

    /**
    * GL 4.1
    * @param n
    * @param pipelines
    * @param pipelinesOffset
    */
    public static native void glGenProgramPipelines(int n, int[] pipelines, int pipelinesOffset);

    /**
    * GL 4.1
    * @param target
    * @param index
    * @param data
    */
    // void glGetDoublei_v(GLenum target, GLuint index, GLdouble* data);
    public static native void glGetDoublei_v(int target, int index, DoubleBuffer data);

    /**
    * GL 4.1
    * @param target
    * @param index
    * @param data
    * @param dataOffset
    */
    public static native void glGetDoublei_v(int target, int index, double[] data, int dataOffset);

    /**
    * GL 4.1
    * @param target
    * @param index
    * @param data
    */
    // void glGetFloati_v(GLenum target, GLuint index, GLfloat* data);
    public static native void glGetFloati_v(int target, int index, FloatBuffer data);

    /**
    * GL 4.1
    * @param target
    * @param index
    * @param data
    * @param dataOffset
    */
    public static native void glGetFloati_v(int target, int index, float[] data, int dataOffset);

    /**
    * GL 4.1
    * @param program
    * @param bufSize
    * @param length
    * @param binaryFormat
    * @param binary
    */
    // void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
    public static native void glGetProgramBinary(int program, int bufSize, IntBuffer length, IntBuffer binaryFormat, Buffer binary);

    /**
    * GL 4.1
    * @param program
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param binaryFormat
    * @param binaryFormatOffset
    * @param binary
    */
    public static native void glGetProgramBinary(int program, int bufSize, int[] length, int lengthOffset, int[] binaryFormat, int binaryFormatOffset, long binary);

    /**
    * GL 4.1
    * @param pipeline
    * @param bufSize
    * @param length
    * @param infoLog
    */
    // void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
    public static native void glGetProgramPipelineInfoLog(int pipeline, int bufSize, IntBuffer length, ByteBuffer infoLog);

    /**
    * GL 4.1
    * @param pipeline
    * @param bufSize
    * @param length
    * @param lengthOffset
    * @param infoLog
    * @param infoLogOffset
    */
    public static native void glGetProgramPipelineInfoLog(int pipeline, int bufSize, int[] length, int lengthOffset, byte[] infoLog, int infoLogOffset);

    /**
    * GL 4.1
    * @param pipeline
    * @param pname
    * @param params
    */
    // void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params);
    public static native void glGetProgramPipelineiv(int pipeline, int pname, IntBuffer params);

    /**
    * GL 4.1
    * @param pipeline
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetProgramPipelineiv(int pipeline, int pname, int[] params, int paramsOffset);

    /**
    * GL 4.1
    * @param shadertype
    * @param precisiontype
    * @param range
    * @param precision
    */
    // void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
    public static native void glGetShaderPrecisionFormat(int shadertype, int precisiontype, IntBuffer range, IntBuffer precision);

    /**
    * GL 4.1
    * @param shadertype
    * @param precisiontype
    * @param range
    * @param rangeOffset
    * @param precision
    * @param precisionOffset
    */
    public static native void glGetShaderPrecisionFormat(int shadertype, int precisiontype, int[] range, int rangeOffset, int[] precision, int precisionOffset);

    /**
    * GL 4.1
    * @param index
    * @param pname
    * @param params
    */
    // void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params);
    public static native void glGetVertexAttribLdv(int index, int pname, DoubleBuffer params);

    /**
    * GL 4.1
    * @param index
    * @param pname
    * @param params
    * @param paramsOffset
    */
    public static native void glGetVertexAttribLdv(int index, int pname, double[] params, int paramsOffset);

    /**
    * GL 4.1
    * @param pipeline
    */
    // GLboolean glIsProgramPipeline(GLuint pipeline);
    public static native boolean glIsProgramPipeline(int pipeline);

    /**
    * GL 4.1
    * @param program
    * @param binaryFormat
    * @param binary
    * @param length
    */
    // void glProgramBinary(GLuint program, GLenum binaryFormat, GLvoid* binary, GLsizei length);
    public static native void glProgramBinary(int program, int binaryFormat, Buffer binary, int length);

    /**
    * GL 4.1
    * @param program
    * @param binaryFormat
    * @param binary
    * @param length
    */
    public static native void glProgramBinary(int program, int binaryFormat, long binary, int length);

    /**
    * GL 4.1
    * @param program
    * @param pname
    * @param value
    */
    // void glProgramParameteri(GLuint program, GLenum pname, GLint value);
    public static native void glProgramParameteri(int program, int pname, int value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    */
    // void glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
    public static native void glProgramUniform1d(int program, int location, double v0);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
    public static native void glProgramUniform1dv(int program, int location, int count, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform1dv(int program, int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    */
    // void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
    public static native void glProgramUniform1f(int program, int location, float v0);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
    public static native void glProgramUniform1fv(int program, int location, int count, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform1fv(int program, int location, int count, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    */
    // void glProgramUniform1i(GLuint program, GLint location, GLint v0);
    public static native void glProgramUniform1i(int program, int location, int v0);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint* value);
    public static native void glProgramUniform1iv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform1iv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    */
    // void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
    public static native void glProgramUniform1ui(int program, int location, int v0);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
    public static native void glProgramUniform1uiv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform1uiv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    */
    // void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
    public static native void glProgramUniform2d(int program, int location, double v0, double v1);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
    public static native void glProgramUniform2dv(int program, int location, int count, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform2dv(int program, int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    */
    // void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
    public static native void glProgramUniform2f(int program, int location, float v0, float v1);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
    public static native void glProgramUniform2fv(int program, int location, int count, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform2fv(int program, int location, int count, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    */
    // void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
    public static native void glProgramUniform2i(int program, int location, int v0, int v1);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint* value);
    public static native void glProgramUniform2iv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform2iv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    */
    // void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
    public static native void glProgramUniform2ui(int program, int location, int v0, int v1);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
    public static native void glProgramUniform2uiv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform2uiv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
    public static native void glProgramUniform3d(int program, int location, double v0, double v1, double v2);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
    public static native void glProgramUniform3dv(int program, int location, int count, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform3dv(int program, int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    public static native void glProgramUniform3f(int program, int location, float v0, float v1, float v2);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
    public static native void glProgramUniform3fv(int program, int location, int count, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform3fv(int program, int location, int count, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    public static native void glProgramUniform3i(int program, int location, int v0, int v1, int v2);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint* value);
    public static native void glProgramUniform3iv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform3iv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    */
    // void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    public static native void glProgramUniform3ui(int program, int location, int v0, int v1, int v2);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
    public static native void glProgramUniform3uiv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform3uiv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
    public static native void glProgramUniform4d(int program, int location, double v0, double v1, double v2, double v3);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble* value);
    public static native void glProgramUniform4dv(int program, int location, int count, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform4dv(int program, int location, int count, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    public static native void glProgramUniform4f(int program, int location, float v0, float v1, float v2, float v3);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat* value);
    public static native void glProgramUniform4fv(int program, int location, int count, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform4fv(int program, int location, int count, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    public static native void glProgramUniform4i(int program, int location, int v0, int v1, int v2, int v3);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint* value);
    public static native void glProgramUniform4iv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform4iv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param v0
    * @param v1
    * @param v2
    * @param v3
    */
    // void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    public static native void glProgramUniform4ui(int program, int location, int v0, int v1, int v2, int v3);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    */
    // void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint* value);
    public static native void glProgramUniform4uiv(int program, int location, int count, IntBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniform4uiv(int program, int location, int count, int[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix2dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix2dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix2fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix2fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix2x3dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix2x3dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix2x3fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix2x3fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix2x4dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix2x4dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix2x4fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix2x4fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix3dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix3dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix3fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix3fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix3x2dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix3x2dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix3x2fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix3x2fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix3x4dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix3x4dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix3x4fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix3x4fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix4dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix4dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix4fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix4fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix4x2dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix4x2dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix4x2fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix4x2fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble* value);
    public static native void glProgramUniformMatrix4x3dv(int program, int location, int count, boolean transpose, DoubleBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix4x3dv(int program, int location, int count, boolean transpose, double[] value, int valueOffset);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    */
    // void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
    public static native void glProgramUniformMatrix4x3fv(int program, int location, int count, boolean transpose, FloatBuffer value);

    /**
    * GL 4.1
    * @param program
    * @param location
    * @param count
    * @param transpose
    * @param value
    * @param valueOffset
    */
    public static native void glProgramUniformMatrix4x3fv(int program, int location, int count, boolean transpose, float[] value, int valueOffset);

    /**
    * GL 4.1
    */
    // void glReleaseShaderCompiler();
    public static native void glReleaseShaderCompiler();

    /**
    * GL 4.1
    * @param first
    * @param count
    * @param v
    */
    // void glScissorArrayv(GLuint first, GLsizei count, GLint* v);
    public static native void glScissorArrayv(int first, int count, IntBuffer v);

    /**
    * GL 4.1
    * @param first
    * @param count
    * @param v
    * @param vOffset
    */
    public static native void glScissorArrayv(int first, int count, int[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param left
    * @param bottom
    * @param width
    * @param height
    */
    // void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
    public static native void glScissorIndexed(int index, int left, int bottom, int width, int height);

    /**
    * GL 4.1
    * @param index
    * @param v
    */
    // void glScissorIndexedv(GLuint index, GLint* v);
    public static native void glScissorIndexedv(int index, IntBuffer v);

    /**
    * GL 4.1
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glScissorIndexedv(int index, int[] v, int vOffset);

    /**
    * GL 4.1
    * @param count
    * @param shaders
    * @param binaryformat
    * @param binary
    * @param length
    */
    // void glShaderBinary(GLsizei count, GLuint* shaders, GLenum binaryformat, GLvoid* binary, GLsizei length);
    public static native void glShaderBinary(int count, IntBuffer shaders, int binaryformat, Buffer binary, int length);

    /**
    * GL 4.1
    * @param count
    * @param shaders
    * @param shadersOffset
    * @param binaryformat
    * @param binary
    * @param length
    */
    public static native void glShaderBinary(int count, int[] shaders, int shadersOffset, int binaryformat, long binary, int length);

    /**
    * GL 4.1
    * @param pipeline
    * @param stages
    * @param program
    */
    // void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
    public static native void glUseProgramStages(int pipeline, int stages, int program);

    /**
    * GL 4.1
    * @param pipeline
    */
    // void glValidateProgramPipeline(GLuint pipeline);
    public static native void glValidateProgramPipeline(int pipeline);

    /**
    * GL 4.1
    * @param index
    * @param x
    */
    // void glVertexAttribL1d(GLuint index, GLdouble x);
    public static native void glVertexAttribL1d(int index, double x);

    /**
    * GL 4.1
    * @param index
    * @param v
    */
    // void glVertexAttribL1dv(GLuint index, GLdouble* v);
    public static native void glVertexAttribL1dv(int index, DoubleBuffer v);

    /**
    * GL 4.1
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribL1dv(int index, double[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param x
    * @param y
    */
    // void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
    public static native void glVertexAttribL2d(int index, double x, double y);

    /**
    * GL 4.1
    * @param index
    * @param v
    */
    // void glVertexAttribL2dv(GLuint index, GLdouble* v);
    public static native void glVertexAttribL2dv(int index, DoubleBuffer v);

    /**
    * GL 4.1
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribL2dv(int index, double[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param x
    * @param y
    * @param z
    */
    // void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
    public static native void glVertexAttribL3d(int index, double x, double y, double z);

    /**
    * GL 4.1
    * @param index
    * @param v
    */
    // void glVertexAttribL3dv(GLuint index, GLdouble* v);
    public static native void glVertexAttribL3dv(int index, DoubleBuffer v);

    /**
    * GL 4.1
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribL3dv(int index, double[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param x
    * @param y
    * @param z
    * @param w
    */
    // void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    public static native void glVertexAttribL4d(int index, double x, double y, double z, double w);

    /**
    * GL 4.1
    * @param index
    * @param v
    */
    // void glVertexAttribL4dv(GLuint index, GLdouble* v);
    public static native void glVertexAttribL4dv(int index, DoubleBuffer v);

    /**
    * GL 4.1
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glVertexAttribL4dv(int index, double[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param size
    * @param type
    * @param stride
    * @param pointer
    */
    // void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
    public static native void glVertexAttribLPointer(int index, int size, int type, int stride, Buffer pointer);

    /**
    * GL 4.1
    * @param index
    * @param size
    * @param type
    * @param stride
    * @param pointer
    */
    public static native void glVertexAttribLPointer(int index, int size, int type, int stride, long pointer);

    /**
    * GL 4.1
    * @param first
    * @param count
    * @param v
    */
    // void glViewportArrayv(GLuint first, GLsizei count, GLfloat* v);
    public static native void glViewportArrayv(int first, int count, FloatBuffer v);

    /**
    * GL 4.1
    * @param first
    * @param count
    * @param v
    * @param vOffset
    */
    public static native void glViewportArrayv(int first, int count, float[] v, int vOffset);

    /**
    * GL 4.1
    * @param index
    * @param x
    * @param y
    * @param w
    * @param h
    */
    // void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
    public static native void glViewportIndexedf(int index, float x, float y, float w, float h);

    /**
    * GL 4.1
    * @param index
    * @param v
    */
    // void glViewportIndexedfv(GLuint index, GLfloat* v);
    public static native void glViewportIndexedfv(int index, FloatBuffer v);

    /**
    * GL 4.1
    * @param index
    * @param v
    * @param vOffset
    */
    public static native void glViewportIndexedfv(int index, float[] v, int vOffset);
}

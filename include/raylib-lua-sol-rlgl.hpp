#ifndef RAYLIB_LUA_SOL_RLGL_
#define RAYLIB_LUA_SOL_RLGL_

#include "raylib.h"
#include "sol/sol.hpp"

#include "rlgl.h"

#ifndef RAYLIB_LUA_SOL_ADD_ENUM
#define RAYLIB_LUA_SOL_ADD_ENUM(x) \
  lua[#x] = x
#endif

void raylib_lua_sol_rlgl(sol::state& lua) {
  lua["RL_DEFAULT_BATCH_BUFFER_ELEMENTS"] = RL_DEFAULT_BATCH_BUFFER_ELEMENTS;
  lua["RL_DEFAULT_BATCH_BUFFERS"] = RL_DEFAULT_BATCH_BUFFERS;
  lua["RL_DEFAULT_BATCH_DRAWCALLS"] = RL_DEFAULT_BATCH_DRAWCALLS;
  lua["RL_DEFAULT_BATCH_MAX_TEXTURE_UNITS"] = RL_DEFAULT_BATCH_MAX_TEXTURE_UNITS;
  lua["RL_MAX_MATRIX_STACK_SIZE"] = RL_MAX_MATRIX_STACK_SIZE;
  lua["RL_MAX_SHADER_LOCATIONS"] = RL_MAX_SHADER_LOCATIONS;
  lua["RL_CULL_DISTANCE_NEAR"] = RL_CULL_DISTANCE_NEAR;
  lua["RL_CULL_DISTANCE_FAR"] = RL_CULL_DISTANCE_FAR;

  lua["RL_TEXTURE_WRAP_S"] = RL_TEXTURE_WRAP_S;
  lua["RL_TEXTURE_WRAP_T"] = RL_TEXTURE_WRAP_T;
  lua["RL_TEXTURE_MAG_FILTER"] = RL_TEXTURE_MAG_FILTER;
  lua["RL_TEXTURE_MIN_FILTER"] = RL_TEXTURE_MIN_FILTER;

  lua["RL_TEXTURE_FILTER_NEAREST"] = RL_TEXTURE_FILTER_NEAREST;
  lua["RL_TEXTURE_FILTER_LINEAR"] = RL_TEXTURE_FILTER_LINEAR;
  lua["RL_TEXTURE_FILTER_MIP_NEAREST"] = RL_TEXTURE_FILTER_MIP_NEAREST;
  lua["RL_TEXTURE_FILTER_NEAREST_MIP_LINEAR"] = RL_TEXTURE_FILTER_NEAREST_MIP_LINEAR;
  lua["RL_TEXTURE_FILTER_LINEAR_MIP_NEAREST"] = RL_TEXTURE_FILTER_LINEAR_MIP_NEAREST;
  lua["RL_TEXTURE_FILTER_MIP_LINEAR"] = RL_TEXTURE_FILTER_MIP_LINEAR;
  lua["RL_TEXTURE_FILTER_ANISOTROPIC"] = RL_TEXTURE_FILTER_ANISOTROPIC;
  lua["RL_TEXTURE_MIPMAP_BIAS_RATIO"] = RL_TEXTURE_MIPMAP_BIAS_RATIO;

  lua["RL_TEXTURE_WRAP_REPEAT"] = RL_TEXTURE_WRAP_REPEAT;
  lua["RL_TEXTURE_WRAP_CLAMP"] = RL_TEXTURE_WRAP_CLAMP;
  lua["RL_TEXTURE_WRAP_MIRROR_REPEAT"] = RL_TEXTURE_WRAP_MIRROR_REPEAT;
  lua["RL_TEXTURE_WRAP_MIRROR_CLAMP"] = RL_TEXTURE_WRAP_MIRROR_CLAMP;

  lua["RL_MODELVIEW"] = RL_MODELVIEW;
  lua["RL_PROJECTION"] = RL_PROJECTION;
  lua["RL_TEXTURE"] = RL_TEXTURE;

  lua["RL_LINES"] = RL_LINES;
  lua["RL_TRIANGLES"] = RL_TRIANGLES;
  lua["RL_QUADS"] = RL_QUADS;

  lua["RL_UNSIGNED_BYTE"] = RL_UNSIGNED_BYTE;
  lua["RL_FLOAT"] = RL_FLOAT;

  lua["RL_STREAM_DRAW"] = RL_STREAM_DRAW;
  lua["RL_STREAM_READ"] = RL_STREAM_READ;
  lua["RL_STREAM_COPY"] = RL_STREAM_COPY;
  lua["RL_STATIC_DRAW"] = RL_STATIC_DRAW;
  lua["RL_STATIC_READ"] = RL_STATIC_READ;
  lua["RL_STATIC_COPY"] = RL_STATIC_COPY;
  lua["RL_DYNAMIC_DRAW"] = RL_DYNAMIC_DRAW;
  lua["RL_DYNAMIC_READ"] = RL_DYNAMIC_READ;
  lua["RL_DYNAMIC_COPY"] = RL_DYNAMIC_COPY;

  lua["RL_FRAGMENT_SHADER"] = RL_FRAGMENT_SHADER;
  lua["RL_VERTEX_SHADER"] = RL_VERTEX_SHADER;
  lua["RL_COMPUTE_SHADER"] = RL_COMPUTE_SHADER;

  lua["RL_ZERO"] = RL_ZERO;
  lua["RL_ONE"] = RL_ONE;
  lua["RL_SRC_COLOR"] = RL_SRC_COLOR;
  lua["RL_ONE_MINUS_SRC_COLOR"] = RL_ONE_MINUS_SRC_COLOR;
  lua["RL_SRC_ALPHA"] = RL_SRC_ALPHA;
  lua["RL_ONE_MINUS_SRC_ALPHA"] = RL_ONE_MINUS_SRC_ALPHA;
  lua["RL_DST_ALPHA"] = RL_DST_ALPHA;
  lua["RL_ONE_MINUS_DST_ALPHA"] = RL_ONE_MINUS_DST_ALPHA;
  lua["RL_DST_COLOR"] = RL_DST_COLOR;
  lua["RL_ONE_MINUS_DST_COLOR"] = RL_ONE_MINUS_DST_COLOR;
  lua["RL_SRC_ALPHA_SATURATE"] = RL_SRC_ALPHA_SATURATE;
  lua["RL_CONSTANT_COLOR"] = RL_CONSTANT_COLOR;
  lua["RL_ONE_MINUS_CONSTANT_COLOR"] = RL_ONE_MINUS_CONSTANT_COLOR;
  lua["RL_CONSTANT_ALPHA"] = RL_CONSTANT_ALPHA;
  lua["RL_ONE_MINUS_CONSTANT_ALPHA"] = RL_ONE_MINUS_CONSTANT_ALPHA;

  lua["RL_FUNC_ADD"] = RL_FUNC_ADD;
  lua["RL_MIN"] = RL_MIN;
  lua["RL_MAX"] = RL_MAX;
  lua["RL_FUNC_SUBTRACT"] = RL_FUNC_SUBTRACT;
  lua["RL_FUNC_REVERSE_SUBTRACT"] = RL_FUNC_REVERSE_SUBTRACT;
  lua["RL_BLEND_EQUATION"] = RL_BLEND_EQUATION;
  lua["RL_BLEND_EQUATION_RGB"] = RL_BLEND_EQUATION_RGB;
  lua["RL_BLEND_EQUATION_ALPHA"] = RL_BLEND_EQUATION_ALPHA;
  lua["RL_BLEND_DST_RGB"] = RL_BLEND_DST_RGB;
  lua["RL_BLEND_SRC_RGB"] = RL_BLEND_SRC_RGB;
  lua["RL_BLEND_DST_ALPHA"] = RL_BLEND_DST_ALPHA;
  lua["RL_BLEND_SRC_ALPHA"] = RL_BLEND_SRC_ALPHA;
  lua["RL_BLEND_COLOR"] = RL_BLEND_COLOR;

  lua["RL_READ_FRAMEBUFFER"] = RL_READ_FRAMEBUFFER;
  lua["RL_DRAW_FRAMEBUFFER"] = RL_DRAW_FRAMEBUFFER;

  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_SOFTWARE);
  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_11);
  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_21);
  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_33);
  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_43);
  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_ES_20);
  RAYLIB_LUA_SOL_ADD_ENUM(RL_OPENGL_ES_30);

  lua.set_function("rlMatrixMode", rlMatrixMode);
  lua.set_function("rlPushMatrix", rlPushMatrix);
  lua.set_function("rlPopMatrix", rlPopMatrix);
  lua.set_function("rlLoadIdentity", rlLoadIdentity);
  lua.set_function("rlTranslatef", rlTranslatef);
  lua.set_function("rlRotatef", rlRotatef);
  lua.set_function("rlScalef", rlScalef);
  lua.set_function("rlFrustum", rlFrustum);
  lua.set_function("rlOrtho", rlOrtho);
  lua.set_function("rlViewport", rlViewport);
  lua.set_function("rlSetClipPlanes", rlSetClipPlanes);
  lua.set_function("rlGetCullDistanceNear", rlGetCullDistanceNear);
  lua.set_function("rlGetCullDistanceFar", rlGetCullDistanceFar);

  lua.set_function("rlBegin", rlBegin);
  lua.set_function("rlEnd", rlEnd);
  lua.set_function("rlVertex2i", rlVertex2i);
  lua.set_function("rlVertex2f", rlVertex2f);
  lua.set_function("rlVertex3f", rlVertex3f);
  lua.set_function("rlTexCoord2f", rlTexCoord2f);
  lua.set_function("rlNormal3f", rlNormal3f);
  lua.set_function("rlColor4ub", rlColor4ub);
  lua.set_function("rlColor3f", rlColor3f);
  lua.set_function("rlColor4f", rlColor4f);

  lua.set_function("rlEnableVertexArray", rlEnableVertexArray);
  lua.set_function("rlDisableVertexArray", rlDisableVertexArray);
  lua.set_function("rlEnableVertexBuffer", rlEnableVertexBuffer);
  lua.set_function("rlDisableVertexBuffer", rlDisableVertexBuffer);
  lua.set_function("rlEnableVertexBufferElement", rlEnableVertexBufferElement);
  lua.set_function("rlDisableVertexBufferElement", rlDisableVertexBufferElement);
  lua.set_function("rlEnableVertexAttribute", rlEnableVertexAttribute);
  lua.set_function("rlDisableVertexAttribute", rlDisableVertexAttribute);

  lua.set_function("rlActiveTextureSlot", rlActiveTextureSlot);
  lua.set_function("rlEnableTexture", rlEnableTexture);
  lua.set_function("rlDisableTexture", rlDisableTexture);
  lua.set_function("rlEnableTextureCubemap", rlEnableTextureCubemap);
  lua.set_function("rlDisableTextureCubemap", rlDisableTextureCubemap);
  lua.set_function("rlTextureParameters", rlTextureParameters);
  lua.set_function("rlCubemapParameters", rlCubemapParameters);

  lua.set_function("rlEnableShader", rlEnableShader);
  lua.set_function("rlDisableShader", rlDisableShader);

  lua.set_function("rlEnableFramebuffer", rlEnableFramebuffer);
  lua.set_function("rlDisableFramebuffer", rlDisableFramebuffer);
  lua.set_function("rlGetActiveFramebuffer", rlGetActiveFramebuffer);
  lua.set_function("rlActiveDrawBuffers", rlActiveDrawBuffers);
  lua.set_function("rlBlitFramebuffer", rlBlitFramebuffer);
  lua.set_function("rlBindFramebuffer", rlBindFramebuffer);

  lua.set_function("rlEnableColorBlend", rlEnableColorBlend);
  lua.set_function("rlDisableColorBlend", rlDisableColorBlend);
  lua.set_function("rlEnableDepthTest", rlEnableDepthTest);
  lua.set_function("rlDisableDepthTest", rlDisableDepthTest);
  lua.set_function("rlEnableDepthMask", rlEnableDepthMask);
  lua.set_function("rlDisableDepthMask", rlDisableDepthMask);
  lua.set_function("rlEnableBackfaceCulling", rlEnableBackfaceCulling);
  lua.set_function("rlDisableBackfaceCulling", rlDisableBackfaceCulling);
  lua.set_function("rlColorMask", rlColorMask);
  lua.set_function("rlSetCullFace", rlSetCullFace);
  lua.set_function("rlEnableScissorTest", rlEnableScissorTest);
  lua.set_function("rlDisableScissorTest", rlDisableScissorTest);
  lua.set_function("rlScissor", rlScissor);
  lua.set_function("rlEnablePointMode", rlEnablePointMode);
  lua.set_function("rlDisablePointMode", rlDisablePointMode);
  lua.set_function("rlSetPointSize", rlSetPointSize);
  lua.set_function("rlGetPointSize", rlGetPointSize);
  lua.set_function("rlEnableWireMode", rlEnableWireMode);
  lua.set_function("rlDisableWireMode", rlDisableWireMode);
  lua.set_function("rlSetLineWidth", rlSetLineWidth);
  lua.set_function("rlGetLineWidth", rlGetLineWidth);
  lua.set_function("rlEnableSmoothLines", rlEnableSmoothLines);
  lua.set_function("rlDisableSmoothLines", rlDisableSmoothLines);
  lua.set_function("rlEnableStereoRender", rlEnableStereoRender);
  lua.set_function("rlDisableStereoRender", rlDisableStereoRender);
  lua.set_function("rlIsStereoRenderEnabled", rlIsStereoRenderEnabled);

  lua.set_function("rlClearColor", rlClearColor);
  lua.set_function("rlClearScreenBuffers", rlClearScreenBuffers);
  lua.set_function("rlCheckErrors", rlCheckErrors);
  lua.set_function("rlSetBlendMode", rlSetBlendMode);
  lua.set_function("rlSetBlendFactors", rlSetBlendFactors);
  lua.set_function("rlSetBlendFactorsSeparate", rlSetBlendFactorsSeparate);

  lua.set_function("rlglInit", rlglInit);
  lua.set_function("rlglClose", rlglClose);
  lua.set_function("rlGetVersion", rlGetVersion);
  lua.set_function("rlSetFramebufferWidth", rlSetFramebufferWidth);
  lua.set_function("rlGetFramebufferWidth", rlGetFramebufferWidth);
  lua.set_function("rlSetFramebufferHeight", rlSetFramebufferHeight);
  lua.set_function("rlGetFramebufferHeight", rlGetFramebufferHeight);

  lua.set_function("rlGetTextureIdDefault", rlGetTextureIdDefault);
  lua.set_function("rlGetShaderIdDefault", rlGetShaderIdDefault);

  lua.set_function("rlDrawRenderBatchActive", rlDrawRenderBatchActive);
  lua.set_function("rlCheckRenderBatchLimit", rlCheckRenderBatchLimit);
  lua.set_function("rlSetTexture", rlSetTexture);

  lua.set_function("rlLoadVertexArray", rlLoadVertexArray);
  lua.set_function("rlUnloadVertexArray", rlUnloadVertexArray);
  lua.set_function("rlUnloadVertexBuffer", rlUnloadVertexBuffer);
  lua.set_function("rlSetVertexAttribute", rlSetVertexAttribute);
  lua.set_function("rlSetVertexAttributeDivisor", rlSetVertexAttributeDivisor);
  lua.set_function("rlDrawVertexArray", rlDrawVertexArray);
  lua.set_function("rlDrawVertexArrayInstanced", rlDrawVertexArrayInstanced);

  lua.set_function("rlLoadTextureDepth", rlLoadTextureDepth);
  lua.set_function("rlGetPixelFormatName", rlGetPixelFormatName);
  lua.set_function("rlUnloadTexture", rlUnloadTexture);

  lua.set_function("rlLoadFramebuffer", rlLoadFramebuffer);
  lua.set_function("rlFramebufferAttach", rlFramebufferAttach);
  lua.set_function("rlFramebufferComplete", rlFramebufferComplete);
  lua.set_function("rlUnloadFramebuffer", rlUnloadFramebuffer);
  lua.set_function("rlResizeFramebuffer", rlResizeFramebuffer);

  lua.set_function("rlLoadShader", rlLoadShader);
  lua.set_function("rlLoadShaderProgram", rlLoadShaderProgram);
  lua.set_function("rlLoadShaderProgramEx", rlLoadShaderProgramEx);
  lua.set_function("rlLoadShaderProgramCompute", rlLoadShaderProgramCompute);
  lua.set_function("rlUnloadShader", rlUnloadShader);
  lua.set_function("rlUnloadShaderProgram", rlUnloadShaderProgram);
  lua.set_function("rlGetLocationUniform", rlGetLocationUniform);
  lua.set_function("rlGetLocationAttrib", rlGetLocationAttrib);
  lua.set_function("rlSetUniformMatrix", rlSetUniformMatrix);
  lua.set_function("rlSetUniformSampler", rlSetUniformSampler);

  lua.set_function("rlComputeShaderDispatch", rlComputeShaderDispatch);
  lua.set_function("rlUnloadShaderBuffer", rlUnloadShaderBuffer);
  lua.set_function("rlBindShaderBuffer", rlBindShaderBuffer);
  lua.set_function("rlCopyShaderBuffer", rlCopyShaderBuffer);
  lua.set_function("rlGetShaderBufferSize", rlGetShaderBufferSize);
  lua.set_function("rlBindImageTexture", rlBindImageTexture);

  lua.set_function("rlGetMatrixModelview", rlGetMatrixModelview);
  lua.set_function("rlGetMatrixProjection", rlGetMatrixProjection);
  lua.set_function("rlGetMatrixTransform", rlGetMatrixTransform);
  lua.set_function("rlGetMatrixProjectionStereo", rlGetMatrixProjectionStereo);
  lua.set_function("rlGetMatrixViewOffsetStereo", rlGetMatrixViewOffsetStereo);
  lua.set_function("rlSetMatrixProjection", rlSetMatrixProjection);
  lua.set_function("rlSetMatrixModelview", rlSetMatrixModelview);
  lua.set_function("rlSetMatrixProjectionStereo", rlSetMatrixProjectionStereo);
  lua.set_function("rlSetMatrixViewOffsetStereo", rlSetMatrixViewOffsetStereo);
  lua.set_function("rlLoadDrawCube", rlLoadDrawCube);
  lua.set_function("rlLoadDrawQuad", rlLoadDrawQuad);
}

#endif

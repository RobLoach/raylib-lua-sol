#ifndef RAYLIB_LUA_SOL_RLGL_
#define RAYLIB_LUA_SOL_RLGL_

#include "raylib.h"
#include "sol/sol.hpp"

#include "rlgl.h"

void raylib_lua_sol_rlgl(sol::state& lua) {
  lua["DEFAULT_BATCH_BUFFER_ELEMENTS"] = DEFAULT_BATCH_BUFFER_ELEMENTS;
  lua["DEFAULT_BATCH_BUFFERS"] = DEFAULT_BATCH_BUFFERS;
  lua["DEFAULT_BATCH_DRAWCALLS"] = DEFAULT_BATCH_DRAWCALLS;
  lua["MAX_BATCH_ACTIVE_TEXTURES"] = MAX_BATCH_ACTIVE_TEXTURES;
  lua["MAX_MATRIX_STACK_SIZE"] = MAX_MATRIX_STACK_SIZE;
  lua["MAX_MESH_VERTEX_BUFFERS"] = MAX_MESH_VERTEX_BUFFERS;
  lua["MAX_SHADER_LOCATIONS"] = MAX_SHADER_LOCATIONS;
  lua["MAX_MATERIAL_MAPS"] = MAX_MATERIAL_MAPS;
  lua["RL_CULL_DISTANCE_NEAR"] = RL_CULL_DISTANCE_NEAR;
  lua["RL_CULL_DISTANCE_FAR"] = RL_CULL_DISTANCE_FAR;

  lua["RL_TEXTURE_WRAP_S"] = RL_TEXTURE_WRAP_S;
  lua["RL_TEXTURE_WRAP_T"] = RL_TEXTURE_WRAP_T;
  lua["RL_TEXTURE_MAG_FILTER"] = RL_TEXTURE_MAG_FILTER;
  lua["RL_TEXTURE_MIN_FILTER"] = RL_TEXTURE_MIN_FILTER;

  lua["RL_TEXTURE_FILTER_NEAREST"] = RL_TEXTURE_FILTER_NEAREST;
  lua["RL_TEXTURE_FILTER_LINEAR "] = RL_TEXTURE_FILTER_LINEAR ;
  lua["RL_TEXTURE_FILTER_MIP_NEAREST"] = RL_TEXTURE_FILTER_MIP_NEAREST;
  lua["RL_TEXTURE_FILTER_NEAREST_MIP_LINEAR"] = RL_TEXTURE_FILTER_NEAREST_MIP_LINEAR;
  lua["RL_TEXTURE_FILTER_LINEAR_MIP_NEAREST"] = RL_TEXTURE_FILTER_LINEAR_MIP_NEAREST;
  lua["RL_TEXTURE_FILTER_MIP_LINEAR"] = RL_TEXTURE_FILTER_MIP_LINEAR;
  lua["RL_TEXTURE_FILTER_ANISOTROPIC"] = RL_TEXTURE_FILTER_ANISOTROPIC;

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


  lua.set_function("rlMatrixMode", rlMatrixMode);
  lua.set_function("rlPushMatrix", rlPushMatrix);
  lua.set_function("rlPopMatrix", rlPopMatrix);
  lua.set_function("rlLoadIdentity", rlLoadIdentity);
  lua.set_function("rlTranslatef", rlTranslatef);
  lua.set_function("rlRotatef", rlRotatef);
  lua.set_function("rlScalef", rlScalef);
  lua.set_function("rlMultMatrixf", rlMultMatrixf);
  lua.set_function("rlFrustum", rlFrustum);
  lua.set_function("rlOrtho", rlOrtho);
  lua.set_function("rlViewport", rlViewport);
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
  lua.set_function("rlEnableShader", rlEnableShader);
  lua.set_function("rlDisableShader", rlDisableShader);
  lua.set_function("rlEnableFramebuffer", rlEnableFramebuffer);
  lua.set_function("rlDisableFramebuffer", rlDisableFramebuffer);
  lua.set_function("rlEnableDepthTest", rlEnableDepthTest);
  lua.set_function("rlDisableDepthTest", rlDisableDepthTest);
  lua.set_function("rlEnableDepthMask", rlEnableDepthMask);
  lua.set_function("rlDisableDepthMask", rlDisableDepthMask);
  lua.set_function("rlEnableBackfaceCulling", rlEnableBackfaceCulling);
  lua.set_function("rlDisableBackfaceCulling", rlDisableBackfaceCulling);
  lua.set_function("rlEnableScissorTest", rlEnableScissorTest);
  lua.set_function("rlDisableScissorTest", rlDisableScissorTest);
  lua.set_function("rlScissor", rlScissor);
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
  lua.set_function("rlglInit", rlglInit);
  lua.set_function("rlglClose", rlglClose);
  lua.set_function("rlLoadExtensions", rlLoadExtensions);
  lua.set_function("rlGetVersion", rlGetVersion);
  lua.set_function("rlGetFramebufferWidth", rlGetFramebufferWidth);
  lua.set_function("rlGetFramebufferHeight", rlGetFramebufferHeight);

  lua.set_function("rlGetShaderDefault", rlGetShaderDefault);
  lua.set_function("rlGetTextureDefault", rlGetTextureDefault);
  lua.set_function("rlLoadRenderBatch", rlLoadRenderBatch);
  lua.set_function("rlUnloadRenderBatch", rlUnloadRenderBatch);
  lua.set_function("rlDrawRenderBatch", rlDrawRenderBatch);
  lua.set_function("rlSetRenderBatchActive", rlSetRenderBatchActive);
  lua.set_function("rlDrawRenderBatchActive", rlDrawRenderBatchActive);
  lua.set_function("rlCheckRenderBatchLimit", rlCheckRenderBatchLimit);
  lua.set_function("rlSetTexture", rlSetTexture);
  lua.set_function("rlLoadVertexArray", rlLoadVertexArray);
  lua.set_function("rlLoadVertexBuffer", rlLoadVertexBuffer);
  lua.set_function("rlLoadVertexBufferElement", rlLoadVertexBufferElement);
  lua.set_function("rlUpdateVertexBuffer", rlUpdateVertexBuffer);
  lua.set_function("rlUnloadVertexArray", rlUnloadVertexArray);
  lua.set_function("rlUnloadVertexBuffer", rlUnloadVertexBuffer);
  lua.set_function("rlSetVertexAttribute", rlSetVertexAttribute);
  lua.set_function("rlSetVertexAttributeDivisor", rlSetVertexAttributeDivisor);
  lua.set_function("rlSetVertexAttributeDefault", rlSetVertexAttributeDefault);
  lua.set_function("rlDrawVertexArray", rlDrawVertexArray);
  lua.set_function("rlDrawVertexArrayElements", rlDrawVertexArrayElements);
  lua.set_function("rlDrawVertexArrayInstanced", rlDrawVertexArrayInstanced);
  lua.set_function("rlDrawVertexArrayElementsInstanced", rlDrawVertexArrayElementsInstanced);

//  lua.set_function("rlLoadExtensions", rlLoadExtensions);
  lua.set_function("rlLoadTexture", rlLoadTexture);
  lua.set_function("rlLoadTextureDepth", rlLoadTextureDepth);
  lua.set_function("rlLoadTextureCubemap", rlLoadTextureCubemap);
  lua.set_function("rlUpdateTexture", rlUpdateTexture);
  lua.set_function("rlGetGlTextureFormats", rlGetGlTextureFormats);
  lua.set_function("rlUnloadTexture", rlUnloadTexture);
  lua.set_function("rlGenerateMipmaps", rlGenerateMipmaps);
  lua.set_function("rlReadTexturePixels", rlReadTexturePixels);
  lua.set_function("rlReadScreenPixels", rlReadScreenPixels);
  lua.set_function("rlLoadFramebuffer", rlLoadFramebuffer);
  lua.set_function("rlFramebufferAttach", rlFramebufferAttach);
  lua.set_function("rlFramebufferComplete", rlFramebufferComplete);
  lua.set_function("rlUnloadFramebuffer", rlUnloadFramebuffer);
  lua.set_function("rlLoadShaderCode", rlLoadShaderCode);
  lua.set_function("rlCompileShader", rlCompileShader);
  lua.set_function("rlLoadShaderProgram", rlLoadShaderProgram);
  lua.set_function("rlUnloadShaderProgram", rlUnloadShaderProgram);
  lua.set_function("rlGetLocationUniform", rlGetLocationUniform);
  lua.set_function("rlGetLocationAttrib", rlGetLocationAttrib);
  lua.set_function("rlSetUniform", rlSetUniform);
  lua.set_function("rlSetUniformMatrix", rlSetUniformMatrix);
  lua.set_function("rlSetUniformSampler", rlSetUniformSampler);
  lua.set_function("rlSetShader", rlSetShader);
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

#ifndef RAYLIB_LUA_SOL_RLGL_
#define RAYLIB_LUA_SOL_RLGL_

#include "raylib.h"
#include "sol/sol.hpp"

#include "rlgl.h"

void raylib_lua_sol_rlgl(sol::state& lua) {
  lua["DEFAULT_BATCH_BUFFERS"] = DEFAULT_BATCH_BUFFERS;
  lua["DEFAULT_BATCH_DRAWCALLS"] = DEFAULT_BATCH_DRAWCALLS;
  lua["MAX_MATRIX_STACK_SIZE"] = MAX_MATRIX_STACK_SIZE;
  lua["MAX_SHADER_LOCATIONS"] = MAX_SHADER_LOCATIONS;
  lua["MAX_MATERIAL_MAPS"] = MAX_MATERIAL_MAPS;
  lua["RL_CULL_DISTANCE_NEAR"] = RL_CULL_DISTANCE_NEAR;
  lua["RL_CULL_DISTANCE_FAR"] = RL_CULL_DISTANCE_FAR;
  lua["RL_TEXTURE_WRAP_S"] = RL_TEXTURE_WRAP_S;
  lua["RL_TEXTURE_WRAP_T"] = RL_TEXTURE_WRAP_T;
  lua["RL_TEXTURE_MAG_FILTER"] = RL_TEXTURE_MAG_FILTER;
  lua["RL_TEXTURE_MIN_FILTER"] = RL_TEXTURE_MIN_FILTER;
  lua["RL_TEXTURE_ANISOTROPIC_FILTER"] = RL_TEXTURE_ANISOTROPIC_FILTER;
  lua["RL_FILTER_NEAREST"] = RL_FILTER_NEAREST;
  lua["RL_FILTER_LINEAR"] = RL_FILTER_LINEAR;
  lua["RL_FILTER_MIP_NEAREST"] = RL_FILTER_MIP_NEAREST;
  lua["RL_FILTER_NEAREST_MIP_LINEAR"] = RL_FILTER_NEAREST_MIP_LINEAR;
  lua["RL_FILTER_LINEAR_MIP_NEAREST"] = RL_FILTER_LINEAR_MIP_NEAREST;
  lua["RL_FILTER_MIP_LINEAR"] = RL_FILTER_MIP_LINEAR;
  lua["RL_WRAP_REPEAT"] = RL_WRAP_REPEAT;
  lua["RL_WRAP_CLAMP"] = RL_WRAP_CLAMP;
  lua["RL_WRAP_MIRROR_REPEAT"] = RL_WRAP_MIRROR_REPEAT;
  lua["RL_WRAP_MIRROR_CLAMP"] = RL_WRAP_MIRROR_CLAMP;
  lua["RL_MODELVIEW"] = RL_MODELVIEW;
  lua["RL_PROJECTION"] = RL_PROJECTION;
  lua["RL_TEXTURE"] = RL_TEXTURE;
  lua["RL_LINES"] = RL_LINES;
  lua["RL_TRIANGLES"] = RL_TRIANGLES;
  lua["RL_QUADS"] = RL_QUADS;

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
  lua.set_function("rlEnableTexture", rlEnableTexture);
  lua.set_function("rlDisableTexture", rlDisableTexture);
  lua.set_function("rlTextureParameters", rlTextureParameters);
  lua.set_function("rlEnableRenderTexture", rlEnableRenderTexture);
  lua.set_function("rlDisableRenderTexture", rlDisableRenderTexture);
  lua.set_function("rlEnableDepthTest", rlEnableDepthTest);
  lua.set_function("rlDisableDepthTest", rlDisableDepthTest);
  lua.set_function("rlEnableBackfaceCulling", rlEnableBackfaceCulling);
  lua.set_function("rlDisableBackfaceCulling", rlDisableBackfaceCulling);
  lua.set_function("rlEnableScissorTest", rlEnableScissorTest);
  lua.set_function("rlDisableScissorTest", rlDisableScissorTest);
  lua.set_function("rlScissor", rlScissor);
  lua.set_function("rlEnableWireMode", rlEnableWireMode);
  lua.set_function("rlDisableWireMode", rlDisableWireMode);
  lua.set_function("rlDeleteTextures", rlDeleteTextures);
  lua.set_function("rlDeleteRenderTextures", rlDeleteRenderTextures);
  lua.set_function("rlDeleteShader", rlDeleteShader);
  lua.set_function("rlDeleteVertexArrays", rlDeleteVertexArrays);
  lua.set_function("rlDeleteBuffers", rlDeleteBuffers);
  lua.set_function("rlClearColor", rlClearColor);
  lua.set_function("rlClearScreenBuffers", rlClearScreenBuffers);
  lua.set_function("rlUpdateBuffer", rlUpdateBuffer);
  lua.set_function("rlLoadAttribBuffer", rlLoadAttribBuffer);
  lua.set_function("rlglInit", rlglInit);
  lua.set_function("rlglClose", rlglClose);
  lua.set_function("rlglDraw", rlglDraw);
  lua.set_function("rlGetVersion", rlGetVersion);
  lua.set_function("rlCheckBufferLimit", rlCheckBufferLimit);
  lua.set_function("rlSetDebugMarker", rlSetDebugMarker);
  lua.set_function("rlLoadExtensions", rlLoadExtensions);
  lua.set_function("rlUnproject", rlUnproject);
  lua.set_function("rlLoadTexture", rlLoadTexture);
  lua.set_function("rlLoadTextureDepth", rlLoadTextureDepth);
  lua.set_function("rlLoadTextureCubemap", rlLoadTextureCubemap);
  lua.set_function("rlUpdateTexture", rlUpdateTexture);
  lua.set_function("rlGetGlTextureFormats", rlGetGlTextureFormats);
  lua.set_function("rlUnloadTexture", rlUnloadTexture);
  lua.set_function("rlGenerateMipmaps", rlGenerateMipmaps);
  lua.set_function("rlReadTexturePixels", rlReadTexturePixels);
  lua.set_function("rlReadScreenPixels", rlReadScreenPixels);
  lua.set_function("rlLoadRenderTexture", rlLoadRenderTexture);
  lua.set_function("rlRenderTextureAttach", rlRenderTextureAttach);
  lua.set_function("rlRenderTextureComplete", rlRenderTextureComplete);
  lua.set_function("rlLoadMesh", rlLoadMesh);
  lua.set_function("rlUpdateMesh", rlUpdateMesh);
  lua.set_function("rlUpdateMeshAt", rlUpdateMeshAt);
  lua.set_function("rlDrawMesh", rlDrawMesh);
  lua.set_function("rlUnloadMesh", rlUnloadMesh);
}

#endif

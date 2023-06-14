#ifndef RAYLIB_LUA_SOL_RAYMATH_
#define RAYLIB_LUA_SOL_RAYMATH_

#include "raylib.h"
#include "sol/sol.hpp"

#include "raymath.h"

void raylib_lua_sol_raymath(sol::state& lua) {

  lua.set_function("Clamp", Clamp);
  lua.set_function("Lerp", Lerp);
  lua.set_function("Normalize", Normalize);
  lua.set_function("Remap", Remap);
  lua.set_function("Wrap", Wrap);
  lua.set_function("FloatEquals", FloatEquals);

  lua.set_function("Vector2Zero", Vector2Zero);
  lua.set_function("Vector2One", Vector2One);
  lua.set_function("Vector2Add", Vector2Add);
  lua.set_function("Vector2AddValue", Vector2AddValue);
  lua.set_function("Vector2Subtract", Vector2Subtract);
  lua.set_function("Vector2SubtractValue", Vector2SubtractValue);
  lua.set_function("Vector2Length", Vector2Length);
  lua.set_function("Vector2LengthSqr", Vector2LengthSqr);
  lua.set_function("Vector2DotProduct", Vector2DotProduct);
  lua.set_function("Vector2Distance", Vector2Distance);
  lua.set_function("Vector2DistanceSqr", Vector2DistanceSqr);
  lua.set_function("Vector2Angle", Vector2Angle);
  lua.set_function("Vector2Scale", Vector2Scale);
  lua.set_function("Vector2Multiply", Vector2Multiply);
  lua.set_function("Vector2Negate", Vector2Negate);
  lua.set_function("Vector2Divide", Vector2Divide);
  lua.set_function("Vector2Normalize", Vector2Normalize);
  lua.set_function("Vector2Transform", Vector2Transform);
  lua.set_function("Vector2Lerp", Vector2Lerp);
  lua.set_function("Vector2Reflect", Vector2Reflect);
  lua.set_function("Vector2Rotate", Vector2Rotate);
  lua.set_function("Vector2MoveTowards", Vector2MoveTowards);
  lua.set_function("Vector2Invert", Vector2Invert);
  lua.set_function("Vector2Clamp", Vector2Clamp);
  lua.set_function("Vector2ClampValue", Vector2ClampValue);
  lua.set_function("Vector2Equals", Vector2Equals);

  lua.set_function("Vector3Zero", Vector3Zero);
  lua.set_function("Vector3One", Vector3One);
  lua.set_function("Vector3Add", Vector3Add);
  lua.set_function("Vector3AddValue", Vector3AddValue);
  lua.set_function("Vector3Subtract", Vector3Subtract);
  lua.set_function("Vector3SubtractValue", Vector3SubtractValue);
  lua.set_function("Vector3Scale", Vector3Scale);
  lua.set_function("Vector3Multiply", Vector3Multiply);
  lua.set_function("Vector3CrossProduct", Vector3CrossProduct);
  lua.set_function("Vector3Perpendicular", Vector3Perpendicular);
  lua.set_function("Vector3Length", Vector3Length);
  lua.set_function("Vector3LengthSqr", Vector3LengthSqr);
  lua.set_function("Vector3DotProduct", Vector3DotProduct);
  lua.set_function("Vector3Distance", Vector3Distance);
  lua.set_function("Vector3DistanceSqr", Vector3DistanceSqr);
  lua.set_function("Vector3Angle", Vector3Angle);
  lua.set_function("Vector3Negate", Vector3Negate);
  lua.set_function("Vector3Divide", Vector3Divide);
  lua.set_function("Vector3Normalize", Vector3Normalize);
  lua.set_function("Vector3OrthoNormalize", Vector3OrthoNormalize);
  lua.set_function("Vector3Transform", Vector3Transform);
  lua.set_function("Vector3RotateByQuaternion", Vector3RotateByQuaternion);
  lua.set_function("Vector3RotateByAxisAngle", Vector3RotateByAxisAngle);
  lua.set_function("Vector3Lerp", Vector3Lerp);
  lua.set_function("Vector3Reflect", Vector3Reflect);
  lua.set_function("Vector3Min", Vector3Min);
  lua.set_function("Vector3Max", Vector3Max);
  lua.set_function("Vector3Barycenter", Vector3Barycenter);
  lua.set_function("Vector3Unproject", Vector3Unproject);
  lua.set_function("Vector3ToFloatV", Vector3ToFloatV);
  lua.set_function("Vector3Invert", Vector3Invert);
  lua.set_function("Vector3Clamp", Vector3Clamp);
  lua.set_function("Vector3ClampValue", Vector3ClampValue);
  lua.set_function("Vector3Equals", Vector3Equals);
  lua.set_function("Vector3Refract", Vector3Refract);

  lua.set_function("MatrixDeterminant", MatrixDeterminant);
  lua.set_function("MatrixTrace", MatrixTrace);
  lua.set_function("MatrixTranspose", MatrixTranspose);
  lua.set_function("MatrixInvert", MatrixInvert);
  lua.set_function("MatrixIdentity", MatrixIdentity);
  lua.set_function("MatrixAdd", MatrixAdd);
  lua.set_function("MatrixSubtract", MatrixSubtract);
  lua.set_function("MatrixMultiply", MatrixMultiply);
  lua.set_function("MatrixTranslate", MatrixTranslate);
  lua.set_function("MatrixRotate", MatrixRotate);
  lua.set_function("MatrixRotateX", MatrixRotateX);
  lua.set_function("MatrixRotateY", MatrixRotateY);
  lua.set_function("MatrixRotateZ", MatrixRotateZ);
  lua.set_function("MatrixRotateXYZ", MatrixRotateXYZ);
  lua.set_function("MatrixRotateZYX", MatrixRotateZYX);
  lua.set_function("MatrixScale", MatrixScale);
  lua.set_function("MatrixFrustum", MatrixFrustum);
  lua.set_function("MatrixPerspective", MatrixPerspective);
  lua.set_function("MatrixOrtho", MatrixOrtho);
  lua.set_function("MatrixLookAt", MatrixLookAt);
  lua.set_function("MatrixToFloatV", MatrixToFloatV);

  lua.set_function("QuaternionAdd", QuaternionAdd);
  lua.set_function("QuaternionAddValue", QuaternionAddValue);
  lua.set_function("QuaternionSubtract", QuaternionSubtract);
  lua.set_function("QuaternionSubtractValue", QuaternionSubtractValue);
  lua.set_function("QuaternionIdentity", QuaternionIdentity);
  lua.set_function("QuaternionLength", QuaternionLength);
  lua.set_function("QuaternionNormalize", QuaternionNormalize);
  lua.set_function("QuaternionInvert", QuaternionInvert);
  lua.set_function("QuaternionMultiply", QuaternionMultiply);
  lua.set_function("QuaternionScale", QuaternionScale);
  lua.set_function("QuaternionDivide", QuaternionDivide);
  lua.set_function("QuaternionLerp", QuaternionLerp);
  lua.set_function("QuaternionNlerp", QuaternionNlerp);
  lua.set_function("QuaternionSlerp", QuaternionSlerp);
  lua.set_function("QuaternionFromVector3ToVector3", QuaternionFromVector3ToVector3);
  lua.set_function("QuaternionFromMatrix", QuaternionFromMatrix);
  lua.set_function("QuaternionToMatrix", QuaternionToMatrix);
  lua.set_function("QuaternionFromAxisAngle", QuaternionFromAxisAngle);
  lua.set_function("QuaternionToAxisAngle", QuaternionToAxisAngle);
  lua.set_function("QuaternionFromEuler", QuaternionFromEuler);
  lua.set_function("QuaternionToEuler", QuaternionToEuler);
  lua.set_function("QuaternionTransform", QuaternionTransform);
  lua.set_function("QuaternionEquals", QuaternionEquals);
}

#endif
#ifndef RAYLIB_LUA_SOL_
#define RAYLIB_LUA_SOL_

#include "raylib.h"
#include "sol/sol.hpp"

void raylib_lua_sol_color(sol::state& lua) {
	lua["LIGHTGRAY"] = Color(LIGHTGRAY);
	lua["GRAY"] = Color(GRAY);
	lua["DARKGRAY"] = Color(DARKGRAY);
	lua["YELLOW"] = Color(YELLOW);
	lua["GOLD"] = Color(GOLD);
	lua["ORANGE"] = Color(ORANGE);
	lua["PINK"] = Color(PINK);
	lua["RED"] = Color(RED);
	lua["MAROON"] = Color(MAROON);
	lua["GREEN"] = Color(GREEN);
	lua["LIME"] = Color(LIME);
	lua["DARKGREEN"] = Color(DARKGREEN);
	lua["SKYBLUE"] = Color(SKYBLUE);
	lua["BLUE"] = Color(BLUE);
	lua["DARKBLUE"] = Color(DARKBLUE);
	lua["PURPLE"] = Color(PURPLE);
	lua["VIOLET"] = Color(VIOLET);
	lua["DARKPURPLE"] = Color(DARKPURPLE);
	lua["BEIGE"] = Color(BEIGE);
	lua["BROWN"] = Color(BROWN);
	lua["DARKBROWN"] = Color(DARKBROWN);
	lua["WHITE"] = Color(WHITE);
	lua["BLACK"] = Color(BLACK);
	lua["BLANK"] = Color(BLANK);
	lua["MAGENTA"] = Color(MAGENTA);
	lua["RAYWHITE"] = Color(RAYWHITE);
}

void raylib_lua_sol_structs(sol::state& lua) {
  lua.new_usertype<Rectangle>("Rectangle",
    sol::call_constructor, sol::factories(
      []() {
        return Rectangle{};
      },
      [](Rectangle const& r) {
        return Rectangle{r.x, r.y, r.width, r.height};
      },
      [](float x, float y, float width, float height) {
        return Rectangle{x, y, width, height};
      }
    ),
    "x", &Rectangle::x,
    "y", &Rectangle::y,
    "width", &Rectangle::width,
    "height", &Rectangle::height,
    sol::meta_function::to_string, [](Rectangle& r) {
      return TextFormat("{x: %02.02f, y: %02.02f, width: %02.02f, height: %02.02f}", r.x, r.y, r.width, r.height);
    }
  );

  lua.new_usertype<Color>("Color",
    sol::call_constructor, sol::factories(
      [](){
        return Color{};
      },
      [](unsigned char r, unsigned char g, unsigned char b) {
        return Color{r, g, b, 255};
      },
      [](unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
        return Color{r, g, b, a};
      }
    ),
    "r", &Color::r,
    "g", &Color::g,
    "b", &Color::b,
    "a", &Color::a);
	lua.new_usertype<Vector2>("Vector2",
    sol::call_constructor, sol::factories(
      [](){
        return Vector2{};
      },
      [](float x, float y){
        return Vector2{x, y};
      }
    ),
		"x", &Vector2::x,
		"y", &Vector2::y,
    sol::meta_function::to_string, [](Vector2& v) {
      return TextFormat("{x: %02.02f, y: %02.02f}", v.x, v.y);
    });
	lua.new_usertype<Vector3>("Vector3",
    sol::call_constructor, sol::factories(
      [](){
        return Vector3{};
      },
      [](float x){
        return Vector3{x, 0, 0};
      },
      [](float x, float y){
        return Vector3{x, y, 0};
      },
      [](float x, float y, float z){
        return Vector3{x, y, z};
      }
    ),
		"x", &Vector3::x,
		"y", &Vector3::y,
		"z", &Vector3::z);
	lua.new_usertype<Vector4>("Vector4",
    sol::call_constructor, sol::factories(
      [](){
        return Vector4{};
      },
      [](float x){
        return Vector4{x, 0, 0, 0};
      },
      [](float x, float y){
        return Vector4{x, y, 0, 0};
      },
      [](float x, float y, float z){
        return Vector4{x, y, z, 0};
      },
      [](float x, float y, float z, float w){
        return Vector4{x, y, z, w};
      }
    ),
		"x", &Vector4::x,
		"y", &Vector4::y,
		"z", &Vector4::z,
		"w", &Vector4::w);
	lua.new_usertype<Matrix>("Matrix",
    sol::call_constructor, sol::factories(
      [](){
        return Matrix{};
      },
      [](float _m0, float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9, float _m10, float _m11, float _m12, float _m13, float _m14, float _m15){
        return Matrix{_m0,_m1,_m2,_m3,_m4,_m5,_m6,_m7,_m8,_m9,_m10,_m11,_m12,_m13,_m14,_m15};
      }
    ),
		"m0", &Matrix::m0,
		"m1", &Matrix::m1,
		"m2", &Matrix::m2,
		"m3", &Matrix::m3,
		"m4", &Matrix::m4,
		"m5", &Matrix::m5,
		"m6", &Matrix::m6,
		"m7", &Matrix::m7,
		"m8", &Matrix::m8,
		"m9", &Matrix::m9,
		"m10", &Matrix::m10,
		"m11", &Matrix::m11,
		"m12", &Matrix::m12,
		"m13", &Matrix::m13,
		"m14", &Matrix::m14,
		"m15", &Matrix::m15);
	lua.new_usertype<Image>("Image",
		"data", &Image::data,
		"width", &Image::width,
		"height", &Image::height,
		"mipmaps", &Image::mipmaps,
		"format", &Image::format);
	lua.new_usertype<Texture2D>("Texture",
		"id", &Texture2D::id,
		"width", &Texture2D::width,
		"height", &Texture2D::height,
		"mipmaps", &Texture2D::mipmaps,
		"format", &Texture2D::format);
  lua.new_usertype<RenderTexture2D>("RenderTexture2D",
    "id", &RenderTexture2D::id,
    "texture", &RenderTexture2D::texture,
    "depth", &RenderTexture2D::depth,
    "depthTexture", &RenderTexture2D::depthTexture);
  lua.new_usertype<NPatchInfo>("NPatchInfo",
    "sourceRec", &NPatchInfo::sourceRec,
    "left", &NPatchInfo::left,
    "top", &NPatchInfo::top,
    "right", &NPatchInfo::right,
    "bottom", &NPatchInfo::bottom,
    "type", &NPatchInfo::type);
  lua.new_usertype<CharInfo>("CharInfo",
    "value", &CharInfo::value,
    "offsetX", &CharInfo::offsetX,
    "offsetY", &CharInfo::offsetY,
    "advanceX", &CharInfo::advanceX,
    "image", &CharInfo::image);
  lua.new_usertype<Font>("Font",
    "baseSize", &Font::baseSize,
    "charsCount", &Font::charsCount,
    "texture", &Font::texture,
    "recs", &Font::recs,
    "chars", &Font::chars);
  lua.new_usertype<Camera3D>("Camera",
    sol::call_constructor, sol::factories(
      [](){
        return Camera3D{};
      },
      [](Vector3 position, Vector3 target, Vector3 up, float fovy, int type){
        return Camera3D{position, target, up, fovy, type};
      },
      [](Vector3 position, Vector3 target, Vector3 up, float fovy){
        return Camera3D{position, target, up, fovy, 0};
      },
      [](Vector3 position, Vector3 target, Vector3 up){
        return Camera3D{position, target, up, 0, 0};
      }
    ),
    "position", &Camera3D::position,
    "target", &Camera3D::target,
    "up", &Camera3D::up,
    "fovy", &Camera3D::fovy,
    "type", &Camera3D::type);
  lua.new_usertype<Camera2D>("Camera2D",
    sol::call_constructor, sol::factories(
      [](){
        return Camera2D{};
      },
      [](Vector2 offset, Vector2 target, float rotation, float zoom){
        return Camera2D{offset, target, rotation, zoom};
      },
      [](Vector2 offset, Vector2 target){
        return Camera2D{offset, target, 0, 0};
      }
    ),
    "offset", &Camera2D::offset,
    "target", &Camera2D::target,
    "rotation", &Camera2D::rotation,
    "zoom", &Camera2D::zoom);
  lua.new_usertype<Mesh>("Mesh",
    "vertexCount", &Mesh::vertexCount,
    "triangleCount", &Mesh::triangleCount,
    "vertices", &Mesh::vertices,
    "texcoords", &Mesh::texcoords,
    "texcoords2", &Mesh::texcoords2,
    "normals", &Mesh::normals,
    "tangents", &Mesh::tangents,
    "colors", &Mesh::colors,
    "indices", &Mesh::indices,
    "animVertices", &Mesh::animVertices,
    "animNormals", &Mesh::animNormals,
    "boneIds", &Mesh::boneIds,
    "boneWeights", &Mesh::boneWeights,
    "vaoId", &Mesh::vaoId,
    "vboId", &Mesh::vboId);
  lua.new_usertype<Shader>("Shader",
    "id", &Shader::id,
    "locs", &Shader::locs);
  lua.new_usertype<MaterialMap>("MaterialMap",
    "texture", &MaterialMap::texture,
    "color", &MaterialMap::color,
    "value", &MaterialMap::value);
  lua.new_usertype<Material>("Material",
    "shader", &Material::shader,
    "maps", &Material::maps,
    "params", &Material::params);
  lua.new_usertype<Transform>("Transform",
    "translation", &Transform::translation,
    "rotation", &Transform::rotation,
    "scale", &Transform::scale);
  lua.new_usertype<BoneInfo>("BoneInfo",
    "name", &BoneInfo::name,
    "parent", &BoneInfo::parent);
  lua.new_usertype<Model>("Model",
    "transform", &Model::transform,
    "meshCount", &Model::meshCount,
    "meshes", &Model::meshes,
    "materialCount", &Model::materialCount,
    "materials", &Model::materials,
    "meshMaterial", &Model::meshMaterial,
    "boneCount", &Model::boneCount,
    "bones", &Model::bones,
    "bindPose", &Model::bindPose);
  lua.new_usertype<ModelAnimation>("ModelAnimation",
    "boneCount", &ModelAnimation::boneCount,
    "bones", &ModelAnimation::bones,
    "frameCount", &ModelAnimation::frameCount);
    //"framePoses", &ModelAnimation::framePoses
  lua.new_usertype<Ray>("Ray",
    sol::call_constructor, sol::factories(
      [](){
        return Ray{};
      },
      [](Vector3 pos){
        return Ray{pos};
      },
      [](Vector3 pos, Vector3 dir){
        return Ray{pos, dir};
      }
    ),
    "position", &Ray::position,
    "direction", &Ray::direction);
  lua.new_usertype<RayHitInfo>("RayHitInfo",
    "hit", &RayHitInfo::hit,
    "distance", &RayHitInfo::distance,
    "position", &RayHitInfo::position,
    "normal", &RayHitInfo::normal);
  lua.new_usertype<BoundingBox>("BoundingBox",
    sol::call_constructor, sol::factories(
      [](){
        return BoundingBox{};
      },
      [](Vector3 minimum, Vector3 maximum){
        return BoundingBox{minimum, maximum};
      }
    ),
    "min", &BoundingBox::min,
    "max", &BoundingBox::max);
  lua.new_usertype<Wave>("Wave",
    "sampleCount", &Wave::sampleCount,
    "sampleRate", &Wave::sampleRate,
    "sampleSize", &Wave::sampleSize,
    "channels", &Wave::channels,
    "data", &Wave::data);
  lua.new_usertype<AudioStream>("AudioStream",
    "sampleRate", &AudioStream::sampleRate,
    "sampleSize", &AudioStream::sampleSize,
    "channels", &AudioStream::channels);
    //"buffer", &AudioStream::buffer);
  lua.new_usertype<Sound>("Sound",
    "sampleCount", &Sound::sampleCount,
    "stream", &Sound::stream);
  lua.new_usertype<Music>("Music",
    "ctxType", &Music::ctxType,
    "ctxData", &Music::ctxData,
    "sampleCount", &Music::sampleCount,
    "loopCount", &Music::loopCount,
    "stream", &Music::stream);
  lua.new_usertype<VrDeviceInfo>("VrDeviceInfo",
    "hResolution", &VrDeviceInfo::hResolution,
    "vResolution", &VrDeviceInfo::vResolution,
    "hScreenSize", &VrDeviceInfo::hScreenSize,
    "vScreenSize", &VrDeviceInfo::vScreenSize,
    "vScreenCenter", &VrDeviceInfo::vScreenCenter,
    "eyeToScreenDistance", &VrDeviceInfo::eyeToScreenDistance,
    "lensSeparationDistance", &VrDeviceInfo::lensSeparationDistance,
    "interpupillaryDistance", &VrDeviceInfo::interpupillaryDistance,
    "lensDistortionValues", &VrDeviceInfo::lensDistortionValues,
    "chromaAbCorrection", &VrDeviceInfo::chromaAbCorrection);
}

#define RAYLIB_LUA_SOL_ADD_ENUM(x) \
  lua[#x] = x

void raylib_lua_sol_enums(sol::state &lua) {
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_RESERVED);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_FULLSCREEN_MODE);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_RESIZABLE);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_UNDECORATED);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_TRANSPARENT);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_HIDDEN);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_ALWAYS_RUN);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_MSAA_4X_HINT);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_VSYNC_HINT);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_ALL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_TRACE);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_DEBUG);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_INFO);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_WARNING);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_ERROR);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_FATAL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_NONE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_APOSTROPHE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_COMMA);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_MINUS);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_PERIOD);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_SLASH);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_ZERO);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_ONE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_TWO);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_THREE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_FOUR);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_FIVE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_SIX);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_SEVEN);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_EIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_NINE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_SEMICOLON);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_EQUAL);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_A);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_B);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_C);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_D);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_E);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_G);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_H);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_I);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_J);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_K);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_L);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_M);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_N);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_O);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_P);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_Q);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_R);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_S);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_T);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_U);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_V);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_W);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_X);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_Y);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_Z);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_SPACE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_ESCAPE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_ENTER);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_TAB);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_BACKSPACE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_INSERT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_DELETE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_DOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_UP);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_PAGE_UP);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_PAGE_DOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_HOME);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_END);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_CAPS_LOCK);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_SCROLL_LOCK);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_NUM_LOCK);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_PRINT_SCREEN);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_PAUSE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F1);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F2);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F3);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F4);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F5);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F6);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F7);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F8);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F9);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F10);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F11);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_F12);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT_SHIFT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT_CONTROL);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT_ALT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT_SUPER);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT_SHIFT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT_CONTROL);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT_ALT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT_SUPER);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KB_MENU);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT_BRACKET);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_BACKSLASH);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT_BRACKET);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_GRAVE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_0);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_1);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_2);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_3);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_4);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_5);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_6);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_7);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_8);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_9);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_DECIMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_DIVIDE);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_MULTIPLY);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_SUBTRACT);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_ADD);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_ENTER);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_KP_EQUAL);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_BACK);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_MENU);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_VOLUME_UP);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_VOLUME_DOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_LEFT_BUTTON);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_RIGHT_BUTTON);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_MIDDLE_BUTTON);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_PLAYER1);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_PLAYER2);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_PLAYER3);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_PLAYER4);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_UNKNOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_UP);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_DOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_LEFT);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_UP);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_TRIGGER_1);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_TRIGGER_2);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_TRIGGER_1);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_TRIGGER_2);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_MIDDLE_LEFT);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_MIDDLE);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_MIDDLE_RIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_LEFT_THUMB);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_BUTTON_RIGHT_THUMB);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_UNKNOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_LEFT_X);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_LEFT_Y);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_RIGHT_X);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_RIGHT_Y);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_LEFT_TRIGGER);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_RIGHT_TRIGGER);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VERTEX_POSITION);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VERTEX_TEXCOORD01);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VERTEX_TEXCOORD02);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VERTEX_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VERTEX_TANGENT);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VERTEX_COLOR);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MATRIX_MVP);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MATRIX_MODEL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MATRIX_VIEW);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MATRIX_PROJECTION);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_VECTOR_VIEW);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_COLOR_DIFFUSE);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_COLOR_SPECULAR);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_COLOR_AMBIENT);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_ALBEDO);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_METALNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_ROUGHNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_OCCLUSION);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_EMISSION);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_HEIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_CUBEMAP);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_IRRADIANCE);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_PREFILTER);
  RAYLIB_LUA_SOL_ADD_ENUM(LOC_MAP_BRDF);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_FLOAT);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_VEC2);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_VEC3);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_VEC4);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_INT);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_IVEC2);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_IVEC3);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_IVEC4);
  RAYLIB_LUA_SOL_ADD_ENUM(UNIFORM_SAMPLER2D);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_ALBEDO);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_METALNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_ROUGHNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_OCCLUSION);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_EMISSION);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_HEIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_CUBEMAP);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_IRRADIANCE);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_PREFILTER);
  RAYLIB_LUA_SOL_ADD_ENUM(MAP_BRDF);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_GRAYSCALE);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_GRAY_ALPHA);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R5G6B5);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R8G8B8);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R5G5B5A1);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R4G4B4A4);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R8G8B8A8);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R32);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R32G32B32);
  RAYLIB_LUA_SOL_ADD_ENUM(UNCOMPRESSED_R32G32B32A32);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_DXT1_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_DXT1_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_DXT3_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_DXT5_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_ETC1_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_ETC2_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_ETC2_EAC_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_PVRT_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_PVRT_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_ASTC_4x4_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(COMPRESSED_ASTC_8x8_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(FILTER_POINT);
  RAYLIB_LUA_SOL_ADD_ENUM(FILTER_BILINEAR);
  RAYLIB_LUA_SOL_ADD_ENUM(FILTER_TRILINEAR);
  RAYLIB_LUA_SOL_ADD_ENUM(FILTER_ANISOTROPIC_4X);
  RAYLIB_LUA_SOL_ADD_ENUM(FILTER_ANISOTROPIC_8X);
  RAYLIB_LUA_SOL_ADD_ENUM(FILTER_ANISOTROPIC_16X);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_AUTO_DETECT);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LINE_VERTICAL);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LINE_HORIZONTAL);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_CROSS_THREE_BY_FOUR);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_CROSS_FOUR_BY_THREE);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_PANORAMA);
  RAYLIB_LUA_SOL_ADD_ENUM(WRAP_REPEAT);
  RAYLIB_LUA_SOL_ADD_ENUM(WRAP_CLAMP);
  RAYLIB_LUA_SOL_ADD_ENUM(WRAP_MIRROR_REPEAT);
  RAYLIB_LUA_SOL_ADD_ENUM(WRAP_MIRROR_CLAMP);
  RAYLIB_LUA_SOL_ADD_ENUM(FONT_DEFAULT);
  RAYLIB_LUA_SOL_ADD_ENUM(FONT_BITMAP);
  RAYLIB_LUA_SOL_ADD_ENUM(FONT_SDF);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_ALPHA);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_ADDITIVE);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_MULTIPLIED);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_NONE);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_TAP);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_DOUBLETAP);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_HOLD);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_DRAG);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_SWIPE_RIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_SWIPE_LEFT);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_SWIPE_UP);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_SWIPE_DOWN);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_PINCH_IN);
  RAYLIB_LUA_SOL_ADD_ENUM(GESTURE_PINCH_OUT);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_CUSTOM);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_FREE);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_ORBITAL);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_FIRST_PERSON);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_THIRD_PERSON);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_PERSPECTIVE);
  RAYLIB_LUA_SOL_ADD_ENUM(CAMERA_ORTHOGRAPHIC);
  RAYLIB_LUA_SOL_ADD_ENUM(NPT_9PATCH);
  RAYLIB_LUA_SOL_ADD_ENUM(NPT_3PATCH_VERTICAL);
  RAYLIB_LUA_SOL_ADD_ENUM(NPT_3PATCH_HORIZONTAL);
}

#define RAYLIB_LUA_SOL_ADD_FUNCTION(x) \
  lua.set_function(#x, x)

void raylib_lua_sol_functions(sol::state &lua) {
  RAYLIB_LUA_SOL_ADD_FUNCTION(InitWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WindowShouldClose);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CloseWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowReady);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowMinimized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowFocused);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowResized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowHidden);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowFullscreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ToggleFullscreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnhideWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(HideWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowIcon);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowTitle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowMonitor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowMinSize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowSize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWindowHandle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorPhysicalWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorPhysicalHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWindowPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWindowScaleDPI);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetClipboardText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetClipboardText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ShowCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(HideCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsCursorHidden);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EnableCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DisableCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ClearBackground);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginDrawing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndDrawing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginMode2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndMode2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginMode3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndMode3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginTextureMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndTextureMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginScissorMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndScissorMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseRay);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCameraMatrix);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCameraMatrix2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorldToScreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorldToScreenEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorldToScreen2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenToWorld2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTargetFPS);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFPS);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFrameTime);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTime);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorToInt);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorNormalize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorFromNormalized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorToHSV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorFromHSV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetColor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(Fade);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetConfigFlags);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTraceLogLevel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTraceLogExit);
  // RAYLIB_LUA_SOL_ADD_FUNCTION(SetTraceLogCallback);
  // RAYLIB_LUA_SOL_ADD_FUNCTION(TraceLog);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TakeScreenshot);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRandomValue);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFileData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SaveFileData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFileText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SaveFileText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileExists);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsFileExtension);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DirectoryExists);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetExtension);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileNameWithoutExt);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetDirectoryPath);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetPrevDirectoryPath);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorkingDirectory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetDirectoryFiles);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ClearDirectoryFiles);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ChangeDirectory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsFileDropped);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetDroppedFiles);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ClearDroppedFiles);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileModTime);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CompressData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DecompressData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SaveStorageValue);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadStorageValue);
  RAYLIB_LUA_SOL_ADD_FUNCTION(OpenURL);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyDown);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyReleased);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyUp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetExitKey);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetKeyPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadAvailable);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonDown);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonReleased);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonUp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadButtonPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadAxisCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadAxisMovement);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonDown);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonReleased);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonUp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseX);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseY);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMousePosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMousePosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMouseOffset);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMouseScale);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseWheelMove);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchX);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchY);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetGesturesEnabled);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGestureDetected);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureDetected);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchPointsCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureHoldDuration);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureDragVector);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureDragAngle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGesturePinchVector);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGesturePinchAngle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetCameraMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateCamera);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetCameraPanControl);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetCameraAltControl);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetCameraSmoothZoomControl);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetCameraMoveControls);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPixel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPixelV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLine);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineBezier);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineStrip);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleSector);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleSectorLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleGradient);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawEllipse);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawEllipseLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRingLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectanglePro);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleGradientV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleGradientH);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleGradientEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleLinesEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleRounded);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleRoundedLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangleFan);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangleStrip);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPoly);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPolyLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionRecs);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionCircles);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionCircleRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCollisionRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointCircle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImageEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImageRaw);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportImageAsCode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetImageData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetImageDataNormalized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageColor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageGradientV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageGradientH);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageGradientRadial);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageChecked);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageWhiteNoise);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImagePerlinNoise);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageCellular);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageCopy);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFromImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageToPOT);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFormat);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaMask);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaClear);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaCrop);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaPremultiply);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageCrop);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageResize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageResizeNN);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageResizeCanvas);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageMipmaps);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDither);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFlipVertical);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFlipHorizontal);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageRotateCW);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageRotateCCW);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorTint);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorInvert);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorGrayscale);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorContrast);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorBrightness);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorReplace);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageExtractPalette);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetImageAlphaBorder);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageClearBackground);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawPixel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawPixelV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawLine);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawLineV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawCircle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawCircleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangleRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDraw);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadTextureFromImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadTextureCubemap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadRenderTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadRenderTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTextureData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenTextureMipmaps);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTextureFilter);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTextureWrap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureQuad);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTexturePro);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureNPatch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetPixelDataSize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFontDefault);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFont);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFontEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFontFromImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFontData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageFontAtlas);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadFont);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawFPS);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextRecEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextCodepoint);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeasureText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeasureTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGlyphIndex);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextCopy);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextIsEqual);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextLength);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextFormat);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextSubtext);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextReplace);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextInsert);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextJoin);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextSplit);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextAppend);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextFindIndex);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToUpper);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToLower);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToPascal);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToInteger);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToUtf8);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCodepoints);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCodepointsCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetNextCodepoint);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CodepointToUtf8);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLine3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPoint3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircle3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCube);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeWiresV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSphereEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSphereWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCylinder);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCylinderWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPlane);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRay);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawGrid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawGizmo);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadModelFromMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadMeshes);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadMaterials);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadMaterialDefault);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadMaterial);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMaterialTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetModelMeshMaterial);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadModelAnimations);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateModelAnimation);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadModelAnimation);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsModelAnimationValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshPoly);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshPlane);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCube);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshHemiSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCylinder);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshTorus);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshKnot);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshHeightmap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCubicmap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeshBoundingBox);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeshTangents);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeshBinormals);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModelEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModelWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModelWiresEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBoundingBox);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBillboard);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBillboardRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionSpheres);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionBoxes);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionBoxSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionRaySphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionRaySphereEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionRayBox);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCollisionRayModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCollisionRayTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCollisionRayGround);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadShader);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadShaderCode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadShader);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShaderDefault);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTextureDefault);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShapesTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShapesTextureRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShapesTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShaderLocation);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShaderValue);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShaderValueV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShaderValueMatrix);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShaderValueTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMatrixProjection);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMatrixModelview);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMatrixModelview);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMatrixProjection);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenTextureCubemap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenTextureIrradiance);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenTexturePrefilter);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenTextureBRDF);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginShaderMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndShaderMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginBlendMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndBlendMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(InitVrSimulator);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CloseVrSimulator);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateVrTracking);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetVrConfiguration);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsVrSimulatorReady);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ToggleVrMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginVrDrawing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndVrDrawing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(InitAudioDevice);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CloseAudioDevice);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioDeviceReady);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMasterVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadSoundFromWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportWaveAsCode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlaySound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PauseSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ResumeSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlaySoundMulti);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopSoundMulti);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetSoundsPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsSoundPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetSoundVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetSoundPitch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaveFormat);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaveCopy);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaveCrop);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWaveData);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlayMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PauseMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ResumeMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMusicPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMusicVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMusicPitch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMusicLoopCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMusicTimeLength);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMusicTimePlayed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(InitAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CloseAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioStreamProcessed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlayAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PauseAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ResumeAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioStreamPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamPitch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamBufferSizeDefault);
}

void TraceLogWrapper(int messageType, const std::string& message) {
  TraceLog(messageType, message.c_str());
}

void raylib_lua_sol_function_wrappers(sol::state &lua) {
  lua.set_function("TraceLog", &TraceLogWrapper);
}

void raylib_lua_sol(sol::state& lua) {
  raylib_lua_sol_structs(lua);
	raylib_lua_sol_color(lua);
	raylib_lua_sol_enums(lua);
  raylib_lua_sol_functions(lua);
  raylib_lua_sol_function_wrappers(lua);
}

#endif // RAYLIB_LUA_SOL_

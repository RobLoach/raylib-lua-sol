#ifndef RAYLIB_LUA_SOL_
#define RAYLIB_LUA_SOL_

#include "raylib.h"

#include <string>
#include <tuple>

#include "sol/sol.hpp"
#include "./raylib-lua-sol-rlgl.hpp"
#include "./raylib-lua-sol-raymath.hpp"

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
    "z", &Vector3::z,
    sol::meta_function::to_string, [](Vector3& v) {
      return TextFormat("{x: %02.02f, y: %02.02f, z: %02.02f}", v.x, v.y, v.z);
    });
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
    "w", &Vector4::w,
    sol::meta_function::to_string, [](Vector4& v) {
      return TextFormat("{x: %02.02f, y: %02.02f, z: %02.02f, w: %02.02f}", v.x, v.y, v.z, v.w);
    });
  lua["Quaternion"] = lua["Vector4"];
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
  lua.new_usertype<Texture>("Texture",
    "id", &Texture::id,
    "width", &Texture::width,
    "height", &Texture::height,
    "mipmaps", &Texture::mipmaps,
    "format", &Texture::format);
  lua["Texture2D"] = lua["Texture"];
  lua["TextureCubemap"] = lua["Texture"];
  lua.new_usertype<RenderTexture>("RenderTexture2D",
    "id", &RenderTexture::id,
    "texture", &RenderTexture::texture,
    "depth", &RenderTexture::depth);
  lua["RenderTexture"] = lua["RenderTexture2D"];
  lua.new_usertype<NPatchInfo>("NPatchInfo",
    "source", &NPatchInfo::source,
    "left", &NPatchInfo::left,
    "top", &NPatchInfo::top,
    "right", &NPatchInfo::right,
    "bottom", &NPatchInfo::bottom,
    "layout", &NPatchInfo::layout);
  lua.new_usertype<GlyphInfo>("GlyphInfo",
    "value", &GlyphInfo::value,
    "offsetX", &GlyphInfo::offsetX,
    "offsetY", &GlyphInfo::offsetY,
    "advanceX", &GlyphInfo::advanceX,
    "image", &GlyphInfo::image);
  lua.new_usertype<Font>("Font",
    "baseSize", &Font::baseSize,
    "glyphCount", &Font::glyphCount,
    "glyphPadding", &Font::glyphPadding,
    "texture", &Font::texture,
    "recs", &Font::recs,
    "glyphs", &Font::glyphs);
  lua.new_usertype<Camera3D>("Camera",
    sol::call_constructor, sol::factories(
      [](){
        return Camera3D{};
      },
      [](Vector3 position, Vector3 target, Vector3 up, float fovy, int projection){
        return Camera3D{position, target, up, fovy, projection};
      },
      [](Vector3 position, Vector3 target, Vector3 up, float fovy){
        return Camera3D{position, target, up, fovy, CAMERA_PERSPECTIVE};
      },
      [](Vector3 position, Vector3 target, Vector3 up){
        return Camera3D{position, target, up, 45.0f, CAMERA_PERSPECTIVE};
      }
    ),
    "position", &Camera3D::position,
    "target", &Camera3D::target,
    "up", &Camera3D::up,
    "fovy", &Camera3D::fovy,
    "projection", &Camera3D::projection);
  lua["Camera3D"] = lua["Camera"];
  lua.new_usertype<Camera2D>("Camera2D",
    sol::call_constructor, sol::factories(
      [](){
        return Camera2D{{0.0f, 0.0f}, {0.0f, 0.0f}, 0.0f, 1.0f};
      },
      [](Vector2 offset, Vector2 target, float rotation, float zoom){
        return Camera2D{offset, target, rotation, zoom};
      },
      [](Vector2 offset, Vector2 target){
        return Camera2D{offset, target, 0.0f, 1.0f};
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
    "boneCount", &Mesh::boneCount,
    "boneIndices", &Mesh::boneIndices,
    "boneWeights", &Mesh::boneWeights,
    "animVertices", &Mesh::animVertices,
    "animNormals", &Mesh::animNormals,
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
    "maps", &Material::maps);
  lua.new_usertype<Transform>("Transform",
    "translation", &Transform::translation,
    "rotation", &Transform::rotation,
    "scale", &Transform::scale);
  lua.new_usertype<BoneInfo>("BoneInfo",
    "parent", &BoneInfo::parent);
  lua.new_usertype<ModelSkeleton>("ModelSkeleton",
    "boneCount", &ModelSkeleton::boneCount,
    "bones", &ModelSkeleton::bones,
    "bindPose", &ModelSkeleton::bindPose);
  lua.new_usertype<Model>("Model",
    "transform", &Model::transform,
    "meshCount", &Model::meshCount,
    "materialCount", &Model::materialCount,
    "meshes", &Model::meshes,
    "materials", &Model::materials,
    "meshMaterial", &Model::meshMaterial,
    "skeleton", &Model::skeleton,
    "currentPose", &Model::currentPose,
    "boneMatrices", &Model::boneMatrices);
  lua.new_usertype<ModelAnimation>("ModelAnimation",
    "boneCount", &ModelAnimation::boneCount,
    "keyframeCount", &ModelAnimation::keyframeCount);
  lua.new_usertype<Ray>("Ray",
    sol::call_constructor, sol::factories(
      [](){
        return Ray{};
      },
      [](Vector3 pos){
        return Ray{pos, Vector3{0, 0, 0}};
      },
      [](Vector3 pos, Vector3 dir){
        return Ray{pos, dir};
      }
    ),
    "position", &Ray::position,
    "direction", &Ray::direction);
  lua.new_usertype<RayCollision>("RayCollision",
    sol::call_constructor, sol::factories(
      [](){
        return RayCollision{};
      }
    ),
    "hit", &RayCollision::hit,
    "distance", &RayCollision::distance,
    "point", &RayCollision::point,
    "normal", &RayCollision::normal);
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
    "frameCount", &Wave::frameCount,
    "sampleRate", &Wave::sampleRate,
    "sampleSize", &Wave::sampleSize,
    "channels", &Wave::channels,
    "data", &Wave::data);
  lua.new_usertype<AudioStream>("AudioStream",
    "sampleRate", &AudioStream::sampleRate,
    "sampleSize", &AudioStream::sampleSize,
    "channels", &AudioStream::channels);
  lua.new_usertype<Sound>("Sound",
    "stream", &Sound::stream,
    "frameCount", &Sound::frameCount);
  lua.new_usertype<Music>("Music",
    "stream", &Music::stream,
    "frameCount", &Music::frameCount,
    "looping", &Music::looping,
    "ctxType", &Music::ctxType,
    "ctxData", &Music::ctxData);
  lua.new_usertype<VrDeviceInfo>("VrDeviceInfo",
    "hResolution", &VrDeviceInfo::hResolution,
    "vResolution", &VrDeviceInfo::vResolution,
    "hScreenSize", &VrDeviceInfo::hScreenSize,
    "vScreenSize", &VrDeviceInfo::vScreenSize,
    "eyeToScreenDistance", &VrDeviceInfo::eyeToScreenDistance,
    "lensSeparationDistance", &VrDeviceInfo::lensSeparationDistance,
    "interpupillaryDistance", &VrDeviceInfo::interpupillaryDistance);
  lua.new_usertype<VrStereoConfig>("VrStereoConfig");
  lua.new_usertype<FilePathList>("FilePathList",
    "count", &FilePathList::count);
  lua.new_usertype<AutomationEvent>("AutomationEvent",
    "frame", &AutomationEvent::frame,
    "type", &AutomationEvent::type);
  lua.new_usertype<AutomationEventList>("AutomationEventList",
    "capacity", &AutomationEventList::capacity,
    "count", &AutomationEventList::count,
    "events", &AutomationEventList::events);
}

#ifndef RAYLIB_LUA_SOL_ADD_ENUM
#define RAYLIB_LUA_SOL_ADD_ENUM(x) \
  lua[#x] = x
#endif

void raylib_lua_sol_enums(sol::state &lua) {
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_VSYNC_HINT);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_FULLSCREEN_MODE);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_RESIZABLE);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_UNDECORATED);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_HIDDEN);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_MINIMIZED);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_MAXIMIZED);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_UNFOCUSED);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_TOPMOST);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_ALWAYS_RUN);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_TRANSPARENT);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_HIGHDPI);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_WINDOW_MOUSE_PASSTHROUGH);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_BORDERLESS_WINDOWED_MODE);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_MSAA_4X_HINT);
  RAYLIB_LUA_SOL_ADD_ENUM(FLAG_INTERLACED_HINT);

  RAYLIB_LUA_SOL_ADD_ENUM(LOG_ALL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_TRACE);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_DEBUG);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_INFO);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_WARNING);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_ERROR);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_FATAL);
  RAYLIB_LUA_SOL_ADD_ENUM(LOG_NONE);

  RAYLIB_LUA_SOL_ADD_ENUM(KEY_NULL);
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
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_LEFT_BRACKET);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_BACKSLASH);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_RIGHT_BRACKET);
  RAYLIB_LUA_SOL_ADD_ENUM(KEY_GRAVE);
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

  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_LEFT);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_RIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_MIDDLE);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_SIDE);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_EXTRA);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_FORWARD);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_BUTTON_BACK);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_LEFT_BUTTON);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_RIGHT_BUTTON);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_MIDDLE_BUTTON);

  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_DEFAULT);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_ARROW);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_IBEAM);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_CROSSHAIR);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_POINTING_HAND);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_RESIZE_EW);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_RESIZE_NS);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_RESIZE_NWSE);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_RESIZE_NESW);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_RESIZE_ALL);
  RAYLIB_LUA_SOL_ADD_ENUM(MOUSE_CURSOR_NOT_ALLOWED);

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

  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_LEFT_X);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_LEFT_Y);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_RIGHT_X);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_RIGHT_Y);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_LEFT_TRIGGER);
  RAYLIB_LUA_SOL_ADD_ENUM(GAMEPAD_AXIS_RIGHT_TRIGGER);

  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_ALBEDO);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_METALNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_ROUGHNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_OCCLUSION);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_EMISSION);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_HEIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_CUBEMAP);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_IRRADIANCE);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_PREFILTER);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_BRDF);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_DIFFUSE);
  RAYLIB_LUA_SOL_ADD_ENUM(MATERIAL_MAP_SPECULAR);

  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_POSITION);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_TEXCOORD01);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_TEXCOORD02);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_TANGENT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_COLOR);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MATRIX_MVP);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MATRIX_VIEW);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MATRIX_PROJECTION);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MATRIX_MODEL);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MATRIX_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VECTOR_VIEW);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_COLOR_DIFFUSE);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_COLOR_SPECULAR);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_COLOR_AMBIENT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_ALBEDO);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_METALNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_NORMAL);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_ROUGHNESS);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_OCCLUSION);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_EMISSION);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_HEIGHT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_CUBEMAP);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_IRRADIANCE);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_PREFILTER);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_BRDF);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_BONEIDS);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_BONEWEIGHTS);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MATRIX_BONETRANSFORMS);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_VERTEX_INSTANCETRANSFORM);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_DIFFUSE);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_LOC_MAP_SPECULAR);

  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_FLOAT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_VEC2);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_VEC3);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_VEC4);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_INT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_IVEC2);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_IVEC3);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_IVEC4);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_UINT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_UIVEC2);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_UIVEC3);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_UIVEC4);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_UNIFORM_SAMPLER2D);

  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_ATTRIB_FLOAT);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_ATTRIB_VEC2);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_ATTRIB_VEC3);
  RAYLIB_LUA_SOL_ADD_ENUM(SHADER_ATTRIB_VEC4);

  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R5G6B5);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R8G8B8);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R5G5B5A1);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R4G4B4A4);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R32);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R32G32B32);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R32G32B32A32);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R16);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R16G16B16);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R16G16B16A16);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT1_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT1_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT3_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT5_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_ETC1_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_ETC2_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_PVRT_RGB);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_PVRT_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA);
  RAYLIB_LUA_SOL_ADD_ENUM(PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA);

  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_FILTER_POINT);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_FILTER_BILINEAR);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_FILTER_TRILINEAR);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_FILTER_ANISOTROPIC_4X);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_FILTER_ANISOTROPIC_8X);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_FILTER_ANISOTROPIC_16X);

  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_WRAP_REPEAT);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_WRAP_CLAMP);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_WRAP_MIRROR_REPEAT);
  RAYLIB_LUA_SOL_ADD_ENUM(TEXTURE_WRAP_MIRROR_CLAMP);

  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LAYOUT_AUTO_DETECT);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LAYOUT_LINE_VERTICAL);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LAYOUT_LINE_HORIZONTAL);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR);
  RAYLIB_LUA_SOL_ADD_ENUM(CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE);

  RAYLIB_LUA_SOL_ADD_ENUM(FONT_DEFAULT);
  RAYLIB_LUA_SOL_ADD_ENUM(FONT_BITMAP);
  RAYLIB_LUA_SOL_ADD_ENUM(FONT_SDF);

  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_ALPHA);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_ADDITIVE);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_MULTIPLIED);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_ADD_COLORS);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_SUBTRACT_COLORS);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_ALPHA_PREMULTIPLY);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_CUSTOM);
  RAYLIB_LUA_SOL_ADD_ENUM(BLEND_CUSTOM_SEPARATE);

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

  RAYLIB_LUA_SOL_ADD_ENUM(NPATCH_NINE_PATCH);
  RAYLIB_LUA_SOL_ADD_ENUM(NPATCH_THREE_PATCH_VERTICAL);
  RAYLIB_LUA_SOL_ADD_ENUM(NPATCH_THREE_PATCH_HORIZONTAL);
}

#define RAYLIB_LUA_SOL_ADD_FUNCTION(x) \
  lua.set_function(#x, x)

void raylib_lua_sol_functions(sol::state &lua) {
  RAYLIB_LUA_SOL_ADD_FUNCTION(InitWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CloseWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WindowShouldClose);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowReady);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowFullscreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowHidden);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowMinimized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowMaximized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowFocused);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowResized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWindowState);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowState);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ClearWindowState);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ToggleFullscreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ToggleBorderlessWindowed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MaximizeWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MinimizeWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(RestoreWindow);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowIcon);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowTitle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowMonitor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowMinSize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowMaxSize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowSize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowOpacity);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetWindowFocused);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRenderWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRenderHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCurrentMonitor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorPhysicalWidth);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorPhysicalHeight);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorRefreshRate);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWindowPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWindowScaleDPI);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMonitorName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetClipboardText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetClipboardText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetClipboardImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EnableEventWaiting);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DisableEventWaiting);

  RAYLIB_LUA_SOL_ADD_FUNCTION(ShowCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(HideCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsCursorHidden);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EnableCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DisableCursor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsCursorOnScreen);

  RAYLIB_LUA_SOL_ADD_FUNCTION(ClearBackground);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginDrawing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndDrawing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginMode2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndMode2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginMode3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndMode3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginTextureMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndTextureMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginShaderMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndShaderMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginBlendMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndBlendMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginScissorMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndScissorMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(BeginVrStereoMode);
  RAYLIB_LUA_SOL_ADD_FUNCTION(EndVrStereoMode);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadVrStereoConfig);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadVrStereoConfig);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadShader);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadShaderFromMemory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsShaderValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShaderLocation);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShaderLocationAttrib);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShaderValueMatrix);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShaderValueTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadShader);

  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenToWorldRay);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenToWorldRayEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorldToScreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorldToScreenEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorldToScreen2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetScreenToWorld2D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCameraMatrix);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCameraMatrix2D);

  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTargetFPS);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFrameTime);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTime);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFPS);

  RAYLIB_LUA_SOL_ADD_FUNCTION(SwapScreenBuffer);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PollInputEvents);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaitTime);

  RAYLIB_LUA_SOL_ADD_FUNCTION(SetRandomSeed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRandomValue);

  RAYLIB_LUA_SOL_ADD_FUNCTION(TakeScreenshot);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetConfigFlags);
  RAYLIB_LUA_SOL_ADD_FUNCTION(OpenURL);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTraceLogLevel);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFileText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadFileText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SaveFileText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileRename);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileRemove);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileCopy);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileMove);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileTextReplace);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileTextFindIndex);
  RAYLIB_LUA_SOL_ADD_FUNCTION(FileExists);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DirectoryExists);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsFileExtension);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileLength);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileModTime);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileExtension);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFileNameWithoutExt);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetDirectoryPath);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetPrevDirectoryPath);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetWorkingDirectory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetApplicationDirectory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MakeDirectory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ChangeDirectory);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsPathFile);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsFileNameValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsFileDropped);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetDirectoryFileCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetDirectoryFileCountEx);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadAutomationEventList);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadAutomationEventList);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportAutomationEventList);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAutomationEventBaseFrame);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StartAutomationEventRecording);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopAutomationEventRecording);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlayAutomationEvent);

  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyPressedRepeat);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyDown);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyReleased);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsKeyUp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetKeyPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCharPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetKeyName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetExitKey);

  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadAvailable);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadName);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonDown);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonReleased);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGamepadButtonUp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadButtonPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadAxisCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGamepadAxisMovement);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetGamepadMappings);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetGamepadVibration);

  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonPressed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonDown);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonReleased);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMouseButtonUp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseX);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseY);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMousePosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseDelta);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMousePosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMouseOffset);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMouseScale);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseWheelMove);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMouseWheelMoveV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMouseCursor);

  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchX);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchY);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchPosition);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchPointId);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTouchPointCount);

  RAYLIB_LUA_SOL_ADD_FUNCTION(SetGesturesEnabled);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsGestureDetected);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureDetected);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureHoldDuration);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureDragVector);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGestureDragAngle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGesturePinchVector);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGesturePinchAngle);

  RAYLIB_LUA_SOL_ADD_FUNCTION(SetShapesTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShapesTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetShapesTextureRectangle);

  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPixel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPixelV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLine);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineBezier);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLineDashed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleGradient);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleSector);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleSectorLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircleLinesV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawEllipse);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawEllipseV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawEllipseLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawEllipseLinesV);
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
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRectangleRoundedLinesEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPoly);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPolyLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPolyLinesEx);

  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSplineSegmentLinear);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSplineSegmentBasis);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSplineSegmentCatmullRom);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSplineSegmentBezierQuadratic);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSplineSegmentBezierCubic);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetSplinePointLinear);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetSplinePointBasis);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetSplinePointCatmullRom);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetSplinePointBezierQuad);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetSplinePointBezierCubic);

  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionRecs);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionCircles);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionCircleRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionCircleLine);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointCircle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionPointLine);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCollisionRec);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImageRaw);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImageFromTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadImageFromScreen);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsImageValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportImageAsCode);

  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageColor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageGradientLinear);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageGradientRadial);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageGradientSquare);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageChecked);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageWhiteNoise);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImagePerlinNoise);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageCellular);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenImageText);

  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageCopy);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFromImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFromChannel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFormat);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageToPOT);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageCrop);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaCrop);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaClear);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaMask);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageAlphaPremultiply);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageBlurGaussian);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageResize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageResizeNN);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageResizeCanvas);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageMipmaps);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDither);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFlipVertical);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageFlipHorizontal);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageRotate);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageRotateCW);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageRotateCCW);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorTint);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorInvert);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorGrayscale);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorContrast);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorBrightness);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageColorReplace);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetImageAlphaBorder);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetImageColor);

  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageClearBackground);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawPixel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawPixelV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawLine);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawLineV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawLineEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawCircle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawCircleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawCircleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawCircleLinesV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangleV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangleRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawRectangleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawTriangleEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawTriangleLines);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDraw);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ImageDrawTextEx);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadTextureFromImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadTextureCubemap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadRenderTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsTextureValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsRenderTextureValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadRenderTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenTextureMipmaps);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTextureFilter);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTextureWrap);

  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTexturePro);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextureNPatch);

  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorIsEqual);
  RAYLIB_LUA_SOL_ADD_FUNCTION(Fade);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorToInt);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorNormalize);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorFromNormalized);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorToHSV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorFromHSV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorTint);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorBrightness);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorContrast);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorAlpha);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorAlphaBlend);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ColorLerp);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetColor);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetPixelDataSize);

  RAYLIB_LUA_SOL_ADD_FUNCTION(GetFontDefault);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFont);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadFontFromImage);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsFontValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadFont);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportFontAsCode);

  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawFPS);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextPro);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTextCodepoint);

  RAYLIB_LUA_SOL_ADD_FUNCTION(SetTextLineSpacing);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeasureText);
  RAYLIB_LUA_SOL_ADD_FUNCTION(MeasureTextEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGlyphIndex);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGlyphInfo);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetGlyphAtlasRec);

  RAYLIB_LUA_SOL_ADD_FUNCTION(GetCodepointCount);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextIsEqual);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextLength);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextSubtext);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextRemoveSpaces);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetTextBetween);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextReplace);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextReplaceAlloc);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextReplaceBetween);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextReplaceBetweenAlloc);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextInsert);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextInsertAlloc);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextFindIndex);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToUpper);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToLower);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToPascal);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToSnake);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToCamel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToInteger);
  RAYLIB_LUA_SOL_ADD_FUNCTION(TextToFloat);

  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawLine3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPoint3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCircle3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawTriangle3D);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCube);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCubeWiresV);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSphereEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawSphereWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCylinder);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCylinderEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCylinderWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCylinderWiresEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCapsule);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawCapsuleWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawPlane);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawRay);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawGrid);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadModelFromMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsModelValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetModelBoundingBox);

  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModel);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModelEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModelWires);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawModelWiresEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBoundingBox);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBillboard);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBillboardRec);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawBillboardPro);

  RAYLIB_LUA_SOL_ADD_FUNCTION(UploadMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(DrawMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMeshBoundingBox);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshTangents);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportMeshAsCode);

  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshPoly);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshPlane);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCube);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshHemiSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCylinder);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCone);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshTorus);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshKnot);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshHeightmap);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GenMeshCubicmap);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadMaterialDefault);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMaterialValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadMaterial);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMaterialTexture);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetModelMeshMaterial);

  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateModelAnimation);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateModelAnimationEx);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsModelAnimationValid);

  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionSpheres);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionBoxes);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CheckCollisionBoxSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRayCollisionSphere);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRayCollisionBox);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRayCollisionMesh);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRayCollisionTriangle);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetRayCollisionQuad);

  RAYLIB_LUA_SOL_ADD_FUNCTION(InitAudioDevice);
  RAYLIB_LUA_SOL_ADD_FUNCTION(CloseAudioDevice);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioDeviceReady);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMasterVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMasterVolume);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsWaveValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadSoundFromWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadSoundAlias);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsSoundValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadSoundAlias);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportWave);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ExportWaveAsCode);

  RAYLIB_LUA_SOL_ADD_FUNCTION(PlaySound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PauseSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ResumeSound);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsSoundPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetSoundVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetSoundPitch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetSoundPan);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaveCopy);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaveCrop);
  RAYLIB_LUA_SOL_ADD_FUNCTION(WaveFormat);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMusicValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlayMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsMusicStreamPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UpdateMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PauseMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ResumeMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SeekMusicStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMusicVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMusicPitch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetMusicPan);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMusicTimeLength);
  RAYLIB_LUA_SOL_ADD_FUNCTION(GetMusicTimePlayed);

  RAYLIB_LUA_SOL_ADD_FUNCTION(LoadAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioStreamValid);
  RAYLIB_LUA_SOL_ADD_FUNCTION(UnloadAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioStreamProcessed);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PlayAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(PauseAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(ResumeAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(IsAudioStreamPlaying);
  RAYLIB_LUA_SOL_ADD_FUNCTION(StopAudioStream);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamVolume);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamPitch);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamPan);
  RAYLIB_LUA_SOL_ADD_FUNCTION(SetAudioStreamBufferSizeDefault);
}

static sol::table FilePathListToLuaTable(sol::state& lua, FilePathList list) {
  sol::table paths = lua.create_table();
  for (unsigned int i = 0; i < list.count; i++) {
    paths[i + 1] = std::string(list.paths[i] ? list.paths[i] : "");
  }
  return paths;
}

void TraceLogWrapper(int messageType, const std::string& message) {
  TraceLog(messageType, "%s", message.c_str());
}

void raylib_lua_sol_function_wrappers(sol::state &lua) {
  lua.set_function("TraceLog", &TraceLogWrapper);

  lua.set_function("UpdateCamera", [](Camera& camera, int mode) {
    UpdateCamera(&camera, mode);
  });
  lua.set_function("UpdateCameraPro", [](Camera& camera, Vector3 movement, Vector3 rotation, float zoom) {
    UpdateCameraPro(&camera, movement, rotation, zoom);
  });

  lua.set_function("LoadDroppedFiles", [&lua]() {
    FilePathList list = LoadDroppedFiles();
    sol::table paths = FilePathListToLuaTable(lua, list);
    UnloadDroppedFiles(list);
    return paths;
  });
  lua.set_function("LoadDirectoryFiles", [&lua](const char* dirPath) {
    FilePathList list = LoadDirectoryFiles(dirPath);
    sol::table paths = FilePathListToLuaTable(lua, list);
    UnloadDirectoryFiles(list);
    return paths;
  });
  lua.set_function("LoadDirectoryFilesEx", [&lua](const char* basePath, const char* filter, bool scanSubdirs) {
    FilePathList list = LoadDirectoryFilesEx(basePath, filter, scanSubdirs);
    sol::table paths = FilePathListToLuaTable(lua, list);
    UnloadDirectoryFiles(list);
    return paths;
  });

  lua.set_function("LoadFontEx", sol::overload(
    [](const char* fileName, int fontSize) {
      return LoadFontEx(fileName, fontSize, nullptr, 0);
    },
    [](const char* fileName, int fontSize, sol::object, int glyphCount) {
      return LoadFontEx(fileName, fontSize, nullptr, glyphCount);
    }
  ));

  lua.set_function("CheckCollisionLines", [](Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2) {
    Vector2 collisionPoint{};
    bool collided = CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, &collisionPoint);
    return std::tuple<bool, Vector2>(collided, collisionPoint);
  });

  lua.set_function("SetShaderValue", sol::overload(
    [](Shader shader, int locIndex, float value) {
      SetShaderValue(shader, locIndex, &value, SHADER_UNIFORM_FLOAT);
    },
    [](Shader shader, int locIndex, Vector2 value) {
      SetShaderValue(shader, locIndex, &value, SHADER_UNIFORM_VEC2);
    },
    [](Shader shader, int locIndex, Vector3 value) {
      SetShaderValue(shader, locIndex, &value, SHADER_UNIFORM_VEC3);
    },
    [](Shader shader, int locIndex, Vector4 value) {
      SetShaderValue(shader, locIndex, &value, SHADER_UNIFORM_VEC4);
    },
    [](Shader shader, int locIndex, float value, int uniformType) {
      SetShaderValue(shader, locIndex, &value, uniformType);
    },
    [](Shader shader, int locIndex, Vector2 value, int uniformType) {
      SetShaderValue(shader, locIndex, &value, uniformType);
    },
    [](Shader shader, int locIndex, Vector3 value, int uniformType) {
      SetShaderValue(shader, locIndex, &value, uniformType);
    },
    [](Shader shader, int locIndex, Vector4 value, int uniformType) {
      SetShaderValue(shader, locIndex, &value, uniformType);
    }
  ));
}

void raylib_lua_sol(sol::state& lua) {
  raylib_lua_sol_color(lua);
  raylib_lua_sol_enums(lua);
  raylib_lua_sol_functions(lua);
  raylib_lua_sol_function_wrappers(lua);
  raylib_lua_sol_structs(lua);
  raylib_lua_sol_rlgl(lua);
  raylib_lua_sol_raymath(lua);
}

#endif // RAYLIB_LUA_SOL_

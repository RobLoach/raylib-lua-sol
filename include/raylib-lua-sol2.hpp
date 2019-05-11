#ifndef RAYLIB_LUA_SOL2_
#define RAYLIB_LUA_SOL2_

#include <raylib.h>
#include <sol/sol.hpp>
#include <iostream>

void raylib_lua_sol2_color(sol::state &lua) {
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

void raylib_lua_sol2_structs(sol::state &lua) {
	lua.new_usertype<Vector2>("Vector2",
    sol::call_constructor, sol::factories(
      [](){
        return Vector2{};
      },
      [](float x){
        return Vector2{x, 0};
      },
      [](float x, float y){
        return Vector2{x, y};
      }
    ),
		"x", &Vector2::x,
		"y", &Vector2::y);
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
	lua.new_usertype<Rectangle>("Rectangle",
    sol::call_constructor, sol::factories(
      [](){
        return Rectangle{};
      },
      [](float x, float y){
        return Rectangle{x, y, 0, 0};
      },
      [](float x, float y, float width, float height){
        return Rectangle{x, y, width, height};
      }
    ),
		"x", &Rectangle::x,
		"y", &Rectangle::y,
		"width", &Rectangle::width,
		"height", &Rectangle::height);
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
  // TODO: Add remaining Structs
}

void raylib_lua_sol2_enums(sol::state &lua) {
	lua.new_enum("ConfigFlag",
		"FLAG_SHOW_LOGO", FLAG_SHOW_LOGO,
		"FLAG_FULLSCREEN_MODE", FLAG_FULLSCREEN_MODE,
		"FLAG_WINDOW_RESIZABLE", FLAG_WINDOW_RESIZABLE,
		"FLAG_WINDOW_UNDECORATED", FLAG_WINDOW_UNDECORATED,
		"FLAG_WINDOW_TRANSPARENT", FLAG_WINDOW_TRANSPARENT,
		"FLAG_WINDOW_HIDDEN", FLAG_WINDOW_HIDDEN,
		"FLAG_MSAA_4X_HINT", FLAG_MSAA_4X_HINT,
		"FLAG_VSYNC_HINT", FLAG_VSYNC_HINT
	);
  lua.new_enum("TraceLogType",
    "LOG_ALL", LOG_ALL,
    "LOG_TRACE", LOG_TRACE,
    "LOG_DEBUG", LOG_DEBUG,
    "LOG_INFO", LOG_INFO,
    "LOG_WARNING", LOG_WARNING,
    "LOG_ERROR", LOG_ERROR,
    "LOG_FATAL", LOG_FATAL,
    "LOG_NONE", LOG_NONE
  );
  // TODO: Add remaining enums
}

#define RAYLIB_LUA_SOL2_ADD_FUNCTION(x) \
  lua.set_function(#x, x)

void raylib_lua_sol2_functions(sol::state &lua) {
  RAYLIB_LUA_SOL2_ADD_FUNCTION(InitWindow);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(WindowShouldClose);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CloseWindow);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsWindowReady);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsWindowMinimized);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsWindowResized);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsWindowHidden);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ToggleFullscreen);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnhideWindow);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(HideWindow);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetWindowIcon);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetWindowTitle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetWindowPosition);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetWindowMonitor);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetWindowMinSize);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetWindowSize);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetWindowHandle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetScreenWidth);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetScreenHeight);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMonitorCount);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMonitorWidth);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMonitorHeight);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMonitorPhysicalWidth);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMonitorPhysicalHeight);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMonitorName);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetClipboardText);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetClipboardText);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(ShowCursor);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(HideCursor);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsCursorHidden);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EnableCursor);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DisableCursor);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(ClearBackground);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginDrawing);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndDrawing);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginMode2D);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndMode2D);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginMode3D);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndMode3D);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginTextureMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndTextureMode);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMouseRay);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetWorldToScreen);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetCameraMatrix);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetTargetFPS);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetFPS);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetFrameTime);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTime);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(ColorToInt);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ColorNormalize);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ColorToHSV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ColorFromHSV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetColor);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(Fade);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetConfigFlags);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetTraceLogLevel);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetTraceLogExit);
  // TODO: Add SetTraceLogCallback
  //RAYLIB_LUA_SOL2_ADD_FUNCTION(SetTraceLogCallback);
  // TODO: Add TraceLog
  //RAYLIB_LUA_SOL2_ADD_FUNCTION(TraceLog);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TakeScreenshot);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetRandomValue);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(FileExists);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsFileExtension);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetExtension);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetFileName);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetFileNameWithoutExt);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetDirectoryPath);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetWorkingDirectory);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetDirectoryFiles);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ClearDirectoryFiles);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ChangeDirectory);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsFileDropped);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetDroppedFiles);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ClearDroppedFiles);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetFileModTime);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(StorageSaveValue);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(StorageLoadValue);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(OpenURL);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsKeyPressed);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsKeyDown);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsKeyReleased);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsKeyUp);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetKeyPressed);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetExitKey);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGamepadAvailable);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGamepadName);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGamepadName);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGamepadButtonPressed);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGamepadButtonDown);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGamepadButtonReleased);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGamepadButtonUp);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGamepadButtonPressed);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGamepadAxisCount);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGamepadAxisMovement);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsMouseButtonPressed);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsMouseButtonDown);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsMouseButtonReleased);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsMouseButtonUp);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMouseX);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMouseY);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMousePosition);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMousePosition);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMouseOffset);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMouseScale);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMouseWheelMove);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTouchX);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTouchY);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTouchPosition);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetGesturesEnabled);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsGestureDetected);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGestureDetected);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTouchPointsCount);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGestureHoldDuration);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGestureDragVector);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGestureDragAngle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGesturePinchVector);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGesturePinchAngle);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetCameraMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateCamera);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetCameraPanControl);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetCameraAltControl);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetCameraSmoothZoomControl);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetCameraMoveControls);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawPixel);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawPixelV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawLine);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawLineV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawLineEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawLineBezier);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawLineStrip);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircleSector);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircleSectorLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircleGradient);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircleV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircleLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRing);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRingLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleRec);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectanglePro);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleGradientV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleGradientH);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleGradientEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleLinesEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleRounded);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRectangleRoundedLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTriangle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTriangleLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTriangleFan);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawPoly);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetShapesTexture);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionRecs);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionCircles);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionCircleRec);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetCollisionRec);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionPointRec);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionPointCircle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionPointTriangle);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadImage);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadImageEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadImagePro);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadImageRaw);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ExportImage);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ExportImageAsCode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadTextureFromImage);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadTextureCubemap);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadRenderTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadImage);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadRenderTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetImageData);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetImageDataNormalized);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetPixelDataSize);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTextureData);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetScreenData);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateTexture);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageCopy);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageToPOT);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageFormat);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageAlphaMask);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageAlphaClear);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageAlphaCrop);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageAlphaPremultiply);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageCrop);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageResize);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageResizeNN);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageResizeCanvas);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageMipmaps);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageDither);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageExtractPalette);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageText);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageTextEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageDraw);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageDrawRectangle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageDrawRectangleLines);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageDrawText);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageDrawTextEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageFlipVertical);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageFlipHorizontal);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageRotateCW);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageRotateCCW);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageColorTint);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageColorInvert);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageColorGrayscale);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageColorContrast);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageColorBrightness);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ImageColorReplace);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageColor);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageGradientV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageGradientH);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageGradientRadial);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageChecked);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageWhiteNoise);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImagePerlinNoise);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageCellular);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenTextureMipmaps);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetTextureFilter);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetTextureWrap);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextureV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextureEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextureRec);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextureQuad);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTexturePro);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextureNPatch);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetFontDefault);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadFont);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadFontEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadFontFromImage);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadFontData);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenImageFontAtlas);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadFont);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawFPS);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawText);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextRec);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawTextRecEx);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(MeasureText);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(MeasureTextEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetGlyphIndex);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetNextCodepoint);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextIsEqual);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextLength);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextCountCodepoints);
  // TODO: Add TextFormat
  //RAYLIB_LUA_SOL2_ADD_FUNCTION(TextFormat);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextSubtext);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextReplace);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextInsert);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextJoin);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextSplit);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextAppend);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextFindIndex);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextToUpper);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextToLower);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextToPascal);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(TextToInteger);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawLine3D);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCircle3D);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCube);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCubeV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCubeWires);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCubeWiresV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCubeTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawSphere);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawSphereEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawSphereWires);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCylinder);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawCylinderWires);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawPlane);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawRay);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawGrid);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawGizmo);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadModel);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadModelFromMesh);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadModel);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadMeshes);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ExportMesh);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadMesh);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadMaterials);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadMaterialDefault);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadMaterial);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMaterialTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetModelMeshMaterial);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadModelAnimations);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateModelAnimation);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadModelAnimation);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsModelAnimationValid);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshPoly);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshPlane);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshCube);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshSphere);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshHemiSphere);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshCylinder);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshTorus);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshKnot);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshHeightmap);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenMeshCubicmap);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(MeshBoundingBox);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(MeshTangents);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(MeshBinormals);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawModel);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawModelEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawModelWires);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawModelWiresEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawBoundingBox);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawBillboard);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(DrawBillboardRec);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionSpheres);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionBoxes);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionBoxSphere);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionRaySphere);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionRaySphereEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CheckCollisionRayBox);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetCollisionRayModel);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetCollisionRayTriangle);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetCollisionRayGround);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadText);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadShader);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadShaderCode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadShader);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetShaderDefault);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetTextureDefault);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetShaderLocation);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetShaderValue);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetShaderValueV);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetShaderValueMatrix);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetShaderValueTexture);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMatrixProjection);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMatrixModelview);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMatrixModelview);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenTextureCubemap);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenTextureIrradiance);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenTexturePrefilter);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GenTextureBRDF);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginShaderMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndShaderMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginBlendMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndBlendMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginScissorMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndScissorMode);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(InitVrSimulator);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CloseVrSimulator);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateVrTracking);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetVrConfiguration);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsVrSimulatorReady);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ToggleVrMode);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(BeginVrDrawing);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(EndVrDrawing);


  RAYLIB_LUA_SOL2_ADD_FUNCTION(InitAudioDevice);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CloseAudioDevice);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsAudioDeviceReady);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMasterVolume);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadWave);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadWaveEx);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadSound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadSoundFromWave);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateSound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadWave);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadSound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ExportWave);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ExportWaveAsCode);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(PlaySound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(PauseSound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ResumeSound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(StopSound);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsSoundPlaying);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetSoundVolume);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetSoundPitch);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(WaveFormat);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(WaveCopy);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(WaveCrop);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetWaveData);

  // TODO: Add LoadMusicStream
  //RAYLIB_LUA_SOL2_ADD_FUNCTION(LoadMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UnloadMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(PlayMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(StopMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(PauseMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ResumeMusicStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsMusicPlaying);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMusicVolume);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMusicPitch);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetMusicLoopCount);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMusicTimeLength);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(GetMusicTimePlayed);

  RAYLIB_LUA_SOL2_ADD_FUNCTION(InitAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(UpdateAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(CloseAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsAudioBufferProcessed);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(PlayAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(PauseAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(ResumeAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(IsAudioStreamPlaying);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(StopAudioStream);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetAudioStreamVolume);
  RAYLIB_LUA_SOL2_ADD_FUNCTION(SetAudioStreamPitch);
}

void raylib_lua_sol2(sol::state &lua) {
	raylib_lua_sol2_color(lua);
	raylib_lua_sol2_structs(lua);
	raylib_lua_sol2_enums(lua);
  raylib_lua_sol2_functions(lua);
}

#endif // RAYLIB_LUA_SOL2_

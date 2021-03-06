-------------------------------------------------------------------------------------------
--
--  raylib [textures] example - Retrieve image data from texture: GetTextureData()
--
--  NOTE: Images are loaded in CPU memory (RAM) textures are loaded in GPU memory (VRAM)
--
--  This example has been created using raylib 1.6 (www.raylib.com)
--  raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
--
--  Copyright (c) 2014-2016 Ramon Santamaria (@raysan5)
--
-------------------------------------------------------------------------------------------

-- Initialization
-------------------------------------------------------------------------------------------
local screenWidth = 800
local screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - texture to image")

-- NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

local image = LoadImage("resources/raylib_logo.png")  -- Load image data into CPU memory (RAM)
local texture = LoadTextureFromImage(image)           -- Image converted to texture, GPU memory (RAM -> VRAM)
UnloadImage(image)                                    -- Unload image data from CPU memory (RAM)

image = GetTextureData(texture)                       -- Retrieve image data from GPU memory (VRAM -> RAM)
UnloadTexture(texture)                                -- Unload texture from GPU memory (VRAM)

texture = LoadTextureFromImage(image)                 -- Recreate texture from retrieved image data (RAM -> VRAM)
UnloadImage(image)                                    -- Unload retrieved image data from CPU memory (RAM)
-------------------------------------------------------------------------------------------

-- Main game loop
while not WindowShouldClose() do            -- Detect window close button or ESC key
    -- Update
    ---------------------------------------------------------------------------------------
    -- TODO: Update your variables here
    ---------------------------------------------------------------------------------------

    -- Draw
    ---------------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE)

        DrawText("this IS a texture loaded from an image!", 300, 370, 10, GRAY)

    EndDrawing()
    ---------------------------------------------------------------------------------------
end

-- De-Initialization
-------------------------------------------------------------------------------------------
UnloadTexture(texture)       -- Texture unloading

CloseWindow()                -- Close window and OpenGL context
-------------------------------------------------------------------------------------------

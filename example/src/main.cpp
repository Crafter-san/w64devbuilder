#include "raylib.h"
#include <iostream>
#include "gui.hpp"
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920*0.75; // 1440
    const int screenHeight = 1080*0.75; // 810

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");

    Shape rect_a = {
        .xa = 200,
        .ya = 200,
        .width = 200,
        .height = 200,
        .color = {
            .r = 200,
            .g = 0,
            .b = 20,
            .a = 255
        }
    };

    Shape title_line = {
        .xa = 18,
        .ya = 42,
        .xb = screenWidth - 18,
        .yb = 42
    };
    Shape circle = {
        .xa = 300,
        .ya = 300,
        .radius = 100,
        .color = {
            .r = 200,
            .g = 0,
            .b = 20,
            .a = 255
        }
    };
    Shape middle_line = {
        .xa = 300,
        .ya = 300,
        .xb = 400,
        .yb = 400
    };
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        


        //----------------------------------------------------------------------------------
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Simple Game", 20, 20, 20, DARKGRAY);
            DrawRectangle(100, 100, 200, 200, BLACK);
            //rect_a.lRect(rect_a.color);
            circle.ellipse(circle.color);
            title_line.line(title_line.color);
            middle_line.line(middle_line.color);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

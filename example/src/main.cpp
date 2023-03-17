#include "raylib.h"
#include <iostream>
struct TwoPoint {
    int xa = 0;
    int ya = 0;
    int xb = 0;
    int yb = 0;
    Color color = {
        .r = 0,
        .g = 0,
        .b = 0,
        .a = 255
    };
    void rect(Color col) {
        DrawRectangle(xa, ya, xb, yb, col);
    };
    void rect() {
        DrawRectangle(xa, ya, xb, yb, color);
    };
    void line(Color col) {
        DrawLine(xa, ya, xb, yb, col);
    };
    void line() {
        DrawLine(xa, ya, xb, yb, color);
    };
    void lRect(Color col) {
        DrawRectangleLines(xa, ya, xb, yb, col);
    };
    void lRect() {
        DrawRectangleLines(xa, ya, xb, yb, BLACK);
    };
    using execute_fp = void (*)();
    execute_fp onclick;
};
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920*0.75; // 1440
    const int screenHeight = 1080*0.75; // 810

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");

    TwoPoint rect_a = {
        .xa = 200,
        .ya = 200,
        .xb = 400,
        .yb = 400,
        .color = {
            .r = 150,
            .g = 0,
            .b = 20,
            .a = 255
        }
    };

    TwoPoint title_line{
        .xa = 18,
        .ya = 42,
        .xb = screenWidth - 18,
        .yb = 42
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
            rect_a.lRect();
            rect_a.rect();
            title_line.line();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
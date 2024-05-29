#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include <raylib.h>
#include <raymath.h>

#include "nob.h"

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080

#define FPS 120
#define PHYSICS_FPS 62

#define WINDOW_FLAGS FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED

#define FIXED_UPDATE
int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
    SetWindowState(WINDOW_FLAGS);

    SetTargetFPS(0);

    float accumulator = 0.0f;
    float current_time = GetTime();
    const float fixed_update_time = 1.0f / (float)PHYSICS_FPS;

    while (!WindowShouldClose()) {
        float new_time = GetTime();
        float frame_time = new_time - current_time;
        current_time = new_time;
        accumulator += frame_time;
        while (accumulator >= fixed_update_time)
        {
            //Fixed update loop

            accumulator -= fixed_update_time;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

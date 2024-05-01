#include "body.h"
#include "mathf.h"
#include "raylib.h"
#include "raymath.h"
#include "world.h"

#include <stdlib.h>
#include <assert.h>

#define MAX_BODIES 10

int main(void)
{
	InitWindow(1280, 720, "Physics Engine");
	SetTargetFPS(120);

	////Body* bodies = new Body[20];
	//Body* bodies = (Body*)malloc(sizeof(Body) * MAX_BODIES);
	//assert(bodies);


	//int bodyCount = 0;

	//game loop
	while (!WindowShouldClose())
	{
		////update
		float dt = GetFrameTime();
		float fps = (float)GetFPS();

		Vector2 position = GetMousePosition();
		//if (IsMouseButtonDown(0)) {
		//	bodies[bodyCount].position = position;
		//	bodies[bodyCount].velocity = CreateVector2(GetRandomFloatValue(-5, 5), GetRandomFloatValue(-5, 5));
		//	bodyCount++;
		//}

		////render/draw (render is just a fancy word for draw)
		//BeginDrawing();
		//ClearBackground(BLACK);
		////stats
		//DrawText(TextFormat("FPS: %.2f (ms %.2fms)", fps, 1000 / fps), 10, 10, 20, LIME);
		//DrawText(TextFormat("FRAME: %.4f", dt), 10, 30, 20, LIME);

		//DrawCircle((int)position.x, (int)position.y, 20, DARKGREEN);
		//for (int i = 0; i < bodyCount; i++) {
		//	bodies[i].position = Vector2Add(bodies[i].position, bodies[i].velocity);
		//	DrawCircle((int)bodies[i].position.x, (int)bodies[i].position.y, 10, RED);
		//}

		//EndDrawing();

		/*
		* The code in main() should only use the CreateBody when the mouse is clicked and the bodies list when updating and drawing them.
		* Because the bodies are in a linked list instead of an array (next to each other in memory),
		* they will need to be updated/drawn in a different type of loop than the for loop in class. They will require a while loop.
		*/

		if (IsMouseButtonDown(0))
		{
			Body* body = CreateBody();
			body->position = position;
			body->velocity = CreateVector2(GetRandomFloatValue(-5, 5), GetRandomFloatValue(-5, 5));
		};

		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle((int)position.x, (int)position.y, 20, DARKGREEN);
		DrawText(TextFormat("FPS: %.2f (ms %.2fms)", fps, 1000 / fps), 10, 10, 20, LIME);

		DrawText(TextFormat("FRAME: %.4f", dt), 10, 30, 20, LIME);
		// update / draw bodies
		Body* body = bodies;
		while (body) // do while we have a valid pointer, will be NULL at the end of the list
		{
			// update body position
			// draw body
			body->position = Vector2Add(body->position, body->velocity);
			DrawCircle((int)body->position.x, (int)body->position.y, 10, RED);

			body = body->next; // get next body
		}

		EndDrawing();
	}


	CloseWindow();
	free(bodies); //free the memory (clean up after yourself!) In C++ this would be delete[] bodies;
	return 0;
}
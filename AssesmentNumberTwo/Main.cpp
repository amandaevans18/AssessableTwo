/*At the bare minimum, your game project should make use of or incorporate the following elements:

rendering capabilities (likely by leveraging a third-party library)
a graphical user interface (GUI buttons, text, etc.)
use of assets from disk (sounds, images, file I/O)
input-checking and response
Since this is the second assessment project, we are primarily looking for growth in your programming abilities. 
While you were permitted to write the most egregious code for your first assessment, we expect you to have learned and developed strategies for solving problems with programming.*/
#include"Game.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	//screen width
	int screenWidth = 800;
	// screen height
	int screenHeight = 450;


	//Controls the window size / makes the window
	InitWindow(screenWidth, screenHeight, "Dungeon");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	Game myGame;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
		BeginDrawing();
		myGame.go();
		EndDrawing();
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------
	return 0;
}
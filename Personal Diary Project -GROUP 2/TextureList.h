#include "texture.h"

texture modes[40];

//texture textureVariable;

void textureInit()
{
    modes[0].Create("HAPPY.bmp");
	modes[1].Create("OK.bmp");
	modes[2].Create("SAD.bmp");
	modes[3].Create("school.bmp");
	modes[4].Create("work.bmp");
	modes[5].Create("welcome.bmp");
	modes[6].Create("friends.bmp");
	modes[7].Create("hangout.bmp");
	modes[8].Create("welcome2.bmp");
	modes[9].Create("menu2.bmp");
	modes[10].Create("gaming.bmp");
	modes[11].Create("music.bmp");
	modes[12].Create("concert.bmp");
	modes[13].Create("football.bmp");
	modes[14].Create("cricket.bmp");
	modes[15].Create("jogging.bmp");
	modes[16].Create("travel.bmp");
	modes[17].Create("hiking.bmp");
	modes[18].Create("gardening.bmp");
	modes[19].Create("cooking.bmp");
	modes[20].Create("painting.bmp");
	modes[21].Create("photography.bmp");
	modes[22].Create("party.bmp");
	modes[23].Create("relax.bmp");
	modes[24].Create("beach.bmp");
	modes[25].Create("shopping.bmp");
	modes[26].Create("swimming.bmp");
	modes[27].Create("study.bmp");
	modes[28].Create("movies.bmp");
	modes[29].Create("writing.bmp");
	modes[30].Create("workout.bmp");
	modes[31].Create("experiment.bmp");
	modes[32].Create("help.bmp");
	modes[33].Create("goodbye.bmp");
	modes[34].Create("credit.bmp");
	modes[35].Create("delete.bmp");
	modes[36].Create("entrydate.bmp");
	modes[37].Create("login.bmp");
	modes[38].Create("activity.bmp");
	//textureVariable.Create("google.bmp");
}



/**
How to use texture image:

1. in TextureList.h: declare texture type variables as needed. For every image, you need to declare one texture type variable.

Example:

texture textureVariable;


2. in TextureList.h: in the function textureInit(): initialize the texture variable that you declared in step 1 with the name
of the image file.

Example: suppose you have an image file named: "google.bmp"
then, you initialize as follows:

textureVariable.Create("google.bmp");


3. in the main cpp file in iDraw function: use drawTexture function to draw the image. drawTexture takes three arguments.

-> first argument   : lower left x-coordinate of the image
-> second argument  : lower left y-coordinate of the image
-> third argument   : name of the textureVariable declared in step 1


Example:

drawTexture(100, 200, textureVariable);
**/

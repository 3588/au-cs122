#include "DarkGDK.h"

int begin1x=0;
int begin1y=175;
int begin2x=511;
int begin2y=175;
void setUp()
{
	::dbLoadSound("Hit metal.wav",1);
	::dbSetImageColorKey(0,255,0);
	::dbLoadImage("BowlingBall1.bmp",1);
	::dbLoadImage("BowlingBall2.bmp",2);
	::dbSprite(1,begin1x,begin1y,1);
	::dbSprite(2,begin2x,begin2y,2);
}
void moveBalls()
{
	int x1=::dbSpriteX(1)+10;
	int x2=::dbSpriteX(2)-10;
	::dbSprite(1,x1,begin1y,1);
	::dbSprite(2,x2,begin2y,2);
}
void detectCollision()
{
	if(::dbSpriteCollision(1,2))
	{
		::dbPlaySound(1);
		::dbSprite(1,begin1x,begin1y,1);
		::dbSprite(2,begin2x,begin2y,2);
	}
}
void DarkGDK()
{
	::dbSyncOn();
	::dbSyncRate(10);

	setUp();

	while(::LoopGDK())
	{
		moveBalls();
		detectCollision();

		::dbSync();
	}
	::dbWaitKey();
}
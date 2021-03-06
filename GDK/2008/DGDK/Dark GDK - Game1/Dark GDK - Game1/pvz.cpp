//=======================
//DarkGdk Program PVZ
//CS 122A Junjun Huang
//4/22/2011 v1.0
//4/24/2011 v2.0
//=======================
#include "DarkGDK.h"
//================================
//widith=800 Height=600
//dbSetWindowTitle = Plants vs Zombies
//load data
//================================
void game_initialize()
{
	dbSetDisplayMode(800,600,dbScreenDepth());
	dbSetWindowTitle("Plants vs Zombies");
	dbLoadMusic("sound\\ZombiesOnYourLawn.wav",1);
	dbLoadMusic("sound\\hugewave.wav",2);
	dbLoadMusic("sound\\KitanaiSekai.wav",3);

	dbLoadBitmap("image\\start_1.jpg",1);
	dbLoadBitmap("image\\start_2.jpg",2);
	dbLoadBitmap("image\\start_3.jpg",3);

	dbLoadImage("image\\options_menuback.jpg",1);
	dbLoadImage("image\\PvZ_Logo.jpg",2);
	dbLoadImage("image\\welcome_back.jpg",3);
	dbLoadImage("image\\background1.jpg",4);
	


}
//================================
//Paly sound when started the game
//ZombiesOnYourLawn.mp3
//================================
void game_started()
{	
		dbPlayMusic(1);		
			for(int i=1;i<=3;i++)
			{
				dbCopyBitmap(i,0);
				dbWait(1000);
				dbDeleteBitmap(i);
			}		
		
		dbWaitKey();
		dbStopMusic(1);
		dbCLS();
}
//================================
//Ask use enter name
//global char* name
//================================
char* name="junjun";
void game_EnterName()
{	
	dbLoadBitmap("image\\1.jpg");
	dbWait(1000);
	dbCLS();
	dbPasteImage(1,188.5,0,0);
	dbDeleteImage(1);
	dbPasteImage(2,50,484,0);
	dbDeleteImage(2);
	dbPositionMouse(309,432);
	dbSetCursor(309,432);
	dbSetTextSize(25);
	dbSetTextFont("Algerian");
	name=dbInput();
	dbPlayMusic(2);
	dbPasteImage(3,268.5,130,0);
	dbDeleteImage(3);
	double t_x=dbTextWidth(name);
	t_x= 380-t_x/2;
	dbSetCursor(t_x,190);
	dbSetTextSize(30);
	dbPrint(name);
	dbWait(1000);
	dbSetTextFont("");//cleaning font
	
}
//=================
//game over
//=================
void game_over()
{
	dbCLS();
	dbLoadImage("image\\ZombiesWon_.png",90);
	dbLoadImage("image\\ZombiesWon.jpg",91);
	double xx1=dbScreenWidth(),yy1=dbScreenHeight();
	xx1=xx1/2;
	yy1=yy1/2;
	xx1=xx1-564/2;
	yy1=yy1-468/2;
	dbPasteImage(90,xx1,yy1,0);
	dbWait(1000);
	dbPasteImage(91,xx1,yy1,0/1);
	dbWaitKey();
	exit(1);


}
//================================
//load the game
//for myself
//image 1400*600
//================================
void game_load_1()
{
	dbPlayMusic(3);
	//=============================
	//choose the load image
	//zombie has different location 
	//=============================
	dbLoadImage("image\\background1.png",1);
	dbLoadImage("image\\background2.png",2);
	dbLoadImage("image\\background3.png",3);
	dbRandomize(dbTimer());
	int paste_image = dbRND(2)+1;
	dbPasteImage(paste_image,0,0,0);
	dbSetTextSize(25);
	dbSetCursor(300,500);
	dbPrint(name);
	dbSetCursor(300+dbTextWidth(name),500);
	dbPrint("'s home");
	dbWait(1000);
	int t_1=0;
	while(t_1>-600)
	{
		dbCLS();
		dbPasteImage(paste_image,t_1,0,0);
		dbWait(10);
		t_1--;

	}
	while(t_1<0)
	{
		dbCLS();
		dbPasteImage(paste_image,t_1,0,0);
		dbWait(10);
		t_1++;

	}
	dbDeleteImage(1);
	dbDeleteImage(2);
	dbDeleteImage(3);
	dbWait(1000);
	

}

//================================
//load the game 2
//ready to play
//================================
double money = 500;
void game_load_2()
{
	
		dbSetDisplayMode(1000,600,dbScreenDepth());
		dbLoadBitmap("image\\background1.jpg");
		dbLoadBitmap("image\\SeedBank.png");
		dbWait(200);
		dbLoadImage("image\\SeedBank1.png",1);
		dbLoadImage("image\\SeedBank2.png",2);
		dbLoadImage("image\\SeedBank3.png",3);
		dbPasteImage(1,0,0,0);
		dbWait(200);
		dbPasteImage(2,0,0,0);
		dbWait(200);
		dbPasteImage(3,0,0,0);
		dbWait(200);
		dbSetCursor(23,63);
		dbSetTextToBold();
		dbSetTextSize(20);
		dbPrint(money);
		dbWait(200);
	
}
//=================
//move the zombie
//=================
double zombiex, zombiey;
void game_zombie_move(double zmx1, double zmy1, double mx1)
{
	dbLoadBitmap("image\\background1.jpg");
	dbLoadImage("image\\Zombie_digger_head2.png",20);
	if(mx1==0)
	{
dbSprite(1,zmx1,zmy1,20);
zombiex = dbSpriteX(1);
zombiey = dbSpriteY(1);
	}
	else
	{
	    

	    dbOffsetSprite(1,mx1+20,0);
		zombiex = dbSpriteX(1);
		zombiey = dbSpriteY(1);
		dbWait(10);
		money--;
dbSetSpritePriority(1,99);
dbSetSpritePriority(4,98);
dbSetSpritePriority(3,2);
dbSetSpritePriority(2,1);
		
 		dbLoadImage("image\\background1.jpg",30);
		dbLoadImage("image\\SeedBank3.png",31);
 		dbLoadImage("image\\SeedBank0.png",32);
 		dbSprite(2,0,0,30);
 		dbSprite(3,0,0,31);
 		dbSprite(4,0,0,32);
	
	}	 
}
//===========
//check if lost
//check zombiex did
//===========
double p_or_z_did = 0;// 1 zombiex did
void check_p_z(double mouse_x, double mouse_y)
{
	
	dbPrint(zombiex);
	dbPrint(zombiey);
	if (zombiex<=250)//lost
	{
		game_over();
	} 
	else if (zombiex==mouse_x+99/2)
	{
		game_over();
		p_or_z_did=1;
	}else if (zombiex>mouse_x)
	{
		//nothink
	}
	
}
bool mouseFullClick(int &x, int &y)
{
	
	bool buttonClick = false;

	if ( dbMouseClick() == 1 )
	{
		// 获得鼠标指针的坐标
		x = dbMouseX();
		y = dbMouseY();

		
		while ( dbMouseClick() == 1)
		{
			
		}

		
		buttonClick = true;
	}
	return buttonClick;
}

void DarkGDK()
{

game_initialize();
game_started();
 game_EnterName();
 game_load_1();
 game_load_2();

double move_x=0;
int back_x=9999, back_y=9999;

int x;
int y;
dbLoadImage("image\\Tallnut_body.png",80);

while (LoopGDK())
{

	game_zombie_move(980,290,move_x);
	
		
	if(mouseFullClick(x,y))
	{
		back_x=x;
		back_y=y;
		dbSprite(20,x-99/2,y-146/2,80);
		dbSetSpritePriority(20,100);
		dbWait(100);
	}
	check_p_z(back_x, back_y);
	move_x=move_x+1;
}

	

dbPrint("test");
dbPrint(name);
dbWaitKey();
}
#include "DarkGDK.h"
//单个僵尸移动
void game_zombie_move(double& after_move_x, double& after_move_y, int start_move_x)
{
	dbLoadImage("image\\background1.jpg",30);
	dbLoadImage("image\\SeedBank3.png",31);
	dbLoadImage("image\\SeedBank0.png",32);
	dbSprite(2,0,0,30);
	dbLoadImage("image\\Zombie_digger_head2.png",20);

	if(start_move_x==0)
	{
		dbSprite(1,after_move_x,after_move_y,20);
		dbSetSpritePriority(1,99);
	}
	else
	{

		dbSprite(1,after_move_x-10,after_move_y,20);
		dbSetSpritePriority(1,99);
		after_move_x = dbSpriteX(1);
		after_move_y = dbSpriteY(1);
		
		dbSprite(2,0,0,30);
		dbSprite(3,0,0,31);
		dbSprite(4,0,0,32);

	}	 
}
//鼠标判断
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
//设置障碍
void game_plant_move(double& after_move_x, double& after_move_y)
{
	dbLoadImage("image\\Tallnut_body.png",80);
	int x,y;
	if(mouseFullClick(x,y))
	{
		after_move_x=x;
		after_move_y=y;
		dbSprite(20,x-99/2,y-146/2,80);
		dbSetSpritePriority(20,99);
		dbWait(100);
	}
}
//检查是否重叠
void check_p_v_z(double px,double py,double zx, double zy)
{
	if(px>zx)
	{
		
	}
	else
	{
		if(zx<=250)//lost
		{
			exit(1);
		}
		else
		{
			//nothing
		}
	}
}
void DarkGDK()
{
	//for test
	dbSetDisplayMode(1000,600,dbScreenDepth());

	double after_move_x=980, after_move_y=290;
	double p_after_move_x=0, p_after_move_y=0;
	int tempx=0;
	
	while (LoopGDK())
	{
		game_zombie_move(after_move_x,after_move_y,tempx);
		tempx++;
		game_plant_move(p_after_move_x,p_after_move_y);
		dbWait(10);
	
		
	}

}
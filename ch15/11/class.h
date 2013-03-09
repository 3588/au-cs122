//================
//Ch15 Pro11 class 
//CS122 Junjun Huang
//4/21/2011 16:27 done & test
//================
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
//==========
//config 
//Initialize ant & doodlebug
//getType() 1=ant;2=doodlebug
//==========
const int Initialize_ANT = 5;
const int Initialize_DOODLEBUG = 100;
const int ANT = 1;
const int DOODLEBUG = 2;
//================
//hint code
//================
class World
{
	friend class Organism;			// Allow Organism to access grid
	friend class Doodlebug;			// Allow Organism to access grid
	friend class Ant;			// Allow Organism to access grid
public:
	World();
	~World();
	Organism* getAt(int x, int y);
	void setAt(int x, int y, Organism *org);
	void Display();
	void SimulateOneStep();
private:
	Organism* grid[20][20];
};
class Organism
{
	friend class World;			// Allow world to affect organism
public:
	Organism();
	Organism(World *world, int x, int y);
	~Organism();
	virtual void breed() = 0;	// Whether or not to breed
	virtual void move() = 0;	// Rules to move the critter
	virtual int getType() =0;	// Return if ant or doodlebug
	virtual bool starve() = 0;	// Determine if organism starves
protected:
	int x,y;			// Position in the world
	bool moved;			// Bool to indicate if moved this turn
	int breedTicks;			// Number of ticks since breeding
	World *world;
};
class Ant : public Organism
{
	friend class World;
public:
	Ant();
	Ant(World *world, int x, int y);
	void breed();	// Must define this since virtual
	void move();	// Must define this since virtual
	int getType();	// Must define this since virtual
	bool starve()   // Return 0, ant never starves
	{ return false; }
};
class Doodlebug : public Organism
{
	friend class World;
public:
	Doodlebug();
	Doodlebug(World *world, int x, int y);
	void breed();	// Must define this since virtual
	void move();	// Must define this since virtual
	int getType();	// Must define this since virtual
	bool starve();	// Check if a doodlebug starves to death
private:
	int starveTicks;	// Number of moves before starving
};
//================
//hint code end
//================
//******************************************************************
//================
//World Class Definitions
//================
World::World()
{
	//build 20*20
	int i,j;
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		{
			grid[i][j]=NULL;
		}
	}
}
World::~World()
{
	int i,j;
	for (i=0; i<20; i++)
	{
		for (j=0; j<20; j++)
		{
			if (grid[i][j]!=NULL) delete (grid[i][j]);
		}
	}
}
Organism* World::getAt(int x, int y)
{
	if (x>=20||y>=20)
	{
		return NULL;
	}
	if (x<0||y<0)
	{
		return NULL;
	}
	return grid[x][y];
}
void World::setAt(int x, int y, Organism *org)
{
	int check=1;
	if (x>=20||y>=20)
	{
		check=0;
	}
	if (x<0||y<0)
	{
		check=0;
	}
	if (check)
	{grid[x][y] = org;}
		

}
void World::Display()
{
	for (int j=0; j<20; j++)
	{
		for (int i=0; i<20; i++)
		{
			if (grid[i][j]==NULL)
			{cout << ".";}
			else 
			{
				if(grid[i][j]->getType()== ANT)
			       {cout << "o";}
			    else 
			       {cout << "X";}
			}
		}
		cout <<"\n";
	}
}
//***************************
//===========================
//for myself
//模拟一步
//ant 3 time step 活, 多一个 ant time step重新计算
//doodlebug 8 time step 活, 多一个 doodlebug time step重新计算
//ant 随机 上 下 左 右
//ant 目标 占据了 不懂| 在网格内
//doodlebug 上下左右 有 ant. del move
//doodlebug 和 ant 一样 if 没有ant. doodlebug can't del|move doodlebug
//===========================
//***************************
void World::SimulateOneStep()
{

	for (int i=0; i<20; i++)
		for (int j=0; j<20; j++)
		{
			if (grid[i][j]!=NULL)
			{
				grid[i][j]->moved = 0;
			}
		}
	for (int i=0; i<20; i++)
		for (int j=0; j<20; j++)
		{
			if ((grid[i][j]!=NULL) && (grid[i][j]->getType()==ANT))
			{
				if (grid[i][j]->moved == 0)
				{
					grid[i][j]->moved = 1;
					grid[i][j]->move();
				}
			}
		}
	for (int i=0; i<20; i++)
		for (int j=0; j<20; j++)
		{
			if ((grid[i][j]!=NULL) && (grid[i][j]->getType()==DOODLEBUG))
		{
			if (grid[i][j]->moved == 0)
				{
					grid[i][j]->moved = 1;
					grid[i][j]->move();
				}
		}
			}
	for (int i=0; i<20; i++)
		for (int j=0; j<20; j++)
			{
				if ((grid[i][j]!=NULL) && (grid[i][j]->getType()==DOODLEBUG))
					{
					if (grid[i][j]->starve())
						{
							delete (grid[i][j]);
							grid[i][j] = NULL;
						}
					}
			}
	for (int i=0; i<20; i++)
		for (int j=0; j<20; j++)
			{
				if ((grid[i][j]!=NULL) && (grid[i][j]->moved==1))
							{
								grid[i][j]->breed();
							}
			}
}
//================
//Organism Class Definitions
//================
Organism::Organism()
{
	x=0;
	y=0;
	moved = 0;
	breedTicks = 0;
	world = NULL;
}
Organism::Organism(World *world, int x, int y)
{
	this->world = world;
	this->x=x;
	this->y=y;
	moved = 0;
	breedTicks = 0;
	world->setAt(x,y,this);
}
Organism::~Organism()
{}
//================
//Ant Class Definitions
//add Organism()
//================
Ant::Ant() : Organism()
{}
Ant::Ant(World *world, int x, int y) : Organism(world,x,y)
{}
void Ant::move()
{
	
	int rang1 = rand() % 4;
	if (rang1==0)//up
	{
		if ((x<19) && (world->getAt(x+1,y)==NULL))
		{
			world->setAt(x+1,y,world->getAt(x,y)); 
			world->setAt(x,y,NULL);
			x++;
		}
	}

	if (rang1==1)//down
	{
		if ((y>0) && (world->getAt(x,y-1)==NULL))
		{
			world->setAt(x,y-1,world->getAt(x,y));
			world->setAt(x,y,NULL);
			y--;
		}
		
	}
	 if (rang1==2)//l
	{
		if ((y<19) && (world->getAt(x,y+1)==NULL))
		{
			world->setAt(x,y+1,world->getAt(x,y));
			world->setAt(x,y,NULL);
			y++;
		}
		
	}

	if (rang1==3)//r
	{
		if ((x>0) && (world->getAt(x-1,y)==NULL))
		{
			world->setAt(x-1,y,world->getAt(x,y)); 
			world->setAt(x,y,NULL);
			x--;
		}
	}
}
int Ant::getType()
{
	return ANT;
}
void Ant::breed()
{
	breedTicks++;
	if (breedTicks == 3)
	{	
		if ((x<19) && (world->getAt(x+1,y)==NULL))
		{
			Ant *newAnt = new Ant(world, x+1, y);
		}else if ((y<19) && (world->getAt(x,y+1)==NULL))
		{
			Ant *newAnt = new Ant(world, x, y+1);
		}else if ((x>0) && (world->getAt(x-1,y)==NULL))
		{
			Ant *newAnt = new Ant(world, x-1, y);
		}else if ((y>0) && (world->getAt(x,y-1)==NULL))
		{
			Ant *newAnt = new Ant(world, x, y-1);
		}		 
	breedTicks = 0;
	}
}
//================
//Doodlebug Class Definitions
//add Organism()
//================
Doodlebug::Doodlebug() : Organism()
{
	starveTicks = 0;
}
Doodlebug::Doodlebug(World *world, int x, int y) : Organism(world,x,y)
{
	starveTicks = 0;
}
void Doodlebug::move()
{
	if((x<19) && (world->getAt(x+1,y)!=NULL)&&(world->getAt(x+1,y)->getType() == ANT))
	{
		delete (world->grid[x+1][y]);  
		world->grid[x+1][y] = this;    
		world->setAt(x,y,NULL);
		starveTicks =0 ;	  	
		x++;
		return;
	}else if ((y<19) && (world->getAt(x,y+1)!=NULL) &&
		(world->getAt(x,y+1)->getType() == ANT))
	{
		delete (world->grid[x][y+1]); 
		world->grid[x][y+1] = this;
		world->setAt(x,y,NULL);
		starveTicks =0 ;
		y++;
		return;
	}else if ((x>0) && (world->getAt(x-1,y)!=NULL) &&
		(world->getAt(x-1,y)->getType() == ANT))
	{
		delete (world->grid[x-1][y]);
		world->grid[x-1][y] = this;
		world->setAt(x,y,NULL);
		starveTicks =0 ;
		x--;
		return;
	}else if ((y>0) && (world->getAt(x,y-1)!=NULL)&&(world->getAt(x,y-1)->getType() == ANT))
	{
		delete (world->grid[x][y-1]);  
		world->grid[x][y-1] = this;    
		world->setAt(x,y,NULL);
		starveTicks =0 ;
		y--;
		return;
	}
int rang1 = rand() % 4;
	if (rang1==0)
	{
		if ((x<19) && (world->getAt(x+1,y)==NULL))
		{
			world->setAt(x+1,y,world->getAt(x,y));
			world->setAt(x,y,NULL);
			x++;
		}
		
	}
	if (rang1==1)
	{
		if ((y<19) && (world->getAt(x,y+1)==NULL))
		{
			world->setAt(x,y+1,world->getAt(x,y));
			world->setAt(x,y,NULL); 
			y++;
		}
	}
	if (rang1==2)
	{
		if ((x>0) && (world->getAt(x-1,y)==NULL))
		{
			world->setAt(x-1,y,world->getAt(x,y));  // Move to new spot
			world->setAt(x,y,NULL);  // Set current spot to empty
			x--;
		}
	}
	if(rang1==3)
	{
		if ((y>0) && (world->getAt(x,y-1)==NULL))
		{
			world->setAt(x,y-1,world->getAt(x,y));
			world->setAt(x,y,NULL);
			y--;
		}
	}
	starveTicks++;
}
int Doodlebug::getType()
{
	return DOODLEBUG;
}
void Doodlebug::breed()
{
	breedTicks++;
	if (breedTicks == 8)
	{
		if ((x<19) && (world->getAt(x+1,y)==NULL))
		{
			Doodlebug *newDoodle = new Doodlebug(world, x+1, y);
		}else if ((y<19) && (world->getAt(x,y+1)==NULL))
		{
			Doodlebug *newDoodle = new Doodlebug(world, x, y+1);
		}else if ((x>0) && (world->getAt(x-1,y)==NULL))
		{
			Doodlebug *newDoodle = new Doodlebug(world, x-1, y);
		}else if ((y>0) && (world->getAt(x,y-1)==NULL))
		{
			Doodlebug *newDoodle = new Doodlebug(world, x, y-1);
		}		
		breedTicks = 0; 
	}
}
bool Doodlebug::starve()
{
	if (starveTicks > 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//***************************
//class end
//***************************
#endif CLASS_H
/*
 * primo.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: Davidelocal
 */

#include<iostream>
#include<stdio.h>
#include<conio.h>

#define KEY_UP 77
#define KEY_DOWN 75
#define KEY_LEFT 72
#define KEY_RIGHT 80
# define len 20
# define hei 20
//using namespace std;

class coso
{
private:
	int x,y;
public:
	float x_position()
	{
		return x;
	}
	float y_position()
	{
		return y;
	}
	void initial_cond()
	{
		float x1,y1;
		std::cout<<"Insert the initial x position..."<<std::endl;
		std::cin>>x1;
		std::cout<<"Insert the initial y position..."<<std::endl;
		std::cin>>y1;
		x=x1;
		y=y1;
	}
	void control()
	{
		int c;
		if (_getch() == 224) {// if
		switch((_getch()))
		{
		case KEY_UP:
			y=y+1;
			break;
		case KEY_DOWN:
			y=y-1;
			break;
		case KEY_LEFT:
			x=x-1;
			break;
		case KEY_RIGHT:
			x=x+1;
			break;
		default:
			break;
		}
		}
	}
	int die(int a){
		if(x==0 || x==len-1 || y==0 || y==hei-1){
			system("CLS");
			std::cout<<"You died"<<std::endl;
			return a+1;
		}
	}
};
class map{
private:
	char *m[hei][len];
public:
	void generate(){
		char m1[hei][len];
		int i, j;
		for(i=0;i<hei;i++)
		{
			for(j=0;j<len;j++)
			{
				if(j==0 || j==len-1 || i==0 || i==hei-1)
				{
					m[i][j]="X";
				}
				else{
					m[i][j]=" ";
				}

			}
		}
	}
	void show(){
		int i, j;
		for(i=0;i<hei;i++)
		{
			for(j=0;j<len;j++)
			{
					std::cout<<m[i][j];
			}
			std::cout<<std::endl;
		}
	}
	void clearup(int x, int y){
		m[x][y]=" ";
	}
	void populate(int x, int y){
		m[x][y]="O";
	}

};


int main()
{



	int i,iter=1000;
	coso thing;
	map m1;
	m1.generate();
	m1.show();
	thing.initial_cond();
	system("CLS");
	std::cout<<"The initial coordinates of thing are... x="<<thing.x_position()<<" and y="<<thing.y_position()<<std::endl;
	m1.populate(thing.x_position(),thing.y_position());
	m1.show();

	for(i=0;i<iter;i++)

	{   //
		m1.clearup(thing.x_position(),thing.y_position());
		thing.control();
		system("CLS");
		std::cout<<"The coordinates of thing are... x="<<thing.x_position()<<" and y="<<thing.y_position()<<std::endl;
		if(i=thing.die(iter)>iter){break;}
		m1.populate(thing.x_position(),thing.y_position());
		m1.show();
	}
	system("pause");
	return 0;

}



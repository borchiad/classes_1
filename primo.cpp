/*
 * primo.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: Davidelocal
 */

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<random>
#include<iomanip>
#include<time.h>
#include<vector>
#include<chrono>
#include<Windows.h>

#include "def_classes.h"
#include "snake.h"


void clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
//using namespace std;


int main()
{
	srand(time(NULL));
	coso thing; //This is snake
	thing.first();
	map m1; //this is its playground
	food fruit;

    int i,iter=1000;
    int var_len=1;
    int tim=0;

	int already_food=0;

	m1.generate();
	m1.show();

	thing.initial_cond();
	thing.snake(var_len);
	clearscreen();
	//std::cout<<"The initial coordinates of thing are... x="<<thing.x_position().front()<<" and y="<<thing.y_position().front()<<std::endl;
	//system("pause");
	m1.populate(thing.x_position(),thing.y_position());
	m1.show();
	//system("pause");
	//fruit.gen(thing.x_position(),thing.y_position());
	int some=rand()%4+1;
	while(1)

	{   //

		m1.cleanup(thing.x_position(),thing.y_position());

		some=thing.control(some);
		thing.move(some);
		thing.snake(var_len);
		clearscreen();

		if((i=thing.die(iter,i))>iter){break;}  //Checks if you are dead
		/*std::cout<<"The coordinates of thing are... x="<<thing.x_position().front()<
		 *
		 <" and y="<<thing.y_position().front()<<std::endl;*/
		bool gib_fruit=fruit.is_there_food();  //Is there food?
		if(gib_fruit==true)
		{
			if(already_food==0)
			{fruit.gen(thing.x_position(),thing.y_position());
			already_food=1;}
			m1.populate_foody(thing.x_position(),thing.y_position(),fruit.get_foodx(),fruit.get_foody());
		}
		else
		{m1.populate(thing.x_position(),thing.y_position());}
		if(gib_fruit==true)
		{already_food=thing.eating(fruit.get_foodx(),fruit.get_foody());}
		var_len=var_len+already_food;


		m1.show();
		Sleep(500);
	}
	system("pause");
	return 0;

}
//You should save the positions in an array of length == length snake!


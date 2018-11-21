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
    int i,iter=1000;
    int var_len=1;
	coso thing;
	map m1;
	m1.generate();
	m1.show();
	thing.initial_cond();
	thing.snake(var_len);
	clearscreen();
	std::cout<<"The initial coordinates of thing are... x="<<thing.x_position().front()<<" and y="<<thing.y_position().front()<<std::endl;
	m1.populate(thing.x_position(),thing.y_position());
	m1.show();

	bool some;
	while(1)

	{   //

		m1.cleanup(thing.x_position(),thing.y_position());
		if(var_len<10){
		var_len=var_len+1;}
		some=false;
		//auto now= std::chrono::steady_clock::now();
		//while((now+std::chrono::milliseconds(500))>std::chrono::steady_clock::now()){
		some=thing.control();
		thing.move();
		//break;}
		//if(some==false){
		//thing.move();
		//}
		thing.snake(var_len);
		clearscreen();
		std::cout<<"The coordinates of thing are... x="<<thing.x_position().front()<<" and y="<<thing.y_position().front()<<std::endl;
		if((i=thing.die(iter,i))>iter){break;}
		m1.populate(thing.x_position(),thing.y_position());
		m1.show();
	}
	system("pause");
	return 0;

}
//You should save the positions in an array of length == length snake!


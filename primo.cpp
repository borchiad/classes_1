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

#include "def_classes.h"
#include "snake.h"



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
	thing.snake(thing.x_position().front(),thing.y_position().front(),var_len);
	system("CLS");
	std::cout<<"The initial coordinates of thing are... x="<<thing.x_position().front()<<" and y="<<thing.y_position().front()<<std::endl;
	m1.populate(thing.x_position(),thing.y_position());
	m1.show();

	for(i=0;i<iter;i++)

	{   //
		//m1.clearup(thing.x_position().back(),thing.y_position().back());
		m1.generate();
		thing.control();
		if(var_len<10){
		var_len=var_len+1;}
		thing.snake(thing.x_position().front(),thing.y_position().front(),var_len);
		system("CLS");
		std::cout<<"The coordinates of thing are... x="<<thing.x_position().front()<<" and y="<<thing.y_position().front()<<std::endl;
		if((i=thing.die(iter,i))>iter){break;}
		m1.populate(thing.x_position(),thing.y_position());
		m1.show();
	}
	system("pause");
	return 0;

}
//You should save the positions in an array of length == length snake!


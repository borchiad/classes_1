/*
 * snake.h
 *
 *  Created on: 14 Nov 2018
 *      Author: Davidelocal
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include<iostream>
#include<vector>
#include<random>
#include<fstream>

#define KEY_UP 77
#define KEY_DOWN 75
#define KEY_LEFT 72
#define KEY_RIGHT 80
# define len 40
# define hei 25

class coso
{
private:
	std::vector<int> snakex;  //these vectors contain the coordinate of the snake
	std::vector<int> snakey;
	int x,y;
	int motion; //motion asumes the value of te last change of direction!
	int length,speed; //these ones are the number of segments of the snake and its speed.
public:
	std::vector<int> x_position()
	{
		return snakex;
	}
	std::vector<int> y_position()
	{
		return snakey;
	}
	void snake(int xcoo, int ycoo, int sn_len)
	{
		//this is actually the object snake. This function build the snake.
		//length=sn_len;
		//int sn[2][length];
		std::vector<int> sn_x;
		std::vector<int> sn_y;
		//snakex.insert(snakex.begin(),xcoo); //Adds an element at the head of the vector
		//snakey.insert(snakey.begin(),ycoo);
		snakex.erase(snakex.begin()+sn_len,snakex.end()); //Removes all the elements past the length.
		snakey.erase(snakey.begin()+sn_len,snakey.end());
	}
	void initial_cond()
	{
		float x1,y1;
		std::cout<<"Insert the initial x position..."<<std::endl;
		std::cin>>x1;
		std::cout<<"Insert the initial y position..."<<std::endl;
		std::cin>>y1;
		snakex.insert(snakex.begin(),x1);
		snakey.insert(snakey.begin(),y1);
	}
	void control()
	{
		int c;
		if (_getch() == 224) {// if
		switch((_getch()))
		{
		case KEY_UP:
			c=0;
			snakey.insert(snakey.begin(),snakey.front()+1);
			snakex.insert(snakex.begin(),snakex.front());
			break;
		case KEY_DOWN:
			c=1;
			snakey.insert(snakey.begin(),snakey.front()-1);
			snakex.insert(snakex.begin(),snakex.front());
			break;
		case KEY_LEFT:
			c=2;
			snakex.insert(snakex.begin(),snakex.front()-1);
			snakey.insert(snakey.begin(),snakey.front());
			break;
		case KEY_RIGHT:
			c=3;
			snakex.insert(snakex.begin(),snakex.front()+1);
			snakey.insert(snakey.begin(),snakey.front());
			break;
		default:
			break;
		}
		}
		motion=c;
	}
	int die(int a,int i){
		if(snakex.front()==0 || snakey.front()==len-1 || snakey.front()==0 || snakex.front()==hei-1){
			system("CLS");
			std::cout<<"You died"<<std::endl;
			return a+1;
		}
		else{
			return i;
		}
	}
	void eating(int x, int y)  //takes in input the position of a fruit
	{

	}
};



#endif /* SNAKE_H_ */

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
	int leng(){
		return length;
	}
	void first()
	{
		length=1;
	}
	void growth(int i)
	{
		length=i;
	}
	void snake(int len1)
	{
		//this is actually the object snake. This function build the snake.
		//length=sn_len;
		snakex.erase(snakex.begin()+len1,snakex.end()); //Removes all the elements past the length.
		snakey.erase(snakey.begin()+len1,snakey.end());
	}
	void initial_cond()
	{
		float x1,y1;
		x1=rand()%(hei-1) - 1;
		y1=rand()%(len-1) - 1;
		snakex.insert(snakex.begin(),x1);
		snakey.insert(snakey.begin(),y1);
	}
	int control(int a)
	{
		int c=a;
		if(kbhit()){
		if (_getch() == 224) {// if
		switch((_getch()))
		{
		case KEY_UP:
			c=0;
			break;
		case KEY_DOWN:
			c=1;
			break;
		case KEY_LEFT:
			c=2;
			break;
		case KEY_RIGHT:
			c=3;
			break;
		default:
			break;
		}
		}
		}
		//motion=c;
		//std::cout<<c<<std::endl;
		return c;
	}
	void move(int a){
		switch(a)
		{
		case 0:
			snakey.insert(snakey.begin(),snakey.front()+1);
			snakex.insert(snakex.begin(),snakex.front());
			break;
		case 1:
			snakey.insert(snakey.begin(),snakey.front()-1);
			snakex.insert(snakex.begin(),snakex.front());
			break;
		case 2:
			snakex.insert(snakex.begin(),snakex.front()-1);
			snakey.insert(snakey.begin(),snakey.front());
			break;
		case 3:
			snakex.insert(snakex.begin(),snakex.front()+1);
			snakey.insert(snakey.begin(),snakey.front());
			break;
		default:
			break;
		}
		}
	int die(int a,int i){
		if(snakex.front()==0 || snakey.front()==len-1 || snakey.front()==0 || snakex.front()==hei-1){
			system("CLS");
			std::cout<<"You died"<<std::endl;
			//system("pause");
			return a+1;
		}
		else{
			return i;
		}
	}
	int eating(int x, int y)  //takes in input the position of a fruit
	{
		if(snakex.front()==x && snakey.front()==y)
		{
			//growth();
			return 1;

		}
		else{return 0;}

	}
};



#endif /* SNAKE_H_ */

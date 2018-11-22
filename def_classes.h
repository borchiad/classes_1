/*
 * def_classes.h
 *
 *  Created on: 14 Nov 2018
 *      Author: Davidelocal
 */

#ifndef DEF_CLASSES_H_
#define DEF_CLASSES_H_

#include<iostream>
#include<vector>
#include<random>
#include<fstream>
#include<algorithm>
#include <io.h>
#include <fcntl.h>

#define KEY_UP 77
#define KEY_DOWN 75
#define KEY_LEFT 72
#define KEY_RIGHT 80
# define len 40
# define hei 25


class food{
private:
	int x,y;
public:
	void gen(std::vector<int> xv,std::vector<int> yv){
		int a=xv.front(),b=yv.front();
		while(std::find(xv.begin(), xv.end(), a) == xv.end())
		{a=rand()%(hei-1) + 1;}
		while(std::find(yv.begin(), yv.end(), b) == yv.end())
		{b=rand()%(len-1) + 1;}
		x=b;
		y=a;
		}
	int get_foodx(){
		return x;
	}
	int get_foody(){
		return y;
	}
	bool is_there_food(){
		int c=rand()%10+1;
		if(c%4==0)
		{return true;}
		else
		{return false;}
	}


};
class map{
private:
	char *m[hei][len];
public:
	void generate(){
		int i, j;
		for(i=0;i<hei;i++)
		{for(j=0;j<len;j++)
			{
				if(j==0 || j==len-1 || i==0 || i==hei-1)
				{m[i][j]="X";}
				else
				{m[i][j]=" ";}}}
	}
	void show(){
		int i, j;
		for(i=0;i<hei;i++)
		{for(j=0;j<len;j++)
			{
					std::cout<<m[i][j];
			}
			std::cout<<std::endl;}
	}
	void cleanup(std::vector<int> x,std::vector<int> y,int a, int b){
		int i=x.size(),j=0;
				for(j=0;j<i;j++)
				{
					if(j==0)
					{m[x.front()][y.front()]=" ";}
					else
					{m[x[j]][y[j]]=" ";}
				}
				m[a][b]=" ";
	}
	void populate(std::vector<int> x,std::vector<int> y, int a, int b){
		int i=x.size(),j=0;
		for(j=0;j<i;j++)
		{
			if(j==0)
			{m[x.front()][y.front()]="O";}
			else
			{m[x[j]][y[j]]="o";}
		}
		m[a][b]="M";
	}
};

/*class game
{

};*/



#endif /* DEF_CLASSES_H_ */

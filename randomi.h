/*
 *
 * randomi.h
 *
 *  Created on: 22 Nov 2018
 *      Author: Davidelocal
 */

#ifndef RANDOMI_H_
#define RANDOMI_H_

#include<random>
#include "params.h"

std::random_device rd;
// obtain a random number from hardware
std::mt19937 eng(rd()); // seed the generator

int generatorlen()
{
	std::uniform_int_distribution<int> distrl(1, len-2);
	return distrl(eng);

}

int generatorhei()
{
	std::uniform_int_distribution<int> distrh(1, hei-2);
	return distrh(eng);


}



#endif /* RANDOMI_H_ */

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
# define len 40
# define hei 25

int generatorlen()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distrl(1, len-1);
	return distrl(eng);

}

int generatorhei()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distrh(1, hei-1);
	return distrh(eng);


}



#endif /* RANDOMI_H_ */

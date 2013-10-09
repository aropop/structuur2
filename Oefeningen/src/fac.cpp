/*
 * fac.cpp
 *
 *  Created on: 4-okt.-2013
 *      Author: arno
 */

//vraag 6 les 2

#include "fac.h"


long fac(int n){
	long res = 1;
	while (n > 0){
		res = res * n;
		n = n - 1;
	}
	return res;
}



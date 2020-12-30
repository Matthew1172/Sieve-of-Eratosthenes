/*
 *
 * @author Matthew Pecko
 * 12/29/2020
 *
 * Seive of Eratosthenes in C
 *
 * Define MIN as 2, and MAX to be the upper bound
 * of the prime range (in decimal)
 *
 *
 * The number of bytes we will need can be found:
 * numberOfBytes = diff/32
 * trueNumber = floor(numberOfBytes)+1
 *
 *
 * We want to seive the range from [0,sqrt(diff)]
 * we will stick with [0,diff] for now
 *
 */


#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "math.h"

#define MIN 2
#define MAX 999999999

void print(uint32_t* a);

int main(){
	uint32_t size, i, j, counter, p, k, e;
	size = (uint32_t)floor(MAX/32);
	uint32_t* state = calloc(size+1, 4);
	i = 2;
	while(i<=MAX){
		k = i;
		p = k % 32;
		e = (uint32_t)(k / 32);
		if(!(state[e] & (1 << p))){
			j = i*i;
			counter = 0;
			while(j <= MAX+1){
				k = j;
				p = k % 32;
				e = (uint32_t)(k / 32);
				state[e] = state[e] | (1 << (p));
				counter++;
				j = (i*i) + counter*i;
			}	
		}
		i++;
	}
	printf("\n\n\n\n\n\n");
	printf("RESULT--------------------------- \n");
	print(state);
}

void print(uint32_t* a){
	uint32_t i, k, p, e;
	i = 2;
	do{
		k = i;
		p = k % 32;
		e = (uint32_t)(k / 32);
		if(!(a[e] & (1 << p))){
			printf("The state of %d is: \t true \n", i);
		}else{
			printf("The state of %d is: \t false \n", i);
		}	
		i++;
	}while(i <= MAX);
}

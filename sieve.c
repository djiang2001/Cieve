#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int n){
  int i, j;
  int max = (n * log(n) * 1.15);
  char * primes;
  primes = malloc(max);

  for(i = 2; i < max; i++){
    primes[i] = 1;
  }

  for(i = 2; i < max; i++){
    if(*(primes + i)){
      n--;
      if(!n){
	free(primes);
	return i;
      }
      for(j = i; j < max; j+= i){
	if(*(primes +j)){
	  *(primes +j) = 0;
	}
      }
    }
  }
  free(primes);
  return 0;
}



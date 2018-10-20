#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long sieve(long n){

  long ary_length = (long)(1.15 * n * log(n));

  char *ary = malloc(ary_length);

  long i;
  for(i = 0; i < ary_length; i++){
    *(ary + i) = -1;
  }
  long counter = 1, current = 2;

  while(counter < n){

    long multiple;
    for(multiple = 2*current; multiple < ary_length; multiple += current){
      *(ary + multiple) = 0;
    }

    current++;
    while(!(*(ary + current))){
      current++;
    }
    counter++;
  }
  free(ary);
  return current;
}

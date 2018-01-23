#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define PI 3.1415926535
int main(int argc, char **argv)
{
int randomNumber, guess, test;
	randomNumber=srand(time(NULL));
	test=randomNumber%2;
	printf ("Guess whether the number is odd or even (1 for odd and 0 for even): ");
	scanf ("%d", &guess);
	if (guess==test&&test==1) {
		printf ("Your guess is right!\n");
		printf ("It is an odd number:%d\n", randomNumber);
	}else if (guess==test&&test==0){
		printf ("Your guess is right!\n");
		printf ("It is an even number:%d\n", randomNumber);
	}else {
		printf ("Your guess is wrong:(\n");
		printf ("The number is %d\n", randomNumber);
	}
	return 0;
}

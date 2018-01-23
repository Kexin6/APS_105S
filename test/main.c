#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	double i, bonus;
	printf ("What is your net income?\n");
	scanf ("%lf", &i);
	if (i<=100000){
		bonus=i*0.1;
		i=i+bonus;
	}else if (i<=20000){
		bonus=100000*0.1+(i-100000)*0.075;
		i=i+bonus;
	}else if (i<=400000){
		bonus=100000*0.1+100000*0.075+(i-200000)*0.05;
		i=i+bonus;
	}else if (i<=600000){
		bonus=100000*0.1+100000*0.075+200000*0.05+(i-400000)*0.03;
		i=i+bonus;
	}else if (i<=1000000){
		bonus=100000*0.1+100000*0.075+200000*0.05+200000*0.03+(i-600000)*0.015;
		i=i+bonus;
	}else{
		bonus=100000*0.1+100000*0.075+200000*0.05+200000*0.03+600000*0.015+(i-1000000)*0.001;
		i=i+bonus;
	}
	printf ("The total income you will have is: %lf.\n", i);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>

#define ZERO (double) (0.0)
#define ONE (double) (1.0)
#define TWO (double) (2.0)
#define THREE (double) 3.0
#define FOUR (double) (4.0)
double sqrt_func(double x);

void main() {
	int i,n;
	double h,l,sum,c0,c1,c2;
	double a=0;

	n=1000;

	h = ONE/n;
	l= h/TWO;
	c0 = l/THREE;
	c1 = TWO*c0;
	c2 =  FOUR * c0;
	double c=0;

	sum = c0*sqrt_func(ZERO) + c0*sqrt_func(ONE);

	for (i=2;i<=2*n-2; i=i+2){
		c=i*l;
		sum+=c1*sqrt_func(c);
	}
	for(i=1;i<=2*n-1;i=i+2){
		c=i*l;
		sum+=c2*sqrt_func(c);
   	}
     printf("%30.20f %30.20f  \n",sum,(M_PI/4));
}


double sqrt_func(double x) {
	return sqrt(1 - x * x);
}

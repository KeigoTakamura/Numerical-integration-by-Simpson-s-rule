
#include<stdio.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>

#define n_max   2000000
#define n_min   50000
#define ZERO (double) (0.0)
#define ONE (double) (1.0)
#define TWO (double) (2.0)
#define THREE (double) 3.0
#define FOUR (double) (4.0)
double sqrt_func(double x);

void main() {
	long double  *sum_log_point;
	sum_log_point =  (long double *)malloc((n_max+1)*sizeof(long double));
	int i,n;
	int cout=0;
	double h,l,sum,c0,c1,c2;
	double a=0;
	n=0;
	FILE *fp;
	//h = ONE/n;
	//l= h/TWO;
	//sum=ZERO,h=ONE/n,l=h/TWO,c0=l/THREE,c1=TWO*c0c0 = l/THREE;
	c1 = TWO*c0;
	c2 =  FOUR * c0;
	double c=0;
	double sum_test = M_PI/(long double)4.0;
	//long double  sum_log[n_max+1];
        for(cout=n_min;cout<n_max;cout++){
		n=cout;
		sum=ZERO;
		h=ONE/n;
		l=h/TWO;
		c0=l/THREE;
		c1=TWO*c0;
		c2=FOUR * c0;
		sum = c0*sqrt_func(ZERO) + c0*sqrt_func(ONE);
		for (i=2;i<=2*n-2; i=i+2){
			c=i*l;
			sum+=c1*sqrt_func(c);
		}
		for(i=1;i<=2*n-1;i=i+2){
			c=i*l;
			sum+=c2*sqrt_func(c);
   		}
     		//printf("%30.20f %30.20f  \n",sum,(M_PI/4));
		sum_log_point[cout]=sum_test-sum;
	}
	fp =fopen("test.txt","w+");
	for(n=n_min;n<n_max;n++){
		fprintf(fp,"%d %30.20llf \n",n,sum_log_point[n]);
	}
	fclose(fp);
	free(sum_log_point);
	return;
}


double sqrt_func(double x) {
	return sqrt(1 - x * x);
}

#include<stdio.h>
#include<math.h>

double sqrt_func(double x);

void main(){
int n=1000;
double  h = 1.0 /  n*2.0;
double sum=0.0;
double a=0.0;


sum=sqrt_func(0.0);
for(int i=1;i < n;i++){
 sum+=4.0*sqrt_func(a+i*h)+2.0*sqrt_func(a+(i+1)*h);
 sum/=h;
}
sum/=3.0;

printf("%lf \n",sum);
}

double sqrt_func(double x) {
        return sqrt(1 - x * x);
}




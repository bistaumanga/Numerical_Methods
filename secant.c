#include<stdio.h>
#include<math.h>

float f(float x)
{
    return sin(x)+3*x-exp(x);
}

void swap(float* x0,float *x1)
{
    float x;
    x=*x0;
    *x0=*x1;
    *x1=x;
}

int main()
{
   float x0,x1,x2,e=0.00005;
   printf("Enter initial guesses: ");
   scanf("%g%g",&x0,&x1);
   do
   {
        if(fabs((*f)(x0))<fabs((*f)(x1)))
            swap(&x0,&x1);
        static int count=0;
        x2=x1-((x1-x0)/((*f)(x1)-(*f)(x0)))*(*f)(x1);
        if(fabs((*f)(x2)-(*f)(x1))==0 || count++>=500) {printf("method fails to converge");exit(1);};
        x0=x1;
        x1=x2;

          }while(fabs((*f)(x0))>e);
   printf("Root is %6.4g",x0);
}

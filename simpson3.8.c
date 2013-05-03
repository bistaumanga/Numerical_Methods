#include<stdio.h>
float f(float x)
{
    return sin(x);
}

int main()
{
    float x0,xn,h=0.01,I=0;
    printf("Enter limits :");
    scanf("%g%g",&x0,&xn);
    int i,j,n=((xn-x0)/h);
    h=(xn-x0)/n;
    for(i=0;i<n;i+=3)
        for(j=i;j<=i+3;j++){
            I+=f(x0+j*h);
            if(j%3!=0)
                I+=2*f(x0+j*h);
        }
    I*=(3.0/8*h);
    printf("Integral is :%g\t",I);
}

#include<stdio.h>

float f(float);
int main()
{
    float a,b,e,c;
    printf("accuracy: ");scanf("%f",&e);
    while(1)
    {
        printf("give the range a and b:  ");
        scanf("%f%f",&a,&b);
        if(fabs(f(a))<=e) {printf("%g is root",a) ; break;}
        else if(fabs(f(b))<=e) {printf("%g is root",b);break;}
        if(f(a)*f(b)<0 ) break;
    }
    do
    {
        c=(a+b)/2;
        if(f(c)*f(a)<0) b=c;
        else a=c;
    }while(fabs(f(c))>e);
    printf("root is %.4g",c);
}

float f(float x)
{
    return pow(sin(x),2)+2*cos(x);
}

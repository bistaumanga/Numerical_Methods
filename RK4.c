/*RK4 method*/
/*Umanga Bista*/
#include<stdio.h>
float fxy(float x,float y)
{
    return (x+sqrt(y));
}
int main()
{
    printf("solution of ordinary differential equation\n\t\tusing RK4 method\n");
    float x0,y0,xn;
    printf("enter the value of x0,y0 and xn\n");
    scanf("%f%f%f",&x0,&y0,&xn);
    float k,k1,k2,k3,k4,x,y;
    x=x0;y=y0;
    float h;
    h=(xn-x0)/10000;
    for(x=x0;x<=xn;x+=h)
    {
        //if (x==xn) break;
        k1=h*fxy(x,y);
        k2=h*fxy(x+h/2,y+k1/2);
        k3=h*fxy(x+h/2,y+k2/2);
        k4=h*fxy(x+h,y+k3);
        k=(k1+2*k2+2*k3+k4)/6;
        //x=x+h;
        y=y+k;
        printf("x: %f\t y: %f\n",x,y);

    }
}

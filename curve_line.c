#include<stdio.h>
int main()
{
    float *x,*y,Ex=0,Ey=0,Exy=0,Ex2=0;
    unsigned int n,i;
    printf("How many data?  ");scanf("%d",&n);
    x=(float*)calloc(n,sizeof(float));
    y=(float*)calloc(n,sizeof(float));
    for(i=0;i<n;++i)
    {
        printf("Enter x[%d] & y[%d]  ",i+1,i+1);
        scanf("%g%g",x+i,y+i);
    }
    for(i=0;i<n;++i)
    {
        Ex+=*(x+i);Ey+=*(y+i);
        Ex2+=pow(*(x+i),2);
        Exy+=(*(x+i)**(y+i));
    }
    float a=(Ex*Ey-n*Exy)/(pow(Ex,2)-n*Ex2);
    float b=(Exy*Ex-Ex2*Ey)/(pow(Ex,2)-n*Ex2);
    printf("Best fitting straight line is y=%gx+%g",a,b);

}

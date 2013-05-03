#include<stdio.h>
int main()
{
    float*x=NULL,*y=NULL,Ex=0,Ex2=0,Exy=0,Ey=0;
    char choice;
    static int count=0,i;
    printf("Exponential fit to a set of observational data:");
    while(choice!='n')
    {
        x=realloc(x,1);
        y=realloc(y,1);
        printf("\nEnter x %d and y %d :  ",count+1,count+1);
        scanf("%g%g",x+count,y+count);
        *(y+count)=log(*(y+count));
        printf("do you want to add more data?? ");
        choice=getche();
        count++;
    }
    for(i=0;i<count;++i)
    {
        Ex+=*(x+i);
        Ey+=*(y+i);
        Ex2+=pow(*(x+i),2);
        Exy+=(*(x+i)*(*(y+i)));
    }
    float a=(Ex*Ey-count*Exy)/(pow(Ex,2)-count*Ex2);
    float b=(Exy*Ex-Ex2*Ey)/(pow(Ex,2)-count*Ex2);
    printf("\nfit is  y=%f*e^(%f*x)",exp(b),a);
}

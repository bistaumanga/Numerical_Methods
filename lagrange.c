#include<stdio.h>

int main()
{
    float *ax,*ay,num,den,x,y=0.0;
    unsigned int n,i,j;
    printf("enter no of items:\t");scanf("%d",&n);
    ax=(float *)malloc(n*sizeof(*ax));
    ay=(float *)malloc(n*sizeof(*ay));
    for (i=0;i<n;++i)
    {
        printf("enter x[%d] and y[%d]:\t",i+1,i+1);
        scanf("%g%g",&ax[i],&ay[i]);
    }
    for (i=0;i<n;++i)
    {
        //printf("\nenter x[%d] and y[%d]",i+1,i+1);
        printf("%g%\t%g\n",ax[i],ay[i]);
    }
    while(1){y=0.0;
    printf("\n enter x:");scanf("%f",&x);
    for(i=0;i<n;++i)
    {
        num=1;
        den=1;
        for(j=0;j<n;++j)
            if(j!=i)
            {
                num*=(x-ax[j]);
                den*=(ax[i]-ax[j]);
            }
        y+=((num/den)*ay[i]);
    }
    printf("y at x=%g is y=%g",x,y);}
    free(ax);free(ay);
}

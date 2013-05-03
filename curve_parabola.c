#include<stdio.h>

void gauss_jordon(float**matrix,int order)
{
    int i,j,k;
    for(j=0;j<order;++j)
        for(i=0;i<order;++i)
            if(i!=j)
            {
                float ratio=*(*(matrix+j)+i)/(*(*(matrix+j)+j));
                for(k=0;k<=order;++k)
                *(*(matrix+k)+i)-=(*(*(matrix+k)+j))*ratio;
            }
    for(i=0;i<order;++i)
        for(j=order;j>=0;--j)
            *(*(matrix+j)+i)/=(*(*(matrix+i)+i));
}
int main()
{
    printf("\t\tCurve Fitting_Parabolic\n");
    int n,i,j,k,order=3;
    printf("Number of observations:  ");
    scanf("%d",&n);
    float *x,*y;
    x=(float*)calloc(n,sizeof(float));
    y=(float*)calloc(n,sizeof(float));
    for(i=0;i<n;++i)
    {
        printf("Enter x(%d) & y(%d) :  ",i+1,i+1);
        scanf("%g%g",x+i,y+i);
    }
    float**matrix;
    matrix=(float**)calloc(order+1,sizeof(float*));
    for(i=0;i<=order;++i)
        *(matrix+i)=(float*)calloc(order,sizeof(float));
    for(i=0;i<order;++i)
        for(j=0;j<order;++j)
            for(k=0;k<n;++k)
                *(*(matrix+j)+i)+=pow(*(x+k),i+j);
    for(i=0;i<order;++i)
            for(k=0;k<n;++k)
                *(*(matrix+order)+i)+=(pow(*(x+k),i)*(*(y+k)));
    gauss_jordon(matrix,order);

    printf("\nThe parabola is %.2g + %.2gx + %.2gx^2",*(*(matrix+order)+0),*(*(matrix+order)+1),*(*(matrix+order)+2));
    for (i = 0; i<=order; i++)
       free(matrix+i);
    free(matrix);
    free(x);
    free(y);
    return 0;
}

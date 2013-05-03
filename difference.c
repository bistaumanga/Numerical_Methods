#include<stdio.h>
#include<math.h>

float f(float x)
{
    return exp(x)*sin(x);
}

int main()
{
    int n=5,i,j;
    float **matrix,x,*y,h;
    printf("Enter initial value of x :");
    scanf("%g",&x);
    h=0.1;
    //Difference table, dynamic
    y=(float*)(calloc(n,sizeof(float)));
    matrix = (float **) calloc(n-1, sizeof(float *));
	for(i = 0; i < n-1; i++)
		matrix[i] = (float *) calloc(n-1-i, sizeof(float));

    //calculating differences
	for(i=0;i<n;++i)
        *(y+i)=f(x+i*h);
    for(i=0;i<n-1;++i)
        *(*(matrix+0)+i)=*(y+i+1)-*(y+i);
    for(i=1;i<n-1;++i)
        for(j=0;j<n-1-i;++j)
            *(*(matrix+i)+j)=*(*(matrix+i-1)+j+1)-*(*(matrix+i-1)+j);

    printf("\nForward Difference table:\n");
    for(i=0;i<n;++i)
        {   printf("%.4g\t%.4g",x+i*h,*(y+i));
            for(j=0;j<n-1-i;++j)
            printf("\t%6.3f",*(*(matrix+j)+i));printf("\n");}

    printf("\nBackward Difference Table:\n");
    for(i=0;i<n;++i)
        {   printf("%.4g\t%.4g",x+i*h,*(y+i));
            for(j=0;j<i;++j)
            printf("\t%6.3f",*(*(matrix+j)+i-j-1));printf("\n");}

    //free memory
    for (i = 0; i< n-1; i++)
       free(matrix+i);
    free(matrix);
    free(y);
    return 0;
}

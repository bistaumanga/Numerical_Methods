#include<stdio.h>
int main()
{
    int n,i,j,k;
    printf("\t\tGauss-Jordan Method\n\nEnter no of unknown variables: ");
    scanf("%d",&n);
    float**matrix,*x;
    x=(float*)calloc(n,sizeof(float));
    matrix = (float **) calloc(n+1, sizeof(float *));
	for(i = 0; i < n+1; i++)
		*(matrix+i) = (float *) calloc(n, sizeof(float));
    for(i=0;i<n;++i)
            for(j=0;j<n+1;++j){
            printf("element[%d,%d]\t",i+1,j+1);
            scanf("%g",*(matrix+j)+i);}
    for(j=0;j<n-1;++j)
        for(i=j+1;i<n;++i)
        {
            float ratio=*(*(matrix+j)+i)/(*(*(matrix+j)+j));
            for(k=0;k<n+1;++k)
                *(*(matrix+k)+i)-=*(*(matrix+k)+j)*ratio;
        }
    printf("The upper triangular matrix is: \n");
    for(i=0;i<n;++i){
        for(j=0;j<n+1;++j)
            printf("\t%.2f",*(*(matrix+j)+i));
        printf("\n");}

    ///back substitution
    for(i=n-1;i>=0;--i)
    {
        float s=0;
        for(j=i+1;j<n;++j)
            s+=*(*(matrix+j)+i)*(*(x+j));
        *(x+i)=(*(*(matrix+n)+i)-s)/(*(*(matrix+i)+i));
    }
    printf("The solutions are: ");
    for(i=0;i<n;++i)
        printf("\t%.2f",*(x+i));
    for (i = 0; i< n+1; i++)
       free(matrix+i);
    free(matrix);
    free(x);
}

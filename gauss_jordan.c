#include<stdio.h>
int main()
{
    int n,i,j,k;
    printf("\t\tGauss-Jordan Method\n\nEnter no of unknown variables: ");
    scanf("%d",&n);
    float**matrix;
    matrix = (float **) calloc(n+1, sizeof(float *));
	for(i = 0; i < n+1; i++)
		*(matrix+i) = (float *) calloc(n, sizeof(float));
    for(i=0;i<n;++i)
            for(j=0;j<n+1;++j){
            printf("element[%d,%d]\t",i+1,j+1);
            scanf("%g",*(matrix+j)+i);}
        int count=0;
    for(j=0;j<n;++j){
        for(i=0;i<n;++i)
            if(i!=j)
            {
                float ratio=*(*(matrix+j)+i)/(*(*(matrix+j)+j));
                for(k=0;k<n+1;++k){
                *(*(matrix+k)+i)-=(*(*(matrix+k)+j))*ratio;count++;}
                 printf("%d\n",count);
            }

    }

    for(i=0;i<n;++i)
        for(j=n;j>=0;--j)
            *(*(matrix+j)+i)/=(*(*(matrix+i)+i));
    printf("\nThe Normal Matrix is:\n");
    for(i=0;i<n;++i){
        for(j=0;j<n+1;++j){
            ///int element=(*(*(matrix+j)+i))<0?(*(*(matrix+j)+i))-0.5:(*(*(matrix+j)+i))+0.5;///round off
            printf("\t%.2f",*(*(matrix+j)+i));}
       // printf("\t|\t%.2f",*(*(matrix+n)+i));///display
        ;printf("\n");}
    printf("The solutions are: ");
    for(i=0;i<n;++i)
        printf(" %.3f",*(*(matrix+n)+i));///(*(*(matrix+i)+i)));
    for (i = 0; i< n+1; i++)
       free(matrix+i);
    free(matrix);
}

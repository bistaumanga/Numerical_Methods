//numerical differintiation with forward difference table
//Umanga Bista
//formula: f'(x)=1/h*(▲Yo-▲²Yo/2+.........+pow(-1,n-1)*▲ⁿYo/n)

#include<stdio.h>
#include<math.h>

float f(float x)
{
    return pow(x,3)-pow(2,x);
}

int main()
{
    int n=10,i,j;
    float **matrix,x,h=0.1,der=0;
    printf("Enter value for which you like to calculate derivative :");
    scanf("%g",&x);
    matrix = (float **) calloc(n, sizeof(float *));
	for(i = 0; i < n; i++)
		*(matrix+i) = (float *) calloc(n-i, sizeof(float));
	for(i=0;i<n;++i)
        *(*(matrix+0)+i)=f(x+i*h);
    for(i=1;i<n;++i)
        for(j=0;j<n-i;++j)
            *(*(matrix+i)+j)=*(*(matrix+i-1)+j+1)-*(*(matrix+i-1)+j);

    for(i=1;i<n;++i)
        der+=(pow(-1,i+1)*(*(*(matrix+i)+0))/(h*i));
    printf("Derivative is : %g",der);

    for (i = 0; i< n; i++)
       free(matrix+i);
    free(matrix);
   // free(y);
    return 0;
}

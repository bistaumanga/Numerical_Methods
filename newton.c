//Newoton Raphson Method
//With numeric differentiation with forward difference table
//Umanga Bista
#include<stdio.h>
#include<math.h>

float f(float x)
{
    return atan(2*x)+atan(3*x)-atan(1);
}
 float df(float x)
 {
    int n=6,i,j;
    float **matrix,*y,h,der=0;
    h=0.1;

    //Difference table, dynamic
    y=(float*)(calloc(n,sizeof(float)));
    matrix = (float **) calloc(n-1, sizeof(float *));
	for(i = 0; i < n-1; i++)
		matrix[i] = (float *) calloc(n-1-i, sizeof(float));

    //printf("\n%d\n",sizeof(**matrix));
	for(i=0;i<n;++i)
        *(y+i)=f(x+i*h);
    for(i=0;i<n-1;++i)
        *(*(matrix+0)+i)=*(y+i+1)-*(y+i);
    for(i=1;i<n-1;++i)
        for(j=0;j<n-1-i;++j)
            *(*(matrix+i)+j)=*(*(matrix+i-1)+j+1)-*(*(matrix+i-1)+j);
        //Derivative here
    for(i=0;i<n-1;++i)
        der+=(pow(-1,i)*(*(*(matrix+i)+0))/(h*(i+1)));

    //free memory
    for (i = 0; i< n-1; i++)
       free(matrix+i);
    free(matrix);
    free(y);
    return der;
 }

 int main()
 {
     float x,e=0.00005;
     printf("Newton-Raphson Method\n");
     printf("Enter initial guesses : ");
     scanf("%g",&x);
     if(df(x)==0) {printf("\nMethod fails for derivative zero at initial guess");
     exit(1);}
     while(fabs(f(x))>=e)
        x-=(f(x)/df(x));
     printf("Root is: %.4f",x); return 0;
 }

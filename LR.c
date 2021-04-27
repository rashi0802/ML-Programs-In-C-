#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i;
float x[20],y[20], sumx=0,sumy=0,sumxy=0,sumx2=0,a,b;
	printf("\n\n-------------Implementing Linear Regression Model----------\n\n");
	printf("Enter the number of data points\n");
	scanf("%d",&n);
	printf("Enter the data values of x and y for the data points\n");
	for(i=1;i<=n;i++)
	{
		printf("x[%d]=",i);
		scanf("%f",&x[i]);
		printf("y[%d]=",i);
		scanf("%f",&y[i]);
	}
	
	for(i=0;i<=n;i++)
	{
		sumx=sumx + x[i];
		sumy=sumy + y[i];
		sumxy= sumxy + x[i]*y[i];
		sumx2= sumx2 + x[i]*x[i];
	}
	// Calculating coefficients a and b for the regression line 
	a= ( (n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
	b= (sumy-(a*sumx))/n;
	
	printf("\nThe least square regression line is: y= %0.2f x + %0.2f",a,b);
	return 0;
	
	
	
	
}

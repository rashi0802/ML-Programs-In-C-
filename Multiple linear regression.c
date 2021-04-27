#include<stdio.h>
int main()
{
	int i,j,n;
	float x1[10],x2[10],y[10],x1s=0,x2s=0,ys=0,x1x2,x1x2s=0,x1y,x1ys=0,x1sq=0,x2sq=0,x2y,x2ys=0;
	float m1,n1,u1,m2,n2,u2,x,z,p,d1,d2,d3,a1,a3,a2,b1,b2,b3,c1,c2,c3;
	printf("\n---------------Implementing Multiple Linear Regression------------------\n\n");
	printf("\n---------------------------Enter the data----------------------------------\n");
	printf("Number of tuples taken ?\n");
	scanf("%d",&n);
	printf("Enter the values of x1,x2,y for all the tuples taken\n");
	printf("Enter the values of x1\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x1[i]);
		x1s=x1s+x1[i];
	}
    printf("Enter the values of x2\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x2[i]);
		x2s=x2s+x2[i];
	}
	printf("Enter the values of y\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&y[i]);
		ys=ys+y[i];
	}
	printf("The equation will be of the form a0 + a1x1 + a2x2\n");
	printf("Calculating the values of a0, a1, a2\n");
	for(i=0;i<n;i++)
	{
		x1x2=x1[i]*x2[i];
		x1x2s=x1x2s+x1x2;
		x1y=x1[i]*y[i];
		x1ys=x1ys+x1y;
		x2y=x2[i]*y[i];
		x2ys=x2ys+x2y;
		x1sq= x1sq+ x1[i]*x1[i];
		x2sq= x2sq+ x2[i]*x2[i];	
	}
	//Solving 3 equations obtained
	/*ys=n*a0+a1*x1s+a2*x2s;
	x1ys=a0*x1s+a1*x1sq+a2*x1x2s;
	x2ys=a0*x2s+a1*x1x2s+a2*x2sq;*/
	a1=n;
	a2=x1s;
	a3=x2s;
	b1=x1s;
	b2=x1sq;
	b3=x1x2s;
	c1=x2s;
	c2=x1x2s;
	c3=x2sq;
	d1=ys;
	d2=x1ys;
	d3=x2ys;
	m1=(c1*a2)-(c2*a1);
	n1=(c1*b2)-(c2*b1);
	u1=(c1*d2)-(c2*d1);
	m2=(c2*a3)-(c3*a2);
	n2=(c2*b3)-(c3*b2);
	u2=(c2*d3)-(c3*d2);
	
	x=((n1*u2)-(n2*u1))/((n1*m2)-(n2*m1));
	z=(u1-(m1*x))/n1;
	p=(d1-(a1*x)-(b1*z))/c1;
	printf("\nThe Least Square Method Multi Linear Regression Equation Is\n");
	printf("\ny=%f + %fx1 + %fx2",x,z,p);
	return 0;
	}

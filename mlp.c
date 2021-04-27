#include<stdio.h>
#include<math.h>
int main()

{
	int i,j,input,k=0,h;
	float bias[10],s[10],l,x[10],w[10][10],o[10],output[10],sum[10],p=0,r;
	printf("\n-------------------------Implementing the Multi Layer Perceptron--------------------------------\n");
	printf("Enter the number of inputs\n");
	scanf("%d",&input);
	printf("Enter the number of hidden layers\n");
	scanf("%d",&h);
	printf("2 outputs 0 or 1\n");
	printf("Enter the value of inputs\n");
	for(i=0;i<input;i++)
	{
		printf("x[%d]=",i+1);
		scanf("%f",&x[10]);
	}
	for(i=0;i<h;i++)
	{
		printf("Bias[%d]=",i+1);
		scanf("%f",&bias[i]);
		printf("Output[%d]=",i+1);
		scanf("%f",&output[i]);
	}
	printf("Enter learning rate\n");
	scanf("%f",&l);
	for(i=0;i<h;i++)
	{
	for(j=0;j<input;j++)
	{
		r=1;
		printf("w[%d][%d]=",i,j);
		scanf("%f",&w[i][j]);
		r=1*x[i];
		p=p+r*w[i][j];
		
	}
	s[k]=p;	
	k++;
	}
	//bias+xi*wi
	for(i=0;i<h;i++)
	{
		
			sum[i]=s[i]+bias[i];
			o[i]=i/(1+exp(sum[i]));
			if(o[i]!=output[i])
			{
				for(i=0;i<input;i++)
				{
					for(j=0;j<h;j++)
					{
						w[i][j]=w[i][j]+l*x[i];
					}
				}
			}
		
	}
	printf("The updated weights are:\n");
	for(i=0;i<input;i++)
				{
					for(j=0;j<h;j++)
					{
						
						printf("%f\y",w[i][j]);
					}
					printf("\n");
				}
	
	return 0;
}

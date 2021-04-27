#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n;
	float w[10], bias=0.3, sum=0.0, output=0.0,x[10],t[10],l=0.5,test[10],threshold,e;
	printf("\n-------Implementing Single Layer Perceptron-----------\n");
	printf("Enter the number of weights\n");
	scanf("%d",&n);
	
	//Enter Weights
	printf("Enter the weights and target value (0 or 1)\n");
	for(i=0;i<n;i++)
	{
		printf("w%d= ",(i+1));
		scanf("%f",&w[i]);
		printf("t%d= ",(i+1));
		scanf("%f",&t[i]);
	}
	
	
	//Enter threshold value
	printf("\nEnter the threshold value\n");
	scanf("%f",&threshold);
	
	printf("\nWeight Matrix is= \n");
	for(i=0;i<n;i++)
	{
		printf("%f\t",w[i]);
	}
	
	//Enter values for the nodes
	printf("\n\nEnter the values for the nodes\n");
	for(i=0;i<n;i++)
	{
		printf("x%d= ",(i+1));
		scanf("%f",&x[i]);
	
	}
	
	//Calculating Weighted Sum
	for(i=0;i<n;i++)
	{
		sum=sum + x[i]*w[i];
	}
	
	if(sum< threshold)
		output=0.0;
	else
	    output=1.0;
	    
	//Recomputing weights
	for(i=0;i<16;i++)
	{
		for(j=0;j<n;j++)
		{
			if(output!=t[j])
			{
				e=t[j]-output;
				w[j]=w[j]+ l*e;
				threshold=threshold-l*e;
			}
			
		}
	}
	
	printf("\nReady To Percept\n");
	//Enter test data
	printf("\nEnter any sample to test\n");
	for(i=0;i<n;i++)
	{
		printf("Weight%d= ",i);
	scanf("%f",&test[i]);
	}
	for(i=0;i<n;i++)
	{
		int sum=0;
		sum=sum+x[i]*test[i];
	}
	if(sum<threshold)
	printf("Sample belongs to class A");
	else
	printf("Sample belongs to class B");
	
		
return 0;
}

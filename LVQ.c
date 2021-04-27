#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,class[10],m,n;
	float l,v[10][10],a,b;
	printf("\n---------------------Implementing Linear Vector Quantization---------------------------\n");
	printf("\nEnter the number of vectors\n");
	scanf("%d",&n);
	printf("Enter the number of data items in each vecor\n");
	scanf("%d",&m);
	//Entering vectors
	printf("Enter the vectors");
	for(i=0;i<n;i++)
	{
		printf("\nEnter vectors and class (1 or 2)\n");
		
		for(j=0;j<m;j++)
		{
			printf("v[%d][%d]=",i,j);
			scanf("%f",&v[i][j]);
		}
		printf("Class for vector %d=",i+1);
		scanf("%d",&class[10]);
	}
	printf("\nEnter the learning rate\n");
	scanf("%f",&l);
	//computing distances
	for(i=2;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a=a+(v[0][j]-v[i][j])*(v[0][j]-v[i][j]);
    		b=b+(v[1][j]-v[i][j])*(v[1][j]-v[i][j]);
		}
		a=sqrt(a);
		b=sqrt(b);
		if((class[i]!=class[0])&&(a<b))
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					v[0][j]=v[0][j]-l*(v[i][j]-v[0][j]);
				}
			}
		}
		else if((class[i]==class[0])&&(a<b))
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					v[0][j]=v[0][j]+l*(v[i][j]-v[0][j]);
				}
			}
		}
		else if((class[i]!=class[1])&&(a>b))
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					v[1][j]=v[1][j]-l*(v[i][j]-v[1][j]);
				}
			}
		}
		if((class[i]==class[1])&&(a>b))
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					v[1][j]=v[1][j]+l*(v[i][j]-v[1][j]);
				}
			}
		}
	}
	printf("The updated weight matrix is:\n");
	for(i=0;i<=1;i++)
	{
		for(j=0;j<m;j++)
		{
		printf("%f\t",v[i][j]);
		}
		printf("\n");
	}
	
	
return 0;	
}

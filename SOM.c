#include<stdio.h>
#include<conio.h>
int main()
{
	int i=0,j,n,c,k,m;
	float w[10][10],v[10][10],l, distance[10],a=0,b=0;
	printf("\n-------Implementing Self Organized Map---------\n");
	printf("Enter the number of vectors\n");
	scanf("%d",&m);
	printf("Enter the number of attributes in vectors\n");
	scanf("%d",&n);
	printf("Enter the number of clusters\n");
	scanf("%d",&c);
	printf("Enter the learning rate(0<r<1)\n");
	scanf("%f",&l);
	printf("\nInitialize Random Weights for (%dx%d) Weight Matrix\n",m,c);
	for(i=0;i<m;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%f",&w[i][j]);
		}
	}
	printf("\nInitialize Vectors (%dx%d) Matrix\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&v[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		    
					a=a+(w[i][1]-v[i][j])*(w[i][1]-v[i][j]);
					b=b+(w[i][2]-v[i][j])*(w[i][2]-v[i][j]);					
         	
		}
		if(a<b)
		{
		printf("Winning Cluster 1");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			w[i][1]=w[i][1]+ l*(v[i][j]-w[i][1]);
		    }
		}}
		else if(b<a)
		{
		printf("Winning Cluster 2");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
			w[i][1]=w[i][2]+ l*(v[i][j]-w[i][2]);
		    }
	    }
        }
           
	}
	printf("\nThe updated Weight Matrix is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%f",w[i][j]);
		}
	}
return 0;	
}

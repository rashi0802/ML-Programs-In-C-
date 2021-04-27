#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("\n----------------Implementing Q Algorithm--------------\n\n");
	int i,j,r[10][10],initial_state,final_state,reward,n,new_state=0,p[10],k;
	float l,q[10][10];
	printf("Enter the number of states in the graph\n");
	scanf("%d",&n);
	printf("Enter the gamma value ( between 0 and 1)\n");
	scanf("%f",&l);
	
	
	//Initializing Q and R Matrix
	printf("Enter the R Matrix\n1.Enter -1 if states are not connected\n2.Enter 0 if states are connected and no reward\n3.Enter the reward for the corresponding connected states\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			q[i][j]=0;
			printf("For node (%d,%d)=",i,j);
			scanf("%d",&r[i][j]);
		}
	}
	printf("Reward Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",r[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the Initial state=\n");
	scanf("%d",&initial_state);
	printf("Enter the Final state=\n");
	scanf("%d",&final_state);
	
	for(i=0;i<n;i++)
	{
		while(i!=final_state)
		{
		
		i=new_state;
		for(j=0;j<n;j++)
		{
			if(r[i][j]>r[i][j+1])
			{
				new_state=j;
					for(k=0;k<=n;k++)
	              	{
			            if(r[new_state][k]>r[new_state][k+1])
		        	    {
				           reward=r[new_state][k+1];
		        	    }
		            }
				p[i]=j;
				q[i][j]=r[i][j]+l*reward;
			}
		}
	    }
	}
	
	printf("\nUpdated Final Q Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f\t",q[i][j]);
		}
		printf("\n");
	}
		printf("\n\nThe Path Is:\t");
		printf("%d",initial_state);
	for(i=0;i<n;i++)
	{
	    
		printf("->%d",p[i]);
	}
return 0;	
}





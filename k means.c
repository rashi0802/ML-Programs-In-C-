#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n,k=0,p=0,sum1=0,sum2=0;
	float h[20],w[20],class[10],a[10],b[10],c[10],d[10],h1[10],w1[10],sumh1=0,sumw1=0,h2[10],w2[10];
	float sumh2,sumw2,meanvh1,meanvh2,meanvw1,meanvw2,s1,s2,q1,q2;
	printf("\n-----------------------Implementing K Means Clustering------------------------\n");
	printf("\nEnter the number of data items\n");
	scanf("%d",&n);
	printf("\nTaking 2 attributes\n");
	printf("Enter the values in first attributes\n");
	for(i=0;i<n;i++)
	{
		printf("v[%d]=",(i+1));
		scanf("%f",&h[i]);
	}

	printf("Enter the values in second attributes\n");
	for(i=0;i<n;i++)
	{
		printf("p[%d]=",(i+1));
		scanf("%f",&w[i]);
	}
    //Computing Centroids
    printf("For the first iteration taking first two elements as centroid\n");
    for(i=2;i<n;i++)
    {
    		a[i]=sqrt((h[0]-h[i])*(h[0]-h[i])+(w[0]-w[i])*(w[0]-w[i]));
    		b[i]=sqrt((h[1]-h[i])*(h[1]-h[i])+(w[1]-w[i])*(w[1]-w[i]));
    		if(a[i]<b[i])
    		{
    			class[i]=1;
    			h1[k]=h[i];
    			w1[k]=w[i];
    			k++;
    		sumh1=sumh1+h[i];	
    	    sumw1=sumw1+w[i];
			}
			else
			{
				class[i]=2;	
				h2[p]=h[i];
				w2[p]=w[i];
				p++;
				sumh2=sumh2+h[i];	
    	        sumw2=sumw2+w[i];
			}			
	}
    
	meanvh1=sumh1/k;
	meanvw1=sumw1/k;
	meanvh2=sumh2/p;
	meanvw2=sumw2/p;
	// Mean vectors
	printf("Mean vectors for class 1 are= (%f,%f)\n",meanvh1,meanvw1);
	printf("Mean vectors for class 2 are= (%f,%f)\n",meanvh2,meanvw2);
	
	//Enter a sample to test
	printf("Enter a sample to test the class\n");
	printf("Attribute 1=");
	scanf("%f",&s1);
	printf("Attribute 2=");
	scanf("%f",&s2);
	
	//computing distances between the sample and new centroids
	q1=sqrt((s1-meanvh1)*(s1-meanvh1)+(s2-meanvw1)*(s2-meanvw1));
    q2=sqrt((s1-meanvh2)*(s1-meanvh2)+(s2-meanvw2)*(s2-meanvw2));
    if(q1<q2)
    printf("Sample belongs to Class A");
    else
    printf("Sample belongs to Class B");
	
return 0;	
}

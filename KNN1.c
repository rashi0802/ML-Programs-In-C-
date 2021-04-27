#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	int i,j,n,class[50],cs,th,values[50],class1,class2,position;
	float x[50],y[50],xt,yt,distance[50],xf,yf,swap;
	
	printf("\n\n--------Implementing KNN Algorithm---------\n\n");
	printf("Enter the number of samples in training data\n");
	scanf("%d",&n);
	printf("Enter the training data\n");
	printf("Enter the x coordinate, y coordinate, class of the samples(1 or 2)\n");
	for(i=1;i<=n;i++)
	{
		printf("x[%d]=",i);
		scanf("%f",&x[i]);
		printf("y[%d]=",i);
		scanf("%f",&y[i]);
		printf("class[%d]=",i);
		scanf("%d",&class[i]);
		
	}
	//Displaying the Training Dataset Entered
	printf("\nx\ty\tClass\n");
	for(i=1;i<=n;i++)
	{
		
			printf("\n%f\t%f\t%d\t",x[i],y[i],class[i]);
	}
	// Enter the Test Data
	printf("\nEnter the Test Data To Predict The Class\n");
	printf("\nX coordinate=");
	scanf("%f",&xt);
	printf("\nY coordinate=");
	scanf("%f",&yt);

	printf("\nEnter the threshold value for testing data\n");
	scanf("%d",&th);
	
	//Calculating Euclidean Distance
	for(i=1;i<=n;i++)
	{
		xf=(x[i]-xt)*(x[i]-xt);
		yf=(y[i]-yt)*(y[i]-yt);
		distance[i]=sqrt(xf+yf);
	}
	//Sorting 
	for(i = 0; i < n - 1; i++)
   {
    position=i;
     for(j = i + 1; j < n; j++)
    {
    if(distance[position] > distance[j])
    position=j;
    }
    if(position != i)
    {
    swap=distance[i];
    distance[i]=distance[position];
    distance[position]=swap;
    values[i]=class[position];
    }
    }
    //checking class
    for(i=0;i<th;i++)
    {
    	if(values[i]=="1")
    	class1++;
    	else
    	class2++;
	}
	if(class1>class2)
	printf("Sample belongs to Class 1");
	else
	printf("Sample belongs to Class 2");
	return 0;
}

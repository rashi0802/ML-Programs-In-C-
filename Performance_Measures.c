#include<stdio.h>
#include<stdlib.h>
int main()
{
float tp,fp,tn,fn,n,p,t;
	float accuracy, error_rate,sensitivity, specificity,precision,recall,fmeasure;
	printf("\n------------Implementing Performance Measures-----------------\n\n");
	printf("For Calculating performance measures input the following values computed on a specific data\n");
	printf("Enter the number of data items\n");
	scanf("%d",&t);
	printf("Enter the number of positive classified items\n");
	scanf("%d",&p);
	printf("Enter the number of negative classified items\n");
	scanf("%d",&n);
	printf("Enter the true positive values\n");
	scanf("%d",&tp);
	printf("Enter the false positive values\n");
	scanf("%d",&fp);
	printf("Enter the true negative values\n");
	scanf("%d",&tn);
	printf("Enter the false negative values\n");
	scanf("%d",&fn);
	accuracy=(tp+tn)/t;
	error_rate=(1-accuracy);
	sensitivity=(tp/p);
	specificity=(tn/n);
	precision=(tp/(tp+fp));
	recall=(tp/(tp+fn));
	fmeasure=(2*precision*recall)/(precision+recall);
	printf("Accuracy= %f\n",accuracy);
	printf("Error Rate= %f\n",error_rate);
	printf("Sensitivity= %f\n",sensitivity);
	printf("Specificity= %f\n",specificity);
	printf("Precision= %f\n",precision);
	printf("Recall= %f\n",recall);
	printf("F Measure= %f\n",fmeasure);
	return 0;
}

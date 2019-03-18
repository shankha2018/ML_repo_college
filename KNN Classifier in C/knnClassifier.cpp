#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>


struct PredictData{
	int prediction;
	double x,y;
	double euclidean_dis;
};
typedef struct PredictData Predict;

int knnClassifier(Predict arr[],int n, int k,Predict u){
	int gr1=0,gr2=0;
	printf("\nUnknown value (X,Y)-> (%f,%f)",u.x,u.y);
	//Calculate the value of all equidean distance
	for(int i=0;i<n;i++){
		arr[i].euclidean_dis = sqrt(((arr[i].x - u.x)*(arr[i].x - u.x)) + ((arr[i].y - u.y)*(arr[i].y - u.y)));
	}
	//To make in ascending order
	Predict temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i].euclidean_dis>arr[j].euclidean_dis)
			{
				temp.x=arr[i].x;
				arr[i].x=arr[j].x;
				arr[j].x=temp.x;
				temp.y=arr[i].y;
				arr[i].y=arr[j].y;
				arr[j].y=temp.y;
				temp.prediction=arr[i].prediction;
				arr[i].prediction=arr[j].prediction;
				arr[j].prediction=temp.prediction;
				temp.euclidean_dis=arr[i].euclidean_dis;
				arr[i].euclidean_dis=arr[j].euclidean_dis;
				arr[j].euclidean_dis=temp.euclidean_dis;
			}
		}
	}
	printf("\n\nsl.no.\tX_axis\t\tY_axis\t\tEq.dis.\t\tGroup");
	//After ascending order sort........printed values of new sorted data set in the range of value of k
	for(int i=0;i<k;i++){
		printf("\n%d->\t%f\t%f\t%f\t%d\n",i+1,arr[i].x,arr[i].y,arr[i].euclidean_dis,arr[i].prediction);
	}
	for (int i = 0; i < k; i++) 
    { 
        if (arr[i].prediction == 0) {
            gr1++; 
		}
        else if (arr[i].prediction == 1) {
            gr2++; 
		}
    } 
  
    return (gr1 > gr2 ? 0 : 1); 
}
int main() 
{ 
    int n = 17,k; // Number of data in the dataset -> n=17
    Predict arr[n]; 
  
	//Dataset.....starts
    arr[0].x = 1; 
    arr[0].y = 12; 
    arr[0].prediction = 0; 
  
    arr[1].x = 2; 
    arr[1].y = 5; 
    arr[1].prediction = 0; 
  
    arr[2].x = 5; 
    arr[2].y = 3; 
    arr[2].prediction = 1; 
  
    arr[3].x = 3; 
    arr[3].y = 2; 
    arr[3].prediction = 1; 
  
    arr[4].x = 3; 
    arr[4].y = 6; 
    arr[4].prediction = 0; 
  
    arr[5].x = 1.5; 
    arr[5].y = 9; 
    arr[5].prediction = 1;
	 
	arr[6].x = 7; 
    arr[6].y = 2; 
    arr[6].prediction = 1; 
  
    arr[7].x = 6; 
    arr[7].y = 1; 
    arr[7].prediction = 1; 
  
    arr[8].x = 3.8; 
    arr[8].y = 3; 
    arr[8].prediction = 1; 
  
    arr[9].x = 3; 
    arr[9].y = 10; 
    arr[9].prediction = 0; 
  
    arr[10].x = 5.6; 
    arr[10].y = 4; 
    arr[10].prediction = 1; 
  
    arr[11].x = 4; 
    arr[11].y = 2; 
    arr[11].prediction = 1; 
  
    arr[12].x = 3.5; 
    arr[12].y = 8; 
    arr[12].prediction = 0; 

	arr[13].x = 2; 
    arr[13].y = 11; 
    arr[13].prediction = 0; 
  
    arr[14].x = 2.5; 
    arr[14].y = 5.5; 
    arr[14].prediction = 1; 
  
    arr[15].x = 2; 
    arr[15].y = 9; 
    arr[15].prediction = 0; 
  
    arr[16].x = 1; 
    arr[16].y = 7; 
    arr[16].prediction = 0; 
    //Dataset....ends
  
    /*Test of train Dataset*/
    Predict p; 
    float r,q;
    printf("KNN Classification using C\n\n");
    printf("Enter the value of x-coordinate:");
    scanf("%f",&r);
    printf("Enter the value of y-coordinate:");
    scanf("%f",&q);
    printf("Enter the value of K:");
    scanf("%d",&k);
    p.x=r;
    p.y=q;
    // Parameter to decide group of the testing point 
    printf ("\nTherefore the Entered Data (%f,%f) belongs to the group -> %d.\n",p.x,p.y,knnClassifier(arr, n, k, p)); 
    return 0; 
} 




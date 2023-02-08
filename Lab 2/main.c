#include <stdio.h>

int main(){
    int n;
    printf("Enter thr size of the array: ");
    scanf("%d",&n);
    int arr[n];
  
    for (int i=0; i<n; i++){
          printf("enter the num: ");
        scanf("%d", &arr[i]);
    }

    int min1=arr[0];
    int min2=arr[1];

    for (int j = 0; j < n; j++)
    {
        if (arr[j]<min1){
            min2=min1;
            min1=arr[j];

        }
        if (arr[j]<min2 && arr[j]>min1){
            min2=arr[j];
        }
    }
    
    printf("%d  %d", min1,min2);
    return 0;
}
#include<stdio.h>
int main(){
    int arr[60] , size , i , j , temp , min;
    printf("Enter the size of the array:");
    scanf("%d",&size);

    printf("Enter elements of array:");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i =0;i<size;i++){
        min = i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        
    }
    printf("Sorted array elements:");
    for (i = 0;i<size;i++){
        printf("%d",arr[i]);
    }
    return 0;
    
}














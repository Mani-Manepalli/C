//Example of Traversal for an Array
#include<stdio.h>
int main(){
    int arr[50],size,i;
    printf("Enter Size:");
    scanf("%d",&size);
    printf("\nEnter elements:");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nElements in the Array:");
    for ( i = 0; i < size; i++)
    {
        printf("%d",arr[i]);
    }
    
    return 0;

}
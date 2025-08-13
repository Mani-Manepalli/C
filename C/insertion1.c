#include <stdio.h>
int main() {
    int arr[60],size , i , j ,temp;
    printf("Enter the size of array elements:");
    scanf("%d", & size);
    printf("Enter the elements of array:\n");   
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i<size; i++) {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }   
        arr[j + 1] = temp;

    }
    printf("Insertion array:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;


}














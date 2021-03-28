#include <stdio.h>

void quicksort(int[],int,int);
int partition(int[],int,int);
int select(int[],int,int);

main() {
    int arr[] = {6,5,3,1,7,9,4,1,3,6,2,1,10,50,3,4,2};
    quicksort(arr,0,16);
    for (int i = 0; i < 17; i++)
        printf("%d\n", select(arr, 17, i));
}

void quicksort(int arr[], int l, int r) {
    if (r < l)
        return;
    int p = partition(arr, l, r);
    quicksort(arr, l, p - 1);
    quicksort(arr, p + 1, r);
}

int partition(int arr[], int l, int r) {
    int i = l - 1;
    int x = arr[r];

    for (int j = l; j < r; j++) {
        if (arr[j] < x) {
            i+=1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

int select(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low < high) {
        int j = partition(arr, low, high);
        if (j < x)
            low = j + 1;
        else if (j > x)
            high = j - 1;
        else 
            return arr[j];
    }
    return arr[x];
}


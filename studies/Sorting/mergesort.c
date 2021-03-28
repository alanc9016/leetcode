#include <stdio.h>

void mergesort(int[], int[], int,int);
void sort(int[],int);
void merge(int[],int[],int,int,int);

main() {
    int arr[] = {5,1,2,4,6,1,8,9};
    sort(arr, 8);

    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
}


void sort(int arr[], int n) {
    int aux[n];
    mergesort(arr, aux, 0, n - 1);
}

void mergesort(int arr[], int aux[], int low, int high) {
    if (high <= low) return;
    int mid = low + (high - low) / 2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid + 1, high);
    merge(arr, aux, low, mid, high);
}

void merge(int arr[], int aux[], int low, int mid, int high) {
    for (int k = low; k <= high; k++)
        aux[k] = arr[k];

    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++) {
        if (i > mid) arr[k] = aux[j++];
        else if (j > high) arr[k] = aux[i++];
        else if (aux[j] < aux[i]) arr[k] = aux[j++];
        else arr[k] = aux[i++];
    }
}


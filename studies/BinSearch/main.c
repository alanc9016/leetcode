#include <stdio.h>

int binsearch(int *arr, int x);

main() {
    int arr[] = {0,1,2,3,4,5,6,7,8,9};

    printf("%d\n", binsearch(arr, -1));
}

int binsearch(int *arr, int x) {
    int low = 0;
    int high = 9;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x) 
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (mid>=10) return 10;
    else if(arr[mid] > x) return mid ;
    else return mid + 1;
}


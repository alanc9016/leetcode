#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

#define MAXSIZE 9

class MaxHeap {
public:
    MaxHeap() :
        size(0) {}
    int parent(int);
    int leftChild(int);
    int rightChild(int);
    void siftUp(int);
    void siftDown(int);
    void insert(int);
    void remove(int);
    int extractMax();
    void changePriority(int,int);
    int size;
private:
    std::vector<int> H;
};

std::vector<int> heapSort(std::vector<int>);
MaxHeap buildHeap(std::vector<int>);

main() {
    /* MaxHeap heap; */

    /* heap.insert(12); */
    /* heap.insert(11); */
    /* heap.insert(13); */
    /* heap.insert(5); */
    /* heap.insert(6); */
    /* heap.insert(7); */
    /* heap.insert(12); */
    /* heap.insert(11); */
    /* heap.insert(14); */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    /* std::cout << heap.extractMax() << std::endl; */
    std::vector<int> arr = {12,11,13,5,6,7};
    arr = heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' ';
}

int MaxHeap::parent(int i) {
    return floor(i/2);
}

int MaxHeap::leftChild(int i) {
    return 2 * i + 1;
}

int MaxHeap::rightChild(int i) {
    return 2 * i + 2;
}

void MaxHeap::siftUp(int i) {
    while (i > 0 && H[i] > H[parent(i)]) {
        int temp = H[parent(i)];
        H[parent(i)] = H[i];
        H[i] = temp;
        i = parent(i);
    }
}

void MaxHeap::siftDown(int i) {
    int maxIndex = i;

    int l = leftChild(i);

    if (l < size && H[l] > H[maxIndex])
        maxIndex = l;
    
    int r = rightChild(i);

    if (r < size && H[r] > H[maxIndex])
        maxIndex = r;

    if (maxIndex != i) {
        std::swap(H[i], H[maxIndex]);
        siftDown(maxIndex);
    }
}

void MaxHeap::insert(int p) {
    if (size == MAXSIZE) {
        std::cout << "ERROR" << std::endl;
        return;
    }

    H.push_back(p);
    siftUp(size);
    size++;
}

void MaxHeap::remove(int i) {
    H[i] = INT_MAX;
    siftUp(i);
    extractMax();
}

int MaxHeap::extractMax() {
    int res = H[0];

    H[0] = H[size];
    siftDown(0);

    return res;
}


std::vector<int> heapSort(std::vector<int> arr) {
    MaxHeap heap = buildHeap(arr);

    for (int i = heap.size-1; i >= 0; i--)
        arr[i] = heap.extractMax();
    return arr;
}

MaxHeap buildHeap(std::vector<int> arr) {
    MaxHeap heap;
    for (auto & e : arr)
        heap.insert(e);

    return heap;
}


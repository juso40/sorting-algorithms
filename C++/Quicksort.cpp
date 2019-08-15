#include <iostream>
#include <vector>

#include "Randomdata.cpp"

void swap(int *a, int *b){
    // swap two values in an array/ vector
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(std::vector<int> &arr,int start,int end){
    int pivot = start;
    for (int i = start + 1; i <= end; i++){
        if (arr[i] <= arr[start]){
            pivot += 1;
            swap(&arr[i], &arr[pivot]);
        }
    }
    swap(&arr[pivot], &arr[start]);
    return pivot;
}

void quickSort(std::vector<int> &arr, int start=0, int end=-2){
    if (end == -2){
        quickSort(arr, 0, arr.size() - 1);
    }
    else if (start < end){
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void printArray(const std::vector<int>& arr){
    for (auto const& v: arr){
        std::cout << v << " | ";
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    quickSort(arr);
    printArray(arr);

    std::cout << "\n\n";
    std::vector<int> bench = randomData(5000);
    printArray(bench);
    std::cout << "\n\n";
    quickSort(bench);
    printArray(bench);

    return 0;
}
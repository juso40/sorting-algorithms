#include <iostream>
#include <vector>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(std::vector<int> &arr){
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    bubbleSort(arr);
    printArray(arr);
    return 0;
}
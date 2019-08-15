#include <iostream>
#include <vector>

#include "Randomdata.cpp"

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

void printArray(const std::vector<int>& arr){
    for (auto const& v: arr){
        std::cout << v << " | ";
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    bubbleSort(arr);
    printArray(arr);

    std::cout << "\n\n";
    std::vector<int> bench = randomData(5000);
    printArray(bench);
    std::cout << "\n\n";
    bubbleSort(bench);
    printArray(bench);

    return 0;
}
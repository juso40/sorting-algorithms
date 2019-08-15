#include <iostream>
#include <vector>

#include "Randomdata.cpp"

void insertionSort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        int elem = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > elem){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = elem;
    }
}

void printArray(const std::vector<int>& arr){
    for (auto const& v: arr){
        std::cout << v << " | ";
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    insertionSort(arr);
    printArray(arr);

    std::vector<int> bench = randomData(5000);
    insertionSort(bench);
    printArray(bench);

    return 0;
}
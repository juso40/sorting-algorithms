#include <iostream>
#include <vector>

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
        std::cout << v << std::endl;
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    insertionSort(arr);
    printArray(arr);
    return 0;
}
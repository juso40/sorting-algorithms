#include <iostream>
#include <vector>

#include "Randomdata.cpp"

void selectionSort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        int *min = &arr[i]; // pointer to the min index
        for ( int j = i; j < n - 1; j++){
            if (arr[j] < *min){
                min = &arr[j]; // update the min pointer if smaller
            } 
        }
        int temp = arr[i]; //swap arr[i] with the smallest index
        arr[i] = *min;
        *min = temp;
    }
}

void printArray(const std::vector<int>& arr){
    for (auto const& v: arr){
        std::cout << v << " | ";
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    selectionSort(arr);
    printArray(arr);

    std::cout << "\n\n";
    std::vector<int> bench = randomData(5000);
    printArray(bench);
    std::cout << "\n\n";
    selectionSort(bench);
    printArray(bench);

    return 0;
}
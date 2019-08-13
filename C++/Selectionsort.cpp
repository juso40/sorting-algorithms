#include <iostream>
#include <vector>

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

void printArray(std::vector<int> &arr){
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    selectionSort(arr);
    printArray(arr);
    return 0;
}
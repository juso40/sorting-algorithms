#include <iostream>
#include <vector>

#include "Randomdata.cpp"

void merge(std::vector<int> &arr, std::vector<int> &left, std::vector<int> &right){
    int left_idx = 0, right_idx = 0, arr_idx = 0;

    while (left_idx < left.size() && right_idx < right.size()) 
    {
        if (left[left_idx] <= right[right_idx]) {
            arr[arr_idx] = left[left_idx];
            left_idx++;
        }
        else {
            arr[arr_idx] = right[right_idx];
            right_idx++;
        }
        arr_idx++;
    }
    // Copy the remaining elements, if any
    while (left_idx < left.size()) {
        arr[arr_idx] = left[left_idx];
        left_idx++; arr_idx++;
    }
    while (right_idx < right.size()) {
        arr[arr_idx] = right[right_idx];
        right_idx++; arr_idx++;
    }
}

void mergeSort(std::vector<int> &arr){
    if (arr.size() <= 1){
        return;
    }
    int n = arr.size();
    int mid = n / 2;
    std::vector<int> left;
    std::vector<int> right;
    //split our unsorted array in 2 arrays
    for (int i = 0; i < mid; i++){
        left.push_back(arr[i]);
    }
    for (int i = 0; i < n - mid; i++){
        right.push_back(arr[mid + i]);
    }
    // recursively call mergeSort() untill size <= 1 
    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right); // merge the subarrays back to our main array

}

void printArray(const std::vector<int>& arr){
    for (auto const& v: arr){
        std::cout << v << " | ";
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    mergeSort(arr);
    printArray(arr);

    std::cout << "\n\n";
    std::vector<int> bench = randomData(5000);
    printArray(bench);
    std::cout << "\n\n";
    mergeSort(bench);
    printArray(bench);

    return 0;
}
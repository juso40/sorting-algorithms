#include <vector>
#include <iostream>
#include <algorithm>  // used for min(x, y);

#include "Randomdata.cpp"

#define RUN 32

void insertionSort(std::vector<int> &arr, int start = 0, int end = 0){
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

void merge(std::vector<int> &arr, int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;

    std::vector<int> left(len1);
    std::vector<int> right(len2);

    for (int i = 0; i < len1; i++){
        left[i] = arr[start + i];
    }
    for (int i = 0; i < len2; i++){
        right[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < len1 && j < len2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1){
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2){
        arr[k] = right[j];
        k++;
        j++;
    }

}

void timSort(std::vector<int> &arr){
    int n = arr.size();
    if (n <= 64){
        return insertionSort(arr, 0, n - 1);
    }

    for (int i = 0; i < n; i += RUN){
        insertionSort(arr, i, std::min(i + RUN - 1, n - 1));
    }

    int block = RUN;
    while (block < n){
        int start, end, mid;
        for (start = 0; start < n; start += 2 * block){
            end = std::min(n - 1, start + 2 * block - 1);
            mid = (start + end) / 2;
            merge(arr, start, mid, end);
        }
        block = block * 2;
    }
}

void printArray(const std::vector<int>& arr){
    for (auto const& v: arr){
        std::cout << v << " | ";
    }
}

int main(){
    std::vector<int> arr = {12, 321, 12, 1, 5, 34, 27};
    timSort(arr);
    printArray(arr);

    std::cout << "\n\n";
    std::vector<int> bench = randomData(5000);
    printArray(bench);
    std::cout << "\n\n";
    timSort(bench);
    printArray(bench);

    return 0;
}
#include <iostream>
#include <vector>

#include "Randomdata.cpp"

void stalinSort(std::vector<int> &arr){
    if (arr.size() <= 1){
        return;
    }
    int max = arr[0];
    int n = 0;
    while (n < arr.size()){
        if (arr[n] < max){
            arr.erase(arr.begin() + n);
        }
        else if (arr[n] >= max){
            max = arr[n];
            n++;
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
    stalinSort(arr);
    printArray(arr);

    std::cout << "\n\n";
    std::vector<int> bench = randomData(5000);
    printArray(bench);
    std::cout << "\n\n";
    stalinSort(bench);
    printArray(bench);

    return 0;
}
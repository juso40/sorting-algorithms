#include <random>
#include <vector>

std::vector<int> randomData(int range){
    std::vector<int> result;
    for (int i = 0; i < range; i++){
        result.push_back(std::rand() % 500);
    }
    return result;
}
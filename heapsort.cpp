#include <iostream>
#include <vector>

void HeapDownUp(std::vector<int>& array, int start, int end) {
    auto switchPos = 2 * start + 1;
    while(switchPos <= end) {
        // 右孩子存在
        if (switchPos < end && array[switchPos] < array[switchPos+1]) {
            switchPos = switchPos + 1;
        }
        if (array[start] < array[switchPos]) {
            std::swap(array[start], array[switchPos]);
            start = switchPos;
            switchPos = start * 2 + 1;
        } else {
            break;
        }
    }
}

void HeapSort(std::vector<int>& array, int n) {
    for (auto i = n/2-1; i >= 0; --i) {
        HeapDownUp(array, i, n-1);
    }

    for (auto i = n-1; i > 0; --i) {
        std::swap(array[0], array[i]);
        HeapDownUp(array, 0, i-1);
    }
}


int main() {
    std::vector<int> array = {110,100,90,40,80,20,60,10,30,50,70};
    HeapSort(array, array.size());
    for (auto val : array)  {
        std::cout << val << std::endl;
    }
    return 0;
}
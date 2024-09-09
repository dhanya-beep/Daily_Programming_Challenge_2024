#include <iostream>
#include <vector>

void sort012(std::vector<int>& arr) {
    int left = 0, mid = 0;
    int right = arr.size() - 1;

    while (mid <= right) {
        if (arr[mid] == 0) {
            std::swap(arr[left], arr[mid]);
            left++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            std::swap(arr[mid], arr[right]);
            right--;
        }
    }
}

int main() {
    std::vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    sort012(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

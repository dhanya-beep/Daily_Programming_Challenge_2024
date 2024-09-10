#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(const vector<int>& arr) {
    int n = arr.size() + 1;  // Since arr has n-1 elements
    long long expected_sum = static_cast<long long>(n) * (n + 1) / 2;  // Use long long to prevent overflow
    long long actual_sum = 0;

    for (int num : arr) {
        actual_sum += num;
    }

    return static_cast<int>(expected_sum - actual_sum);  // Cast back to int
}

int main() {
    // Test Case 1
    vector<int> arr1 = {1, 2, 4, 5};
    cout << "Missing Number: " << findMissingNumber(arr1) << endl;  // Output: 3

    // Test Case 2
    vector<int> arr2 = {2, 3, 4, 5};
    cout << "Missing Number: " << findMissingNumber(arr2) << endl;  // Output: 1

    // Test Case 3
    vector<int> arr3 = {1, 2, 3, 4};
    cout << "Missing Number: " << findMissingNumber(arr3) << endl;  // Output: 5

    // Test Case 4
    vector<int> arr4 = {1};
    cout << "Missing Number: " << findMissingNumber(arr4) << endl;  // Output: 2

    // Test Case 5
    vector<int> arr5(999999);
    for (int i = 0; i < 999999; ++i) {
        arr5[i] = i + 1;  // This will create an array from 1 to 999999
    }
    cout << "Missing Number: " << findMissingNumber(arr5) << endl;  // Output: 1000000

    return 0;
}

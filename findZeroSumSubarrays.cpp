#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int, vector<int>> prefixSumMap;
    vector<pair<int, int>> result;
    int currentSum = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];
        
        if (currentSum == 0) {
            result.push_back(make_pair(0, i)); 
        }
      
        if (prefixSumMap.find(currentSum) != prefixSumMap.end()) {
            for (int startIndex : prefixSumMap[currentSum]) {
                result.push_back(make_pair(startIndex + 1, i)); 
            }
        }

        prefixSumMap[currentSum].push_back(i);
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, -3, 3, -1, 2};
    vector<int> arr2 = {4, -1, -3, 1, 2, -1};
    vector<int> arr3 = {0, 0, 0};
    vector<int> arr4 = {-3, 1, 2, -3, 4, 0};

    auto printResult = [](const vector<pair<int, int>>& result) {
        for (const auto& p : result) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    };

    cout << "Subarrays with zero sum in arr1: ";
    printResult(findZeroSumSubarrays(arr1));  

    cout << "Subarrays with zero sum in arr2: ";
    printResult(findZeroSumSubarrays(arr2));  

    cout << "Subarrays with zero sum in arr3: ";
    printResult(findZeroSumSubarrays(arr3)); 

    cout << "Subarrays with zero sum in arr4: ";
    printResult(findZeroSumSubarrays(arr4));  

    return 0;
}

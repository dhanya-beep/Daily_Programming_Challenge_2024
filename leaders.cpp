#include <bits/stdc++.h>
using namespace std;

vector<int> findLeader(vector<int>& arr){
    int n = arr.size();
    vector<int> leaders;
    
    int right = arr[n-1];
    leaders.push_back(right);
    
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > right){
            leaders.push_back(arr[i]);
            right = arr[i];
        }
    }
    
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
}

int main(){
    vector<int> arr = {100, 50, 20, 10};
    vector<int> leaders = findLeader(arr);
    
    cout<<"leaders:";
    for(int i = 0; i < leaders.size(); i++){
        cout<< " " <<leaders[i];
    }
    
    return 0;
}
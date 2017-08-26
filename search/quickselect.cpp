#include <iostream>
#include <vector>
#include <algorithm>

#include "utils.h"

using namespace std;

int helper(vector<int>& nums, int start, int end, int target){
    
    if(start >= end) return nums[start];

    int pivot = nums[end];
    int idx = start - 1;
    
    for(int i = start; i <= end; i++){
        if(nums[i] <= pivot){
            int temp = nums[i];
            nums[i] = nums[++idx];
            nums[idx] = temp;
        }
    }

    if(idx == target){
        return nums[idx];
    }

    if(idx > target){
        return helper(nums, start, idx-1, target);
    }
    else{
        return helper(nums, idx+1, end, target);
    }
}

int quickselect(vector<int>& nums, int k){
    return helper(nums, 0, nums.size()-1, k-1);
}

int main(){

    vector<int> nums = randomIntVector(20);
    int k = 11;

    cout << "Unsorted: \n";
    printNums(nums);

    int number = quickselect(nums, k);
    cout << "\nNumber: " << number << endl;
    
    sort(nums.begin(), nums.end());
    cout << "\nAns: " << nums[k-1] << endl;

    //printNums(nums);
    
    return 0;
}

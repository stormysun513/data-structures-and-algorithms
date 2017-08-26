#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

#include "utils.h"

using namespace std;

void helper(vector<int>& nums, int start, int end, vector<int>& buf);

void mergesort(vector<int>& nums){
    vector<int> buf(nums.size());
    helper(nums, 0, nums.size()-1, buf);
}

void helper(vector<int>& nums, int start, int end, vector<int>& buf){
    
    if(start >= end) return;

    // divide
    int mid = start + (end-start)/2;
    helper(nums, start, mid, buf);
    helper(nums, mid+1, end, buf);

    // combine two sorted array
    int i = start;
    int j = mid+1;
    int idx = start;

    // cout << "Debug: " << start << ", " << end << endl;
    while(i <= mid && j <= end){
        if(nums[i] < nums[j]){
            buf[idx++] = nums[i++];
        }
        else{
            buf[idx++] = nums[j++];
        }
    }

    while(i <= mid) buf[idx++] = nums[i++];
    while(j <= end) buf[idx++] = nums[j++];
    for(int k = start; k <= end; k++){
        nums[k] = buf[k];
    }
}

int main(){

    vector<int> nums = randomIntVector(20);

    cout << "Unsorted: \n";
    printNums(nums);

    mergesort(nums);   
    cout << "\nSorted: \n";
    printNums(nums);
    
    return 0;
}

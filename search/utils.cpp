#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

#define MAX_INT_RANGE       200

bool compareNums(const vector<int>& nums1, const vector<int>& nums2){
    if(nums1.size() != nums2.size()) return false;
    for(int i = 0; i < nums1.size(); i++){
        if(nums1[i] != nums2[i]) return false;
    }
    return true;
}

void printNums(const vector<int>& nums){   
    
    for(int num: nums){
        cout << num << " ";
    }
    cout << endl;
}

vector<int> randomIntVector(int size){
    
    srand((unsigned long)time(0));    
    vector<int> nums(size);
    for(int j = 0; j < size; j++){
        nums[j] = rand()%MAX_INT_RANGE;
    }
    return nums;
}

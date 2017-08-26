
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

void swap(vector<int>& nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void bubblesort(vector<int>& nums){
    
    for(int i = nums.size()-1; i > 0; i--){
        for(int j = 1; j <= i; j++){
            if(nums[j] < nums[j-1]){
                swap(nums, j, j-1);
            }
        }
    }
}

int main(){

    vector<int> nums = randomIntVector(20);

    cout << "Unsorted: \n";
    printNums(nums);

    bubblesort(nums);   
    cout << "\nSorted: \n";
    printNums(nums);
    
    return 0;
}

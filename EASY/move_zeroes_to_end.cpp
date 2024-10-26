#include <bits/stdc++.h>
using namespace std;

//approach 1 use extra array
//append all non zero element
//till the remaining size append zero

void moveZeroes(vector<int>& nums) {
        vector<int> arr;
        for(auto elem: nums){
            if(elem!=0){
                arr.push_back(elem);
            }
        }
        for(int i=arr.size();i<nums.size();i++){
            arr.push_back(0);
        }
        nums = arr;
    }

//approach 2

// 2pointer approach .
//mark first zero element
//check next zero element and swap their position with current zero and do j++ now

void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    if(j!=-1){
        for (int i = j + 1; i < n; i++) {
                if (nums[i] != 0) {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
    }
    
    }


int main(){
    vector<int> nums = {0,2,0,3};
    moveZeroes(nums);
    for(auto elem: nums){
        cout<<elem;
    }
}
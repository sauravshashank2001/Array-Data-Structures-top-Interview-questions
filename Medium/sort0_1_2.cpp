/**
 Given an array nums with n objects colored red, white, or blue, 
 sort them in-place so that objects of the same color are adjacent, 
 with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

sort(nums.begin(),nums.end());

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
 */

#include<bits/stdc++.h>
using namespace std;

//approach 1 , count all three with three varible and update the array accordingly or maintain new array 
//and push 0,1,2 as per count

//dutch national flag algo

//maintain three pointers 
//two at start(low,mid) one at end(high)
//low for 0 ,mid for 1 end for high
//if mid==0 swap with low and do mid++ low++
//if mid==2 swap with high and do mid++ high--
//if mid ==1 do mid++

void color_sort(vector<int>& nums){
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;
    while(mid<=high){
       if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return;
}


int main(){
    vector<int> nums= {2,0,1};
    color_sort(nums);
    for(auto it:nums){
        cout<<it;
    }

}
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]



#include<bits/stdc++.h>
using namespace std;

//approach 1 - find the final rotation equivalent which is smaller than vector size and first push later number 
//into new vector then the before elements 
void rotateArraytoleft(vector<int>&nums,int k){
    vector<int> arr;
    int finl_rotation = k%nums.size();
    for (int i= nums.size()-finl_rotation;i<nums.size();i++){
        arr.push_back(nums[i]);
    }
    for(int i=0;i<nums.size()-finl_rotation;i++){
        arr.push_back(nums[i]);
    }
}

//approach 2 using array reversal

void Reverse(vector<int>&nums, int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
// Function to Rotate k elements to left
void rotateArraytoleft2(vector<int>&nums, int k)
{
  // Reverse first k elements
  Reverse(arr, 0, k - 1);
  // Reverse last n-k elements
  Reverse(arr, k, nums.size() - 1);
  // Reverse whole array
  Reverse(arr, 0, nums.size - 1);
}



int main(){

    vector<int> nums = {1,2,3,4,5,6,7};
    int k=3;
    vector<int> arr;
    rotateArraytoleft2(nums,k);
    for(auto num: nums){
        cout<<num;
    }


}
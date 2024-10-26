/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
 */

#include<bits/stdc++.h>
using namespace std;

//approach 1- iterate on array with two for loop and for each element check if elements sum == target

//approach 2- insert each element in hashmap with index look for target-current elem is present in hashmap
//if yes return both index

//tc- o(n) space- o(1)

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size();i++){
            if(hashmap.find(target-nums[i]) == hashmap.end()){
                hashmap[nums[i]] = i;
            }
            else{
                return {hashmap[target-nums[i]],i};
            }
        }
        return {-1,-1};
    }


//for o(1)-space and o(nlogn)time
// sort array use two pointer as sum is greater or smaller move right and left pointer accordingly

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {left,right};
        }
        else if (sum < target) left++;
        else right--;
    }
    return {-1,-1};
}


int main(){
    vector<int> v= {1,3,5,9,6,7};
    int result = 4;

}
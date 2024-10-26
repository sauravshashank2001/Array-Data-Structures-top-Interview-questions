// return size of array after removing duplicates

//[1,2,2,3] -> o/p - 3, also need to change the array


//Brute force - insert each element into a hashmap,clear the vector and insert back
//lastly sort and return the hashmap size

//note use set - it stores in ascending order so no need for sorting

/*int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> map;
        for(auto x:nums){
            map[x] = true;
        }
        nums.clear();
        for(const auto&x: map){
            nums.push_back(x.first);
        }
        sort(nums.begin(),nums.end());
        return map.size();
    }*/

//optimize

#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>&nums){
    int start = 0;
    int end = 0;
    while(start<nums.size()-1){
        start++;
        if(nums[start]!=nums[end]){
            end++;
            nums[end] = nums[start];
            
        }
    }
    return end+1;
    
}


int main(){
    vector<int> nums = {1,1,2};
    int result = removeDuplicates(nums);
    cout<<result;
}
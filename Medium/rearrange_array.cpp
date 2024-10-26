

/**
 * 
 * You are given a 0-indexed integer array nums of even length 
 * consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they 
were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
 
 */

//approach 1 - maintain two arr one positive one negative. 
//iterate on positive if index %2==0 push positive element else -1
//iterate on main array set negative elem where ever with negative elem
//edge case last elem negative - check size of main array if one less then push last elem of negtive array 

#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> arrPositive;
    vector<int> arrNegative;
    for(auto it:nums){
        if(it>0){
            arrPositive.push_back(it);
        }
    }
    for(auto it:nums){
        if(it<0){
            arrNegative.push_back(it);
        }
    }
    nums.clear();
    int start1=0;
    int start2=0;
    int i=0;
    while(start1<arrPositive.size()){
        if(i%2==0){
            nums.push_back(arrPositive[start1]);
            start1++;
        }
        else{
            nums.push_back(-1);
        }
        i++;
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]==-1){
            nums[i] = arrNegative[start2];
            start2++;
        }

    }
    if(nums.size()!= arrPositive.size()+arrNegative.size()){
        nums.push_back(arrNegative[arrNegative.size()-1]);
    }
    return nums;


}

// approach2 - use single array

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> arr(nums.size(),0);
    int negIndex= 1;
    int posIndex = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            arr[negIndex] = nums[i];
            negIndex+=2;
        }
        if(nums[i]>0){
            arr[posIndex] = nums[i];
            posIndex+=2;
        }
    }
    return arr;


}



int main(){
    vector<int> v= {1,3,5,9,6,7};
    int result = 4;

}




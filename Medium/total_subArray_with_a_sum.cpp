/**
 *Given an array of integers nums and an integer k, 
 return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
 * 
 */

//brute force - genrate all subarray and check their sum == target

int subarraySum1(vector<int>& nums, int k) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
int subarraySum2(vector<int>& nums, int k) {
         map<int,int> map1;
        map1[0]=1;
        int prefixSum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int remaining  = prefixSum-k;
            count+=map1[remaining];
            map1[prefixSum] +=1;
        }
        
        return count;
    }
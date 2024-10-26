/**
 * Problem Statement: Given an array containing both positive and negative
 *  integers, we have to find the length of the longest subarray with the 
 * sum of all elements equal to zero.

Examples
Example 1:
Input Format
: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result
: 5
 * 
 */

#include<bits/stdc++.h>
using namespace std;

//approach 1 - generate all subarray check sum if 0 maintain count and max_count of length

int maxLen(vector<int>& arr, int n) {
        // Your code here
        int max_count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            int count=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                count++;
                if(sum==0){
                    max_count = max(count,max_count);
                }
            }
        }
        return max_count;
    }


//approach 2 - using prefix_Sum
//update prefix sum in a hashmap
//if prefix sum is found in map that means the subarray in between have 0 sum

int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int> map;
        int max_len=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum ==0 ){ //if total sum till now is 0
                max_len = max(i+1,max_len);
            }
            if(map.count(sum)>0){
                max_len = max(max_len,i-map[sum]);
            }
            else{
                map[sum]=i;
            }
        }
        return max_len;
    }

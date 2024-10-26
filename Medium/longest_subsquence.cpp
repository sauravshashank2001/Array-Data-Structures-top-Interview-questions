#include<bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Examples
Example 1:
Input:
 [100, 200, 1, 3, 2, 4]

Output:
 4


 */

//brute force - go to each element and find elem+1 element 
//till it present using while update mx count the move to next element

int max_subsequence1(vector<int>&nums){
    int count =1;
    int max_count=1;
    if(nums.size()==0){
        return 0;
    }
    for(int i=0;i<nums.size();i++){
        int  elem=nums[i];
        count=1;
        while(count>0){
            if(find(nums.begin(),nums.end(),elem+1) !=nums.end()){
                count++;
            }
            else{
                count=0;
                break;
            }
            max_count = max(max_count,count);
            elem++;

        }
    }
    return max_count;
}


//approach 2 - sort and update the count and max_count 
int max_subsequence(vector<int>&nums){
    int count =1;
    int max_count=1;
    if(nums.size()==0){
        return 0;
    }
    
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]+1==nums[i+1] || nums[i]==nums[i+1]){
            count++;
            max_count = max(count,max_count);
        }
        else if(nums[i]==nums[i+1]){//if same elem occur then dont break count
            continue;
        }
        else{
            count=1;
        }
    }
    return max_count;
}

//optimal-using set dsa to lookup at o(1) and do contant work for each elem. for looking at therir respective seq




#include <bits/stdc++.h>
using namespace std;

int max_subsequence3(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}





int main(){

    vector<int> nums={100, 200, 1, 3, 2, 4};
    cout<<max_subsequence1(nums);

}
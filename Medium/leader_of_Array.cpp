/**
Given an array, print all the elements which are leaders. A Leader 
is an element that is greater than all of the elements on its right side in the array.

Example 1:
Input:

arr = [4, 7, 1, 0]
Output
:
 7 1 0

 */

//brute force - check each element and look for anything greater present in the right


#include<bits/stdc++.h>
using namespace std;
 vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            bool greatest = true;

            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>arr[i]){
                    greatest = false;
                }
            }
            if(greatest){
                ans.push_back(arr[i]);
            }
            
        }
        return ans;
        
        
    }

//optimized - maintain a max from last if current is greater append else pass
//if same order required then push it in stack and take out in result vector
 vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int max_elem = arr[arr.size()-1];
        ans.push_back(max_elem);
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]>max_elem){
                ans.push_back(arr[i]);
                max_elem = arr[i];
            }
            
        }
        return ans;
        
        
    }


int main(){
    vector<int> nums= {1,3,5,9,6,7};
    vector<int> result = leaders(nums);
    for(auto it:result){
        cout<<it;
    }

}
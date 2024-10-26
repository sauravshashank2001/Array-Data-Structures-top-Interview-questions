#include<bits/stdc++.h>
using namespace std;


/**
 * Given an integer array of size n, find all 
 * elements that appear more than ⌊ n/3 ⌋ times.


Example 1:

Input: nums = [3,2,3]
Output: [3]

 */


//approach 1 - go to each elem use stl count and store it in the array - o(n2)

//appproach2 - sort and count o(nlogn)
//approach 2 - store occurence of each  o(1)
// in hashmap and iterate again on map to get elements occurence greater
 //than n/3 insert it in resultant vector


vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> result;
        for(auto it:nums){
            if(map.count(it)>0){
                map[it]++;
            }
            else{
                map[it]=1;
            }
        }
        for(auto it: map){
            if(it.second> nums.size()/3){
                result.push_back(it.first);
            }
        }
        return result;
    }
//boye's morre voting algorithm
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);
    return ls;
}



int main(){
    vector<int> nums={1,2,2,3,3,2,3,4};
    vector<int> res = majorityElement(nums);
    for(auto it:res){
        cout<<it<" ";  
    }
}
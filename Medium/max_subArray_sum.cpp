#include<bits/stdc++.h>
using namespace std;


//approach 1 - check sum of each subarray and maintain a max sum
int max_subArraySum(vector<int>& nums){
    int max_sum =nums[0];
    for(int i=0;i<nums.size();i++){
        int sum =0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;



}

//approach 2 -  kadane's algo
// algo if current sum 0 it will reduce overall max_sum so dont consider tht
// so for each index maintain overall sum and check if it is grter than max_sum
//if it is less than 0 put it 0 again 


 int maxSubArray2(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            max_sum = max(sum,max_sum);
            if(sum<0){
                sum =0;
            }
            
        }
        return max_sum;
       

    }


int main(){
    vector<int> nums= {-2,1,-3,4,-1,2,1,-5,4};
    cout<<max_subArraySum(nums);

}
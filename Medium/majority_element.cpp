/***
 * Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
Example 1:

Input: nums = [3,2,3]
Output: 3
 * 
 * 
 */

//approach 1 - count occurence of each whichever hits >n/2 first return that - o(n2)

int majorityElement1(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int count_1 = count(nums.begin(),nums.end(),nums[i]);
            if(count_1> nums.size()/2){
                return nums[i];
            }
        }
        return -1;
    }

//approach 2- sort and count each if count >n/2 then return if element change make count 1 again    
int majorityElement2(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int count =1;
    int result = nums[0];
    for(int i=0;i<nums.size();i++){
        
        if(nums[i]==nums[i+1]){
            count++;
            if(count>nums.size()/2){
               result = nums[i];
            }
        }
        else{
            count=1;
        }
    }
    return result;
    }

//approach 3- maintain frequency in a hashmap and if frequncy >  n/2 return that element

int majorityElement3(vector<int>& nums) {
    unordered_map<int,int> map;
    int result = nums[0];
    
    for(int i=0;i<nums.size();i++){
        if(map.count(nums[i])){
            map[nums[i]]++;
            if(map[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
        else{
            map[nums[i]]=1;
        }
        
    }
    return result;
    }


//moore's most voting algorithm

int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; // count
        int el; // Element

        //applying the algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i]) cnt++;
            else cnt--;
        }

        //checking if the stored element
        // is the majority element:
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) cnt1++;
        }

        if (cnt1 > (n / 2)) return el;
        return -1;
    }





int main(){
    vector<int> nums= {2,0,1};
    int result =  majorityElement2(nums);
    cout<<result;

}


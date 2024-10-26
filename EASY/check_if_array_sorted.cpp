//array may be rotated but check after rotation it is sorted or not 

//[3,4,5,1,2] - > true, [3,1,2,4,5] - false

bool check(vector<int>& nums) {
    int count =0;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
    } 
    if(nums[nums.size()-1]>nums[0]){
        count++;
    }
    return count<2;
}

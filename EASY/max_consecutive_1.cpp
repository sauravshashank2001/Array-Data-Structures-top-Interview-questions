//approach - check number update count if number is 1 if not 1 then make count 0and maintain a max_count 

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max_count = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                
                if(i<nums.size()>1 && nums[i+1]==1){
                    count+=1;
                }
                else{
                    count+=1;
                }
                
            }
            else{
                count=0;
            }

            max_count = max(max_count,count);
        }
        return max_count;
    }
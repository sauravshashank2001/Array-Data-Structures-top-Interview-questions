//every number appear twice find the unique number

//brute force select each elemnt and perform linear search for each if count ==1 then return

//approach 1 using hashmap and counting the frequency


int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto it: nums){
            if(map.count(it)>0){
                map[it] += 1;   
            }
            else{
                map[it]=1;
            }
        }
        for(auto it:map){
            if(it.second==1){
                return it.first;
            }
        }
        return nums[0];

    }
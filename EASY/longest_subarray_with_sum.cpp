//prblem - Given an array arr containing n integers and an integer k. 
//Your task is to find the length of the longest Sub-Array with the sum of
// the elements equal to the given value k.

//brute force

//generate all subarray and maintain max size

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}


//approach 2 - using hashmap and check prefix sum
//maintain each index sum in a hashmap
//for each index check if remaining sum is present in hashmap
//if yes update maxlength with the help of index

//Note- work for both 0,positive and negative 

int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map <long long,int> prefixSumMap;
        
        int maxlen=0;
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=A[i]; //taking sum for each index
            
            if(sum == K){//checking if total sum till now is required sum
                maxlen = max(maxlen,i+1);
            }
            int rem =sum - K;
            if(prefixSumMap.count(rem)>0){//checking if remaing number has came at any index
                int len = i - prefixSumMap[rem];
                maxlen = max(maxlen,len);
            }
            if(prefixSumMap.count(sum)==0){
                prefixSumMap[sum] =i; //updating left most index sum at end as we need longes
            }
        }        
        return maxlen;
    } 


//most optimal two pointer approach

//works only for positives 

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}



//merge two sorted array without extra space


// - using an extra array

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int start1 = 0;
        int start2=0;
        while(start1<m && start2<n){
            if(nums1[start1]>nums2[start2]){
                nums3.push_back(nums2[start2]);
                start2++;
            }
            else{
                nums3.push_back(nums1[start1]);
                start1++;
            }
        }
        while(start1<m){
            nums3.push_back(nums1[start1]);
            start1++;
        }
        while(start2<n){
            nums3.push_back(nums2[start2]);
            start2++;
        }
        nums1=nums3;
    }

//sort these two store smaller in 1st larger in later
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

}
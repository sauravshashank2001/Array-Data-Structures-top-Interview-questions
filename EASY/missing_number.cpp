/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.

 */

// approach 1 -  sort the array and start from starting by adding 1 not equal apply break and return

#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int missing_number_1(vector<int> &a)
{

    sort(nums.begin(), nums.end());
    if (nums.size() == 1 && nums[0] != 0)
    {
        return 0;
    }
    else if (nums.size() == 1 && nums[0] == 0)
    {
        return 1;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums[i])
        {
            return i;
        }
    }
    return nums[nums.size() - 1] + 1;
}

// optimal approach - sum of n whole number - current array sum  = missing number

// sum of n natural number - n(n+1)/2

int missing_number_2(vector<int> &nums)
{
    if (nums.size() == 1 && nums[0] != 0)
    {
        return 0;
    }
    else if (nums.size() == 1 && nums[0] == 0)
    {
        return 1;
    }
    int first_n_number_sum = ((nums.size()) * (nums.size() + 1)) / 2;
    cout << first_n_number_sum;
    int array_sum = accumulate(nums.begin(), nums.end(), 0);
    cout << array_sum;
    if (find(nums.begin(), nums.end(), 0) == nums.end())
    {
        return 0;
    }
    if (first_n_number_sum - array_sum != 0)
    {
        return abs(first_n_number_sum - array_sum);
    }
    else
    {
        return *max_element(nums.begin(), nums.end()) + 1;
    }
}


//using xor
int missingNumber23(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main()
{
    vector<int> a = {1, 2, 4, 5};

    vector<int> unionResult = missing_number_1(a);

    // Print the union result - 1,2,3,4,5,6

    return 0;
}

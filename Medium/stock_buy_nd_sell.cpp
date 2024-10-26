#include<bits/stdc++.h>
using namespace std;

/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single 
day to buy one stock and choosing a different day in
 the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
buy on day 2 and sell on day 5
 */

//approach1 - take difference with each arr[i]-arr[j] should be greater than 0 and return max_diff

int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    for(int i=0;i<prices.size();i++){
        for(int j=i+1;j<prices.size();j++){
            max_profit= max(max_profit,prices[j]-prices[i]);
        }
    }
    
    return max_profit;
}

//approach2   -maintain a minimum and difference btween current elem and that min

int maxProfit2(vector<int> prices){
    int max_profit = 0;
    int min_price= prices[0];
    for(int i=1;i<prices.size();i++){
        min_price = min(min_price,prices[i]);
        max_profit = max(max_profit,prices[i]-min_price);
    }
    return max_profit;
}


int main(){
    vector<int> nums= {7,1,5,3,6,4};
    cout<<maxProfit2(nums);

}
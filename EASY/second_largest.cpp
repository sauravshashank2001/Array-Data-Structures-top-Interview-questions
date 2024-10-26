#include <bits/stdc++.h>
using namespace std;

//brute forcc- sort and return n-2 index element

 int getSecondLargest(vector<int> &arr) {
        
        int largest = arr[0];
        int second_largest =-1; 
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>largest){
                second_largest = largest;
                largest = arr[i];
            }
            else if(arr[i]<largest && arr[i]>second_largest){
                second_largest = arr[i];
            }
        }
        return second_largest;
    }

int main(){
    vector<int> arr={1,2,31,34,3};
    cout<<second_largest(arr);

}
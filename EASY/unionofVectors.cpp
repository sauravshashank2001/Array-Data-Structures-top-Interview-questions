//give unique elements present in two vectors

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        set<int> unique;
        for(int i =0; i<a.size();i++){
            unique.insert(a[i]);
        }
        for(int i =0; i<b.size();i++){
            unique.insert(b[i]);
        }
        vector<int> result(unique.begin(),unique.end());
        return result;
        
    }

int main() {
    vector<int> a = {1, 2, 4, 5};
    vector<int> b = {2, 3, 5, 6};

    vector<int> unionResult = findUnion(a, b);

    // Print the union result - 1,2,3,4,5,6
    for (int num : unionResult) {
        cout << num << " ";
    }

    return 0;
}

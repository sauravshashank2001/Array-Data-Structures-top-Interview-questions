//approach 1 - sort the array it will sort based on starting and ending interval 

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size(); // size of the array

    //sort the given intervals:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = intervals[i][0];
        int end = intervals[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (intervals[j][0] <= end) {//checking if it merges with previously merged interval
                end = max(end, intervals[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
    }


//approach 2- sort the intervals and check if next elem is merging with previously inserted
//interval yes merge else just push
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); // size of the array

    //sort the given intervals:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
            
        }
        else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
          
    }
    return ans;
    }
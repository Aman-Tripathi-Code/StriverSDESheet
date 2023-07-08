vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    /*
        -> We will take two variable start and end which will mark the starting and ending of a interval
        -> Now if the start time of an interval is less than the end variable we will merge intervals
        -> Else we get a interval and reassign the start and end to the start time and end time of 
            current interval
        -> TC -> O(N) SC -> O(1) no extra space other than answer
    */
    sort(intervals.begin(),intervals.end());
    int start = intervals[0][0], end = intervals[0][1];

    vector<vector<int>> ans;
    for(int i = 1; i<intervals.size(); i++){
        if(intervals[i][0] <= end){
            end = max(end,intervals[i][1]);
        }
        else{
            ans.push_back({start,end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    ans.push_back({start,end});
    return ans;
}

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

//O(N) TIME AND O(N) SPACE

 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newi) {
        int n = intervals.size(),i=0,k;
        vector<vector<int>> ans;
        while(i < n){
            if(intervals[i][1] >= newi[0]){
                if(intervals[i][0] > newi[0]){
                    if(intervals[i][1] > newi[1] && intervals[i][0] > newi[1]){
                        ans.emplace_back(newi);
                        k=i;
                        break;
                    }
                    intervals[i][0] = newi[0];
                }
                if(intervals[i][1] < newi[1]){
                k=i+1;
                while(k < n && intervals[k][1] < newi[1]  && intervals[k][0] < newi[1]){
                    k++;
                }
                
                if(k < n){
                    if(intervals[k][0] > newi[1]){
                        intervals[i][1] = newi[1];
                    }
                    else{
                         intervals[i][1] = intervals[k][1];
                        k++;
                    }
                }
                else{
                    intervals[i][1] = newi[1];
                }
                ans.emplace_back(intervals[i]);
                }
                break;
            }
            ans.emplace_back(intervals[i]);
            i++;
            k=i;
        }
        cout<<k;
        while(k < n){
            ans.emplace_back(intervals[k]);
            k++;
        }
        
        if(i==n){
            ans.emplace_back(newi);
        }
        
        return ans;
    }

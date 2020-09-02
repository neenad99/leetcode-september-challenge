/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/




 bool containsNearbyAlmostDuplicate(vector<int>& arr, int k, int t) {
        /*int n = arr.size();
        for(int i=0;i<n;i++){ // NAIVE O(N^2) time
            for(int j=i+1;j<n;j++){
                if(abs(i-j)<=k && abs(arr[i]-arr[j])<=t){
                    return true;
                }
            }
        }
        
        return false;*/
        set<long> s;   // USING SET O(NLOGK) TIME O(K) SPACE
        int n = arr.size();
        long temp;
        for(int i=0;i<n;i++){
            temp = arr[i];
            if(i>k){
                s.erase(arr[i-k-1]);
            }
            
            auto j = s.lower_bound(temp-t);
            
            if(j!=s.end() && (*j - temp) <= t){
                return true;
            }
            
            s.insert(arr[i]);
        }
        
        
        return false;
    }
        
        
   

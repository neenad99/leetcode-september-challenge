/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.
*/


 int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            while(nums[i] > 0 && nums[i] <= n && nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1]){
                    break;
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans = i+1;
                break;
            }
        }
        
        if(ans==-1){
            return n+1;
        }
        
        return ans;
    }

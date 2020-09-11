/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long lp=1,rp=1,maxprod=INT_MIN;
        int left=0,right=n-1;
        while(left < n && right >= 0){
            lp*=nums[left++];
            rp*=nums[right--];
            maxprod = max(maxprod,max(lp,rp));
            if(lp==0){
                lp=1;
            }
            if(rp==0){
                rp=1;
            }
        }
        
        return (int)maxprod;
    }

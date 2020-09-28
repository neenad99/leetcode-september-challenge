/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/
 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       /* int n=nums.size(),currp,count=0;
        
        for(int i=0;i<n;i++){  // BRUTE FORCE O(N^2) TIME O(1) SPACE
            currp=1;
            for(int j=i;j<n;j++){
                currp*=nums[j];
                if(currp >=k){
                    break;
                }
                else{
                    count++;
                }
            }
        }
        
        
        return count;*/
        if(k <= 1){  // USING SLIDING WINDOW APPROACH O(N) TIME O(1) SPACE
            return 0;
        }
        int start=0,end=0,currp=1,count=0,n=nums.size();
        
        while(end < n){
            currp*=nums[end];
            while(currp >=k){
                currp/=nums[start];
                start++;
            }
            count+=end-start+1;
            end++;
        }
        
        
        return count;
    }
 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       /* int n=nums.size(),currp,count=0;
        
        for(int i=0;i<n;i++){  // BRUTE FORCE O(N^2) TIME O(1) SPACE
            currp=1;
            for(int j=i;j<n;j++){
                currp*=nums[j];
                if(currp >=k){
                    break;
                }
                else{
                    count++;
                }
            }
        }
        
        
        return count;*/
        if(k <= 1){
            return 0;
        }
        int start=0,end=0,currp=1,count=0,n=nums.size();
        
        while(end < n){
            currp*=nums[end];
            while(currp >=k){
                currp/=nums[start];
                start++;
            }
            count+=end-start+1;
            end++;
        }
        
        
        return count;
    }

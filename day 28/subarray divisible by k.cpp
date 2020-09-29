/*
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/

 int subarraysDivByK(vector<int>& arr, int k) {
      /*  int n=arr.size(),count=0,curr;  // BRUTE FORCE O(N^2) TIME
        for(int i=0;i<n;i++){
            curr=0;
            for(int j=i;j<n;j++){
                curr+=arr[j];
                if(curr%k==0){
                    count++;
                }
            }
        }
        
        
        return count;*/
        // USING PREFIX SUM CONCEPT AND USING MAP OR ARRAY TO STORE THE PREFIX SUM
        //O(N) TIME O(N) OR O(K) SPACE
        int n=arr.size(),count=0,curr=0;
       // unordered_map<int,int> m;
        vector<int> m(k);
        m[0] = 1;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            count+=m[((curr%k)+k)%k];
            m[((curr%k)+k)%k]++;
        }
        
        return count;
    }

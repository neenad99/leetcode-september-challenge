/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.
Example 1:
Input: [3,2,3]
Output: [3]
Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

vector<int> majorityElement(vector<int>& nums) {
        //using hash map O(N) time O(N) space
       /* int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        nums.clear();
        for(auto j:m){
            if(j.second > n/3){
                nums.emplace_back(j.first);
            }
        }
        
        return nums;*/
        //MOORE VOTING ALGO O(N) TIME O(1) SPACE
         int n=nums.size(),c1=0,c2=0;
        long long a = INT_MAX,b=INT_MAX;
        a++,b++;
        for(int num:nums){
            if(a==num){
                 c1++;
            }
            else if(b==num){
                c2++;
            }
            else if(c1==0){
                a = num;
                c1++;
            }
            else if(c2==0){
                b = num;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int n:nums){
            if(n==a){
                c1++;
            }
            if(n==b){
                c2++;
            }
        }
        vector<int> ans;
        
        if(c1 > n/3){
            ans.push_back(a);
        }
        if(c2 > n/3){
            ans.push_back(b);
        }
        
        return ans;
        
    }

/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
*/

 static bool compare(string &a,string &b){
        string res1 = a + b;
        string res2 = b + a;
        
        return res1 > res2 ? true : false;
    }
    
    
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);
        string ans;
        for(int i=0;i<n;i++){
            arr[i] = to_string(nums[i]);
        }
        
        sort(arr.begin(),arr.end(),(compare));
        if(arr[0]=="0"){
            return "0";
        }
        
        for(int i=0;i<n;i++){
            ans+=arr[i];
        }
        
        
        return ans;
    }

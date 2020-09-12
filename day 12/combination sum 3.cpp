/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

//USE THE CONCEPT OF SUBSET GENERATION OF THE ARRAY KEEPING TRACK OF LENGTH OF SUBSET SHOULD BE K AND KEEP SUM VARIABLE TO KEEP TRACK OF SUM OF KTH LENGTH SUBSET WHICH SHOULD BE N

int sum=0;
    void generatecomb(int arr[],vector<vector<int>> &ans,vector<int> &temp,int &n,int &k,int index){
        if(temp.size()==k && sum==n){
            ans.emplace_back(temp);
        }
       if(index>=9){
           return ;
       }
        
        for(int i=index;i<9;i++){
            temp.emplace_back(arr[i]);
            sum+=arr[i];
            generatecomb(arr,ans,temp,n,k,i+1);
            temp.pop_back();
            sum-=arr[i];
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        int arr[9];
        for(int i=0;i<9;i++){
            arr[i] = i+1;
        }
        
        generatecomb(arr,ans,temp,n,k,0);
        
        return ans;
    }

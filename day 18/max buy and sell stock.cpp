/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/


int maxProfit(vector<int>& arr) {
        int n = arr.size(),minprice=INT_MAX,maxprofit=INT_MIN;
        if(n==0 || n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr[i] <= arr[i+1]){
                    minprice=arr[i];
                }
            }
            else if(i==n-1){
                if(arr[i] >= arr[i-1] && minprice!=INT_MAX){
                    maxprofit = max(maxprofit,arr[i]-minprice);
                }
            }
            else{
                if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1] && minprice!=INT_MAX){
                    maxprofit = max(maxprofit,arr[i]-minprice);
                }
                if(arr[i] <= arr[i-1] && arr[i] <= arr[i+1]){
                    minprice = min(minprice,arr[i]);
                }
            }
        }
        
        return maxprofit==INT_MIN ? 0 : maxprofit;
    }

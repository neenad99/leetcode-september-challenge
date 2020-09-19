/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/

 void digitgen(unordered_set<int> &s,int &low,int &high,int i,int num){
        if(num > high || i > 10){
            return ;
        }
        if(num>=low && num <=high){
            s.insert(num);
        }
        for(int j=i;j<=9;j++){
            if(num%10 + 1 == j){
                int temp = num*10 + j;
                digitgen(s,low,high,j+1,temp);
            }
            else{
                digitgen(s,low,high,j+1,j);
            }
        }
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        unordered_set<int> s;
        digitgen(s,low,high,1,0);
        
        for(auto j=s.begin();j!=s.end();j++){
            ans.emplace_back(*j);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }

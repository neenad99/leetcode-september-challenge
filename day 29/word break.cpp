class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        unordered_set<string> set;
        for(string &i:dict){
            set.insert(i);
        }
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(set.find(s.substr(j,i-j))!=set.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        
        
        return dp[n];
    }
};

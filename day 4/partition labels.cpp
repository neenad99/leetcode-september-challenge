/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less part
S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

 vector<int> partitionLabels(string s) {
        int n=s.length(),maxpos=0,start=-1;
        vector<int> ans;
        int last[26];
        for(int i=0;i<26;i++){
            last[i] = -1;
        }
        
        for(int i=n-1;i>=0;i--){
            if(last[s[i]-'a']==-1){
                last[s[i]-'a'] = i;
            }
        }
      
        maxpos = last[s[0]-'a'];
       
        for(int i=0;i<n;i++){
            if(last[s[i]-'a'] > maxpos){
                maxpos = last[s[i]-'a'];
            }
            if(i==maxpos){
                ans.emplace_back(i-start);
                start=i;
            }
        }
        
        
        return ans;
    }

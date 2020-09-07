/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pat, string str) {
        int n=str.length(),m=pat.length(),spaces=0;
        for(int i=0;i<n;i++){
            if(str[i]==' '){
                spaces++;
            }
        }
        if(spaces!=m-1){
            return false;
        }
        unordered_map<string,char> m1;
        vector<int> count(26);
        int ind=0;
        string temp;
        
        for(int i=0;i<m;i++){
            while(ind < n && str[ind]!=' '){
                temp+=str[ind++];
            }
            ind++;
            auto j=m1.find(temp);
            if(j!=m1.end() && count[pat[i]-'a']==0){
                return false;
            }
            else if(j==m1.end() && count[pat[i]-'a']==1){
                return false;
            }
            else if(j!=m1.end() && count[pat[i]-'a']==1){
                if(m1[temp]!=pat[i]){
                    return false;
                }
            }
            count[pat[i]-'a']=1;
            m1[temp]=pat[i];
            temp="";
        }
        
       
        
        return true;
    }
};

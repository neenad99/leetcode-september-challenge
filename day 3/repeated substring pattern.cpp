/*

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

 bool repeatedSubstringPattern(string s) {
        int n=s.length(),m,j,k;
        string pat;
        for(int i=0;i<(n/2);i++){
            pat+=s[i];
            m = pat.length();
            if(n%m==0){
                k=0;
                for(j=i+1;j<n;j++){
                    if(s[j]!=pat[k%m]){
                        break;
                    }
                    k++;
                }
                if(j==n){
                    return true;
                }
            }
        }
        
        
        
        return false;
    }

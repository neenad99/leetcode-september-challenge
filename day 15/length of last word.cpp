/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/


int lengthOfLastWord(string s) {
        int n=s.length(),length=0,lastlength=0;
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(length > 0 && s[i]==' '){
                lastlength=length;
                length=0;
            }
            else if(s[i]!=' '){
                length++;
            }
        }
        
        if(length > 0){
            lastlength = length;
        }
        
        
        return lastlength;
    }
    
    def lengthOfLastWord(self, s: str) -> int:
        arr = s.split()
        if(len(arr)==0):
            return 0
        return len(arr[len(arr)-1])
        

/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
*/

/*int binarytoint(string num){
        int n=num.length();
        int ans=0,power=0;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='1'){
                ans+=(1<<power);
            }
            power++;
        }
       
        return ans;
    }*/
    
    void dfs(TreeNode* root,int num,int &total){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            num = (num << 1) | root->val;
            total+=num;
            return ;
        }
        num = (num << 1) | root->val;
        dfs(root->left,num,total);
        dfs(root->right,num,total);
        
    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        int total=0;
        dfs(root,0,total);
            
        return total; 
    }

/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20
*/


void dfs(vector<vector<int>> &grid,int nonobj,int &count,int i,int j){
        if(i>=0 && j>=0 && i< grid.size() && j<grid[i].size()){
            if(grid[i][j]==2 && nonobj==1){
                count++;
                return ;
            }
            if(grid[i][j] < 0){
                return ;
            }
            int temp = grid[i][j];
            grid[i][j] = -2;
           // nonobj--;
            dfs(grid,nonobj-1,count,i-1,j);
            dfs(grid,nonobj-1,count,i,j-1);
            dfs(grid,nonobj-1,count,i+1,j);
            dfs(grid,nonobj-1,count,i,j+1);
            grid[i][j] = temp;
            
        }
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int count=0,startr,startc,nonobj=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    startc=j;
                    startr=i;
                }
                if(grid[i][j]>=0){
                    nonobj++;
                }
            }
        }
       // cout<<nonobj;
        dfs(grid,nonobj,count,startr,startc);
        
        return count;
    }

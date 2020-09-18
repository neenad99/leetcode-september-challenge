/*
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
*/

 bool isRobotBounded(string s) {
        int n=s.length(),x=0,y=0,j=0;
        vector<vector<int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                j = (j+1)%4;
            }
            else if(s[i]=='L'){
                j = (j+3)%4;
            }
            else{
                x+=d[j][0];
                y+=d[j][1];
            }
        }
        
        return x==0 && y==0 || j > 0;
    }

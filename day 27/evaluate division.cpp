/*
You are given equations in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating-point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= equations[i][0], equations[i][1] <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= queries[i][0], queries[i][1] <= 5
equations[i][0], equations[i][1], queries[i][0], queries[i][1] consist of lower case English letters and digits.
*/


// A GOOD PROBLEM THAT STRENGTHENS THE CONCEPT OF GRAPH AND ITS APLICATION IN THIS QUESTION

/*
Binary relationship is represented as a graph usually.
Does the direction of an edge matters? -- Yes. Take a / b = 2 for example, it indicates a --2--> b as well as b --1/2--> a.
Thus, it is a directed weighted graph.
In this graph, how do we evaluate division?
Take a / b = 2, b / c = 3, a / c = ? for example,

a --2--> b --3--> c
We simply find a path using DFS from node a to node c and multiply the weights of edges passed, i.e. 2 * 3 = 6.


FIRST BUILD GRAPH USING EQUATIONS AND VALUES GIVEN THEN PROCESS EACH QUERY AND TO FIND VALUE CHECK IF MAP CONTAINS DIRECT ANSWER ACC TO QUERY OR IF THE ANSWER TO QUERTY IS A PRODUCT THEN WE TRAVERSE THE GRAPH USING DFS AND MULTIPLY EACH WEIGHT TO GET ANSWER
*/
  unordered_map<string,unordered_map<string,double>> buildgraph(vector<vector<string>>& equ, vector<double>& val){
         unordered_map<string,unordered_map<string,double>> adj;
        int n=equ.size();
        for(int i=0;i<n;i++){
            adj[equ[i][0]][equ[i][1]] = val[i];
            adj[equ[i][1]][equ[i][0]] = 1/val[i];
        }
        
        return adj;
    }
    double getweight(unordered_map<string,unordered_map<string,double>> &graph,set<string> &vis,string a,string b){
        if(graph.find(a)==graph.end()){
            return -1;
        }
        if(a==b){
            return 1;
        }
        if(graph[a].find(b)!=graph[a].end()){
            //cout<<graph[a][b]<<" ";
            return graph[a][b];
        }
        
        vis.insert(a);
        
        for(auto j=graph[a].begin();j!=graph[a].end();j++){
            if(vis.find(j->first)==vis.end()){
                double res = getweight(graph,vis,j->first,b);
                if(res!=-1.0){
                    return res*j->second;
                }
            }
        }
        
        return -1.0;
    }    
        
        
        
    vector<double> calcEquation(vector<vector<string>>& equ, vector<double>& val, vector<vector<string>>& q) {
       unordered_map<string,unordered_map<string,double>> graph = buildgraph(equ,val);
        int n = q.size();
        vector<double> ans(n);
        set<string> vis;
        for(int i=0;i<n;i++){
            ans[i] = getweight(graph,vis,q[i][0],q[i][1]);
            vis.clear();
        }
        
        
        return ans;
    }

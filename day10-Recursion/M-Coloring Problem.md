[Link](https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#)
# M-Coloring Problem
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
```
Example 1:
Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.

Example 2:
Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0
```
## Solution :: BackTrack
Time Complexity: O( N<sup>M</sup> )<br>
Space Complexity: O(N)
```cpp
class Solution{
    int N;
    bool ispossible(int node, bool graph[101][101],vector<int>& color,int col){
        for(int k=0;k<N;k++)
            if(graph[node][k]==1 && color[k]==col)
                return 0;
        return 1;
    }
    bool fun(int node,int m,bool graph[101][101],vector<int>& color){
        if(node==N)
            return 1;
        for(int col=1;col<=m;col++)
            if(ispossible(node,graph,color,col)){
                color[node]=col;
                if(fun(node+1,m,graph,color))
                    return 1;
                else 
                    color[node]=0;
            }
        
        //tried all possible colors, butt couldnt find so returning false
        return 0;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        N=n;
        vector<int> color(n,0);
        if(fun(0,m,graph,color))
            return 1;
        return 0;
    }
};
```

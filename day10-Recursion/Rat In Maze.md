[Link](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)
# Rat in a Maze Problem
```
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
```
## Solution :: Backtrack
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.<br>
Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree
```cpp
class Solution{
    vector<string> ans;
    int n;
    void solve(vector<vector<int>> &a,int i,int j,string s){
        if(i<0||i>=n || j<0||j>=n || a[i][j]!=1)return;
        if(i==n-1&&j==n-1){
            ans.push_back(s);
            return;
        }
        a[i][j]=-1;
        solve(a,i+1,j,s+'D');
        solve(a,i,j+1,s+'R');
        solve(a,i-1,j,s+'U');
        solve(a,i,j-1,s+'L');
        a[i][j]=1;
    }
   public:
   vector<string> findPath(vector<vector<int>> &m, int n) {
       // Your code goes here
        string temp="";
        this->n=n;
        solve(m,0,0,temp);
        return ans;
   }
};
```
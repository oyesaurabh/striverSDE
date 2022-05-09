[question link](https://leetcode.com/problems/unique-paths/)

# unique paths

## Problem Statements
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

![image](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)<br>
Example 1:
Input: m = 3, n = 7
Output: 28

## Approach 1 ( recursion ) 
Time Complexity: O(2<sup>N</sup>) i.e. exexponential
Space Complexity: O(2<sup>N</sup>) as we are using stack

```cpp
    int find(int i,int j,int m,int n){
        if(i==m-1 || j==n-1)return 1;
        return find(i+1,j,m,n)+find(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return find(0,0,m,n);
    }
```

## Approach 2 ( DP ) 
Time Complexity: O(N\*M) 
Space Complexity: O(N\*M)

```cpp
    int find(int i,int j,vector<vector<int>>& a){
        if(i==m-1 || j==n-1)return 1;
        if(a[i][j]>0)return a[i][j];
        a[i][j]=find(i+1,j,a)+find(i,j+1,a);
        return a[i][j];
    }
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        vector<vector<int>> dp(m,vector<int>(n,0));
        return find(0,0,dp);
    }
```

## Approach 3 ( Combinatorics Solution ) 
Time Complexity: O(n-1) ||  O(m-1) 
Space Complexity: O(1) 

```cpp
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
```
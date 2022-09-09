[Link](https://leetcode.com/problems/rotting-oranges/)
# Rotting Oranges
You are given an m x n grid where each cell can have one of three values:
```
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
```

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.<br>

Example 1:<br>
![img](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)
```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```
## Solution  :: BFS
Time Complexity: O ( n x n ) x 4<br>
Space Complexity: O ( n x n )<br>
```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        queue<pair<int,int>> q;
        int fresh=0;
        int n=a.size(), m=a[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]==2)  q.push({i,j});
                else if(a[i][j]==1)  fresh++;
        
        
        int time=0;
        int dir[]={-1,0,1,0,-1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx=dir[i]+x, newy=dir[i+1]+y;
                    if(newx<0 || newx>=n || newy<0 || newy>=m || a[newx][newy]!=1)continue;
                    a[newx][newy]=2;
                    fresh--;
                    q.push({newx, newy});
                }
            }
            time++;
        }
        
        
        if(fresh>0)return -1;
        return time==0?0:time-1; //time cant be -ve 
    }
};
```
[Link](https://leetcode.com/problems/n-queens/)<br>
# N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.<br>
![img](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```
## Solution :: BackTrack
Time Complexity: O(N!).<br>
Space Complexity: O(N)
```cpp
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return ans;
    }
    void solve(vector<string> &board,int row){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<board.size();j++){
            if(issafe(board,row,j)==false)continue;
            board[row][j]='Q';
            solve(board,row+1);
            board[row][j]='.';
        }
    }
    bool issafe(vector<string>& board,int row,int col){
        int n=board.size();
        //col checking
        for(int i=0;i<row;i++)
            if(board[i][col]=='Q')return 0;
        //left diagonal
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if(board[i][j]=='Q')return 0;
        //right diagonal
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
            if(board[i][j]=='Q')return 0;
        return 1;
    }
};
```
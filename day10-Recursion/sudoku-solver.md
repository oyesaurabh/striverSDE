[Link](https://leetcode.com/problems/sudoku-solver/)
# sudoku-solver
Write a program to solve a Sudoku puzzle by filling the empty cells.<br>
![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
```
Input: 
board = [["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]]

Output: [["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
```
![img](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

## Solution :: BackTrack
Time Complexity: O(9<sup>(n<sup>2</sup>)</sup>), in the worst case, for each cell in the n2 board, we have 9 possible numbers.<br>
Space Complexity: O(1)
```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& a) {
        solve(a);
    }
private:
    bool solve(vector<vector<char>> &a){
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if (a[i][j] != '.') continue;
                for(char c='1';c<='9';c++){
                    if(isSafe(a,i,j,c)){
                        a[i][j]=c;
                        if(solve(a)==true)  return true;
                        else    a[i][j]='.'; //backtrack   
                    }
                }
                
                return false; //we tried all numbers form 1 to 9... but none satisfied any condition so return false
            }
        return 1;// at last, we have filled all the elements so returning true
    }
    bool isSafe(vector<vector<char>>& a,int row,int col,char c){
        int blkrow = (row / 3) * 3, blkcol = (col / 3) * 3; // Block no. is i/3, first element is i/3*3
        for (int i = 0; i < 9; i++)
            if (a[i][col] == c || a[row][i] == c || 
                    a[blkrow + i / 3][blkcol + i % 3] == c)
                return false;
          return true;
    }
};
```
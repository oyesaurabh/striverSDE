[Question link](https://leetcode.com/problems/pascals-triangle/)
# Pascal's triangle

![Pascal's triangle](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

## Problem 1 (Leetcode)

Given an integer numRows, return the first numRows of Pascal's triangle.

## Solution

Time complexity : O(N\*N)  
Space complexity : O(N\*N)

```cpp
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
        res.push_back({1});
        for(int i=1; i<numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0; j<i-1; j++){
                temp.push_back(res[i-1][j]+res[i-1][j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
``` 

## Problem 2

Given row no. and column no. in a pascal triangle, find element in that position.

### Formula

r = row, c = col  
Element = <sup>r-1</sup>C<sub>c-1</sub>

## Solution

Time complexity : O(N)  
Space complexity : O(1)

```cpp
    int getPascalElement(int row, int col) {
        int res=1;
        for(int j=1; j<col; j++)
            res *= --row;
        while(--col) res /= col;
        return res;
    }
```

## Problem 3

Given row number, return that whole row

## Solution

Time complexity : O(N)  
Space complexity : O(N)

```cpp
    vector<int> getRow(int row) {
        // row++ if index starts from 0
        int n = row;
        vector<int> res(n);
        res[0] = res[n-1] = 1;
        long long int numerator = 1, denominator=1;
        for(int col=1; col<n-1; col++) {
            numerator *= (--row);
            denominator *= (col);
            res[col] = (numerator/denominator);
        }
        return res;
    }
```
int overflow in leetcode so..
Time complexity : O(N\*n)  
Space complexity : O(N)
``` cpp

    vector<int> getRow(int row) {
        // row++ if index starts from 0
        vector<int> A(row, 0);
        A[0] = 1;
        for(int i=1; i<row; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
```
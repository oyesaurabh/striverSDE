[Question Link](https://leetcode.com/problems/search-a-2d-matrix/)

# Search a 2D Matrix

## Problem statement
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
![for Example ](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

## Approach 1 ( Naive Approach )

Time complexity : O(N \* M)  
Space complexity : O(1)

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(auto it:matrix)
        for(auto i:it)
            if(i==target)return 1;

    return 0;
}

```
## Approach 2 ( BS )

Time complexity : O(log (N \* M) )  
Space complexity : O(1)

```cpp
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int i=0,j=m-1;
        // while(i<n && j>=0){
        //     if(matrix[i][j] > target)
        //         j--;
        //     else if(matrix[i][j] < target)
        //         i++;
        //     else return 1;
        // }
        // return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(matrix[mid/m][mid%m] > target)
                high=mid-1;
            else if(matrix[mid/m][mid%m] < target)
                low=mid+1;
            else 
                return 1;
        }
        return 0;
    }
```


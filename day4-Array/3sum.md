[Question LInk](https://leetcode.com/problems/3sum/)

# 3 SUM

## Problem
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

>Example 1:
>Input: nums = [-1,0,1,2,-1,-4]
>Output: [[-1,-1,2],[-1,0,1]]


## Approach 1:
time: O(N\*N)
space: O(N)
```cpp
    vector<vector<int>> threeSum(vector<int>& a) {
        sort( a.begin(),a.end() );
        vector<vector<int>> ans;
        int n=a.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || i>0&&a[i]!=a[i-1]){    
                int low=i+1;
                int high=n-1;
                while(low<high){
                    int s=a[i]+a[low]+a[high];
                    if(s==0){
                        ans.push_back( {a[i],a[low],a[high]} );
                        while(low<high && a[low]==a[low+1])low++;
                        while(low<high && a[high]==a[high-1])high--;
                        low++;high--;
                    }
                    else if(s>0)
                        high--;
                    else 
                        low++;
                }
            }
        }
        return ans;
    }
```
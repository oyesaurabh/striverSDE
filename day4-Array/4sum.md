[Question LInk](https://leetcode.com/problems/4sum/)

# 4 SUM

## Problem
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

```
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```


## Approach 1 (Using 3 pointers and Binary Search):
![](https://lh5.googleusercontent.com/FSMH98BnMlFnsvLQhThALsuRfnQON31KgaDKS7rxBC6I9gu5GB0PzrhczZYB_1bR5DZHgm2wK5iiQXtrqk7ZqylQII4GtQj0x68INvp9uNVWlp0tZLsq8Y4O6cHv0-kumGt5gkw)
time: O(N log N + N³ logN)
space:  O(M * 4), where M is the number of quads
```cpp
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
      
        set<vector<int>> sv;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {      
                   int x = target-nums[i]-nums[j]-nums[k];     
                        if(binary_search(nums.begin()+k+1,nums.end(),x)){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(x);
                            sv.insert(v);
                        }
                }
            }
        }
        vector<vector<int>> res(sv.begin(),sv.end());
        return res;
    }
```
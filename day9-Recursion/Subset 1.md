[Link](https://leetcode.com/problems/subsets/)
# Subset / powerset / subsequence
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```
## Recursive
```cpp
class Solution {
    vector<vector<int>> ans;
public:
    void sub(vector<int> &a,int i,vector<int> temp){
        if(i==a.size()){
            ans.push_back(temp);
            return;
        }
        sub(a,i+1,temp); //ignore
        temp.push_back(a[i]);
        sub(a,i+1,temp); //take

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sub(nums,0,temp);
        return ans;
    }
};
```

## Bits 
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){ //pow(2,n)
            vector<int> t;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    t.push_back(nums[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
```
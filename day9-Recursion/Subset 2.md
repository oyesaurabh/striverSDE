[Link](https://leetcode.com/problems/subsets-ii/)
#  Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).<br>

***The solution set must not contain duplicate subsets. Return the solution in any order.***
```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```
## 1. Solution : using Set

```cpp
class Solution {
    set<vector<int>> set;
    void sub(vector<int>& a,int i,vector<int> temp){
        if(i==a.size()){
            sort(temp.begin(), temp.end());
            set.insert(temp);
            return;
        }
        sub(a,i+1,temp);
        temp.push_back(a[i]);
        sub(a,i+1,temp);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sub(nums,0,temp);
        vector<vector<int>> ans(set.begin(), set.end());
        return ans;
    }
};
```
## 2. Solution more optimized
```cpp
class Solution {
    vector<vector<int>> ans;
    void sub(vector<int>& a,int i,vector<int> temp){
        if(i==a.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(a[i]);
        sub(a,i+1,temp);
        temp.pop_back();
        
        while(i+1 < a.size() && a[i]==a[i+1])
            i++;
        sub(a,i+1,temp);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        sub(nums,0,temp);
        return ans;
    }
};
```
### OR
```cpp
class Solution {
    vector<vector<int>> ans;
    void sub(vector<int>& a,int ind,vector<int> temp){
        ans.push_back(temp);
        for(int i=ind;i<a.size();i++){
            if(i!=ind && a[i]==a[i-1])continue;
            temp.push_back(a[i]);
            sub(a,i+1,temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        sub(nums,0,temp);
        return ans;
    }
};
```
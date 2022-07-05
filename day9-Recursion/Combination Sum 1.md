[Link](https://leetcode.com/problems/combination-sum/)

# Combination Sum 1
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 

You may return the combinations in any order.
```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```
## Solution 
```cpp
class Solution {
    vector<vector<int>> ans;
    int n;
    void fun(vector<int>& a, vector<int> temp, int ind,int t){
        if(t==0){
            ans.push_back(temp);return;
        }
        if(t<0)return;
        for(int i=ind;i<n;i++){
            if(t<a[i])continue;
            temp.push_back(a[i]);
            fun(a,temp,i,t-a[i]);   
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<int> temp;
        n=a.size();
        fun(a,temp,0,t);
        return ans;
    }
};
```

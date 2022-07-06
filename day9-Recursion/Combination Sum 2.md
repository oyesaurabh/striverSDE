[Link](https://leetcode.com/problems/combination-sum-ii/submissions/)
# Combination Sum 2
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```
## Solution 
```cpp
class Solution {
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& a,int target,vector<int> temp,int ind){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        // if(target < 0)return;
        for(int i=ind;i<n;i++){
            if(i!=ind && a[i]==a[i-1])continue;
            if(a[i]>target)return;
            temp.push_back(a[i]);
            solve(a,target-a[i],temp,i+1);
            temp.pop_back();
        }
    } 
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        if(a.empty())return {}; 
        sort(a.begin(), a.end());
        n=a.size();
        vector<int> temp;
        solve(a,t,temp,0);
        return ans;
    }
};
```
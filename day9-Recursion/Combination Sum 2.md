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
```
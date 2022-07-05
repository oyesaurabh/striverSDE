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
    int l;
public:
    void fun(vector<int>& a,vector<int>& temp,int ind,int t){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(t<0)return;
        for(int i=ind;i<l;i++){
            if (i > ind && a[i] == a[i-1]) continue; //checking the previous number
            // if its equal then ignore them...      
            temp.push_back(a[i]);
            fun(a,temp,i+1,t-a[i]);                            
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        l=a.size();
        sort(a.begin(),a.end());
        vector<int> temp;
        fun(a,temp,0,t);
        return ans;
    }
};
```
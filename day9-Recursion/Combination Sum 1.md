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
    void solve(vector<int>& a,int target,vector<int> temp,int ind){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        // if(target < 0)return;
        for(int i=ind;i<n;i++){
            // if(i!=ind && a[i]==a[i-1])continue; add this for combination sum II question
            if(a[i]>target)return;
            temp.push_back(a[i]);
            solve(a,target-a[i],temp,i);
            temp.pop_back();
        }
    } 
public:
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        if(a.empty())return {}; 
        sort(a.begin(), a.end());
        n=a.size();
        vector<int> temp;
        solve(a,t,temp,0);
        return ans;
    }
};
```

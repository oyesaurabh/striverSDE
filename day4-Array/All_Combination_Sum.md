[Combination Sum 1](https://leetcode.com/problems/combination-sum/)<br>
[Combination Sum 2](https://leetcode.com/problems/combination-sum-ii/)<br>
[Combination Sum 3](https://leetcode.com/problems/combination-sum-iii/)
# Combination Sum

## Combination Sum 1:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
```
Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
```

## Solution

```cpp
    vector<vector<int>> ans;
    int l;
    void fun(vector<int>& a, vector<int> &temp,int ind,int t){
        if(t==0){
            ans.push_back(temp);return;
        }
        if(t<0)return;
        for(int i=ind;i<l;i++){
            if(t<a[i])continue;
            temp.push_back(a[i]);
            fun(a,temp,i,t-a[i]);   
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        // sort(a.begin(),a.end());
        vector<int> t;
        l=a.size();
        fun(a,t,0,target);
        return ans;
    }
```

## Combination Sum 2
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
```
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [ [1,1,6], [1,2,5], [1,7], [2,6] ]
```
```cpp
    vector<vector<int>> ans;
    int l; 
    void fun(vector<int>& a,vector<int>& temp,int ind,int t){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(t<0)return;
        for(int i=ind;i<l;i++){
            if (i > ind && a[i] == a[i-1]) continue;          
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
```
## Combination Sum 3
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
```
Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
```
```cpp
    vector<vector<int>> ans;
    void help(vector<int>& t,int k,int n,int ind){
        if(n==0 && t.size()==k){
            ans.push_back(t);
            return;
        }
        if(n<0)return;
        for(int i=ind;i<=9;i++){
            if(i>n)return;
            t.push_back(i);
            help(t,k,n-i,i+1);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        help(t,k,n,1);
        return ans;
    }
```

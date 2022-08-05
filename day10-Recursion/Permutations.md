[Link](https://leetcode.com/problems/permutations/)
# Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
```
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
```
## BackTracking
Time Complexity: O(N!)<br>
Space Complexity: O(1)
```cpp
class Solution {
    int n;
    vector<vector<int>> ans;
    void solve(vector<int>& a,int begin){
        if(begin==n){
            ans.push_back(a);
            return;
        }
        for(int i=begin;i<n;i++){
            swap(a[i],a[begin]);//doing things
            solve(a,begin+1);
            swap(a[i],a[begin]);//backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& a) {
        n=a.size();
        solve(a,0);
        return ans;
    }
};
```
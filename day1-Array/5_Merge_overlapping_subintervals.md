[Question link](https://leetcode.com/problems/merge-intervals/)
# Merge overlapping subintervals

## Problem statement

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

## Approach 1 [ O(N^2) ]

```cpp
vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        if(!n)return ans;

        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            vector<int> t=a[i];
            if(!ans.empty() && t[0]<=ans.back()[1])continue;
            for(int j=i+1;j<n;j++){
                if(t[1]>=a[j][0])
                    t[1]=max(a[j][1],t[1]);
                else 
                    break;
            }
            ans.push_back(t);
        }
        return ans;
    }
```

## Approach 2 [ O(N\*log(N)) ]

```cpp
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        if(!n)return ans;

        sort(a.begin(),a.end());
        ans.push_back(a[0]);
        for(int i=1;i<;i++){
            if(a[i][0]<=ans.back()[1])
                ans.back()[1]=max(ans.back()[1],a[i][1]);
            else 
                ans.push_back(a[i]);
        }

        return ans;
    }
```
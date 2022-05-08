[Question Link](https://leetcode.com/problems/majority-element-ii/)

# Majority Element II

## Problem statement
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

## Approach 1 ( Brute-Force )
Time Complexity: O(N\*N)
Space Complexity: O(1)

```cpp
 vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans;
    for(int i=0;i<n-1;i++){
        int s=0;
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j])s++;
        }
        if(s>n/3)ans.push_back(nums[i]);
    }   
    return ans;
    }
```
## Approach 1 ( HashMap )
Time Complexity: O(N)
Space Complexity: O(N)

```cpp
    vector<int> majorityElement(vector<int>& nums) {
        int t=nums.size()/3;
        unordered_map<int,int> m;
        for(auto i:nums)m[i]++;
        vector<int> ans;
        for(auto i:m){
            if(i.second>t)ans.push_back(i.first);
        }
        return ans;
    }
```

### Approach 3 ( Extended Boyer Moore’s Voting Algorithm )
Time Complexity: O(N)
Space Complexity: O(1)

```cpp
    vector<int> majorityElement(vector<int>& a) {
        //     Boyer Moore’s Voting Algorithm
        int num1=-1,num2=-1,c1=0,c2=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i] == num1)
                c1++;
            else if(a[i] == num2)
                c2++;
            else if(c1==0)
                num1=a[i],c1=1;
            else if(c2==0)
                num2=a[i],c2=1;
            else
                c1--,c2--;
            
        }
        vector<int> ans;
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(a[i]==num1)
                c1++;
            else if(a[i]==num2)
                c2++;
        }
        if(c1>n/3)
            ans.push_back(num1);
        if(c2>n/3)
            ans.push_back(num2);
        return ans;
    }


```

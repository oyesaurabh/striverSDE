[Question link](https://leetcode.com/problems/maximum-subarray/)

# Maximum subarray sum

## Problem statement

Given an integer array nums, find the
subarray
with the largest sum, and return its sum.

Example 1:

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

Example 2:

```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

Example 3:

```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

## Approach 1 [ O(N^3) ]

```cpp
int maxSubArray(vector<int>& nums) {
    int n = nums.size(), res=nums[0];
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = 0;
            for(int k=i; k<=j; k++)
                sum+=nums[k];
            res = max(res, sum);
        }
    }
    return res;
}
```

## Approach 2 [ O(N^2) ]

```cpp
int maxSubArray(vector<int>& nums) {
    int n = nums.size(), res=nums[0];
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            res = max(res, sum);
        }
    }
    return res;
}
```

## Approach 3 [ O(N) ] -> Kadane's algorithm

```cpp
int maxSubArray(vector<int>& nums) {
        int sum,t;
        sum=t=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum<0)sum=nums[i];
            else sum+=nums[i];

            t=max(t,sum);
        }
        return t;
}
```

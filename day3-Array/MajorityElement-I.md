[Question Link](https://leetcode.com/problems/majority-element/)

# Majority Element

## Problem statement
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

>Example 1:
>Input: nums = [3,2,3]
>Output: 3

## Approach 1 ( Naive Approach )
Time Complexity: O(N\*N)
Space Complexity: O(1)

Check the count of occurrences of all elements of the array one by one. Start from the first element of the array and count the number of times it occurs in the array. If the count is greater than the floor of N/2 then return that element as the answer. If not, proceed with the next element in the array and repeat the process.

## Approach 2 ( using hashmap )
Time Complexity: O(N)
Space Complexity: O(N)

```cpp
int majorityElement(vector<int>& nums) {
    int n=nums.size();
        int target=(n/2);
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]++;
            if(m[it]>target)return it;
        }
        return 69;   //unreachable code
    }
```
## Approach 3 ( Moore’s Voting Algorithm )
Time Complexity: O(N)
Space Complexity: O(1)

```cpp
    int majorityElement(vector<int>& nums) {
        int e=nums[0],c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==e)
                c++;
            else c--;
            if(c==0)e=nums[i],c=1;
        }
        return e;
    }
```

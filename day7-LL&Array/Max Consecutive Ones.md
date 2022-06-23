[Link](https://leetcode.com/problems/max-consecutive-ones/)
# Max Consecutive Ones
Given a binary array nums, return the maximum number of consecutive 1's in the array.
***Example 1:***
```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```
## Solution
Time : O(N)<br>
Space : O(1)
```cpp
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,c=0;
        for(auto it:nums){
            if(it)c++;
            else c=0;
            ans=max(ans,c);
        }
        return ans;
    }
```
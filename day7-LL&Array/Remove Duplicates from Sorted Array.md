[Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
# Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

***Example 1:***<br>
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```
## Solution 1 : Using Set
Time complexity: O(n*log(n))+O(n)<br>
Space Complexity: O(n) 
```cpp
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(auto it:nums)
            set.insert(it);
        int t=set.size();
        int i=0;
        for(auto it:set)
            nums[i++]=it;
        return t;
    }
```
## Solution 2 : Two pointers
Time complexity: O(n)<br>
Space Complexity: O(1) 
```cpp
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int n=nums.size();
        while(j<n){
            if(nums[i] != nums[j])
                nums[++i]=nums[j];
            j++;
        }
        return i+1;
    }
```
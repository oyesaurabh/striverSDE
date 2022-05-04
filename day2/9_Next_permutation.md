[Question link](https://leetcode.com/problems/next-permutation/)
[Another_link](// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm)
# Next Permutation

## Problem statement

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

## Approach 1 (Brute force)

Time complexity : O(N! \* N)  
Space complexity : O(N! \* N)

```cpp
void getPermutations(int i, vector<int> nums, vector<vector<int>>& p) {
    if(i==nums.size())
        p.push_back(nums);
    for(int j=i; j<nums.size(); j++) {
        swap(nums[i], nums[j]);
        getPermutations(i+1, nums, p);
    }
}
void nextPermutation(vector<int>& nums) {
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());
    vector<vector<int>> p;
    getPermutations(0, v, p);
    for(int i=0; i<p.size(); i++) {
        if(p[i]==nums) {
            int ind = (i+1)%p.size();
            nums = p[ind];
            break;
        }
    }
}
```

## Approach 2 (Optimal)

Time complexity : O(N)  
Space complexity : O(1)

```cpp    

int findPeak(vector<int> a){
        for(int i=a.size()-1;i>0;i--)
            if(a[i-1]<a[i])return i;
        return 0;
    }
int successorOfPivot(vector<int> a,int p){
        int i=a.size()-1;
        while(a[i]<=p)i--;
        return i;
    }

void nextPermutation(vector<int>& nums) {
        int i=findPeak(nums);
        if(i==0){ 
            reverse(nums.begin(),nums.end());
            return;
        }
        int pivot=nums[i-1];
        int j=successorOfPivot(nums,pivot);
        swap(nums[i-1],nums[j]);
        reverse(nums.begin()+i,nums.end());
    }
```

## Approach 3 (Using STL, not for Interviews)

Time complexity : O(N)  
Space complexity : O(1)

```cpp
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}
```
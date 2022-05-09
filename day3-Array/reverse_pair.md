[question link](https://leetcode.com/problems/reverse-pairs/)

# Reverse Pairs

## Problem Statements
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

>>Example 1:
>>Input: nums = [1,3,2,3,1]
>>Output: 2

## Approach 1 (brute force)
Time complexity : O(N^2)  
Space complexity : O(1)

```cpp
int reversePairs(vector<int>& a) {
        int pair=0;
        int n=a.size();
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(a[i] > 2*a[j])
                    pair++;
        return pair;
    }
```
## Approach 2 (using merge sort)
Time complexity : O( NlogN ) + O(N) + O(N)    
Space complexity : O(1)

```cpp
// merge sort
    // void merge(vector<int>& a,int left,int m,int right){
    //     int i=left,j=m+1;
    //     vector<int> t;
    //     while(i<=m && j<=right){
    //         if(a[i]<a[j])t.push_back(a[i++]);
    //         else t.push_back(a[j++]);
    //     }
    //     while(i<=m)
    //         t.push_back(a[i++]);
    //     while(j<=right)
    //         t.push_back(a[j++]);
    //     int k=left;
    //     for(auto it:t)
    //         a[k++]=it;
    // }
    // void merge_sort(vector<int>& a,int left,int right){
    //     if(left<right){
    //         int m=(left + right)>>1;
    //         merge_sort(a,left,m);
    //         merge_sort(a,m+1,right);
    //         merge(a,left,m,right);
    //     }
    // }
int ans=0;
void merge(vector<int>& a,int left,int m,int right){
        // actual work
        int j=m+1;
        for(int i=left;i<=m;i++){
            while(j<=right && a[i]>2LL*a[j])
                j++;
            ans+=j-(m+1);
        }
        //sorting
        int i=left;
        j=m+1;
        vector<int> t;
        while(i<=m && j<=right){
            if(a[i]<=a[j])
                t.push_back(a[i++]);
            else
                t.push_back(a[j++]);
        }
        while(i<=m)
            t.push_back(a[i++]);
        while(j<=right)
            t.push_back(a[j++]);
        
        for(int k=left;k<=right;k++)
            a[k]=t[k-left];

    }
    void merge_sort(vector<int>& a,int left,int right){
        if(left>=right)return;
        
        int m=(left + right)>>1;
        merge_sort(a,left,m);
        merge_sort(a,m+1,right);
        merge(a,left,m,right);    
        
    }
    int reversePairs(vector<int>& a) {
        merge_sort(a,0,a.size()-1);
        return ans;

    }
```
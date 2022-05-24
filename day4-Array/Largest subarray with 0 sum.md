[Link](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

# Largest subarray with 0 sum 
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
```
Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
```
## Solution 1 (Naive approach) :
consider all possible subarrays of the given array and check for the subarrays that sum to zero.
<br>
Time Complexity: O(N^2) as we have two loops for traversal<br>
Space Complexity : O(1) as we aren’t using any extra space.

```cpp
int maxLen(vector<int>&a, int n)
    {   
        // TLE as expected
        int ans=0;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=a[j];
                if(s==0)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
```
## Solution 2 (HashMap or map ) :
Time Complexity: O(N), as we are traversing the array only once.
<br>
Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap.

```cpp
int maxLen(vector<int>&a, int n){
    unordered_map<int ,int> m;
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==0)
            ans=max(ans,i+1);
        else if(m.find(sum) == m.end() )
            m[sum]=i;
        else 
            ans=max(ans,i-m[sum]);
        }
    return ans;
}

```
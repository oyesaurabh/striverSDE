[Link](https://leetcode.com/problems/kth-largest-element-in-an-array/)
# Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.
```
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```
## Solution 1: Sorting the Array
Time : O(NlogN)<br>
Space : O(1)
```cpp
    int findKthLargest(vector<int>& a, int k) {
        O(NlogN)
        sort(a.rbegin(), a.rend());
        return a[k-1]; 
}
```
## Solution 2: Using Heap
Time O(NlogN) ( the insertion and deletion in a priority queue takes O(logn) time and we are doing it for N times so )<br>
space O(K) (becoz size of priority queue will never be greater than K)<br>
```cpp
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it:a){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
```
## Solution 3: Using Quickselect Algorithm
Time : The worst case time complexity of this method is O(n^2) but its Average time complexity is O(n).<br>
Space : O(1)
[CodeLink](https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/)

[Link](https://leetcode.com/problems/search-in-rotated-sorted-array/)<br>
[Link](https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1)
# Search in Rotated Sorted Array
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.
```
Example 1:

Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
Output:
5
Explanation: 10 is found at index 5.
```
## Solutin :: Linear Search
Time Complexity : O(N)<br>
Space Complexity: O(1)
```cpp
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i] == target)return i;
        return -1;
    }
```

## SOlution :: Binary_search
Time Complexity: O(log(N))<br>
Space Complexity: O(1)<br>
![img](https://takeuforward.org/wp-content/uploads/2021/11/image-7.png)<br>
```cpp
    int search(vector<int>& a, int t) {
        int i=0,j=a.size()-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(a[mid] == t )
                return mid;//bingoo
            else if(a[i] <= a[mid]){ //between left part, left....mid
                if(a[i]<=t && t<=a[mid])
                    j=mid-1;
                else 
                    i=mid+1;
            }
            else{ //between right part, mid....right
                if( a[mid] <= t && t<=a[j] )
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return -1;
    }
```
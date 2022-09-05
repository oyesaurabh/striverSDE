[Link](https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)
# K-th element of two sorted Arrays
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
 
```
Example 1:
Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.
```
## Solution :: Naive
Time : O(N+M)<br>
Space : O(1)<br>
```cpp
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   int i = 0, j = 0, count = 0;
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                count++;
                if (count == k) return arr1[i];
                i++;
            } else {
                count++;
                if (count == k) return arr2[j];
                j++;
            }
        }
        while (i < n) {
            count++;
            if (count == k) return arr1[i];
            i++;
        }
        while (j < m) {
            count++;
            if (count == k) return arr2[j];
            j++;
        }
        return -1;
    }
```
## Solution :: BinarySearch
Time Complexity : log(min(m,n))<br>
Space Complexity : O(1)<br>
```cpp

```
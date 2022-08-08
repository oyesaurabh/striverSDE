[Link](https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1)
# Find Nth root of M
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 
```
Example 1:
Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9

Example 2:
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
```
## Solution :: Binary
Time Complexity: M x log(M)<br>
Space Complexity: O(1)
```cpp
	int NthRoot(int n, int m)
	{
	    // Code here.
	   int i=1,j=m;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(pow(mid,n)==m)return mid;
            else if(pow(mid,n) < m)i=mid+1;
            else j=mid-1;
        }
        return -1;
	} 
```
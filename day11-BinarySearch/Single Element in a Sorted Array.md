[Link](https://leetcode.com/problems/single-element-in-a-sorted-array/)
[Link](https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1)
# Single Element in a Sorted Array
```
Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```
## Solution 1: Using XOR(^)
Time Complexity: O(N)<br>
Space Complexity: O(1)
```cpp
	int search(int A[], int N){
	    //code
	    int x_or=0;
	    for(int i=0;i<N;i++)
	        x_or^=A[i];
	    return x_or;
	}
```

## Solution 1: Binary_search
Time Complexity: O(log(N))<br>
Space Complexity: O(1)
![img](https://lh6.googleusercontent.com/PWsdbxN5nvAxplEei2TU-jgQqbeX2tPY2i6lDAyht-GCYDxqOK_rvAyZ5LzFdaVFevSTthC6kT3w9Rv3rYcDvvM2pRuB-SclnnUVT7fOrgByFU3ThONbvsEyewh5BdobUcUBsyY0)<br>
![img](https://lh4.googleusercontent.com/YcSRnwKsFgEAbDpMbUMO5c9zsgU-9PbXBJLck7zeCmEouFHHPqjCW_KciyBgZ5KOHANGnT2RrOVGIVAs4TGZ72tTBWv4rOEfOQceXLL6AiTLoe4egNq0_bHOEPcXyVFPBU6wb7QG)<br>
```cpp
   int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1)return a[0];
        
        int i=0,j=a.size()-1;
        while(i<=j){
            int mid=(i+j)>>1;
            //odd
            if(mid&1){
                if(a[mid-1] == a[mid])//left array
                    i=mid+1;
                else //else right array
                    j=mid-1;
            }
            //even
            else{
                if(a[mid] != a[mid+1]) // right array
                    j=mid-1;
                else  //left array
                    i=mid+1;
            }
        }
        return a[i];
    }

```
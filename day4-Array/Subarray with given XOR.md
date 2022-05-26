[Link](https://www.interviewbit.com/problems/subarray-with-given-xor/)<br>
[Sol Link](https://www.youtube.com/watch?v=lO9R5CaGRPY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=26)
# Subarray with given XOR
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.

```
Example Input
Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6

Output 1:
 4

Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
```
## Solution 1: Brute Force
Time Complexity: O(N<sup>2</sup>)<br>
Space Complexity: O(1)

```cpp
int Solution::solve(vector<int> &A, int B) {
    // O(N*N) && S(1)
    int ans=0;
    for(int i=0;i<A.size();i++){
        int s=0;
        for(int j=i;j<A.size();j++){
            s^=A[j];
            if(s==B)ans++;
        }
    }
    return ans;
}
```

# Solution 2: Prefix xor and map
main idea is : (similar concept that we have used in largest subarray with 0 sum)
```
y ^ k = prexor
y ^ k ^ k = prexor ^ k
y = prexor ^ k 
```
Time Complexity: O(N)<br>
Space Complexity: O(N)
```cpp
int Solution::solve(vector<int> &A, int k) {
    int ans=0;
    unordered_map<int,int> m;
    int prexor=0;
    for(auto it:A){
        prexor^=it;
        if(prexor==k)
            ans++;
        int y=prexor^k;
        if(m.find(y) != m.end())   //found
                ans+=m[y];
        m[prexor]++;    
    }
    return ans;
}

```
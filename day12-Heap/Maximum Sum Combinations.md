[Link](https://www.interviewbit.com/problems/maximum-sum-combinations/)
# Maximum Sum Combinations
Example
```
Input 1:
 A = [3, 2]
 B = [1, 4]
 C = 2
Output 1:
 [7, 6]
Explanation 1:
 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)

Input 2:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4
Output 2:
 [10, 9, 9, 8]
Explanation 2:
 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)
 ```
## Brute Force
Time Complexity: O(N^2)<br>
Auxiliary Space : O(N^2)
```cpp
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int> pq;
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
            pq.push(A[i] + B[j]);
    vector<int> ans;
    while(C--)
        ans.push_back(pq.top()), pq.pop();
    return ans;
}
```

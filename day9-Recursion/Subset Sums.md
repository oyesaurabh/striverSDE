[link](https://practice.geeksforgeeks.org/problems/subset-sums2234/1)
# Subset Sums
Given a list arr of N integers, print sums of all subsets in it.
```
Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
```
## Solution : Recursion
Space :  O(2^N)<br>
Time : O(2^N)
```cpp
    vector<int> ans;
    int n;
    void solve(vector<int> &a,int i,int sum){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        solve(a,i+1,sum);//ignor
        solve(a,i+1,sum+a[i]);//include
    }
    vector<int> subsetSums(vector<int> a, int N){
        n=N;
        solve(a,0,0);
        return ans;
    }
```


[Link](https://leetcode.com/problems/longest-consecutive-sequence/)

# LConsecutiveS
## Problem:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

>Example 1:
>Input: nums = [100,4,200,1,3,2]
>Output: 4
>Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

## Approach 1: (Brute force)
We can simply sort the array and run a for loop to find the longest consecutive sequence.<br>
Time :  O(N * log(N)) + O( N ).<br>
Space : O( 1 )

```cpp
int longestConsecutive(vector<int>& a) {
        if(a.empty())return 0;
        
        sort(a.begin(),a.end());
        
        int ans = 1;
        int prev = a[0];
        int cur = 1;
        
        for(int i = 1;i < a.size();i++){
            if(a[i] == prev+1)
                cur++;
            
            else if(a[i] != prev)
                cur = 1;
            
            prev = a[i];
            ans = max(ans, cur);
        }
        return ans;
    }
```

## Approach 2: ( Better on paper only, not actually LOL  )
Time :  O( N ) + O( N ) + O( N )<br>
Space : O( N )

```cpp
int longestConsecutive(vector<int>& a) {
    if(a.empty())return 0;
    unordered_set<int> s(a.begin(), a.end());

    int ans=1;
    for(auto it:a)
        if(s.find(it-1) == s.end()){
            int sum=1;
            while(s.find(++it) != s.end())
                    sum++;
                
            ans=max(ans,sum);
        }
    
    return ans;
}

```
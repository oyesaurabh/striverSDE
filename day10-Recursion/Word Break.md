[Linmk](https://leetcode.com/problems/word-break/)
# Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
<br>
***Note*** that the same word in the dictionary may be reused multiple times in the segmentation.
```
Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```
## Recursive :: TLE
TIME : O(2<sup>N</sup> - 1)<br>
SPACE : O()<br>

```cpp
class Solution {
    unordered_set<string> set;
    int size;
    bool solve(string s,int k){
        if(k==size)return 1;
        
        for(int i=k;i<size;i++)
            if(set.find(s.substr(k,i-k+1))!=set.end() && solve(s,i+1) )
                return 1;
        
        return 0;
    }
public:
    bool wordBreak(string s, vector<string>& a) {
        for(auto it:a)
            set.insert(it);
        size=s.size();
        return solve(s,0);
    }
};
```
## Memoizaton 
TIME : O(2<sup>N</sup> - 1)<br>
SPACE : O(N)<br>

```cpp
class Solution {
    unordered_set<string> set;
    int dp[301]; //becoze max size of word will be 300
    int size;
    bool solve(string s,int k){
        if(k==size)return 1;
        
        if(dp[k]!=-1)return dp[k];
            
        for(int i=k;i<size;i++)
            if(set.find(s.substr(k,i-k+1))!=set.end() && solve(s,i+1) )
                return dp[k]=1;
        
        return dp[k]=0;
    }
public:
    bool wordBreak(string s, vector<string>& a) {
        for(auto it:a)
            set.insert(it);
        size=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};
```
## DP
```cpp

```
## TRIE

```cpp
```
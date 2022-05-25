[Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
# Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.
```
Examples:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```
## Solution 1: Brute force Approach
Time Complexity: O(N<sup>2</sup>)
<br>
Space Complexity: O(N)<br>
(***NOTE:*** wont be accepted on leetcode.If you know why plz let me know)
```cpp
int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            
            unordered_set<int> set;
            for(int j=i;j<s.size();j++)
                if(set.find(s[j]) == set.end() )
                    set.insert(s[j]);
                else {
                    ans=max(ans,j-i);
                    break;
                }
            
        }
    return ans;
}
```

## Solution 2: Optimised  Approach 1
Time Complexity: O( 2*N ) (sometimes left and right both have to travel complete array)
<br>
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

```cpp
 int lengthOfLongestSubstring(string str) {
 if(str.empty())return 0;
        int ans = 0;
        int n=str.size();
        unordered_set < char > set;
        int i=0,j=0;
        while(j<n) {
            if (set.find(str[j]) != set.end()) //if duplicate element is found
              while (i < j && set.find(str[j]) != set.end()) {
                set.erase(str[i]);
                i++;
            }
                
            set.insert(str[j]);
            ans = max(ans, j - i + 1);
            j++;

          }
          return ans;
    }

```
## Solution 3: Optimised  Approach 2
Time Complexity: O( N )
<br>
Space Complexity: O(N) where N represents the size of HashSet where we are storing our elements

```cpp
int lengthOfLongestSubstring(string s) {
    vector < int > mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n) {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
      return len;
}
```
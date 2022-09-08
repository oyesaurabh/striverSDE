[Link](https://leetcode.com/problems/largest-rectangle-in-histogram/)
# Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

***Example 1:***

![img](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)<br>
```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```
***Example 2:***

![img](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)<br>
```
Input: heights = [2,4]
Output: 4
```
## Solution :: Naive
Time Complexity: O(N*N ) <br>
Space Complexity: O(1)<br>
```cpp
int largestRectangleArea(vector<int>& a) {
        O(N*N)... TLE
        int ans=a[0];
        for(int i=0;i<a.size();i++){
            int mn=a[i];
            for(int j=i;j<a.size();j++){
                mn=min(a[j],mn);
                ans=max(ans, (mn*(j-i+1)) );
            }
        }
        return ans;
    }
//same but better
int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i-1,right=i+1;
            int count=1;           
            while(left>=0 && a[left] >= a[i])
                count++,left--;
            while(right<n && a[i] <= a[right])
                count++,right++;         
            ans=max(ans, count*a[i]);
        }
        return ans;
    }
```
## Solution 2
Time Complexity: O( 3N )<br>
Space Complexity: O(2N) <br>
```cpp
    vector<int> preGreaterElement(vector<int>& a){
        stack<int> s;
        int n=a.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()]>=a[i])
                s.pop();
            if(s.empty())
                ans[i]=-1;
            else
                ans[i]=s.top();
            
            s.push(i);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& a){
        stack<int> s;
        int n=a.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]>=a[i])
                s.pop();
            if(s.empty())
                ans[i]=-1;
            else
                ans[i]=s.top();
            
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int> next=nextGreaterElement(a);
        vector<int> pre=preGreaterElement(a);

        int area=0;
        for(int i=0;i<a.size();i++){
            int l=a[i];
            int b=(next[i]==-1?n:next[i])-pre[i]-1;
            
            area=max(area,l*b);
        }
        return area;
    }
```
## Solution 3 
Time Complexity: O( N ) + O (N)<br>
Space Complexity: O(N) <br>
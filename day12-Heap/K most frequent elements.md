[Link](https://leetcode.com/problems/top-k-frequent-elements/)
# Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
```
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
```
## Solution :: Heap
Time O(N + NlogN + kLogN) || (not sure)<br> 
Space O(k + N) (N = map, K = heap)
```cpp
vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int> m;
        for(auto it:nums)
            m[it]++;
    
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > pq; //min_hheap
        for(auto it:m){
            pq.push({it.second,it.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
```
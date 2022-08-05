[Link](https://leetcode.com/problems/permutation-sequence/)
# K-th permutation Sequence
Given n and k, return the kth permutation sequence.<br>

Input: 4 3<br>
Output: 1324<br>
**Explanation:** <br>
Permutations of first 4 natural numbers:<br>
1234,1243,1324,1342,1423,1432.....<br>
So the 3rd permutation is 1324. <br>

## Solution : Brute Force
Time : O(N)+O(N!)+O(N!\*logN!)<br>
Space : O(N!)
```cpp
class Solution {
    int n;
    //function for calculating permutation.
    void permutation(string &s,int index,vector<string>&ans){
        if(index==n){
            ans.push_back(s);
            return;
        }
        for(int i=index; i<n; i++){
            swap(s[i], s[index]);
            permutation(s,index+1,ans);
            swap(s[i], s[index]);
        }
    }
public:
    string getPermutation(int n, int k) {
        this->n=n;
        string s;
        vector<string> ans;
        //calulating string eg. n==3, s='123'
        for(int i=1;i<=n;i++)// O(N)
            s+=(i+'0');

        //calculating and storing all possible permutations. 
        permutation(s,0,ans);// O(N!)
        sort(ans.begin(), ans.end());// O(N! * logN!)

        //finally returning kth permutation.
        return ans[k-1];
    }
};
```
## Solution :: (Optimal Approach Maths)
**Intuition:**<br>
Since this is a permutation we can assume that there are four positions that need to be filled using the four numbers of the sequence. First, we need to decide which number is to be placed at the first index. Once the number at the first index is decided we have three more positions and three more numbers.  Now the problem is shorter. We can repeat the technique that was used previously until all the positions are filled. The technique is explained below
```
Approach:
Say we have N = 4  and K = 17. Hence the number sequence is {1,2,3,4}.

Step1
since N=4, therefore there will be 4! permutations.
therefore If we consider the sequences as 0-based and in the sorted form we observe:- 

The 0th – 5th permutation will start with 1 
The 6th – 11th permutation will start with 2
The 12th – 17th permutation will start with 3 
The 18th – 23rd permutation will start with 4.

Since each of the four blocks illustrated above comprises 6 permutations, therefore, 
the 16th permutation will lie in (16 / 6 ) = 2nd block. 
Therefore 3 occupies the first position of the sequence and our k will become (16 % 6) = 4 for next call.
3 _ _ _

Step2
Our new search space comprises three elements {1,2,4} where K = 4 . Using the previous technique
The 0th – 1st sequence starts with 1 
The 2nd – 3rd sequence starts with 2 
The 4th – 5th sequence starts with 4

The 4th permutation will lie in (4/2) = 2nd block and k=k%2 ie 0.
3 4 _ _

step 3
The new search space will have two elements {1 ,2} and K = 0. 
One block starts with 1 and the other block starts with 2. The other remaining number can form only one 1! = 1 sequence. In sorted form –

The  0th sequence starts with 1 
The  1st sequence. starts with 2

The 0th permutation will lie in the (0/1) = 0th block Therefore 1 occupies the 3rd position.
Also K=K%1=0
3 4 1 _

step 4
Now the only block has 2 in the first position and no remaining number is present.
3 4 1 2

```
```cpp

```

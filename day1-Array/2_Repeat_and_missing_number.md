[Question link](https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/)

# Find the repeating and the missing number in an array

## Problem statement

Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

## Approach 1 (Extra array, count sort)

Time complexity : O(N)  
Space complexity : O(N)

```cpp
vector<int> find_missing_repeating(vector<int> array)
{
    int n = array.size() + 1;
    vector<int> hash(n, 0); // initializing the substitute array with 0 of size n+1.
    vector<int> ans;              // initializing the answer  array .
    for (int i = 0; i < array.size(); i++)
        hash[array[i]]++;
    
    for (int i = 1; i <= array.size(); i++)
        if (hash[i] == 0 || hash[i] > 1)
            ans.push_back(i);
        
    return ans;
}
```
## Approach 2 (Cycle Sort)
Time complexity : O(2N)  
Space complexity : O(1)

```cpp
int *findTwoElement(int *a, int n) {
    //cycle sort
    for(int i=0;i<n;i++)
        while(a[a[i]-1] != a[i])
            swap(a[a[i]-1] , a[i]);

    // searching the element which are not in correct index
    int *ans=new int[2];
        for(int i=0;i<n;i++)
            if(a[i]-1 != i){
                ans[0]=a[i];  // repeated element
                ans[1]=i+1;   // missing element
                return ans;
            }
    return ans;
}

```

## Approach 3 (Mathematics)

Time complexity : O(N)  
Space complexity : O(1)  
it requires long int to store large values

```cpp
vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();
    
    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     

    long long int missingNumber=0, repeating=0;
    missingNumber = (S + P/S)/2;
    repeating = missingNumber - S;

    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}
```


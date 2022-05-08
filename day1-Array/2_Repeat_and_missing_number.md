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
    vector<int> substitute(n, 0); // initializing the substitute array with 0 of size n+1.
    vector<int> ans;              // initializing the answer  array .
    for (int i = 0; i < array.size(); i++)
    {
        substitute[array[i]]++;
    }
    for (int i = 1; i <= array.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
```

## Approach 2 (Mathematics)

Time complexity : O(N)  
Space complexity : O(1)  
it requires long int to store large values

```cpp
int *findTwoElement(int *arr, int n) {
    long sum = 0, sqSum=0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        sqSum += arr[i]*arr[i];
    }
    // x = duplicate num, y = missing num
    long xminusy = sum - (long(n)*(n+1))/2;
    long xsqminusysq = sqSum - (long(n)*(n+1)*(2*n+1))/6;
    long xplusy = xsqminusysq / xminusy;
    int x = (int)((xminusy + xplusy) / 2);
    int y = (int)(xplusy - x);
    int * res = new int[2];
    res [0] = x;
    res[1] = y;
    return res;
}
```

## Approach 3 (Xor)

Time complexity : O(N)  
Space complexity : O(1)

```cpp
int *findTwoElement(int *arr, int n) {
    int num = 0, i;
    for(i=0; i<n; i++)
        num = (num^arr[i]);
    for(i=1; i<=n; i++)
        num = (num^i);

    int setbit = num & ~(num-1);

    int x = 0, y = 0;
    for(i=0; i<n; i++) {
        if(arr[i] & setbit)
            x = (x^arr[i]);
        else
            y = (y^arr[i]);
    }
    for(i=1; i<=n; i++){
        if(i&setbit)
            x = (x^i);
        else
            y =(y^i);
    }
    int * res = new int[2];
    res[0] = x;
    res[1] = y;
    for(i=0; i<n; i++) {
        if(arr[i] == res[1]) {
            swap(res[0], res[1]);
            break;
        }
    }
    return res;
}
```
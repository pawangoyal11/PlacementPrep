// A contigous or non-contiguous sequence which follows the order

// Take or not take

#include<bits/stdc++.h>
using namespace std;

int printSequences(int ind, int s, int sum, int arr[], int n)
{
    if(s > sum)
    {
        return 0;
    }
    if(ind == n)
    {
        // condition satisfied
        if(s == sum)
        {
            return 1;
        }
        // condition not satisfied
        return 0;
    }
    //Take or pick the particular index into the subsequence

    s += arr[ind];
    int l= printSequences(ind+1, s, sum, arr, n);
    s -= arr[ind];

    // Not pick, or not take condition, this element is not added to your subsequence

    int r= printSequences(ind+1, s, sum, arr, n);
    
    return l+r;
}

int main()
{
    int arr[]= {1,2,1};
    int n= 3;
    int sum= 2;
    cout<<printSequences(0, 0, sum, arr, n)<<endl;
    return 0;
}

// TC- O(2^N * N)   
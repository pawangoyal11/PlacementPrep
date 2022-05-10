// A contigous or non-contiguous sequence which follows the order

// Take or not take

#include<bits/stdc++.h>
using namespace std;

bool printSequences(int ind, vector<int> &ds,int s, int sum, int arr[], int n)
{
    if(ind == n)
    {
        // condition satisfied
        if(s == sum)
        {
            for(auto it: ds)
            {
                cout<< it << " ";
            }
            cout << endl;
            return true;
        }
        // condition not satisfied
        return false;
    }
    //Take or pick the particular index into the subsequence

    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printSequences(ind+1, ds, s, sum, arr, n == true))
    {
        return true;
    }
    s -= arr[ind];
    ds.pop_back();

    // Not pick, or not take condition, this element is not added to your subsequence

    if(printSequences(ind+1, ds, s, sum, arr, n) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[]= {1,2,1};
    int n= 3;
    int sum= 2;
    vector<int> ds;
    printSequences(0, ds, 0, sum, arr, n);
    return 0;
}

// TC- O(2^N * N)  
// A contigous or non-contiguous sequence which follows the order

// Take or not take

#include<bits/stdc++.h>
using namespace std;

void printSequences(int ind, vector<int> &ds, int arr[], int n)
{
    if(ind==n)
    {
        for(auto it: ds)
        {
            cout<< it << "";
        }
        if(ds.size()==0)
        {
            cout<<"{}";
        }
        cout<< endl;
        return;
    }
    //Take or pick the particular index into the subsequence

    ds.push_back(arr[ind]);
    printSequences(ind+1, ds, arr, n);
    ds.pop_back();

    // Not pick, or not take condition, this element is not added to your subsequence

    printSequences(ind+1, ds, arr, n);
}

int main()
{
    int arr[]= {3,1,2};
    int n= 3;
    vector<int> ds;
    printSequences(0, ds, arr, n);
    return 0;
}

// TC- O(2^N * N)
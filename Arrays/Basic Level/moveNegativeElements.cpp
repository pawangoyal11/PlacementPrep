#include<iostream>

using namespace std;

void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int ans[n];
        int j=0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]>=0)
            {
                ans[j]= arr[i];
                j++;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]<0)
            {
                ans[j]= arr[i];
                j++;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            arr[i]= ans[i];
        }
    }

int main()
{
    int arr[]= {-1,-3,3,-4,21,91};
    segregateElements(arr,6);
    return 0;
}
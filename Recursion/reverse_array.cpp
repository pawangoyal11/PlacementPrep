#include<iostream>

using namespace std;

// Parametrised
void reverse(int arr[], int n, int l, int r)
{
    if(l>=r)
        return;
    
    swap(arr[l], arr[r]);
    reverse(arr, n, l+1, r-1);
}

//Functional
void reverseFunc(int arr[], int n, int i)
{
    if(i>=n/2)
    {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseFunc(arr, n, i+1);

}
int main()
{
    int arr[]={1,3,4,6,7,8,9,3,2,0};
    reverseFunc(arr,10,0);
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
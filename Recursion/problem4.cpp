// Print 1 to n using Backtracking

#include<iostream>
using namespace std;

int num=1;
void Print1ToN(int i, int n)
{
    if(i<1)
    {
        return;
    }
    
    Print1ToN(i-1, n);
    cout<<i<<endl;
}

int main()
{
    int n;
    cin>>n;
    Print1ToN(n, n);
    return 0;
}
// Print Linearly from n to 1

#include<iostream>
using namespace std;

void Print1ToN(int i, int n)
{
    if(i<1)
    {
        return;
    }
    cout<<i<<endl;
    Print1ToN(i-1, n);
}

int main()
{
    int n;
    cin>>n;
    Print1ToN(n, n);
    return 0;
}
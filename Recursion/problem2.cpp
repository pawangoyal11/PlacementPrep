// Print Linearly from 1 to N

#include<iostream>
using namespace std;

int num=1;
void Print1ToN(int i, int n)
{
    if(i>n)
    {
        return;
    }
    cout<<i<<endl;
    Print1ToN(i+1, n);
}

int main()
{
    int n;
    cin>>n;
    Print1ToN(1, n);
    return 0;
}
// Recursion?? When a function calls itself until a specified condition is met.

// Print Name N Times

#include<iostream>
using namespace std;

void PrintName(int i, int n)
{
    if(i>n)
    {
        return;
    }
    cout<<"Pawan"<<endl;
    PrintName(i+1, n);
}

int main()
{
    int n;
    cin>>n;
    PrintName(1,n);
    return 0;
}
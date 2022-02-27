// Print n to 1 using Backtracking

#include<iostream>
using namespace std;

void PrintNTo1(int i, int n)
{
    if(i>n)
    {
        return;
    }
    
    PrintNTo1(i+1, n);
    cout<<i<<endl;
}

int main()
{
    int n;
    cin>>n;
    PrintNTo1(1, n);
    return 0;
}
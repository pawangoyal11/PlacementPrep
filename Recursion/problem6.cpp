// Sum of first n numbers parametrized and functional

#include<iostream>
using namespace std;


// Parametrized Recursive Function
void Sum(int i, int sum)
{
    if(i<1)
    {
        cout<<sum<<endl;
        return;
    }
    Sum(i-1, sum+i);
}

// Functional Recurive Function
int GetSum(int n)
{
    if(n==0)
        return 0;

    return n+GetSum(n-1);
}

int main()
{
    int n;
    cin>>n;
    Sum(n,0);
    cout<<"Sum = "<<GetSum(n)<<endl;
    return 0;
}
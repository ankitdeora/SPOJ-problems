#include <iostream>
#include <cmath>
using namespace std;
int reverse_number(int n);
int length(int n);

int main()
{
    int N;
    cin>>N;

    int a,b;

    for(int i=0;i<N;i++)
    {
        cin>>a>>b;
        cout << reverse_number(a)<<" "<<reverse_number(b)<<endl;
        //cout<<reverse_number(reverse_number(a)+reverse_number(b))<<endl;
    }
    return 0;
}
int length(int n)
{
    int i=0;
    while(n!=0)
    {
        n=n/10;
        i++;
    }
    return i;
}
int reverse_number(int n)
{
    int r_number = 0;
    int remainder=0;
    int len = length(n);
    for(int j=0;j<len;j++)
    {
        remainder = n%10;
        r_number += remainder*pow(10,len-j-1);
        n=n/10;
    }
    return r_number;
}

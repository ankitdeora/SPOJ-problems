#include <iostream>

using namespace std;
int main()
{
    int n=0;
    while(n!=42)
    {
        cin>>n;
        if(n==42) break;
        cout<<n<<endl;
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n=1;
	while(n!=0)
	{
		cin>>n;
		if(n==0) break;
		cout<<n*(n+1)*(2*n+1)/6<<endl;
		
	}
	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int t=0;
	cin>>t;
	int factorial(int);
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		cout<<factorial(n)<<endl;
	}
	return 0;
}

int factorial(int n)
{
	if(n==1) return 1;
	else 
	{
		int m=n-1;
		return n*factorial(m);
	}
}

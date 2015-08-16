#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t=0;
	bool isPrime(int);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a=0;
		int b=0;
		cin>>a>>b;
		
		for(int j=a;j<b+1;j++)
		{
			//if(isPrime(j)) cout<<j<<endl;
			if(j!=1)
			{
				bool ifPrime=true;
				for(int k=2;k<j;k++)
				{
					if(j%k==0) 
					{
						ifPrime=false;
						break;	
					}
				}
				if(ifPrime) cout<<j<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
bool isPrime(int n)
{
	if(n==1) return false;
	for(int k=2;k<n;k++)
	{
		if(n%k==0) return false;
	}
	return true;
}

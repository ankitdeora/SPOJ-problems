#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N=0;
	cin>>N;
	int maxPowerFive(int);
	for(int i=0;i<N;i++)
	{
		int x=0;
		int result=0;
		cin>>x;
		
		int count = maxPowerFive(x);
		for(int j=1;j<count+1;j++)
		{
			result += x/pow(5,j);
		}
		cout<<result<<endl;
	}
}

int maxPowerFive(int n)
{
	int i=0;
	while(n>pow(5,i+1)||n==pow(5,i+1))
	{
		i++;
	}
	return i;
}

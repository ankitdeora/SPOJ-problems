#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N=0;
	cin>>N;
	int rectangles = 0;
	for(int i=1;i<N+1;i++)
	{
		int factorCount=0;
		for(int j=1;j<i+1;j++)
		{
			if(i%j==0) factorCount++;
		}
		if(factorCount%2!=0) factorCount = (factorCount+1)/2;
		else factorCount = factorCount/2;
		
		rectangles+=factorCount;
	}
	cout<<rectangles<<endl;
	return 0;
}

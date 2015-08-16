#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t=0;
	cin>>t;
	int arr[10]={0,0,4,4,2,0,0,4,4,2};
	for(int i=0;i<t;i++)
	{
		int a=0;
		int b=0;
		cin>>a>>b;
		if(b==0)
		{
			cout<<1<<endl;
			continue;
		}
		
		int lastDigit=0;	
		int tail = a%10;
		int remainder = 0;
		
		if(arr[tail]==0) lastDigit = tail;
		else
		{
			remainder = b%arr[tail];
			if(remainder==0) remainder = arr[tail];
			lastDigit = pow(tail,remainder);

		}
		cout<<lastDigit%10<<endl;
	}
	return 0;
}

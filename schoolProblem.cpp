#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a=0;
	int b=0;
	
	for(int i=0;i<10;i++)
	{
		cin>>a;
		cin>>b;
		
		cout<<(a+b)/2<<endl<<(a-b)/2<<endl;	
	}
	return 0;
}


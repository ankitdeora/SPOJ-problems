#include <iostream>
using namespace std;

int main() {
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a = 0;
		int b = 0;
		int n = 0;
		cin>>a>>b;
		if(!(a<0)&&!(b<0))
		{	
			if(a==b){
				n = (a%2==0)?2*a:2*a-1;	
				cout<<n<<endl;
			} 
			else if(a==b+2)
			{
				n = (a%2==0)?a+b:a+b-1;
				cout<<n<<endl;
			} 
			else cout<<"No Number"<<endl;
		}
		else cout<<"No Number"<<endl;
	}
	return 0;
}

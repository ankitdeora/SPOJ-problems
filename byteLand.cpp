#include<iostream>
 
using namespace std;

int goldToDollars(int,int*);

int main()
{
	int n=0;
	int arr[100000];
	for(int j=0;j<100000;j++)
	{
		arr[j]=-1;
	}
	
	for(int i=0;i<5;i++)
	{
		cin>>n;
		cout<<goldToDollars(n,arr)<<endl;
	}
	
    return 0;
}

int goldToDollars(int n,int* a)
{
	if(n==0) return 0;
	if(a[n]!=-1) return a[n];
	else
	{
		if(n/2 + n/3 + n/4 < n ) a[n]=n;
		else 
		{
			a[n] = goldToDollars(n/2,a)+goldToDollars(n/3,a)+goldToDollars(n/4,a);
		}
		return a[n];
	}
}



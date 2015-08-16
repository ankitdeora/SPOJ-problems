#include <iostream>
using namespace std;

int main()
{
	int t=0;
	int n=0;
	int* arr;
	
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cout<<endl;
		
		int inversions = 0;
		cin>>n;
		arr = new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		
		for(int k=0;k<n;k++)
		{
			for(int p=k+1;p<n;p++)
			{
				if(arr[p]<arr[k]) inversions++;
			}
		}
		cout<<inversions<<endl;
					
	}
	return 0;
}

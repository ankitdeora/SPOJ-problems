#include <iostream>

using namespace std;

int main()
{
	int t=0;
	cin>>t;
	int arr[1000];

	for(int i=0;i<t;i++)
	{
		int n=0;
		cin>>n;
		int arr_size = 1;
		arr[0]=1;
		int carry = 0;
		int prod = 0;
		
		for(int k=n;k>0;k--)
		{
			//multiply(arr,k)
			for(int i=0;i<arr_size;i++)
			{
				prod = arr[i]*k + carry;
				arr[i]=prod%10;
				carry = prod/10;
			}
			
			while(carry!=0)
			{
				arr[arr_size]=carry%10;
				carry=carry/10;
				arr_size++;
			}
		}
		
		for(int p=arr_size-1;p>-1;p--)
		{
			cout<<arr[p];
		}
		cout<<endl;
	}
	return 0;
}


#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int t=0;
	while(t!=-1)
	{
		cin>>t;
		if(t==-1) break;
		int arr[t];
		int sum_candies = 0;
		
		for(int i=0;i<t;i++)
		{
			cin>>arr[i];
			sum_candies += arr[i];
		}
		
		int candiesInOnePacket = sum_candies/t;	
		int moves = 0;
		
		if(sum_candies%t==0)
		{
			for(int j=0;j<t;j++)
			{
				if(arr[j]>candiesInOnePacket)
				{
					 moves+=arr[j]-candiesInOnePacket;
				}
				
			}	
		}
		else moves = -1;
		
		cout<<moves<<endl;
		
	}
	return 0;
}

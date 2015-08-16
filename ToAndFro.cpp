#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int t=1;
	while(t!=0)
	{
		cin>>t;
		if(t==0) break;
		
		string input = "";
		cin.ignore();
		getline(cin,input);
		int len=input.length();
		int l = len/t;
		char arr[l][t];
		
		for(int i=0;i<len;i++)
		{
			int row = i/t;
			int col = i%t;
			if(row%2==0)
			{
				arr[row][col]=input[i]; 	
			}
			else arr[row][t-1-col]=input[i];
		}
		
		for(int j=0;j<t;j++)
		{
			for(int k=0;k<l;k++)
			{
				cout<<arr[k][j];
			}
		//	cout<<endl;
			
		}
		cout<<endl;
		
	}
	
	return 0;
}

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isOperator(char);
int main()
{
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin.ignore();
		string input = " ";
   		getline(cin, input);
   		int nextIndex = 0;
   		
   		string operators = "";
   		for(int k=0;k<input.length();k++)
   		{
   			
   			if(isOperator(input[k]))
   			{
   				operators[nextIndex] = input[k];
   				nextIndex++;
   			}
   			else if(input[k]==')')
   			{
   				nextIndex--;
   				cout<<operators[nextIndex];
   			}
   			else if(input[k]!='(')
   			{
   				cout<<input[k];
   			}
   			
   		}
   		cout<<endl;
	}
  
   	return 0;
}

bool isOperator(char ch)
{
	string AllOperators = "+-*/^";
	int len = AllOperators.length();
	int	index = AllOperators.find(ch);
	if(index<len&&index>-1) return true;
	else return false;
}



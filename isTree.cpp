#include <iostream>
using namespace std;

struct node
{
	int id;
	int neighbour;
};

bool join(int,int,node*,int);

int main()
{
	int N=0;
	int M=0;
	int a=0;
	int b=0;
	int* x_array;
	int* y_array;
	
	cin>>N>>M;
	x_array = new int[M+1];
	y_array = new int[M+1];
	
	for(int i=1;i<M+1;i++)
	{
		cin>>a>>b;
		x_array[i]=a;
		y_array[i]=b;		
	}
	
	if(M==N-1)
	{
		node* mainArr;
		mainArr = new node[N+1];
		for(int k=1;k<N+1;k++)
		{
			mainArr[k].id = k;
			mainArr[k].neighbour = 0;
		}
		
		bool Loop = false;
		for(int p=1;p<M+1;p++)
		{
			if(!join(x_array[p],y_array[p],mainArr,N)) 
			{
				Loop = true;
				break;
			}
		}
		
		bool moreNeighbours = false;
		for(int q=1;q<N+1;q++)
		{
			if(mainArr[q].neighbour==0||mainArr[q].neighbour>3)
			{
				moreNeighbours = true;
				break;
			}
		}
		
		if(N==1&&M==0) cout<<"YES"<<endl;
		else if(Loop||moreNeighbours) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
	}
	else cout<<"NO"<<endl;
	
	return 0;
}

bool join(int a,int b,node* A,int N)
{
	int pid = A[a].id;
	int qid = A[b].id;
	
	if(pid==qid) return false;
	for(int i=1;i<N+1;i++)
	{
		if(A[i].id==qid) A[i].id = pid;
	}
	A[a].neighbour++;
	A[b].neighbour++;
	return true;
}

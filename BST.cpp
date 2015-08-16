#include <iostream>
#include <conio.h>
using namespace std;

struct node
{	
	int data;
	node* left;
	node* right;
};

node* newNode(int);
void insert(int,node*);
void inorder(node*);
node* nodeSearch(int,node*);
void printPredSuc(int,node*);
int maxBST(node*);
int minBST(node*);
bool isBST(node*);

int main()
{
	node* root = newNode(18);
	insert(32,root);
	insert(19,root);
	insert(14,root);
	insert(17,root);
	insert(13,root);
	insert(15,root);
	insert(30,root);
	insert(25,root);
	
	/*
	              18
	           /     \
			 /        \
	        14         32
	      /   \        /
		 13	   17    19 
		      /		   \
			 15          30
					   /
				      25
	*/
	
	node* temp = nodeSearch(32,root);
	temp->right = newNode(35);
	cout<<isBST(root)<<endl;
	
	inorder(root);
	cout<<endl;
	//cout<<maxBST(root->right)<<","<<minBST(root->right);
	/*int n=-1;
	cin>>n;
	while(n!=0)
	{
		printPredSuc(n,root);	
		cin>>n;
	}*/
	
	//cout<<endl<<nodeSearch(100,root)<<endl;
	//_getch();
	return 0;
}

bool isBST(node* m_node)
{
	if(m_node==NULL) return true;
	//bool flag = m_node->left->data<m_node->data&&m_node->right->data>m_node->data;
	bool flagLeft = false;
	bool flagRight = false;
	if(isBST(m_node->left)&&isBST(m_node->right))
	{
		flagLeft = true;
		flagRight = true;
		if(m_node->left!=NULL) flagLeft = maxBST(m_node->left)<m_node->data;
		if(m_node->right!=NULL) flagRight = minBST(m_node->right)>m_node->data;
		return flagLeft&&flagRight;
	}
	return false;
}

int maxBST(node* m_node)
{
	if(m_node==NULL) return -1;
	
	while(m_node->right!=NULL)
	{
		m_node = m_node->right;
	}
	return m_node->data;
}

int minBST(node* m_node)
{
	if(m_node==NULL) return -1;
	
	while(m_node->left!=NULL)
	{
		m_node = m_node->left;
	}
	return m_node->data;
}

void printPredSuc(int key,node* m_node)
{
	int pred = -1;
	int suc = -1;
	
	while(m_node!=NULL)
	{
		if(m_node->data>key)
		{
			suc = m_node->data;
			m_node = m_node->left;
		}
		else if(m_node->data<key)
		{
			pred = m_node->data;
			m_node = m_node->right;
		}
		else if(m_node->data==key)
		{
			node* current = m_node->left;
			while(current!=NULL)
			{
				pred = current->data;
				current = current->right;
			}
			
			current = m_node->right;
			while(current!=NULL)
			{
				suc = current->data;
				current = current->left;
			}
			m_node = NULL;
		}
	}
	cout<<"pred:"<<pred<<", suc:"<<suc<<endl;
}
node* nodeSearch(int key,node* m_node)
{
	if(m_node==NULL) return NULL;
	if(m_node->data==key) return m_node;
	node* RN = nodeSearch(key,m_node->right);
	node* LN = nodeSearch(key,m_node->left);
	if(RN!=NULL) return RN;
	else if(LN!=NULL) return LN;
	return NULL;
}

void insert(int key, node* m_node)
{
	if(m_node->data<key)
	{
		if(m_node->right==NULL)
		{
			node* temp = newNode(key);
			m_node->right = temp;
		}
		else insert(key,m_node->right);
	}
	else 
	{
		if(m_node->left==NULL)
		{
			node* temp = newNode(key);
			m_node->left = temp;
		}
		else insert(key,m_node->left);
	}
}

void inorder(node *m_node)
{
    if (m_node != NULL)
    {
        inorder(m_node->left);
        printf("%d ", m_node->data);
        inorder(m_node->right);
    }
}

node* newNode(int key)
{
	node* temp = new node;
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


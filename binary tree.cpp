#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int);
int printAncestors(node*,int);
void mirrorTree(node*);
void printPostorder(node*);
void printAllLeaves(node*);
int height(node*);
void sumTree(node*);
int nodeSum(node*);
int depth(node*,int);
void printNodesAt(node*,int);
void closestKeys(node*);
int maximumKey(node*);
int main()
{
	
    node* root = newNode(10);  
    root->left        = newNode(-2);
    root->right       = newNode(6);
    root->right->right = newNode(5);
	root->right->left = newNode(7);
	root->left->left  = newNode(8);
    root->left->right = newNode(-4);
	//root->left->right->right = newNode(2);    
    root->left->left->left = newNode(9);
    
/*    			 10
  			   /   \
		     -2      6
			/  \    /  \
		  8	   -4  7    5
		 /
		9
*/	

	 //cout<<holdSumProperty(root)<<endl;
	 printPostorder(root);
	 cout<<endl;
	 cout<<maximumKey(root->right)<<endl;
	 //closestKeys(root);
	 //printNodesAt(root,2);
     //printAllLeaves(root);
     //cout<<endl;
	 //cout<<depth(root,7)<<endl;
     //sumTree(root);
   	 //printPostorder(root);
     //cout<<endl<<nodeSum(root->left)<<endl;
     //printAncestors(root,7);
    /*
   printPostorder(root);
   cout<<"done"<<endl;
   
   mirrorTree(root);
   cout<<"done"<<endl;
   
   printPostorder(root);
   cout<<"done"<<endl;
   */
	_getch();
	return 0;
}
int maximumKey(node* m_node)
{
	if(m_node==NULL) return 0;
	
	int value = maximumKey(m_node->left) > maximumKey(m_node->right) ? maximumKey(m_node->left) :  maximumKey(m_node->right);
	value = value > m_node->data ? value : m_node->data ;
	return value;
}

void closestKeys(node* m_node)
{
	bool flagLeft = m_node->left->left==NULL&&m_node->left->right==NULL;
	bool flagRight = m_node->right->left==NULL&&m_node->right->right==NULL;
	
	if(flagLeft) cout<<m_node->left->data<<",";
	if(flagRight) cout<<m_node->right->data<<",";
	
	if(!flagLeft&&!flagRight)
	{
		closestKeys(m_node->left);
		closestKeys(m_node->right);
	}
	
}
void printNodesAt(node* m_node,int depth)
{
	if(m_node==NULL) return;
	if(depth==0) 
	{
		cout<<m_node->data<<",";
		return;
	}
	depth--;
	printNodesAt(m_node->left,depth);
	printNodesAt(m_node->right,depth);
	return;
}
int depth(node* m_node,int key)
{
	if(m_node == NULL) return 0;
	if(m_node->data == key) return 1;
		
	int depthLeft = depth(m_node->left,key);
	int depthRight = depth(m_node->right,key);
	int depthFlag = depthLeft + depthRight;
	
	if(depthFlag!=0)
	{
		return 1+depthFlag;
	}
	return 0;
}
void sumTree(node* m_node)
{
	if(m_node==NULL) return;
	m_node->data = nodeSum(m_node->left)+nodeSum(m_node->right);
	sumTree(m_node->left);
	sumTree(m_node->right);
}

int nodeSum(node* m_node)
{
	if(m_node==NULL) return 0;
	else return nodeSum(m_node->left)+nodeSum(m_node->right)+m_node->data;
}

int height(node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left 
      height and right heights */   
   return 1 + max(height(node->left), height(node->right));
} 

int printAncestors(node* root,int key)
{
	if(root==NULL) return 0;
	
	if(root->data == key) return 1;
	else if(printAncestors(root->left,key)+printAncestors(root->right,key)>0)
	{
		cout<<root->data<<",";
	}
	return 1;
}

void printPostorder(node* node)
{
     if (node == NULL)
        return;
     // first recur on left subtree
     printPostorder(node->left);
	 
     // then recur on right subtree
     printPostorder(node->right);
     cout<<node->data<<",";
     // now deal with the node
     
}

void mirrorTree(node *root)
{
	if(root==NULL) return;
	
	mirrorTree(root->left);
	mirrorTree(root->right);
	
	node* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void printAllLeaves(node* node)
{
	if(node==NULL) return;
	
	printAllLeaves(node->left);
	printAllLeaves(node->right);
	
	if(node->left==NULL&&node->right==NULL)
	{
		cout<<node->data<<",";
		//printAncestors(root,node->data);
		
	}
}

node* newNode(int n)
{
	node* temp = new node;
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


//A Binary Search Tree Class that implements various tree methods....
#include <vector>
#include <iostream>
using namespace std;
class Node
{
public:
	long data;
	Node* left;
	Node* right;
public:
	Node(long data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

class Tree
{
public:
    //Declare a root node for the Tree.
	Node *root;
	// A Vector that Stores the result of a Traversal..
	vector<long> traversal;
public:
	Tree()
	{
	    //The root is initially NULL before any insertion.
		root=NULL;
	}
	//An Insertion function that takes the input parameter the Tree's root and data
	Node * insert(Node* root,long data)
	{
		//If Tree empty - Base Case
		if(root==NULL)
		{
			Node *my_node = new Node(data);
			return my_node;
		}
		//Otherwise go down to proper position recursively...and insert.
		else
		{
			if(data<root->data)
			{
				root->left = insert(root->left,data);
			}
			else
			{
				root->right =  insert(root->right,data);
			}
		}
		return root;
	}
	void inorder(Node *root)
	{
	    //Base Case
		if(root==NULL)
		{
			return;
		}
		inorder(root->left);
		this->traversal.push_back(root->data);
		inorder(root->right);
	}
};
int main()
{
	int n;
	cout<<"Enter the Number of elements in the Tree:";
	cin>>n;
	Tree *t = new Tree();
	for(int i=0;i<n;i++)
	{
		long data;
		cout<<"Enter Data to insert:";
		cin>>data;
		t->root=t->insert(t->root,data);
	}
	//Call the 'inorder' function which stores the result in the class member traversal.
	t->inorder(t->root);

	vector<long> result=t->traversal;

	cout<<"OUTPUT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	cout<<"END"<<endl;
}

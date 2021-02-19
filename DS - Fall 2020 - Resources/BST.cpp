#include<iostream>

using namespace std; 

class Node
{
	public:
	int key;
	Node* left;
	Node* right;
};

Node* newNode(int item)
{
	Node* temp = new Node;
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;	
}

Node* insert(Node* node, int key)
{
	//cout<<"Hi";
	
	if(node==NULL)
	{ return newNode(key); }
	
	if(key < node->key)
	{ node->left = insert(node->left, key); }
	else{
	node->right = insert(node->right, key);
	}
	
	return node;
}

//inorder traversal
void inorder(Node* root)
{
	//cout<<"Hi";
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<endl;
		inorder(root->right);
	}	
}

//preorder traversal
void preorder(Node* root)
{
	if(root!=NULL)
	{
		cout<<root->key<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}

Node* inorderSeccussor(Node* node)
{
	Node* temp = node;
	
	while(temp && temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
	
}

//deletion

Node* deleteNode(Node* root, int key)
{
	if(root == NULL) return root;
	
	if(key<root->key)
	{
		root->left = deleteNode(root->left, key);
	}
	else if(key>root->key)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if(root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			//root = temp
			return temp;
		}
		else if(root->right == NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}
		
		Node *temp = inorderSeccussor(root->right);
		
		root->key = temp->key;
		
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
	
}

int main()
{
	
	Node* root = NULL;
	
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root,13);
	root = insert(root,14);
	root = insert(root,8);
	root = insert(root,9);
	
	
	inorder(root);
	
	root = deleteNode(root, 10);
	
	preorder(root);
	
	getchar();
	return 1;
}

#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

//init the tree
void TR_init(TREE_PTR *root)
{
	*root = NULL;
}//check


//checking if the tree is empty
int TR_empty(TREE_PTR root)
{
	return root == NULL;
}//check

//returning the data member of a node
elem TR_data(TREE_PTR p)
{
	return p -> data;
}//check



//inserting the root node inside a null tree
int TR_insert_root(TREE_PTR *root, elem x)
{
	//make a new node pointer for the tree
	TREE_PTR new_node;

	//return false if the tree isn't empty
	if(!TR_empty(*root))
		return False;
	
	
	//malloc memory for it
	new_node = (TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(!new_node)
	{
		printf("\nUnable to allocate memory.");
		return False;
	}
	
	//putting the right values on the members of the node
	new_node -> data = x;
	new_node -> left = NULL;
	new_node -> right = NULL;
	
	//making the root pointer point to the new_node that is now the root of the tree
	*root = new_node;
	return True;
}//check


//insert a node as a left child
int TR_insert_left(TREE_PTR node, elem x)
{
	TREE_PTR new_node;
	
	if(node -> left != NULL)
		return False;
	
	
	new_node = (TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(!new_node)
	{
		printf("\nUnable to allocaet memory.");
		return False;
	}
	//puting the right values on the members of the new left child
	new_node -> data = x;
	new_node -> left = NULL;
	new_node -> right = NULL;
	//making node.left point to the new node
	node -> left = new_node;
	
	return True;
}//check


//insert a node as a right child
int TR_insert_right(TREE_PTR node, elem x)
{
	TREE_PTR new_node;
	
	if(node -> right != NULL)
		return False;
	
	
	new_node = (TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(!new_node)
	{
		printf("\nUnable to allocaet memory.");
		return False;
	}
	//puting the right values on the members of the new right child
	new_node -> data = x;
	new_node -> left = NULL;
	new_node -> right = NULL;
	//making node.right point to the new node
	node -> right = new_node;
	
	return True;
}//check


//deleting the root if it doesn't have children

int TR_del_root(TREE_PTR *root, elem *x)
{
	if((*root) -> left != NULL || (*root) -> right != NULL)
		return False;
	
	*x = (*root) -> data;
	free(*root);
	*root = NULL;
	return True;
}

//deleting the left child of a parent if it has no kids
int TR_del_left_child(TREE_PTR parent, elem *x)
{
	if(parent -> left == NULL)
		return False;
	if(parent -> left -> left != NULL || parent -> left -> right != NULL)
		return False;
		
	*x = parent -> left -> data;
	free(parent -> left);
	parent -> left = NULL;
	return True;
}

//deleting the right child of a parent if it has no kids
int TR_del_right_child(TREE_PTR parent, elem *x)
{
	if(parent -> right == NULL)
		return False;
	if(parent -> right -> left != NULL || parent -> right -> right != NULL)
		return False;
	
	*x = parent -> right -> data;
	free(parent -> right);
	parent -> right = NULL;
	return True;
}


//temp
void TR_print_node(TREE_PTR v)
{
	printf("%d ",v->data);
}//check

//print on the preorder path
void TR_preorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_print_node(v);
		TR_preorder(v -> left);
		TR_preorder(v -> right);
	}
}//check

//print on the inorder path
void TR_inorder(TREE_PTR v)
{
	if(v != NULL)
	{
		TR_inorder(v -> left);
		TR_print_node(v);
		TR_inorder(v -> right);
	}
}//check

//print on the postorder path
void TR_postorder(TREE_PTR v)
{
	if(v != NULL)
	{
		TR_postorder(v -> left);
		TR_postorder(v -> right);
		TR_print_node(v);
	}
}//check

//searching a value inside a BST
int TR_search_BST(TREE_PTR root, elem x)
{
	TREE_PTR current;
	current = root;
	while(current!=NULL)
	{
		if(current -> data == x)
			return True;
		else if(current -> data > x)
		{
			current = current -> left;
		}
		else
		{
			current = current -> right;
		}
	}
	return False;
}

int TR_insert_BST(TREE_PTR *root, elem x)
{
	TREE_PTR new_node, curr_node;
	new_node = malloc(sizeof(TREE_NODE));
	new_node -> data = x;
	new_node -> left = NULL;
	new_node -> right = NULL;
	curr_node = *root;
	
	if(*root == NULL)
	{
		(*root) = new_node;	
		return True;
	}
	while(1)
	{
		if(curr_node -> data == x)
		{
			free(new_node);
			return False;
		}//check
		
		else if(x > curr_node -> data)
		{
			if(curr_node -> right == NULL)
			{
				curr_node -> right = new_node;
				return True;
			}
			else
				curr_node = curr_node -> right;
		}//check
		
		else
		{
			if(curr_node -> left == NULL)
			{
				curr_node -> left = new_node;
				return True;
			}
			else
				curr_node = curr_node -> left;
		}//check
	}
}




int TR_delete_BST(TREE_PTR *root, elem x)
{
	//If tree is empty
	if(TR_empty(*root))
		return False;
	
	TREE_PTR current, parent, nextOrdered;
	int p; 
	int temp;
	
	// 1. Search
	parent=NULL;
	current=*root;
	
	while (current!=NULL)
	{
		if (x == current->data)
			break;
		else if (x < current->data)
		{
			parent=current;
			p=1;
			current=current->left;	
		}
		else // x > current->data 
		{
			parent=current;
			p=2;
			current=current->right;
		}			
	}
	if (current==NULL)
		return False;
	
	
	//2.1 The node to be deleted has no left or right child
	if(current -> right == NULL && current -> left == NULL)
	{
		free(current);
		if(parent == NULL)
			*root = NULL;
		else
		{
			if(p == 1)
				parent -> left = NULL;
			else if(p == 2)
				parent -> right = NULL;
		}
	}

	//2.2 The NTBD has 1 left child 
	else if(current -> left != NULL && current -> right == NULL)
	{
		free(current);
		if(parent == NULL)
			*root =  NULL;
		else
		{
			if(p == 1)
			{
				parent -> left = current -> left;
			}
			else
			{
				parent -> right = current -> left;
			}
		}
	}
	
	//2.3 The NTBD has 1 right child
	else if(current -> left == NULL && current -> right != NULL)
	{
		free(current);
		if(parent == NULL)
			*root =  NULL;
		else
		{
			if(p == 1)
			{
				parent -> left = current -> right;
			}
			else
			{
				parent -> right = current -> right;
			}
		}
	}
	
	//2.4 The NTBD has 2 children
	else
	{
		//Find the next node in the inorder path
		p = 1;
		nextOrdered = current -> right;
		while(nextOrdered -> left != NULL)
		{
			parent = nextOrdered;
			nextOrdered = nextOrdered -> left;
			p = 2;
		}
		current -> data = nextOrdered -> data;
		if(p==1)
		{
			current -> right = nextOrdered -> right;
			free(nextOrdered);
		}
		else
		{
			parent -> left = nextOrdered -> right;
			free(nextOrdered);
		}
	}	
}











































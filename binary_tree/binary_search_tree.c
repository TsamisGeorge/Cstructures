#include "binary_tree.h"
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
	if(*root!= NULL)
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


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
	curr_node = (*root);
	if(TR_empty(*root))
		(*root) = new_node;
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
		else if(x < curr_node -> data)
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



void TR_delete_BST(TREE_PTR *root, elem x)
{
    TREE_PTR parent_node = NULL;
    TREE_PTR curr_node = *root;

    // Find the node to be deleted and its parent
    while (curr_node != NULL && curr_node->data != x) {
        parent_node = curr_node;
        if (x < curr_node->data)
            curr_node = curr_node->left;
        else
            curr_node = curr_node->right;
    }

    // If the node is not found, return
    if (curr_node == NULL)
        return;

    // If the node has two children, replace it with its in-order successor
    if (curr_node->left != NULL && curr_node->right != NULL) {
        TREE_PTR succ_parent_node = curr_node;
        TREE_PTR succ_node = curr_node->right;
        while (succ_node->left != NULL) {
            succ_parent_node = succ_node;
            succ_node = succ_node->left;
        }
        curr_node->data = succ_node->data;
        curr_node = succ_node;
        parent_node = succ_parent_node;
    }

    // If the node has one or no children, replace it with its child (if any)
    TREE_PTR child_node = NULL;
    if (curr_node->left != NULL)
        child_node = curr_node->left;
    else if (curr_node->right != NULL)
        child_node = curr_node->right;
    if (parent_node == NULL)
        *root = child_node;
    else if (parent_node->left == curr_node)
        parent_node->left = child_node;
    else
        parent_node->right = child_node;

    // Free the memory allocated for the deleted node
    free(curr_node);
}

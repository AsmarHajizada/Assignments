#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int value)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node -> value = value;
	node -> left = NULL;
	node -> right = NULL;
	return (node);
}


int findMaxSum(struct Node* iter)
{
	if (iter == NULL)	
	{
		return 0;	
	}
	int left = findMaxSum(iter -> left);
	int right = findMaxSum(iter -> right);
	if (left > right)
	{
		return left + iter -> value;
	}
	else	
	{ 
		return right + iter -> value;	
	}
}

int main()
{
	struct Node* root = newNode(1);
	root -> left = newNode(5);
	root -> right = newNode(10);
	root -> left -> left = newNode(20);
	root -> left -> left -> left = newNode(999);
	root -> left -> right = newNode(4);
	root -> right -> right = newNode(20);
	root -> right -> right -> right = newNode(15);
	root -> right -> left = newNode(21);
	root -> right -> left -> left = newNode(13);

	printf("Max path sum is: %d\n", findMaxSum(root));

	return 0;
}

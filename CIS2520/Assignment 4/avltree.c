/*
Name: Junyan Chen
Student ID: 1026737
Assignemnt 4
Date: November 26,2018
*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct structNodes{

	int height;
	int counter;
	char key[500];
	struct structNodes *left;
	struct structNodes *right;

}structNodes;


/*prototypes*/
structNodes *findKey(char *key, structNodes *node);
structNodes *insertNode(char *key, structNodes *node);
structNodes *deleteNode(char *key, structNodes *root);
int height(structNodes *node);
int max(int value1, int value2);
structNodes *min(structNodes *value);
structNodes *rotateRightS(structNodes *node);
structNodes *rotateLeftS(structNodes *node);
structNodes *rotateRightD(structNodes *node);
structNodes *rotateLeftD(structNodes *node);
int getBalance(structNodes *node);

/*main function prototypes*/

structNodes *fileOpen(structNodes *node, char *fileName);
void findK(structNodes *nodes);
void insertK(structNodes *node);
void removeK(structNodes *node);
int size(structNodes *node);
void findAll(structNodes * node);
void inorderFrequency(structNodes *node, int num);


/*finding the node insdie the tree*/
structNodes *findKey(char *key, structNodes *node){

	if(node == NULL )
	{
		return NULL;
	}

	/*/if the key is smaller than the key that's inside the tree
	return the key that's in the lett side of the tree*/
	if(strcmp(key, node->key) < 0)
	{
		return findKey(key, node->left);
	}

	/*if the key is bigger than the key that's insde the tree
	return the key that's in the right side of the tree*/
  else if(strcmp(key, node->key) > 0)
  {
		return findKey(key, node->right);
	}

	else
	{
		return node;
	}
}



/*insert a node insde the tree*/
structNodes *insertNode(char *key, structNodes *node){

	if(node == NULL)
	{

		node = (structNodes*)malloc(sizeof(structNodes));

		if(node == NULL){

				printf("MEMEORY ERROR\n");
				return NULL;
		}

		/*creating a node*/
		node->height = 1;
		node->counter = 0;
		strcpy(node->key, key);
		node->left = NULL;
		node->right = NULL;

	}

	/*if the key and previous key are the same increase the counter by 1*/
	if(strcmp(key, node->key)== 0)
	{
		(node->counter)++;
	}
	/*inserting the node to the left(*/
	else if(strcmp(key, node->key) < 0)
	{
		node->left = insertNode(key, node->left);

		/*if height of the right side and the left side is the same = 2*/
  	if(height(node->left) - height(node->right) == 2)
  	{

			/*if the key is less than the key that's on the left side of the tree*/
			if(strcmp(key, node->left->key)< 0)
  		{
				/*sinlge rotate to the left*/
				node = rotateLeftS(node);
    	}
    	else
    	{
				/*double rotate to the right*/
      	node = rotateLeftD(node);
    	}
    }
	}

	/*inserting the node to the right*/
	else if (strcmp(key, node->key) > 0)
	{
		node->right = insertNode(key,node->right);

		/*if height of the right side and the left side is the same = 2*/
    if(height(node->right) - height(node->left) == 2)
    {
			/*if the key is bigger than the key that's on the right side of the tree*/
      if(strcmp(key, node->right->key) > 0)
      {
				/*sinlge rotate to the right*/
        node = rotateRightS(node);
      }
      else
      {
				/*double rottate to the right*/
        node = rotateRightD(node);
      }
    }
	}

	  /*update the height of this node*/
    node->height = 1 + (max(height(node->left), height(node->right))) ;


return node;
}

/*remove a node*/
structNodes *deleteNode(char *key, structNodes *root)
{

	if(root == NULL)
	{
		return root;
	}

	/*if the key is smaller then the key on the tree*/
	if(strcmp(key, root->key) < 0)
	{
		/*delet the key on the left side of the tree*/
		root->left = deleteNode(key, root->left);

	}
	/*if the key is bigger then the key on the tree*/
	else if(strcmp(key,root->key) > 0)
	{
		/*delet the key on the right side of the tree*/
		root->right = deleteNode(key, root->right);

	}
	else
	{
		/*if both side of three is NULL, with a cild or no cild*/
		if(root->left == NULL || root->right == NULL)
		{
			structNodes *temp;
			temp = root->left ? root->left: root->right;

			/*When there's no cild*/
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				/*copy the content of the non-child case*/
				*root = *temp;
			}
				free(temp);

		}
		else
		{

			structNodes *temp;

			/*smalest to the irght subtree (inorder)*/
			temp = min(root->right);

			/*copy the in inorder to the root->key*/
			strcpy(root->key,temp->key);

			/*deleting the inorder*/
			root->right = deleteNode(temp->key, root->right);
		}
	}

	if(root == NULL)
	{
		return root;
	}

	/*updating the height of the current node*/
	root->height = max(height(root->left),height(root->right)) + 1;

	int balance = getBalance(root);

	/*There will be 4 cases to do when the root become unbalacnes*/

	if(balance > 1 && getBalance(root->left) >= 0)
	{
		return rotateRightS(root);
	}


	if(balance > 1 && getBalance(root->left) < 0)
	{
		root->left = rotateLeftS(root->left);
		return rotateRightS(root);
	}

	if(balance < -1 && getBalance(root->right) <= 0)
	{

		return rotateLeftS(root);
	}

	if(balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rotateRightS(root->right);
		return rotateLeftS(root);
	}

	return root;
}


/*finding the  of the tree*/
int height(structNodes *node)
{
	if(node == NULL)
	{
		return -1;
	}

	return node->height;
}

/*finding the max number*/
int max(int value1, int value2)
{
	int num;
	if(value1 > value2)
	{
		num = value1;
	}else
	{
		 num = value2;
	}

	return num;
}

/*finfin the min number*/
structNodes *min(structNodes *value)
{
	structNodes *current;

	current = value;

	while(current->left !=NULL)
	{
		current = current->left;
	}
		return current;

}

/* right rotate once*/
structNodes *rotateRightS(structNodes *node)
{

	structNodes *current = NULL;

	current = node->right;
	node->right = current->left;
	current->left = node;

  /*updating the height*/
	node->height = (max(height(node->left),height(node->right)))+1;
	current->height = (max(height(current->right),node->height))+1;

	return current;
}

/*left rotate once*/
structNodes *rotateLeftS(structNodes *node)
{
	structNodes *current = NULL;

	current = node->left;
	node->left = current->right;
	current->right = node;

	/*updating the height*/
	node->height = (max(height(node->left),height(node->right)))+1;
	current->height = (max(height(current->left), node->height))+1;

	return current;
}

/*right rotate twice*/
structNodes *rotateRightD(structNodes *node)
{
	node->right = rotateLeftS(node->right);
	return rotateRightS(node);

}

/*left rotate twice*/
structNodes *rotateLeftD(structNodes *node)
{
	node->left = rotateRightS(node->left);
	return rotateLeftS(node);

}

/*balance the tree if unbalanced*/
int getBalance(structNodes *node)
{
	if( node == NULL)
	{
		return 0;
	}

	return (height(node->left) - height(node->right));
}



int main()
{

	structNodes* node = NULL;
	int userInput = 0;
	int counter = 0;

  while (userInput != 7)
  {
		printf("1. Initializaiton\n");
		printf("2. Find\n");
		printf("3. Insert\n");
		printf("4. Remove\n");
		printf("5. Check Height, Size and Total Count\n");
		printf("6. Find ALL(Above a given frequency\n");
		printf("7. Exit\n");

		printf("avl/> ");
		scanf("%d", &userInput);

    if(userInput == 1)
    {

			FILE* fp;
			char word[1000];
			char* token;
			char space[1000]= " ";



			/*open hthe file*/
			fp = fopen("A4_data_f18.txt", "r");

			if(fp == NULL)
			{
				printf("Could not open file\n");

			}

			while(fgets(word,1000,fp) != NULL)
			{
				/*initialize the token to key when it sees a spcae " "*/
				token = strtok(word, space);

				do{

					if(strlen(token) > 1){

					/*if it reads a a new linen, delet it,
					and covert to an entire entire*/
					if (token[strlen(token)-1] == '\n')
					{
						token[strlen(token)- 1] = '\0';
					}

							node = insertNode(token, node);
							counter++;
				  }

					token = strtok(NULL, "\n ");



				}while(token != NULL);

			}
			fclose(fp);

}

    else if(userInput == 2)
    {
			if(node == NULL)
			{
				printf("ERROR\n");
				printf("\n");
			}
			else{
      	/*find the key*/
				findK(node);
				printf("\n");
			}

    }else if(userInput == 3)
    {
			if(node == NULL)
			{
				printf("ERROR\n");
				printf("\n");
			}
			else
			{
      	/*insert the key*/
				insertK(node);
				counter++;
				printf("\n");
			}
    }else if(userInput == 4)
    {
			if(node == NULL)
			{
				printf("ERROR\n");
				printf("\n");
			}
			else
			{
				/*remvoing a node*/
				removeK(node);
				counter--;
				printf("\n");
			}

    }else if (userInput == 5)
    {
			if(node == NULL)
			{
				printf("ERROR\n");
				printf("\n");
			}
			else
			{
			/*find the height and checking the tree size and the total count*/
				printf("Height: %d, Size: %d, Total Count: %d\n", height(node),size(node),counter);
				printf("\n");
			}

    }else if(userInput == 6)
    {
			if(node == NULL)
			{
				printf("ERROR\n");
				printf("\n");
			}
			else
			{
				/*find the frequencies*/
				findAll(node);
				printf("\n");
			}
    }else
    {
        exit(-1);
    }
  }

		return 0;

}


void findK(structNodes *node)
{
	char key[100];
	structNodes *findTheKey;


	printf("find key:");
	scanf("%s",key );

	findTheKey= findKey(key, node);

	if(findTheKey == NULL)
	{
		printf("No_such_key\n");
	}
	else
	{
		printf("Key: %s, Frequency: %d", key, findTheKey->counter);
	}

}


void insertK(structNodes *node)
{
	char key[100];
	structNodes *findTheKey;

	printf("insert key:");
	scanf("%s",key);


	findTheKey = findKey(key, node);

	if(findTheKey != NULL)
	{
		findTheKey->counter++;
	}
	else
	{
		node = insertNode(key, node);
	}

	findTheKey = findKey(key, node);
	printf("Key: %s, Frequency: %d", key, findTheKey->counter);

}


void removeK(structNodes *node)
{
	char key[100];
	structNodes *findTheKey;

	printf("remove key:");
	scanf("%s", key);


	findTheKey = findKey(key, node);

	if(findTheKey == NULL)
	{
		printf("No_such_key\n");
	}
	else if(findTheKey->counter == 1)
	{
		node = deleteNode(key, node);
		printf("Key: %s, Frequency: %d", key, findTheKey->counter);
	}
	else
	{
		findTheKey->counter --;
		printf("Key: %s, Frequency: %d", key, findTheKey->counter);
	}


}


int size(structNodes *node)
{
	int c = 1;

	if(node == NULL)
	{
		return 0;
	}

	/*recursive calls to it's function to find the left nd right node
	and adding all the nodes toether in the tree to find the total size*/
	c += size(node->right) + size(node->left) ;

	return c;

}


void findAll(structNodes * node)
{
	int userInput;

	printf("Frequency: ");
	scanf("%d", &userInput);

	inorderFrequency(node, userInput);

}

/*find the the frequency in inorder*/
void inorderFrequency(structNodes *node, int num)
{

	if(node == NULL)
	{
		return;
	}

 	inorderFrequency(node->left, num);

	if(node->counter >= num)
	{
			printf("Key: %s, Frequency: %d\n", node->key, node->counter);
	}

 	inorderFrequency(node->right, num);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// comparator from previous question
int numberPlateCompare(char *plate1, char *plate2) {
	char x, y;
	for (int i = 0; i < 6; ++i) {
		x = *plate1++, y = *plate2++;
		if (x != y) return x < y;
	}
	// if same, return 2
	return 2;
}

typedef struct BST_Node {
	struct BST_Node *parent, *child[2];
	char number[7];
} BST_Node;

// create BST, global variables required in order to call
// BST_insert and BST_search with only one argument `numberPlate`

BST_Node * BST_Node_init(char *numberPlate, BST_Node *parent) {
	BST_Node *node = (BST_Node *)malloc(sizeof(BST_Node));
	node->parent = parent, node->child[0] = node->child[1] = NULL;
	strcpy(node->number, numberPlate);
	return node;
}

// assumes distinct numberPlate values
void BST_insert(char *numberPlate, BST_Node ** bst, int *node_count) {
	++(*node_count);
	if (*bst == NULL) {
		*bst = BST_Node_init(numberPlate, (BST_Node *)NULL);
		return;
	}
	BST_Node *parent = *bst, *curr = *bst;
	while (1) {
		int val = numberPlateCompare(parent->number, numberPlate);
		curr = parent->child[val];
		if (curr == NULL) {
			parent->child[val] = BST_Node_init(numberPlate, parent);
			return;
		}
		parent = curr;
	}
}

void BST_search(char *numberPlate, BST_Node ** bst, char **stack) {
	int stack_size = 0;
	BST_Node *parent = *bst, *curr = *bst;
	while (1) {
		if (parent == NULL) {
			puts("0");
			return;
		}
		int val = numberPlateCompare(parent->number, numberPlate);
		if (val == 2) {
			putchar('1');
			putchar(' ');
			for (int i = 0; i < stack_size; ++i) putchar((*stack)[i]);
			putchar('\n');
			return;
		}
		curr = parent->child[val];
		(*stack)[stack_size++] = val ? 'R' : 'L';
		parent = curr;
	}
}

// useful for debugging BST
void in_order_dfs(BST_Node *node) {
	if (!node) return;
	if (node->child[0]) {
		putchar('<');
		in_order_dfs(node->child[0]);
	}
	printf("%s ", node->number);
	if (node->child[1]) {
		putchar('>');
		in_order_dfs(node->child[1]);
	}
	putchar('^');
}

int main() {
	char* firstLine = NULL;
	char* inputLine = NULL;
	size_t length = 0, counter = 0, plateLength = 6;
	char choice, numberPlate[7];


	// Fetching only the first line of input.
	length = getline(&firstLine, &length, stdin);

	// Parsing the string word by word. 
	BST_Node *bst = NULL;
    char *stack;
    int node_count = 1;
	while (counter < length) {
		strncpy(numberPlate, &firstLine[counter], plateLength);
		numberPlate[plateLength] = '\0';
		counter += plateLength + 1; // The +1 takes care of the space between words.

		// Call your BST Insert function here with argument: numberPlate
		BST_insert(numberPlate, &bst, &node_count);
		// debug
		//in_order_dfs(bst); putchar('\n');
	}

	// allocate memory for stack storing the path in case of valid element in BST
	stack = malloc(sizeof(char) * node_count);


	// Main input handler to serve requests.
	while (getline(&inputLine, &length, stdin) != -1) {
		sscanf(inputLine, "%c %s", &choice, numberPlate);
		if(choice == 'S') {

			// Call your BST Search function here with argument: numberPlate
			BST_search(numberPlate, &bst, &stack);

		}
		free(inputLine); inputLine = NULL;
		length = 0;
	}
	return 0;

}

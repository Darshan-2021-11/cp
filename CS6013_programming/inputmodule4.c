#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int numberPlateCompare(char *plate1, char *plate2) {
	char x, y;
	for (int i = 0; i < 6; ++i) {
		x = *plate1++, y = *plate2++;
		if (x != y) return x < y;
	}
	return 2;
}

typedef struct BST_Node {
	struct BST_Node *parent, *child[2];
	char number[7];
} BST_Node;

BST_Node * BST_Node_init(char *numberPlate, BST_Node *parent) {
	BST_Node *node = malloc(sizeof(BST_Node));
	node->parent = parent;
	node->child[0] = node->child[1] = NULL;
	strcpy(node->number, numberPlate);
	return node;
}

void BST_transplant(BST_Node **root, BST_Node *u, BST_Node *v) {
	if (u->parent == NULL) {
		*root = v;
	} else if (u == u->parent->child[0]) {
		u->parent->child[0] = v;
	} else {
		u->parent->child[1] = v;
	}
	if (v) v->parent = u->parent;
}

BST_Node* BST_minimum(BST_Node* node) {
	while (node && node->child[0]) node = node->child[0];
	return node;
}

BST_Node* BST_maximum(BST_Node* node) {
	while (node && node->child[1]) node = node->child[1];
	return node;
}

int BST_insert(char *numberPlate, BST_Node ** bst) {
	if (*bst == NULL) {
		*bst = BST_Node_init(numberPlate, NULL);
		return 1;
	}
	BST_Node *parent = *bst, *curr = *bst;
	while (1) {
		int val = numberPlateCompare(parent->number, numberPlate);
		if (val == 2) return 0;
		curr = parent->child[val];
		if (curr == NULL) {
			parent->child[val] = BST_Node_init(numberPlate, parent);
			return 1;
		}
		parent = curr;
	}
}

BST_Node* BST_find(BST_Node *node, char *key) {
	while (node) {
		int cmp = numberPlateCompare(node->number, key);
		if (cmp == 2) return node;
		node = node->child[cmp];
	}
	return NULL;
}

void BST_search_and_print_path(char *numberPlate, BST_Node *bst) {
	if (!bst) {
		puts("0");
		return;
	}

	int cap = 256;
	char *stack = malloc(cap);
	int sz = 0;

	BST_Node *p = bst, *c = bst;
	while (1) {
		if (!p) {
			puts("0");
			free(stack);
			return;
		}

		int val = numberPlateCompare(p->number, numberPlate);
		if (val == 2) {
			putchar('1');
			if (sz > 0) {
				putchar(' ');
				for (int i = 0; i < sz; ++i)
					putchar(stack[i]);
			}
			putchar('\n');
			free(stack);
			return;
		}

		if (sz + 1 >= cap) {
			cap *= 2;
			stack = realloc(stack, cap);
		}

		c = p->child[val];
		stack[sz++] = val ? 'R' : 'L';
		p = c;
	}
}

BST_Node* BST_predecessor(BST_Node *root, char *key) {
	BST_Node *c = root, *pred = NULL;
	while (c) {
		int cmp = numberPlateCompare(c->number, key);
		if (cmp == 2) {
			if (c->child[0]) return BST_maximum(c->child[0]);
			return pred;
		}
		if (cmp == 1) {
			pred = c;
			c = c->child[1];
		} else {
			c = c->child[0];
		}
	}
	return pred;
}

BST_Node* BST_successor(BST_Node *root, char *key) {
	BST_Node *c = root, *succ = NULL;
	while (c) {
		int cmp = numberPlateCompare(c->number, key);
		if (cmp == 2) {
			if (c->child[1]) return BST_minimum(c->child[1]);
			return succ;
		}
		if (cmp == 0) {
			succ = c;
			c = c->child[0];
		} else {
			c = c->child[1];
		}
	}
	return succ;
}

void BST_inorder(BST_Node *node, int *first) {
	if (!node) return;
	if (node->child[0]) BST_inorder(node->child[0], first);
	if (!(*first)) putchar(' ');
	fputs(node->number, stdout);
	*first = 0;
	if (node->child[1]) BST_inorder(node->child[1], first);
}

void BST_postorder(BST_Node *node, int *first) {
	if (!node) return;
	if (node->child[0]) BST_postorder(node->child[0], first);
	if (node->child[1]) BST_postorder(node->child[1], first);
	if (!(*first)) putchar(' ');
	fputs(node->number, stdout);
	*first = 0;
}

void BST_free(BST_Node *node) {
	if (!node) return;
	if (node->child[0]) BST_free(node->child[0]);
	if (node->child[1]) BST_free(node->child[1]);
	free(node);
}

int main(void) {

	char *firstLine = NULL;
	size_t flen = 0;

	ssize_t r = getline(&firstLine, &flen, stdin);
	if (r == -1) {
		free(firstLine);
		return 0;
	}
	if (firstLine[r-1] == '\n')
		firstLine[r-1] = '\0';

	BST_Node *bst = NULL;

	char *tok = strtok(firstLine, " ");
	while (tok) {
		char tmp[7] = {0};
		strncpy(tmp, tok, 6);
		tmp[6] = '\0';
		BST_insert(tmp, &bst);
		tok = strtok(NULL, " ");
	}

	char *line = NULL;
	size_t llen = 0;

	while (getline(&line, &llen, stdin) != -1) {

		char op = 0;
		char plate[16] = {0};

		int items = sscanf(line, " %c %15s", &op, plate);

		if (items < 1) {
			free(line);
			line = NULL;
			llen = 0;
			continue;
		}

		char tmp[7] = {0};
		strncpy(tmp, plate, 6);
		tmp[6] = '\0';

		switch (op) {

			case 'S':
				BST_search_and_print_path(tmp, bst);
				break;

			case '<': {
									BST_Node *p = BST_predecessor(bst, tmp);
									if (!p) puts("0");
									else printf("%s\n", p->number);
									break;
								}

			case '>': {
									BST_Node *s = BST_successor(bst, tmp);
									if (!s) puts("0");
									else printf("%s\n", s->number);
									break;
								}

			case '+':
								BST_insert(tmp, &bst);
								break;

			case '-': {
									BST_Node *z = BST_find(bst, tmp);
									if (!z) {
										puts("-1");
										break;
									}

									int children = 0;
									if (z->child[0]) children++;
									if (z->child[1]) children++;

									if (children == 0) {
										BST_transplant(&bst, z, NULL);
										free(z);
										puts("0");
									} else if (children == 1) {
										BST_Node *t = z->child[0] ? z->child[0] : z->child[1];
										printf("1 %s\n", t->number);
										BST_transplant(&bst, z, t);
										free(z);
									} else {
										BST_Node *y = BST_minimum(z->child[1]);
										printf("2 %s\n", y->number);
										if (y->parent != z) {
											BST_transplant(&bst, y, y->child[1]);
											y->child[1] = z->child[1];
											if (y->child[1]) y->child[1]->parent = y;
										}
										BST_transplant(&bst, z, y);
										y->child[0] = z->child[0];
										if (y->child[0]) y->child[0]->parent = y;
										free(z);
									}
									break;
								}

			case 'I': {
									int first = 1;
									BST_inorder(bst, &first);
									putchar('\n');
									break;
								}

			case 'P': {
									int first = 1;
									BST_postorder(bst, &first);
									putchar('\n');
									break;
								}

			default:
								break;
		}

		free(line);
		line = NULL;
		llen = 0;
	}

	BST_free(bst);
	free(firstLine);
	return 0;
}

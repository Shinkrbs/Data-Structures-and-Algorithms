#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _tnode {
    Element data;
    struct _tnode *left, *right;
} *TNODE;

typedef struct _bst {
    TNODE root;
} *BST;

BST createBST() {
    BST my = (BST)malloc(sizeof(struct _bst));
    my->root = NULL;
    return my;
}

void insertBSTNode(TNODE root, Element data) {
    if (data > root->data) {
        if (root->right == NULL) {
            root->right = (TNODE)malloc(sizeof(struct _tnode));
            root->right->data = data;
            root->right->left = root->right->right = NULL;
        } else {
            insertBSTNode(root->right, data);
        }
    } else {
        if (root->left == NULL) {
            root->left = (TNODE)malloc(sizeof(struct _tnode));
            root->left->data = data;
            root->left->left = root->left->right = NULL;
        } else {
            insertBSTNode(root->left, data);
        }
    }
}

void insert(BST tree, Element data) {
    if (tree->root) {
        insertBSTNode(tree->root, data);
    } else {
        tree->root = (TNODE)malloc(sizeof(struct _tnode));
        tree->root->data = data;
        tree->root->left = tree->root->right = NULL;
    }
}

void preorder(TNODE root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void preorderBST(BST tree) {
    printf("Preorder: ");
    preorder(tree->root);
    printf("\n");
}

void inorder(TNODE root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void inorderBST(BST tree) {
    printf("Inorder: ");
    inorder(tree->root);
    printf("\n");
}

void postorder(TNODE root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void postorderBST(BST tree) {
    printf("Postorder: ");
    postorder(tree->root);
    printf("\n");
}

int computeHeight(TNODE root) {
    if (root == NULL)
        return 0;
    int hl = computeHeight(root->left);
    int hr = computeHeight(root->right);
    return (hl > hr) ? hl + 1 : hr + 1;
}

int computeHeightBST(BST tree) {
    return computeHeight(tree->root);
}

TNODE delete(TNODE root, Element target) 
{
    if (root == NULL) return NULL;

    if (target < root->data) {
        root->left = delete(root->left, target);
    } else if (target > root->data) {
        root->right = delete(root->right, target);
    } else {
        // Node to delete found
        if (root->left == NULL) {
            TNODE temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TNODE temp = root->left;
            free(root);
            return temp;
        } else {
            // Node with two children: get the inorder successor (smallest in the right subtree)
            TNODE largest_left = root->left;
            while (largest_left->right != NULL) {
                largest_left = largest_left->right;
            }
            // Copy the inorder successor's content to this node
            root->data = largest_left->data;
            // Delete the inorder successor
            root->left = delete(root->left, largest_left->data);
        }
    }
    return root;
}

void deleteBST(BST tree, Element target) {
    tree->root = delete(tree->root, target);
}

int main() {
    BST t = createBST();
    insert(t, 70);
    insert(t, 59);
    insert(t, 69);
    insert(t, 45);
    insert(t, 33);
    insert(t, 95);
    insert(t, 125);
    insert(t, 26);
    insert(t, 200);

    preorderBST(t);
    inorderBST(t);
    postorderBST(t);

    printf("Height of BST: %d\n", computeHeightBST(t));

    return 0;
}

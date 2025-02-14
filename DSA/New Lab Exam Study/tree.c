#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node
{
    element data;
    struct node *left, *right;
}*NODE;

typedef struct bst
{
    NODE root;
}*BST;

NODE createNode()
{
    NODE x = (NODE)malloc(sizeof(struct node));
    x->left = x->right = NULL;
    return x;
}

BST createBST()
{
    BST x = (BST)malloc(sizeof(struct bst));
    x->root = NULL;
    return x;
}

void insert(NODE root, element data)
{
    NODE new = createNode();
    new->data = data;
    
    if(data > root->data)
    {
        if(root->right == NULL)
            root->right = new;
        else    
            insert(root->right, data);
    }
    else
    {
        if(root->left == NULL)
            root->left = new;
        else    
            insert(root->left, data);
    }
}

void insertBST(BST tree, element data)
{
    if(tree->root == NULL)
    {
        NODE new = createNode();
        new->data = data;
        tree->root = new;
    }
    else
        insert(tree->root, data);
}

NODE search(NODE root, element target, int* ctr)
{
    if(root == NULL) return NULL;

    (*ctr)++;
    if(target < root->data)
        return search(root->left, target, ctr);
    else if(target > root->data)
        return search(root->right, target, ctr);
    else
        return root;
}

void searchBST(BST tree, element target)
{
    int ctr = 0;
    NODE temp = search(tree->root, target, &ctr);
    if(temp->data == target)
        printf("Data Found, Comparisons: %d\n", ctr);
    else
        printf("Data Not Found, Comparisons: %d\n", ctr);
}

NODE delete(NODE root, element target)
{
    if(root == NULL) return root;
    if(target < root->data)
        return delete(root->left, target);
    else if(target > root->data)
        return delete(root->right, target);
    else
    {
        if(root->left == NULL)
        {
            NODE temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            NODE temp = root->left;
            free(root);
            return temp;
        }

        // If the target is an internal node
        NODE largest_left = root->left;
        while(largest_left->right != NULL)
            largest_left = largest_left->right;
        root->data = largest_left->data;
        root->left = delete(root->left, largest_left->data);
    }
}

void deleteBST(BST tree, element target)
{
    if(tree->root == NULL) return;
    tree->root = delete(tree->root, target);
}

void preorder(NODE root)
{
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void preorderBST(BST tree)
{
    printf("Preorder: ");
    preorder(tree->root);
    printf("\n");
}

void inorder(NODE root)
{
    if(root  == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void inorderBST(BST tree)
{
    printf("Inorder: ");
    inorder(tree->root);
    printf("\n");
}

void postorder(NODE root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void postorderBST(BST tree)
{
    printf("Postorder: ");
    postorder(tree->root);
    printf("\n");
}

int height(NODE root)
{
    if(root == NULL) return 0;
    int hl = height(root->left);
    int hr = height(root->right);

    return ((hl > hr) ? hl : hr) + 1;
}

void heightBST(BST tree)
{
    printf("Height of tree: %d\n", height(tree->root));
}

int balance_factor(NODE root)
{
    if(root == NULL) return 0;
    return height(root->left) - height(root->right);
}

void balance_factorBST(BST tree)
{
    printf("Balance Factor: %d\n", balance_factor(tree->root));
}

int total_nodes(NODE root)
{
    if(root == NULL) return 0;
    int l = total_nodes(root->left);
    int r = total_nodes(root->right); 

    return l + r + 1;
}

void total_nodesBST(BST tree)
{
    printf("Total Nodes: %d\n", total_nodes(tree->root));
}

int leaves(NODE root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return leaves(root->left) + leaves(root->right);
}

void leavesBST(BST tree)
{
    printf("Total Leaves: %d\n", leaves(tree->root));
}

int level_node(NODE root, element target, int level)
{
    if(root == NULL) return 0;
    if(root->data == target) return level;

    // Check subtrees
    int left_lev = level_node(root->left, target, level++);
    if(left_lev != 0)
        return left_lev;
    return level_node(root->right, target, level++);
}

void level_nodeBST(BST tree, element target)
{
    int res = level_node(tree->root, target, 1);
    if(res != 0)
        printf("Level of %d: %d\n", target, res);
    else
        printf("Data Not Found!\n");
}

void disp_leaves(NODE root)
{
    if(root == NULL) return;
    if(root->right == NULL && root->left == NULL)
    {
        printf("%d ", root->data);
        return;
    }
    disp_leaves(root->right);
    disp_leaves(root->left);
}

void disp_leavesBST(BST tree)
{
    printf("Leaves: ");
    disp_leaves(tree->root);
    printf("\n");
}

element maxVal(BST tree)
{
    if(tree->root == NULL) return 0;
    NODE p = tree->root;
    while(p->right != NULL)
        p = p->right;
    return p->data;
}

element minVal(BST tree)
{
    if(tree->root == NULL) return 0;
    NODE p = tree->root;
    while(p->left != NULL)
        p = p->left;
    return p->data;
}

int main()
{
    BST tree = createBST();

    insertBST(tree, 10);
    insertBST(tree, 12);
    insertBST(tree, 8);
    insertBST(tree, 9);
    insertBST(tree, 2);
    insertBST(tree, 3);
    insertBST(tree, 7);
    insertBST(tree, 11);
    insertBST(tree, 14);

    preorderBST(tree);
    inorderBST(tree);
    postorderBST(tree);
    balance_factorBST(tree);
    level_nodeBST(tree, 3);
    leavesBST(tree);
    disp_leavesBST(tree);

    printf("Maximum Value: %d\n", maxVal(tree));
    printf("Minimum Value: %d\n", minVal(tree));
    return 0;
}
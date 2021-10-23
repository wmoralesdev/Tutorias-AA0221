#include <iostream>
using namespace std;

struct node {
    int data;

    node* left, *right;

    node() {
        left = right = NULL;
    }

    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void inOrder(node* tree);
void preOrder(node* tree);
void postOrder(node* tree);
void insertBST(int data, node** tree);

int main(void) {
    // Pointer -> To modify a ptr you should send a mem address
    node* tree = NULL;
    int x = 0;
    // &x; -> ptr -> dir mem var
    // &tree; -> ptr ptr -> dir mem ptr -> dir mem dir mem

    while(cin >> x) {
        insertBST(x, &tree);
    }

    inOrder(tree);
    cout << endl;

    return 0;
}

/*
    insertBst(data, tree)
        if tree is null:
            tree = node(data)
        else:
            if data <= tree.data:
                insertBst(data, tree.left)
            else:
                insertBst(data, tree.right)
*/
void insertBST(int data, node** tree) {
    if (!*tree)
        *tree = new node(data);
    else {
        if(data <= (*tree)->data)
            insertBST(data, &(*tree)->left);
        else
            insertBST(data, &(*tree)->right);
    }
}

/*
    inOrder(tree)
        if tree is not null:
            inOrder(tree.left)
            print(tree.data)
            inOrder(tree.right)
*/
void inOrder(node* tree) {
    if (tree) {
        // Left
        inOrder(tree->left);

        // Root
        cout << tree->data << "\t";

        // Right
        inOrder(tree->right);
    }
}

/*
    preOrder(tree)
        if tree is not null:
            print(tree.data)
            preOrder(tree.left)
            preOrder(tree.right)
*/
void preOrder(node* tree) {
    if (tree) {
        // Root
        cout << tree->data << "\t";

        // Left
        preOrder(tree->left);

        // Right
        preOrder(tree->right);
    }
}

/*
    postOrder(tree)
        if tree is not null:
            postOrder(tree.left)
            postOrder(tree.right)
            print(tree.data)
*/
void postOrder(node* tree) {
    if (tree) {
        // Left
        postOrder(tree->left);

        // Right
        postOrder(tree->right);

        // Root
        cout << tree->data << "\t";
    }
}
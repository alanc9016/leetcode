#include <iostream>
#include <queue>
#include <climits>

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *GetNewNode(int);
Node *insert(Node*,int);
Node *insertItv(Node*,int);
Node* search(Node*,int);
Node* getMin(Node*);
Node* getMax(Node*);
int height(Node*);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void bfs(Node*);
bool is_binary_search_tree(Node*,int,int);
Node *deleteNode(Node*,int);
Node *get_successor(Node*,int);

main() {
    Node *root = nullptr;

    root = insertItv(root, 2);
    root = insertItv(root, 1);
    root = insertItv(root, 3);

    /* root = insert(root, 2); */
    /* root = insert(root, 1); */
    /* root = insert(root, 3); */

    inorder(root);
}


Node *GetNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node *root, int data) {
    if (root == nullptr) 
        root = GetNewNode(data);
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else 
        root->right = insert(root->right, data);

    return root;
}

Node* search(Node *root, int data) {
    if (root == nullptr)
        return nullptr;

    if (data == root->data)
        return root;

    if (data < root->data)
        root->left = search(root->left, data);
    else
        root->right = search(root->right, data);
}

Node* getMin(Node *root) {
    if (root == nullptr)
        return root;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

Node* getMax(Node *root) {
    if (root == nullptr)
        return root;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

int height(Node *root) {
    if (root == nullptr)
        return 0;
    return std::max(height(root->left), height(root->right))+1;
}


void inorder(Node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->data << std::endl;
    inorder(root->right);
}


void preorder(Node *root) {
    if (root == nullptr) 
        return;
    std::cout << root->data << std::endl;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root) {
    if (root == nullptr) 
        return;
    preorder(root->left);
    preorder(root->right);
    std::cout << root->data << std::endl;
}

void bfs(Node *root) {
    std::queue<Node*> queue;

    queue.push(root);

    while (!queue.empty()) {
        Node *x = queue.front();
        queue.pop();
        std:: cout << x->data << std::endl;
        if (x->right)
            queue.push(x->right);
        if (x->left)
            queue.push(x->left);
    }
}


bool is_binary_search_tree(Node *root, int min_val, int max_val) {
    if (root == nullptr)
        return true;

    if (root->data > min_val && root->data < max_val
            && is_binary_search_tree(root->left, min_val, root->data)
            && is_binary_search_tree(root->right, root->data, max_val))
        return true;
    else
        return false;
    
}

Node *deleteNode(Node *root, int data) {
    if (root == nullptr)
        return root;

    if (root->data < data)
        root->right = deleteNode(root->right, data);
    else if (root->data > data)
        root->left = deleteNode(root->left, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node *temp = root;
            root = root->left;
            delete temp;
        } else {
            Node *temp = getMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

Node *get_successor(Node *root, int data) {
    Node *current = search(root, data);

    if (current == nullptr)
        return nullptr;
    if (current->right) {
        return getMin(root->right);
    } else {
        Node *successor = nullptr;
        Node *ancestor = root;

        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        return successor;
    }
}


#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node (int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    private:
    Node* root;
    
    void InsertNode(Node*& node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return;
        }

        if (key < node->key) {
            InsertNode(node->left, key);
        }
        else if(key > node->key){
            InsertNode(node->right, key);
        }
    }

    Node* SearchNode(Node* node, int key) {
        if (node == NULL) 
            return NULL;

        node = root;
        while(node != NULL) {
            if (node->key == key) {
                return node;
            }
            else if (key < node->key)
            node = node->left;
            else 
            node = node->right;
        }
        return NULL;
    }
    Node* FindMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* DeleteNode(Node*& node, int key) {
        if (node == NULL) 
            return node;
        
        
        if (key < node->key){
            node->left = DeleteNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = DeleteNode(node->right, key);
        }
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
        Node* temp = FindMin(node->right);
        node->key = temp->key;
        node->right = DeleteNode(node->right, temp->key);
        }
        return node;
    }
    void InOrderTraversal(Node* node) {
        if (node == NULL) 
        return;

        
        InOrderTraversal(node->left);
        cout << node->key << "\n";
        InOrderTraversal(node->right);

    }
    void PreOrderTraversal(Node* node) {
        if (node == NULL) 
        return;

        cout << node->key << "\n";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);

    }
    void PostOrderTraversal(Node* node){
        if (node == NULL) 
        return;

        
        PostOrderTraversal(node->left);
        PostOrderTraversal(node->right);
        cout << node->key << "\n";
    }
    void DisplayBST(Node* node) {
        if (node == NULL) {
            return;
        }
        
        DisplayBST(node->right);
        cout << node->key << "\n";
        DisplayBST(node->left);
    }

    public:
    BST() {
        this->root = NULL;
    }
    void Insert(int key) {
        InsertNode(this->root, key);
    }
    Node* Search(int key) {
        return SearchNode(this->root, key);
    }
    void Remove(int key) {
        DeleteNode(this->root, key);
    }
    void InOrder() {
        InOrderTraversal(this->root);
    }
    void PreOrder() {
        PreOrderTraversal(this->root);
    }
    void PostOrder(){
        PostOrderTraversal(this->root);
    }
    void Display() {
        DisplayBST(this->root);
    }
};

int main() {
    BST bst;
    
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.Insert(80);

    cout << "\nInorder traversal: \n\n";
    bst.InOrder();
    cout << "\nPreorder traversal: \n\n";
    bst.PreOrder();
    cout << "\nPostorder traversal: \n\n";
    bst.PostOrder();
    cout << "\nDisplaying BST:\n\n";
    bst.Display();
    
    Node* searchedNode = bst.Search(60);
    if (searchedNode == NULL) {
        cout << "Node not found in the BST\n";
    }
    else {
        cout << "Node found in the BST: " << searchedNode->key << "\n";
    }

    bst.Remove(30);
    cout << "Inorder Traversal after deleting a node: \n";
    bst.InOrder();
}
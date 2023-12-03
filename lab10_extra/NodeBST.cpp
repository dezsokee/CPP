#include "NodeBST.h"
#include <iostream>

using namespace std;

void NodeBST::inorder(NodeBST::Node *node) const {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}

void NodeBST::preorder(NodeBST::Node *node) const {
    if (node == nullptr) return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void NodeBST::postorder(NodeBST::Node *node) const {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->val << " ";
}

void NodeBST::deleteSubTree(NodeBST::Node *node) {
    if (node == nullptr) return;
    deleteSubTree(node->left);
    deleteSubTree(node->right);
    delete node;

}

NodeBST::NodeBST() {
    root = nullptr;

}

NodeBST::~NodeBST() {
    deleteSubTree(root);
}

void NodeBST::insert(int val) {
    Node *newNode = new Node(val);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node *curr = root;

    while (true) {
        if (val < curr->val) {
            if (curr->left == nullptr) {
                curr->left = newNode;
                return;
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = newNode;
                return;
            }
            curr = curr->right;
        }
    }
}

bool NodeBST::find(int val) const {
    Node *curr = root;

    while (curr != nullptr) {
        if (val == curr->val) return true;
        if (val < curr->val) curr = curr->left;
        else curr = curr->right;
    }

    return false;
}

void NodeBST::print_inorder() const {
    inorder(root);
    cout << endl;
}

void NodeBST::print_preorder() const {
    preorder(root);
    cout << endl;
}

void NodeBST::print_postorder() const {
    postorder(root);
    cout << endl;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> struct Node {
    T key;
    Node *left;
    Node *right;
};

template <class T> class BinarySearchTree {
private:
    Node<T> *root;

    void insert(T key, Node<T> *leaf) {
        if(key < leaf->key) {
            if (leaf->left != NULL) {
                insert(key, leaf->left);
            } else {
                leaf->left = new Node<T>;
                leaf->left->key = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        } else if (key >= leaf->key) {
            if(leaf->right != NULL) {
                insert(key, leaf->right);
            } else {
                leaf->right = new Node<T>;
                leaf->right->key = key;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }

    Node<T> *search(T key, Node<T> *leaf) {
        if(leaf != NULL) {
            if (key == leaf->key) {
                return leaf;
            }
            if (key < leaf->key) {
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
        } else {
            return NULL;
        }
    }

    void destroy_tree(Node<T> *leaf) {
        if (leaf != NULL) {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }
public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(T key) {
        if (root != NULL) {
            insert(key, root);
        } else {
            root = new Node<T>;
            root->key = key;
            root->left = NULL;
            root->right = NULL;
        }
    }

    Node<T> *search(T key) {
        return search(key, root);
    }

    void destroy_tree() {
        destroy_tree(root);
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}

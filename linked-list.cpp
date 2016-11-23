#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class LinkedList {
    struct Node {
        T key;
        Node *prev;
        Node *next;
    };
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool empty_list() {
        return size == 0 ? true : false;
    }

    void list_insert(T x) {
        Node *node = new Node();
        node->key = x;
        node->next = NULL;
        if (tail == NULL) {
            node->prev = NULL;
    		head = tail = node;
    	} else {
            node->prev = tail;
    		tail->next = node;
    		tail = node;
    	}
        size++;
    }

    T list_pop() {
        if (empty_list()) {
            cerr << "empty list" << endl;
            exit(EXIT_FAILURE);
        } else {
            Node *node = head;
            T ret = node->key;
            head = head->next;
            delete node;
            size--;
            return ret;
        }
    }

    void print() {
        Node *node = head;
        int count = 0;
        while (count < size) {
            cout << node->key;
            if (count == 0) {
                cout << "(HEAD)";
            }
            if (count == size - 1) {
                cout << "(TAIL)";
            }
            cout << " -> ";
            node = node->next;
            count++;
        }
        cout << "(null)" << endl;
    }
};

int main(int argc, char const *argv[]) {
    LinkedList<float> list;
    list.list_insert(5);
    list.list_insert(10);
    list.list_insert(20);
    list.print();
    cout << list.list_pop() << endl;
    cout << list.list_pop() << endl;
    list.print();
    return 0;
}

#include <iostream>
#include <stdlib.h>

using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;

        Node() : val(0), next(nullptr) {}
        Node(int v) : val(v), next(nullptr) {}
        Node(int v, Node *next) : val(v), next(next) {}
    };

    Node *head = nullptr;
    int size=0;

public:
    MyLinkedList() {}
    
    int get(int index) {
        Node *t = this->head;
        if (this->size > index) {
            for (int i=0; i<index; i++) {
                if (t == nullptr) {
                    return -1;
                }
                t = t->next;
            }
            return t->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val, this->head);
        this->head = newNode;

        this->size++;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        Node *t = this->head;
        if (this->size != 0) {
            while (t->next != nullptr) {
                t = t->next;
            }
            t->next = newNode;
        } else {
            this->head = newNode;
        }
        this->size++;
    }
    
    void addAtIndex(int index, int val) {
        Node *newNode = new Node(val);
        Node *t = this->head;
        if (this->size >= index) {
            if (index == 0) {
                if (this->size == 0) {
                    this->head = newNode;
                } else {
                    this->head = newNode;
                    newNode->next = t;
                }
                this->size++;
            } 
            else {
                int i = 0;
                while (i<index) {
                    if (i == index-1 && t->next != nullptr) {
                        newNode->next = t->next;
                        t->next = newNode;
                    } else if (i == index-1 && t->next == nullptr) {
                        t->next = newNode;
                    }
                    t = t->next;
                    i++;
                }
                this->size++;
            }  
        }
    }
    
    void deleteAtIndex(int index) {
        Node *t = this->head;
        int i = 0;
        if (this->size > index) {
            if (index == 0) {
                this->head = t->next;
                this->size--;
            } else {
                while (i<index) {
                    if (i == index-1 && t->next->next != nullptr) {
                        t->next = t->next->next;
                    } else if (i == index-1 && t->next->next == nullptr) {
                        t->next = nullptr;
                    }
                    i++;
                    t = t->next;
                }
                this->size--;
            }
        }
    }

    int getSize() {
        return this->size;
    }
};
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */

int main(int argc, char *argv[]) {
    MyLinkedList MyLinkedList;
    // MyLinkedList.addAtIndex(0, 10);
    // MyLinkedList.addAtIndex(0, 20);
    // MyLinkedList.addAtIndex(1, 30);
    // MyLinkedList.get(0);

    // MyLinkedList.addAtHead(2);
    // MyLinkedList.deleteAtIndex(1);
    // MyLinkedList.addAtHead(2);
    // MyLinkedList.addAtHead(7);
    // MyLinkedList.addAtHead(3);
    // MyLinkedList.addAtHead(2);
    // MyLinkedList.addAtHead(5);
    // MyLinkedList.addAtTail(5);
    // MyLinkedList.get(5);
    // MyLinkedList.deleteAtIndex(6);
    // MyLinkedList.deleteAtIndex(4);

    MyLinkedList.addAtHead(1);
    MyLinkedList.addAtTail(3);
    MyLinkedList.addAtIndex(1, 2);
    MyLinkedList.get(1);
    MyLinkedList.deleteAtIndex(1);
    MyLinkedList.get(1);

    // MyLinkedList.addAtHead(4);
    // MyLinkedList.get(1);
    // MyLinkedList.addAtHead(1);
    // MyLinkedList.addAtHead(5);
    // MyLinkedList.deleteAtIndex(3);
    // MyLinkedList.addAtHead(7);
    // MyLinkedList.get(3);
    // MyLinkedList.get(3);
    // MyLinkedList.get(3);
    // MyLinkedList.addAtHead(1);
    // MyLinkedList.deleteAtIndex(4);


    for (int i = 0; i < MyLinkedList.getSize(); i++) {
        cout << MyLinkedList.get(i) << endl;
    }
    return 0;
}
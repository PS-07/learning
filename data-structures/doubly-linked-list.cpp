#include <bits-stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {} 
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void remove(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) {
                if (curr->prev) curr->prev->next = curr->next;
                else head = curr->next;
                
                if (curr->next) curr->next->prev = curr->prev;
                else tail = curr->prev;

                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    void displayForward() const {
        Node* current = head;
        while (current) {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    void displayBackward() const {
        Node* current = tail;
        while (current) {
            cout<<current->data<<" ";
            current = current->prev;
        }
        cout<<endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);
    
    cout<<"List in forward order: ";
    list.displayForward();  // Output: 5 10 20 30
    
    cout<<"List in backward order: ";
    list.displayBackward();  // Output: 30 20 10 5

    list.remove(20);
    cout<<"List after removing 20: ";
    list.displayForward();  // Output: 5 10 30

    return 0;
}
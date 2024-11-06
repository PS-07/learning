#include <bits-stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void add_to_head(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* remove_tail() {
        Node* lru = tail->prev;
        remove_node(lru);
        return lru;
    }

    void move_to_head(Node* node) {
        remove_node(node);
        add_to_head(node);
    }
};

class LRUCache {
private:
    int capacity;
    int page_faults;
    unordered_map<int, Node*> m;
    DoublyLinkedList dll;

public:
    LRUCache(int cap) {
        capacity = cap;
        page_faults = 0;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        
        Node* node = m[key];
        dll.move_to_head(node);
        return node->val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;
            dll.move_to_head(node);
        } else {
            page_faults++;
            if (m.size() == capacity) {
                Node* lru = dll.remove_tail();
                m.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            m[key] = node;
            dll.add_to_head(node);
        }
    }

    int get_page_faults() const {
        return page_faults;
    }
};

int main() {
    LRUCache cache(3);  // capacity of the cache is 3

    // Put some values
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    // Access some values
    cout << "Get key 1: " << cache.get(1) << endl; // Should return 10
    cout << "Get key 2: " << cache.get(2) << endl; // Should return 20

    // Add another value, should evict the least recently used (key 3)
    cache.put(4, 40);

    // Trying to get an evicted key
    cout << "Get key 3: " << cache.get(3) << endl; // Should return -1 (not found)

    // Adding more values and triggering more evictions
    cache.put(5, 50);  // Evicts key 1
    cout << "Get key 1: " << cache.get(1) << endl; // Should return -1 (not found)
    cout << "Get key 4: " << cache.get(4) << endl; // Should return 40
    cout << "Get key 5: " << cache.get(5) << endl; // Should return 50

    // Check page fault count
    cout << "Total page faults: " << cache.get_page_faults() << endl; // Should return 5

    return 0;
}

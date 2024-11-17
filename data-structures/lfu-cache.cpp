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
        node->prev = head;
        head->next = node;
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

    bool is_empty() {
        return head->next == tail && tail->prev == head;
    }
};

class LFUCache {
private:
    int capacity;
    int min_count;
    unordered_map<int, pair<int, Node* > > m;
    unordered_map<int, DoublyLinkedList> m_dll;

    void move_to_next_dll(int curr_freq, Node* node) {
        m_dll[curr_freq].remove_node(node);
        m_dll[curr_freq + 1].add_to_head(node);

        if (m_dll[curr_freq].is_empty() && curr_freq == min_count)
            min_count++; 
    }

public:
    LFUCache(int cap) {
        capacity = cap;
        min_count = 1;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        int curr_freq = m[key].first;
        Node* node = m[key].second;

        move_to_next_dll(curr_freq, node);
        m[key].first++;

        return node->val;
    }

    void put(int key, int val) {
        if (m.find(key) != m.end()) {
            m[key].second->val = val;
            move_to_next_dll(m[key].first, m[key].second);
            m[key].first++;
        } else {
            if (m.size() == capacity) {
                Node* lru = m_dll[min_count].remove_tail();
                if (m_dll[min_count].is_empty()) 
                    min_count++;
                m.erase(lru->key);
                delete lru;
            }

            min_count = 1;
            Node* node = new Node(key, val);
            m[key] = make_pair(min_count, node);
            m_dll[min_count].add_to_head(node);
        }
    }
};

int main() {
    LFUCache lfu(3); // Create an LFUCache with a capacity of 3.

    // Add key-value pairs to the cache
    lfu.put(1, 10); // Cache: {1: 10}
    lfu.put(2, 20); // Cache: {1: 10, 2: 20}
    lfu.put(3, 30); // Cache: {1: 10, 2: 20, 3: 30}

    // Access some keys
    cout << "Get 1: " << lfu.get(1) << endl; // Returns 10. Cache: {2: 20, 3: 30, 1: 10}
    cout << "Get 2: " << lfu.get(2) << endl; // Returns 20. Cache: {3: 30, 1: 10, 2: 20}

    // Add another key, evicting the least frequently used one (key 3)
    lfu.put(4, 40); // Cache: {1: 10, 2: 20, 4: 40}

    // Test eviction
    cout << "Get 3: " << lfu.get(3) << endl; // Returns -1 (not found).
    cout << "Get 4: " << lfu.get(4) << endl; // Returns 40. Cache: {1: 10, 2: 20, 4: 40}

    // Add another key, evicting the least frequently used one (key 1 or key 2 based on recency)
    lfu.put(5, 50); // Cache: {2: 20, 4: 40, 5: 50}

    // Test eviction
    cout << "Get 1: " << lfu.get(1) << endl; // Returns -1 (not found).
    cout << "Get 5: " << lfu.get(5) << endl; // Returns 50.
    cout << "Get 2: " << lfu.get(2) << endl; // Returns 20.

    return 0;
}

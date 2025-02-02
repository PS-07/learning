#include <bits/stdc++.h>
using namespace std;

const int MAX_CHILDREN = 26;

struct TrieNode {
    struct TrieNode* children[MAX_CHILDREN];
    bool ending;
    
    TrieNode() {
        for(int i=0; i<MAX_CHILDREN; i++)
            children[i] = NULL;
        ending = false;
    }
};

class Trie {
private:
    struct TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int x = c - 'a';
            if (node->children[x] == nullptr) 
                node->children[x] = new TrieNode();
            node = node->children[x];
        }
        node->ending = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int x = c - 'a';
            if (node->children[x] == nullptr)
                return false;
            else
                node = node->children[x];
        }
        return node->ending;
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    
    cout << "Search apple: " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search app: " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search banana: " << (trie.search("banana") ? "Found" : "Not Found") << endl;
    cout << "Search orange: " << (trie.search("orange") ? "Found" : "Not Found") << endl;

    return 0;
}
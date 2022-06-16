#include <bits/stdc++.h>
using namespace std;

const int MAX_CHILDREN = 26;

struct TrieNode {
    struct TrieNode* children[MAX_CHILDREN];
    bool terminating;
    
    TrieNode() {
        for(int i=0; i<MAX_CHILDREN; i++)
            children[i] = NULL;
        terminating = false;
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
        struct TrieNode* node = root;
        int s = word.size();
        int i = 0;
        
        while(i < s) {
            if(node->children[word[i]-'a'] != NULL) 
                node = node->children[word[i]-'a'];
            else {
                TrieNode* newNode = new TrieNode();
                node->children[word[i]-'a'] = newNode;
                node = newNode;
            }   
            i++;
        }
        node->terminating = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int s = word.size();
        
        for(int i=0; i<s; i++) {
            if(node->children[word[i]-'a'] == NULL)
                return false;
            else
                node = node->children[word[i]-'a'];
        }
        return node->terminating;
    }
};
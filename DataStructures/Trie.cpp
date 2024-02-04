#include <bits/stdc++.h>
using namespace std;
 
struct TrieNode {
    TrieNode *children[26];
    bool isEndOfWord;
    int numWords;

    TrieNode() {
        this->isEndOfWord = false;
        this->numWords = 0;

        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode* curr = this->root;
        curr->numWords++;
    
        for (char c : key) {
            int index = c - 'a';

            if (!curr->children[index])
                curr->children[index] = new TrieNode();
    
            curr = curr->children[index];
            curr->numWords++;
        }
    
        curr->isEndOfWord = true;
    }

    bool search(string key) {
        TrieNode* curr = this->root;
    
        for (char c : key) {
            int index = c - 'a';
            if (!curr->children[index])
                return false;
    
            curr = curr->children[index];
        }
    
        return curr->isEndOfWord;
    }
};

int main() {
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
 
    Trie* trie = new Trie();
 
    for (string key : keys)
        trie->insert(key);
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    cout<<"the"<<" --- "<<output[trie->search("the")]<<endl;
    cout<<"these"<<" --- "<<output[trie->search("these")]<<endl;
    cout<<"their"<<" --- "<<output[trie->search("their")]<<endl;
    cout<<"thaw"<<" --- "<<output[trie->search("thaw")]<<endl;
    return 0;
}
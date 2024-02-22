#include <bits/stdc++.h>
using namespace std;

struct node {
    bool isWord = false;
    vector<node*> children;

    node() {
        children = vector<node*>(26, nullptr);
    }

    void insert(string &s, int idx) {
        if (idx == s.size()) {
            isWord = true;
            return;
        }

        if (!children[s[idx]-'a']) children[s[idx]-'a'] = new node();
        children[s[idx]-'a']->insert(s, idx+1);
    }


    bool search(string &s, int idx) {
        if (idx == s.size()) return isWord;
        if (!children[s[idx]-'a']) return false;
        return children[s[idx]-'a']->search(s, idx+1);
    }
};

int main() {
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    pair<string, bool> words[] = {{"the", true}, {"these", false}, {"their", true}, {"thaw", false}};
 
    node* root = new node();
 
    for (string key : keys)
        root->insert(key, 0);
 
    char output[][32] = {"Not present in trie", "Present in trie"};
    
    for (auto [word, inTrie] : words) {
        assert(!(root->search(word, 0) ^ inTrie));
    }

    return 0;
}
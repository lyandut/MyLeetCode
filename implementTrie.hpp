//
// Created by liyan on 2019-06-06.
//

/*
 * 208. Implement Trie (Prefix Tree)
 * https://leetcode.com/problems/implement-trie-prefix-tree/
 */

#ifndef MYLEETCODE_IMPLEMENTTRIE_HPP
#define MYLEETCODE_IMPLEMENTTRIE_HPP

#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode *children[26];
    TrieNode() : isWord(false) {
        memset(children, NULL, sizeof(children));
    }
};


class Trie {

private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(char ch : word){
            if(p->children[ch-'a'] == nullptr){
                p->children[ch-'a'] = new TrieNode();
            }
            p = p->children[ch-'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(char ch : word){
            if(p->children[ch-'a'] == nullptr) { return false; }
            p = p->children[ch-'a'];
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(char ch : prefix){
            if(p->children[ch-'a'] == nullptr) { return false; }
            p = p->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //MYLEETCODE_IMPLEMENTTRIE_HPP

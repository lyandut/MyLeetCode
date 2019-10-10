//
// Created by liyan on 2019-06-10.
//

/*
 * 211. Add and Search Word - Data structure design
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/
 */

#ifndef MYLEETCODE_ADDANDSEARCHWORD_HPP
#define MYLEETCODE_ADDANDSEARCHWORD_HPP

#include <iostream>
#include <string>

using namespace std;

class WordDictionary {

struct TrieNode {
    bool isWord;
    TrieNode* children[26];
    TrieNode() : isWord(false) {
        memset(children,  NULL, sizeof(children));
    }
};

public:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (char ch : word) {
            if (p->children[ch - 'a'] == nullptr) {
                p->children[ch - 'a'] = new TrieNode();
            }
            p = p->children[ch - 'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(TrieNode* p, string word, int pos) {
        if (p == nullptr) { return false; }
        if (pos == word.size()) { return p->isWord; }
        char ch = word[pos];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(p->children[i], word, pos+1)) {
                    return true;
                }
            }
            return false;
        }
        else {
            if (p->children[ch - 'a'] == nullptr) {
                return false;
            }
            else {
                return dfs(p->children[ch - 'a'], word, pos+1);
            }
        }
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

#endif //MYLEETCODE_ADDANDSEARCHWORD_HPP

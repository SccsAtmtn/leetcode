#include "head.h"

struct TrieNode {
    char val;
    bool isEnd;
    TrieNode *sons[26];
    TrieNode(char val):val(val), isEnd(false) {
        for (int i=0; i<26; ++i)
            sons[i] = nullptr;
    }
};

class WordDictionary {
public:
    WordDictionary():root(new TrieNode('#')) {}

    void addWord(string word) {
        TrieNode *currentNode = root;
        for (int i=0; i<word.length(); ++i)
            if (currentNode->sons[word[i]-'a']==nullptr) {
                currentNode->sons[word[i]-'a'] = new TrieNode(word[i]);
                currentNode = currentNode->sons[word[i]-'a'];
            }
            else 
                currentNode = currentNode->sons[word[i]-'a'];
        currentNode->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
private:
    TrieNode *root;

    bool dfs(TrieNode *subRoot, string &word, int start) {
        if (start==word.length())
            return subRoot->isEnd;
        if (word[start]=='.')
            for (int i=0; i<26; ++i)
                if (subRoot->sons[i]) {
                    if (dfs(subRoot->sons[i], word, start+1))
                        return true;
                }
                else;
        else if (subRoot->sons[word[start]-'a'])
            return dfs(subRoot->sons[word[start]-'a'], word, start+1);
        return false;
    }
};

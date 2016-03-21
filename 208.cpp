class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        end = false;
        key = '#';
    }
    TrieNode(char key): key(key) {
        end = false;
    }
    vector<TrieNode *> sons;
    bool end;
    char key;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * current = root;
        for (int i=0; i<word.size(); ++i) {
            TrieNode * next = NULL;
            for (int j=0; j<current->sons.size(); ++j)
                if (current->sons[j]->key==word[i]) {
                    next = current->sons[j];
                    break;
                }
            if (!next) {
                next = new TrieNode(word[i]);
                current->sons.push_back(next);
            }
            current = next;
        }
        current->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * current = root;
        for (int i=0; i<word.size(); ++i) {
            TrieNode * next = NULL;
            for (int j=0; j<current->sons.size(); ++j) 
                if (current->sons[j]->key==word[i]) {
                    next = current->sons[j];
                    break;
                }
            if (!next) return false;
            current = next;
        }
        return current->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * current = root;
        for (int i=0; i<prefix.size(); ++i) {
            TrieNode * next = NULL;
            for (int j=0; j<current->sons.size(); ++j) 
                if (current->sons[j]->key==prefix[i]) {
                    next = current->sons[j];
                    break;
                }
            if (!next) return false;
            current = next;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
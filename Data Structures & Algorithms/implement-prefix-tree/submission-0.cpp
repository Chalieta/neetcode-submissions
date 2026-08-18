class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.count(c) == 0) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (cur->children.count(c) == 0) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};

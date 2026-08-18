class Node {
    public:
    unordered_map<char, Node*> children;
    bool isWord = false;
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == '.') {
                if (cur->children.empty()) {
                    return false;
                }
                for (const auto& [key, value] : cur->children) {
                    string subword = word;
                    subword[i] = key;
                    if (search(subword)) {
                        return true;
                    }
                }
                return false;
            } else if (cur->children.count(word[i]) == 0) {
                return false;
            }
            cur = cur->children[word[i]];
        }
        return cur->isWord;
    }
};

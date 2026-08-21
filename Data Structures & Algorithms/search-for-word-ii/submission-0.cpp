class TreeNode {
    public:
    unordered_map<char, TreeNode*> children;
    bool isWord = false;

    void insert(string word) {
        TreeNode* cur = this;
        for (char c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c] = new TreeNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visited;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TreeNode* root = new TreeNode();
        for (const string& word : words) {
            root->insert(word);
        }

        int ROWS = board.size(), COLS = board[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(board, r, c, root, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board, int r, int c, TreeNode* node, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
        visited[r][c] || !node->children.count(board[r][c])) {
            return;
        }

        visited[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];

        if (node->isWord) {
            res.insert(word);
        }

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        visited[r][c] = false;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }

        unordered_map<string, vector<string>> mp; // Maps pattern to list of words

        // Populate the map
        for (auto word : wordList) {
            for (int i = 0; i < word.length(); ++i) {
                string pattern = word;
                pattern[i] = '*';
                mp[pattern].push_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        int res = 1;

        q.push(beginWord);
        visited.insert(beginWord);

        while (!q.empty()) {
            int qSize = q.size();
            for (int k = 0; k < qSize; ++k) {
                string cur = q.front();
                q.pop();
                if (cur == endWord) {
                    return res;
                }

                // Add neighbors to the queue
                for (int i = 0; i < cur.length(); ++i) {
                    string pattern = cur;
                    pattern[i] = '*';
                    for (auto neighbor : mp[pattern]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
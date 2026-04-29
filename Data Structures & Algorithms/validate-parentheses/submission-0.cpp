class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                ss.push(c);
            } else if (ss.empty() || !isMatch(ss.top(), c)) {
                return false;
            } else {
                ss.pop();
            }
        }
        return ss.empty();
    }

private:
    bool isMatch(char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) ans += c;  // don't add the first '(' of a primitive
                st.push(c);
            } else { // c == ')'
                st.pop();  // guaranteed safe now
                if (!st.empty()) ans += c;  // don't add the last ')' of a primitive
            }
        }

        return ans;
    }
};

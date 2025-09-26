class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (auto it : s) {
            if (it == '(') {
                st.push('(');
            } else if (it == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(it);
            }
        }
        return st.size();
    }
};

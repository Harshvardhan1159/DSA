class Solution {
public:
string rle(string s) {
    string ans = "";
    int count = 1;

    for (int i = 1; i <= s.size(); i++) {
        if (i < s.size() && s[i] == s[i - 1]) {
            count++;  // keep counting same chars
        } else {
            ans += to_string(count) + s[i - 1]; // append "count+char"
            count = 1; // reset
        }
    }

    return ans;
}


  string solve(int n) {
        if (n == 1) return "1";
        string prev = solve(n - 1);
        return rle(prev);
    }

    string countAndSay(int n) {
        return solve(n);
    }
};
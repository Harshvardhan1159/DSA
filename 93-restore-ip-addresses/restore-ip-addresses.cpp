class Solution {
public:
    bool isvalid(string n) {
        if (n.empty() || n.size() > 3) return false;
        if (n.size() > 1 && n[0] == '0') return false; 
        int num = stoi(n);
        return num >= 0 && num <= 255;
    }

    void func(string s, int n, vector<string>& ans, string temp, int idx, int parts) {
        if (idx == n && parts == 4) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        if (parts >= 4 || idx >= n) return;

        for (int i = 1; i <= 3 && idx + i <= n; i++) { 
            string x = s.substr(idx, i);
            if (isvalid(x)) {
                func(s, n, ans, temp + x + ".", idx + i, parts + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string temp;
        func(s,s.size(),ans,temp,0,0);
        return ans;
    }
};
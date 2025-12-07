class Solution {
public:
    string decToBinary(int n) {
        string bin = "";
        while (n > 0) {
    		int bit = n%2;
          	bin.push_back('0' + bit);
            n /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

    bool isPalindrom(string s){
        int n = s.length();
        for(int i = 0; i <= n/2; i++){
            if (s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    
    bool isBinaryPalindrome(int n){
        string bin = decToBinary(n);
        return isPalindrom(bin);
    }
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            int op = 0;
            int num = nums[i];
            if(isBinaryPalindrome(num)) res.push_back(op);
            else {
                int i = 1;
                while(true){
                    if(isBinaryPalindrome(num-i) || isBinaryPalindrome(num+i)){
                        op++;
                        res.push_back(op);
                        break;
                    }
                    i++;
                    op++;
                }
            }
        }
        return res;
    }
};
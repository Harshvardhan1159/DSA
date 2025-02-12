class Solution {
public:
  bool ispalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left++] != str[right--])
            return false;
    }
    return true;
}
void func (string s,vector<vector<string>>&ans,vector<string>&temp,int idx , int n){
    if(idx==n){
        ans.push_back(temp);
        return;
    }
    for(int i=idx;i<n;i++){
        if(ispalindrome(s.substr(idx,i-idx+1))){
            temp.push_back(s.substr(idx,i-idx+1));
            func(s,ans,temp,i+1,n);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        func(s,ans,temp,0,n);
        return ans;
    }
};
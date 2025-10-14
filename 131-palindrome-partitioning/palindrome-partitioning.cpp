class Solution {
public:
   bool pal(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
   }
    void f(string &s,int i,int n, vector<vector<string>>&ans,vector<string>temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(pal(s.substr(i,j-i+1))){
                string x=s.substr(i,j-i+1);
                temp.push_back(x);
                f(s,j+1,n,ans,temp);
                temp.pop_back();
                
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
         vector<string>temp;
         int n = s.size();
         f(s,0,n,ans,temp);
         return ans;
    }
};
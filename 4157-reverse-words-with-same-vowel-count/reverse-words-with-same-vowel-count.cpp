class Solution {
public:
   int count(string s){
    int n = s.size();
    int cnt =0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')cnt++;
    }
    return cnt;
   }
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        bool first = true;
        string ans;
        int x=0;
        while(ss>>word){
            if(first){
                 x = count(word);
                first = false;
                ans+=word+" ";
            }else{
            int y = count(word);
            if(x==y){
                reverse(word.begin(),word.end());
            }


            ans+=word+" ";
            }

        }
        return ans.substr(0,ans.size()-1);
    }
};
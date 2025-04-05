class Solution {
public:
    int ladderLength(string st, string e, vector<string>& word) {
        unordered_set<string>s(word.begin(),word.end());
        queue<pair<string,int>>q;
        q.push({st,1});
        while(!q.empty()){
        pair<string,int>p=q.front();
        q.pop();
        string x = p.first;
        int c = p.second;
        if(x==e)return c;
        for(int i=0;i<x.size();i++){
            string temp =x;
        for(char it='a';it<='z';it++){
          temp[i]=it;
          if(s.find(temp)!=s.end()){
            q.push({temp,c+1});
            s.erase(temp);
          }  
        }
        }
        }
        return 0;
    }
};
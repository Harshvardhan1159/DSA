class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
         vector<int>ans;
         int last = INT_MIN;
         int start =0;
         for(int i=0;i<n;i++){
             last = max(mp[s[i]],last);
            if(last ==i){
                ans.push_back(last-start+1);
                start = last+1;
            }
           
            
           
         }
         return ans;
    }
};
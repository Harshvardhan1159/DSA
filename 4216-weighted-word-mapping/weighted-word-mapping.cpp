class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string ans="";
        for(auto i:words){
            int sum =0;
            for(auto j:i){
              sum+=weights[j-'a'];
            }
             sum=sum%26;
             sum=25-sum;
             char x= 'a'+sum;
             ans.push_back(x);

        }
        return ans;
    }
};
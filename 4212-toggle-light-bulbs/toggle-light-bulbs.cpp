class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
       vector<int>v(101,0);
       vector<int>ans;
       int n = bulbs.size();
       for(int i=0;i<n;i++){
        v[bulbs[i]]=1-v[bulbs[i]];
       }
       for(int i=0;i<101;i++){
         if(v[i]>0){
            ans.push_back(i);
         }
       }
       return ans;
    }
};
class Solution {
public:
    int beautySum(string s) {
     int n = s.size();
     
     int sum =0;
     map<char,int>mp;
     for(int i =0;i<n;i++){
        char c = s[i];
        mp[c]++;
        
        for(int j = i+1;j<n;j++){
           char a = s[j];
           mp[a]++;
           int mini = INT_MAX;
        int maxi = INT_MIN;
           for(auto it:mp){
           if(it.second>maxi){
            maxi = it.second;
           }
           if(it.second<mini){
            mini = it.second;
           }
           }
           sum+=maxi-mini;
        }
        mp.clear();
     }  

     return sum; 
    }
};
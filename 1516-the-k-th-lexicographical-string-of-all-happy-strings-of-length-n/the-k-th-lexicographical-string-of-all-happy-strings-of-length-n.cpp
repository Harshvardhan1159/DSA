class Solution {
public:
void func(int n ,vector<char>&vec,string &temp,vector<string>&ans,int idx){
    if(idx==n){
        ans.push_back(temp);
        return;
    }
    for(int i =0;i<3;i++){
        if(temp.empty()||temp.back()!=vec[i]){
        temp+=vec[i];
      
        func(n,vec,temp,ans,idx+1);
        temp.pop_back();
        }
    }

}
    string getHappyString(int n, int k) {
       vector<string>ans;
        string temp;
       vector<char> vec = {'a', 'b', 'c'};
        func(n,vec,temp,ans,0);
        sort(ans.begin(),ans.end());
        if(k>ans.size()){
            return "";
        }
        string x = ans[k-1];
        return x;
    }
};
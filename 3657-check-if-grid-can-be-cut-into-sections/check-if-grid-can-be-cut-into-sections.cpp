class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
       vector<vector<int>>x;
       vector<vector<int>>y;
        // int x = rect.size();
        // if(x>n)return false;
        for(auto i:rect){
            int x1 = i[0];
            int y1 = i[1];
            int x2 = i[2];
            int y2= i[3];
           
            x.push_back({x1,x2});
            y.push_back({y1,y2});
        }
        sort(x.begin(),x.end());
            int start =0;
            int end =0;
            int sec =0;
            int c =0;
            for(auto i:x){
                if(i[0]>=end){
                    c++;
                    end = i[1];
                }else{
                    end=max(end,i[1]);
                }
                if(c==3)return true;
            }

             sort(y.begin(),y.end());
             start =0;
             end =0;
             sec =0;
             c =0;
            for(auto i:y){
                if(i[0]>=end){
                    c++;
                    end = i[1];
                }else{
                    end=max(end,i[1]);
                }
                if(c==3)return true;
            }
          
        
        return false;
    }
};
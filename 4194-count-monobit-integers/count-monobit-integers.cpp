class Solution {
public:
    int countMonobit(int n) {
        int ans=0;
        for(int i=0;i<=n;i++){
            if(i==0||i==1||i==3||i==7||i==15||i==31||i==63||i==127||i==255||i==511)ans++;
     
        }
        return ans;
    }
};
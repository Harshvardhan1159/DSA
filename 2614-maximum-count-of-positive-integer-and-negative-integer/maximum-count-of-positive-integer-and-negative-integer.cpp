class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p=0;
        int n =0;
        int maxi =0;
        int k =nums.size();
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                n++;
            }else if(nums[i]>0){
                p++;
            }else{
                n=0;
                p=0;
            }
            maxi=max(maxi,max(p,n));
        }
        return maxi;
    }
};
class Solution {

    private:
    int valid(int mid,vector<int>& nums,int n){
        int k =1;
        int sum=0;
        for(int i=0;i<n;i++){
          if(nums[i]+sum<=mid){
            sum+=nums[i];

          }else{
            sum=nums[i];
            k++;
          }
        }
        return k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
       int sum = 0;
       int n = nums.size();
       int s =0;
       for(int i=0;i<n;i++){
        sum+=nums[i];
        s= max(nums[i],s);
       } 
    
    int ans =0;
    int e = sum;
     while(s<=e){
    int mid = s+(e-s)/2;
    int split = valid(mid,nums,n);
    if(split<=k){
       ans =mid;
        e=mid-1;
    }else{
        s= mid+1;
    }
     

     }
     return ans;
    }
};
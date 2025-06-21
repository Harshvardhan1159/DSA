class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int res=0;
        
     // loop to count the no. of set bits
        while(n>0){
           n = n & (n-1);
           res++;
        }
        return res;
    }
};
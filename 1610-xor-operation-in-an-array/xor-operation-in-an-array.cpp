class Solution {
public:
    int xorOperation(int n, int start)
    {
        //optimized approach(without creating extra array)
        //time complexity: O(n)
        //space complexity: O(1)

        int i;
        int ans=0;

        for(i=0;i<n;i++)
        {
            //store current-element in 'temp'
            int temp= start + (2*i);
            //performing 'XOR' operation on elements till 'n'
            ans=ans^temp;
        }
        
        return ans;
    }
};
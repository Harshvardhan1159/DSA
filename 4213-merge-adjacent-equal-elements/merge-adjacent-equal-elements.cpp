class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;   // use long long to avoid overflow
        
        for(int i = 0; i < nums.size(); i++){
            
            if(st.empty() || st.top() != nums[i]){
                st.push(nums[i]);
            }
            else{
                long long val = nums[i];
                st.pop();           
                val *= 2;         
                
                
                while(!st.empty() && st.top() == val){
                    st.pop();
                    val *= 2;
                }
                
                st.push(val);
            }
        }
        
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

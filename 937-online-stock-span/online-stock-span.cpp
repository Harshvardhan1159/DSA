class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i=1;
        while(!st.empty()&& price>=st.top().first){
            int x = st.top().second;
            st.pop();
            i+=x;
        }
        st.push({price,i});
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
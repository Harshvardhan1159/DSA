class StockSpanner {
public:
stack<pair<int,int>> st; //val and index
int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty()&&st.top().first<=price){
            st.pop();
        }
        int span;
        if(st.empty()) span=-1; 
        else span=st.top().second;
        st.push({price,i});
         i++;
        return st.top().second -span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
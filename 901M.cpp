class StockSpanner {
public:
    stack<int> prices,weights;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int w=1;
        while(!prices.empty() && prices.top() <= price)
        {
            w+=weights.top();
            weights.pop();
            prices.pop();
        }
        prices.push(price);
        weights.push(w);
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
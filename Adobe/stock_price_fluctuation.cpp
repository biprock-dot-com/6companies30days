class StockPrice {
private:
 
    map<int,int>price_at_timestamp;
    map<int,int>price_value;

public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(price_at_timestamp.count(timestamp))
        {
            int prev_price = price_at_timestamp[timestamp];
            if(--price_value[prev_price] == 0)
             price_value.erase(prev_price);
        }

        price_at_timestamp[timestamp] = price;
        price_value[price]++;

    }
    
    int current() {
        return rbegin(price_at_timestamp)->second;
    }
    
    int maximum() {
        return rbegin(price_value)->first;
    }
    
    int minimum() {
        return begin(price_value)->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

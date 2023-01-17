class Solution {
public:

void buy(vector<int>& price, vector<vector<int>>& special, int& covered, vector<int> & needs, vector<int>& current, int& total, int& result) {
    int purchaseReq = 0;
    int purchaseExtra = 0;
    
    for(int i = 0; i <needs.size();i++) {
        if(needs[i] >current[i]) {
            purchaseReq = 1;
        } else if(needs[i] < current[i]) {
            purchaseExtra = 1;
            break;
        }
    }
   
    if(purchaseExtra) {
        return;
    } else if(purchaseExtra == 0 && purchaseReq == 0) {
        result = min(result,total);
        return;
    }
    
    for(int i = covered; i < special.size(); i++) {
        
        for(int j = 0; j < price.size();j++) {
            current[j]+=special[i][j];
        }
        total += special[i][price.size()];
        
        buy(price,special,i,needs,current,total,result);
        
    
        for(int j = 0; j < price.size();j++) {
            current[j]-=special[i][j];
        }
        total -= special[i][price.size()];
    }
    return;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int total = 0; 
    int result = INT_MAX; 
    int elements = price.size();
    
   
    for(int i = 0; i < elements;i++) {
        vector<int> priceAlone(elements+1,0);
        priceAlone[i] = 1;
        priceAlone[elements] = price[i];
        special.push_back(priceAlone);
    }
    
    vector<int> current(needs.size(),0); 
    int covered = 0; 
    buy(price,special,covered,needs,current,total, result);
    return result;
}
};

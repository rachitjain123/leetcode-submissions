class Cashier {
    int disc;
    int tot_cst;
    int num_cst;
    unordered_map<int,int> productPriceMap;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        disc=discount;
        tot_cst=n;
        num_cst=0;
        for(int i=0;i<products.size();i++)
            productPriceMap[products[i]]=prices[i];
            
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double tot_amount=0;
        num_cst++;
        for(int i=0;i<product.size();i++)
            tot_amount+=productPriceMap[product[i]]*amount[i];
        if(num_cst%tot_cst==0)
            tot_amount *= (1-(double)disc/100);
        return tot_amount;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
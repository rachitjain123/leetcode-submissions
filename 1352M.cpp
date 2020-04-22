class ProductOfNumbers {
public:
    vector<int>prefMul;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num==0)
            prefMul.clear();
        else if(prefMul.empty())
            prefMul.push_back(num);
        else
        {
            int lastNum=prefMul.back();
            prefMul.push_back(lastNum*num);
        }
    }
    
    int getProduct(int k) {
        if(prefMul.size()<k)
            return 0;
        if(prefMul.size()==k)
            return prefMul.back();
        int cum1Prod=prefMul.back();
        int cum2Prod=prefMul[prefMul.size()-k-1];
        int kProd=cum1Prod/cum2Prod;
        return kProd;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
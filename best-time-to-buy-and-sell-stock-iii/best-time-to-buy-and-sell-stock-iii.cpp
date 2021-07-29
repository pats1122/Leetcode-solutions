class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        vector<int> firstTxn(n,0);
        vector<int> secondTxn(n,0);
        
        //first transaction
        int min_price = prices[0];
        for(int i=1; i<n; i++){
            //choose to sell today or some previous day
            firstTxn[i] = max(firstTxn[i-1], prices[i]-min_price);
            min_price = min(min_price, prices[i]);
        }
        res = firstTxn[n-1];
        
        //second transaction
        int max_price = prices[n-1];
        for(int i=n-2;i>1; i--){
            //choose to buy today or some later day
            secondTxn[i] = max(secondTxn[i+1], max_price-prices[i]);
            max_price = max(max_price, prices[i]);
            
            //res = max(1 txn, (1st txn + max profit from 2nd txn))
            res = max(res, firstTxn[i-1]+secondTxn[i]);
        }
        
        return res;
    }
};
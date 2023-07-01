int maximumProfit(vector<int> &prices){

    /*
    -> We can just run a nested loop and calculate the maximum profit that can be made if we buy at 
        that element
    -> TC - O(N*N) SC = O(1)

    -> We can take a buy variable and whenever we get any element less than buy we just update it
    -> At each day we can sell that buy and find then maximum profit
    -> TC - O(N) SC = O(1)
    */
    
    int maxProfit = 0, buy = prices[0];
    for(int i = 0; i<prices.size(); i++){
        if(prices[i] < buy){
            buy = prices[i];
        }
        maxProfit = max(maxProfit,(prices[i]-buy));
    }
    return maxProfit;
}
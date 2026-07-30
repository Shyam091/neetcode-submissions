class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l=0;
        int r;
        int Max = 0;
        for(int r=1;r<n;r++)
        {
            if(prices[l] <= prices[r])
            {
                Max = max(Max, prices[r] - prices[l]);
            }

            else{
                l=r;
            }
        }

        return Max;
        
    }
};

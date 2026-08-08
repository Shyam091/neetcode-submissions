class Solution {
public:
    int rateHour(vector<int>& piles, int k)
    {
        int total = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i] <= k)
            {
                total++;
            }
            else{
               if(piles[i] % k == 0)
               {
                total += piles[i]/k;
               }
               
               else if(piles[i] % k != 0)
               {
                total += piles[i]/k+1;
               }

            }
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right =  *max_element(piles.begin() , piles.end());

        while(left <= right)
        {
            int rate = (left + right ) / 2;
            int  k = rateHour(piles, rate);

            if(k <= h)
            {
                right = rate-1;
            }

            else if(k  >h)
            {
                left = rate + 1;
            }
        }

        return left ;
    }
};

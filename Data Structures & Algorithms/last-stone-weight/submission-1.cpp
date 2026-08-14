class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 6 aur 4 ko nikal, lo
        // aur agr dono equal hai to kuch add mt kro
        // agr 6 bda hai 4 se to 2 add kro
        // agr 6 4 se chhota hai to 4-6 add kro.
        priority_queue<int>pq;
        for(int x : stones)
        {
            pq.push(x);
        }
        while(!pq.empty())
        {
            int num1=pq.top();
            pq.pop();
            if(pq.empty())
            {
                return num1;
            }
            int num2=pq.top();
            pq.pop();
            if(num1 > num2)
            {
                pq.push(num1-num2);
            }
            else if(num2>num1)
            {
                pq.push(num2-num1);
            }

            else if(num1 == num2)
            {
                // have to push nothing....
            }
        }

        return 0;
    }
};

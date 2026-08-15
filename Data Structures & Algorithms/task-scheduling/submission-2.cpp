class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // will use pq to get the task with max freq.
        // once we pick it then we set it cooling time.

        int m = tasks.size();
        unordered_map<char, int>mp;
        for(int x:tasks)
        {
            mp[x]++;
        }
        priority_queue<pair<int , char>>pq; // max heap
        // X-2
        // Y-2
        for(auto it:mp)
        {
            pq.push({it.second , it.first});
        }
        // now we have one max heap 
        
        queue< pair<char, pair<int,int> > > q; // cpu queue.

        int timer = 0;

        while(!pq.empty() || !q.empty())
        {
            timer++; // we increase the time -  we are at time t;
            while(!q.empty() && q.front().second.second <= timer) // frist check first charisready?
            {
                auto [c2 , p1] =  q.front();
      
                q.pop();
                // if we directly put it back again in queue, then without checking hte max freq count, it will directly pick the front.
                // we can put it again in the heap, so it will pick the char with most freq.

                    pq.push({p1.first,c2});
                
            }
            if(!pq.empty()){
                auto [f1 , c2] = pq.top();
                pq.pop();
                if(f1-1>0)
                {
                q.push({c2,{f1-1, timer+n+1}});
                }
            }

            else{
                // do nothing. idle time.
            }
                    
        }
    return timer;

    }
};

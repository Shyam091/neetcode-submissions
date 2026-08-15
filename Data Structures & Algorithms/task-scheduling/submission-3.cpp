class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int>mp;
        for(int x:tasks)
        {
            mp[x]++;
        }
        priority_queue<pair<int , char>>pq; 
        for(auto it:mp)
        {
            pq.push({it.second , it.first});
        }
        
        queue< pair<char, pair<int,int> > > q; 

        int timer = 0;

        while(!pq.empty() || !q.empty())
        {
            timer++; 
            if(!q.empty() && q.front().second.second <= timer) 
            {
                auto [c2 , p1] =  q.front();
      
                q.pop();

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
                
            }
                    
        }
    return timer;

    }
};

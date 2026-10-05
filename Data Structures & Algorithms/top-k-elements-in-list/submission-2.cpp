class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // top k frequent elements.

        // frequencies - sort
        // frequencies - on the basis of the pq

        // we will use min heap, because we need to remove it from the top, so we need max freq.

        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq; //min heap
        unordered_map<int,int>mp; // for frequencies
        // every time we have to push it and when size becomes 3 we have to remove one element.

        for(int x:nums)
        {
            mp[x]++;
        }
      
            for(auto& [key, freq]:mp)
            {
                pq.push({freq, key });
                if(pq.size() > k)
                {
                    pq.pop();
                }
            }

        vector<int>ans;
        while(!pq.empty())
        {
            auto [freq, ele] = pq.top();
            ans.push_back(ele);
            pq.pop();
        }

        return ans;
        
    }
};

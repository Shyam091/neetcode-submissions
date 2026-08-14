class KthLargest {
public:
    int k;
    int s=0;
    bool init = false;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        s=nums.size();
        this->k=k;
        for(int i=0;i<nums.size();i++)
        {
           if(pq.size() == k)
           {
            pq.push(nums[i]);
            pq.pop();
           }
           else{
           pq.push(nums[i]);
           }
            
        }
    }
    
    int add(int val) {
       if(pq.size() == k)
       {
        pq.push(val);
        pq.pop();
        return pq.top();
       }

       else{
        pq.push(val);
        if(pq.size() == k)
        {
            return pq.top();
        }
       }
    }
};

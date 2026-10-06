class Solution {
public:
    int trap(vector<int>& height) {
        // left max and right max for each question, then each = min (left max, right max);
        int n = height.size();
        vector<int>lmax(n);
        vector<int>rmax(n);
        lmax[0]=INT_MIN;

        for(int i=1;i<n;i++)
        {
            int mx = height[i-1]; // last index val
            lmax[i]=max(mx, lmax[i-1]); // left max for curr bar.
        }

        rmax[n-1]=INT_MIN;

        for(int i=n-2;i>=0;i--)
        {
            int mx =  height[i+1]; // next index val;
            rmax[i] = max(mx, rmax[i+1]);
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(i == 0  || i == n-1)
            {
                continue ;
            }

            int mn = min(lmax[i],rmax[i]);

            if(mn > height[i])
            {
                ans+=mn-height[i];
            }
        }

        return ans ;


    }
};

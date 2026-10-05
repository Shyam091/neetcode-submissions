class Solution {
public:
    bool isAnagram(string s, string t) {
       int n = s.size();
       int m = t.size();

       if(n!=m)
       {
        return false;
       }

       vector<int>v(26,0);

       for(char x:s)
       {
        v[x-'a'] +=1;
       }

       for(char x:t)
       {
        v[x-'a'] -=1;
       }

       for(int x:v)
       {
        if(x!= 0)
        {
            return false ;
        }
       }

       return true;

       


    }
};

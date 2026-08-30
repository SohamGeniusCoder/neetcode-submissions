class Solution {
public:

    int lengthOfLongestSubstring(string s) 
    {
        int l=0,r=0;set<char> set1;int max = 0;
        
        while(r<s.size())
        {
            int k = set1.size();
            set1.insert(s[r]);
            if(k == set1.size()) //this means s[r] is in the set
            {
                if(max < set1.size())
                {
                    max = set1.size();
                }
                while(s[l] != s[r])
                {
                    set1.erase(s[l]);
                    l++;
                }
                set1.erase(s[l]);
                l++;
                set1.insert(s[r]);
                
            }
            else
            {
                
                if(max<set1.size())
                {
                    max = set1.size();
                }
            }
            r++;
            
            
        }
        return max;
    }
};

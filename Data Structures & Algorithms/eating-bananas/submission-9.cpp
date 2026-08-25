class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int max = piles[0];
        int min = 1;

        for(int i = 0; i < piles.size(); i++)
        {
            if(piles[i] > max)
            {
                max = piles[i];
            }
        }

        while(min < max)
        {
            int mid = (min + max) / 2;
            int hrsRequired = 0;

            for(int i = 0; i < piles.size(); i++)
            {
                if(piles[i] % mid == 0)
                {
                    hrsRequired += piles[i] / mid;
                }
                else
                {
                    hrsRequired += (piles[i] / mid) + 1;
                }
            }

            if(hrsRequired <= h)
            {
                max = mid;
            }
            else
            {
                min = mid + 1;
            }
        }

        return min;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mp=0;
        int b=prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]>b){
                mp=max(mp, prices[i]-b);
            }
            b=min(b, prices[i]);
        }
        return mp;
    }
};
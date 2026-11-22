class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n % 2 == 0) return 1.0;
        if(x == -1 && n % 2 != 0) return -1.0;

        long long b = n;
        bool neg = false;

        if(b < 0) {
            neg = true;
            b = -b;
        }

        double ans = 1;

        while(b > 0) {
            if(b % 2 == 1) {
                ans *= x;
            }

            x *= x;
            b /= 2;
        }

        if(neg) {
            ans = 1.0 / ans;
        }

        return ans;
    }
};




class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) return "0";
        string ans = "";

        if((numerator<0 && denominator>0)||(numerator>0 && denominator<0)) ans = ans + '-';
        long long n = abs(numerator), d = abs(denominator);

        ans = ans + to_string(n/d);
        
        long long deciPart = n%d ;

        if(deciPart>0) ans = ans + '.';

        unordered_map<long long , int>recurr;

        while(deciPart>0)
        {
            if(recurr.find(deciPart )!= recurr.end())
            {
                ans.insert(recurr[deciPart],"(");
                ans = ans + ')';
                break;
            }

            recurr[deciPart]= ans.length();
            deciPart*= 10;
            ans = ans + to_string(deciPart/d);
            deciPart%= d;
        }

        return ans;
    }
};

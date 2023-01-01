class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>m;
        int bulls =0, cows =0;

        for(int i=0; i<secret.size(); i++)
        {
           if(secret[i]==guess[i])
             bulls++;
           else 
             m[secret[i]]++;

        }

        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i] ) continue;
            else if(m[guess[i]])
            {
                m[guess[i]]--;
                cows++;
            }
        }
        return (to_string(bulls) + "A" + to_string(cows) + "B");
         
    }
};
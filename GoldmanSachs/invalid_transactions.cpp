class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> invalid;
        unordered_set<int> Set;
        
        vector<vector<string>> split;
        for(auto t : transactions){
            stringstream stream(t);
            string temp; vector<string> token;
            int j = 0;
            while(getline(stream, temp, ',')){
                token.push_back(temp);
                j++;
                if(j == 4)
                    split.push_back(token);
            }
        }
     
        for(int i = 0; i < split.size(); i++){
            if(stoi(split[i][2]) > 1000)
                Set.insert(i);
        }
      
        for(int i = 0; i < split.size(); i++){
            for(int j = i+1; j < split.size(); j++){
                string name1, name2, time1, time2, city1, city2;
                name1 = split[i][0];
                time1 = split[i][1];
                city1 = split[i][3];
                name2 = split[j][0];
                time2 = split[j][1];
                city2 = split[j][3];
                
                if(abs(stoi(time2) - stoi(time1)) <= 60 && name1==name2 && city1!=city2){
                    Set.insert(i);
                    Set.insert(j);
                }
            }
        }
        
        for(auto x = Set.begin(); x != Set.end(); x++)
            invalid.push_back(transactions[*x]);
       
        return invalid;
    }
};

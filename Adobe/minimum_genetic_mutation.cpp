class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        vector<char>DNA_Base = {'A', 'C','G','T'};
        deque<pair<string,int>>dq({{startGene,0}});
        set<string>gene_bank (bank.begin(), bank.end());
        

        while(!dq.empty())
        {
            string gene = dq.front().first;
            int mutation_count = dq.front().second;
            dq.pop_front();

            if(gene == endGene) return mutation_count;

            for(int i=0; i<gene.size(); i++)
            {
                for(char x : DNA_Base)
                {
                    string mutate = gene;
                    mutate[i] = x;

                    if(gene_bank.count(mutate))
                    {
                        gene_bank.erase(mutate);
                        dq.emplace_back(mutate, mutation_count+1);
                    }
                }
            }
        }
        return -1;
    }
};

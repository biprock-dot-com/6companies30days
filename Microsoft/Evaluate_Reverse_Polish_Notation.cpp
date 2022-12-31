class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;

        for(auto& t : tokens)
        {
            if(t=="+" || t=="-"|| t=="*" || t=="/")
            {
                //d1 = data1, d2 = data2
                long long d1 = s.top();
                s.pop();
                long long d2 = s.top();
                s.pop();

                if(t=="+")
                 d1 = d2+d1;
                if(t=="-")
                 d1 = d2-d1;
                if(t=="*")
                 d1 = d2*d1;
                if(t=="/")
                 d1 = d2/d1;
                 s.push(d1);
            }
            else s.push(stoi(t));
        }
        return s.top();
    }
};
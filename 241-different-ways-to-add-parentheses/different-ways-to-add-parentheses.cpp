class Solution {
public:
    
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            char ch=expression[i];
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' )
            {
                string leftpart=expression.substr(0,i);
                string rightpart=expression.substr(i+1);

                vector<int> left=diffWaysToCompute(leftpart);
                vector<int> right=diffWaysToCompute(rightpart);

                for(int l:left)
                {
                    for(int r:right)
                    {
                        if(ch=='+')
                        {
                            ans.push_back(l+r);
                        }
                        if(ch=='-')
                        {
                            ans.push_back(l-r);
                        }
                        if(ch=='*')
                        {
                            ans.push_back(l*r);
                        }
                    }
                }
            }

        }
        if(ans.empty())
        {
            ans.push_back(stoi(expression));
        }
        return ans;
        
    }
};
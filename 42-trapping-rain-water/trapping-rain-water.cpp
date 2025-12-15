class Solution {
public:
    int solve(vector<int>& height,int index)
    {
        int n=height.size();
        int area=0;
        int leftmaxi=0;
        for(int i=0;i<index;i++)
        {
            leftmaxi=max(leftmaxi,height[i]);
        }
        
        vector<int>rightmaxi(n);
        rightmaxi[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmaxi[i]=max(height[i],rightmaxi[i+1]);
        }

        for(int i=index;i<height.size()-1;i++)
        {
            int len=0;
            if(min(leftmaxi,rightmaxi[i+1])>height[i])
                len=min(leftmaxi,rightmaxi[i+1])-height[i];
            area=area+len;

            leftmaxi=max(leftmaxi,height[i]);

        }
        return area;
    }
    int trap(vector<int>& height) {
        if (height.size() < 3) 
            return 0;
        return solve(height,1);
        
    }
};
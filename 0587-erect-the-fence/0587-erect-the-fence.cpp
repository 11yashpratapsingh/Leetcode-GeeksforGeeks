class Solution {
public:
    
    int getRotAgle(vector<int>& a, vector<int>& b, vector<int>& c){
        // (x2-x1)(y3-y1) - (y2-y1)(x3-x1) -> 3D Cross-product of AB and AC vectors
        return ((b[0] - a[0])*(c[1]-a[1])) - ((b[1]-a[1])*(c[0]-a[0]));
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n<=3) return trees;
        
        sort(trees.begin(),trees.end());
        
        vector<vector<int>> upHull,lwHull;
        
        upHull.push_back(trees[0]);
        upHull.push_back(trees[1]);
        
        for(int i=2;i<n;i++){
            int upSz = upHull.size();
            
            while(upSz >=2 && getRotAgle(upHull[upSz-2],upHull[upSz-1],trees[i])>0){
                upHull.pop_back();
                upSz--;
            }
            
            upHull.push_back(trees[i]);
        }
        
        lwHull.push_back(trees[n-1]);
        lwHull.push_back(trees[n-2]);
        for(int i=n-3;i>=0;i--){
            int lwSz = lwHull.size();
            
            while(lwSz >=2 && getRotAgle(lwHull[lwSz-2],lwHull[lwSz-1],trees[i])>0){
                lwHull.pop_back();
                lwSz--;
            }
            
            lwHull.push_back(trees[i]);
        }
        
        upHull.insert(upHull.end(),lwHull.begin(),lwHull.end());
        
        sort(upHull.begin(),upHull.end());
        upHull.erase(unique(upHull.begin(),upHull.end()),upHull.end());
        
        return upHull;
    }
};
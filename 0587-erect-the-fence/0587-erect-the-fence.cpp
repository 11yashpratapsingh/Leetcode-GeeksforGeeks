class Solution {
public:
    //     To calculate the crossProduct 
    // Cross product of two vectors AB and AC
    // returns positive for counter clockwise
    // turn and negative for clockwise turn
    int getRotAgle(vector<int>& a, vector<int>& b, vector<int>& c){
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
//          If less then or equal to 3 return Trees. They all need to included .
        if(n<=3) return trees;
//      sort them according to increasing order of x cordinates.           
        sort(trees.begin(),trees.end());
        
        vector<vector<int>> upHull,lwHull;
		 // Upper HULL construction
        //       Push first 2 points in UpperHullTrees. 
        upHull.push_back(trees[0]);
        upHull.push_back(trees[1]);
        //         Travese throw all the points of sorted Trees.
        for(int i=2;i<n;i++){
            int upSz = upHull.size();
        //             Cross Product > 0  bigger counterclockwise angle . So,we need to remove B and insert C.
            while(upSz >=2 && getRotAgle(upHull[upSz-2],upHull[upSz-1],trees[i])>0){
                upHull.pop_back();
                upSz--;
            }
            
            upHull.push_back(trees[i]);
        }
        
        // Lower HULL construction
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
        
        //         Add the top hull to down hull
        upHull.insert(upHull.end(),lwHull.begin(),lwHull.end());
        
        //          Remove the duplicates present in the lTrees.
        sort(upHull.begin(),upHull.end());
        upHull.erase(unique(upHull.begin(),upHull.end()),upHull.end());
        
        return upHull;
    }
};
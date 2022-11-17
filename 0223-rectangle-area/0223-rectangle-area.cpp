class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int lt_bound = max(ax1,bx1);
        int rt_bound = min(ax2,bx2);
        int tp_bound = min(ay2,by2);
        int bt_bound = max(ay1,by1);
        
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);
        int inters = 0;
        
        if(lt_bound < rt_bound && bt_bound < tp_bound) inters = (rt_bound - lt_bound) * (tp_bound - bt_bound);
        
        return area1 + area2 - inters;
    }
};
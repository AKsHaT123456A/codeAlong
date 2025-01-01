class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
     int x=max(x1,min(xCenter,x2));
     int y=max(y1,min(yCenter,y2));
     int d = sqrt(pow(abs(xCenter-x),2)+pow(abs(yCenter-y),2));\
     cout<<d;
     if(d<=radius)return true;
     return false;
    }
};
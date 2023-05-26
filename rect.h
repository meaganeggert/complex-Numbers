#pragma once
#include <iostream>
#include <cmath>
#include "./point.h"

using namespace std;

//Holds a rectangle in space
//Contains a center point, and a half-size in the x and y directions.
//So a rectangle from (1,2) to (5,4) would have a center point of (3,3) and a half-size of (2,1) looks like this -
//Rectangle bob = {3,3,2,1}
//(The half-size is the size from the center to the edge)
struct Rectangle {
        Point loc = {0.,0.};
        Point size = {0.,0.};

        //This version of distance_to takes two ints as parameters instead of one Point
        //But since it's basically the same thing, it just calls the other version!
        float distance_to(int x, int y) const {
                return this->distance_to({float(x),float(y)});
        }

        float distance_to(const Point &p) const {
                //YOU: This is the heart of the assignment
                return 0; //Change this obviously
        }

        friend std::istream& operator>>(std::istream& ins, Rectangle &rhs) {
                return ins >> rhs.loc.x >> rhs.loc.y >> rhs.size.x >> rhs.size.y;
        }

        friend std::ostream& operator<<(std::ostream& outs, const Rectangle &rhs) {
                return outs << '(' << rhs.loc.x-rhs.size.x << ',' << rhs.loc.y-rhs.size.y << ") to (" << rhs.loc.x+rhs.size.x << ',' << rhs.loc.y+rhs.size.y << ')';
        }

        float distance_to_rect (const int &curJ, const int &curI) const {
//              Point checker = {curJ, curI};
                float rightEdge = loc.x + size.x;
        float leftEdge = loc.x - size.x;
                float topEdge = loc.y - size.y;
            float bottomEdge = loc.y + size.y;
                Point cornerTL = {leftEdge, topEdge} ;
                Point cornerTR = {rightEdge, topEdge};
                Point cornerBL = {leftEdge, bottomEdge};
                Point cornerBR = {rightEdge, bottomEdge};
                float leftDist, rightDist, horizDist, topDist, bottomDist, vertDist, TLdist, TRdist, BLdist, BRdist, newDist;
                float minDist = 20.0;

                if (curI >= topEdge && curI <= bottomEdge){
                        if (curJ == rightEdge || curJ == leftEdge){
                                minDist = 0.0;
                        }
                        else {
                                rightDist = curJ - rightEdge;
                                leftDist = curJ - leftEdge;
                                newDist = fmin(abs(rightDist), abs(leftDist));
                        }
                        minDist = fmin(abs(minDist), abs(newDist));
                }

                if (curJ >= leftEdge && curJ <= rightEdge) {
                        if (curI == topEdge || curI == bottomEdge){
                                minDist = 0.0;
                        }
                        else {
                                topDist = curI - topEdge;
                                bottomDist = curI - bottomEdge;
                                newDist = fmin(abs(topDist), abs(bottomDist));
                        }
                        minDist = fmin(abs(minDist), abs(newDist));
                }

                else {
                        TLdist = hypot(curJ - cornerTL.x, curI - cornerTL.y);
                        minDist = fmin(abs(minDist), abs(TLdist));
                        TRdist = hypot(curJ - cornerTR.x, curI - cornerTR.y);
                        minDist = fmin(abs(minDist), abs(TRdist));
                        BLdist = hypot(curJ - cornerBL.x, curI - cornerBL.y);
                        minDist = fmin(abs(minDist), abs(BLdist));
                        BRdist = hypot(curJ - cornerBR.x, curI - cornerBR.y);
                        minDist = fmin(abs(minDist), abs(BRdist));

                }

                if (curJ > leftEdge && curJ < rightEdge){
                        if(curI > topEdge && curI < bottomEdge){
                                return (trunc(minDist)*-1);
                        }
                }
                return trunc(minDist);
        }

/*      bool isItInside (const int &testI, const int &testJ) {
                if (testJ > leftEdge && testJ < rightEdge){
                        if (testI > topEdge && testI < bottomEdge){
                                return true;
                        }
                }
                return false;
        }
*/
};

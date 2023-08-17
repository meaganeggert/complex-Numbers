#include "/public/read.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include "rect.h"
#include "circle.h"
using namespace std;

[[noreturn]]
void die() {
        cout << "BAD INPUT!\n";
        exit(1);
}

string negDist(const int negDistance) {
        if (negDistance == -1) return "A";
        if (negDistance == -2) return "B";
        if (negDistance == -3) return "C";
        if (negDistance == -4) return "D";
        if (negDistance == -5) return "E";
        if (negDistance == -6) return "F";
        if (negDistance == -7) return "G";
        if (negDistance == -8) return "H";
        if (negDistance == -9) return "I";

        return "X";
}

int main() {
        const int COLS = read("Please enter number of columns:\n");
        const int ROWS = read("Please enter number of rows:\n");
        //YOU: Vet COLS and ROWS to make sure it makes sense... or die()!
        if (!cin or COLS <= 0 or ROWS <= 0) die();

        vector<Point>     roids; //Holds all asteroids we've entered
        vector<Rectangle> rects; //Holds all rectangles
        vector<Circle>    circs; //Holds all circles
        while (true) {
                const int choice = read("Do you want to enter a 1) Asteroid, 2) Rectangle, 3) Circle? 4) Quit\n");
                //cout << choice << endl;
                if (choice == 1) {
                        Point aster = read("Please enter the x,y for an asteroid:\n");
                        //YOU: Vet the asteroid to make sure it fits on the map... or die()!
                        if (!cin or aster.x > COLS or aster.x < 0 or aster.y > ROWS or aster.y < 0) die();
                        else {
                                roids.push_back(aster);
                        }
                } else if (choice == 2) {
                        //Reads a new rect in using the operator>> function in rect.h
                        //Rectangle rect = read("Please enter the x,y,half-w,half-h for a rectangle:\n");
                        cout << "Please enter the x,y,half-w,half-h for a rectangle:\n";
                        float x = read();
                        float y = read();
                        float hw = read();
                        float hh = read();
                        Rectangle rect;
                        rect.loc.x = x;
                        rect.loc.y = y;
                        rect.size.x = hw;
                        rect.size.y = hh;
                        //Vet the rect to make sure it fits on the map
                        if (!cin) die();
                        if (rect.loc.x + rect.size.x >= COLS or rect.loc.y + rect.size.y >= ROWS) die();
                        if (rect.loc.x - rect.size.x < 0 or rect.loc.y - rect.size.y < 0) die();
                        else {rects.push_back(rect);}
                } else if (choice == 3) {
                        //YOU: You need to make the operator>> for Circle in circle.h or this line won't compile
                        //cout << "hello" << endl;
                        cout << "Please enter the x,y,r for a circle:\n";
                        float x;;
                        float y;;
                        float r;
                        cin >> x >> y >> r;
                        Circle cir (x, y, r);
                        if (!cin or r<=0 or x <= 0 or y <= 0) die();
                        if (r > x or r > y) die();
                        if (r >= (COLS - x) or r >= (ROWS - y)) die();
                        else {
                                circs.push_back(cir);
                        }
                        //Circle cir = read("Please enter the x,y,r for a circle:\n");
                        //Vet the circle to make sure it fits on the map
                        //if (!cin or cir.get_X() <= 0 or cir.get_Y() <= 0) die();
                        //if (cir.get_Rad() <= 0) die();
                        //if (cir.get_Rad() > cir.get_X() or cir.get_Rad() > cir.get_Y()) die();
                        //if (cir.get_Rad() > (COLS-cir.get_X()) or cir.get_Rad() > (ROWS - cir.get_Y())) die ();


                        //circs.push_back(cir);
                } else if (choice == 4) {
                        break;
                } else die();
        }

        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        float closest = 10;

                        auto comparer = [](float closest, float dist) {
                                return abs(closest) < abs(dist) ? closest : dist;
                        };
                        for (const auto &a : roids) closest = comparer(closest,a.distance_to(j,i));
                        for (const auto &a : rects) closest = comparer(closest,a.distance_to_rect(j,i));
                        //YOU: This line won't compile until you make a distance_to function in Circle in circle.h...
                        for (const auto &a : circs) closest = comparer(closest,a.distance_to(j,i));
                        int d = int(closest);
                        if (d == 0) cout << '*';
                        else if (abs(d) >= 10) cout << '.';
                        else if (d > 0 and d < 10) cout << d;
                        //Make it print 'A' for -1, 'B' for -2, etc.
                        else if (d < 0) {
                                string distOutput;
                                distOutput = negDist(d);
                                cout << distOutput;

                        }
                }
                        cout << endl;
        }

}

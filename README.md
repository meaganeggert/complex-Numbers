## SDF-2 
### Practice with Signed Distance Fields
Practice for proper class design. Creating classes for points, circles, and rectangles and creating a signed distance field based on their locations and the points on a 2d grid.
These are the directions we were given.

---

Purpose: To teach you about classes, and extend SDF1 into a more interesting
direction, where you can have negative distances (hence a "signed" distance
field) when you are inside of a rectangle or circle.

You will be coding this assignment inside of three files:
circle.h
rect.h
main.cc

There is another file that is done for you, that you might want to look at:
point.h

point.h contains the "Point" class, formerly known as the Asteroid class, with
some important advancements such as having an overloaded operator<< and
operator>> allowing you to cin and cout a Point just like how you could an
int, or do a:
Point bob = read("Please enter a point:\n"); //Neat, eh?

You should study the Point class and ask questions about it, as you will be
emulating it for the Rectangle and Circle classes you have to write.

== SIGNED DISTANCE FIELDS ==
Your job for this assignment is to get the program working not just with
points as in SDF1 but to also make it work with a rectangle and circle. Areas
inside of a rectangle or circle have a negative distance. This is useful in a
lot of areas, such as font rendering, where you can use it to bevel the edges
of a font.

Suppose you have a rectangle that looks like this:

 ******
 *    *
 *    *
 *    *
 ******

All of the grid spaces one on the inside of the rectangle have a value of -1,
which you will print as 'A'. All spaces at -2 you will print as 'B', and so
forth, down to -9 as 'I', and then '.' for anything 10 or more away from an
edge.

So for that rectangle above, the inside would be filled like this:

 ******
 *AAAA*
 *ABBA*
 *AAAA*
 ******

If you have overlapping areas, you will output the value closest to 0. Drop
all decimals, so -0.5 would be a 0, which would be printed as a '*'.

== WHAT YOU NEED TO CODE ==
1) Vetting the input in main.cc
2) Writing the distance_to function for Rectangle (this will hurt your brain
probably, and is the hardest part, so maybe save it for last?)
3) Writing the entire Circle class, look at how the Rectangle class uses the Point
class and mimic it.
3a) Add some member variables to the Circle class
3b) Write an operator>> and operator<< for the Circle class so that you can do
I/O with it. Look at the Rectangle class for an example of how to do this
3c) Write a distance_to() function for the Circle class, this should be pretty
easy, as it's easy to use the Pythagorean theorem to find out how far away a

point is, and to tell if that point is outside or inside the circle, and by
how much by just subtracting the radius out of it.

== CULT OF THE LAMDA ==
This is probably the first time you've seen a lambda function used.

This code here -
auto comparer = [](float closest, float dist) {
        return abs(closest) < abs(dist) ? closest : dist;
};

Is identical to this code here -
float comparer(float closest, float dist) {
        return abs(closest) < abs(dist) ? closest : dist;
}

Q: So what is the benefit of it?
A: It makes you look smart. Also, it doesn't require you to make a function
and have that name floating around the namespace. Which matters on big projects.

== SAMPLE RUNS ==

Sample Run #1: Make a circle at (10,10) with a radius of 7

Please enter number of columns:
20 20
Please enter number of rows:
Do you want to enter a 1) Asteroid, 2) Rectangle, 3) Circle? 4) Quit
3
Please enter the x,y,r for a circle:
10 10 7
Do you want to enter a 1) Asteroid, 2) Rectangle, 3) Circle? 4) Quit
4
76554433333333344556
65543322222222233455
55433211111111123345
5432211*******112234
43321*****A*****1233
4321***AAABAAA***123
3211**ABBBCBBBA**112
321**ABBCCDCCBBA**12
321**ABCDDEDDCBA**12
321**ABCDEFEDCBA**12
321*ABCDEFGFEDCBA*12
321**ABCDEFEDCBA**12
321**ABCDDEDDCBA**12
321**ABBCCDCCBBA**12
3211**ABBBCBBBA**112
4321***AAABAAA***123
43321*****A*****1233
5432211*******112234
55433211111111123345
65543322222222233455

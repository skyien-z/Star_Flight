Overview:
146 nodes: ask user to enter amount of fuel for each trip––can make UI later
Each node computes distance from given node to other 145 nodes––make edge if fuel allows it
Fuel should be asked in a range

Ask user to enter in a star for the end distance

UI will control fuel and end distance along with printing stuff or displaying it
BFS needs find the end node; BFS will throw an error if fuel is not enough to get to star

UI will make sure to call graph

Design:
/**
 * helper function: compute distance between stars (star1, star2)––Graph Class
 * 
 * double for loop, and computer distance between every star
 * if distance is less than fuel (however that may work), push star* (&star) neighbors list in star class
 * How much fuel goes for: ex: 1 unit of fuel can go 1 cartesian coordinates away––distance as fuel
 * 
 */

To do for this week:
Add a vector of star* of neighbors in the star class (Kylie) –– will write tests for this
A* Implementation (Charles)
BFS (Sriram and Keesan)
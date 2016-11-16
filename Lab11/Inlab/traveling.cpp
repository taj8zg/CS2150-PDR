/**@brief traveling.cpp implements a solution to the TSP problem 
 * @details Inlab11 - traveling.cpp
 * @author Ashley Nguyen - apn2my
 * @date 4/26/16
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/** @fn computeDistance(MiddleEarth &me, string start, vector<string> dests)
 * 
 * @param me the Middle Earth object
 * @param start the city to begin the journey
 * @param dests vector holding all the cities to visit 
 *
 * @return float distance to travel to all of cities 
 * @brief calculates the distance between all the cities from the start
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
/** @fn printRoute(string start, vector<string> dests)
 *
 * @brief prints the route 
 * 
 * @param start the city to begin the journey 
 * @param dests vector holding all the cities visited en route 
 */
void printRoute (string start, vector<string> dests);

/** @brief main function to product output of TSP algorithm
 * @details takes in 5 command line parameter inputs 
 *
 * @param argc a.out
 * @param argv vector of command line arguments 
 * @return returns 0 upon completion 
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // Find shortest distance after looping through permutations
    string start = dests[0];
    vector<string> final = dests;
    float smallestDist = computeDistance(me, start, dests);
    float distance = 0.0;
    vector<string>::iterator begin = dests.begin() + 1; //
    vector<string>::iterator end = dests.end();
    
    // Sort the vector -- can be costly? 
    sort(begin, end);
    // Find permutation of shortest distances 
    while( next_permutation(begin, end)){
	distance = computeDistance(me, start, dests);
	if( distance < smallestDist ){
	  smallestDist = distance;
	  final = dests;
	}
    }

      printRoute(start, final);
      cout << endl;
      cout << "and will have length " << smallestDist << endl;

      return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float result = 0.0;
  for(int i = 0; i < dests.size(); i++){
    result += me.getDistance(start, dests[i]);
    start = dests[i];
  }
  result += me.getDistance(dests[0],dests[dests.size()-1]);
  return result; 
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  cout << "Your journey will take you along the path ";
  for(int i = 0; i < dests.size(); i++){
    cout << dests[i] << " -> ";
  }
  cout << start;
}

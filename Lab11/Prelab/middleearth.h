// Ashley Nguyen - apn2my
// PreLab11 - middleearth.h
// 4.24.16
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
/** @def MIDDLEEARTH_H 
 * defines the header file for middle earth if not previously defined
 *
 */
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

/**@headerfile middleearth.h "middleearth.h"
 *
 *
 *
 */
class MiddleEarth {
  /** @privatesection
   *
   */
private:
  /** @var int num_city_names 
   * @var int xsize
   * @var int ysize
   * @brief number of cities, width and height sizes
   */
    int num_city_names, xsize, ysize;
    /** @var vector<float> xpos 
     * @var vector<float> ypos
     * @brief x and y positions 
     */
    vector<float> xpos, ypos;
    /** @var vector<string> cities
     */
    vector<string> cities;
    /** @var float *distances
     */
    float *distances;
    /** @var map<string, int> indices
     * @brief map of indices
     */
    map<string, int> indices;

/** @publicsection
 *
 */
public:
/** @fn MiddleEarth(int xsize, int ysize, int num_cities, int seed)
 * @brief MiddleEarth constructor, Iluvatar 
 * @param xsize width 
 * @param ysize height 
 * @param num_cities number of cities 
 * @param seed random seed 
 */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    /** @fn ~MiddleEarth()
     */
    ~MiddleEarth();
    /** @fn print()
     */
    void print();
    /** @fn printTable()
     */
    void printTable();
    /** @fn getDistance(string city1, string city2)
     * @param city1 first city 
     * @param city2 second city 
     */
    float getDistance (string city1, string city2);
    /**@fn getItinerary (unsigned int length)
     * @param length 
     */
    vector<string> getItinerary(unsigned int length);
};

#endif

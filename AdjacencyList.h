#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

// how to make a pair
pair<string, double> productOne ("tomatoes",2.30);

// or

pair<string, double> productTwo = {"tomatoes",2.30};

class AdjacencyList {

    // Think about what member variables you need to initialize
    int pageID;
    vector<pair<int, int>> adjacents;

    // map<pageId, adjacents<pageId, weight>
    map<int, vector<pair<int, int>>> adj;

public:

    // Think about what helper functions you will need in the algorithm

    /* prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and
    rounding rank to two decimal places */
    void PageRank(int n);

};


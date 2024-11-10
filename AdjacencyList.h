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
    vector<string> adjacents;

    // map<pageId, adjacents<pageId>
    map<int, vector<int>> adjList;
    vector<int> existingSite;

    int totalPages = 0;

public:

    // Think about what helper functions you will need in the algorithm

    void addPage(string URL);
    void setEdge();


    /* prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and
    rounding rank to two decimal places */
    void PageRank(int n);

};


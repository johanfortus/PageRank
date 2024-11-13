#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

class AdjacencyList {

    // Private member variable
    int totalPages = 0;

public:

    // Public member variables
    map<string, vector<string>> adjList;
    set<string> webPages;
    map<string, int> pageID;
    map<int, string> pageURL;

    // setEdge allows for the insertion of two nodes, whether they exist or not
    void setEdge(string webPageOne, string webPageTwo);

    // Prints rank of pages after p iterations in alphabetical order and rounded to two decimal places
    void PageRank(int n);

};
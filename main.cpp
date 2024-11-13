#include <iostream>
#include <string>
#include <sstream>
#include "AdjacencyList.h"
using namespace std;

int main() {

    // read first number of lines (n) from cin
    int n;
    cin >> n;
    cout << endl;

    // read the number of power iterations (p) from cin
    int p;
    cin >> p;
    cout << endl;

    // Initialize Graph
    AdjacencyList Graph;

    // for each of the next n lines, read in the vertices from and to
    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        istringstream in(line);

        // read in the source vertex
        string from;
        cin >> from;

        // read in the destination vertex
        string to;
        cin >> to;

        // Add Vertices & Edges
        Graph.setEdge(from, to);
    }

    // Power Iterations
    Graph.PageRank(p);
    return 0;
}
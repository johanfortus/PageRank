#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cmath>
#include "AdjacencyList.h"
using namespace std;

int main() {

    // read first number of lines (n) from cin
    int n;
    cout << "How many lines? ";
    cin >> n;
    cout << endl;

    // read the number of power iterations (p) from cin
    int p;
    cout << "How many power iterations? ";
    cin >> p;
    cout << endl;


    // Automate test case from canvas
    vector<string> froms = {"google.com", "google.com", "facebook.com", "ufl.edu", "ufl.edu", "maps.com", "gmail.com"};
    vector<string> tos = {"gmail.com", "maps.com", "ufl.edu", "google.com", "gmail.com", "facebook.com", "maps.com"};


    AdjacencyList Graph;

    // for each of the next n lines, read in the vertices from and to
    for(int i = 0; i < n; i++) {
//        string line;
//        getline(cin, line);
//        istringstream in(line);


        // read in the source vertex
        string from;
        cout << "FROM: ";
//        cin >> from;
        from = froms[i];
        cout << from;
        cout << endl;

        // read in the destination vertex
        string to;
        cout << "TO: ";
//        cin >> to;
        to = tos[i];
        cout << to;
        cout << endl;

        // ADD VERTICES / EDGE (FROM->TO) TO YOUR ADJACENCY LIST HERE
        Graph.setEdge(from, to);

    }

    Graph.printGraph();

    // DO POWER ITERATIONS HERE

    return 0;
}
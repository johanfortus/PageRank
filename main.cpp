#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    // read first number of lines (n) from cin
    int n;
    cin >> n;

    // read the number of power iterations (p) from cin
    int p;
    cin >> p;

    // for each of the next n lines, read in the vertices from and to
    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        istringstream in(line);


        // read in the source vertex
        string from;
        in >> from;

        // read in the destination vertex
        string to;
        in >> to;

        // ADD VERTICES / EDGE (FROM->TO) TO YOUR ADJACENCY LIST HERE
    }

    // DO POWER ITERATIONS HERE

    return 0;
}
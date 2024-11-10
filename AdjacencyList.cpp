#include "AdjacencyList.h"


void AdjacencyList::setEdge(string webPageOne, string webPageTwo) {
    vector<string>::iterator iter;

    iter = find(webPages.begin(), webPages.end(), webPageOne);
    if(iter == webPages.end()) {
        cout << webPageOne << " WAS NOT FOUND" << endl;
        webPages.push_back(webPageOne);
    }

    iter = find(webPages.begin(), webPages.end(), webPageTwo);
    if(iter == webPages.end()) {
        cout << webPageTwo << " WAS NOT FOUND" << endl;
        webPages.push_back(webPageTwo);
    }
    cout << endl;

}
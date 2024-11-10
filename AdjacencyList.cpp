#include "AdjacencyList.h"


void AdjacencyList::setEdge(string webPageOne, string webPageTwo) {
//    vector<string>::iterator iter;
//
//    iter = find(webPages.begin(), webPages.end(), webPageOne);
//    if(iter == webPages.end()) {
//        cout << webPageOne << " WAS NOT FOUND" << endl;
//        webPages.push_back(webPageOne);
//    }
//
//    iter = find(webPages.begin(), webPages.end(), webPageTwo);
//    if(iter == webPages.end()) {
//        cout << webPageTwo << " WAS NOT FOUND" << endl;
//        webPages.push_back(webPageTwo);
//    }


    webPages.insert(webPageOne);
    if(webPages.size() != totalPages) {
        totalPages++;
        pageIdOf[webPageOne] = totalPages;
    }


    webPages.insert(webPageTwo);
    if(webPages.size() != totalPages) {
        totalPages++;
        pageIdOf[webPageTwo] = totalPages;
    }

//    map<string, int>::iterator iter;
//    for(iter = getPageID.begin(); iter != getPageID.end(); iter++) {
//        cout << iter->first << endl;
//    }

    for(auto i : pageIdOf) {
        cout << i.first << " : " << i.second << endl;
    }







    webPages.insert(webPageTwo);
    cout << endl;

}
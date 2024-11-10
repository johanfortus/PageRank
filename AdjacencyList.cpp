#include "AdjacencyList.h"


void AdjacencyList::setEdge(string webPageOne, string webPageTwo) {
    webPages.insert(webPageOne);
    if(webPages.size() != totalPages) {
        totalPages++;
        pageIdOf[webPageOne] = totalPages;
        pageUrlOf[totalPages] = webPageOne;
    }

    webPages.insert(webPageTwo);
    if(webPages.size() != totalPages) {
        totalPages++;
        pageIdOf[webPageTwo] = totalPages;
        pageUrlOf[totalPages] = webPageTwo;
    }

    map<int, vector<int>>::iterator iter;

    adjList[pageIdOf[webPageOne]].push_back(pageIdOf[webPageTwo]);


    cout << adjList[pageIdOf[webPageOne]].size() << endl;
    for(auto i : pageIdOf) {
        cout << i.first << " : " << i.second << endl;
    }
}

void AdjacencyList::printGraph() {

    map<int, vector<int>>::iterator iter;

//    for(iter = adjList.begin(); iter != adjList.end(); iter++) {
//        cout << iter->first << " : [";
//        for(int j = 0; j < iter->second.size(); j++) {
//            if(j == iter->second.size() - 1)
//                cout << iter->second[j];
//            else
//                cout << iter->second[j] << ", ";
//        }
//        cout << "] " << endl;
//    }

    for(iter = adjList.begin(); iter != adjList.end(); iter++) {
        cout << pageUrlOf[iter->first] << " : [";
        for(int j = 0; j < iter->second.size(); j++) {
            if(j == iter->second.size() - 1)
                cout << pageUrlOf[iter->second[j]];
            else
                cout << pageUrlOf[iter->second[j]] << ", ";
        }
        cout << "] " << endl;
    }


}
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

    adjList[pageIdOf[webPageOne]].push_back(pageIdOf[webPageTwo]);
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

void AdjacencyList::PageRank(int n) {
    map<int, float> ranking;
    float defaultRank = 1.0 / adjList.size();
    for(auto i : adjList)
        ranking[i.first] = defaultRank;

    for(int i = 0; i < n - 1; i++) {
        map<int, float> newRanking;
        for(auto page : adjList)
            newRanking[page.first] = 0;

        for(auto j : adjList) {
            for(auto outgoingLink : j.second)
                newRanking[outgoingLink] = newRanking[outgoingLink] + ranking[j.first] / j.second.size();
        }

        for(auto page : newRanking)
            ranking[page.first] = page.second;
    }

    for(auto i : ranking)
        cout << pageUrlOf[i.first] << " : " << i.second << endl;
}
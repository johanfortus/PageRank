#include "AdjacencyList.h"

void AdjacencyList::setEdge(string webPageOne, string webPageTwo) {
    if(webPages.find(webPageOne) == webPages.end()) {
        totalPages++;
        webPages.insert(webPageOne);
        pageID[webPageOne] = totalPages;
        pageURL[totalPages] = webPageOne;
    };

    if(webPages.find(webPageTwo) == webPages.end()) {
        totalPages++;
        webPages.insert(webPageTwo);
        pageID[webPageTwo] = totalPages;
        pageURL[totalPages] = webPageTwo;
    }
    adjList[webPageOne].push_back(webPageTwo);
}

void AdjacencyList::PageRank(int n) {
    map<string, double> Ranking;
    double defaultRank = 1.0 / totalPages;
//    cout << "Default Rank: " << defaultRank << endl << endl;
    for(auto page : adjList) {
        Ranking[page.first] = defaultRank;
    }

    for(int i = 0; i < n - 1; i++) {
        map<string, double> newRanking;
        for(auto page : Ranking) {
            newRanking[page.first] = 0;
        }

//        for(auto page : newRanking) {
//            cout << page.first << " : " << page.second << endl;
//        }

        for(auto page : adjList) {
//            cout << page.first << " : " << page.second.size() << " outdegrees" << endl;

            for(auto outdegreeLink : page.second) {
                newRanking[outdegreeLink]+=Ranking[page.first] / page.second.size();
            }
        }

        for(auto page : newRanking) {
//            cout << page.first << " : " << page.second << endl;
            Ranking[page.first] = page.second;
        }
    }
    cout << fixed << setprecision(2);
    for(auto page : Ranking) {
        cout << page.first << " " << page.second << endl;
    }
}

void AdjacencyList::printGraph() {
    for(auto i : adjList) {
        cout << i.first << " : [";
        for(int j = 0; j < i.second.size(); j++) {
            if(j == i.second.size() - 1) {
                cout << i.second[j];
            }
            else {
                cout << i.second[j] << ", ";
            }
        }
        cout << "]" << endl;
    }
}
void AdjacencyList::printIDs() {
    for(auto page : pageID) {
        cout << page.first << " : " << page.second << endl;
    }
}
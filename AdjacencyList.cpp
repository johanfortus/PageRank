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


//    cout << adjList[pageIdOf[webPageOne]].size() << endl;
//    for(auto i : pageIdOf) {
//        cout << i.first << " : " << i.second << endl;
//    }
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

    cout << "Graph size: " << adjList.size() << endl;

}

void AdjacencyList::PageRank(int n) {

    map<int, float> ranking;
    float defaultRank = 1.0 / adjList.size();
    cout << "Default Rank: " << defaultRank << endl;
    for(auto i : adjList) {
//        cout << "Page ID: " << pageId.first << ", Outgoing Links: " << pageId.second.size() << endl;

        ranking[i.first] = defaultRank;

    }

//    for(auto pageId : ranking) {
//        cout << pageId.first << " : " << pageId.second << endl;
//    }



//    for(auto i : newRanking) {
//        cout << i.first << " : " << i.second << endl;
//    }

    for(int i = 0; i < n; i++) {
        map<int, float> newRanking;

        for(auto page : adjList) {
            newRanking[page.first] = 0;
        }




        for(auto j : adjList) {
            for(auto outgoingLink : j.second) {
                cout << "newRanking[" << outgoingLink << "] (" << pageUrlOf[outgoingLink] << ") going to be ";
                cout << newRanking[outgoingLink] << " + " << ranking[j.first] << " / " << j.second.size() << endl;
                newRanking[outgoingLink] = newRanking[outgoingLink] + ranking[j.first] / j.second.size();
                cout << newRanking[outgoingLink] << endl;
            }
        }

        cout << "Iterating through newRanking: " << endl;
        for(auto page : newRanking) {
            cout << page.first << " (" << pageUrlOf[page.first] <<") : " << page.second << endl;
        }


        for(auto page : newRanking) {
            ranking[page.first] = page.second;
        }

        cout << "Iterating ranking: " << endl;
        for(auto page : ranking) {
            cout << page.first << " : " << page.second <<endl;
        }

        cout << endl;
    }



//    for(auto i : ranking) {
//        cout << i.first << " : " << i.second << endl;
//    }
}
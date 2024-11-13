#include "AdjacencyList.h"

void AdjacencyList::setEdge(string webPageOne, string webPageTwo) {

    // If webPageOne is not an existing node in the adjacency list
    if(webPages.find(webPageOne) == webPages.end()) {
        totalPages++;
        webPages.insert(webPageOne);
        pageID[webPageOne] = totalPages;
        pageURL[totalPages] = webPageOne;
        adjList[webPageOne];
    };

    // If webPageTwo is not an existing node in the adjacency list
    if(webPages.find(webPageTwo) == webPages.end()) {
        totalPages++;
        webPages.insert(webPageTwo);
        pageID[webPageTwo] = totalPages;
        pageURL[totalPages] = webPageTwo;
        adjList[webPageTwo];
    }

    // Set webPageTwo as an adjacent to webPageOne
    adjList[webPageOne].push_back(webPageTwo);
}

void AdjacencyList::PageRank(int n) {

    // Initialize ranking map & default ranks
    map<string, double> Ranking;
    double defaultRank = 1.0 / totalPages;
    for(auto page : adjList)
        Ranking[page.first] = defaultRank;

    // Loops (p) power iterations
    for(int i = 0; i < n - 1; i++) {

        // Initialize map containing the modified ranks of the web pages, and setting all to 0
        map<string, double> newRanking;
        for(auto page : Ranking)
            newRanking[page.first] = 0;

        // Set the page's new rank or update/accumulate the page's new rank
        for(auto page : adjList) {
            for(auto outdegreeLink : page.second)
                newRanking[outdegreeLink]+=Ranking[page.first] / page.second.size();
        }

        // Set Ranking's values to newRanking values
        for(auto page : newRanking)
            Ranking[page.first] = page.second;
    }

    // Print Web Page ranks and round to two decimal places
    cout << fixed << setprecision(2);
    for(auto page : Ranking)
        cout << page.first << " " << page.second << endl;
}
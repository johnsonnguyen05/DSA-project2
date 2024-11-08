#include "AdjacencyList.h"
#include <iomanip>
#include <sstream>

map<string, pair<vector<pair<string, float>>, float>> AdjacencyList::getGraph() {
    return this->graph;
}

void AdjacencyList::insert(string from, string to) {
    if (this->graph.find(from) == this->graph.end()) { //insertion from and to
        this->graph[from] = {{}, 1}; //initalize empty neighbors with temp outdegree value
    }

    this->graph[from].first.push_back({to, 1}); //add addition dest

    if (this->graph.find(to) == this->graph.end()) { //edge case where webpage has no outgoing
        this->graph[to] = {{}, 1}; //initalize empty neighbors with temp outdegree value
    }
}

void AdjacencyList::check() { //display data
    for (auto node : this->graph) {
        cout << "{" << node.first << " : ";
        for (auto adjacent : node.second.first) {
            cout << "{" << adjacent.first << ", " << adjacent.second << "} ";
        }
        cout << node.second.second << "} " <<endl;
    }
}

void AdjacencyList::pageRank(int p) {
    float n = this->graph.size();

    for (auto& node : this->graph) {
        node.second.second = 1.0f / n; //normalize ranks, r(0)
    }

    for (int i = 1; i < p; i++) { //power iterations
        map<string, float> newRanks;

        // Initialize new ranks for the next iteration
        for (auto& node : this->graph) {
            newRanks[node.first] = 0.0f;
        }

        // Calculate rank contributions based on incoming links
        for (auto& node : this->graph) {
            float currentRank = node.second.second;
            int outDegree = node.second.first.size();

            if (outDegree > 0) {
                float distributedRank = currentRank / outDegree;
                for (auto& adjacent : node.second.first) {
                    newRanks[adjacent.first] += distributedRank;
                }
            }
        }

        // Update each node's rank for the next iteration
        for (auto& node : this->graph) {
            node.second.second = newRanks[node.first];
        }
    }

    for (auto node : this->graph) { //display in alphabetical order
            cout << node.first << ' ' << fixed << setprecision(2) << node.second.second << endl;
        }
}
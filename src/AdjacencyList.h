#include "adjacencylist.cpp"
#include <iomanip>

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

        for (auto& node : this->graph) {
            float outerRank = node.second.second / node.second.first.size(); //get new ranks, and store in map for later updates
            for (auto& adjacent : node.second.first) {
                newRanks[adjacent.first] += outerRank;
            }
        }

        for (auto& node : this->graph) {
            for (auto rank : newRanks) {
                if (rank.first == node.first) {
                    node.second.second = newRanks[node.first]; //update ranks
                }
            }
        }
    }

    for (auto node : this->graph) { //display in alphabetical order
            cout << node.first << ' ' << fixed << setprecision(2) << node.second.second << endl;
        }
}
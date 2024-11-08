
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class AdjacencyList
{
private:
    map<string, pair<vector<pair<string, float>>, float>> graph; //holy { (from) : {{(to), (degree)}, {(to), (degree)} , (rank)}}
public:
    map<string, pair<vector<pair<string, float>>, float>> getGraph();
    void insert(string from, string to);
    void check();
    void pageRank(int p);
};
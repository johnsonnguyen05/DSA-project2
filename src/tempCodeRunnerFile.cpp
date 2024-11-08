#include "adjacencylist.h"

int main()
{
    AdjacencyList graph;

    int no_of_lines, power_iterations;
    std::string from, to;

    std::cin >> no_of_lines;
    std::cin >> power_iterations;

    for (int i = 0; i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        graph.insert(from, to);
    }

    graph.pageRank(power_iterations);

    return 0;
}
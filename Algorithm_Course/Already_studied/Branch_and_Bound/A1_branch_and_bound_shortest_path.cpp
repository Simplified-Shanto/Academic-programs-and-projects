#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct SearchState {
    int currentVertex;
    int distanceSoFar;
    vector<int> pathSoFar;
};

bool vertexAlreadyInPath(const vector<int>& pathSoFar, int candidateVertex) {
    for (int vertex : pathSoFar) {
        if (vertex == candidateVertex) {
            return true;
        }
    }
    return false;
}

void printPath(const vector<int>& path, const vector<char>& vertexName) {
    for (int pathIndex = 0; pathIndex < static_cast<int>(path.size()); pathIndex++) {
        cout << vertexName[path[pathIndex]];
        if (pathIndex + 1 < static_cast<int>(path.size())) {
            cout << " -> ";
        }
    }
}

int main() {
    // Vertex numbers make the adjacency list easy to store; vertexName makes output readable.
    const int sourceVertex = 0;
    const int goalVertex = 6;
    vector<char> vertexName = {'S', 'A', 'B', 'C', 'D', 'E', 'G'};

    // {neighbourVertex, edgeWeight}; every edge is undirected in this practice graph.
    vector<vector<pair<int, int>>> graph = {
        {{1, 3}, {2, 6}},                  // S
        {{0, 3}, {3, 7}, {4, 2}},          // A
        {{0, 6}, {4, 3}, {5, 6}},          // B
        {{1, 7}, {6, 2}},                  // C
        {{1, 2}, {2, 3}, {5, 2}, {6, 4}},  // D
        {{2, 6}, {4, 2}, {6, 1}},          // E
        {{3, 2}, {4, 4}, {5, 1}}           // G
    };

    // S -> A -> D -> G is already a valid solution, so it gives an upper bound of 9.
    // Branch and bound only explores a new path if it can improve this known answer.
    int bestKnownDistance = 9;
    vector<int> bestKnownPath = {sourceVertex, 1, 4, goalVertex};

    queue<SearchState> statesToExplore;
    statesToExplore.push({sourceVertex, 0, {sourceVertex}});

    while (!statesToExplore.empty()) {
        SearchState currentState = statesToExplore.front();
        statesToExplore.pop();

        cout << "Exploring: ";
        printPath(currentState.pathSoFar, vertexName);
        cout << "   distance = " << currentState.distanceSoFar << '\n';

        for (const auto& [neighbourVertex, edgeWeight] : graph[currentState.currentVertex]) {
            // With positive weights, a cycle only makes a path longer, never better.
            if (vertexAlreadyInPath(currentState.pathSoFar, neighbourVertex)) {
                continue;
            }

            int candidateDistance = currentState.distanceSoFar + edgeWeight;

            // This is the bound: a path already as expensive as the best answer cannot win.
            if (candidateDistance >= bestKnownDistance) {
                cout << "  Pruned at " << vertexName[neighbourVertex]
                     << ": candidate distance " << candidateDistance
                     << " >= bound " << bestKnownDistance << '\n';
                continue;
            }

            vector<int> candidatePath = currentState.pathSoFar;
            candidatePath.push_back(neighbourVertex);

            if (neighbourVertex == goalVertex) {
                bestKnownDistance = candidateDistance;
                bestKnownPath = candidatePath;
                cout << "  Better complete path found. New bound = "
                     << bestKnownDistance << '\n';
            } else {
                // queue makes this a breadth-first exploration of the search tree.
                statesToExplore.push({neighbourVertex, candidateDistance, candidatePath});
            }
        }
    }

    cout << "\nShortest path: ";
    printPath(bestKnownPath, vertexName);
    cout << "\nShortest distance: " << bestKnownDistance << '\n';
}

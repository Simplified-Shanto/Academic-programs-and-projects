#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// The enum values are still stored internally as 0, 1, 2, ...,
// but the graph can now use the meaningful vertex letters.
enum Vertex { S, A, B, C, D, E, G };

int main() {
    const Vertex source = S;
    const Vertex goal = G;

    // {neighbour, weight}
    vector<vector<pair<Vertex, int>>> graph = {
        {{A, 3}, {B, 6}},                  // S
        {{S, 3}, {C, 7}, {D, 2}},          // A
        {{S, 6}, {D, 3}, {E, 6}},          // B
        {{A, 7}, {G, 2}},                  // C
        {{A, 2}, {B, 3}, {E, 2}, {G, 4}},  // D
        {{B, 6}, {D, 2}, {G, 1}},          // E
        {{C, 2}, {D, 4}, {E, 1}}           // G
    };

    // We already know S -> A -> D -> G costs 9, so use 9 as the first bound.
    int bestDistance = 9;

    // Each queue entry is {current vertex, distance of the path reaching it}.
    queue<pair<Vertex, int>> statesToExplore;
    statesToExplore.push({source, 0});

    while (!statesToExplore.empty()) {
        auto [currentVertex, distanceSoFar] = statesToExplore.front();
        statesToExplore.pop();

        for (auto [neighbour, edgeWeight] : graph[currentVertex]) {
            int candidateDistance = distanceSoFar + edgeWeight;

            // Bound: this path cannot improve the best complete answer.
            if (candidateDistance >= bestDistance) {
                continue;
            }

            if (neighbour == goal) {
                bestDistance = candidateDistance; // Found a better answer.
            } else {
                statesToExplore.push({neighbour, candidateDistance}); // Branch.
            }
        }
    }

    cout << "Shortest distance = " << bestDistance << '\n';
}

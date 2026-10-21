#include <iostream>
#include <vector>

using namespace std;

const int vertexCount = 4;
const int availableColorCount = 3;

// adjacencyMatrix[u][v] is 1 when an undirected edge connects u and v.
// Edges: 0--1, 0--2, 1--2, 1--3, and 2--3.
vector<vector<int>> adjacencyMatrix = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};

// Checks whether candidateColor can be assigned to currentVertex.
bool isColorSafe(
    const vector<int>& colorOfVertex,
    int currentVertex,
    int candidateColor
) {
    // Only adjacent vertices matter. Non-adjacent vertices may share a color.
    for (int neighbourVertex = 0;
         neighbourVertex < vertexCount;
         neighbourVertex++) {

        bool isNeighbour = adjacencyMatrix[currentVertex][neighbourVertex] == 1;
        bool neighbourUsesCandidateColor =
            colorOfVertex[neighbourVertex] == candidateColor;

        if (isNeighbour && neighbourUsesCandidateColor) {
            return false;
        }
    }
    return true;
}

// Attempts to assign a valid color to currentVertex and all later vertices.
bool colorGraph(vector<int>& colorOfVertex, int currentVertex) {
    // All vertices received valid colors, so one solution was found.
    if (currentVertex == vertexCount) {
        return true;
    }

    // Try every available color for the current vertex.
    for (int candidateColor = 1;
         candidateColor <= availableColorCount;
         candidateColor++) {

        if (isColorSafe(colorOfVertex, currentVertex, candidateColor)) {
            colorOfVertex[currentVertex] = candidateColor;

            // Continue by coloring the next vertex.
            if (colorGraph(colorOfVertex, currentVertex + 1)) {
                return true;
            }

            // Later vertices could not be colored, so undo this choice.
            colorOfVertex[currentVertex] = -1;
        }
    }

    // No available color works for this vertex under the current choices.
    return false;
}

int main() {
    // -1 means the vertex has not received a color yet.
    vector<int> colorOfVertex(vertexCount, -1);

    if (colorGraph(colorOfVertex, 0)) {
        cout << "A valid coloring using " << availableColorCount
             << " colors:\n";

        for (int vertex = 0; vertex < vertexCount; vertex++) {
            cout << "Vertex " << vertex << " -> Color "
                 << colorOfVertex[vertex] << '\n';
        }
    } else {
        cout << "No valid coloring exists with " << availableColorCount
             << " colors.\n";
    }

    return 0;
}

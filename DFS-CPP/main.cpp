#include <iostream>

#define MAX 50

using namespace std;

template <class T>
class List {
private:
    T data[MAX];
    int length;
public:
    List() { length = 0; }
    void InsertEnd(T val) { if (length < MAX) data[length++] = val; }
    void Print() {
        for (int i = 0; i < length; i++) cout << data[i] << " ";
        cout << endl;
    }
    void Clear() { length = 0; }
};

template<class T>
class Graph {
private:
    T adjMatrix[MAX][MAX];
    int numVertices, vertices[MAX];
public:
    Graph();
    void LoadFixedGraph();
    void PrintMatrix();
    void FindConnectedComponents();
    void DFS(int, int[], List<T>&);
};

// Constructor
template<class T>
Graph<T>::Graph() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
    numVertices = 0;
    for (int i = 0; i < MAX; i++) vertices[i] = i;
}

// Load the fixed graph of 50 nodes and 85 edges
template <class T>
void Graph<T>::LoadFixedGraph() {
    numVertices = 50;
    int edges[][2] = {
        {0,29},{0,46},{0,21},{0,14},{0,38},{0,31},{1,41},{1,31},{1,21},{1,17},
        {2,9},{2,26},{2,5},{2,25},{2,4},{3,18},{3,30},{3,47},{4,28},{4,9},
        {4,8},{5,44},{5,12},{6,37},{6,10},{7,23},{7,22},{7,39},{9,19},{9,28},
        {9,27},{11,33},{13,25},{13,38},{13,29},{14,26},{14,28},{14,39},
        {15,22},{15,31},{15,19},{15,41},{16,46},{16,26},{16,38},{16,27},
        {17,40},{17,29},{18,45},{18,42},{18,35},{18,33},{18,47},{20,36},
        {20,49},{20,42},{22,26},{22,34},{23,31},{23,32},{23,40},{24,31},
        {24,44},{25,38},{26,31},{27,32},{29,48},{29,41},{30,47},{30,37},
        {33,36},{33,49},{34,48},{35,45},{36,45},{37,49},{37,45},{37,47},
        {38,41},{40,48},{41,44},{42,49},{43,48},{45,47}
    };

    int totalEdges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < totalEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}

// Print adjacency matrix
template<class T>
void Graph<T>::PrintMatrix() {
    cout << "\nAdjacency Matrix (1 = edge, 0 = no edge):\n\n     ";
    for (int i = 0; i < numVertices; i++)
        cout << (i < 10 ? "  " : " ") << i;
    cout << "\n";

    for (int i = 0; i < numVertices; i++) {
        cout << (i < 10 ? " " : "") << i << "  ";
        for (int j = 0; j < numVertices; j++) {
            cout << "  " << adjMatrix[i][j];
        }
        cout << "\n";
    }
}

// DFS using explicit stack
template <class T>
void Graph<T>::DFS(int start, int visited[], List<T>& component) {
    int stack[MAX];
    int top = -1;

    // Push start vertex onto stack
    stack[++top] = start;

    while (top >= 0) {
        int current = stack[top--];
        if (!visited[current]) {
            visited[current] = 1;
            component.InsertEnd(vertices[current]);

            // Push adjacent vertices not visited
            for (int j = numVertices - 1; j >= 0; j--) { // Reverse order to match recursive order
                if (adjMatrix[current][j] != 0 && !visited[j]) {
                    stack[++top] = j;
                }
            }
        }
    }
}

// Find all connected components
template <class T>
void Graph<T>::FindConnectedComponents() {
    int visited[MAX] = {0};
    List<T> component;
    int count = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            component.Clear();
            DFS(i, visited, component);
            count++;
            cout << "\nComponent " << count << ": ";
            component.Print();
        }
    }
    cout << "\nTotal connected components: " << count << endl;
}

int main() {
    Graph<int> G;
    G.LoadFixedGraph();
    G.PrintMatrix();
    G.FindConnectedComponents();
    return 0;
}

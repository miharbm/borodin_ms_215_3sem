#include <iostream>
#include <fstream>
#include <cmath>
#include "graph.h"
#include "tests.h"
using namespace std;

int main(int argc, char *argv[]) {
    bool end = false;

    while (!end) {

        int GraphType;
        int n_vertex;
        int n_arcs;
        int TaskType;

        cout << "Type of graph:\n1. Graph\n2. Digraph\n";
        cin >> GraphType;
        bool mode = (GraphType == 1) ? true : false;

        cout << "Number of vertex: ";
        cin >> n_vertex;

        cout << "Number of arcs: ";
        cin >> n_arcs;

        cout << "Task:\n1. BestPath\n2. BestPathThroughput\n";
        cin >> TaskType;

        Graph graph;
        pair<double, vector<Node*>> path;
        graph.Generate(n_vertex, n_arcs, mode);

        if (TaskType == 1) {
            path = graph.SearchBestPath(graph.GetVertex(0), graph.GetVertex(n_vertex - 1));
        }
        else if (TaskType == 2) {
            path = graph.SearchBestPathThroughput(graph.GetVertex(0), graph.GetVertex(n_vertex - 1));
        }

        graph.DrawInFilePath("path.png", "Graph", path.second);

        cout << "Your graph in file path.png\n";
        if (TaskType == 1) {
            cout << "Min lenght: ";
        }
        else if (TaskType == 2) {
            cout << "Max throughput: ";
        }
        if (abs(path.first - 1e10) < 1e-1) cout << "There is no path connecting these vertex";
        else cout << path.first;

        ofstream len_of_path("len.txt");
        if (abs(path.first - 1e10) < 1e-1) len_of_path << "There is no path connecting these vertex";
        else len_of_path << path.first;
        len_of_path.close();

        cout << "\nContinue?\n1. Yes\n2. No\n";
        int a;
        cin >> a;
        end = (a == 1) ? false : true;
    }

    return 0;
}

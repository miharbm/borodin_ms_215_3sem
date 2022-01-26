#ifndef GRAPH_H
#define GRAPH_H

#pragma once
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

class Node;

class Arc {                                                 // класс ребра
public:
    Node *_start;
    Node *_end;
    double _value;                                          // цена или пропускная способность - зависит от задачи

    Arc(Node *start, Node *end, double value = 1) {
        _start = start;
        _end = end;
        _value = value;
    }
};

class Node {                                // класс вершины
public:
    int id = 0;                             // необходим для упрощения обращения к вершинам в графе
    vector<Arc*> _outboundArcs = {};        // исходящие ребра

    void AddOutboundArc(Arc *arc) {
        _outboundArcs.push_back(arc);
    }
};

class Graph {
public:
    bool _mode;                     // true - граф неориентированный, false - граф неориентированный
    vector<Node*> _graph;

    Graph(bool mode = 1) {
        _mode = mode;
    }
    Graph(int n, bool mode) {
        _mode = mode;
        for (int i = 0; i < n; ++i)
            AddVertex();
    }
    Graph(vector<vector<double>> matrix);       // построение графа по матрице смежности, любое ненулевое значение - ребро

    void MakeGraphFromMatrix(vector<vector<double>> matrix);

    void AddVertex(Node *node = nullptr);
    void AddArc(Node *start, Node *end, double value = 1);

    Node* GetVertex(int i);

    //vector<vector<bool>> GetMatrix();             // получение матрицы смежности
    vector<vector<double>> GetMatrix();             // получение матрицы смежности

    void DrawInFile(const string& output = "graph.png", const string& name_of_graph = "Graph");
    void DrawInFilePath(string output = "graph.png", string name_of_graph = "Graph", vector<Node*> path = {});

    pair<double, vector<Node*>> SearchBestPath(Node* start, Node* end);   // поиск наименьшего пути, алгоритм Дейкстры
    pair<double, vector<Node*>> SearchBestPathThroughput(Node* start, Node* end);   // поиск пути с наибольшей пропускной способностью

    void Generate(int n, int m = -1, bool mode = 1);
};

#endif // GRAPH_H

#ifndef TESTS_H
#define TESTS_H

#include <fstream>
#include <cmath>
#include <chrono>
#include "graph.h"
using namespace std;

void SaveTimeGenerationGraph() {
    ofstream out("generationGraph.txt");
    for (int i = 10; i < 1e4; i += 100) {
        Graph g;
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.Generate(i);
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeBestPathGraph() {
    ofstream out("bestPathGraph.txt");
    for (int i = 10; i < 1e4; i += 100) {
        Graph g;
        g.Generate(i);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.SearchBestPath(g.GetVertex(0), g.GetVertex(1));   // поскольку для обсчета любых 2х вершин строится весь граф
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeBestPathThroughputGraph() {
    ofstream out("bestPathThroughputGraph.txt");
    for (int i = 10; i < 1e4; i += 100) {
        Graph g;
        g.Generate(i);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.SearchBestPathThroughput(g.GetVertex(0), g.GetVertex(1));   // поскольку для обсчета любых 2х вершин строится весь граф
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeDrawingGraph() {
    ofstream out("drawingGraph.txt");
    for (int i = 1; i < 100; ++i) {
        Graph g;
        g.Generate(i);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.DrawInFile();
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeGenerationDigraph() {
    ofstream out("generationDigraph.txt");
    for (int i = 10; i < 1e4; i += 100) {
        Graph g(0);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.Generate(i, -1, 0);
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeBestPathDigraph() {
    ofstream out("bestPathDigraph.txt");
    for (int i = 10; i < 1e4; i += 100) {
        Graph g(0);
        g.Generate(i, -1, 0);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.SearchBestPath(g.GetVertex(0), g.GetVertex(1));   // поскольку для обсчета любых 2х вершин строится весь граф
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeBestPathThroughputDigraph() {
    ofstream out("bestPathThroughputDigraph.txt");
    for (int i = 10; i < 1e4; i += 100) {
        Graph g(0);
        g.Generate(i, -1, 0);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.SearchBestPathThroughput(g.GetVertex(0), g.GetVertex(1));   // поскольку для обсчета любых 2х вершин строится весь граф
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

void SaveTimeDrawingDigraph() {
    ofstream out("drawingDigraph.txt");
    for (int i = 1; i < 100; ++i) {
        Graph g(0);
        g.Generate(i, -1, 0);
        auto timeStamp_1 = std::chrono::high_resolution_clock::now();
        g.DrawInFile();
        auto timeStamp_2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeStamp_2 - timeStamp_1).count();
        out << duration << endl;
    }
    out.close();
}

#endif // TESTS_H

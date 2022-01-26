#include "graph.h"

Graph::Graph(vector<vector<double>> matrix) {          // построение графа по матрице смежности, любое ненулевое значение - ребро
    MakeGraphFromMatrix(matrix);
}

void Graph::MakeGraphFromMatrix(vector<vector<double>> matrix) {          // построение графа по матрице смежности, любое ненулевое значение - ребро
    _mode = 0;                                  // (зануление, чтобы не было дубликтатов ребер, т. к. добавление ребра будет при каждом проходе цикла)
    _graph.clear();
    for (int i = 0; i < matrix.size(); ++i) {
        AddVertex();
    }
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j)

            if (matrix.at(i).at(j) != 0) {
                AddArc(GetVertex(i), GetVertex(j), matrix.at(i).at(j));
            }
    }
    _mode = true;                                 // проверка на орграф, checker показывает было ли несоответствие в графе
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = i + 1; j < matrix.size(); ++j)
            if (matrix.at(i).at(j) != matrix.at(j).at(i)) {
                _mode = false;
                break;
            }
    }
}

void Graph::AddVertex(Node *node) {
    if (!node) node = new Node;
    node->id = _graph.size();
    _graph.push_back(node);
}

void Graph::AddArc(Node *start, Node *end, double value) {
    Arc* new_arc1 = new Arc(start, end, value);
    start->AddOutboundArc(new_arc1);
    if (_mode) {
        Arc* new_arc2 = new Arc(end, start, value);
        end->AddOutboundArc(new_arc2);
    }
}

Node *Graph::GetVertex(int i) {
    return _graph.at(i);
}

/*
vector<vector<bool> > Graph::GetMatrix() {      // получение матрицы смежности
    vector<vector<bool>> matrix;
    for (auto node : _graph) {
        vector<bool> current_line(_graph.size());
        for (int i = 0; i < _graph.size(); ++i) current_line.at(i) = 0;
        for (auto arc : node->_outboundArcs) {
            current_line.at(arc->_end->id) = 1;
        }
        matrix.push_back(current_line);
    }
    return matrix;
}
*/

vector<vector<double>> Graph::GetMatrix() {      // получение матрицы смежности, если между вершинами есть ребро, то указывается его вес
    vector<vector<double>> matrix;
    for (auto node : _graph) {
        vector<double> current_line(_graph.size());
        for (int i = 0; i < _graph.size(); ++i) current_line.at(i) = 0;
        for (auto arc : node->_outboundArcs) {
            current_line.at(arc->_end->id) = arc->_value;
        }
        matrix.push_back(current_line);
    }
    return matrix;
}

void Graph::DrawInFile(const string& output, const string& name_of_graph) {    // сохранение рисунка графа в output файл
    string graphiz = R"(..\Graphviz\bin\dot graph.dot -Tpng -o)" + output;
    ofstream out("graph.dot");
    if (_mode) out << "graph " + name_of_graph + " {\n";
    else out << "digraph " + name_of_graph + " {\n";
    for (auto node : _graph) {      // избыточное описание, на случай если есть несколько КСС
        out << node->id << ";\n";
    }
    for (auto node : _graph) {
        for (auto arc : node->_outboundArcs) {
            if (_mode && arc->_start > arc->_end) continue;
            out << arc->_start->id;
            if (_mode) out << " -- ";
            else out << " -> ";
            out << arc->_end->id << " [label=" << arc->_value << "];\n";
        }
    }
    out << "}";
    out.close();

    system(graphiz.c_str());
}

void Graph::DrawInFilePath(string output, string name_of_graph, vector<Node*> path) {    // сохранение рисунка графа в output файл
    string graphiz = "..\\Graphviz\\bin\\dot graph.dot -Tpng -o" + output;
    ofstream out("graph.dot");
    if (_mode) out << "graph " + name_of_graph + " {\n";
    else out << "digraph " + name_of_graph + " {\n";
    for (auto node : _graph) {      // избыточное описание, на случай если есть несколько КСС
        out << node->id;
        for (auto extra_node : path) {      // избыточное описание, на случай если есть несколько КСС
            if (extra_node == node)
                out << " [color=red]";
        }
        out << ";\n";
    }

    for (auto node : _graph) {
        for (auto arc : node->_outboundArcs) {
            if (_mode && arc->_start > arc->_end) continue;
            out << arc->_start->id;
            if (_mode) out << " -- ";
            else out << " -> ";
            out << arc->_end->id << " [label=" << arc->_value;
            for (int i = 0; i < path.size() - 1; ++i)
                if ((i + 1 < path.size() && path.at(i) == arc->_start && path.at(i + 1) == arc->_end)
                        || (_mode && i + 1 < path.size() && path.at(i) == arc->_end && path.at(i + 1) == arc->_start)) {
                    out << " color=red";
                    ++i;
            }
            out << "];\n";
        }
    }
    out << "}";
    out.close();

    system(graphiz.c_str());
}

void relax(Node *vertex, vector<pair<double, Node*>> &dist) {    // обновление минимальных расстояний
    for (auto arc : vertex->_outboundArcs) {
        if (dist[arc->_end->id].first > dist[vertex->id].first + arc->_value)
            dist[arc->_end->id] = { dist[vertex->id].first + arc->_value, vertex };
    }
}

int findIndexofMinDist(vector<pair<double, Node*>> &dist, vector<bool> &color) {   // поиск уже посещенной вершины с минимальным расстоянием
    double INF = 1e10;
    int min_node_index = -1;
    double min_dist = INF;
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i].first < min_dist && !color[i]) {
            min_dist = dist[i].first;
            min_node_index = i;
        }
    }
    return min_node_index;
}

pair<double, vector<Node *> > Graph::SearchBestPath(Node *start, Node *end) {
    double INF = 1e10;
    vector<pair<double, Node*>> dist(_graph.size());    // расстояние от start до i-ой
    vector<bool> color(_graph.size());                  // false - вершину i еще не посетили
                                                        // true - минимальное расстояние до нее уже было найдено
    for (auto node : _graph) {                          // инициализация
        dist[node->id] = { INF, nullptr };
        color[node->id] = false;
    }
    dist[start->id] = { 0, nullptr };

    int x;                                              // поиск кратчайших расстояний
    while((x = findIndexofMinDist(dist, color)) != -1) {
        color[x] = true;
        relax(GetVertex(x), dist);
    }

    vector<Node*> path;
    Node *current_node = end;
    while(current_node != nullptr) {
        path.push_back(current_node);
        current_node = dist.at(current_node->id).second;
    }
    if (path.size() == 1) path.push_back(start);
    reverse(path.begin(), path.end());
    return { dist.at(end->id).first, path };
}

pair<double, vector<Node *> > Graph::SearchBestPathThroughput(Node *start, Node *end) {
    if (abs(SearchBestPath(start, end).first - 1e10) < 1e3) return { -1, vector<Node *>() };  // пути между вершинами нет
    vector<Arc*> sorted_arcs;       // отсортированные в порядке убывания ребра
    for (auto node : _graph) {
        for (auto arc : node->_outboundArcs) {
            if (_mode && arc->_start->id > arc->_end->id) continue;
            sorted_arcs.push_back(arc);
            int i = sorted_arcs.size() - 2;
            while (i >= 0 && sorted_arcs[i]->_value < sorted_arcs[i + 1]->_value) {
                swap(sorted_arcs[i], sorted_arcs[i + 1]);
                --i;
            }
        }
    }

    Graph max_arcs(_graph.size(), _mode);                 // граф, содержащий первые n наибольших ребер
    bool checker = false;
    vector<Node *> best_path;
    double throughput;
    int i = 0;
    while (!checker) {
        Arc* max_arc = sorted_arcs[i];
        max_arcs.AddArc(max_arcs.GetVertex(max_arc->_start->id), max_arcs.GetVertex(max_arc->_end->id), max_arc->_value);
        pair<double, vector<Node *>> current_path = max_arcs.SearchBestPath(start, end);
        if (abs(current_path.first - 1e10) > 1e3) {
            checker = true;
            best_path = current_path.second;
            throughput = max_arc->_value;
        }
        ++i;
    }
    vector<Node *> best_path_in_old_graph;
    for (auto node : best_path) {
        best_path_in_old_graph.push_back(GetVertex(node->id));
    }
    return { throughput, best_path_in_old_graph };
}

void Graph::Generate(int n, int m, bool mode) {
    srand(time(NULL));
    _mode = mode;
    for (int i = 0; i < n; ++i)
        AddVertex();
    if (n == 1) m = 0;
    if (m == -1) {
        if (mode) m = rand() % (max(1, n * (n - 1) / 2)) + 1;
        else m = rand() % (max(1, n * (n - 1))) + 1;
    }

    vector<vector<double>> matrix = GetMatrix();
    for (int i = 0; i < m; ++i) {
        int begin = rand() % n;
        int end = rand() % n;
        if (begin != end && matrix[begin][end] == 0) {
            double dist = rand() % 10 + 1;
            matrix[begin][end] = dist;
            if (mode) matrix[end][begin] = dist;
        }
        else --i;
    }
    MakeGraphFromMatrix(matrix);
}

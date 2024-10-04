#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
public:
    int V;
    list<int>* l;
    bool isDir = false;

    Graph(int V, bool isDir=false){
        this->V = V;
        l = new list<int> [V];
        this->isDir = isDir;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (!isDir){
            l[v].push_back(u);
        }
        
    }

    void print() {
        for (int i=0; i<V; i++) {
            list<int> neibours = l[i];
            cout << i << " : ";
            for (int v : neibours) {
                cout << v << " ";
            }
            
            cout << endl;
        }
    }

    void pathHelper(int src, int des, vector<bool> &vis, string &path) {
        
        

        if (src==des) {
            path += to_string(src);
            cout << path << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);


        list<int> neibours = l[src];
        for (int v: neibours) {
            if (!vis[v]) {
                pathHelper(v, des, vis, path);
            }
        }

        vis[src] = false;
        path = path.substr(0, path.size()-1);
        
    }

    void printAllPaths(int src, int des) {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, des, vis, path);
    }
    
};

int main() {
    Graph graph(7, true);

    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);


    graph.printAllPaths(5,1);
}
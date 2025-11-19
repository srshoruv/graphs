#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
public:
    int V;
    list<int>* l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
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

    bool cycleDetectHelper(int src, int par, vector<bool> &vis) {
        vis[src] = true;
        list<int> neibours = l[src];

        for (int v: neibours) {
            if (!vis[v]) {
                if (cycleDetectHelper(v,src,vis)) {
                    return true;
                }
            } else {
                if ( v != par) {
                    return true;
                }
            }
        }

        return false;
    }

    bool cycleDetect(){
        vector<bool> vis(V, false);
        return cycleDetectHelper(0,-1,vis);
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);

    cout << graph.cycleDetect();
}
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

    bool dirCycleDetectHelper (int src, vector<bool> &vis, vector<bool> &recPath) {
        vis[src] = true;
        recPath[src] = true;

        list<int> neibours = l[src];
        for (int v : neibours) {
            if(!vis[v]) {
                if(dirCycleDetectHelper(v,vis,recPath)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool dirCycleDetect(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V,false);

        for (int i=0; i<V; i++) {
            if(!vis[i]) {
                if (dirCycleDetectHelper(i,vis,recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph graph(4, true);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(3,0);

    cout << graph.dirCycleDetect();
}
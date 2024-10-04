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

    bool isBipatite() {
        queue<int> q;
        vector<int> color(V, -1);
        q.push(0);
        color[0] = 0;

        while (q.size() > 0) {
            int curr = q.front();
            q.pop();

            list<int> neibours = l[curr];
            for (int v: neibours) {
                if (color[v]==-1) {
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if (color[v]==color[curr]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(0,3);

    cout << graph.isBipatite();
}
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

    void bfs() {
        queue <int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neibours = l[u];
            for (int v : neibours) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;


    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    graph.bfs();
}
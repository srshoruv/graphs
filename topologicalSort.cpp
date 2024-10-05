#include <iostream>
#include <vector>
#include <list>
#include <stack>
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

    void topSortHelper(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;
        list<int> neibours = l[src];
        for (int v: neibours) {
            if(!vis[v]){
                topSortHelper(v,vis,s);
        }
        }

        s.push(src);
    }

    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                topSortHelper(i, vis, s);
            }
        }

        while(s.size() > 0) {
        cout << s.top() << " ";
        s.pop();
    } 
    cout << endl;
    }
    
};

int main() {
    Graph graph(6, true);

    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);


    graph.topoSort();
}
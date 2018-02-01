#include<iostream>
#include <list>
#include <stack>
using namespace std;
 
// This class represents a directed graph using adjacency list 
// representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool *vsd;  //visited for DFS
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool isReachable_BFS(int s, int d); 
    bool isReachable_DFS(int s, int d); 
    bool isReachable_DFSs(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    vsd = new bool[V];
    for (int i = 0; i < V; i++)vsd[i]=false;
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable_BFS(int s, int d)
{
    // Base case
    if (s == d)
      return true;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    cout << "s= " << s << endl;
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            cout << *i << endl;
            // If this adjacent node is the destination node, then 
            // return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
     
    // If BFS is complete without visiting d
    return false;
}

bool Graph::isReachable_DFS(int s, int d)
{
    cout << s << endl;
    if (s == d)return true;

    vsd[s] = true;

    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i){
        if (!vsd[*i]){
            vsd[*i]=true;
            if(isReachable_DFS(*i,d))return true;
        }
    }

    return false;
}

bool Graph::isReachable_DFSs(int s, int d)
{
    if (s == d)return true;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)visited[i] = false;

    stack<int> st;
    cout << "s= " << s << endl;
    visited[s] = true;
    st.push(s);

    list<int>::iterator i;
    while(!st.empty()){
        s=st.top();
        st.pop();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            cout << *i << endl;
            if (*i == d)
                return true;
            if (!visited[*i])
            {
                visited[*i] = true;
                st.push(*i);
            }
        }
    }


    return false;
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    // g.addEdge(0, 3);

    cout << "BFS" << endl; 
    int u = 0, v = 3;
    if(g.isReachable_BFS(u, v))
        cout<< "There is a path from " << u << " to " << v << endl;
    else
        cout<< "There is no path from " << u << " to " << v << endl;;

    cout << "\nDFSs" << endl;
    if(g.isReachable_DFSs(u, v))
        cout<< "There is a path from " << u << " to " << v << endl;
    else
        cout<< "\nThere is no path from " << u << " to " << v << endl;

    cout << "\nDFS" << endl;
    if(g.isReachable_DFS(u, v))
        cout<< "There is a path from " << u << " to " << v << endl;
    else
        cout<< "\nThere is no path from " << u << " to " << v << endl;
 
    /*u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v << endl;
    else
        cout<< "\n There is no path from " << u << " to " << v << endl;
    */ 

    return 0;
}


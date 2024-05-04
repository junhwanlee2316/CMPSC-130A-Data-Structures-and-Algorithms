#include<bits/stdc++.h>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int arr[100000];    //skepticism array

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;  
public:
    Graph(int V);  // Constructor

 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    int BFS(int s, int d, int v); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
int Graph::BFS(int s, int d, int m)
{   
    int dayCount[100000];

    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);
 
    // Create a queue for BFS
    queue<int> queue;

    visited[s] = true;
    queue.push(s);
    
    int num = 0;
    int i = 0;
    arr[s] = 0;
    dayCount[0] = 0;
    while(!queue.empty()) 
    {   
        // arr = skepticism array
        s = queue.front();
        queue.pop();

        if(dayCount[s] < d){
        if(arr[s] <= 0){
            for (auto adjecent: adj[s])
                {
                    arr[adjecent] = arr[adjecent] - 1;  //skpeticism decrements for adjacent nodes
                    if(!visited[adjecent]){
                        num++;
                        visited[adjecent] = true;
                    }

                    if(arr[adjecent] == 0){
                        dayCount[adjecent] = dayCount[s] + 1;
                        queue.push(adjecent);
                    }
                }
            }
        }
    }

    return num;
}
 

int main()
{
    std::ios::sync_with_stdio(false);

    long int n,m,d,s;
    cin >> n >> m>> d;

    //unordered_map<int,int> v;
    unordered_map<string,int> name;
    string nm;
    int i;


    for(i = 0; i < n; i++){
        cin >> nm >> s;
        name.insert(pair<string,int>(nm,i));    // key = name of ppl, value = vertex number
        //v.insert(pair<int,int>(i,s));   //key = vertex number, value = skepticism
        arr[i] = s;
    }

    string t1,t2;
    Graph g(n);

    for(int i = 0; i < m; i++){
        cin >> t1 >> t2;
        auto it1 = name.find(t1);
        auto it2 = name.find(t2);
        g.addEdge(it1->second,it2->second);
        g.addEdge(it2->second,it1->second);
    }

    cin >> nm;
    int start_v = name.find(nm)->second;
    

    int num = g.BFS(start_v,d,m);

    cout << num <<endl;


    return 0;
}

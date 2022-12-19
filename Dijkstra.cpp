#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <limits>
using namespace std;

struct Node {
	 int dest;
	 int cost;
   friend std::ostream &operator<<(std::ostream &os, const Node &n) { 
       return os << "{" << n.dest << "," << n.cost << "}";
   }
};

class Graph {
private:
	int numVertices;
	list<Node>* adjList;
public:
	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjList = new list<Node>[numVertices];
	}
	~Graph(){
		delete [] adjList;
	}

	void printGraph() const{
		list<Node>::iterator j;
		cout << "Vertices\n";
		for (int i = 0; i < numVertices; i++){
			cout << i << " -->\t";
			if (!adjList[i].empty()){
				for (j = adjList[i].begin(); j != adjList[i].end(); j++){
					cout << *j << " ";
				}
			}
			else{
				cout << "NULL";
			}
			cout << endl;
		}
	}

	void addEdge(int source, int dest, int cost) {
		Node newNode;
		newNode.dest = dest;
		newNode.cost = cost;
		adjList[source].push_back(newNode);
	}

	void dijkstra(const int start){

		int* dist = new int[numVertices];
		int* prev = new int[numVertices];

		for(int u = 0; u < numVertices; u++) {
			dist[u] = std::numeric_limits<int>::max();   
			prev[u] = -1;    
		}

		dist[start] = 0;   
		set<int> S;       
		list<int> Q;

		for(int u = 0; u < numVertices; u++) {
			Q.push_back(u);    
		}

		while(!Q.empty()) {
			list<int> :: iterator i;
			i = min_element(Q.begin(), Q.end());
			int u = *i; 
			Q.remove(u);
			S.insert(u); 
			list<Node> :: iterator it;
			for(it = adjList[u].begin(); it != adjList[u].end();it++) {
				if((dist[u]+(it->cost)) < dist[it->dest]) {
					dist[it->dest] = (dist[u]+(it->cost));
					prev[it->dest] = u;
				}
			}
		}

		for(int i = 0; i < numVertices; i++){
			if(i != start){
				cout<<start<<" a "<<i<<", Cuesta: "<<dist[i]<<" Vertice Anterior: "<<prev[i]<<endl;
			}
		}
		delete [] prev, dist;
	}
};

int main()
{
	Graph mygraph(6);

	mygraph.addEdge(0, 2, 5);
	mygraph.addEdge(0, 1, 3);
	mygraph.addEdge(1, 3, 1);
	mygraph.addEdge(1, 4, 2);
	mygraph.addEdge(2, 4, 3);
	mygraph.addEdge(2, 5, 4);
	mygraph.addEdge(3, 6, 2);
	mygraph.addEdge(4, 5, 2);

	mygraph.printGraph();

	cout << "Dijkstra" << endl;
	mygraph.dijkstra(0);

	return 0;
}

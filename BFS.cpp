#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
private:
	int numVertices; //Numero de Vertices
	list<int>* adjLists; //Lista de Adjasencia

public:
	Graph(int numVertices){
		this->numVertices = numVertices;
		adjLists = new list<int>[numVertices];
	} 
	~Graph(){
		delete [] adjLists;
	}

	void addEdge(int v, int w){
		adjLists[v].push_back(w);
	}

	void printGraph() const{
		list<int>::iterator j;
		for (int i = 0; i < numVertices; i++){
			cout << i << " -->\t";
			if (!adjLists[i].empty()){
				for (j = adjLists[i].begin(); j != adjLists[i].end(); j++){
					cout << "{" << *j << "}" << " ";
				}
			}
			else{
				cout << "NULL";
			}
			cout << endl;
		}
	}

	void BFS(int s){
		vector<bool> visited;
		visited.resize(numVertices,false);

		queue<int> queue;

		visited[s] = true;
		queue.push(s);

		cout << "Breadth First Traversal: starting from vertex " << s << endl;
		while(!queue.empty()){

			s = queue.front();

			cout << s << " ";

			queue.pop();

			for (const auto& adjecent: adjLists[s]){
				if (!visited[adjecent]){
					visited[adjecent] = true;
					queue.push(adjecent);
				}
			}
		}
	}
};
int main()
{
	Graph mygraph(6);

	mygraph.addEdge(0, 3);
	mygraph.addEdge(0, 5);
	mygraph.addEdge(3, 3);
	mygraph.addEdge(3, 2);
	mygraph.addEdge(5, 1);
	mygraph.addEdge(1, 6);
	mygraph.addEdge(4, 4);
	mygraph.addEdge(4, 4);

	mygraph.printGraph();
  cout << "BFS" << endl;
  
  mygraph.BFS(3);


	return 0;
}

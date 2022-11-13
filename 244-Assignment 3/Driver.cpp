#include<iostream>
#include"Vertex.h"
#include"Graph.h"
#include<string>
#include"Edge.h"
#include"Directed.h"

using namespace std;

int main() {

	//Problem 1 demo
	Vertex v1("1");
	Vertex v2("2");
	Vertex v3("3");
	Vertex v4("4");
	Vertex v5("5");
	Vertex v6("6");

	Edge e1(v1,v2);
	Edge e2(v2,v3);
	Edge e3(v3,v1);
	Edge e4(v1,v5);
	Edge e5(v5,v1);
	Edge e6(v1,v4);
	Edge e7(v5,v2);
	Edge e8(v6,v3);

	Directed dirgraph1(5,7);

	dirgraph1.addVertex(v1);
	dirgraph1.addVertex(v2);
	dirgraph1.addVertex(v3);
	dirgraph1.addVertex(v4);
	dirgraph1.addVertex(v5);

	dirgraph1.addEdge(e1);
	dirgraph1.addEdge(e2);
	dirgraph1.addEdge(e3);
	dirgraph1.addEdge(e4);
	dirgraph1.addEdge(e5);
	dirgraph1.addEdge(e6);
	dirgraph1.addEdge(e7);


	dirgraph1.toString();

	Vertex *vArray = new Vertex [3];

	vArray[0] = v1;
	vArray[1] = v2;
	vArray[2] = v3;

	Directed dirgraph2(3,3);

	dirgraph2.addVertices(vArray);

	dirgraph2.addEdge(e1);
	dirgraph2.addEdge(e2);
	dirgraph2.addEdge(e3);

	dirgraph2.toString();

	if (dirgraph2.removeEdge(e2) == 1)
	cout << "Edge Successfully removed" << endl <<endl;
	else
		cout << "Edge remove failed" << endl << endl;

	dirgraph2.toString();

	if (dirgraph2.removeVertex(v2) == 1)
		cout << "Vertex Successfully removed" << endl <<endl;
		else
			cout << "Vertex remove failed" << endl << endl;

	dirgraph2.toString();

	Graph *graph1 = &dirgraph1;

	if (graph1->searchVertex(v3) == 1)
		cout << "Vertex found in the database" << endl <<endl;
	else
		cout << "Vertex not in the database" << endl << endl;

	if (graph1->searchEdge(e8) == 1)
		cout << "Edge found in the database" << endl <<endl;
	else
		cout << "Edge not in the database" << endl << endl;

// Problem 2 Demo
	Directed dirgraph3;

	dirgraph3 = dirgraph1 + dirgraph2;

	dirgraph3.toString();


	if (dirgraph2 == dirgraph1)
		cout << "They have the exact same vertices and edges" << endl << endl;
	else
		cout << "They are not the same graph" << endl << endl;

	cout << "Number of edges in Graph 3: "<<dirgraph3.getEdgeCounter() <<endl << endl;
	dirgraph3++;
	++dirgraph3;
	cout << "Number of edges in Graph 3 after pre and post increment: "<<dirgraph3.getEdgeCounter() <<endl << endl;



	if (dirgraph2>dirgraph1)
		cout << "Graph 2 is bigger than graph 1" << endl << endl;
	else
		cout << "Graph 1 is bigger than graph 2" << endl << endl;


	if (graph1->clean() == 1){
		cout << "Graph cleaned successfully" << endl << endl;
	}
	else
		cout << "Graph clean unsuccessful" << endl << endl;


	return 0;

}

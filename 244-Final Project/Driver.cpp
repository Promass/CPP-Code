#include<iostream>
#include<string>
#include"Vertex.h"
#include"Graph.h"
#include"Edge.h"
#include"Directed.h"
#include"Undirected.h"

using namespace std;

int main() {

//----------------------------------------------------------------------------------------Directed Graph demo----------------------------------------------------------------------------------------

	cout << "=======================================Directed: First Family Tree Demo=======================================" << endl << endl;
	Vertex v1("Father");
	Vertex v2("Mother");
	Vertex v3("Child1");
	Vertex v4("Child2");
	Vertex v5("Grandchild1");

	Edge e1(v1,v3);
	Edge e2(v1,v4);
	Edge e3(v2,v3);
	Edge e4(v2,v4);
	Edge e5(v3,v5);

	Graph *dir_graph_1 = new Directed (5,5);

	dir_graph_1->addVertex(v1);
	dir_graph_1->addVertex(v2);
	dir_graph_1->addVertex(v3);
	dir_graph_1->addVertex(v4);
	dir_graph_1->addVertex(v5);


	dir_graph_1->addEdge(e1);
	dir_graph_1->addEdge(e2);
	dir_graph_1->addEdge(e3);
	dir_graph_1->addEdge(e4);
	dir_graph_1->addEdge(e5);

	dir_graph_1->toString();

	cout << "===========================================" << endl;
	cout << "            All Possible Paths" << endl;
	cout << "===========================================" << endl;

	dir_graph_1->path(v1);

	cout << endl;

	if (dir_graph_1->removeVertex(v4) == 1)
		cout << v4.getVertex() << " removed from the family tree" << endl<< endl;
	else
		cout << v4.getVertex() << " is not in the family tree" << endl<< endl;

	dir_graph_1->toString();

	if (dir_graph_1->removeEdge(e5) == 1)
			cout << "Link between " << e5.getEdgeStart().getVertex() << " and " << e5.getEdgeEnd().getVertex() << " destroyed successfully" <<endl<< endl;
		else
			cout << "Could not destroy link between " << e5.getEdgeStart().getVertex() << " and " << e5.getEdgeEnd().getVertex() << endl<< endl;

	dir_graph_1->toString();



	cout << "=======================================Directed: Second Family Tree Demo=======================================" << endl << endl;
	Vertex varray[5];
	varray[0].setVertex("Grand Dad");
	varray[1].setVertex("Dad");
	varray[2].setVertex("Mom");
	varray[3].setVertex("Son");
	varray[4].setVertex("Daughter");

	Edge e11(varray[0],varray[1]); // Dad is a descendant of Grand Dad
	Edge e22(varray[1],varray[3]); // Son is a descendant of Dad
	Edge e33(varray[1],varray[4]); // Daughter is a descendant of Dad
	Edge e44(varray[2],varray[3]); // Son is a descendant of Mom
	Edge e55(varray[2],varray[4]); // Daughter is a descendant of Mom

// Since Mom is not a descendant of Dad nor Grand Dad they are not connected

	Directed dir_graph_2(5,5);

	dir_graph_2.addVertices(varray, 5);

	dir_graph_2.addEdge(e11);
	dir_graph_2.addEdge(e22);
	dir_graph_2.addEdge(e33);
	dir_graph_2.addEdge(e44);
	dir_graph_2.addEdge(e55);

	dir_graph_2.toString();

	cout << "===========================================" << endl;
	cout << "            All Possible Paths" << endl;
	cout << "===========================================" << endl;

	dir_graph_2.path(varray[0]);

	cout << endl;

	if (dir_graph_2.searchVertex(varray[2]) == 1)
		cout << varray[2].getVertex() << " found in this family tree" << endl << endl;
	else
		cout << varray[2].getVertex() << " not found in this family tree" << endl << endl;

	if (dir_graph_2.searchEdge(e55) == 1)
		cout << "There is a link between " << e55.getEdgeStart().getVertex() << " and " << e55.getEdgeEnd().getVertex() << " in this family tree" << endl << endl;
	else
		cout << "There is no link between " << e55.getEdgeStart().getVertex() << " and " << e55.getEdgeEnd().getVertex() << " in this family tree" << endl << endl;

//----------------------------------------------------------------------------------------Undirected Graph Demo----------------------------------------------------------------------------------------
	cout << "=======================================Undirected: Social Connections Demo=======================================" << endl << endl;
	Vertex v6("Ains");
	Vertex v7("Alice");
	Vertex v8("Leo");
	Vertex v9("Max");
	Vertex v11("Joe");

	Edge e7(v6,v8); // Ains knows Leo, vice-versa
	Edge e8(v7,v9); // Alice knows Max, vice-versa
	Edge e9(v9,v6); // Max knows Ains, vice-versa

	Undirected undirgraph(5,3);

	undirgraph.addVertex(v6);
	undirgraph.addVertex(v7);
	undirgraph.addVertex(v8);
	undirgraph.addVertex(v9);
	undirgraph.addVertex(v11);

	undirgraph.addEdge(e7);
	undirgraph.addEdge(e8);
	undirgraph.addEdge(e9);

	undirgraph.toString();

	cout << "===========================================" << endl;
	cout << "            All Possible Paths" << endl;
	cout << "===========================================" << endl;
	undirgraph.path(v9);


	return 0;
}


#include <iostream>
#include "Grafo.hpp"

using namespace std;
int main()
{
    CGrafo<int>* G = new CGrafo<int>();

	G->adicionarVertice(2);
	G->adicionarVertice(15);
	G->adicionarVertice(30);
	G->adicionarVertice(7);

	G->adicionarArco(0, 1);
	G->adicionarArco(0, 3);
	G->adicionarArco(1, 2);
	G->adicionarArco(2, 0);

	for (int i = 0; i < G->cantidadVertices(); i++){
		cout << "Vertice: " << G->obtenerVertice(i) << ", ID: " << i << endl;
		for (int j = 0; j < G->cantidadArcos(i); j++)
		{
			cout << "Arco: " << G->obtenerArco(i, j) << ", VERTICE: " << G->obtenerVerticeLlegada(i,j) << endl;
		}
		cout << endl;
	}


    cin.get();
    return 0;
}

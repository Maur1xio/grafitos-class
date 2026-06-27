#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
using namespace std;

template<class T>
class CGrafo {
private:
	class CArco {
	public:
		T info;
		int v; //indice del vertice de llegada
		CArco(int vLlegada) {
			info = T();
			v = vLlegada;
		}
	};
	class CVertice {
	public:
		T info;
		vector<CArco*>* ady; //Lista de adyacencia
		CVertice() {
			info = T();
			ady = new vector<CArco*>();
		}
	};
	//Lista de vértices
	vector<CVertice*>* vertices;

public:
	CGrafo() {
		vertices = new vector<CVertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		CVertice* vert = new CVertice();
		vert->info = info;
		vertices->push_back(vert);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int v) {
		return (vertices->at(v))->info;
	}
	void modificarVertice(int v, T info) {
		(vertices->at(v))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int v, int vLlegada) {
		CVertice* ver = vertices->at(v);
		//Crear el objeto ARCO
		CArco* arc = new CArco(vLlegada);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1;
	}

	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	T obtenerArco(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, T info) {
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	T obtenerVerticeLlegada(int v, int apos) {
		CVertice* ver = vertices->at(v);
		int vi = (ver->ady->at(apos))->v;
		CVertice* ver2 = vertices->at(vi);
		return ver2->info; //indice del vertice de llegada
	}

};

#endif // !__GRAFO_HPP__


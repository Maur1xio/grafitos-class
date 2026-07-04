#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
#include <string>

using namespace std;

template<class TVertice, class TArco>
class CGrafo {
private:
	class CArco {
	public:
		TArco info; 
		int v;

		CArco(int vLlegada, TArco peso = TArco()) {
			info = peso;
			v = vLlegada;
		}
	};

	class CVertice {
	public:
		TVertice info;
		vector<CArco*>* ady;

		CVertice() {
			info = TVertice();
			ady = new vector<CArco*>();
		}
	};
	vector<CVertice*>* vertices;

public:
	CGrafo() {
		vertices = new vector<CVertice*>();
	}

	int adicionarVertice(TVertice info) {
		CVertice* vert = new CVertice();
		vert->info = info;
		vertices->push_back(vert);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	TVertice obtenerVertice(int v) {
		return (vertices->at(v))->info;
	}

	void modificarVertice(int v, TVertice info) {
		(vertices->at(v))->info = info;
	}

	int adicionarArco(int v, int vLlegada, TArco peso) {
		CVertice* ver = vertices->at(v);
		CArco* arc = new CArco(vLlegada, peso);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1;
	}

	int adicionarArco(int v, int vLlegada) {
		CVertice* ver = vertices->at(v);
		CArco* arc = new CArco(vLlegada);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1;
	}

	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	TArco obtenerArco(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, TArco info) {
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	TVertice obtenerVerticeLlegada(int v, int apos) {
		CVertice* ver = vertices->at(v);
		int vi = (ver->ady->at(apos))->v;
		CVertice* ver2 = vertices->at(vi);
		return ver2->info;
	}
};

#endif // !__GRAFO_HPP__
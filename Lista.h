#include <string>
#include <iostream>
using namespace std;
/*
	Lists
	Lista Class by Luis Felipe Alvarez Sanchez
	A01194173
	27 Aug 2018
*/
template <class T>
class Lista {
	public:
		Lista();
		Lista(Lista &list);
		~Lista();
		int getCant();
		T getDato(int index);
		bool add(T dato);
		int search(T dato);
		void print();
		void sort(bool orden);
		void swap(T *a, T *b);
		//Operator == done
		friend bool operator==(Lista l1, Lista l2) {
			int i;
			if (l1.getCant() != l2.getCant()) {
				return false;
			}
			else {
				for (i = 0; i < l1.getCant(); i++) {
					if (l1.arrDatos[i] != l2.arrDatos[i]) {
						return false;
					}
				}
			}
			return true;
		}
		//Operator = done
		void operator=(Lista list) {
			int i;
			for (i = 0; i < list.getCant(); i++) {
				this->arrDatos[i] = list.arrDatos[i];
			}
			this->iCant = list.getCant();
		}
	private:
		T arrDatos[10];
		int iCant;
};
/*Constructor*/
template<class T>
Lista<T>::Lista() {
	iCant = 0;
}
/*Copy constructor*/
template<class T>
Lista<T>::Lista(Lista &list) {
	int i;
	for (i = 0; i < list.getCant(); i++) {
		this->arrDatos[i] = list.arrDatos[i];
	}
	this->iCant = list.getCant();
}
/*Destructor*/
template<class T>
Lista<T>::~Lista() {}
/*add Method*/
template<class T>
bool Lista<T>::add(T dato) {
	if (iCant > 10) {
		return false;
	}
		arrDatos[iCant] = dato;
		iCant++;
		return true;
}
/*swap Method*/
template<class T>
void Lista<T>::swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}
/*sort Method*/
template<class T>
void Lista<T>::sort(bool orden) {
	int i, j;
	for (i = 0; i < iCant - 1; i++) {
		for (j = 0; j < iCant - i - 1; j++) {
			if (orden) {
				if (arrDatos[j] > arrDatos[j + 1]) {
					swap(&arrDatos[j], &arrDatos[j + 1]);
				}
			}else {
				if (arrDatos[j] < arrDatos[j + 1]) {
					swap(&arrDatos[j], &arrDatos[j + 1]);
				}
			}
			
		}
	}
}
/*getDato Method*/
template<class T>
T Lista<T>::getDato(int index) {
	return arrDatos[index];
}
/*print Method */
template<class T>
void Lista<T>::print() {
	int i;
	for (i = 0; i < iCant; i++) {
		cout << i << " - " << getDato(i) << "\n";
	}
}
/*search Method*/
template<class T>
int Lista<T>::search(T dato) {
	int index;
	for (index = 0; index < getCant(); index++) {
		if (dato == arrDatos[index]) {
			return index;
		}
	}
	return -1;
}
/*getCant Method*/
template<class T>
int Lista<T>::getCant() {
	return this->iCant;
}
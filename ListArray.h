#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;

		// Cambia el tamaño del array.
		void resize(int new_size) {
			T* aux = new T[new_size];

			for (int i = 0; i < n; i++) {
				aux[i] = arr[i];
			}

			delete[] arr;
			arr = aux;
			max = new_size;
		}

	public:
		// Crea una lista vacía.
		ListArray() {
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}

		// Libera la memoria.
		~ListArray() override {
			delete[] arr;
		}

		// Devuelve el tamaño.
		int size() override {
			return n;
		}

		// Comprueba si está vacía.
		bool empty() override {
			return n == 0;
		}

		// Inserta un elemento.
		void insert(int pos, T e) override {
			if (pos < 0 || pos > n) {
				throw std::out_of_range("Posición inválida!");
			}

			if (n == max) {
				resize(max * 2);
			}

			for (int i = n; i > pos; i--) {
				arr[i] = arr [i - 1];
			}

			arr[pos] = e;
			n++;		
		}

		// Añade al final.
		void append(T e) override {
			insert(n, e);
		}

		// Añade al principio.
		void prepend(T e) override {
			insert(0, e);
		}

		// Obtiene un elemento.
		T get(int pos) override {
			if (pos < 0 || pos >= n) {
				throw std::out_of_range("Posición inválida!");
			}

			return arr[pos];
		}
		
		// Acceso mediante corchetes.
		T operator[](int pos) {
			return get(pos);
		}

		// Busca un elemento.
		int search(T e) override {
			for (int i = 0; i < n; i++) {
				if (arr[i] == e) {
					return i;
				}
			}

			return - 1;
		}

		// Elimina un elemento.
		T remove(int pos) override {
			if (pos < 0 || pos >= n) {
				throw std::out_of_range("Posición inválida!");
			}

			T elem = arr[pos];

			for (int i = pos; i < n - 1; i++) {
				arr[i] = arr[i + 1];
			}

			n-- ;
			return elem;
		}

		// Muestra la lista.
		friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
			out << "List => [";
			if (list.n != 0) {
				out << "\n";
				
				for (int i = 0; i < list.n; i++) {
					out << " " << list.arr[i] << "\n";
				}
			}
			out << "]";
			return out;
		}
};

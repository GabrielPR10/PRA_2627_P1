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

		void resize(int new_size) {
			T* aux = new T[new_size];

			for (int i = 0; i < n; i++) {
				aux[i] = arr[i];
			}
			delete[] arr;
			arr = aux;max = new_size;
		}

	public:
		ListArray() {
			max = MINSIZE;
			n = 0;
			arr = new T[MINSIZE];
		}

		~ListArray() override {
			delete[] arr;
		}

		int size() const override {
			return n;
		}

		bool empty() const override {
			return n == 0;
		}

		void insert(int pos, T e) override {
			if (pos < 0 || pos > n) {
				throw std::out_of_range("Posicion invalida!");
			}
			if (n == max) {
				resize(max * 2);
			}
			for (int i = n; i > pos; i--) {
				arr[i] = arr [i - 1];
			}
			arr[pos] = 
			e;
			n++;		
		}

		void append(T e) override {
			insert(n, e);
		}

		void prepend(T e) override {
			insert(0, e);
		}

		T get(int pos) const override {
			if (pos < 0 || pos >= n) {
				throw std::out_of_range("Posicion invalida!");
			}
			return arr[pos];
		}
		
		T operator[](int pos) const {
			return get(pos);
		}

		int search(T e) const override {
			for (int i = 0; i < n; i++) {
				if (arr[i] == e) {
					return i;
				}
			}
			return - 1;
		}

		T remove(int pos) override {
			if (pos < 0 || pos >= n) {
				throw std::out_of_range("Posicion invalida!");
			}
			T elem = arr[pos];
for (int i = pos; i < n - 1; i++) {
				arr[i] = arr[i + 1];
			}
			n-- ;
			return elem;
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
			out << "List => [";
			if (!list.empty()) {
				out << "\n";
				for (int i = 0; i < list.n; i++) {
					out << " " << list.arr[i] << "\n";
				}
			}
			out << "]";
			return out;
		}
};

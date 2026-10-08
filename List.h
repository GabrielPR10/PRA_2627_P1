#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
	    // Destructor virtual.
	    virtual ~List() = default;

	    // Inserta en una posición.
	    virtual void insert(int pos, T e) = 0;

	    // Añade al final.
	    virtual void append(T e) = 0;

	    // Añade al principio.
	    virtual void prepend(T e) = 0;

	    // Elimina y devuelve un elemento.
	    virtual T remove(int pos) = 0;

	    // Devuelve un elemento.
	    virtual T get(int pos) = 0;

	    // Busca un elemento.
	    virtual int search(T e) = 0;

	    // Comprueba si está vacía.
	    virtual bool empty() = 0;

	    // Devuelve el número de elementos.
	    virtual int size() = 0;
};

#endif

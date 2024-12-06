#include <iostream>
using namespace std;

template <typename T>
class Coda {
private:
    struct nodo {
        T valore;
        nodo* next;
    };

    nodo* front; // Puntatore al primo elemento della coda
    nodo* rear;  // Puntatore all'ultimo elemento della coda
    int lenght;  // Lunghezza della coda

public:
    // Costruttore
    Coda() : front(NULL), rear(NULL), lenght(0) {}

    // Distruttore
    ~Coda() {
        while (front != NULL) {
            nodo* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue: aggiunge un elemento alla fine della coda
    void enqueue(T elem) {
        nodo* nuovo = new nodo{elem, NULL};

        if (isEmpty()) {
            front = rear = nuovo;
        } else {
            rear->next = nuovo;
            rear = nuovo;
        }

        lenght++;
    }

    // Dequeue: rimuove e restituisce l'elemento in testa alla coda
    T dequeue() {
        if (isEmpty()) {
            cout << "ERROR: coda vuota." << endl;
            return T();
        }

        nodo* temp = front;
        T valore = front->valore;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        lenght--;
        return valore;
    }

    // frontElem: restituisce l'elemento in testa alla coda senza rimuoverlo
    T frontElem() const {
        if (isEmpty()) {
            cout << "ERROR: coda vuota." << endl;
            return T();
        }
        return front->valore;
    }

    // isEmpty: verifica se la coda è vuota
    bool isEmpty() const {
        return lenght == 0;
    }

    // size: restituisce il numero di elementi nella coda
    int size() const {
        return lenght;
    }
};

int main() {
    Coda<int> coda;

    cout << "La coda è vuota? ----> " << (coda.isEmpty() ? "SÌ" : "NO") << endl;
    cout << "Dimensione della coda ----> " << coda.size() << endl;

    cout << "Aggiungo 27 alla coda." << endl;
    coda.enqueue(27);

    cout << "Aggiungo 34 alla coda." << endl;
    coda.enqueue(34);

    cout << "Aggiungo 69 alla coda." << endl;
    coda.enqueue(69);

    cout << "Elemento in testa alla coda ----> " << coda.frontElem() << endl;
    cout << "Dimensione della coda ----> " << coda.size() << endl;

    cout << "Tolgo dalla coda ----> " << coda.dequeue() << endl;
    cout << "Nuovo elemento in testa ----> " << coda.frontElem() << endl;
    cout << "Dimensione della coda ----> " << coda.size() << endl;

    cout << "Tolgo dalla coda ----> " << coda.dequeue() << endl;
    cout << "Tolgo dalla coda ----> " << coda.dequeue() << endl;

    cout << "La coda è vuota? ----> " << (coda.isEmpty() ? "SÌ" : "NO") << endl;
    cout << "Dimensione della coda ----> " << coda.size() << endl;

    return 0;
}

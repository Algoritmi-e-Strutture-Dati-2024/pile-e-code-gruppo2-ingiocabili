#include <iostream>
using namespace std;

template <typename T>
class Coda {
private:
    struct Nodo {
        T valore;       // Valore dell'elemento
        Nodo* next;     // Puntatore al prossimo nodo
    };

    Nodo* front;        // Puntatore all'inizio della coda
    Nodo* rear;         // Puntatore alla fine della coda
    int lenght;         // Numero di elementi nella coda

public:
    // Costruttore: inizializza una coda vuota
    Coda() : front(nullptr), rear(nullptr), lenght(0) {}

    // Distruttore: libera la memoria occupata dalla coda
    ~Coda() {
        while (front != nullptr) {
            Nodo* temp = front;
            front = front->next;
            delete temp;
        }
    }

    //--------------------------ENQUEUE-----------------------------------
    // Aggiunge un elemento alla fine della coda
    void enqueue(T elem) {
        Nodo* nuovo = new Nodo{elem, nullptr};

        if (isEmpty()) {
            front = rear = nuovo; // Se la coda è vuota, front e rear puntano al nuovo nodo
        } else {
            rear->next = nuovo;   // Collega il nuovo nodo alla fine della coda
            rear = nuovo;         // Aggiorna il puntatore rear
        }

        lenght++;
    }
    //------------------------------------------------------------------

    //--------------------------DEQUEUE-----------------------------------
    // Rimuove e restituisce l'elemento all'inizio della coda
    T dequeue() {
        if (isEmpty()) {
            cout << "ERROR: coda vuota." << endl;
            return T(); // Restituisce il valore predefinito del tipo T
        }

        Nodo* temp = front;         // Salva il nodo da eliminare
        T valore = front->valore;   // Ottiene il valore del nodo
        front = front->next;        // Aggiorna il puntatore front
        if (front == nullptr) {     // Se la coda è ora vuota
            rear = nullptr;
        }

        delete temp;                // Libera la memoria del nodo
        lenght--;
        return valore;
    }
    //------------------------------------------------------------------

    //--------------------------FRONT ELEM--------------------------------
    // Restituisce l'elemento all'inizio della coda senza rimuoverlo
    T frontElem() const {
        if (isEmpty()) {
            cout << "ERROR: coda vuota." << endl;
            return T(); // Restituisce il valore predefinito del tipo T
        }
        return front->valore;
    }
    //------------------------------------------------------------------

    //--------------------------IS EMPTY---------------------------------
    // Controlla se la coda è vuota
    bool isEmpty() const {
        return lenght == 0;
    }
    //------------------------------------------------------------------

    //-----------------------------SIZE----------------------------------
    // Restituisce il numero di elementi nella coda
    int size() const {
        return lenght;
    }
    //------------------------------------------------------------------
};

// Funzione principale per testare la classe Coda
int main() {
    Coda<int> coda;

    // Aggiunta di elementi alla coda
    coda.enqueue(5);
    coda.enqueue(10);
    coda.enqueue(15);

    // Mostra il primo elemento
    cout << "Primo elemento: " << coda.frontElem() << endl;
    cout << "Dimensione della coda: " << coda.size() << endl;

    // Rimozione di elementi dalla coda
    cout << "Rimosso: " << coda.dequeue() << endl;
    cout << "Primo elemento: " << coda.frontElem() << endl;
    cout << "Dimensione della coda: " << coda.size() << endl;

    // Svuotamento della coda
    while (!coda.isEmpty()) {
        cout << "Rimosso: " << coda.dequeue() << endl;
    }

    cout << "La coda è vuota? " << (coda.isEmpty() ? "Sì" : "No") << endl;

    return 0;
}

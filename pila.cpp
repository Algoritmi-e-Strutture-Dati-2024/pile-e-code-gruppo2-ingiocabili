#include <iostream>
using namespace std;

//-------------------------------------------------------
// Classe generica per la pila
template <typename T>
class Pila {
private:
    struct Nodo {
        T valore;     // Valore contenuto nel nodo
        Nodo* next;   // Puntatore al nodo successivo
    };

    Nodo* topPila;   // Puntatore al nodo in cima alla pila
    int lenght;      // Lunghezza della pila

public:
    //-------------------------------------------------------
    // Costruttore
    Pila() : topPila(NULL), lenght(0) {}

    // Distruttore
    ~Pila() {
        while (topPila != NULL) {
            Nodo* temp = topPila;
            topPila = topPila->next;
            delete temp;
        }
    }

    //---------------------PUSH---------------------------
    // Aggiunge un elemento in cima alla pila
    void push(T elem) {
        Nodo* nuovo = new Nodo{elem, topPila};
        topPila = nuovo;
        lenght++;
    }
    //-----------------------------------------------------

    //---------------------------POP--------------------
    // Rimuove e restituisce l'elemento in cima alla pila
    T pop() {
        if (isEmpty()) {
            cout << "ERROR: Pila vuota." << endl;
            return T();
        }

        Nodo* temp = topPila;
        T valore = topPila->valore;
        topPila = topPila->next;
        delete temp;
        lenght--;

        return valore;
    }
    //-------------------------------------------------------

    //---------------------TOP-----------------------------
    // Restituisce l'elemento in cima alla pila senza rimuoverlo
    T top() const {
        if (isEmpty()) {
            cout << "ERROR: Pila vuota." << endl;
            return T();
        }

        return topPila->valore;
    }
    //-------------------------------------------------------

    //--------------------IS EMPTY-----------------------------
    // Verifica se la pila è vuota
    bool isEmpty() const {
        return lenght == 0;
    }
    //-------------------------------------------------------

    //-------------------SIZE---------------------------
    // Restituisce il numero di elementi nella pila
    int size() const {
        return lenght;
    }
    //-------------------------------------------------------
};

int main() {
    Pila<int> pila;

    cout << "La pila è vuota? ---> " << (pila.isEmpty() ? "SÌ" : "NO") << endl;
    cout << "Dimensione della pila ---> " << pila.size() << endl;

    cout << "Aggiungo 27 alla pila." << endl;
    pila.push(27);

    cout << "Aggiungo 34 alla pila." << endl;
    pila.push(34);

    cout << "Aggiungo 69 alla pila." << endl;
    pila.push(69);

    cout << "Elemento in cima alla pila ---> " << pila.top() << endl;
    cout << "Dimensione della pila ---> " << pila.size() << endl;

    cout << "Tolgo dalla pila ---> " << pila.pop() << endl;
    cout << "Nuovo elemento in cima ---> " << pila.top() << endl;
    cout << "Dimensione della pila ---> " << pila.size() << endl;

    cout << "Tolgo dalla pila ---> " << pila.pop() << endl;
    cout << "Tolgo dalla pila ---> " << pila.pop() << endl;

    cout << "La pila è vuota? ---> " << (pila.isEmpty() ? "SÌ" : "NO") << endl;
    cout << "Dimensione della pila ---> " << pila.size() << endl;

    return 0;
}

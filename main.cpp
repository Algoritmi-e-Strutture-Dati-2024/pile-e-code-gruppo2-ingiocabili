#include <iostream>
using namespace std;

int main(){
    //test pila
    Pila<int> pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    cout << "Top della pila: " << pila.top() <<endl;
    cout << "Rimozione top: " << pila.pop() <<endl;
    cout << "Top della pila: " << pila.top() <<endl;
    cout << "La pila è vuota? " << (pila.isEmpty() ? "Sì" : "No") << endl; //usando l'operatore ternario
    cout << "Numero di elementi nella pila: " << pila.size() <<endl;

    //test coda
    Coda<int> coda;
    coda.enqueue(10);
    coda.enqueue(20);
    coda.enqueue(30);
    cout << "Front della coda: " << coda.front() <<endl;
    cout << "Rimozione front: " << coda.dequeue() <<endl;
    cout << "La coda è vuota? " << (coda.isEmpty() ? "Sì" : "No") <<endl;
    cout << "Numero di elementi nella coda: " << coda.size() <<endl;

  return 0;
}

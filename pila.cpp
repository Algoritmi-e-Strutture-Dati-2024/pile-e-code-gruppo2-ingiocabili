#include <iostream>

// Definizione della classe Lista come template
template <typename T>
class Pila {
  private:
    //usiamo  un'istanza di ListaPunatori come base
    ListaPuntatori<T> lista;
  public:
    // Costruttore
    void push(T elem){
      //usa l'oggetto lista con la sua relativa funzione per inserire un elemento nella posizione in testa
      lista.inslista(elem, 1);
    }

    T pop(){
      if(lista.listavuota()){
          return lista.lung==0;
      }else{
        //qui viene letto il valore in testa e viene cancellato
        T valore=lista.leggilista(1);
        lista.canclista(1);
        return valore;
      }
    }

    T top(){
      if(lista.listavuota()){
          return lista.lung==0;
      }else{
        return lista.leggilista(1);
      }

    bool isEmpty() const{
      return lung==0;
    }

    int size() const{
      return lista.lunghezza();
    }
  }

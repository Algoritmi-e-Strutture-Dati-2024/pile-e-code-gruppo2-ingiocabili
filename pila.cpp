#include <iostream>

template <typename T>
class Pila {
  private:
    //usiamo  un'istanza di ListaPunatori come base
    ListaPuntatori<T> lista;
  public:
    void push(T elem){
      lista.inslista(elem, 1);
    }

    T pop(){
      if(lista.listavuota()){
          return lista.lung==0;
      }else{
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

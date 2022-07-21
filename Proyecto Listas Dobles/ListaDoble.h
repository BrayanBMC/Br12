#include <iostream>


using namespace std;

class ListaD {
  int dato, busqueda, tamano, tamano1;
  ListaD *sig, *ant;

  public:

    void crearCab(ListaD *&cab, int dato){
		cab=new ListaD;
		cab->dato=dato;
		cab->sig=cab->ant=NULL;	
	}

  void agregarNodo(ListaD *&cab, int dato){
		ListaD *aux=cab;
	    while(aux->sig){
		aux=aux->sig; //avanzar ala siguiente memoria
		}
		aux->sig=new ListaD;
		aux->sig->ant=aux;
		aux=aux->sig;
		aux->dato=dato; //auxiliar en su parte dato hagalo dato
		aux->sig=NULL;
	}

  void crearL(ListaD *&cab) {
    int dato = 999;
    cout<<"Para terminar la lista oprima CERO "<<"\n";
    while (dato > 0) {
      cout << "Numero: ";
      cin >> dato;
      if (dato > 0) {
        if (!cab) {
          crearCab(cab, dato);
        } else {
          agregarNodo(cab, dato);
        }
      }
    }
  }
  
  void mostrarL(ListaD * cab) {
    ListaD * aux = cab;
    while (aux) {
      cout << "Dato " << aux -> dato << endl;
      aux = aux -> sig;
    }
  }

  //Buscar en la lista

  void buscarL(ListaD *cab) {
    int b = 0;
    int busqueda;
    ListaD * aux = cab;
    cout << "Ingrese el dato que desea buscar: ";
    cin >> busqueda;

    while (aux && !b) {
      if (aux -> dato == busqueda) {
        b = 1;
      } else {
        aux = aux -> sig;
      }
    }
    if (b) {
      cout << "El Numero Existe: " << aux -> dato << endl;
    } else {
      cout << "El Numero No Existe" << endl;
    }
  }

  //suma de 2 listas en una tercera

  int contadorL(ListaD * cab) {
    int tamano = 0;
    int tamano1 = 0;
    while (cab) {
      cab = cab -> sig;
      tamano++;
    }
    cout << "Cantidad de elementos de la lista actual: " << tamano << endl <<"\n";
    return tamano;
  }

  int contadorL2(ListaD * aux) {
    int tamano1 = 0,tamanof=0;
    while (aux) {
      aux = aux -> sig;
      tamano1++;
    }
    tamanof=tamano1-2;
    cout << "Cantidad de elementos de la lista actual: " << tamanof << endl;
    return tamanof;
  }


  int sumaL(ListaD *&cab, ListaD *&aux, int t1, int t2) {
    int suma1 = 0, suma2 = 0, suma = 0;
    ListaD *cab3;
    if (t1 == t2) {
      cout << "SUMA " << endl;
      while (cab) { //aux!=NULL
      cab=cab->sig;
      suma1+=cab->dato;
      cout<<" Dato: "<<cab3<<endl;
      }
      while(aux){
      	aux=aux->sig;
      	suma2+=aux->dato;
	  }
	  suma=suma1+suma2;
	  cout<<" Dato: "<<suma<<endl;
    } else {
      cout << "No es posible realizar la suma" << endl;
    }
  }

  //pares de la lista

  void paresL(ListaD *cab) {
    ListaD *aux = cab;

    cout << "Los numeros pares e impares son: " << endl;
    int par, imp;
    while (aux) {
      if (aux -> dato % 2 == 0) {
        cout <<"Numero par: " << aux -> dato << endl;
        aux = aux -> sig;
        par++;
      } else {
        aux = aux -> sig;
      }
    }
    
  }
  
  void imparesL(ListaD * cab) {
    ListaD *aux = cab;

    cout << "Los numeros impares son: " << endl;
    int par, imp;
    while (aux) {
      if (aux -> dato % 2 != 0) {
        cout <<"Numero impar: " << aux -> dato << endl;
        aux = aux -> sig;
      } else {
        aux = aux -> sig;
      }
    }
    
  }

  //Mayores de la lista

  void mayorL(ListaD * cab) {
    ListaD * aux = cab;
    int mayor = 0;
    while (aux) {
      if ((aux -> dato) > mayor) {
        mayor = aux -> dato;
      }
      aux = aux -> sig;
    }
    cout << "El mayor dato de la lista es: " << mayor << endl;
  }

  //Menores de la lista

  void menorL(ListaD * cab) {
    ListaD * aux = cab;
    int menor = 10000;
    while (aux) {
      if ((aux -> dato) < menor) {
        menor = aux -> dato;
      }
      aux = aux -> sig;
    }
    cout << "El menor dato es: " << menor << endl;
  }

  //Invertir lista

  void invertL(ListaD *cab) {
    ListaD * aux = cab;
    ListaD * siguiente = NULL;
    ListaD * anterior = NULL;
    while (aux) {
      siguiente = aux -> sig;
      aux -> sig = anterior;
      anterior = aux;
      aux = siguiente;
    }
    aux = anterior;
    cout << "Lista Invertida: " << endl;
    while (aux&&anterior) {
	  cout << "Dato: " << anterior -> dato << endl;
      anterior = anterior -> sig;
    }
    cout<<" "<<endl;
  }

  //Eliminar nodo

  void eliminaL(ListaD *&cab, int dato) {

    ListaD *aux, *aux1;
    aux1 = aux = cab;

    while (aux && dato != aux -> dato) {
      aux1 = aux;
      aux = aux -> sig;
    }
    if (dato == aux -> dato && aux) {
      if (aux -> sig == NULL) {
        aux1 -> sig = NULL;
      } else {
        if (aux == cab && aux -> sig) {
          cab = cab -> sig;
        } else {
          aux1 -> sig = aux -> sig;
        }
      }
      delete aux;
    } else {
      
      	cout << "Dato no encontrado";
    }
  }


  //Menu de opciones

  void menuL(ListaD *cab) {
    int opc;
    do {
      system("cls");
      cout << ".:::::::: BIENVENIDO AL PROYECTO DE LISTAS DOBLES ::::::::." << endl<<"\n";
      cout << "Ingrese alguna opcion" << endl;
      cout << " 1. Crear lista " << endl;
      cout << " 2. Mostrar lista " << endl;
      cout << " 3. Buscar numero en la lista " << endl;
      cout << " 4. Numeros pares e impares en la lista " << endl;
      cout << " 5. Mayor numero en la lista: " << endl;
      cout << " 6. Menor numero en la lista: " << endl;
      cout << " 7. Invertir de la lista: " << endl;
      cout << " 8. Eliminar nodo de la lista " << endl;
      cout << " 9. Sumar 2 listas " << endl;
      cout << "-----------------------------------------------------------"<< endl;
      cout << " PULSE 666 PARA SALIR... " << endl<<"\n";
      cout << "Eliga la opcion deseada: ";
      cin >> opc;
      cout<<"\n";
      switch (opc) {
      case 1: {
        crearL(cab);
        break;
      }
      case 2: {
        mostrarL(cab);
        break;
      }
      case 3: {
        buscarL(cab);
        break;
      }
      case 4: {
        paresL(cab);
        imparesL(cab);
        break;
      }
      case 5: {
        mayorL(cab);
        break;
      }
      case 6: {
        menorL(cab);
        break;
      }
      case 7: {
        invertL(cab);
        break;
      }
      case 8: {
        cout << "Ingrese el dato que desea eliminar" << endl;
        cin >> dato;
        eliminaL(cab, dato);
        break;
      }
      case 9: {
        int t1, t2=0;
        mostrarL(cab);
        t1 = contadorL(cab);
        ListaD * aux=NULL;
        crearCab(aux, dato);
        agregarNodo(aux, dato);
        crearL(aux);
        t2=contadorL2(aux);
        
        break;
      }

      default: {

      }
     }
      system("pause");
    } while (opc != 666);
  }

};

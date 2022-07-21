#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

class ListaD {
  char dato, busqueda, tamano, tamano1;
  int longitud;
  ListaD *sig, *ant;

  public:

    void crearCab(ListaD *&cab, char dato){
		cab=new ListaD;
		cab->dato=dato;
		cab->sig=cab->ant=NULL;	
	}

  void agregarNodo(ListaD *&cab, char dato){
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

  void crearLc(ListaD *&cab){
	int i;
	char dato;
	dato=i;
	
	char fin;
	fin=237;//Ý
	int letra=0;
	int numero=0;
	int esp=0;	

	cout<<"Para terminar la lista oprima (acento+Y) "<<"\n";
		while(dato!=fin){
		 cout<<"dato = ";
		 cin>>dato;
			if(dato!=fin){	
			if(!cab){//cab==NULL 
				crearCab(cab, dato);
			}
			else{
				agregarNodo(cab,dato);
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

  void buscarL(ListaD * cab) {
    int b = 0;
    char busqueda;
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
      cout << "El Caracter Existe: " << aux -> dato << endl;
    } else {
      cout << "El Caracter No Existe" << endl;
    }
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

  void eliminaL(ListaD *&cab, char dato) {

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
  
  //contador caracteres 
  
  void caracterLc(ListaD *cab, char dato){
    int i,letra=0,numero=0,esp=0;
	
	while(cab){
		if(cab->dato>='A' && cab->dato<='Z'||cab->dato>='a' && cab->dato<='z'){
			letra++;
			cab=cab->sig;
		}else{
			if(cab->dato>='0' && cab->dato<'9'){
			numero++;
			cab=cab->sig;
			}else{
				if(cab->dato<'0' || (cab->dato>'9' && cab->dato<'A') || (cab->dato>'Z' && cab->dato<'a') || cab->dato>'z'||(cab->dato==00 && cab->dato<47) || (cab->dato>122 && cab->dato<160) ||(cab->dato>165 && cab->dato<255) ){
			        esp++;
			        cab=cab->sig;
		            }
			}
		}
	}
			

letra;
numero;
esp;
cout<<"cantidad de Letras: "<<letra<<endl;
cout<<"cantidad de numeros: "<<numero<<endl;
cout<<"cantidad de caracteres especiales: "<<esp<<endl;
  }
  
//Convertir mayusculas en minusculas
  
  void cambiarlL(ListaD *cab){
	ListaD *aux=cab;
	while(aux){
		 if(aux->dato>='A' && aux->dato<='Z'){
		 	char min;
		 	min=aux->dato+32;
		 	cout<<"convertido: "<<min<<endl;
		 	aux=aux->sig;
		}
		else{
			if(aux->dato>='a' && aux->dato<='z'){
			char may;
			may=aux->dato-32;
		 	cout<<"convertido: "<<may<<endl;
		 	aux=aux->sig;
			}
		}
	}
}

    //palabra palindroma
    
    void palindroma(ListaD *&cab){
	ListaD *aux=cab;
	char pal[longitud],palInv[longitud];
	int i=0;
	while(aux){
		pal[i]=aux->dato;
		palInv[i]=aux->dato;
		aux=aux->sig;
		i++;
	}
	for(int i=0;i<longitud/2;i++){
			char aux1[1];
			aux1[0]=palInv[i];
			palInv[i]=palInv[longitud-i-1];
			palInv[longitud-i-1]=aux1[0];
	}
	string palabra=pal,palabraInversa=palInv;
	if(palabra==palabraInversa){
		cout<<"Palabra palindroma detectada -> "<<palabra<<endl;
	}else{
		cout<<"Palabra palindroma no detectada -> "<<palabra<<endl;
	}
}
	
	//caracteres con vocales etc
	
	/*void caracterLcVyC(ListaS *cab, char dato){
    int i,letra=0,vocal=0,consonante=0,numero=0,esp=0;
	
	while(cab){
		if(){
			if((cab->dato=='a')||(cab->dato=='e')||(cab->dato=='i')||(cab->dato=='o')||(cab->dato=='u')||(cab->dato=='A')||(cab->dato=='E')||(cab->dato=='O')||(cab->dato=='U')||(cab->dato=='I')){
			vocal++;
			cab=cab->sig;	
		    }else{
		    	consonante++;
		    	cab=cab->sig;
			}
			cab=cab->sig;
		}
	}
vocal;
consonante;
cout<<"Cantidad de Letras Vocales: "<<vocal<<endl;
cout<<"Cantidad de Letras Consonante: "<<consonante<<endl;
  }*/
   
  //contador palabras
  
   void contadorpL(ListaD *cab, char dato){
    char espacio;
	espacio=37;
	int e;


cout<<"Cantidad de palabras en la lista es: "<<e<<endl;
  }


  //Menu de opciones

  void menuLc(ListaD * cab) {
    int opc;

    do {
      system("cls");
      cout << ".:::::::: BIENVENIDO AL PROYECTO DE LISTAS DOBLES CON CARACTERES ::::::::." << endl<<"\n";
      cout << "Ingrese alguna opcion" << endl;
      cout << " 1. Crear lista de carcteres " << endl;
      cout << " 2. Mostrar lista " << endl;
      cout << " 3. Buscar dato en la lista " << endl;
      cout << " 4. Invertir de la lista " << endl;
      cout << " 5. Contador de caracteres, numeros y especiales " << endl;
      cout << " 6. Convertir Letras MAYUSCULAS en minusculas y viceversa " << endl;
      cout << " 7. Descubra si su palabra es palindroma " << endl;
      cout << " 8. Contador de caracteres con vocales y consonantes " << endl;
      cout << " 9. Contador de palabras en la lista " << endl;
      cout << " 10. Eliminar nodo de la lista " << endl;
      cout << "-----------------------------------------------------------"<< endl;
      cout << " PULSE 666 PARA SALIR DEL PROGRAMA " << endl<<"\n";
      cout << "Eliga la opcion deseada: ";
      cin >> opc;
      cout<<"\n";
      switch (opc) {
      case 1: {
        crearLc(cab);
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
        invertL(cab);
        break;
      }
      case 5: {
        caracterLc(cab, dato);
        break;
      }
      case 6: {
      	cambiarlL(cab);
        break;
      }
      case 7: {
      	palindroma(cab);
        break;
      }
      case 8: {
      	int vocal=0,consonante=0;
		caracterLc(cab, dato);
        while(cab){
			if((cab->dato=='a')||(cab->dato=='e')||(cab->dato=='i')||(cab->dato=='o')||(cab->dato=='u')||(cab->dato=='A')||(cab->dato=='E')||(cab->dato=='O')||(cab->dato=='U')||(cab->dato=='I')){
			vocal++;
			cab=cab->sig;	
		    }else{
		    	if((cab->dato>64&&cab->dato<91)&&(cab->dato>96&&cab->dato<123))
		    	consonante++;
		    	cab=cab->sig;
			}
			cab=cab->sig;
	}
vocal;
consonante;
cout<<"Cantidad de Letras Vocales: "<<vocal<<endl;
cout<<"Cantidad de Letras Consonante: "<<consonante<<endl;
        break;
      }
      case 9: {
        contadorpL(cab, dato);
        break;
      }
      case 10: {
      	cout << "Ingrese el dato que desea eliminar" << endl;
        cin >> dato;
        eliminaL(cab, dato);
        break;
      }
      default: {

      }
     }
      system("pause");
    } while (opc != 666);
  }


};

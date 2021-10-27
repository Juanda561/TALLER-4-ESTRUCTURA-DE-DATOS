#include <iostream>
using namespace std;

struct NODO1{//LISTA ENLAZADA DOBLE
	int NUM;
	NODO1 *SIG;
	NODO1 *ANT;
} *cabeza1, *p1, *q1, *fin1;

struct NODO2{//LISTA ENLAZADA SIMPLE
	int NUM;
	NODO2 *SIG;
	
}*cabeza2, *p2, *q2, *r2, *fin2;

void insertar_numeros_l1(),insertar_numero_l2(),mostrar_lista1(),mostrar_lista2(),agregar_numeros_a_lista1(int&),recorrer_listasimple2(), borrar_de_lista2(int&);

void insertar_numeros_l1(){
	
	char seguir='S';
	
	do{
		
		NODO1* p1 = new NODO1();
	
		if(p1==NULL){
			cout<<"NO hay memoria Disponible";	
		}else{
			cout<<"*****INGRESAR NUMEROS A LA LISTA DOBLE L1*****"<<endl;
			cout<<"Ingrese un NUMERO: ";
			cin>>p1->NUM;
			p1->ANT=NULL;
			p1->SIG=NULL;
		
			if(cabeza1==NULL){//la lista está vacia?
				cabeza1=p1;
			}else{
				//va antes del primero?
				if(p1->NUM>cabeza1->NUM){//lo inserto de primero
					p1->SIG=cabeza1;
					cabeza1->ANT=p1;
					cabeza1=p1;
				}else{
					//va después del último?
					q1=cabeza1;
					
					while(q1->SIG!=NULL){
						q1=q1->SIG;
					}
				
					if(p1->NUM<q1->NUM){//la conecto despues del ultimo
						q1->SIG=p1;
						p1->ANT=q1;
					}else{//va en medio de dos nodos cualquiera
						q1=cabeza1;
					
						while(p1->NUM<q1->NUM){
							q1=q1->SIG;
						}
					
						//Enlazo mi nuevo nodo, primero por la izquierda
						p1->ANT=q1->ANT;
						p1->ANT->SIG=p1;
					
						//enlazo mi nuevo nodo, ahora por la derecha
						p1->SIG=q1;
						q1->ANT=p1;
					}
				}
			}
		}
		cout<<"Desea INGRESAR otro numero? [S/N]: ";
		cin>>seguir;
		cout<<""<<endl;		
	}while(seguir=='S');

}

void insertar_numero_l2(){
	char seguir='S';
	
	while(seguir=='S'){
		
		//Pido un nodo
		NODO2* p2 = new NODO2();
		
		if(p2==NULL){
			cout<<"No hay memoria disponible en el sistema...."<<endl;
		}else{
			//Llenamos el nodo
			cout<<""<<endl;
			cout<<"******INGRESAR NUMEROS A LA LISTA SIMPLE L2******"<<endl;
				
			cout<<"Introduzca una numero: ";
			cin>>p2->NUM;
			
			if(cabeza2==NULL){
				cabeza2=p2;
				fin2=p2;
			}else{
				fin2->SIG=p2;
				fin2=p2;
			}
			
			cout<<"Desea agregar otro numero a la lista? [S/N]: ";
			cin>>seguir;
		}
	}
}

void mostrar_lista1(){
	cout<<""<<endl;
	cout<<"*****Lista Enlazada Doble L1*****"<<endl;
	if(cabeza1!=NULL){
		for	(p1=cabeza1; p1!=NULL; p1=p1->SIG){
			cout<<p1->NUM<<"<->";
		}
	}else{
		cout<<"La lista 1 esta vacia"<<endl;
		system("pause");
	}
	/*p1=cabeza1;
	while(p1!=NULL){
			
			cout<<p1->letra<<"-->";
			p1=p1->SIG;
	}*/	
	cout<<""<<endl;
}

void mostrar_lista2(){
	cout<<""<<endl;
	cout<<"*****Lista Enlazada SIMPLE L2*****"<<endl;
	if(cabeza2!=NULL){
		for	(p2=cabeza2; p2!=NULL; p2=p2->SIG){
			cout<<p2->NUM<<"->";
		}
	}else{
		cout<<"La lista 1 esta vacia"<<endl;
		system("pause");
	}
	/*p1=cabeza1;
	while(p1!=NULL){
			
			cout<<p1->letra<<"-->";
			p1=p1->SIG;
	}*/	
	cout<<""<<endl;
}

void recorrer_listasimple2(){
	
	int numero;
	
	cout<<""<<endl;
	cout<<"*****Lista Enlazada SIMPLE L2*****"<<endl;
	if(cabeza2!=NULL){
		for	(p2=cabeza2; p2!=NULL; p2=p2->SIG){
			numero=p2->NUM;
			agregar_numeros_a_lista1(numero);
		}
	}else{
		cout<<"La lista 1 esta vacia"<<endl;
		system("pause");
	}
	/*p1=cabeza1;
	while(p1!=NULL){
			
			cout<<p1->letra<<"-->";
			p1=p1->SIG;
	}*/	
	cout<<""<<endl;
}

void agregar_numeros_a_lista1(int& numero){
		
		char encontro='N';
		
		p1=cabeza1;
		
		while(encontro=='N' && p1!=NULL){
			if(p1->NUM==numero){
				encontro='S';
				borrar_de_lista2(numero);
				cout<<"Ya esta en la lista 1, el numero: "<<numero<<endl;
				
			}else{
				p1=p1->SIG;
		    }
		}
		
		if(encontro=='N'){
			NODO1* p1 = new NODO1();
		
			if(p1==NULL){
				cout<<"NO hay memoria Disponible";	
			}else{
				cout<<"Se ha agregado de la lista 2, a la lista 1, el numero: "<<numero<<endl;
				p1->NUM=numero;
				p1->ANT=NULL;
				p1->SIG=NULL;
		
				if(cabeza1==NULL){//la lista está vacia?
					cabeza1=p1;
				}else{
					//va antes del primero?
					if(p1->NUM>cabeza1->NUM){//lo inserto de primero
						p1->SIG=cabeza1;
						cabeza1->ANT=p1;
						cabeza1=p1;
					}else{
						//va después del último?
						q1=cabeza1;
					
						while(q1->SIG!=NULL){
							q1=q1->SIG;
						}
				
						if(p1->NUM<q1->NUM){//la conecto despues del ultimo
							q1->SIG=p1;
							p1->ANT=q1;
						}else{//va en medio de dos nodos cualquiera
							q1=cabeza1;
					
							while(p1->NUM<q1->NUM){
							q1=q1->SIG;
							}
					
							//Enlazo mi nuevo nodo, primero por la izquierda
							p1->ANT=q1->ANT;
							p1->ANT->SIG=p1;
					
							//enlazo mi nuevo nodo, ahora por la derecha
							p1->SIG=q1;
							q1->ANT=p1;
						}
					}
				}
			}
		}
		
		cout<<""<<endl;		
}

void borrar_de_lista2(int& numero){
	
	if(cabeza2!=NULL){
		
		for	(q2=cabeza2; q2!=NULL; q2=q2->SIG){
			
			if(q2->NUM==numero){
				if(q2==cabeza2 && q2->SIG==NULL){
					cabeza2=NULL;
					//delete p1;
				}else{
					if(q2==cabeza2){
						cabeza2=cabeza2->SIG;
						//delete p1;
					}else{
						r2=cabeza2;
						while(r2->SIG!=q2){
							r2=r2->SIG;
						}
						r2->SIG=q2->SIG;
						//delete q1;
					}
				}						
			}			
		}				
	}else{
		cout<<"La lista simple l2,  esta vacia"<<endl;
		system("pause");
	}
	
}


int main(){
	
	insertar_numeros_l1();
	mostrar_lista1();
	insertar_numero_l2();
	mostrar_lista2();
	recorrer_listasimple2();
	mostrar_lista1();
	mostrar_lista2();
	
	return 0;
}


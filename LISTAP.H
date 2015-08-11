//================================================//
// - Estructura de Datos y Algoritmos 2014 -
//================================================//
#ifndef LISTAP_H
#define LISTAP_H

#ifndef __STDLIB_H
	#include<STDLIB.H>
#endif
#ifndef __STDIO_H
	#include<STDIO.H>
#endif
#ifndef EXIT_ERROR
	#define EXIT_ERROR 255
#endif

#include <iostream>

//================================================//
using namespace std;

template<class T>
class Nodo {
	public:
	T elemento;
	Nodo<T> *siguiente;
};

typedef Nodo<tipo>* posicion;

template<class T>
class Lista{
private:
	posicion primero;
	posicion ultimo;
	unsigned int cant;
public:
	Lista();
	Lista(const Lista <T> &);
    Lista <T> operator=(const Lista<T> &);
	~Lista();
	int cantidad(void);
	void insertar(T, posicion);
	void eliminar(posicion);
	T recuperar (posicion);
	posicion siguiente(posicion);
	posicion anterior(posicion);
	posicion fin(void);
	posicion primer(void);
	void vaciar(void);
	posicion localizar (T);
	///METODOS NUEVOS
	void ordInsert(T );
	void catList(Lista<T> );
	void operator+(Lista<T> );
	void insList(int orden, Lista<T> );
    Lista<T> invList(void);
    Lista<T> invList(posicion );
    Lista<T> difList(Lista<T> );
    Lista<T> operator -(Lista<T> );
    Lista<T> itcList(Lista<T> );
    Lista<T> operator *(Lista<T> );
    Lista<T> subList(unsigned char , unsigned char );
    Lista<T> mixList (Lista<T> );
    void ordenar(void);
};

///================================================//
template<class T>
void Lista<T>::ordenar(void)
{
    posicion p1, p2,temp;

    posicion p3=anterior(ultimo);

    for(p1=primero->siguiente; p1->siguiente != NULL; p1=p1->siguiente)
        for(p2=primero; p2->siguiente->siguiente != NULL ; p2=p2->siguiente)
            if(p2->siguiente->siguiente->elemento < p2->siguiente->elemento){
                temp=p2->siguiente;
                p2->siguiente=p2->siguiente->siguiente;
                temp->siguiente=p2->siguiente->siguiente;
                p2->siguiente->siguiente=temp;
                }
    ultimo=p2->siguiente;
}

template <class T>
void Lista<T>::ordInsert(T x)
{
    posicion p=primero;
    while(p->siguiente!=NULL && p->siguiente->elemento<x)
        p=p->siguiente;
    insertar(x,p);
}

template <class T>
void Lista<T>::catList(Lista<T> l2)
{
    posicion  p2=l2.primero;
        while(p2->siguiente!=NULL){
            p2=p2->siguiente;
            insertar(p2->elemento,ultimo);
        }
}

template <class T>
void Lista<T>::operator+(Lista<T> l2)
{
    this->catList(l2);
}

template <class T>
void Lista<T>::insList(int orden, Lista<T> l2)
{
    posicion p1=primero, p2=l2.primero;
    if(1<=orden && orden <=cant)
    {
        for(int i=1; i < orden; i++)
            p1=p1->siguiente;

        while(p2->siguiente!=NULL){
            posicion temp=p1->siguiente;
            p1->siguiente=new Nodo<T>;
            p1->siguiente->elemento=p2->siguiente->elemento;
            p1->siguiente->siguiente=temp;
            p2=p2->siguiente;

            if(p1==ultimo)
                ultimo=p1->siguiente;

            p1=p1->siguiente;
            cant++;
        }

    }
}

//template <class T>
//void Lista<T>::insList(int orden, Lista<T> l2)
//{
//   posicion p1=primero, p2=l2.primero;
//    if(1<=orden && orden <=cant)
//    {
//        for(int i=1; i < orden; i++)
//            p1=p1->siguiente;
//
//        while(p2->siguiente!=NULL){
//            insertar(p2->siguiente->elemento, p1);
//            p2=p2->siguiente;
//            p1=p1->siguiente;
//        }
//
//    }
//
//}

template <class T>
Lista<T> Lista<T>::invList(void)
{
    Lista<T> inv;
    posicion p1=primero, p2=inv.primero;
    while(p1->siguiente!=NULL){
        posicion temp=p2->siguiente;
        p2->siguiente=new Nodo<T>;
        p2->siguiente->elemento=p1->siguiente->elemento;
        p2->siguiente->siguiente=temp;
            if(p2==inv.ultimo)
                inv.ultimo=p2->siguiente;
        inv.cant++;
        p1=p1->siguiente;
    }
    return inv;
}

//template <class T>
//Lista<T> Lista<T>::invList2(void)
//{
//    Lista<T> inv;
//    posicion p1=primero;
//    while(p1->siguiente!=NULL){
//        inv.insertar(p1->siguiente->elemento,inv.primero);
//        p1=p1->siguiente;
//    }
//    return inv;
//}

template <class T>
Lista<T> Lista<T>::invList(posicion p) ///Falta controlar p
{
    Lista<T> inv;
    posicion p1=primero,p2=inv.primero;
    while(p1->siguiente!=NULL && p1!=p){
        posicion temp=p2->siguiente;
        p2->siguiente=new Nodo<T>;
        p2->siguiente->elemento=p1->siguiente->elemento;
        p2->siguiente->siguiente=temp;
        p2=p2->siguiente;
        p1=p1->siguiente;
        inv.ultimo=p2;
        inv.cant++;
    }
    while(p1->siguiente!=NULL){
        posicion temp=p2->siguiente;
        p2->siguiente=new Nodo<T>;
        p2->siguiente->elemento=p1->siguiente->elemento;
        p2->siguiente->siguiente=temp;
        p1=p1->siguiente;
            if(p2==inv.ultimo)
                inv.ultimo=p2->siguiente;
        inv.cant++;
    }
    return inv;
}

//template <class T>
//Lista<T> Lista<T>::invList2(posicion p) ///Falta controlar p
//{
//    Lista<T> inv;
//    posicion p1=primero,p2=inv.primero;
//    while(p1->siguiente!=NULL && p1!=p){
//        inv.insertar(p1->siguiente->elemento,p2);
//        p2=p2->siguiente;
//        p1=p1->siguiente;
//    }
//    while(p1->siguiente!=NULL){
//        inv.insertar(p1->siguiente->elemento,p2);
//        p1=p1->siguiente;
//    }
//    return inv;
//}

template <class T>
Lista<T> Lista<T>::difList(Lista<T> l2)
{
    Lista<T> dif;
    posicion p1, p2;
    for(p1=primero; p1->siguiente != NULL ;p1=p1->siguiente)
    {
        for(p2=l2.primero; p2->siguiente != NULL && p2->siguiente->elemento != p1->siguiente->elemento ;p2=p2->siguiente );

        if(p2->siguiente==NULL)
            dif.insertar(p1->siguiente->elemento,dif.ultimo);
    }
    return dif;

}

template <class T>
Lista<T> Lista<T>::operator -(Lista<T> l2)
{
    return this->difList(l2);
}

template <class T>
Lista<T> Lista<T>::itcList(Lista<T> l2)
{
    posicion p1, p2;
    posicion temp;
    Lista<T> itc;
    for(p1=primero; p1->siguiente != NULL; p1=p1->siguiente)
    {
        for(p2=l2.primero; p2->siguiente != NULL && p2->siguiente->elemento!= p1->siguiente->elemento; p2=p2->siguiente);
            if(p2->siguiente!=NULL)
            {
                temp=itc.ultimo->siguiente;
                itc.ultimo->siguiente=new Nodo<T>;
                itc.ultimo->siguiente->elemento=p1->siguiente->elemento;
                itc.ultimo->siguiente->siguiente=temp;
                itc.ultimo=itc.ultimo->siguiente;
                itc.cant++;

                temp=p2->siguiente;
                p2->siguiente=p2->siguiente->siguiente;
                if(temp=l2.ultimo)
                    l2.ultimo=p2;
                delete temp;
                l2.cant--;
            }
    }

    return itc;
}

template <class T>
Lista<T> Lista<T>::operator *(Lista<T> l2)
{
    return this->itcList(l2);
}


template <class T>
Lista<T> Lista<T>::subList(unsigned char i, unsigned char len) ///Falta controlar i
{
    posicion p=primero;
    Lista<T> sub;
    int k;
    for(k=0; k<i && p->siguiente!=NULL; k++)
        p=p->siguiente;
    k=0;
    while(p->siguiente!=NULL && k<len)
    {
    sub.insertar(p->siguiente->elemento,sub.ultimo);
    k++;
    p=p->siguiente;
    }

    return sub;
}

template <class T>
Lista<T> Lista<T>::mixList (Lista<T> l2)
{
    posicion p1, p2;
    posicion temp;
    for(p1=primero, p2=l2.primero; p1->siguiente != NULL && p2->siguiente != NULL ; p1=p1->siguiente , p2=p2->siguiente)
    {
        temp=p2->siguiente;
        p2->siguiente= new Nodo<T>;
        p2->siguiente->elemento=p1->siguiente->elemento;
        p2->siguiente->siguiente=temp;
        if(p2==l2.ultimo)
            l2.ultimo=p2->siguiente;
        l2.cant++;
        p2=p2->siguiente;
    }
    for(p1; p1->siguiente != NULL; p1=p1->siguiente)
    {
        temp=l2.ultimo->siguiente;
        l2.ultimo->siguiente= new Nodo<T>;
        l2.ultimo->siguiente->elemento=p1->siguiente->elemento;
        l2.ultimo->siguiente->siguiente=temp;
        l2.ultimo=l2.ultimo->siguiente;
        l2.cant++;
    }
    return l2;
}


///LIMITE ---------------------------------------------///



template <class T>
Lista<T>::Lista() {
	primero = new Nodo<T>;
	ultimo = primero;
	primero->siguiente = NULL;
	cant = 0;
};

template <class T>
Lista<T>::Lista(const Lista<T> &l2)
{
    primero = new Nodo<T>;
	ultimo = primero;
	primero->siguiente = NULL;
	cant = 0;
    for(posicion p=l2.primero; p->siguiente!=NULL; p=p->siguiente)
        insertar(p->siguiente->elemento,ultimo);
}
template <class T>
Lista <T> Lista<T>:: operator=(const Lista<T> &l2)
{
    for(posicion p=l2.primero; p->siguiente!=NULL; p=p->siguiente)
        insertar(p->siguiente->elemento,ultimo);
    return *this;
}

template <class T>
Lista<T>::~Lista() {
	vaciar();
};

//================================================//

template <class T>
int Lista<T>::cantidad(void) {
	return(cant);
};

//================================================//

template <class T>
void Lista<T>::insertar(T x, posicion p) {
	posicion temp;
	if(p!=NULL) {
		temp = p->siguiente;
		p->siguiente = new Nodo<T>;
		p->siguiente->elemento = x;
		p->siguiente->siguiente = temp;
		if(p==ultimo)
			ultimo = p->siguiente;
		cant++;
	} else {
		fprintf(stderr,"\nHa intentado insertar en una posicion invalida\n");
		exit(EXIT_ERROR);
	}
};

//================================================//

template<class T>
void Lista<T>::eliminar(posicion p) {
	posicion temp;
	if((p!=NULL) && (p!=ultimo)) {
		temp = p->siguiente;
		p->siguiente = p->siguiente->siguiente;
		if(temp==ultimo)
			ultimo=p;
		delete temp;
		cant--;
	} else {
		fprintf(stderr,"\nHa intentado eliminar en una posicion invalida\n");
		exit(EXIT_ERROR);
	}
 };

//================================================//

template <class T>
T Lista<T>::recuperar(posicion p) {
	T result;
	if(p!=NULL && p->siguiente!=NULL)
		result = p->siguiente->elemento;
	else {
		fprintf(stderr,"\nHa intentado recuperar en una posicion invalida\n");
		exit(EXIT_ERROR);
	}
	return(result);
};
//================================================//

template <class T>
posicion Lista<T>::siguiente(posicion p) {
	posicion result;
	if(p!=NULL && p!=ultimo)
			result = p->siguiente;
	else {
		fprintf(stderr,"\nHa intentado encontrar el proximo de una posicion invalida\n");
		exit(EXIT_ERROR);
	}
	return(result);
};

//================================================//

template <class T>
posicion Lista<T>::anterior(posicion p) {
	posicion q;
	if(p!=NULL) {
		q=primero;
		if(p!=q) {
			while(q->siguiente!=NULL &&q->siguiente!=p)
				q=q->siguiente;
		}
	} else {
		fprintf(stderr,"\nHa intentado encontrar el anterior de una posicion invalida\n");
		exit(EXIT_ERROR);
	}
	return (q);
};

//================================================//

template <class T>
posicion Lista<T>::primer(void) {
	return(primero);
};

//================================================//

template <class T>
posicion Lista<T>::fin(void) {
	return(ultimo);
};

//================================================//

template <class T>
posicion Lista<T>::localizar(T x) {
	posicion p;
	p=primero;
	while(p->siguiente!=NULL && p->siguiente->elemento!=x){
		p=p->siguiente;
	}
	return (p);
};

//================================================//

template<class T>
void Lista<T>::vaciar(void){
	posicion temp;
	posicion p;
	p = primero;
	while(p->siguiente!=NULL) {
		temp = p->siguiente;
		p->siguiente = p->siguiente->siguiente;
		delete temp;
	}
	ultimo = p;
	cant = 0;
};

#endif // LISTAP_H

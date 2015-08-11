//================================================//
// - Estructura de Datos y Algoritmos 2014 -
//================================================//
#ifndef LISTAA_H
#define LISTAA_H

#ifndef __STDLIB_H
	#include<STDLIB.H>
#endif
#ifndef __STDIO_H
	#include<STDIO.H>
#endif

#define EXIT_ERROR 255

typedef int posicion;
//================================================//
template<class T>
class Lista {
private:
	T elementos[CANTELE];
	int ultimo;
	int cant;
public:
	Lista();
	void insertar(T, posicion);
	void eliminar(posicion);
	int cantidad();
	posicion localizar(T);
	T recuperar(posicion);
	posicion siguiente(posicion);
	posicion anterior(posicion);
	posicion fin();
	posicion primer();
	void vaciar();

    void ordInsert(T);
    void catList(Lista<T>);
    void insList(int, Lista<T>);
    Lista<T> invList();
    Lista<T> invList(posicion);
    Lista<T> difList1(Lista<T>);
    Lista<T> difList2(Lista<T>);
    Lista<T> itcList(Lista<T>);
    Lista<T> subList(unsigned char, unsigned char);
    Lista<T> mixList (Lista<T>);
    void ordenar(void);

    void operator+(Lista<T>);
    Lista<T> operator-(Lista<T>);
    Lista<T> operator*(Lista<T>);

};

//================================================//
template <class T>
Lista<T>::Lista() {
	ultimo=-1;
	cant=0;
};

//================================================//
template <class T>
int Lista<T>::cantidad() {
	return(cant);
};

//================================================//
template <class T>
void Lista<T>::insertar(T x, posicion p) {
	if((p>=0) && (p<=ultimo+1)){
        if (cant < CANTELE){   ///Modificado
            int i;
            for(i=ultimo; i>=p; i--) {
                elementos[i+1] = elementos[i];
            }
            elementos[p] = x;
            ultimo++;
            cant++;
        }
	} else {
		fprintf(stderr,"\nHa intentado insertar en una posicion invalida\n");
		exit(EXIT_ERROR);
	}
};

//================================================//
template<class T>
void Lista<T>::eliminar(posicion p) {
	if((p>=0) && (p<=ultimo)) {
		int i;
		for(i=p;i<ultimo;i++) {
			elementos[i] = elementos[i+1];
		}
		ultimo--;
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
	if((p>=0) && (p<=ultimo))
		result = elementos[p];
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
	if((p>=0) && (p<=ultimo)) {
			result=p+1;
	} else {
		fprintf(stderr,"\nHa intentado encontrar el proximo de una posicion invalida\n");
		exit(EXIT_ERROR);
	}
	return(result);
};

//================================================//
template <class T>
posicion Lista<T>::anterior(posicion p) {
	posicion result;
	if((p>0) && (p<=ultimo+1)) {
			result = p-1;
	} else {
		fprintf(stderr,"\nHa intentado obtener el anterior de una posicion invalida\n");
		exit(EXIT_ERROR);
	}
	return(result);
};

//================================================//
template <class T>
posicion Lista<T>::primer() {
	return(0);
};

//================================================//
template <class T>
posicion Lista<T>::fin() {
	return(ultimo+1);
};

//================================================//
template <class T>
posicion Lista<T>::localizar(T x) {
	int i;
	for(i=0;((elementos[i]!=x)&&(i<=ultimo));i++);
	return(i);
};

//================================================//

template<class T>
void Lista<T>::vaciar() {
	ultimo = -1;
	cant = 0;
}

//================================================//
template<class T>
void Lista<T>::ordInsert(T x)
{
    int i;
    for (i = 0; i <= ultimo && x > elementos[i]; i++);
    insertar(x, i);
    return;
}

//================================================//
template<class T>
void Lista<T>::catList(Lista<T> l2)
{
    for (int i = 0; i <= l2.ultimo && cant < CANTELE; i++){
        elementos[++ultimo] = l2.elementos[i];
        cant++;
    }
    return;
}

//================================================//
template<class T>
void Lista<T>::insList(int orden, Lista<T> l2)
{
    if (0 <= --orden && orden <= ultimo + 1)
        for (int i = 0; i <= l2.ultimo && cant < CANTELE; i++)
            insertar(l2.elementos[i], i + orden);
    return;
}

//================================================//
template<class T>
Lista<T> Lista<T>::invList()
{
    Lista<T> inv;
    int n = ultimo / 2;

    for (int i = 0; i <= n; i++){
        inv.elementos[i] = elementos[ultimo - i];
        inv.elementos[ultimo - i] = elementos[i];
    }
    inv.ultimo = ultimo;
    inv.cant = cant;

    return inv;
}

//================================================//
template<class T>
Lista<T> Lista<T>::invList(posicion p)
{
    Lista<T> inv;
    int i, n = (p + ultimo) / 2;

    if (p < 0 || ultimo + 1 < p){
        fprintf(stderr, "\nHa intendado invertir en una posicion invalida\n");
		exit(EXIT_ERROR);
    }

    for (i = 0; i < p; i++)
        inv.elementos[i] = elementos[i];
    if (i <= ultimo){
        p += ultimo;
        for (i; i <= n; i++){
            inv.elementos[i] = elementos[p - i];
            inv.elementos[p - i] = elementos[i];
        }
    }
    inv.ultimo = ultimo;
    inv.cant = cant;

    return inv;
}

//================================================//
template<class T>
Lista<T> Lista<T>::difList1(Lista<T> l2)
{
    Lista<T> dif;
    int j;

    for (int i = 0; i <= ultimo; i++){
        for (j = 0; j <= l2.ultimo && l2.elementos[j] != elementos[i]; j++);
        if (j <= l2.ultimo)
            l2.eliminar(j);
        else
            dif.elementos[++dif.ultimo] = elementos[i];
    }
    dif.cant = dif.ultimo + 1;

    return dif;
}

//================================================//
template<class T>
Lista<T> Lista<T>::difList2(Lista<T> l2)
{
    Lista<T> dif;
    int j;

    for (int i = 0; i <= ultimo; i++){
        for (j = 0; j <= l2.ultimo && l2.elementos[j] != elementos[i]; j++);
        if (j > l2.ultimo)
            dif.elementos[++dif.ultimo] = elementos[i];
    }
    dif.cant = dif.ultimo + 1;

    return dif;
}

//================================================//
template<class T>
Lista<T> Lista<T>::itcList(Lista<T> l2)
{
    Lista<T> itc;
    int j;

    for (int i = 0; i <= ultimo; i++){
        for (j = 0; j <= l2.ultimo && l2.elementos[j] != elementos[i]; j++);
        if (j <= l2.ultimo){
            itc.elementos[++itc.ultimo] = elementos[i];
            l2.eliminar(j);
        }
    }
    itc.cant = itc.ultimo + 1;

    return itc;
}

//================================================//
template<class T>
void Lista<T>::operator+(Lista<T> l2)
{
    this->catList(l2);
    return;
}

//================================================//
template<class T>
Lista<T> Lista<T>::operator-(Lista<T> l2)
{
    return this->difList1(l2);
}

//================================================//
template<class T>
Lista<T> Lista<T>::operator*(Lista<T> l2)
{
    return this->itcList(l2);
}

//================================================//
template<class T>
Lista<T> Lista<T>::subList(unsigned char i, unsigned char len)
{
    Lista<T> sub;
    int n = --i + len;

    if (0 <= i && i <= ultimo){
        for (int j = i; i < n && j <= ultimo; j++)
            sub.elementos[++sub.ultimo] = elementos[j];
        sub.cant = sub.ultimo + 1;
    }

    return sub;
}

//================================================//
template <class T>
Lista<T> Lista<T>::mixList (Lista<T> l2) ///Falta controlar CANTELE
{
Lista <T> lista;
posicion p1, p2;
    for(p1=0, p2=0; p1<=ultimo && p2<=l2.ultimo; p1++, p2++){
        lista.elementos[++lista.ultimo]=elementos[p1];
        lista.elementos[++lista.ultimo]=elementos[p2];
    }
    for(p1; p1<=ultimo; p2++)
        lista.elementos[++lista.ultimo]=elementos[p1];
    for(p2; p2<=l2.ultimo;p1++)
        lista.elementos[++lista.ultimo]=elementos[p2];
    lista.cant=lista.ultimo + 1;
return lista;
}

//================================================//
template<class T>
void Lista<T>::ordenar(void)
{
    int i, j;
    T aux;

    for (i = 1; i < cant; i++)
        for (j = 0; j < cant - i; j++){
            if (elementos[j + 1] < elementos[j]){
                aux = elementos[j + 1];
                elementos[j + 1] = elementos[j];
                elementos[j] = aux;
            }
        }

    return;
}

#endif // LISTAA_H

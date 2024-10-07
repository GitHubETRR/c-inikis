#include <iostream>

using namespace std;
int func1(void);
int func2(void);

int func3 (int []);
int (*funcs[])()={func1,func2};
int (**funcsi)()=funcs;
int main (void){
    (funcsi)[0](); //funcsi, a pesar de ser un puntero, esta apuntando a la 1ra posicion de la lista de funcs, por lo que se puede interpretar como un array.
    funcsi++; //en el anterior contexto hubiese sido funcs[1]();, solo aumento el puntero el tamaño necesario (pointer math)
    (*funcsi)();

    (int) funcs[0]();
    (int) funcs[1]();
    return 0;
}

int func1(void){
    cout<<"Hola"<<endl;
    return 0;
}
int func2(void){
    cout<<"chau"<<endl;
    return 0;
}

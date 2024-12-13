#include <iostream>

//PUNTERO 1: int(*x())[20]
//
//func es una funcion que devuelve un puntero a un array de 20 ints
int (*func())[20]{
    static int array[20];
    return &array;
};

//PUNTERO 2: int (*(*x)[])()
//
//punt es un puntero a un array de punteros a funciones que devuelven
//un entero
int (*(*punt)[])() = nullptr;


int func_int1(){
    return 5;
};

int func_int2(){
    return 10;
};

//PUNTERO 3: char *(*(*x[][8])())[]
//
//punt_array es un array que cada uno tiene un array de 8 elementos que son
//punteros a funciones que devuelven punteros a arrays con punteros a chars
//como elemento
char *(*(*punt_array[][8])())[];

int main(void){
    //implementacion de PUNTERO 1
    std::cout<<"Implementacion de puntero 1"<<std::endl;
    int (*array)[20] = func();
    for(int i=0; i<=sizeof(*array)/sizeof(int); i++){
        *array[i] = i;
        std::cout<<i<<std::endl<<"\t"<<*array[i]<<std::endl;
    }

    //implementacion de PUNTERO 2
    std::cout<<"Implementacion de puntero 2"<<std::endl;
    //array de punteros a funciones que devuelven int
    int (*array_func_int[])()={&func_int1,func_int2};
    std::cout<<array_func_int[0]()<<std::endl;

    punt = &array_func_int;

    //implementacion de PUNTERO 3
    std::cout<<"Implementacion de puntero 2"<<std::endl;
    

    return 0;
}

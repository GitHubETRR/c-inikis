struct alumno_t{
    long nmat;
    char nombre[41];
};

struct alumno_t delegado;

void permutar (int *i, int *j) { int temp; temp = *i; *i = *j; *j = temp; }

// Ejemplo de función sobrecargada
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

#include "puntos.h"

inline void string_copy(char *copia, const char *original){
    strcpy(copia, original);
}

inline void string_copy(char *copia, const char *original, const int longitud){
    strncpy(copia, original, longitud);
}

static char string_a[20], string_b[20];

template<typename T>
void print_template(T value){
    cout << value << endl;
};

void incr_ref(int& value);

int main(){
    //for(int i = 0; int var == 2; 1){}

    {
        double x = 2.0;
        printf("%f", x);                    // se imprime    2.0
        {
            printf("%f", x);                // se imprime    2.0
            double x = 3.0;
            printf("%f", x);                // se imprime    3.0
        }
        printf("%f", x);                    // se imprime    2.0
    }
    const int SIZE = 5;
    char var[SIZE];
    
    int i = 2; //si i fuese const int, int *p no puede ser asignado a eso. 
    int *p;
    p = &i;
    *p = 3;
    printf("\ni = %d", i);
    
    double x = 10;
    double y = 7;
    float coc = 10/7;
    printf("\n%d", int(coc));
    
    string_copy(string_a, "Aquello");
    string_copy(string_b, "Esto es una cadena", 4);
    cout << string_b << " y " << string_a << endl;
    // La última sentencia es equivalente a un printf() de C
    //   y se explica en un próximo apartado de este manual

    char nombre;
    int num=2;
    cout << "Introduzca el nombre del fichero\a " << num << ": " << endl;

    cout << "HOLA MUNDO!!!" << endl;

    int hex_var=16;

    cout << "un valor en hexa: " << hex << hex_var << endl;
    cout << "otro mas: " << setbase(0) << hex_var << endl;

    struct struct_puntos{
        int x;
        int y;
    };

    struct_puntos mi_str_pnt;
    struct_puntos* str_pnt_ref = &mi_str_pnt;
    int ref_x=(*str_pnt_ref).x;
    int ref_y=str_pnt_ref->y;

    clase_puntos punto(10,20);
    punto.definir_x(10);

    clase_puntos punto2;
    punto.definir_x(50);
    punto2.definir_y(104);
    punto2.mostrar();
    punto2.mover();
    punto2.mostrar();
    punto2.mover(13,40);
    punto2.mostrar();

    ofstream out ("fichero.txt");
    out << "Estamos aprendiendo ";
    out << "como se escribe en un fichero ";
    out << "y como se lee desde el.";
    out.close();

    ifstream in("fichero.txt");

    const int LINE_SIZE=81;
    char line[LINE_SIZE];
    in.getline(line, LINE_SIZE);
    cout << line << endl;
    in.getline(line, LINE_SIZE);
    cout << line << endl;
    in.getline(line, LINE_SIZE);
    cout << line << endl;

    clase_puntos la_suma = punto + punto2;
    //delete(&la_suma);

    auto strings={"pepe","agua","lolo","bruh"};
    for (auto x:strings){
        cout<<x<<endl;
    }

    clase_puntos punto_original(15,20);
    clase_puntos punto_copia=punto_original;
    punto_copia.mostrar();

    print_template(10);

    int valor_incr=5;
    incr_ref(valor_incr);
    printf("valor original despues de incremento: %d\n",valor_incr);
        
}

//incrementar el valor referenciado por value
void incr_ref(int& value){
    value++;
}

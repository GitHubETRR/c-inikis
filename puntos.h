#include <iostream>
#include <string.h>
//using namespace std; NO USAR USING NAMESPACE EN HEADERS

class clase_puntos{
    private:
        int x;
        int y;
    public:
        clase_puntos(int new_x, int new_y);     //value constructor
        clase_puntos();  
        ~clase_puntos();                       
        void definir(int new_x, int new_y); 
        void definir_x(int new_x);
        void definir_y(int new_y);
        void mover(int desp_x=1, int desp_y=1);
        void mostrar();
        clase_puntos operator+(clase_puntos);
};

//constructores
clase_puntos::clase_puntos(int new_x, int new_y): x(new_x), y(new_y) {}
clase_puntos::clase_puntos(): x(0), y(0) {}

//destructor
clase_puntos::~clase_puntos(){
    printf("rip bozo\n");
}

//metodos
void clase_puntos::definir(int new_x, int new_y){
    if (x < 1000 && x > -1000)x=new_x;
    else{printf("x must be between 1000 & -1000");}

    if (y < 1000 && y > -1000)y=new_y;
    else{printf("y must be between 1000 & -1000");}
}

void clase_puntos::definir_x(int new_x){
    if (x < 1000 && x > -1000)x=new_x;
    else{printf("x must be between 1000 & -1000");}            
}

void clase_puntos::definir_y(int new_y){
    if (y < 1000 && y > -1000)y=new_y;
    else{printf("y must be between 1000 & -1000");}
}

void clase_puntos::mover(int desp_x, int desp_y){
    x += desp_x;
    y += desp_y;
}

inline void clase_puntos::mostrar(){
    cout << "x: " << x << " y: " << y << endl;
}

clase_puntos clase_puntos::operator+(clase_puntos sumando){
    clase_puntos suma(x+sumando.x, y+sumando.y);
    mostrar();
    sumando.mostrar();
    suma.mostrar();
    return suma;
}

#include <iostream>
#include <string.h>

#define SALARIO_BASE 5000

class empleado{
    private:
        const char* nombre;
        unsigned int edad;
        unsigned int salario;
    public:
        //const y destr
        empleado(const char* newNombre, unsigned int newEdad, unsigned int newSalario);
        empleado();
        ~empleado();

        //getters y setters
        void asignarNombre(const char* newNombre);
        const char* getNombre();

        void asignarEdad(unsigned int newNombre);
        unsigned int getEdad();

        void asignarSalario(unsigned int newNombre);
        unsigned int getSalario();
        virtual int calcularSalario(int diasLaborales);
};

empleado::empleado(const char* newNombre, unsigned int newEdad, unsigned int newSalario)
    : nombre(newNombre), edad(newEdad), salario(newSalario) {}
empleado::empleado()
    : nombre("Empleado Sin Nombre"), edad(0), salario(0) {} //constructor default

empleado::~empleado(){
    printf("Se murio el empleado %s, hoy no se trabaja\n", nombre);
}


void empleado::asignarNombre(const char* newNombre){
    nombre=newNombre;
}

inline const char* empleado::getNombre(){
    return nombre;
}

void empleado::asignarEdad(unsigned int newEdad){
    edad=newEdad;
}

inline unsigned int empleado::getEdad(){
    return edad;
}

void empleado::asignarSalario(unsigned int newSalario){
    salario=newSalario;
}

inline unsigned int empleado::getSalario(){
    return salario;
}

int empleado::calcularSalario(int diasLaborales){
    asignarSalario(diasLaborales * SALARIO_BASE);
}

class empleadoFijo : public empleado{
    private:
        unsigned int honorario = 1000;
    public:
        using empleado::empleado;

        int calcularSalario(int diasLaborales) override;
};

int empleadoFijo::calcularSalario(int diasLaborales) {
    asignarSalario(diasLaborales * SALARIO_BASE + honorario);
}

class empleadoTemporal : public empleado{
    private:
        unsigned int honorario = 500;
        unsigned int diasDisponibles = 10; //para esta compañia, todos los empleados tienen max 10 dias de trabajo temporal
    public:
        using empleado::empleado;

        int calcularSalario(int diasLaborales) override;
};

int empleadoTemporal::calcularSalario(int diasLaborales){
    if (diasLaborales<diasDisponibles){
        asignarSalario(diasLaborales * SALARIO_BASE + honorario);
    }
    else{
        printf("Este empleado ya excedio sus dias laborales disponibles (10).");
    }
}

class freelancer : public empleado{
    private:
        unsigned int honorario = 1000;
        unsigned int bonus_freelance = 25/100; //el freelancer tiene un bonus por ser freelance ;)
    public:
        using empleado::empleado;

        int calcularSalario(int diasLaborales) override;
};

int freelancer::calcularSalario(int diasLaborales){
    asignarSalario(diasLaborales * SALARIO_BASE + honorario * (1+bonus_freelance)); //tiene un bonus de 125%
}

int main(void){
    empleado lista_empleados[4];
    lista_empleados[0] = empleado("Jorge", 25, 560000);;
    lista_empleados[1] = empleadoFijo("Pepe", 45, 300000);;
    lista_empleados[2] = empleadoTemporal("Nacho", 18, 211500);;
    lista_empleados[3] = freelancer("Facundo", 22, 150000);;

    std::cout << "Esta compania tiene los siguientes empleados:" << std::endl;
    for (int i = 0; i <= 3; i++){
        std::cout << "\t "
            << lista_empleados[i].getNombre() 
            << " de edad " << lista_empleados[i].getEdad() 
            << " y un salario de " << lista_empleados[i].getSalario() 
            << "." << std::endl;
    }

}

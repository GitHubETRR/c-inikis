/*leer 2 valores y cout:
    1. la suma 
    2. resta
    3. producto
    4. division 
    5. promedio 
    6. doble producto menos mitad doble producto segundo
*/

#include <iostream>
using namespace std;

inline int suma(int,int);
inline int resta(int,int);
inline int producto(int,int);
inline float division(int,int);
inline float promedio(int,int);
inline float dobleprod(int,int);

int main(){
    float x;
    float y;
    cout<<"Ingrese dos valores:"<<endl;
    cin>>x;
    cin>>y;
    printf("%d + %d = %d\n", x, y, suma(x,y));
    printf("%d - %d = %d\n", x, y, resta(x,y));
    printf("%d * %d = %f\n", x, y, producto(x,y));
    printf("%d / %d = %f\n", x, y, division(x,y));
    printf("%d promediado sobre %d (x+y) = %f", x, x+y, promedio(x,y));
    printf("doble producto de %d menos la mitad de %d = %f",x,y,dobleprod(x,y));
}

int suma(int x,int y){
    return x+y;
}

int resta(int x, int y){
    return x-y;
}

int producto(int x, int y){
    return x*y;
}

float division(int x, int y){
    return (float)x/y;
}

float promedio(int x, int y){
    return (float)x/(y+x);
}

float dobleprod(int x, int y){
    return 2*x - y/2;
}

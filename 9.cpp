/*
leer 2 valores y cout:
    1. la suma 
    2. resta
    3. producto
    4. division 
    5. promedio 
    6. doble producto menos mitad doble producto segundo
*/

#include <iostream>
using namespace std;

inline float suma(float,float);
inline float resta(float,float);
inline float producto(float,float);
inline float division(float,float);
inline float promedio(float,float);
inline float dobleprod(float,float);

int main(){
    float x;
    float y;
    cout<<"Ingrese dos valores:"<<endl;
    cin>>x;
    cin>>y;
    printf("%2.1f + %2.1f = %2.1f\n", x, y, suma(x,y));
    printf("%2.1f - %2.1f = %2.1f\n", x, y, resta(x,y));
    printf("%2.1f * %2.1f = %2.1f\n", x, y, producto(x,y));
    printf("%2.1f / %2.1f = %2.1f\n", x, y, division(x,y));
    printf("%2.1f promediado sobre %2.1f (%2.1f + %2.1f) = %2.1f\n", x, x+y, x, y, promedio(x,y));
    printf("doble producto de %2.1f menos la mitad de %2.1f = %2.1f\n",x,y,dobleprod(x,y));

    return 0;
}

inline float suma(float x,float y){
    return x+y;
}

inline float resta(float x, float y){
    return x-y;
}

inline float producto(float x, float y){
    return x*y;
}

inline float division(float x, float y){
    return (float)x/y;
}

inline float promedio(float x, float y){
    return (float)x/(y+x);
}

inline float dobleprod(float x, float y){
    return 2*x - y/2;
}

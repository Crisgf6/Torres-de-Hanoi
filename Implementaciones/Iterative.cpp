#include <iostream>
#include <math.h>
#include <ctime>
#include <vector>
#include <numeric>

using namespace std;

int disc(int i){ //Devuelve el disco a mover
    int cont;
    int x= i+1; //Ya que el bucle empieza en 0
    for(cont=0;x%2==0;cont++){ //Divisiones continuas entre 2 hasta que sea impar
        x/=2;
    }
    return cont; //Devuelve el contador
}

int movimientos(int i, int d) { //Veces que el disco se ha movido antes de la iteración i
    while(d!=0){
        d--;
        i/=2;
    }
    return (i+1)/2;
}

int direccion(int d,int n) { //Cada disco se mueve en la misma dirección CW=1, ACW=2 (clockwise/anticlockwise)
    return 2 - (n + d)%2;
}

int main(){
    vector<double> medias;
    for(int n=3;n<30;n++){
        vector<double> times;
        for (int i=0; i<10; i++) {
            int t0 = clock();
            
            int limit = pow(2,n)-1; //Numero de iteraciones 
            for(int i=0;i<limit;i++){
                int disco = disc(i); //Disco a mover
                int origen = (movimientos(i,disco)*direccion(disco,n))%3; //Torre origen (en esta implementacion, la torre auxiliar es la 3)
                int destino = (origen + direccion(disco,n))%3; //Torre destino
            }
            
            int t1 = clock();
            double time = (double(t1-t0)/CLOCKS_PER_SEC);
            times.push_back(time);
        }
        //Cálculo de la media
        double medium = accumulate(times.begin(), times.end(), 0)/times.size();
        medias.push_back(medium);
    }
    int cont = 3;
    for(int i=0;i<medias.size();i++){
        cout << "Tiempo medio con " << cont << " discos = " << medias[i] << endl;
        cont++;
    }
    return 0;
}



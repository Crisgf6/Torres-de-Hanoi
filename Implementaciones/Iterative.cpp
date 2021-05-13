#include <iostream>
#include <math.h>
#include <ctime> 

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

void msg(int disco, int origen, int destino) {
    cout<<"Mover el disco "<<disco+1<<" desde "<<origen+1<<" hasta "<<destino+1<<endl;
}

int main(){
    unsigned t0, t1;
    t0=clock();
    
    int n;
    cout<<"Los Torres son 1 2 3\n";
    cout<<"Cantidad de discos: ";
    cin>>n;
    int limit = pow(2,n)-1; //Numero de iteraciones 
    for(int i=0;i<limit;i++){
        int disco = disc(i); //Disco a mover
        int origen = (movimientos(i,disco)*direccion(disco,n))%3; //Torre origen (en esta implementacion, la torre auxiliar es la 3)
        int destino = (origen + direccion(disco,n))%3; //Torre destino
        msg(disco,origen,destino);
    }
    cout<<limit<<" movimientos"<<endl;
    
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}

#include <iostream>
 
using namespace std; 
 
#define TORRE_INICIAL 1
#define TORRE_AUXILIAR 2
#define TORRE_FINAL 3

int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal, int &t1, int &t2, int &t3);
void muestra(int t1, int t2, int t3);

int main(){
    int t1=0,t2=0,t3=0,maxdiscos;
    int cantDiscos, movimientos;
    cout<<"Cantidad de discos: ";
    cin>>cantDiscos;
    cout<<"\n_________________________________________ \n";
    t1=cantDiscos;
    maxdiscos = cantDiscos;
    cout<<"La Torre:\n";
    muestra(t1, t2, t3);
    cout<<"\n_________________________________________\nLa serie de movimientos a realizar es:\n";
    movimientos = hanoi(cantDiscos, TORRE_INICIAL, TORRE_AUXILIAR, TORRE_FINAL, t1, t2, t3);
    cout<<"\n\n"<<movimientos<<" movimientos\n";
    return 0;
}

int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal, int &t1, int &t2, int &t3){
    static int cont = 0;
    if(numDiscos == 1){
        cout<<"\n\n"<<cont+1<<")Mover el disco superior de la torre "<<torreInicial<<" a la torre "<<torreFinal<<"\n";
        cont++;
        
        if(torreInicial==1)
            t1--;
        if(torreInicial==2)
            t2--;
        if(torreInicial==3)
            t3--;
        if(torreFinal==1)
            t1++;
        if(torreFinal==2)
            t2++;
        if(torreFinal==3)
            t3++;
            
        muestra(t1, t2, t3);
    }
    else{
        hanoi(numDiscos - 1, torreInicial, torreFinal, torreAuxiliar, t1, t2, t3);
        cout<<"\n\n"<<cont+1<<")Mover el disco superior de la torre "<<torreInicial<<" a la torre "<<torreFinal<<"\n";
        cont++;
        
        if(torreInicial==1)
            t1--;
        if(torreInicial==2)
            t2--;
        if(torreInicial==3)
            t3--;
        if(torreFinal==1)
            t1++;
        if(torreFinal==2)
            t2++;
        if(torreFinal==3)
            t3++;
            
        muestra(t1, t2, t3);
        hanoi(numDiscos - 1, torreAuxiliar, torreInicial, torreFinal, t1, t2, t3);
    }
    return cont;
}

void muestra(int t1, int t2, int t3){
    cout<<"\n\tTorre1:";
    for(int i=1;i<=t1;i++){
        cout<<"*";
    }
    cout<<"\n\tTorre2:";
    for(int i=1;i<=t2;i++){
        cout<<"*";
    }
    cout<<"\n\tTorre3:";
    for(int i=1;i<=t3;i++){
        cout<<"*";
    }
}
#include <iostream>
#include <ctime> 

using namespace std;

void hanoi(int num, int a, int c, int b, int &cont){  //Se pasa el contador por referencia para poder mostrar el numero de movimientos al final del programa
    if(num==1){
        cout<<"Mover el disco "<<num<<" desde "<<a<<" hasta  "<<c<<endl;
        cont++;
    }
    else{
        hanoi(num-1,a,b,c,cont);
        cout<<"Mover el disco "<<num<<" desde "<<a<<" hasta  "<<c<<endl;
        cont++;
        hanoi(num-1,b,c,a,cont);
    }
}
 
int main(){
    unsigned t0, t1;
    t0=clock();
    
    int n;
    int cont = 0;
    cout<<"Los Torres son 1 2 3\n";
    cout<<"Cantidad de discos: ";
    cin>>n;
    hanoi(n,1,3,2,cont);
    cout<<cont<<" movimientos"<<endl;
    
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}

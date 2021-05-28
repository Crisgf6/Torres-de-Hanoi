#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>
#include <stack>

using namespace std;

void hanoi(int n, stack<int>& origen, stack<int>& destino, stack<int>& auxiliar) {
    if (n == 1) {
        int top = origen.top();
        destino.push(top);
        origen.pop();
        return;
    }
    else {
        //Mover n-1 discos de la torre origen a la torre auxiliar
        hanoi(n - 1, origen, auxiliar, destino); //llamada recursiva
        //Mover un disco de la torre origen a la torre destino
        int top = origen.top();
        destino.push(top);
        origen.pop();
        //Mover n-1 discos de la torre auxiliar a la torre destino
        hanoi(n - 1, auxiliar, destino, origen);
    }
    return;
}

int main() {
    vector<double> medias;
    for (int n = 3;n <= 30;n++) {
        vector<double> times;
        for (int i = 0; i < 10; i++) {
            int t0 = clock();

            stack<int> origen;
            stack<int> destino;
            stack<int> auxiliar;

            //llenando la pila de origen con los discos
            for (int i = 0; i < n; i++) {
                origen.push(n - i);
            }

            hanoi(n, origen, destino, auxiliar);

            int t1 = clock();
            double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
            times.push_back(tiempo);
        }
        //Cálculo de la media
        double medium = accumulate(times.begin(), times.end(), 0) / times.size();
        medias.push_back(medium);
    }
    int cont = 3;
    for (int i = 0;i < medias.size();i++) {
        cout << "Tiempo medio con " << cont << " discos = " << medias[i] << endl;
        cont++;
    }
    return 0;
}
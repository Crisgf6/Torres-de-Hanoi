# Torres de Hanoi

*“Dice la leyenda que, al crear el mundo, Dios situó sobre la Tierra tres varillas de diamante y sesenta y cuatro discos de oro que darían paso al fin del mundo cuando los monjes terminen su tarea…”*

<img src="https://github.com/Crisgf6/Torres-de-Hanoi/blob/main/assets/hanoi.PNG" width="400" height="auto">

**Ciudad de Benares (India), hoy Varanasi, donde la leyenda de “La Torre de Hanoi” sitúa el gran templo. En la foto se puede ver a los peregrinos en los ghats (escaleras de piedra que descienden hasta el Ganges) realizando sus baños purificadores en el río, a la vez que rinden tributo al dios del Sol Surya**
#
# Desarrollo del trabajo
*1. Introducción*

A lo largo de este segundo cuatrimestre, conforme he ido avanzando en la signatura y en las practicas, he ido adquiriendo habilidades y experiencia en la algoritmia de C++. A modo de evaluación final, se me pide realizar un trabajo que pone a prueba mis habilidades.

El trabajo consiste en resolver el problema de las torres de Hanoi de manera iterativa y de manera recursiva, así como realizar una comparativa de coste temporal de las dos implementaciones.

Para este proyecto he realizado el código de los dos algoritmos y luego también he hecho un código que resuelve las torres de Hanoi de una manera más visual.

*2. Estudio*

*	El disco pequeño se debe mover siempre cíclicamente en el mismo sentido: hacia la derecha (de A a B, de B a C y de C a A) o hacia la izquierda (de A a C, de C a B y de B a A), según el número de discos sea par o impar respectivamente.
*	El disco pequeño se debe colocar siempre, bien sobre un disco de número par, bien como único disco en el poste de destino (C) si el número de discos es impar o en el otro (B) si es par.
*	Si n es par, mueve el disco 1 hacia la derecha. Si es impar, muévelo hacia la izquierda.
*	Si todos los discos están en C, fin. Si no, mueve un disco que no sea el 1 y vuelve al paso 1.

Para obtener los siguientes resultados, he realizado 10 ejecuciones para cada implementación (con cada disco) y realizado una media del tiempo (en segundos) de ejecución para tratar de reducir el error.

**Esquema de los cálculos:**

<img src="https://github.com/Crisgf6/Torres-de-Hanoi/blob/main/assets/results.jpg" width="600" height="auto">

**Tabla de resultados:**

<img src="https://github.com/Crisgf6/Torres-de-Hanoi/blob/main/assets/tabla.PNG" width="auto" height="auto">

*3. Conclusiones*

El algoritmo iterativo posee 3 ciclos. El primero se encarga del número de iteraciones, el segundo continua la división por 2 y el ultimo verifica cuantas veces se ha movido el disco antes. Esto los hace poseer un orden que los hace más eficientes que los recursivos. La implementación recursiva posee solo 1 ciclo if que verifica si existe ingresado un disco para proceder con el ordenamiento.

El algoritmo iterativo es más lento en tiempo de ejecución. Posee un orden que los hace más entendibles que los recursivos. La implementación recursiva, en cambio, es más rápida en su ejecución y posee un código más sencillo que lo que hace es repetir el ciclo con cada 1 de los discos haciendo más corto el tiempo ya que no depende de una “iteración”.

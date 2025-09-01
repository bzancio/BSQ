# BSQ
Proyecto BSQ

# Estructura archivos

- parser.c → leer archivo, validar, guardarlo.
- solver.c → algoritmo del cuadrado.
- print.c → imprimir resultado.
- utils.c → funciones auxiliares (ft_putstr, ft_strlen, etc.).
- bsq.c → main e inicio del programa.
- bsq.h → incluimos librerias y prototipos.
- Makefile → para compilar y limpiar de forma comoda.

He pensado que seria buena idea gestionar cada argumento como una estructura con todos los datos necesarios para resolver cada mapa y asi gestionar cada cosa por separado, asi que habria que crear un array de estructuras y comprobar errores por cada una de ellas.

# Logica:

---

#### 1 Caso
-----
.

#### 2 Caso
-----
..
..

#### 3 Caso
-----
...
...
...

#### 4 Caso
-----
....
....
....
....

#### 5 Caso
-----
.....
.....
.....
.....
.....

#### 6 Caso
-----



## Notas
----
- Generar el archivo(mapa) por defecto con las funciones, read y ello.
- **Caso 1** siempre esta.
- Caso 2

## Notas extra
----
- Primero recorrer el array, para saber donde estan los caracteres obstaculos y en que posicion (j), sabiendo
donde estan podemos saber lo maximo que podemos generar en un cuadrado perfecto.
- El i y j deben ser iguales, osea debe haber un contador que  cuente cuantos count_x y count_j deben ser iguales, mientras vaya recorriendo el array y si cumple
es un cuadrado perfecto, en caso haya un obstacullo, el contador i,j se reinicia y fuera.
- Maximo caso posible seria el tamaño definido. Si es un cuadrado de 9 sera 9, si no existiera obstaculos.
- ¿backtracking??

- Segun mi
## Mapa
----
La primera línea del mapa contiene la información para leer el mapa:
* El número de líneas del mapa;
* El carácter "vacío";
* El carácter "obstáculo";
* El carácter "lleno";

# 🟩 BSQ – Biggest Square

![C](https://img.shields.io/badge/language-C-blue.svg)
![42 Piscine](https://img.shields.io/badge/42-Piscine-success.svg)
![Status](https://img.shields.io/badge/status-Prepared%20for%20Gallery-informational.svg)

---

## 📜 Descripción

**BSQ (Biggest Square)** es una implementación en C del clásico ejercicio de la Piscina de 42: encontrar el **mayor cuadrado posible sin obstáculos** dentro de un mapa rectangular dado en un fichero de texto y marcar dicho cuadrado usando el carácter `full`.

Este repositorio está pensado para mostrar:
- Lectura y validación robusta de entrada,
- Manejo de memoria dinámica en C,
- Algoritmo en **programación dinámica** para resolución óptima,
- Pruebas automatizadas y utilidades para iterar rápidamente.

---

## 📁 Formato del mapa

- **Primera línea**: número de filas seguido de 3 caracteres (sin separador):
  - El penúltimo carácter = `full`
  - El antepenúltimo carácter = `obstacle`
  - El ante-antepenúltimo (al inicio) = `empty`
  > Ejemplo: `9.ox` → `rows=9`, `empty='.'`, `obstacle='o'`, `full='x'`

- **Siguientes líneas**: las filas del mapa, todas con la misma longitud (rectangular).

**Ejemplo de entrada**:

```
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

**Salida esperada**: el mismo mapa, pero con el mayor cuadrado sustituido por `full` (`x` en el ejemplo).

---

## 🧭 Estructura del repositorio

```
.
├─ Makefile
├─ README.md
├─ runner.sh           # script para ejecutar tests en bsq_tests/
├─ bsq.c
├─ solver.c
├─ parser.c
├─ algo.c
├─ print.c
├─ utils.c
├─ utils2.c
├─ free_utils.c
├─ empty_utils.c
├─ bsq.h
└─ bsq_tests/          # colección de mapas de prueba
```

Descripción breve de archivos clave:

- `bsq.c` — `main`, gestión de ficheros y saltos entre múltiples mapas.
- `solver.c` — flujo principal (`ft_solve_bsq`): lectura, validación, resolución e impresión.
- `parser.c` — parseo de cabecera y lectura del mapa crudo.
- `algo.c` — implementación del algoritmo DP (matriz `dp`) y marcado del cuadrado.
- `utils*.c` — funciones auxiliares (`ft_strjoin`, `ft_split`, `ft_atoi`, `ft_strlen`, etc.).
- `free_utils.c` — funciones para liberar `char **` e `int **`.
- `runner.sh` — script que automatiza la ejecución sobre `bsq_tests/`.

---

## 🔧 Compilación y uso

```bash
# Compilar
make

# Ejecutar con uno o varios ficheros
./bsq map1.txt map2.txt

# Leer desde stdin
cat map.txt | ./bsq

# Limpiar
make clean
make fclean
```

---

## 🧪 Ejemplo rápido

Archivo `example.txt`:

```
5.ox
.....
..o..
.....
.o...
.....
```

Ejecución:

```bash
./bsq example.txt
```

Salida: el mapa impreso por stdout con el mayor cuadrado marcado en `x`.

---

## 🧠 Algoritmo (en una frase)

Se usa **programación dinámica**: para cada celda `(i,j)` la tabla `dp[i][j]` guarda el lado máximo de cuadrado con esquina inferior derecha en `(i,j)`. Si la celda es `obstacle` → 0; en borde → 1; en otro caso → `1 + min(top, left, top-left)`.

**Complejidades**:
- Tiempo: `O(rows * cols)`
- Memoria: `O(rows * cols)` (se puede optimizar a `O(cols)`)

Fragmento clave:

```c
if (map[i][j] == obstacle)
    dp[i][j] = 0;
else if (i == 0 || j == 0)
    dp[i][j] = 1;
else
    dp[i][j] = 1 + ft_min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
```

---

## ⚠️ Casos límite y validaciones

El programa valida y falla (imprime `map error\n`) para:
- Cabecera inválida (menos de 4 caracteres, caracteres no imprimibles, caracteres repetidos entre `empty`, `obstacle`, `full`),
- Filas con longitudes diferentes,
- Filas vacías o líneas vacías intercaladas,
- Mapa mal formado (número de filas no coincide con lo declarado),
- **Mapas sin casillas vacías** (comportamiento actual: `map error`).

> **Nota**: La última validación es la que me llevó a fallar el proyecto: si el mapa está **completamente lleno de obstáculos**, el binario actual imprime `map error`. Dependiendo del especificado por el evaluador, la salida correcta puede ser aceptar el mapa y devolverlo sin cambios (no hay cuadrado que pintar).

---

## 🧩 Reproducir el fallo (mapa lleno de obstáculos)

Archivo `full_obstacles.txt`:

```
3.ox
ooo
ooo
ooo
```

Ejecución:

```bash
./bsq full_obstacles.txt 2>&1 | sed -n '1p'
# Salida actual:
# map error
```

**Explicación**: `solver.c` actualmente valida `!ft_map_has_empty(map)` y trata ese caso como error.

---

## 🧰 Testing local / automatizado

El script `runner.sh` (incluido) permite ejecutar el binario contra todos los mapas en `bsq_tests/` y comprobar si aparece `map error` en stderr para cada uno.

Uso:

```bash
./runner.sh ./bsq
```

---
---

## ✍️ Autores

**Izan Buil y Sergio Romero** — 42 Madrid (Piscina Agosto 2025)  

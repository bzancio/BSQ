# 🟩 BSQ – Biggest Square

## 📜 Resumen del proyecto

El proyecto **BSQ** consiste en encontrar el **mayor cuadrado posible sin obstáculos** en un mapa rectangular definido en un archivo de texto.  
El cuadrado se marca en el mapa usando un carácter especial (`full`).

### 🗂 Formato del mapa

- **Primera línea**: contiene número de filas y tres caracteres especiales (`empty`, `obstacle`, `full`).  
- **Siguientes líneas**: representan el mapa, cada fila con la misma longitud.  

**Ejemplo**:

```text
9.ox
...........................
...o.......................
..............o............
...............o...........
...........................
...........................
........o..................
.....................o.....
...........................
```


- `.` → `empty`  
- `o` → `obstacle`  
- `x` → `full`  

---

## 🏗 Estructura de archivos

| Archivo       | Contenido / Función principal |
|---------------|------------------------------|
| `bsq.c`       | `main`: gestión de archivos, llamadas a `ft_solve_bsq` y manejo de errores. |
| `parser.c`    | Lectura de info de filas (`ft_read_info`), lectura cruda (`ft_read_raw_map`) y conversión a estructura (`ft_read_map`). |
| `utils.c`     | Funciones auxiliares: `ft_putstr`, `ft_puterr`, `ft_strlen`, `ft_atoi`, `ft_strjoin`. |
| `utils2.c`    | Declaración de `ft_split` (pendiente de implementar). |
| `solver.c`    | `ft_solve_bsq`: esqueleto que llama a lectura de info y mapa, maneja errores. |
| `bsq.h`       | Definición de `t_map`, prototipos, constantes y librerías. |
| `Makefile`    | Compilación de objetos y creación del binario `bsq`. |

---

## 🗃 Estructura de datos

```c
typedef struct s_map
{
    int     rows;       // Número de filas del mapa
    int     cols;       // Número de columnas (calculado después de leer la primera fila)
    char    empty;      // Carácter que representa espacios libres
    char    obstacle;   // Carácter que representa obstáculos
    char    full;       // Carácter que representa el cuadrado más grande
    char    **grid;     // Matriz 2D con el mapa leído
} t_map;
```

## 🔧 Funciones implementadas

### `main()`
- Gestiona argumentos y abre cada mapa.  
- Llama a `ft_solve_bsq(map_fd)`.  
- Maneja errores de apertura y saltos de línea entre mapas.

### `ft_read_info(t_map *map, int map_fd)`
- Lee la primera línea del archivo y valida caracteres.  
- Extrae `empty`, `obstacle`, `full`.  
- Llama a `ft_get_rows` para obtener el número de filas.

### `ft_read_raw_map(int map_fd)`
- Lee el mapa en bloques (`MAP_BUFFER_SIZE`).  
- Concatenación con `ft_strjoin`.  
- Retorna `NULL` si falla lectura o malloc.

### `ft_read_map(t_map *map, int map_fd)`
- Llama a `ft_read_raw_map`.  
- Divide el mapa en filas usando `ft_split` (pendiente).  
- Calcula `cols` según la longitud de la primera fila.  
- Libera `raw_map` después de usarlo.

### Auxiliares (`utils.c`)
- `ft_putstr`, `ft_puterr` → escribir en stdout/stderr.  
- `ft_strlen` → longitud de cadena.  
- `ft_atoi` → convierte string a entero, valida dígitos.  
- `ft_strjoin` → concatena dos cadenas dinámicamente.

---

## ⚠️ Pendientes

- `ft_split` → separar `raw_map` en `map->grid` y liberar memoria si falla.  
- Validación de que **todas las filas tengan la misma longitud y demas requisitos del mapa**.  
- Algoritmo BSQ → encontrar el mayor cuadrado y rellenar `map->grid` con `full` (Delego en ti, pero lo miramos juntos y si vamos bien de tiempo dividimos).  
- Printear el mapa con la solución.
- Liberar `map->grid` al final del programa o en caso de error. 
- Optimización de lectura de mapas grandes.
- Debuggeo produndo y comprobar la gestión de memoria en casos limites, asi como pruebas de mapas raros.

---

## 🎯 Puntos críticos / trampas

1. **Primera línea del mapa** → contiene número de filas + tres caracteres; cuidado al separar.  
2. **Carácter `full` distinto de `empty` y `obstacle`** → validar duplicados.  
3. **Tamaño de filas** → todas deben ser iguales.  
4. **Lectura por bloques** → `read` no garantiza devolver todo el mapa de una vez.  
5. **Memoria dinámica** → liberar todo en caso de errores parciales para evitar leaks.

## 🛠 Compilación y uso

```bash
make        # compila el proyecto
./bsq file1.txt file2.txt ...
./bsq       # lee desde stdin
make clean  # borra objetos
make fclean # borra binario y objetos
```

## ✅ Resumen visual del flujo de lectura

```text
Archivo → ft_solve_bsq
       ├─> ft_read_info  → parsea primera línea
       └─> ft_read_map
             ├─> ft_read_raw_map → lee todo el mapa
             └─> ft_split        → divide en filas
```

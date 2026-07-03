*Este proyecto ha sido creado como parte del currículo de 42 por saperez-.*

# get_next_line

## Descripción

get_next_line es una función escrita en C que permite leer líneas completas de un descriptor de archivo de forma incremental. El objetivo principal del proyecto es implementar una solución robusta que devuelva una línea por llamada, gestionando correctamente el buffer de lectura, el final de línea y el resto de datos no consumidos.

Durante el desarrollo del proyecto se trabajan conceptos como:

- Lectura controlada desde descriptores de archivo.
- Manejo de buffers configurables mediante `BUFFER_SIZE`.
- Gestión de memoria dinámica y cadenas en C.
- Conservación de estado entre llamadas sin utilizar variables globales.
- Lectura desde archivos y desde entrada estándar.

La función `get_next_line` es especialmente útil para procesar archivos de texto línea a línea sin cargar todo el archivo en memoria.

---

## Instrucciones

### Compilación

Para compilar el proyecto desde la raíz del repositorio:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

El proyecto también debe compilar correctamente sin definir `BUFFER_SIZE`, utilizando un valor por defecto interno.

### Ejecución

Para ejecutar el binario con un archivo de texto:

```bash
./get_next_line archivo.txt
```

Para leer desde la entrada estándar:

```bash
./get_next_line < archivo.txt
```

---

## Uso

Después de compilar, la función puede utilizarse de la siguiente manera en un programa de prueba:

```c
int fd = open("archivo.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```

El comportamiento esperado es que cada llamada a `get_next_line` devuelva la siguiente línea completa, incluyendo `\n` cuando corresponda, o `NULL` al final del archivo o ante un error.

---

## Características principales

- Lectura de una línea completa por llamada.
- Soporte para distintos tamaños de buffer mediante `BUFFER_SIZE`.
- Conservación de los datos sobrantes entre llamadas.
- Compatibilidad con lectura desde archivos y desde stdin.
- Control de errores en las lecturas y en la gestión de memoria.

---

## Bonus

La versión bonus está implementada usando un único array estático para almacenar el estado por descriptor de archivo. Esto permite leer de múltiples descriptores de archivos de forma alterna sin mezclar las líneas entre ellos.

Los archivos bonus están en el mismo directorio raíz del proyecto que los archivos obligatorios, pero son implementaciones distintas identificadas por el sufijo `_bonus`.

El bonus incluye:

- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

Esta implementación permite alternar llamadas a `get_next_line` en distintos fds (por ejemplo 3, 4 y 5) manteniendo el seguimiento de la posición de cada descriptor.

---

## Algoritmos y estructuras de datos

### Justificación del algoritmo

La solución seleccionada se basa en un enfoque incremental usando un buffer temporal de tamaño `BUFFER_SIZE`. Cada llamada a `get_next_line` lee datos con `read()` hasta encontrar un salto de línea `\n` o hasta agotar el archivo.

El algoritmo guarda los bytes leídos en un área de almacenamiento dinámica. Si la lectura incluye datos más allá del primer salto de línea, ese excedente se conserva para la siguiente invocación. Esto evita leer el archivo completo en memoria y permite mantener el estado entre llamadas sin usar variables globales.

### Ventajas del enfoque

- Permite funcionar correctamente con `BUFFER_SIZE = 1` o con valores grandes.
- Minimiza llamadas a `read()` al leer solo hasta el siguiente salto de línea.
- Evita procesar datos de más, conservando el resto para la siguiente llamada.
- Mantiene una separación clara entre llamadas, lo que facilita la extensión hacia múltiples descriptores de archivo.

### Gestión de memoria

La implementación presta especial atención a:

- liberar memoria tras devolver cada línea,
- evitar fugas al fallar en asignaciones parciales,
- usar solo memoria dinámica y no variables globales.

---

## Recursos

### Documentación y referencias

- Manuales del sistema (`man 2 read`, `man 2 open`).
- Documentación POSIX sobre descriptores de archivo.
- Artículos y tutoriales sobre lectura buffered en C.
- Guías del proyecto `get_next_line` del currículo 42.

### Uso de IA

Este archivo README ha sido generado y depurado con ayuda de IA para asegurar que cumple el formato y los requisitos solicitados. La IA se utilizó para:

- estructurar el contenido del README,
- asegurar la presencia de las secciones obligatorias,
- redactar la justificación del algoritmo,
- revisar y depurar el texto final.

No se ha usado IA para implementar el proyecto en sí, solo para mejorar la documentación y su presentación.

---

## Estructura del proyecto

```text
gnl/
├── get_next_line.c
├── get_next_line_bonus.c
├── get_next_line_utils.c
├── get_next_line_utils_bonus.c
├── get_next_line.h
├── get_next_line_bonus.h
├── README.md
└── [archivos de datos de entrada opcionales]
```

---

## Aprendizajes

Este proyecto permite:

- comprender la lectura incremental desde descriptores de archivo,
- practicar la gestión de buffers y cadenas en C,
- reforzar el uso correcto de `malloc` y `free`,
- desarrollar un patrón de lectura línea a línea robusto.

---

<div align="right">

**Campus 42 Madrid**  
Junio de 2026

</div>

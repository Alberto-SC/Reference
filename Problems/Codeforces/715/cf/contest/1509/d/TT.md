# Técnicas Modernas para NLP

## RNC Básicas
Es una red neuronal utilizadas para problemas de clasificación. Toman como entrada una imagen y dan como salida la cateogoría a la que pertenece una imagen.

```flow
st=>start: Imagen de entrada
op=>operation: RNC
e=>end: Etiqueta de salida
(Clase de la imagen)

st->op->e->
```

### Pasos para crear una red convolucional
:::info
**Paso 1:** Convolución 
Crea "detectores de características" que recorren la imagen, a partir de estas se crea un mapa de características (matrices bidimensionales) que nos indica si cierto rasgo o forma aparece o no en la imagen.
:::
:::info
**Paso 2:** Max Pooling
Aplica una función máximo a cada uno de los mapas de característica, haciéndolos más pequeños y se mejora el performance, evitando el exceso de información. 
:::
:::info
**Paso 3:** Aplanado
Se convierten los mapas de características (matrices bidimensionales) en un vector largo que será la entrada al cuarto paso que es una red neuronal.
:::
:::info
**Paso 4:** Conexión completa
Se tiene una red neuronal con capas ocultas que aprenderá de los rasgos extraídos de los mapas característicos obtenidos del *pooling*.
:::

## RNC para imágenes
### Convolución
Teniendo una pequeña representación del mundo como lo vemos y la forman en la que una computadora entiende, tendríamos el siguiente ejemplo:

![](https://i.imgur.com/xKY0Znb.png)

La fase de de convolción consisten en construir muchos detectores de caracteríticas (matrices) que se aplicarán a la imagen. Se aplicarán por lotes sobre la matrices originales de la imagen tomando el tamaño del detector de características. Los filtros/características se van a operar elemento a elemento y sumar a lo que se le conoce como producto tensorial.

![](https://i.imgur.com/DlP7o9U.png)
:::warning
:pencil: **NOTA:** No es una multiplicación estándar de matrices, sólo es una multiplicación elemento a elemento.
:::

En pocas palabras, lo que se busca es que en la imagen de entrada y en el detector de características exista un uno en la misma posición, se iría desplazando hasta que el mapa de características quede completamente lleno.

![](https://i.imgur.com/PNhynsn.png)

:::success
:heavy_check_mark: **Realidad:** En la aplicación real de estos conceptos, el detector de características se llena con valores aleatorios, después de cada predicción se van a comparando los resultados que devuelve la red neuronal con la etiqueta real que tuvieran las imágenes, de esta forma el modelo:
* Identificará los detectores de características le funcionan mejor.
* Identificará los detectores de características le funcionan peor.
    * Para mejorar esta, cambiará los números en búsqueda de mejorarlo.
:::

El resultado final de la convolución es una gran lista de mapas de características. Cada mapa corresponde a un detector de características y cada detector habrá detectado diferentes formas gracias a los diferentes filtros que la red neuronal fue aprendiendo.
![](https://i.imgur.com/6vw6TGE.png)

### Max Pooling
Retomando el mapa de caracerísticas de la convolución mostrada anteriormente, tomaremos una ventana de $2x2$ que iremos desplazando. Esto nos permitirá reducir cada cuatro números, quedándonos con el máximo de esa posición.

![](https://i.imgur.com/JyT2uKi.png)

Se irá desplazando la ventana, de forma que no coincida con ninguna de las posiciones anteriores, por ende moveremos dos posiciones a la derecha.

![](https://i.imgur.com/5T6Os9S.png)

Continuamos el procedimiento hasta terminar de llenar la matriz, no importa si al deslizar la ventana nos salimos de la matriz. Podemos ver que se ha reducido el tamaño de la imagen, simplificando el costo computacional.

![](https://i.imgur.com/UkoGTzq.png)

Después de realizar este paso con todos los mapas, tendremos un aprendizaje más global sonservando aún la información de las características.

![](https://i.imgur.com/QLZj0l6.png)

### Aplanado
Una red neuronal totalmente conectada necesita un vector en la capa de entrada. Tomamos cada uno de los mapas de características resultantes del *"pooling"* y los transformamos de una matriz a un vector vertical.
![](https://i.imgur.com/4nZidpe.png)

:::warning
:pencil: **NOTA:** La operación de aplanado a pesar de cambiar la forma de la información, aún conserva las posiciones.
:::

Una vez realizado con todos los mapas, tendríamos como resultado tendríamos un macro vector.
![](https://i.imgur.com/ZcaYuyT.png)

Resumiendo, la arquitectura de los primeros 3 pasos quedaría de la siguiente forma.

![](https://i.imgur.com/eKP3f3z.png)

### Conexión completa
Las capas ocultas pueden tener tantas neuronas como se necesite, esto lo que hará es complicar la arquitectura y aumentará las operaciones que se deban hacer. 
La capa amarilla es el vector aplanado del paso anterior y la salida de color rojo serían las posibles categorías de etiquetado (etiquetas de clasificación).

![](https://i.imgur.com/sED9WQB.png)

El número que saldría de la red neuronal representaría la verosimilitud, es decir, la probabilidad de que una imagen corresponda a dicha categoría.

:::warning
:pencil: **NOTA:** Para romper la linealidad del proceso, si el producto que se realiza en la red neuronal se utiliza la **función de activación rectificadora unitaria (ReLu)**, la cual reemplaza los valores negativos con 0 y los positivos los mantiene.
:::

El proceso completo se resumiría en el siguiente diagrama.

![](https://i.imgur.com/LzuYOPQ.png)

## RNC en texto
Para poder trabajar con texto se necesita representar la frase que se desea en formato matricial (vectores de números), es decir, cada palabra se transformará en un vector de más o menos coordenadas.

![](https://i.imgur.com/4WoWKfA.png)

### Transformaciones
#### **One-hot encoding**
Es una representación ***sencilla*** pero ***inefectiva*** de palabras, donde no existe relación entre las palabras.

***Funcionamiento***
Consiste en represntar cada palabra en un vector, donde el tamaño del vector será el tamaño del vocabulario. Todas las posiciones estarán en 0, salvo la posición donde se encuentra la representación de la palabra.
 
![](https://i.imgur.com/ztwWm3A.png)

#### **Word embedding**
Hacemos cada vector más pequeño y le añadimos restricciones para formar relaciones entre las palabras. De esta forma las restricciones hacen que se fuercen a estar cercanas las palabras con similitudes (*semántica*).

***Funcionamiento***
Se escoge un número, el cual será la dimensión del vector. Con esto el vecctor ya no contendrá valores binarios, sino solamente valores entre 1 y 0.

![](https://i.imgur.com/cQ5Vrev.png)

A través de los vectores podemos realizar operaciones (suma o resta), y si la transformación ha sido llevada correctamente algunas propiedades de la palabra real. Ya sea que podamos añadir o quitar significados a las palabras.

Viendo la anterior de manera visual tenemos lo siguiente.

![](https://i.imgur.com/F1SlDN0.png)

En la primera imagen podemos ver lo que sucede cuando las palabras son transformadas en un espacio de dimensión inferior.

:::warning
:pencil: **NOTA:** 
A Paris se le asigna la propiedad de capital, por ende en esta operación se retorna la capital de Italia.
<p style="text-align: center"><b>[Paris]-[Francia]+[Italia]=[Roma]</b></p>
:::

En la segunda imagen, podemos ver una representación bidemensional de palabras embebidas (*transformadas*), de acuerdo a la relación que tienen entre sí es su cercanía entre ellas en el espacio.

***Justificación matemática***
Al hacer el primer producto obtendremos la fila i-ésima de la matriz de embedding, donde está la palabra que estamos analizando. 

Esta matriz es una lista de los vectores originales de las palabras embebidas en un espacio dimensiomal de menor dimensión.
![](https://i.imgur.com/MK4rNHB.png)

***Entrenamiento de la matriz***
Para elegir las mejores coordenadas este vector debe ser reconstruido con el fin de obtener el vector original, haciendo una operación contraria (*matriz de contexto*) multiplicando por otra matriz y de ello obtendremos un vector con el mismo tamaño del vector original pero añadiendo una correlación semántica (*contexto*) a la palabra orginal que se ha codificado.

## RNC para NLP
### Arquitectura de RNC para NLP

#### ***Diferencias principales***
* En las imágenes Los elementos adyacentes son los píxeles en orden de la imagen. En los textos el orden es arbitrario.
* Cada filtro tiene anchura = d_model. Dividir la dimensión de embedding no tiene sentido.
* Elegimos el máximo de cada filtro. La posición de la característica en la frase es menos relevante.
* La posición es importante sólo en las imágenes.
* 3 tamaños diferentes de filtros, para capturar diferentes niveles de correlación entre las palabras.
* En el texto no existe una etapa de aplanamiento.

![](https://i.imgur.com/ALvmKV8.png)
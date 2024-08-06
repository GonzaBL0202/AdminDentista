#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include"StringDinamico.h"
void Agregar (string nomArch, int entero);
// Agrega el nuevo entero al final del archivo
boolean Existe (string nomArch);
// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Vacio (string nomArch);
// Determina si el archivo está vacío o no. Precondición: El archivo existe
boolean Pertenece (string nomArch, int entero);
// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
int Largo (string nomArch);
// Devuelve la cantidad de enteros almacenados en el archivo. Precondición: El archivo existe
int K_esimo (string nomArch, int k);
// Devuelve el k-ésimo entero almacenado en el archivo. Precondición: El archivo existe
// y su largo es  k.
void Desplegar (string nomArch);
// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe


#endif // ARCHIVOS_H_INCLUDED

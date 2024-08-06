#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
#include"StringDinamico.h"
typedef struct {
int dia;
int mes;
int anio;
}Fecha;

void cargarfecha (Fecha &fe);
void mostrarfecha (Fecha fe);
boolean FechaMayorIgual (Fecha f1, Fecha f2);
boolean FechaIgual (Fecha f1, Fecha f2);

int Dardia (Fecha fe);
int Darmes (Fecha fe);
int Daranio (Fecha fe);
boolean fechavalida (Fecha fe);
#endif // FECHAS_H_INCLUDED

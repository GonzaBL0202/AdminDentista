#ifndef CONSULTAS_H_INCLUDED
#define CONSULTAS_H_INCLUDED
#include "StringDinamico.h"
#include "Evaluacion.h"
#include "fechas.h"
typedef struct {
    Fecha fe;
    string motivo;
    long int cedula;
    Evaluacion ev;
}Consulta;

void cargarConsulta (Consulta &cons);
void mostrarConsulta (Consulta cons);
Fecha DarFecha (Consulta cons);
void DarMotivo (Consulta cons, string &s);
long int DarCedula (Consulta cons);

void Bajar_Consulta (Consulta c, FILE * f);
void Levantar_Consulta (Consulta &c, FILE * f);

#endif // CONSULTAS_H_INCLUDED

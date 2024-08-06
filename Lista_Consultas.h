#ifndef LISTA_CONSULTAS_H_INCLUDED
#define LISTA_CONSULTAS_H_INCLUDED
#include "Consultas.h"

typedef struct nodoL {
    Consulta info;
    nodoL * sig;
} Nodo;
typedef Nodo * Lista_Cons;

void CrearLista (Lista_Cons & L);
boolean Vacia (Lista_Cons L);
Consulta Primero (Lista_Cons L);
void Resto (Lista_Cons & L);
void InsConsulta (Lista_Cons & L, Consulta cons);
void ListarConsultas (Lista_Cons LC);
void CantCadaTipo (Lista_Cons LC, int &trat, int &prot, int &salu);
int CantPorFecha (Lista_Cons LC, Fecha fe);
boolean PerteneceRecu (Lista_Cons LC, long int e);
void ListarConsultasPaciente (Lista_Cons LC, long int cedula);
void ListarPostFecha (Lista_Cons LC, Fecha fe);
void BorrarOcurrencias (Lista_Cons &L, long int cedula);

void Bajar_Lista (Lista_Cons L , string nomArch);
void Levantar_Lista (Lista_Cons &L, string nomArch);
#endif // LISTA_CONSULTAS_H_INCLUDED

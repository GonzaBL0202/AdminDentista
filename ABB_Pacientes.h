#ifndef ABB_PACIENTES_H_INCLUDED
#define ABB_PACIENTES_H_INCLUDED
#include "Pacientes.h"
#include "Lista_Consultas.h"

typedef struct nodoA{
        Paciente info;
        nodoA * hizq;
        nodoA * hder;
} nodo;

typedef nodo * ABBP;

void CrearArbol (ABBP &a);
boolean EsVacio (ABBP a);
Paciente DarRaiz (ABBP a);
ABBP HijoIzq (ABBP a);
ABBP HijoDer (ABBP a);
boolean Pertenece (ABBP a, long int cedula);
void Insert (ABBP &a, Paciente p);
void AgregarConsulta (ABBP &a, Lista_Cons &l);
void RegistrarPaciente (ABBP &a, Paciente p);
void ListarPacientes (ABBP a);
void ListarSinConsultas (ABBP a);
void Borrar (long int cedula , ABBP &a);
Paciente Minimo (ABBP a);
void Borrar_Minimo (ABBP &a);
void Incremento_Consulta (ABBP &a, long int cedula);
int CantPacientesXConsultas (ABBP a, int cant);
void MaxConsultas (ABBP a, int &cons, long int &cedula);

void Bajar_ABB_Aux (ABBP a, FILE * f);
void Bajar_ABB (ABBP a, string nomArch);
void Levantar_ABB (ABBP &a, string nomArch);


#endif // ABB_PACIENTES_H_INCLUDED

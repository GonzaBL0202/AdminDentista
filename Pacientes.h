#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
#include "StringDinamico.h"
typedef struct {
    long int cedula;
    string nombre;
    string apellido;
    int telefono;
    int cant_consultas;
} Paciente;

void cargarPaciente (Paciente &pa);
void mostrarPaciente (Paciente pa);
long int DarCedula (Paciente pa);
void DarNombre (Paciente pa, string &nombre);
void Darapellido (Paciente pa, string &apellido);
int DarTelefono (Paciente pa);
int DarCantConsulta (Paciente pa);

void Bajar_Paciente (Paciente P, FILE * f);
void Levantar_Paciente (Paciente &P, FILE * f);

#endif // PACIENTES_H_INCLUDED

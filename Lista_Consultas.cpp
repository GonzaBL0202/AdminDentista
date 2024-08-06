#include "Lista_Consultas.h"

void CrearLista (Lista_Cons & L)
{
L = NULL;
}
boolean Vacia (Lista_Cons L)
{
boolean es = FALSE;
if (L == NULL)
es = TRUE;
return es;
}
/* Precondición: lista NO vacía */
Consulta Primero (Lista_Cons L)
{
return L -> info;
}
/* Precondición: lista NO vacía */
void Resto (Lista_Cons & L)
{
Lista_Cons aux = L;
L = L -> sig;
delete aux;
}
void InsConsulta (Lista_Cons & L, Consulta cons)
{
Lista_Cons aux = new Nodo;
aux -> info = cons;
aux -> sig = L;
L = aux;

}

void ListarConsultas (Lista_Cons LC){
    if(LC != NULL){
        mostrarConsulta(LC->info);
        ListarConsultas(LC->sig);
    }
}

void CantCadaTipo (Lista_Cons LC, int &trat, int &prot, int &salu){

if(LC != NULL){
    if(DarEvaluacion(LC->info.ev)== EN_TRATAMIENTO)
        trat++;
    else
        if(DarEvaluacion(LC->info.ev)==NECESITA_PROTESIS)
            prot++;
        else
            salu++;
    CantCadaTipo(LC->sig, trat, prot, salu);
    }

}

int CantPorFecha (Lista_Cons LC, Fecha fe){
    if(fechavalida(fe)){
        if(LC != NULL){
            if(FechaIgual(DarFecha(LC->info),fe))
                return 1 + CantPorFecha(LC->sig, fe);
            else
                return CantPorFecha(LC->sig, fe);
        }
        return 0;
    }
}

boolean PerteneceRecu (Lista_Cons LC, long int e){
if (LC == NULL)
    return FALSE;
else
    if (LC->info.cedula == e)
        return TRUE;
    else
        return PerteneceRecu (LC -> sig, e);
}
void ListarConsultasPaciente (Lista_Cons LC, long int cedula){
    if(PerteneceRecu(LC, cedula)){
        if(LC != NULL){
        if(LC->info.cedula == cedula){
            mostrarConsulta(LC->info);
            ListarConsultasPaciente(LC->sig, cedula);
        }
        else
            ListarConsultasPaciente(LC->sig, cedula);
        }
    }
}

void ListarPostFecha (Lista_Cons LC, Fecha fe){
if(fechavalida(fe)){
    if(LC != NULL){
        if(FechaMayorIgual(DarFecha(LC->info), fe)){
            mostrarConsulta(LC->info);
            ListarPostFecha(LC->sig, fe);
      }
    }
  }
}

void BorrarOcurrencias (Lista_Cons &L, long int cedula){
if (L != NULL){
 if (cedula == L->info.cedula){
    Lista_Cons aux = L;
    L = L -> sig;
    delete aux;
    BorrarOcurrencias (L, cedula);
 }
 else
    BorrarOcurrencias (L -> sig, cedula);
 }
}



void Bajar_Lista (Lista_Cons L , string nomArch) /* Módulo Lista */
{
 FILE * f = fopen (nomArch, "wb");
 while (L != NULL)
 {
 Bajar_Consulta (L -> info, f);
 L = L -> sig;
 }
 fclose (f);
}
void Levantar_Lista (Lista_Cons &L, string nomArch) /* Módulo Lista */
{
 FILE * f = fopen (nomArch, "rb");
 Consulta cons;
 CrearLista (L);
 Levantar_Consulta (cons, f);
 while (!feof(f))
 {
 InsConsulta (L, cons);
 Levantar_Consulta (cons, f);
 }
 fclose (f);
}

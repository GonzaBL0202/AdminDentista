#include "ABB_Pacientes.h"

/* saber si el árbol está vacío */
boolean EsVacio (ABBP a)
{
return (boolean) (a == NULL);
}
/* crear un árbol vacío */
void CrearArbol (ABBP &a){
a = NULL;
}

/* devolver la raíz del árbol */
/* Precondición: Arbol NO vacío */
Paciente DarRaiz (ABBP a)
{
return a -> info;
}

/* obtener el subárbol izquierdo */
/* Precondición: Arbol NO vacío */
ABBP HijoIzq (ABBP a)
{
return a -> hizq;
}

/* obtener el subárbol derecho */
/* Precondición: Arbol NO vacío */
ABBP HijoDer (ABBP a)
{
return a -> hder;
}

boolean Pertenece (ABBP a, long int cedula)
{
if (a == NULL)
    return FALSE;
else
    if (a->info.cedula == cedula)
        return TRUE;
else
    if (cedula < a->info.cedula)
        return Pertenece (a -> hizq, cedula);
else
    return Pertenece (a -> hder, cedula);
}

void AgregarConsulta (ABBP &a, Lista_Cons &lc){
    Consulta cons;
    cargarConsulta(cons);
    if(Pertenece(a, DarCedula(cons))){
        if(fechavalida(DarFecha(cons))){
                if(lc == NULL){
                    InsConsulta(lc,cons);
                    Incremento_Consulta(a,DarCedula(cons));
                }
                else
                if(FechaMayorIgual(DarFecha(cons), DarFecha(lc->info))){
                    InsConsulta(lc,cons);
                    Incremento_Consulta(a,DarCedula(cons));
            }
        }
    }
}
void Insert (ABBP &a, Paciente p)
{
if (a == NULL){
    a = new nodo;
    a -> info = p;
    a -> hizq = NULL;
    a -> hder = NULL;
}
else{
    if (p.cedula < a->info.cedula)
        Insert (a -> hizq, p);
    else
        Insert (a -> hder, p);
    }
}

void RegistrarPaciente (ABBP &a, Paciente p){
cargarPaciente(p);
if(!Pertenece(a, p.cedula))
    Insert(a,p);
else
    printf("\nEl paciente %ld ya esta registrado\n", p.cedula);
}

void ListarPacientes (ABBP a){
if(a != NULL){
        ListarPacientes (a -> hizq);
        mostrarPaciente(a->info);
        printf("\n");
        ListarPacientes (a -> hder);
    }
}

void ListarSinConsultas(ABBP a){
if(a != NULL){
        ListarSinConsultas (a -> hizq);
        if(a->info.cant_consultas == 0)
        mostrarPaciente(a->info);
        printf("\n");
        ListarSinConsultas (a -> hder);
    }
}

void Borrar (long int cedula , ABBP &a){
ABBP aux;
if (cedula == a -> info.cedula){
    if (a -> hder == NULL){
        aux = a -> hizq;
        delete a;
        a = aux;
    }
    else{
        if (a -> hizq == NULL){
            aux = a -> hder;
            delete a;
            a = aux;
        }
            else{
            a -> info = Minimo (a -> hder);
            Borrar_Minimo (a -> hder);
            }
    }
}
else{
if (cedula < a -> info.cedula)
    Borrar (cedula, a -> hizq);
else
    Borrar (cedula, a -> hder);
    }
}

Paciente Minimo (ABBP a){
if (a -> hizq == NULL)
    return (a->info);
else
    return Minimo (a -> hizq);
}

void Borrar_Minimo (ABBP &a){
ABBP aux;
if (a -> hizq == NULL){
    aux = a -> hder;
    delete a;
    a = aux;
}
else
    Borrar_Minimo (a -> hizq);
}
//precondicion: la cedula ya existe en el arbol
void Incremento_Consulta (ABBP &a, long int cedula)
{
if (a != NULL){
    if (a->info.cedula == cedula){
        a->info.cant_consultas++;
    }
else
    if (cedula < a->info.cedula)
        Incremento_Consulta(a -> hizq, cedula);
else
    Incremento_Consulta(a -> hder, cedula);
    }
}
int CantPacientesXConsultas (ABBP a, int cant){
int cons=0;
if(a==NULL)
    return 0;
else
    if(a->info.cant_consultas >= cant){
        cons++;
        return cons + CantPacientesXConsultas(a->hizq,cant) + CantPacientesXConsultas(a->hder,cant);
    }
    else
        return cons + CantPacientesXConsultas(a->hizq,cant) + CantPacientesXConsultas(a->hder,cant);
}

void MaxConsultas (ABBP a, int &cons, long int &cedula){
if(a != NULL){
if(a->hder != NULL){
    if((a->hder->info.cant_consultas) > cons){
        cons=DarCantConsulta(a->hder->info);
        cedula=DarCedula(a->hder->info);
        }
    }
    if(a->hizq != NULL){
    if((a->hizq->info.cant_consultas) > cons){
        cons=DarCantConsulta(a->hizq->info);
        cedula=DarCedula(a->hizq->info);
        }
    }
MaxConsultas(a->hder, cons,cedula);
MaxConsultas(a->hizq, cons,cedula);
    }
}



void Bajar_ABB_Aux (ABBP a, FILE * f)
{
 if (a != NULL)
 {
 Bajar_Paciente(a -> info, f);
 Bajar_ABB_Aux (a -> hizq, f);
 Bajar_ABB_Aux (a -> hder, f);
 }
}
void Bajar_ABB (ABBP a, string nomArch)
{
 FILE * f = fopen (nomArch, "wb");
 Bajar_ABB_Aux (a, f);
 fclose (f);
}
void Levantar_ABB (ABBP &a, string nomArch)
{
 FILE * f = fopen (nomArch, "rb");
 Paciente p;
 CrearArbol (a);
 Levantar_Paciente (p, f);
 while (!feof(f))
 {
 Insert (a, p);
 Levantar_Paciente (p, f);
 }
 fclose (f);
}


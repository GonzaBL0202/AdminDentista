#include"fechas.h"

void cargarfecha (Fecha &fe){
printf("Ingrese el dia:\n");
scanf("%d", &fe.dia);
printf("Ingrese el mes:\n");
scanf("%d", &fe.mes);
printf("Ingrese el anio:\n");
scanf("%d", &fe.anio);
}

void mostrarfecha (Fecha fe){
printf("FECHA: %d/%d/%d", fe.dia, fe.mes, fe.anio);
}

boolean FechaMayorIgual(Fecha f1, Fecha f2){
    if(f1.anio<f2.anio)
        return FALSE;
    else
        if(f1.mes<f2.mes)
            return FALSE;
        else
            if(f1.dia<f2.dia)
                return FALSE;
            else
                return TRUE;
}

int Dardia (Fecha fe){
return(fe.dia);
}

int Darmes (Fecha fe){
return(fe.mes);
}

int Daranio (Fecha fe){
return(fe.anio);
}
boolean fechavalida (Fecha fe){
boolean valida=TRUE;
if(fe.dia>31 || fe.dia<1)
    valida=FALSE;
    else
        if(fe.dia>30 && (fe.mes==4 || fe.mes==6 || fe.mes==9 || fe.mes==11))
            valida=FALSE;
            else
                if(fe.mes>12 || fe.mes<1)
                valida=FALSE;
                    else
                        if(fe.anio%4==0 && fe.mes==2 && fe.dia>29)
                        valida=FALSE;
                            else
                                if(fe.anio%4!=0 && fe.mes==2 && fe.dia>28)
                                valida=FALSE;
return(valida);
};

boolean FechaIgual(Fecha f1, Fecha f2){
    if(f1.anio!=f2.anio)
        return FALSE;
    else
        if(f1.mes != f2.mes)
            return FALSE;
        else
            if(f1.dia !=f2.dia)
                return FALSE;
            else
                return TRUE;
}

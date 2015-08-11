#ifndef FECHADM_H
#define FECHADM_H

struct FechaDM{
    unsigned short dia;
    unsigned short mes;
};

bool validarFecha(FechaDM fecha)
{
    short cantDias[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return 1 <= fecha.mes && fecha.mes <= 12 &&
           1 <= fecha.dia && fecha.dia <= cantDias[fecha.mes];
}

#endif // FECHADM_H

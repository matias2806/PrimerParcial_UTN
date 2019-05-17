#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
#define TAM_ORQUESTA 50
#define TAM_INSTRUMENTO 20
#define TAM_MUSICO 1000


int main()
{
    int opcion;
    int contadorIdOrquesta=4;                   //cambiar
    int contadorIdInstrumento=4;
    int contadorIdMusico=4;
    int IdFutBaja;

    Orquesta arrayOrquesta[TAM_ORQUESTA];
    Instrumento arrayInstrumento[TAM_ORQUESTA];
    Musico arrayMusico[TAM_MUSICO];

    orquesta_Inicializar(arrayOrquesta,TAM_ORQUESTA);
    instrumento_Inicializar(arrayInstrumento,TAM_INSTRUMENTO);
    musico_Inicializar(arrayMusico, TAM_MUSICO);

    orquesta_hardcodeo(arrayOrquesta);
    instrumento_hardcodeo(arrayInstrumento);
    musico_hardcodeo(arrayMusico);

    do
    {
        utn_getUnsignedInt("\n\t\tMENU\n1) Agregar orquesta \n2) Eliminar orquesta \n3) Imprimir orquesta \n4) Agregar Musico \n5) Modificar Musico \n"
                               "6) Eliminar Musico  \n7) Imprimir Musicos  \n8) Agregar Instrumento  \n9) Imprimir Instrumentos  \n"
                               //"11) Alta socio \n12) Modificar socio \n13) Baja socio \n14) Listar socio"
                               "\n16) Salir\n \tIngrese una opcion: ",                //cambiar
                      "\nError",1,sizeof(int),1,17,1,&opcion);
        switch(opcion)
        {

            case 1: //Alta
                orquesta_alta(arrayOrquesta,TAM_ORQUESTA,&contadorIdOrquesta);
                break;
            case 2: //BAJA
                orquesta_baja(arrayOrquesta,TAM_ORQUESTA, &IdFutBaja);
                musico_semibaja(arrayMusico ,TAM_MUSICO,IdFutBaja);
                break;
            case 3: //LISTAR
                orquesta_listar(arrayOrquesta,TAM_ORQUESTA);
                break;
            case 4://ALTA
                musico_alta(arrayMusico,TAM_MUSICO,&contadorIdMusico);
                break;
            case 5:
                musico_modificar(arrayMusico, TAM_MUSICO);
                break;
            case 6: //BAJA
                musico_baja(arrayMusico, TAM_MUSICO);
                break;
            case 7: //LISTAR
                musico_listar(arrayMusico, TAM_MUSICO);
                break;
            case 8: //alta
                instrumento_alta(arrayInstrumento,TAM_INSTRUMENTO,&contadorIdInstrumento);
                break;
            case 9://Listar
                instrumento_listar(arrayInstrumento,TAM_INSTRUMENTO);
                break;
            case 10://Ordenar

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
            case 14:

                break;
            case 15:

                break;
            case 16://Salir
            break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=16);
    return 0;
}

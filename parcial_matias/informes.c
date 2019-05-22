#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"
#include "informes.h"


///opcion 1 Mostrar todos los musicos que tengan algun tipo de instrumento
void opcion1(Musico* arrayMusico, int tamMusico, int tipoInstrumento ){
    int  j; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA


    printf("\n\n");
    for(j=0; j<tamMusico;j++)
    {
        if(arrayMusico[j].isEmpty==0 && arrayMusico[j].idInstrumento ==tipoInstrumento)
        {
            musico_listaIDString(arrayMusico[j]);
        }
    }
}


///opcion 2  Mostrar todos los musicos que NO esten en alguna orquesta
void opcion2(Musico* arrayMusico, int tamMusico, int NoTipoOrquesta ){
    int  j; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA

    printf("\n\n");
    for(j=0; j<tamMusico;j++)
    {
        if(arrayMusico[j].isEmpty==0 && arrayMusico[j].idOrquesta != NoTipoOrquesta)
        {
            musico_listaIDString(arrayMusico[j]);
        }
    }
}

///opcion 3  imprimir una orquesta con sus respectivos músicos y los instrumentos que
///utiliza cada uno respetando el siguiente esquema...
///Ejemplo....
///---------- ORQUESTA "ALE EL BOLUDO" -----------------
///datos músico
///datos instrumento que utiliza
///datos músico
///datos instrumento que utiliza
///datos músico
void opcion3(Musico* arrayMusico, int tamMusico, Instrumento* arrayInstrumento, int tamInstrumento , Orquesta* arrayOrquesta, int tamOrquesta ){
    int i, j; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int opcion;
    int guardoInst;
    orquesta_listar(arrayOrquesta, tamOrquesta);
    printf("Ingrese el ID de la Orquesta de la cual desea ver sus integrantes e instrumentos");
    scanf("%d",&opcion);

    orquesta_lista(arrayOrquesta[opcion-1]);
    printf("\n\n");



    for(j=0;j<tamMusico;j++){
        if (arrayMusico[j].idOrquesta == opcion){
            musico_lista(arrayMusico[j]);

            guardoInst= arrayMusico[j].idInstrumento;
            for(i=0; i< tamInstrumento; i++){
                instrumento_lista(arrayInstrumento[guardoInst-1]);
                printf("\n-----------------------------------------------------------------");
                break;

            }
        }
    }
}

///opcion 5. Listar los instrumentos que tiene una orquesta determinada
void opcion5(Musico* arrayMusico, int tamMusico, Instrumento* arrayInstrumento, int tamInstrumento , Orquesta* arrayOrquesta, int tamOrquesta ){
    int i, j; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int opcion;
    int guardoInst;
    orquesta_listar(arrayOrquesta, tamOrquesta);
    printf("Ingrese el ID de la Orquesta de la cual desea ver sus instrumentos\n");
    scanf("%d",&opcion);

    orquesta_lista(arrayOrquesta[opcion-1]);
    printf("\n\n");



    for(j=0;j<tamMusico;j++){
        if (arrayMusico[j].idOrquesta == opcion){
            guardoInst= arrayMusico[j].idInstrumento;
            for(i=0; i< tamInstrumento; i++){
                instrumento_lista(arrayInstrumento[guardoInst-1]);
                //printf("\n-----------------------------------------------------------------");
                break;

            }
        }
    }
}



///opcion 6. informar de menor a mayor según la cantidad de músicos que tiene una orquesta(NO ESTA LA PARTE DE MENOR A MAYOR)
void opcion6(Musico* arrayMusico, int tamMusico, Orquesta* arrayOrquesta, int tamOrquesta ){

    int cantiOrques;
    contarCantDeOrquesta(arrayOrquesta, tamOrquesta,  &cantiOrques );

    int j,k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int Acontador[cantiOrques];
    int total =0;


    for(k=0;k<cantiOrques;k++){
        Acontador[k+1]=0;
        for(j=0;j<tamMusico;j++){
            if(arrayMusico[j].idOrquesta ==k ){
                total = total +1;
                Acontador[k]= total ;


            }

        }
        total =0;
    }
    for(k=0;k<cantiOrques;k++){
        orquesta_lista(arrayOrquesta[k]);
        printf("\nOrquesta n%d = cant de musicos =%d\n",k+1,Acontador[k+1]);
        printf("----------------------------------------------------------------\n");
    }
}


///opcion 7. indicar la cantidad de instrumentos que tienen los tipos de instrumentos
void opcion7(Instrumento* arrayInstrumento, int tamInstrumento, int tipoInstrumento){
    int i; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int contador=0;

    for(i=0;i<tamInstrumento;i++){
        if(arrayInstrumento[i].tipo==tipoInstrumento && arrayInstrumento[i].isEmpty==0){
            contador= contador +1;
        }
    }

    if(tipoInstrumento==1){printf("Cuerdas\n");}
    if(tipoInstrumento==2){printf("Viento-madera\n");}
    if(tipoInstrumento==3){printf("Viento-metal\n");}
    if(tipoInstrumento==4){printf("Percusion\n");}
    printf("La cantidad de instrumentos de tipo %d es de %d\n\n", tipoInstrumento, contador);
}


///opcion 8. listar la cantidad de músicos que pertenecen a cada orquesta
void opcion8(Musico* arrayMusico, int tamMusico, Orquesta* arrayOrquesta, int tamOrquesta ){

    int j,k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int cantiOrques;
    contarCantDeOrquesta(arrayOrquesta, tamOrquesta,  &cantiOrques );

    for(k=0;k<cantiOrques;k++){
        printf("\n-----------------------------------------------------------------------\n\t");
        orquesta_lista(arrayOrquesta[k]);
        for(j=0;j<tamMusico;j++){
            if(arrayMusico[j].idOrquesta ==arrayOrquesta[k].idUnico ){
                musico_lista(arrayMusico[j]);

            }
        }
    }
}

///opcion 9. Imprimir todos los músicos los cuales su edad no supere el promedio de TODOS los músicos
void opcion9(Musico* arrayMusico, int tamMusico){
    int j; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int acumulador=0;
    int contador=0;
    float promedio;

    for (j=0; j<tamMusico;j++){
        if(arrayMusico[j].isEmpty ==0){
            contador++;
            acumulador=acumulador + arrayMusico[j].edad;
        }
    }
    promedio=(float) acumulador / contador;

    printf("El total de edad es de %d \n",acumulador);
    printf("Son %d musicos \n",contador);
    printf("Promedio de edad %f \n",promedio);

    for (j=0; j<tamMusico;j++){
        if(arrayMusico[j].edad <= promedio){
            musico_lista(arrayMusico[j]);
        }
    }
}

///opcion 10. contabilizar la cantidad de orquestas según su tipo, ejemplo
///tipo 1= 20
///tipo 2= ...
///tipo 3= ..
///en caso de no haber mostrar el mensaje "no hay orquestas de tipo ......."
void opcion10(Orquesta* arrayOrquesta, int tamOrquesta ){
    int k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int contadorA=0;///TIPO 1
    int contadorB=0;///TIPO 2
    int contadorC=0;///TIPO 3

    orquesta_listar(arrayOrquesta, tamOrquesta);

    for(k=0; k<tamOrquesta;k++){
        if (arrayOrquesta[k].isEmpty ==0 && arrayOrquesta[k].tipo==1){
            contadorA++;
        }
        if (arrayOrquesta[k].isEmpty ==0 && arrayOrquesta[k].tipo==2){
            contadorB++;
        }
        if (arrayOrquesta[k].isEmpty ==0 && arrayOrquesta[k].tipo==3){
            contadorC++;
        }
    }

    if ( contadorA !=0)printf("\n\ntipo 1(Sinfonica) = %d\n",contadorA);else{printf("No hay orquesta del tipo 1(Sinfonica)\n");}
    if ( contadorB !=0)printf("tipo 2(Filarmonica) = %d\n",contadorB);else{printf("No hay orquesta del tipo 2(Filarmonica)\n");}
    if ( contadorC !=0)printf("tipo 3(Camara) = %d\n",contadorC);else{printf("No hay orquesta del tipo 3(Camara)\n");}


}


///Examen Informes


void contarCantDeOrquesta(Orquesta* arrayOrquesta, int tamOrquesta, int* devuelve ){
    int k;
    int contador=0;

    for(k=0;k<tamOrquesta;k++){
        if(arrayOrquesta[k].isEmpty==0){
            contador =contador +1;
        }
    }
    *devuelve=contador;

}

void contarCantDeMusicos(Musico* arrayMusico, int tamMusico, int* devuelve ){
    int j;
    int contador=0;

    for(j=0;j<tamMusico;j++){
        if(arrayMusico[j].isEmpty==0){
            contador =contador +1;
        }
    }
    *devuelve=contador;

}

///a)Listar las Orq con mas de 5 musicos indicando ID DE ORQUESTA
///nombre tipo y lugar
void opcionA(Orquesta* arrayOrquesta, int tamOrquesta ,Musico* arrayMusico, int tamMusico){
    int j,k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int contador=0;

    for(k=0; k>tamOrquesta;k++){
        if(arrayOrquesta[k].isEmpty ==0){
        contador++;
        }
    }

    for(j=0; j>tamMusico;j++){
        if(arrayMusico[j].isEmpty == 0 && arrayMusico[j].idOrquesta){

        }
    }
}


///b)LIstar los musicos de mas de 30 años indicando ID MUSICO nombre apellido edad
///nombre del instrumento y nombre de la Orquesta a la que pertenece
void opcionB(Orquesta* arrayOrquesta, int tamOrquesta ,Musico* arrayMusico, int tamMusico ,Instrumento* arrayInstrumento, int tamInstrumento)
{
    int i,j,k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int auxIdOrq;
    int auxIdInst;
  //  for(i=0;i<tamMusico;i++){
 //   for(i=0;i<tamMusico;i++){
    for(j=0;j<tamMusico;j++){
        if(arrayMusico[j].isEmpty ==0 && arrayMusico[j].edad >=30){
            musico_lista(arrayMusico[j]);

            auxIdInst=arrayMusico[j].idInstrumento;
            auxIdOrq=arrayMusico[j].idOrquesta;

            for(i=0;i<tamInstrumento;i++){
                if(arrayInstrumento[i].isEmpty ==0 && arrayInstrumento[i].idUnico == auxIdInst){
                    instrumento_lista(arrayInstrumento[i]);
                }
            }
            for(k=0;k<tamOrquesta;k++){
                if(arrayOrquesta[k].isEmpty ==0 && arrayOrquesta[k].idUnico == auxIdOrq){
                    orquesta_lista(arrayOrquesta[k]);
                }
            }
            printf("\n----------------------------------------------------\n");
        }
    }
}


///c)Listar las orquestas de un lugar en particular ingresado por el usuario imprimir ID de orquesta nombre tipo y lugar
void opcionC(Orquesta* arrayOrquesta, int tamOrquesta){
    int k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    orquesta_listar (arrayOrquesta, tamOrquesta);
    char lugarBuscado[1000];

    printf("Ingrese el lugar de la orquesta:");
    scanf("%s",lugarBuscado);

    for(k=0;k<tamOrquesta;k++){
        if(arrayOrquesta[k].isEmpty==0 && (strcmp(arrayOrquesta[k].lugar , lugarBuscado)==0) ){
            orquesta_lista(arrayOrquesta[k]);
        }
    }

}



///e)MOstrar todos los musicos de una orquesta determinada(INgresado su ID)
///indicando nombre apeliido edad nombre y tipo de instrumento que toca
void opcionE(Orquesta* arrayOrquesta, int tamOrquesta ,Musico* arrayMusico, int tamMusico ,Instrumento* arrayInstrumento, int tamInstrumento)
{
    int i,j; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int idOrq;
    int aux;

    orquesta_listar(arrayOrquesta, tamOrquesta);
    printf("Ingrese el ID de la Orquesta");
    scanf("%d", &idOrq);


    for(j=0;j<tamMusico;j++){
        if( arrayMusico[j].isEmpty==0 && arrayMusico[j].idOrquesta == idOrq){

            musico_lista(arrayMusico[j]);
            aux = arrayMusico[j].idInstrumento;

            for(i=0;i>tamInstrumento;i++){
                if(arrayInstrumento[i].idUnico==aux){

                instrumento_lista(arrayInstrumento[i]);
            }
        }
    }
}

}


/*
///F imprimir la orquesta con mas musicos indicando todos sus datos y la cantidad de musicos q posee
void opcionF(Musico* arrayMusico, int tamMusico, Orquesta* arrayOrquesta, int tamOrquesta ){
    int j,k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int contadorCantDeOrq =0;
    int arrayDeIds[tamOrquesta];

    for(k=0;k<tamOrquestas;k++){
        if(arrayOrquesta[k].isEmpty ==0){
            contadorCantDeOrq++;
            arrayDeIds[k] = arrayOrquesta[k].idUnico;
        }
    }
    int array[contadorCantDeOrq];

    for(j=0;j<tamMusico;j++){
        if(arrayMusico[j].isEmpty==0 && arrayMusico[j].idOrquesta == ){

        }
    }

}*/


///h)imprimir el promedio de musicos por orquesta
void opcionH(Orquesta* arrayOrquesta, int tamOrquesta ,Musico* arrayMusico, int tamMusico){

    int j,k; ///I = INSTRUMENTO J = MUSICA   K = ORQUESTA
    int cantiOrques;
    int cantMusic;


    contarCantDeOrquesta(arrayOrquesta, tamOrquesta,  &cantiOrques );
    contarCantDeMusicos (arrayMusico , tamMusico,  &cantMusic);




}



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h" //cambiar por nombre entidad
#include "instrumento.h"
#include "orquesta.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)  //1 vacio 0 lleno                                  //cambiar musico
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty ==0 && array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


void musico_hardcodeo(Musico array[]){
    ///Orquesta (2 id1 -1  id2 - 1 id3 - 2 id4)
    ///Instrumento (1 id1 - 2 id2 -  id3 - 2 id4 - 1 id5 - id6 -  id7)

    array[0].idUnico=1;
    array[0].isEmpty=0;
    strcpy(array[0].nombre,"Mus1");
    strcpy(array[0].apellido,"Amus1");
    array[0].edad=30;
    array[0].idInstrumento=2;
    array[0].idOrquesta=1;

    array[1].idUnico=2;
    array[1].isEmpty=0;
    strcpy(array[1].nombre,"Mus2");
    strcpy(array[1].apellido,"Amus2");
    array[1].edad=20;
    array[1].idInstrumento=5;
    array[1].idOrquesta=2;///este

    array[2].idUnico=3;
    array[2].isEmpty=0;
    strcpy(array[2].nombre,"Mus3");
    strcpy(array[2].apellido,"Amus3");
    array[2].edad=25;
    array[2].idInstrumento=2;
    array[2].idOrquesta=4;

    array[3].idUnico=4;
    array[3].isEmpty=0;
    strcpy(array[3].nombre,"Mus4");
    strcpy(array[3].apellido,"Amus4");
    array[3].edad=27;
    array[3].idInstrumento=1;
    array[3].idOrquesta=4;///este

    array[4].idUnico=5;
    array[4].isEmpty=0;
    strcpy(array[4].nombre,"Mus5");
    strcpy(array[4].apellido,"Amus5");
    array[4].edad=22;
    array[4].idInstrumento=3;
    array[4].idOrquesta=1;

    array[5].idUnico=6;
    array[5].isEmpty=0;
    strcpy(array[5].nombre,"Mus6");
    strcpy(array[5].apellido,"Amus6");
    array[5].edad=35;
    array[5].idInstrumento=4;
    array[5].idOrquesta=3;///este

}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID)                          //cambiar musico
{
    int retorno=-1;
    int auxtipo;
    int posicion;
   // char caracter='s';
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar musico
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;


            utn_getUnsignedInt("\n edad: ","\nError",1,sizeof(int),1,99999999,1,&array[posicion].edad);           //mensaje + cambiar campo edad
            //utn_getFloat("\n varFloat: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloat);
            utn_getName("nombre\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("apellido\n: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                 //mensaje + cambiar campo apellido



            do{//orquesta
            auxtipo=utn_getUnsignedInt("\n tipo: ","\nError",1,sizeof(int),1,3,1,&array[posicion].idOrquesta);           //mensaje + cambiar campo tipo
            }while(auxtipo !=0);

            do{//instrumento
            auxtipo=utn_getUnsignedInt("\n tipo: ","\nError",1,sizeof(int),1,4,1,&array[posicion].idInstrumento);           //mensaje + cambiar campo tipo
            }while(auxtipo !=0);
           // utn_getUnsignedInt("\n edadAux: ","\nError",1,sizeof(int),1,99999,1,&array[posicion].edadAux);
            //utn_getFloat("\n varFloatAux: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloatAux);
            //utn_getTexto("nombreAux\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombreAux);
            //printf("\nIngrese un caracter:");
           // caracter=getchar();
            //array[posicion].varChar=caracter;
            printf("\n Posicion: %d\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s\n ID orquesta: %d\n ID instrumento: %d\n ",
                    posicion,
                    array[posicion].idUnico,
                    array[posicion].edad,
                    //array[posicion].varFloat,
                    array[posicion].nombre,
                    array[posicion].apellido,
                    array[posicion].idOrquesta,
                    array[posicion].idInstrumento
                    //array[posicion].varChar,
                    //array[posicion].edadAux,
                    //array[posicion].varFloatAux,
                    //array[posicion].nombreAux
                    );
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;

    if(array!=NULL )
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,100000,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            utn_getUnsignedInt("\n1-SI\n2-NO\n\n¿Seguro que desea borrar?:","No es una opcion valida",1,sizeof(int),1,2,3,&opcion);
            if(opcion==1)
            {
                array[posicion].isEmpty= 1;
                retorno=0;
                printf("\nBaja realizada con exito\n");
            }
            else{
                printf("\n La baja no se ha realizado");
            }
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;/*
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].edad=0;                                                               //cambiar campo edad
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }*/
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        musico_listar(array,sizeArray);
        utn_getUnsignedInt("\n\n\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s\n ID orquesta: %d\n ID instrumento: %d\n ",
                       posicion,
                       array[posicion].idUnico,
                       array[posicion].edad,
                       array[posicion].nombre,
                       array[posicion].apellido,
                       array[posicion].idOrquesta,
                       array[posicion].idInstrumento
                       );
                utn_getChar("\n\nModificar: A(edad) B(ID Orquesta)  S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)//
                {
                    case 'A'://int
                        utn_getUnsignedInt("\nedad ","\nError",1,sizeof(int),1,999999,1,&array[posicion].edad);           //mensaje + cambiar campo edad
                        break;
                    case 'B'://float
                        utn_getUnsignedInt("\n ID Orquesta: ","\nError",1,sizeof(int),1,3,1,&array[posicion].idOrquesta);
                        //utn_getFloat("\nvarFloat: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloat);
                        break;
                    case 'C'://string
                        //utn_getName("\nnombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'D'://string long
                        //utn_getTexto("\napellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);             //mensaje + cambiar campo apellido
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}



//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)                      //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty == 0){

                printf("\n ID: %d\n edad: %d\n nombre: %s\n apellido: %s\n ID orquesta: %d\n ID instrumento: %d\n",
                       array[i].idUnico,
                       array[i].edad,
                       array[i].nombre,
                       array[i].apellido,
                       array[i].idOrquesta,
                       array[i].idInstrumento
                       );
            }
        retorno=0;
        }

    }
    return retorno;
}

int musico_lista(Musico array){

    if(array.isEmpty == 0)
    {
        printf("\n(M) ID: %d edad: %d nombre: %s apellido: %s ID orquesta: %d ID instrumento: %d",
            array.idUnico,
            array.edad,
            array.nombre,
            array.apellido,
            array.idOrquesta,
            array.idInstrumento
            );
    }
    return 0;
}

int musico_listaIDString(Musico array){

    if(array.isEmpty == 0)
    {
        printf("\n\n ID: %d edad: %d nombre: %s apellido: %s \n",
            array.idUnico,
            array.edad,
            array.nombre,
            array.apellido
            );
        if(array.idOrquesta==1){printf("ID Orquesta: Sinfonica   ");}
        if(array.idOrquesta==2){printf("ID Orquesta: Filarmonica   ");}
        if(array.idOrquesta==3){printf("ID Orquesta: Camara   ");}

        if(array.idInstrumento==1){printf("ID Instrumento: Cuerdas");}
        if(array.idInstrumento==2){printf("ID Instrumento: viento-madera");}
        if(array.idInstrumento==3){printf("ID Instrumento: viento-metal");}
        if(array.idInstrumento==4){printf("ID Instrumento: Percusion");}

    }
    return 0;
}


void musico_imprimeUnMusico(Musico array[], int posicion){
    /*printf("\n ID: %d\t edad: %d\t varFloat: %f\n nombre: %s\t apellido: %s\n varChar %c\t edadAux: %d\t varFloatAux: %f\n nombreAux: %s",
        array[posicion].idUnico,
        array[posicion].edad,
        array[posicion].varFloat,
        array[posicion].nombre,
        array[posicion].apellido,
        array[posicion].varChar,
        array[posicion].edadAux,
        array[posicion].varFloatAux,
        array[posicion].nombreAux);*/
}


//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*//*
int musico_ordenarPorString(Musico array[],int size)                              //cambiar musico
{
    int retorno=-1;
    int i, j;
    Musico auxiliar;

    char bufferString[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo apellido

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].edad;                                //cambiar campo edad
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].apellido);          //cambiar campo apellido


            j = i - 1;
            while ((j >= 0) && strcmpi(bufferString,array[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].edad
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].edad=array[j].edad;                        //cambiar campo edad
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].apellido,array[j].apellido);  //cambiar campo apellido

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString);                     //cambiar campo nombre
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].edad=bufferInt;                                                        //cambiar campo edad
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].apellido,bufferLongString);                                  //cambiar campo apellido
        }
        retorno=0;
    }
    return retorno;
}*/


void musico_ordenarPorString2(Musico array[],int size)                              //cambiar autor
{
    printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Musico auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if ((strcmp(array[j].apellido,array[i].apellido)<0))
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;
                    }else if((strcmp(array[j].apellido,array[i].apellido)==0) && (strcmp(array[j].nombre,array[i].nombre)<0))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }
}


void musico_ordenarPorEntero(Musico array[],int size)                              //cambiar autor
{
 /*   printf("\nORDENADO POR ENTERO Y FLOAT\n");
    int i;
    Musico auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if (array[j].edad<=array[i].edad)
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;

                    }
                    if((array[j].edad==array[i].edad) && (array[j].varFloat<=array[i].varFloat))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }*/
}

void musico_semibaja(Musico array[],int size, int idAbajar){

    int i;
    for(i=0;i<size;i++){
        if(array[i].idOrquesta == idAbajar){
            array[i].isEmpty =1;
        }
    }
}



void OrdenaMusicosInsercion(Musico array[],int size){
    int i;
    int j;
    Musico aux;
    int auxEdad;

    musico_listar(array,size);

    for (i=1; i<size; i++){
        aux = array[i];
        auxEdad = array[i].edad;
        j = i - 1;
        while ( (array[j].edad < auxEdad) && (j >= 0) ){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;

    }
    printf("\n-------------------------------------------\n-------------------------------------------\n");
    musico_listar(array,size);
}


void OrdenaMusicosInsercionString(Musico array[],int size){
    int i;
    int j;
    Musico aux;
    char auxNombre[20];

    musico_listar(array,size);

    for (i=1; i<size; i++){
        aux = array[i];
        strcpy(auxNombre , array[i].nombre);
        j = i - 1;
        while ( (strcmp (array[j].nombre , auxNombre) > 0) && (j >= 0) ){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;

    }
    printf("\n-------------------------------------------\n-------------------------------------------\n");
    musico_listar(array,size);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int fantasma_Inicializar(Fantasma array[], int size)  //1 vacio 0 lleno                                  //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion)                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


void fantasma_hardcodeo(Fantasma array[]){
    array[0].idUnico=1;
    array[0].isEmpty=0;
    strcpy(array[0].varString,"matias");
    strcpy(array[0].varLongString,"palmieri");
    array[0].varInt=10;
    array[0].varFloat=88.1;
    array[0].varChar='a';
    array[0].varFloatAux=98.9;
    array[0].varIntAux=98;
    strcpy(array[0].varLongString,"ezequiel");


    array[1].idUnico=2;
    array[1].isEmpty=0;
    strcpy(array[1].varString,"zizue");
    strcpy(array[1].varLongString,"zidane");
    array[1].varInt=30;
    array[1].varFloat=22.2;
    array[1].varChar='z';
    array[0].varFloatAux=731.3;
    array[0].varIntAux=7;
    strcpy(array[0].varLongString,"real madrid");

    array[2].idUnico=3;
    array[2].isEmpty=0;
    strcpy(array[2].varString,"dario");
    strcpy(array[2].varLongString,"benedetto");
    array[2].varInt=30;
    array[2].varFloat=33.3;
    array[2].varChar='s';
    array[0].varFloatAux=8.1;
    array[0].varIntAux=9;
    strcpy(array[0].varLongString,"boca");

    array[3].idUnico=4;
    array[3].isEmpty=0;
    strcpy(array[3].varString,"matias");
    strcpy(array[3].varLongString,"bevilaqcua");
    array[3].varInt=40;
    array[3].varFloat=346.3;
    array[3].varChar='r';
    array[0].varFloatAux=178.9;
    array[0].varIntAux=15;
    strcpy(array[0].varLongString,"mama");
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    char caracter='s';
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;


            utn_getUnsignedInt("\n varInt: ","\nError",1,sizeof(int),1,99999999,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
            utn_getFloat("\n varFloat: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloat);
            utn_getName("varString\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("varLongString\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString

            utn_getUnsignedInt("\n varIntAux: ","\nError",1,sizeof(int),1,99999,1,&array[posicion].varIntAux);
            utn_getFloat("\n varFloatAux: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloatAux);
            utn_getTexto("varStringAux\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varStringAux);
            printf("\nIngrese un caracter:");
           // caracter=getchar();
            array[posicion].varChar=caracter;
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s\n varChar %c\n varIntAux: %d\n varFloatAux: %f\n varStringAux: %s",
                   posicion,
                   array[posicion].idUnico,array[posicion].varInt,
                   array[posicion].varFloat,array[posicion].varString,
                   array[posicion].varLongString,array[posicion].varChar,
                   array[posicion].varIntAux, array[posicion].varFloatAux, array[posicion].varStringAux);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;

    if(array!=NULL )
    {
        fantasma_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,100000,1,&id);          //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        fantasma_listar(array,sizeArray);
        utn_getUnsignedInt("\n\n\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                utn_getChar("\n\nModificar: A(varInt) B(varFloat) C(varString) D(varLongString) S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)//
                {
                    case 'A'://int
                        utn_getUnsignedInt("\nvarInt ","\nError",1,sizeof(int),1,999999,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B'://float
                        utn_getFloat("\nvarFloat: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloat);
                        break;
                    case 'C'://string
                        utn_getName("\nvarString: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D'://string long
                        utn_getTexto("\nvarLongString: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty == 0){

                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s\n varChar %c\n varIntAux: %d\t varFloatAux: %f\n varStringAux: %s",
                       array[i].idUnico,
                       array[i].varInt,
                       array[i].varFloat,
                       array[i].varString,
                       array[i].varLongString,
                       array[i].varChar,
                       array[i].varIntAux,
                       array[i].varFloatAux,
                       array[i].varStringAux);
            }
        retorno=0;
        }

    }
    return retorno;
}

int fantasma_lista(Fantasma array){

    if(array.isEmpty == 0)
    {
        printf("\n ID: %d varInt: %d varFloat: %f varString: %s varLongString: %s varChar %c varIntAux: %d varFloatAux: %f varStringAux: %s",
            array.idUnico,
            array.varInt,
            array.varFloat,
            array.varString,
            array.varLongString,
            array.varChar,
            array.varIntAux,
            array.varFloatAux,
            array.varStringAux);
    }
    return 0;
}

void fantasma_imprimeUnFantasma(Fantasma array[], int posicion){
    printf("\n ID: %d\t varInt: %d\t varFloat: %f\n varString: %s\t varLongString: %s\n varChar %c\t varIntAux: %d\t varFloatAux: %f\n varStringAux: %s",
        array[posicion].idUnico,
        array[posicion].varInt,
        array[posicion].varFloat,
        array[posicion].varString,
        array[posicion].varLongString,
        array[posicion].varChar,
        array[posicion].varIntAux,
        array[posicion].varFloatAux,
        array[posicion].varStringAux);
}


//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*//*
int fantasma_ordenarPorString(Fantasma array[],int size)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;
    Fantasma auxiliar;

    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].varInt;                                //cambiar campo varInt
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmpi(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}*/

///BURBUJA
void fantasma_ordenarPorString2(Fantasma array[],int size)                              //cambiar autor
{
    printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Fantasma auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if ((strcmp(array[j].varLongString,array[i].varLongString)<0))
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;
                    }else if((strcmp(array[j].varLongString,array[i].varLongString)==0) && (strcmp(array[j].varString,array[i].varString)<0))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }
}

///BURBUJA
void fantasma_ordenarPorEntero(Fantasma array[],int size)                              //cambiar autor
{
    printf("\nORDENADO POR ENTERO Y FLOAT\n");
    int i;
    Fantasma auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if (array[j].varInt<=array[i].varInt)
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;

                    }
                    if((array[j].varInt==array[i].varInt) && (array[j].varFloat<=array[i].varFloat))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }
}



//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenarPorStringInsercion(Fantasma array[],int size)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;

    char BvarString[TEXT_SIZE];
    int BvarInt;
    float BvarFloat;
    char BvarChar;
    char BvarLongString[TEXT_SIZE];
    int BvarIntAux;
    float BvarFloatAux;
    char BvarStringAux[TEXT_SIZE];
    int bufferIsEmpty;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(BvarString,array[i].varString);
            strcpy(BvarLongString,array[i].varLongString);
            BvarInt=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;
            BvarChar=array[i].varChar;
            BvarFloat=array[i].varFloat;
            strcpy(BvarStringAux,array[i].varStringAux);
            BvarIntAux=array[i].varIntAux;
            BvarFloatAux=array[i].varFloatAux;
            j = i - 1;

            while ((j >= 0) && strcmp(BvarString,array[j].varString)<0)         {
                strcpy(array[j + 1].varString,array[j].varString);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].varChar=array[j].varChar;
                array[j + 1].varFloat=array[j].varFloat;
                array[j + 1].varIntAux=array[j].varIntAux;
                array[j + 1].varFloatAux=array[j].varFloatAux;
                strcpy(array[j + 1].varLongString,array[j].varLongString);
                strcpy(array[j + 1].varStringAux,array[j].varStringAux);
                j--;
            }
            strcpy(array[j + 1].varString,BvarString);
            strcpy(array[j + 1].varLongString,BvarLongString);
            array[j + 1].idUnico=BvarInt;
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].varIntAux=BvarIntAux;
            array[j + 1].varChar=BvarChar;
            array[j + 1].varFloatAux=BvarFloatAux;
            array[j + 1].varFloat=BvarFloat;
            strcpy(array[j + 1].varStringAux,BvarStringAux);
        }
        retorno=0;
    }
    return retorno;
}

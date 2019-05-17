#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)  //1 vacio 0 lleno                                  //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)                    //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;/*
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)                                                   //cambiar campo tipo
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }*/
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice)                    //cambiar instrumento
{
    int retorno=-1;/*
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
    }*/
    return retorno;
}


void instrumento_hardcodeo(Instrumento array[]){
    array[0].idUnico=1;
    array[0].isEmpty=0;
    strcpy(array[0].nombre,"agudo");
    array[0].tipo=3;

    array[1].idUnico=2;
    array[1].isEmpty=0;
    strcpy(array[1].nombre,"grabe");
    array[1].tipo=4;

    array[2].idUnico=3;
    array[2].isEmpty=0;
    strcpy(array[2].nombre,"fino");
    array[2].tipo=2;

    array[3].idUnico=4;
    array[3].isEmpty=0;
    strcpy(array[3].nombre,"normal");
    array[3].tipo=1;

}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)                          //cambiar instrumento
{
    int retorno=-1;
    int posicion;
  //  char caracter='s';
    int auxtipo;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar instrumento
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;

            do{
            auxtipo=utn_getUnsignedInt("\n tipo: ","\nError",1,sizeof(int),1,4,1,&array[posicion].tipo);           //mensaje + cambiar campo tipo
            }while(auxtipo !=0);
            //utn_getFloat("\n varFloat: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloat);
            utn_getName("nombre\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            //utn_getTexto("varLongString\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString

            //utn_getUnsignedInt("\n tipoAux: ","\nError",1,sizeof(int),1,99999,1,&array[posicion].tipoAux);
            //utn_getFloat("\n varFloatAux: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloatAux);
            //utn_getTexto("nombreAux\n: ","\nError",1,TEXT_SIZE,1,array[posicion].nombreAux);
            //printf("\nIngrese un caracter:");
           // caracter=getchar();
            //array[posicion].varChar=caracter;
            printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s",
                   posicion,
                   array[posicion].idUnico,
                   array[posicion].tipo,
                  // array[posicion].varFloat,
                   array[posicion].nombre
                   //array[posicion].varLongString,
                   //array[posicion].varChar,
                   //array[posicion].tipoAux,
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento array[], int sizeArray)                                      //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;

    if(array!=NULL )
    {
        instrumento_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,100000,1,&id);          //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].tipo=0;                                                               //cambiar campo tipo
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }*/
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int instrumento_modificar(Instrumento array[], int sizeArray)                                //cambiar instrumento
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        instrumento_listar(array,sizeArray);
        utn_getUnsignedInt("\n\n\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(instrumento_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n tipo: %d\n nombre: %s",
                       posicion,
                        array[posicion].idUnico,
                        array[posicion].tipo,
                        //array[posicion].varFloat,
                        array[posicion].nombre
                       // array[posicion].varLongString
                       );
                utn_getChar("\n\nModificar: A(tipo) B(varFloat) C(nombre) D(varLongString) S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)//
                {
                    case 'A'://int
                        utn_getUnsignedInt("\ntipo ","\nError",1,sizeof(int),1,999999,1,&array[posicion].tipo);           //mensaje + cambiar campo tipo
                        break;
                    case 'B'://float
                       // utn_getFloat("\nvarFloat: ","\nError",1,13,0,sizeof(float),1,&array[posicion].varFloat);
                        break;
                    case 'C'://string
                        utn_getName("\nnombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
                        break;
                    case 'D'://string long
                        //utn_getTexto("\nvarLongString: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)                      //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty == 0){

                printf("\n ID: %d\n nombre: %s\n",
                        array[i].idUnico,
                        array[i].nombre);
                if(array[i].tipo ==1){/// 1=Cuerdas 2 viento_madera 3 viento_metal 4 percusion
                    printf(" tipo: Cuerdas\n");
                }
                if(array[i].tipo ==2){
                    printf(" tipo: Viento_madera\n");
                }
                if(array[i].tipo ==3){
                    printf(" tipo: Viento_metal\n");
                }
                if(array[i].tipo ==4){
                    printf(" tipo: Percusion\n");
                }
            }
        retorno=0;
        }

    }
    return retorno;
}

int instrumento_lista(Instrumento array){

    if(array.isEmpty == 0)
    {
        printf("\n ID: %d tipo: %d nombre: %s ",
            array.idUnico,
            array.tipo,
            //array.varFloat,
            array.nombre
            //array.varLongString,
            //array.varChar,
            //array.tipoAux,
            //array.varFloatAux,
            //array.nombreAux
            );
    }
    return 0;
}

void instrumento_imprimeUnInstrumento(Instrumento array[], int posicion){
    printf("\n ID: %d\t tipo: %d\t nombre: %s",
        array[posicion].idUnico,
        array[posicion].tipo,
        //array[posicion].varFloat,
        array[posicion].nombre
       // array[posicion].varLongString,
        //array[posicion].varChar,
        //array[posicion].tipoAux,
        //array[posicion].varFloatAux,
        //array[posicion].nombreAux
        );
}


//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*//*
int instrumento_ordenarPorString(Instrumento array[],int size)                              //cambiar instrumento
{
    int retorno=-1;
    int i, j;
    Instrumento auxiliar;

    char bufferString[TEXT_SIZE];                               //cambiar campo nombre
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);                      //cambiar campo nombre
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].tipo;                                //cambiar campo tipo
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmpi(bufferString,array[j].nombre)<0)         //cambiar campo nombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].tipo
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo nombre
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].tipo=array[j].tipo;                        //cambiar campo tipo
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString);                     //cambiar campo nombre
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].tipo=bufferInt;                                                        //cambiar campo tipo
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}*/


void instrumento_ordenarPorString2(Instrumento array[],int size)                              //cambiar autor
{
   /* printf("\nORDENADO POR APELLIDO Y NOMBRE\n");
    int i;
    Instrumento auxiliar;
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
                    }else if((strcmp(array[j].varLongString,array[i].varLongString)==0) && (strcmp(array[j].nombre,array[i].nombre)<0))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }*/
}


void instrumento_ordenarPorEntero(Instrumento array[],int size)                              //cambiar autor
{
  /* printf("\nORDENADO POR ENTERO Y FLOAT\n");
    int i;
    Instrumento auxiliar;
    int j;

      for(i=0 ; i<size-1 ; i++)
        {
            for(j=i+1; j<size ; j++)
            {
                if((array[i].isEmpty==0) && (array[j].isEmpty==0))
                {
                    if (array[j].tipo<=array[i].tipo)
                    {
                        auxiliar=array[i];
                        array[i]=array[j];
                        array[j]=auxiliar;

                    }
                    if((array[j].tipo==array[i].tipo) && (array[j].varFloat<=array[i].varFloat))
                        {
                            auxiliar=array[i];
                            array[i]=array[j];
                            array[j]=auxiliar;
                        }
                }
            }
        }*/
}

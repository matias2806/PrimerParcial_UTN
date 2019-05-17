#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];//varString
    int tipo;//varInt
    //float varFloat;
    //char varChar;
    char lugar[TEXT_SIZE];//varLongString
    //int varIntAux;
   // float varFloatAux;
    //char varStringAux[TEXT_SIZE];

}Orquesta;


#endif // ORQUESTA_H_INCLUDED

int orquesta_Inicializar(Orquesta array[], int size);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);                    //cambiar orquesta

void orquesta_hardcodeo(Orquesta array[]);
int orquesta_alta(Orquesta array[], int size, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta array[], int sizeArray, int* IdFutBaja);                                     //cambiar orquesta
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int sizeArray);                                //cambiar orquesta

int orquesta_listar(Orquesta array[], int size);                      //cambiar orquesta
int orquesta_lista(Orquesta array);
void orquesta_imprimeUnOrquesta(Orquesta array[], int posicion);

int orquesta_ordenarPorString(Orquesta array[],int size);                              //cambiar orquesta
void orquesta_ordenarPorString2(Orquesta array[],int size);
void orquesta_ordenarPorEntero(Orquesta array[],int size);


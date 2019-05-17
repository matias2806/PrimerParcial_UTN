#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];//varString
    int edad;//varInt
    //float varFloat;
    //char varChar;
    char apellido[TEXT_SIZE];//varLongString
    int idOrquesta;//varIntAux
    //float varFloatAux;
    //char varStringAux[TEXT_SIZE];
    int idInstrumento;

}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);                    //cambiar musico

void musico_hardcodeo(Musico array[]);
int musico_alta(Musico array[], int size, int* contadorID);                          //cambiar musico
int musico_baja(Musico array[], int sizeArray);                                      //cambiar musico
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);                                //cambiar musico

int musico_listar(Musico array[], int size);                      //cambiar musico
int musico_lista(Musico array);
void musico_imprimeUnMusico(Musico array[], int posicion);

int musico_ordenarPorString(Musico array[],int size);                              //cambiar musico
void musico_ordenarPorString2(Musico array[],int size);
void musico_ordenarPorEntero(Musico array[],int size);


void musico_semibaja(Musico array[],int size, int idAbajar);

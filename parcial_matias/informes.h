#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


///opcion 1  Mostrar todos los musicos que tengan algun tipo de instrumento
///opcion 2  Mostrar todos los musicos que NO esten en alguna orquesta

///opcion 3  imprimir una orquesta con sus respectivos músicos y los instrumentos que
///utiliza cada uno respetando el siguiente esquema...
///Ejemplo....
///---------- ORQUESTA "ALE EL BOLUDO" -----------------
///datos músico
///datos instrumento que utiliza
///datos músico
///datos instrumento que utiliza
///datos músico
///datos instrumento que utiliza
///datos músico
///datos instrumento que utiliza

///opcion 5. Listar los instrumentos que tiene una orquesta determinada
///opcion 6. informar de menor a mayor según la cantidad de músicos que tiene una orquesta
///opcion 7. indicar la cantidad de instrumentos que tienen los tipos de instrumentos
///opcion 8. listar la cantidad de músicos que pertenecen a cada orquesta
///opcion 9. Imprimir todos los músicos los cuales su edad no supere el promedio de TODOS los músicos
///opcion 10. contabilizar la cantidad de orquestas según su tipo, ejemplo
///tipo 1= 20
///tipo 2= ...
///tipo 3= ..
///en caso de no haber mostrar el mensaje "no hay orquestas de tipo ......."

void opcion1(Musico* arrayMusico, int tamMusico, int tipoInstrumento );
void opcion2(Musico* arrayMusico, int tamMusico, int NoTipoOrquesta );


void opcion3(Musico* arrayMusico, int tamMusico, Instrumento* arrayInstrumento, int tamInstrumento , Orquesta* arrayOrquesta, int tamOrquesta );
void opcion5(Musico* arrayMusico, int tamMusico, Instrumento* arrayInstrumento, int tamInstrumento , Orquesta* arrayOrquesta, int tamOrquesta );



void opcion6(Musico* arrayMusico, int tamMusico, Orquesta* arrayOrquesta, int tamOrquesta );
void opcion7(Instrumento* arrayInstrumento, int tamInstrumento, int tipoInstrumento);
void opcion8(Musico* arrayMusico, int tamMusico, Orquesta* arrayOrquesta, int tamOrquesta );
void opcion9(Musico* arrayMusico, int tamMusico);
void opcion10(Orquesta* arrayOrquesta, int tamOrquesta );

///Examen Informes
void contarCantDeOrquesta(Orquesta* arrayOrquesta, int tamOrquesta, int* devuelve );
void contarCantDeMusicos(Musico* arrayMusico, int tamMusico, int* devuelve );
void opcionB(Orquesta* arrayOrquesta, int tamOrquesta ,Musico* arrayMusico, int tamMusico ,Instrumento* arrayInstrumento, int tamInstrumento);
void opcionC(Orquesta* arrayOrquesta, int tamOrquesta);
void opcionE(Orquesta* arrayOrquesta, int tamOrquesta ,Musico* arrayMusico, int tamMusico ,Instrumento* arrayInstrumento, int tamInstrumento);
#endif

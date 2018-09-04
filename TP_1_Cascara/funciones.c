
#define INT_MAX 32767
#define INT_MIN -32767

/** \brief Suma de dos numeros enteros
 * \param x int Primer numero enteros
 * \param y int Segundo numero enteros
 * \param resultado int* Resultado pasado por referencia
 * \return int si esta todo bien 0, si es - overflow -1 o si es + overflow -2;
 */
int sumar(int x, int y, int *resultado)
{
    int retorno = -1;
    long numeroAuxiliar;
    numeroAuxiliar= x+y;
    if (numeroAuxiliar < INT_MAX && numeroAuxiliar > INT_MIN)
    {
        retorno = 0;
        *resultado= numeroAuxiliar;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}
/** \brief Resta de enteros
 * \param x int El primer numero a restar
 * \param y int El segundo numero a restar
 * \param resultado int* Resultado pasado pasado por referencia
 * \return int si esta todo bien 0, si es - overflow -1 o si es + overflow -2;
 */
int restar(int x, int y, int *resultado)
{
    int retorno = -1;
    long numeroAuxiliar;
    numeroAuxiliar= x-y;
    if (numeroAuxiliar < INT_MAX && numeroAuxiliar > INT_MIN)
    {
        retorno = 0;
        *resultado= numeroAuxiliar;
    }
    else
    {
        retorno= -1;
    }
    return retorno;
}
/** \brief División de enteros
 * \param x enteros Primer numero a dividir
 * \param y enteros Segundo numero a dividir
 * \param resultado enteros* devuelve el resultado pasado por referencia
 * \return enteros  si esta todo bien 0, si y es = 0 devuelve -1,
 */
int dividir(int x, int y, float *resultadoDivision)
{
    int retorno = -1;
    double numeroAuxiliar;

    if (y == 0)
    {
        retorno = -1;
    }
    else
    {
        numeroAuxiliar= (float)x/y;
        *resultadoDivision= numeroAuxiliar;
        retorno = 0;
    }
    return retorno;
}
/** \brief Multiplicación de enteros
 * \param x int Primer numero a multiplicar
 * \param y int Segundo numero a multiplicar
 * \param resultado int* devuelve el resultado pasado por referencia
 * \return int si esta todo bien 0, si es - overflow -1 o si es + overflow -2;
 */
int multiplicar(int x, int y, int *resultado)
{
    int retorno= -1;
    long numeroAuxiliar;
    numeroAuxiliar= x*y;
    if (numeroAuxiliar < INT_MAX && numeroAuxiliar > INT_MIN)
    {
        retorno = 0;
        *resultado= numeroAuxiliar;
    }

    return retorno;
}
/** \brief Factorizacion de una numero
 * \param x int Numero a factorizar
 * \param resultado int* devuelve el resultado pasado por referencia
 * \return int si todo esta bien 0, si el numero < 0 devuelve -1
 */
int factoriar(int x, int* resultado)
{
    int retorno = -1;
    long numeroAuxiliar = 1;
    if (x < 0 && x < INT_MAX && x > INT_MIN)
    {
        retorno= -1;
    }
    else
    {
        for (int i = 1; i <= x; i++)
        {
            numeroAuxiliar= numeroAuxiliar * i;
        }
        *resultado= numeroAuxiliar;
        retorno= 0;
    }
    return retorno;
}


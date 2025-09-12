#include <iostream> //stdio.h
#include <cmath>
// #define debug
int main()
{
    /*
    If/condicional else
    */
    int a = 5;
    int b = 10;
    if (a > b)
    {
        std::cout << "a es mayor que b" << std::endl;
    }
    else if (a < b)
    {
        std::cout << "a es menor que b" << std::endl;
    }
    else
    {
        std::cout << "a es igual a b" << std::endl;
    }
    int num1, num2;
    std::cout << "Ingrese dos números enteros: ";
    std::cin >> num1 >> num2;
    if ((num1 % 2 == 0 && num2 % 2 == 0))
    {
        std::cout << "Ambos números son pares." << std::endl;
    }
    else if (num1 % 2 == 1 && num2 % 2 != 0)
    {
        std::cout << "Ambos números son impares." << std::endl;
    }
    else if (num1 % 2 == 0 && num2 % 2 != 0)
    {
        std::cout << "El primer número es par y el segundo es impar." << std::endl;
    }
    else
    {
        std::cout << "El primer número es impar y el segundo es par." << std::endl;
    }
    /*
    for and arrays
    */
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 5; i > 0; i--)
    {
        std::cout << "arr[" << i << "]: " << arr[i - 1] << std::endl;
    }
    arr[0] = 12;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = pow(2, i);
        std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
    }
    char matriz[3][3] = {{'e', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    bool found = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "matriz[" << i << "][" << j << "]: " << matriz[i][j] << std::endl;
            if (matriz[i][j] == 'e')
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    int *pToInt;
    pToInt = &arr[0];
    std::cout << "Valor apuntado por pToInt: " << *pToInt << std::endl;
    pToInt = &a;
    std::cout << "Valor apuntado por pToInt: " << *pToInt << std::endl;
    *pToInt = 20;
    std::cout << "Valor de a: " << a << std::endl;
    pToInt = &arr[0];
    for (int i = 0; i < 5; i++, pToInt++)
    {
        std::cout << "Valor apuntado por pToInt  " << i << ": " << *pToInt << std::endl;
    }
    /*
    While and do while
    */
    int count = 0;
    char userInput = 'q';
    while (userInput != 'q')
    {
        std::cout << "Ingrese un carácter (y para continuar, n para salir): ";
        std::cin >> userInput;
        std::cout << "Carácter # " << count + 1 << "ingresado: " << userInput << std::endl;
        count++;
        if (count > 5)
        {
            break;
        }
    }
    userInput = 'q';
    count = 0;
    do
    {
        std::cout << "Ingrese un carácter (q para salir): ";
        std::cin >> userInput;
        std::cout << "Carácter # " << count + 1 << "ingresado: " << userInput << std::endl;
        count++;
        if (count > 10)
        {
            break;
        }
    } while (userInput != 'q');

    /*
    Switch case
    */
    short code;
    userInput = 'a';
    while (userInput != 'q')
    {
        std::cout << "Ingrese un código de respuesta http (200, 301, 404, 500): ";
        std::cin >> code;
        switch (code)
        {
        case 200:
            std::cout << "OK" << std::endl;
            break;
        case 301:
            std::cout << "Redirección permanente" << std::endl;
            break;
        case 404:
            std::cout << "No encontrado" << std::endl;
            break;
        case 500:
            std::cout << "Error interno del servidor" << std::endl;
            break;
        default:
            std::cout << "Código no reconocido" << std::endl;
            break;
        }
        std::cout << "Ingrese un carácter (q para salir): ";
        std::cin >> userInput;
    }
    return 0;
}

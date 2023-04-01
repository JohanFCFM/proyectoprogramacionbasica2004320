#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Videojuego 
{
    int num_articulo;
    string nombre;
    string descripcion;
    string genero;
    string clasificacion_edad;
    string consola;
    float precio;
};

Videojuego nuevo_videojuego[3];

int main() 
{
    int menu; 

    printf("BIENVENIDO A GAMERS \n");
    printf("1. Alta de articulos \n");
    printf("2. Modificacion de articulos \n");
    printf("3. Baja de articulos \n");
    printf("4. Lista de articulos \n");
    printf("5. Limpiar pantalla \n");
    printf("6. Salir \n");
    scanf_s("%d", &menu);

    switch (menu)
    {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                printf("Introduzca el numero del articulo: \n");
                scanf_s("%d", &nuevo_videojuego[i].num_articulo);

                printf("Introduzca el nombre del articulo: \n");
                cin.ignore();
                getline(cin, nuevo_videojuego[i].nombre);

                printf("Introduzca la descripcion del articulo: \n");
                getline(cin, nuevo_videojuego[i].descripcion);

                printf("Introduzca el genero del articulo: \n");
                getline(cin, nuevo_videojuego[i].genero);

                printf("Introduzca la clasificacion de edad del articulo: \n");
                getline(cin, nuevo_videojuego[i].clasificacion_edad);

                printf("Introduzca la consola del articulo: \n");
                getline(cin, nuevo_videojuego[i].consola);

                printf("Introduzca el precio del articulo: \n");
                scanf_s("%f", &nuevo_videojuego[i].precio);

                nuevo_videojuego[i].precio = nuevo_videojuego[i].precio + (nuevo_videojuego[i].precio * 0.16);
            }

        return main();
        break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            printf("Articulos dados de Alta: \n");
            for (int i = 0; i < 3; i++)
            {
                printf("Numero de articulo: %d \n", nuevo_videojuego[i].num_articulo);
                printf("Nombre: %s \n", nuevo_videojuego[i].nombre.c_str());
                printf("Descripcion: %s \n", nuevo_videojuego[i].descripcion.c_str());
                printf("Genero: %s \n", nuevo_videojuego[i].genero.c_str());
                printf("Clasificacion de edad: %s \n", nuevo_videojuego[i].clasificacion_edad.c_str());
                printf("Consola: %s \n", nuevo_videojuego[i].consola.c_str());
                printf("Precio: $ %f \n", nuevo_videojuego[i].precio);
            }
            return main();
            break;

        case 5:
            system("cls");
            return main();
            break;

        case 6:
            printf("Muchas Gracias por su visita \n");
            system("exit");
            break;

        default:
            printf("Opcion invalida \n");
            return main();
            break;

    }
}

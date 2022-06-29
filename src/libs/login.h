// Ramiro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 80
#define ARCHIVO_USUARIOS "usuarios.dat"
#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3

/* Estructura de cuentas de usuario */
struct usuario
{
    char nombre[MAX];
    char password[MAX];
};

typedef struct usuario Usuario;

/* Funciones de menú */
void menuInicial();
void menuListarUsuarios();
void menuRegistrarUsuario();
void menuIniciarSesion();
void menuSistema();

/* Funciones que manipulan el archivo de usuarios */
char insertarUsuario(Usuario usuario);
char existeUsuario(char nombreUsuario[], Usuario *usuario);
Usuario *obtenerUsuarios(int *);
char logear(char nombreUsuario[], char password[]);

int leerLinea(char *cad, int n);
void leerClave(char *password);

char linea[MAX];
/*int main()
{
    menuInicial();
    return 0;
}*/

void menuInicial()
{
    char repite = 1;
    int opcion = -1;

    do
    {
        system("cls");
        printf("\n\t\t\tMENU INICIAL\n");
        printf("\t\t\t============\n");
        printf("\n\t\t[1]. Ver usuarios registrados\n");
        printf("\t\t[2]. Registrar usuario nuevo\n");
        printf("\t\t[3]. Ingresar al sistema\n");
        printf("\t\t[0]. Salir\n");
        printf("\n\t\tIngrese su opcion: [ ]\b\b");
        leerLinea(linea, MAX);
        sscanf(linea, "%d", &opcion);

        switch (opcion)
        {
        case 1:
            menuListarUsuarios();
            break;

        case 2:
            menuRegistrarUsuario();
            break;

        case 3:
            menuIniciarSesion();
            break;

        case 0:
            repite = 0;
            break;
        }

    } while (repite == 1);
}

void menuRegistrarUsuario()
{
    Usuario usuario;
    char nombreUsuario[MAX];
    char respuesta[MAX];
    char repite = 1;

    do
    {
        system("cls");
        printf("\n\t\t\tREGISTRAR USUARIO\n");
        printf("\t\t\t=================\n");
        printf("\n\tIngrese nombre de usuario: ");
        leerLinea(linea, MAX);
        sscanf(linea, "%s", nombreUsuario);

        /* Se verifica que el nombre de usuario no exista */
        if (!existeUsuario(nombreUsuario, &usuario))
        {
            strcpy(usuario.nombre, nombreUsuario);

            printf("\tIngrese la clave: ");
            leerLinea(usuario.password, MAX);

            /* Se inserta el usuario en el archivo de usuarios */
            if (insertarUsuario(usuario))
            {
                printf("\n\tEl usuario fue registrado satisfactoriamente!\n");
            }
            else
            {
                printf("\n\tOcurrio un error al registrar el usuario\n");
                printf("\nInténtelo mas tarde\n");
            }
        }
        else
        {
            printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", usuario.nombre);
            printf("\tNo puede registrar dos usuarios con el mismo nombre de usuario.\n");
        }

        printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
        leerLinea(respuesta, MAX);

        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0))
        {
            repite = 0;
        }

    } while (repite == 1);
}

void menuListarUsuarios()
{
    int numeroUsuarios = 0;
    Usuario *usuarios;
    int i;

    system("cls");
    usuarios = obtenerUsuarios(&numeroUsuarios); /* Retorna un vector dinámico de usuarios */

    if (numeroUsuarios == 0)
    {
        printf("\n\tNo existe ningun usuario registrado!\n");
    }
    else
    {
        printf("\n\t\t    ==> LISTADO DE USUARIOS REGISTRADOS <==\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("%10s%25s%25s\n", "#", "NOMBRE", "PASSWORD");
        printf(" ------------------------------------------------------------------------------\n");

        /* Se recorre el vector dinámico de productos */
        for (i = 0; i < numeroUsuarios; i++)
        {
            printf("%10d%25s%25s\n", (i + 1), usuarios[i].nombre, usuarios[i].password);
        }
        printf(" ------------------------------------------------------------------------------\n");
    }

    // Se libera la memoria asignada al vector dinámico
    free(usuarios);
    usuarios = NULL;
    getchar();
}

void menuIniciarSesion()
{
    char nombreUsuario[MAX];
    char password[MAX];
    int intento = 0;
    int loginExitoso = 0;

    do
    {
        system("cls");
        printf("\n\t\t\tINGRESAR AL SISTEMA\n");
        printf("\t\t\t===================\n");

        printf("\n\t\tUSUARIO: ");
        leerLinea(linea, MAX);
        sscanf(linea, "%s", nombreUsuario);

        printf("\t\tCLAVE: ");
        leerClave(password);

        if (logear(nombreUsuario, password))
        {
            loginExitoso = 1;
        }
        else
        {
            printf("\n\n\t\tUsuario y/o password incorrectos");
            intento++;
            getchar();
        }
    } while (intento < MAX_INTENTOS && loginExitoso == 0);

    if (loginExitoso == 1)
    {
        menuSistema();
    }
    else
    {
        printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
        getchar();
    }
}

void menuSistema()
{
    system("cls");
    printf("\n     ======================================================================\n");
    printf("\t\t\t     BIENVENIDO AL SISTEMA\n");
    printf("\t\t    Sistema de emision de tickets\n");
    printf("\t\t    Ayala - Rolheiser - Uffelmann\n");
    printf("     ======================================================================\n");

    InitialConfigTicket();
    SetListProducts(); // Inicializar la lista de productos global
    MenuSystem();

    getchar();
}

/* Retorna 1 si se registró el usuario en el archivo correctamente */
char insertarUsuario(Usuario usuario)
{
    FILE *archivo;
    char insercion = 0;

    /* Abre el archivo en modo de añadidura, para agregar datos al final. Si no existe es creado*/
    archivo = fopen(ARCHIVO_USUARIOS, "ab");

    if (archivo == NULL)
    {
        insercion = 0;
    }
    else
    {
        /* Registra el struct usuario en el archivo */
        fwrite(&usuario, sizeof(usuario), 1, archivo);
        insercion = 1;

        /* Cierra el archivo */
        fclose(archivo);
    }

    return insercion;
}

/* Retorna 1 si existe el nombre de usuario. Retorna el usuario buscado si existe */
char existeUsuario(char nombreUsuario[], Usuario *usuario)
{
    FILE *archivo;
    char existe;

    /* Abre el archivo en modo de lectura */
    archivo = fopen(ARCHIVO_USUARIOS, "rb");

    if (archivo == NULL)
    {
        existe = 0;
    }
    else
    {
        existe = 0;

        /* Lee secuencialmente del archivo de usuarios */
        fread(&(*usuario), sizeof(*usuario), 1, archivo);
        while (!feof(archivo))
        {
            if (strcmp((*usuario).nombre, nombreUsuario) == 0)
            {
                /* Encuentra un usuario del archivo con el nombre de usuario buscado */
                existe = 1;
                break;
            }

            fread(&(*usuario), sizeof(*usuario), 1, archivo);
        }

        /* Cierra el archivo*/
        fclose(archivo);
    }

    return existe;
}

Usuario *obtenerUsuarios(int *n)
{
    FILE *archivo;
    Usuario usuario;
    Usuario *usuarios; /* Vector dinámico de usuarios */
    int i;

    /* Abre el archivo en modo lectura */
    archivo = fopen(ARCHIVO_USUARIOS, "rb");

    if (archivo == NULL)
    {           /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
        *n = 0; /* No se pudo abrir. Se considera n = 0 */
        usuarios = NULL;
    }
    else
    {

        fseek(archivo, 0, SEEK_END);                          /* Posiciona el cursor al final del archivo */
        *n = ftell(archivo) / sizeof(Usuario);                /* # de usuarios almacenados en el archivo. (# de registros) */
        usuarios = (Usuario *)malloc((*n) * sizeof(Usuario)); /* Se asigna memoria para todos los usuarios almacenados en el archivo */

        /* Se recorre el archivo secuencialmente */
        fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
        fread(&usuario, sizeof(usuario), 1, archivo);
        i = 0;
        while (!feof(archivo))
        {
            usuarios[i++] = usuario;
            fread(&usuario, sizeof(usuario), 1, archivo);
        }

        /* Cierra el archivo */
        fclose(archivo);
    }

    return usuarios;
}

/* Retorna 1 o 0 si el usuario y password son correctos para un usuario en particular */
char logear(char nombreUsuario[], char password[])
{
    FILE *archivo;
    char logeoExitoso;
    Usuario usuario;

    /* Abre el archivo en modo de lectura */
    archivo = fopen(ARCHIVO_USUARIOS, "rb");

    if (archivo == NULL)
    {
        logeoExitoso = 0;
    }
    else
    {
        logeoExitoso = 0;

        /* Lee secuencialmente del archivo de usuarios */
        fread(&usuario, sizeof(usuario), 1, archivo);
        while (!feof(archivo))
        {
            if (strcmp(usuario.nombre, nombreUsuario) == 0 && strcmp(usuario.password, password) == 0)
            {
                /* Encuentra un usuario del archivo con el nombre de usuario y password buscado */
                logeoExitoso = 1;
                break;
            }

            fread(&usuario, sizeof(usuario), 1, archivo);
        }

        /* Cierra el archivo*/
        fclose(archivo);
    }

    return logeoExitoso;
}

int leerLinea(char *cad, int n)
{
    int i, c;

    /* 1 COMPROBACIÓN DE DATOS INICIALES EN EL BUFFER */
    c = getchar();
    if (c == EOF)
    {
        cad[0] = '\0';
        return 0;
    }

    if (c == '\n')
    {
        i = 0;
    }
    else
    {
        cad[0] = c;
        i = 1;
    }

    /* 2. LECTURA DE LA CADENA */
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        cad[i] = c;
    }
    cad[i] = '\0';

    /*3. LIMPIEZA DEL BUFFER */
    if (c != '\n' && c != EOF) /* es un caracter */
        while ((c = getchar()) != '\n' && c != EOF)
            ;

    return 1;
}

void leerClave(char *password)
{
    char caracter;
    int i = 0;

    while (caracter = getch())
    {
        if (caracter == TECLA_ENTER)
        {
            password[i] = '\0';
            break;
        }
        else if (caracter == TECLA_BACKSPACE)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            if (i < MAX)
            {
                printf("*");
                password[i] = caracter;
                i++;
            }
        }
    }
}
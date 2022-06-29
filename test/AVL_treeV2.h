#include <stdio.h>
#include <stdlib.h>
#include "./momentC.h"

// Estructura de los Productos
struct Item{
	int idItem;
	char *name;
	double price;
};

// Estructura de los Productos del Ticket
struct ItemTicket{
	float quantity;
	struct Item *itemInfo;
	struct ItemTicket *next;
};

// Estructura de arbol aVL
struct Ticket{
	int id;
	char *date;
	char *time;
	char *resIVA;
	struct ItemTicket *ProductsTicket;
	struct Ticket *left;
	struct Ticket *right;
	int height;
};

// struct Ticket{
// 	char *date;
// 	char *time;
// 	char *resIVA;
// 	struct ItemTicket *itemTicket;
// };

// struct TicketTree{
// 	unsigned int id;
// 	struct Ticket ticket;
// 	struct TicketTree *left;
// 	struct TicketTree *right;
// };


// Carlos

// void InsertTicket(){
//   // printf("PROBLEMS 1\n");
//   struct TicketTree *pNewTicketTreeItem = (struct TicketTree *)malloc(sizeof(struct TicketTree));
//   // printf("PROBLEMS 2\n");

//   // DATOS DEL TICKET
//   // id
//   pNewTicketTreeItem->id = id_tickets;
//   // Hora y Fecha
//   pNewTicketTreeItem->ticket.time = getTime();
//   // // printf("TIME: %s\n", pNewTicketTreeItem->ticket.time);
//   pNewTicketTreeItem->ticket.date = getDate();
//   // // printf("DATE: %s\n", pNewTicketTreeItem->ticket.date);

//   // Items del ticket - Dont work
//   // InsertItemTicket(); 
//   // pNewTicketTreeItem->ticket.itemTicket = pAuxItemTicket;


//   // Responsabilidad frente al IVA del emisor
//   pNewTicketTreeItem->ticket.resIVA = IVAResponsability();


//   pNewTicketTreeItem->left = NULL;
//   pNewTicketTreeItem->right = NULL;



//   if (pTicketTree == NULL){
//     pTicketTree = pNewTicketTreeItem;
//   } else{
//     struct TicketTree *previus, *current;
//     previus = NULL;
//     current = pTicketTree;
//     while (current != NULL){
//       previus = current;
//       if (pNewTicketTreeItem->id < current->id){
//         current = current->left;
//       } else{
//         current = current->right;
//       }
//     }
//     if (pNewTicketTreeItem->id < previus->id){
//       previus->left = pNewTicketTreeItem;
//     } else{
//       previus->right = pNewTicketTreeItem;
//     }
//   }

//   // Limpio el puntero auxiliar
//   pAuxItemTicket = NULL;

//   // Incrementa el contador de ID de tickets para el príximo ticket
//   id_tickets++;
// }

void PrintMessage(char *message, char *type){
	printf("\n");
	printf("%s: %s\n", type, message);
	printf("\n");
}

char *IVAResponsability(){
	int option;
	char *responsability[] = { "IVA Responsable Inscripto", "IVA no Responsable", "IVA exento", "Responsable Monotributo",
	"Monotributista Social" };

	do{
		printf("Responsabilidad frente al impuesto al valor agregado del emisor segun corresponda:\n");
		printf("1. IVA Responsable Inscripto\n");
		printf("2. IVA no Responsable\n");
		printf("3. IVA exento\n");
		printf("4. Responsable Monotributo\n");
		printf("5. Monotributista Social\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		if (option < 1 || option > 5){
			PrintMessage("Opcion invalida", "Error");
		}
	} while (option < 1 || option > 5);

	return responsability[option - 1];
}

// Carlos


// Funcion para calcular la altura
int height(struct Ticket *N){
	if (N == NULL) return 0;
	return N->height;
}

// Funcion para hallar el maximo entre dos enteros
int max(int a, int b){
	return (a > b) ? a : b;
}

/* Funcion que crea un nuevo Ticket. */
struct Ticket *newTicket(int id){
	struct Ticket *Ticket = (struct Ticket *)malloc(sizeof(struct Ticket));
	Ticket->id = id;
	Ticket->date = getDate(); // Obtiene la fecha actual
	Ticket->time = getTime(); // Obtiene la hora actual
	Ticket->resIVA = IVAResponsability();

	// Generar Lista de Productos - empty

	Ticket->left = NULL;
	Ticket->right = NULL;
	Ticket->height = 1; // se debe inicializar

	return Ticket;
}

// Funcion para rotar a la derecha el subarbol y
struct Ticket *rightRotate(struct Ticket *y){
	struct Ticket *x = y->left;
	struct Ticket *T2 = x->right;
	// Se realiza la rotacion
	x->right = y;
	y->left = T2;
	// Actualizacion de alturas
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	// devuelve nueva raiz
	return x;
}

// Funcion para rotar a la izquierda el sub�rbol x
struct Ticket *leftRotate(struct Ticket *x){
	struct Ticket *y = x->right;
	struct Ticket *T2 = y->left;
	// Se realiza rotacion
	y->left = x;
	x->right = T2;
	// Actualizacion de alturas
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	// retorna nueva raiz
	return y;
}


// Calcular el FB del Ticket
int getBalance(struct Ticket *N){
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Ticket *insert(struct Ticket *Ticket, int id){
	/* 1. Se realiza la rotacion normal*/
	if (Ticket == NULL)
		return(newTicket(id));
	if (id < Ticket->id)
		Ticket->left = insert(Ticket->left, id);
	else if (id > Ticket->id)
		Ticket->right = insert(Ticket->right, id);
	else // no hay claves iguales
		return Ticket;
	/* 2. Actualizar altura del antecesor */
	Ticket->height = 1 + max(height(Ticket->left),
		height(Ticket->right));
	/* 3. Conseguir el FB de ese antepasado para saber si esta equilibrado*/
	int balance = getBalance(Ticket);
	// Si esa desbalanceado hay 4 casos
	// Left Left Caso
	if (balance > 1 && id < Ticket->left->id)
		return rightRotate(Ticket);
	// Right Right Caso
	if (balance < -1 && id > Ticket->right->id)
		return leftRotate(Ticket);
	// Left Right Caso
	if (balance > 1 && id > Ticket->left->id){
		Ticket->left = leftRotate(Ticket->left);
		return rightRotate(Ticket);
	}
	// Right Left Caso
	if (balance < -1 && id < Ticket->right->id){
		Ticket->right = rightRotate(Ticket->right);
		return leftRotate(Ticket);
	}
	/* devuelve el puntero*/
	return Ticket;
}


/* Dado un arbol ABB no vacio, devuelve el Ticket con el valor de clave minimo encontrado */
struct Ticket *minValueTicket(struct Ticket *Ticket){
	struct Ticket *current = Ticket;
	/* bucle hacia abajo para encontrar la rama mas izquierda*/
	while (current->left != NULL)
		current = current->left;
	return current;
}


// Funcion recursiva para eliminar el Ticket.
struct Ticket *deleteTicket(struct Ticket *root, int id){
	// paso 1: realizer el borrado normal
	if (root == NULL)
		return root;
	if (id < root->id)
		root->left = deleteTicket(root->left, id);
	else if (id > root->id)
		root->right = deleteTicket(root->right, id);
	else{
		if ((root->left == NULL) || (root->right == NULL)){
			struct Ticket *temp = root->left ? root->left :
				root->right;
			if (temp == NULL){
				temp = root;
				root = NULL;
			} else
				*root = *temp; // Copia el contenido
			free(temp);
		} else{
			// obtener el Ticket mas peque�o derecho
			struct Ticket *temp = minValueTicket(root->right);
			// copia los datos en este Ticket
			root->id = temp->id;
			// Elimina
			root->right = deleteTicket(root->right, temp->id);
		}
	}
	// Si el arbol tiene un solo Ticket
	if (root == NULL)
		return root;
	// Paso 2. actualizar altura
	root->height = 1 + max(height(root->left),
		height(root->right));
	// Paso 3: obtener FB
	int balance = getBalance(root);
	// Si esta desbalanceado, ver los 4 casos
	// Left Left Caso
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	// Left Right Caso
	if (balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Right Caso
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	// Right Left Caso
	if (balance < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

// Funcion para imprimir el arbol en preorden
void preOrder(struct Ticket *root){
	if (root != NULL){
		printf("%d ", root->id);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
	int id_ticket = 1; // Id de los tickets
	struct Ticket *root = NULL;

	root = insert(root, id_ticket);
	id_ticket++; // Incrementar ID para el siguiente ticket


	// // Cosntruye el arbol de la figura
	// root = insert(root, i++);
	// root = insert(root, 5);
	// root = insert(root, 14);
	// root = insert(root, 0);
	// root = insert(root, 6);
	// root = insert(root, 11);
	// root = insert(root, -1);
	// root = insert(root, 1);
	// root = insert(root, 2);
	//  El arbol es
	// 9
	// / \
	// 1 10
	// / \ \
	// 0 5 11
	// / / \
	// -1 2 6


	// printf("El arbol es \n");
	// 	   preOrder(root);
	// root = deleteTicket(root, 15);
	// Arbol AVL despues del borrado del 10
	// 1
	// / \
	// 0 9
	// / / \
	// -1 5 11
	// / \
	// 2 6


	// printf("Arbol despues del borrado del 10 \n");
	// preOrder(root);
	return 0;
}


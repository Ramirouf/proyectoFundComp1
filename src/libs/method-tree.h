#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funciones relacionadas al arbol de tickets



// TREE AVL

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
struct Ticket *newTicket(){
	struct Ticket *pNewTicket = (struct Ticket *)malloc(sizeof(struct Ticket));
	int cant_prod_min;
	int seguir = 1;

	// Init
	cant_prod_min = 0;

	// Ticket Data
	//  id
	pNewTicket->id = id_tickets;
	// Hora y Fecha
	strcpy(pNewTicket->date, getDate());
	strcpy(pNewTicket->time, getTime());

	// Productos del ticket
	while (seguir){
		seguir = InsertItemTicket();
		if (seguir)
			cant_prod_min++;
	}
	pNewTicket->ProductsTicket = pAuxItemTicket;

	pNewTicket->left = NULL;
	pNewTicket->right = NULL;
	pNewTicket->height = 1; // se debe inicializar

	// Limpio el puntero auxiliar de productos
	pAuxItemTicket = NULL;

	// Incrementa el contador de ID de tickets para el príximo ticket
	id_tickets++;

	return pNewTicket;
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

struct Ticket *insert(struct Ticket *Ticket){
	/* 1. Se realiza la rotacion normal*/
	if (Ticket == NULL)
		return newTicket();

	if (id_tickets < Ticket->id){
		Ticket->left = insert(Ticket->left);
	} else if (id_tickets > Ticket->id){
		Ticket->right = insert(Ticket->right);
	} else{
		// no hay claves iguales
		return Ticket;
	}

	/* 2. Actualizar altura del antecesor */
	Ticket->height = 1 + max(height(Ticket->left), height(Ticket->right));

	/* 3. Conseguir el FB de ese antepasado para saber si esta equilibrado*/
	int balance = getBalance(Ticket);

	// Si esa desbalanceado hay 4 casos
	// Left Left Caso
	if (balance > 1 && id_tickets < Ticket->left->id)
		return rightRotate(Ticket);
	// Right Right Caso
	if (balance < -1 && id_tickets > Ticket->right->id)
		return leftRotate(Ticket);
	// Left Right Caso
	if (balance > 1 && id_tickets > Ticket->left->id){
		Ticket->left = leftRotate(Ticket->left);
		return rightRotate(Ticket);
	}
	// Right Left Caso
	if (balance < -1 && id_tickets < Ticket->right->id){
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
			struct Ticket *temp = root->left ? root->left : root->right;
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
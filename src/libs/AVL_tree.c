#include<stdio.h>
#include<stdlib.h>
// Estructura de árbol aVL
struct Nodo
{
	int key;
	struct Nodo *left;
	struct Nodo *right;
	int height;
};
// Funcion para calcular la altura
int height(struct Nodo *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
// Funcion para hallar el maximo entre dos enteros
int max(int a, int b)
{
	return (a > b)? a : b;
}
/* Funcion que crea un nuevo nodo. */
struct Nodo* newNodo(int key)
{
	struct Nodo* Nodo = (struct Nodo*)
		malloc(sizeof(struct Nodo));
	Nodo->key = key;
	Nodo->left = NULL;
	Nodo->right = NULL;
	Nodo->height = 1; // se debe inicializar
	return(Nodo);
}
// Funcion para rotar a la derecha el subárbol y
struct Nodo *rightRotate(struct Nodo *y)
{
	struct Nodo *x = y->left;
	struct Nodo *T2 = x->right;
	// Se realiza la rotacion
	x->right = y;
	y->left = T2;
	// Actualizacion de alturas
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	// devuelve nueva raiz
	return x; }
// Funcion para rotar a la izquierda el subárbol x
struct Nodo *leftRotate(struct Nodo *x)
{
	struct Nodo *y = x->right;
	struct Nodo *T2 = y->left;
	// Se realiza rotacion
	y->left = x;
	x->right = T2;
	// Actualizacion de alturas
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	// retorna nueva raiz
	return y; }
// Calcular el FB del nodo
int getBalance(struct Nodo *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
struct Nodo* insert(struct Nodo* Nodo, int key)
{
	/* 1. Se realiza la rotacion normal*/
	if (Nodo == NULL)
		return(newNodo(key));
	if (key < Nodo->key)
		Nodo->left = insert(Nodo->left, key);
	else if (key > Nodo->key)
		Nodo->right = insert(Nodo->right, key);
	else // no hay claves iguales
		return Nodo;
	/* 2. Actualizar altura del antecesor */
	Nodo->height = 1 + max(height(Nodo->left),
						   height(Nodo->right));
	/* 3. Conseguir el FB de ese antepasado para saber si esta equilibrado*/
	int balance = getBalance(Nodo);
	// Si esa desbalanceado hay 4 casos
	// Left Left Caso
	if (balance > 1 && key < Nodo->left->key)
		return rightRotate(Nodo);
	// Right Right Caso
	if (balance < -1 && key > Nodo->right->key)
		return leftRotate(Nodo);
	// Left Right Caso
	if (balance > 1 && key > Nodo->left->key)
	{
		Nodo->left = leftRotate(Nodo->left);
		return rightRotate(Nodo);
	}
	// Right Left Caso
	if (balance < -1 && key < Nodo->right->key)
	{
		Nodo->right = rightRotate(Nodo->right);
		return leftRotate(Nodo);
	}
	/* devuelve el puntero*/
	return Nodo;
}
/* Dado un arbol ABB no vacio, devuelve el nodo con el valor de clave minimo encontrado */
struct Nodo * minValueNodo(struct Nodo* Nodo)
{
	struct Nodo* current = Nodo;
	/* bucle hacia abajo para encontrar la rama mas izquierda*/
	while (current->left != NULL)
		current = current->left;
	return current;
}
// Funcion recursiva para eliminar el nodo.
struct Nodo* deleteNodo(struct Nodo* root, int key)
{
	// paso 1: realizer el borrado normal
	if (root == NULL)
		return root;
	if ( key < root->key )
		root->left = deleteNodo(root->left, key);
	else if( key > root->key )
		root->right = deleteNodo(root->right, key);
	else
	{
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct Nodo *temp = root->left ? root->left :
				root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp; // Copia el contenido
			free(temp);
		}
		else
		{
			// obtener el nodo mas pequeño derecho
			struct Nodo* temp = minValueNodo(root->right);
			// copia los datos en este nodo
			root->key = temp->key;
			// Elimina
			root->right = deleteNodo(root->right, temp->key);
		} }
	// Si el arbol tiene un solo nodo
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
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Right Caso
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	// Right Left Caso
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
// Funcion para imprimir el árbol en preorden
void preOrder(struct Nodo *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
	struct Nodo *root = NULL;
	/* Cosntruye el árbol de la figura*/
	root = insert(root, 15);
	root = insert(root, 5);
	root = insert(root, 14);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);
	/* El árbol es
	9
	/ \
	1 10
	/ \ \
	0 5 11
	/ / \
	-1 2 6
	*/
	printf("El árbol es \n");
		   preOrder(root);
	root = deleteNodo(root, 15);
	/* Arbol AVL despues del borrado del 10
	1
	/ \
	0 9
	/ / \
	-1 5 11
	/ \
	2 6
	*/
	printf("Arbol despues del borrado del 10 \n");
	preOrder(root);
	return 0;
} 


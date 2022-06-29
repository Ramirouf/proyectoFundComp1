#include <stdio.h>
#include <stdlib.h>

// Globales
#include "src/libs/Init.h"
#include "src/libs/utilities.h"
#include "src/libs/crypt.h"
#include "src/libs/login-methods.h"
#include "src/libs/users.h"

// Esenciales
#include "src/libs/products.h"
#include "src/libs/config-ticket.h"
#include "src/libs/method-product-ticket.h"
#include "src/libs/method-tree.h"
#include "src/libs/ticket.h"

// Menus, submenus, etc.
#include "src/components/Login.h"
#include "./src/components/InitialConfigTicket.h"
#include "./src/components/TicketSettings.h"
#include "./src/components/ViewTicket.h"
#include "./src/components/Exit.h"
#include "./src/components/MenuSystem.h"

// FLOW DEL PROGRAMA
// Inciar Sesion
// Configurar Ticket
// Menu Clasico (MenuSystem)
#include "src/libs/login.h"
int main()
{
	// InitialConfigUser();
	menuInicial();
	// InitialConfigTicket();
	// SetListProducts(); // Inicializar la lista de productos global
	// MenuSystem();

	return 0;
}

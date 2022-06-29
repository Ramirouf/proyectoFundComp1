#include <stdio.h>
#include <stdlib.h>

// Globales
#include "src/libs/Init.h"
#include "src/libs/utilities.h"

// Esenciales
#include "src/libs/products.h"
#include "src/libs/config-ticket.h"
#include "src/libs/method-product-ticket.h"
#include "src/libs/method-tree.h"
#include "src/libs/ticket.h"

// Menus y submenus
#include "./src/components/TicketSettings.h"
#include "./src/components/ViewTicket.h"
#include "./src/components/Exit.h"
#include "./src/components/MenuSystem.h"

int main(){
	SetListProducts(); // Inicializar la lista de productos global
	MenuSystem();

	return 0;
}

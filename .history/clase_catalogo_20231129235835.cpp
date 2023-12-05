#include <iostream>
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"

using namespace std;

Catalogo::Catalogo() {
    PedidoPtr = nullptr;
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();
    canalesPtr = nullptr;
}

Catalogo::Catalogo(Listas& lista_has,Listas& lista_viv,Usuario& usuario1) {
    PedidoPtr = nullptr;
    this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
    canalesPtr = nullptr;
    //this->canalesPtr = &canales;
}
void Catalogo::tab_catalogo() {
    bool retro = true;
    int op;
    do {
        cout << "\n\tCatalogo\n"
             << "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
                case 1:
                    system("cls");
                    cout << "\x1B[34m" << "\nCATALOGO HAS" << "\x1B[m" << "\n\n";
                    retro = false;
                    print_catalogo(lista_has);
                    break;
                case 2:
                    system("cls");
                    cout << "\x1B[34m" << "\nCATALOGO VIVO" << "\x1B[m" << "\n\n";
                    retro = false;
                    print_catalogo(lista_viv);
                    break;
                case 3:
                    retro = false;
                    PedidoPtr->tab_pedido();
                    break;
                case 4:
                    retro = false;
                    pantalla_start(true, lista_has, lista_viv, usuario1);	
                    break;
                default:
                    error_valor();
            }
        }
    } while (retro);
    
}
void Catalogo::set_pedidoPtr(Pedido* PedidoPtr) {
    this->PedidoPtr = PedidoPtr;
}
void Catalogo::set_canalesPtr(CanalesV* canalesPtr) {
    this->canalesPtr = canalesPtr;
}

void Catalogo::print_catalogo(Listas& array_catalogo) {
    try {
        array_catalogo.print_lista();
    } catch (const invalid_argument& e) {
        cerr << "Exception while print_lista :c " << e.what() << endl;
    }
    int op;
    int op_;
    bool retro = true;
    bool retro1 = true;
    do {
        cout << "print cat catalogo\x1B[34m" << "\n\t1. Anadir a Pedido" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Opciones para Ordenar y Filtrar" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Regresar a Catalogo" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
                case 1:
                    retro = false;
                    cout << "(anadir a pedido pronto sera implementado xd)";	
                    cout << "\n\nEscoja indice del producto que desea anadir: " << endl;
                    do {
                        cout << "\x1B[34m" << "\n\t0. para volver a catalogo" << "\x1B[m" << "\n";
                        cin >> op_;
                        if (std::cin.fail() || !(op_ >= 0 && op_ <= 99)) {
                            error_valor();
                        } else {
                            if (op_ == 0) {
                                retro1 = false;
                                system("cls");
                                tab_catalogo();
                            } else {
                                cout << "producto 'anadido' :p\n";	
                                retro1 = true;
                                //funcion para añadir producto	a carrito de compras
                               
                            }
                        }
                    }while (retro1);
                    break;
                case 2:
                    retro = false;
                    system("cls");
                    cout << "Filtrar por: " << endl;
                    do {
                        cout << "\x1B[34m" << "\n\t1. Descripcion" << "\x1B[m" << "\n"
                            << "\x1B[34m" << "\n\t2. Nivel" << "\x1B[m" << "\n"
                            << "\x1B[34m" << "\n\t3. Grado" << "\x1B[m" << "\n"
                            << "\x1B[34m" << "\n\t4. Area" << "\x1B[m" << "\n"
                            << "\x1B[34m" << "\n\t5. Regresar a Catalogo" << "\x1B[m" << "\n"
                            << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
                        cin >> op_;
                        if (std::cin.fail() || !(op_ >= 1 && op_ <= 5)) {
                            error_valor();
                        } else {
                            switch (op_) {
                                case 1:
                                    retro1 = true;
                                    cout << "filtrar por descripcion pronto sera implementado xd";	
                                    break;
                                case 2:
                                    retro1 = true;
                                    cout << "filtrar por Nivel pronto sera implementado xd";
                                    break;
                                case 3:
                                    retro1 = true;
                                    cout << "filtrar por grado pronto sera implementado xd";
                                    break;
                                case 4:
                                    retro1 = true;
                                    cout << "filtrar por area pronto sera implementado xd";
                                    break;
                                case 5:
                                    retro1 = false;
                                    system("cls");
                                    tab_catalogo();
                                    break;
                                default:
                                    error_valor();
                            }
                        }
                    }while (retro1);
                    break;
                case 3:
                    retro = false;
                    system("cls");
                    tab_catalogo();
                    break;
                case 4:
                    retro = false;
                    pantalla_start(true, lista_has, lista_viv, usuario1);	
                    break;
                default:
                    error_valor();
            }
        }
    } while (retro);
}
Listas *Catalogo::filtrar_producto(int tipo){
    Listas *lista_filtrada = new Listas();

}
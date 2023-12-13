//clase_pedidos.h
#include <iostream>
#include "c_producto.h"
#include "c_listas.h"
#include "c_usuario.h"
#ifndef C_PEDIDOS_H
#define C_PEDIDOS_H
class Catalogo;
class CanalesV;
class Pedido {
private:
    char* nombreCole;
    char* direccionCole;
    char* emailCole;
    char* nombreResp;
    int numTele;
    long long codigoCole;
    long long codigoRUC;
    Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
    Catalogo* catalogoPtr;
    CanalesV* canalesPtr;
	Usuario* usuarioPtr;
    Listas productos_anadidos_has;
    Listas productos_anadidos_viv;
    int cantidad_tot;
public:
    Pedido();
    Pedido(Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
    ~Pedido();
    void tab_pedido();
    void setCatalogo(Catalogo* cat_ptr);
    void setCanales(CanalesV* can_ptr);
    void setUsuario(Usuario* usu_ptr);
    void setNombreCole(const char* nom_c);
    const char* getNombreCole() const;
    void setDireccionCole(const char* dir_c);
    const char* getDireccionCole() const;
    void setEmailCole(const char* email_c);
    const char* getEmailCole() const;
    void setNombreResp(const char* nombre_r);
    const char* getNombreResp() const;
    void setNumTele(int num_tel);
    int getNumTele() const;
    void setCodigoCole(long long cod_col);
    long long getCodigoCole() const;
    void setCodigoRUC(long long cod_ruc);
    long long getCodigoRUC() const;
    void print_pedido();
    void recibir_datos();
    void set_lista_venta(Listas productos_anadidos);
    int get_cantidad_tot()const;
};
#endif

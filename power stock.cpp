#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
private:	
	long codigo;
	long cantidad;
	string timestamp;
} registroStock;

class stock
{
public:
	void actualizar(long codigo, long cantidad)
	{	
		//TODO actualizar archivo de stock
	}
};

class Item
{
    private:
        string descripcion;
    float precioUnitario;
    int cantidad;

    public:
        Item()
        {
            descripcion = "";
            precioUnitario = 0;
            cantidad = 0;
        }

    string getDescripcion()
    {
      return descripcion;
    } 

    float getPrecioUnitario()
    {
    return precioUnitario;
    }
    
	//TODO crear getter para atributo "cantidad"
    int getCantidad()
    {
    return cantidad;
    }

    void setDescripcion(string d)
    {
        descripcion  = d; 
       
    }
    void setPrecio(float p)
	{
        precioUnitario = p;
    }

    //TODO crear setter para atributo "cantidad"
    void setCantidad(int c)
    {
     cantidad = c ;    
    }

    void imprimir()
    {
        cout << getDescripcion() << " | " << getCantidad() << " | $" << getPrecioUnitario() *getCantidad() << endl;
    }
};

class Ticket
{
    private:
        int numero;
    vector<Item> items;
    public:
        void imprimir()
        {
            float total = 0;
            imprimirEncabezado();
            for (auto item: items)
            {
                item.imprimir();
				total += item.getPrecioUnitario() *  item.getCantidad(); 
            }
            cout << "Total: " << total << endl;
        }

    void imprimirEncabezado()
    {
        cout << "***************************************" << endl;
        cout << "***  ********     ****     ****     ***" << endl;
        cout << "***  ******** *** ****** ****** *** ***" << endl;
        cout << "***  ******** *** ****** ****** *** ***" << endl;
        cout << "***  ******** *** ****** ****** *** ***" << endl;
        cout << "***     *****     ****** ******     ***" << endl;
        cout << "***************************************" << endl;
        cout << endl;
        cout << "Sucursal 34" << endl;
        cout << "Parque Patricios" << endl;
        cout << "CUIT 30-009999999-2" << endl;
        cout << "" << endl;
    }

    void imprimirSubtotal()
    {
        float subtotal;

        subtotal = 0;
        for (auto item: items)
        {
            //TODO completar
            subtotal +=item.getCantidad()*item.getPrecioUnitario();
        }

        cout << numero << " | $" << subtotal << endl;
    }

    void addItem(Item i)
    {
        items.push_back(i);
    }

    void setNumero(int n)
    {
        numero = n;
    }
};

void imprimirReporte(vector<Ticket> tickets)
{
    for (auto ticket: tickets)
    {
        ticket.imprimirSubtotal();
    }
}

int main()
{
    string nombre;
    float precioUnitario;
    int cantidad;
    int numeroTicket;
    vector<Ticket> tickets;
    Ticket * ticket;

    cout << "*******************************************" << endl;
    cout << "*Profesor: Jose Fuentes" << endl;
    //TODO completar nombre
    cout << "*Alumno: " << endl;
    cout << "*Curso: 4° 4°" << endl;
    //TODO completar número de práctica
    cout << "*Trabajo: Practica ##" << endl;
    //TODO completar fecha
    cout << "*Fecha: dd-mm-yyyy" << endl;

    cout << "*******************************************" << endl << endl;

    numeroTicket = 0;
    ticket = new Ticket();

    while (true)
    {
        cout << "Nombre del producto (o TICKET para finalizar ticket, REPORTE para listado de tickets):" << endl;
        getline(cin >> ws, nombre);
        //cin >> nombre;

        if (nombre == "TICKET")
        {
            ticket->setNumero(numeroTicket);
            ticket->imprimir();
            tickets.push_back(*ticket);

	        //TODO crear archivo de ticket en formato CSV
	        //incluyendo fecha y hora del ticket


	        //TODO actualizar archivo de stock


            numeroTicket++;
            ticket = new Ticket();
            continue;
        }
        else if (nombre == "REPORTE")
        {
            imprimirReporte(tickets);
            break;
        }

        cout << "Cantidad:" << endl;

        cin >> cantidad;

        cout << "Precio unitario:" << endl;

        cin >> precioUnitario;

        Item item;
        item.setDescripcion(nombre);
        item.setCantidad(cantidad);
        item.setPrecio(precioUnitario);
        ticket->addItem(item);
        
        //TODO crear archivo de reporte en formato CSV
        
        
    }

    return 0;
}
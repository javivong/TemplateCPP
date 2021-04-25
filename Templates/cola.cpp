#pragma region "Tipo Dato Cola Ordenada"

// TIPO DATO COLA ORDENADA
struct item
{
    int fecha;
    long cantidad;
    item* siguiente;
};

struct cola
{
    item* inicio;
    long maximo;
};

void insertar(cola* c, int fecha, long cantidad)
{
    item* it = new item;

    // Inserta el nodo al inicio de la cola
    it->siguiente = c->inicio;
    it->fecha = fecha;
    it->cantidad = cantidad;
    c->inicio = it;

    item* anterior = it;
    item* siguiente = it->siguiente;

    if (c->maximo < cantidad)
        c->maximo = cantidad;

    // Elimina cualquier nodo con cantidad menor a la recien insertada
    //while (siguiente != NULL)
    //{
    //    if (siguiente->cantidad < cantidad) {
    //        item* borrar = siguiente;
    //        anterior->siguiente = siguiente->siguiente;
    //        free(borrar);
    //    }
    //    else
    //        anterior = siguiente;
    //    siguiente = anterior->siguiente;
    //}

}

item* buscar(cola* c, long cantidad)
{
    item* it = c->inicio;
    if (c->maximo < cantidad) it = NULL;
    else {
        while (it != NULL && it->cantidad < cantidad)
            it = it->siguiente;
    }
    return it;
}

#pragma endregion
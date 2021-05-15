#include <bits/stdc++.h>

template <class t>
class Node
{
    /*
        ----------------------------------------------------------
        Creamos una clase nodo para facilitar la implementacion de 
        la estruuctura, dicho nodo cuenta con tres atributos  para
        almacenar los datos  del  nodo y  las direcciones del nodo 
        previo y el siguiente.
        ----------------------------------------------------------
    */
public:
    t Data;
    Node<t> *next, *prev;
    Node(t Data);
    Node<t> &changedata(t newdata); //Cambia los datos del nodo
    Node<t> &operator=(const t data) const;
    ~Node();
};

template <class t>
Node<t>::Node(t Data)
{
    this->Data = Data;
    this->prev = NULL;
    this->next = NULL;
}
template <class t>
Node<t> &Node<t>::changedata(t newdata)
{
    return this->Data = newdata;
}
template <class t>
Node<t> &Node<t>::operator=(const t data) const
{
    return this->Data = data;
}
template <class t>
Node<t>::~Node()
{
}

/*
    ----------------------------------------------------------------------------------------------
        La implementacion de la clase Queue(Cola) consta de 4  atributos los cuales son un puntero 
    de tipo nodo(Node) llamado nodes el cual usaremos para crear los nodos  con lo cual la memoria 
    de la estructura se manejara de forma dinamica es  decir la estructrua  no ocupara mas memoria
    de la que sea necesaria para ir alamcenando los  datos que  entren a la  cola. A demas de esto 
    contamos con 2 punteros extra los  cuales se  utilizaran como referencia para mantener siempre
    a nuestra dispocion el primer elemto de la cola y el ultimo, este puntero al final de la  fila 
    nos servira unicamente para ir formando los elementos a la cola(Ver clase Deque para mas usos)
    finalmente una variable para almacenar el tamaño de la Cola.

    La clase Queue cuenta con varios metodos los cuales presentaremos a continuacion:

    -Push{O(1)}: Inserta un elemto a las cola.
    
    -Pop{O(1)}: Elimina el elemento al frente de la cola, si la cola esta vacia 
    arroja una excepcion.
    
    -Front{O(1)}: Retorna el elemento al frente de la cola, si la cola esta vacia
    arroja una excepcion.

    -Front & Pop: Elimina el elemto al frente de la cola y lo retorna.

    -Clear{O(n)}: Elimina todos los elemetos de la cola.

    -Size: retorna el tamaño.

    -Empty: Retorna true si la pila esta vacia.
    ----------------------------------------------------------------------------------------------


*/

template <class Type>
class Queue
{
private:
    Node<Type> *nodes; //Variable para crear nodos
    Node<Type> *ft;    //Referencia al primer elemeto de la cola
    Node<Type> *tail;  //Referencia al utlimo elemento de la cola
    size_t sz;         //Tamaño de la cola

public:
    Queue();
    void push(Type data); //Inserta elemetos a la cola O(1)
    void pop();           //Elimina elementos de la cola O(1)
    Type front();         //Retorna el primer elemto de la cola O(1)
    Type front_and_pop(); //Retorna y elemina el elemto al frente de la cola O(1)
    void clear();         //Elimina todos los elemetos de la cola O(n)
    bool empty();         //Determina si la cola esta vacia
    size_t size();        //retorna el tamaño de la cola
    ~Queue();
};

template <class Type>
Queue<Type>::Queue()
{
    this->sz = 0;
    this->nodes = NULL;
    this->ft = NULL;
}

template <class Type>
void Queue<Type>::push(Type Data)
{
    if (this->ft == NULL)
    {
        this->nodes = new Node<Type>(Data);
        this->ft = this->nodes;
        this->tail = this->ft;
        this->sz += 1;
    }
    else
    {
        this->nodes = new Node<Type>(Data);
        this->tail->next = this->nodes;
        this->tail = this->tail->next;
        this->sz += 1;
    }
}

template <class Type>
void Queue<Type>::pop()
{
    if (this->ft == NULL)
        throw std::invalid_argument("La cola esta vacia!");

    Node<Type> *tmp = this->ft;

    this->ft = this->ft->next;
    this->sz -= 1;
    if (this->ft == NULL)
        this->tail = NULL;

    delete tmp;
}

template <class Type>
void Queue<Type>::clear()
{
    if (this->ft == NULL)
        return;

    Node<Type> *it = this->ft;

    while (it != NULL)
    {
        Node<Type> *aux = it;
        it = it->next;
        delete aux;
    }

    this->ft = NULL;
    this->tail = NULL;
    this->sz = 0;
}

template <class Type>
Type Queue<Type>::front()
{
    if (this->ft == NULL)
        throw std::invalid_argument("La cola esta vacia!");
    return this->ft->Data;
}

template <class Type>
bool Queue<Type>::empty()
{
    return this->ft == NULL;
}
template <class Type>
Type Queue<Type>::front_and_pop()
{
    Type r = this->front();
    this->pop();
    return r;
}

template <class Type>
size_t Queue<Type>::size()
{
    return this->sz;
}

template <class Type>
Queue<Type>::~Queue()
{
    if (this->ft != NULL)
    {
        Node<Type> *it = this->ft;

        while (it != NULL)
        {
            Node<Type> *aux = it;
            it = it->next;
            delete aux;
        }
    }
}

/*
    -------------------------------------------------------------------------------------------
        La clase Deque (Double ended Queue) funciona de igual forma que la clase  Queue  con la
    diferencia de que aqui tenemos acceso tanto al  elemento que se encuentra al frente  de  la
    cola y al que se encuentra al final de esta, de igual forma  podremos  eliminar el elemento
    al frente   o al final de la misma.
    
    Tanto los atributos como los metodos siguen siendo los  mismos que en la  clase  Queue  con 
    algunos metodos añadidos los cuales mencionamos a continuacion:

    -Pop back{O(1)}: Elimina el elemto al final de la cola.

    -End{O(1)}: Retorna el ultimo elemento de la cola.
    -------------------------------------------------------------------------------------------
*/

template <class ty>
class Deque
{
private:
    Node<ty> *nodes; //Variable para crear nodos
    Node<ty> *ft;    //Referencia al primer elemeto de la cola
    Node<ty> *tail;  //Referencia al utlimo elemento de la cola
    size_t sz;       //Tamaño de la cola

public:
    Deque();
    void push(ty data); //Inserta elemetos a la cola O(1)
    void pop();         //Elimina elementos de la cola O(1)
    void pop_back();    //Elimina el elemento al final de la cola O(1)
    ty front();         //Retorna el primer elemto de la cola O(1)
    ty end();           //Retorna el elemto al final de la cola O(1)
    ty front_and_pop(); //Retorna y elemina el elemto al frente de la cola O(1)
    void clear();       //Elimina todos los elemetos de la cola O(n)
    bool empty();       //Determina si la cola esta vacia
    size_t size();      //retorna el tamaño de la cola
    ~Deque();
};

template <class ty>
Deque<ty>::Deque()
{
    this->sz = 0;
    this->nodes = NULL;
    this->ft = NULL;
}

template <class ty>
void Deque<ty>::push(ty Data)
{
    if (this->ft == NULL)
    {
        this->nodes = new Node<ty>(Data);
        this->ft = this->nodes;
        this->tail = this->ft;
        this->sz += 1;
    }
    else
    {
        this->nodes = new Node<ty>(Data);
        this->tail->next = this->nodes;
        this->tail->next->prev = this->tail;
        this->tail = this->tail->next;
        this->sz += 1;
    }
}

template <class ty>
void Deque<ty>::pop()
{
    if (this->ft == NULL)
        throw std::invalid_argument("La cola esta vacia!");

    Node<ty> *tmp = this->ft;

    this->ft = this->ft->next;
    this->ft->prev = NULL;
    this->sz -= 1;
    if (this->ft == NULL)
        this->tail = NULL;

    delete tmp;
}

template <class ty>
void Deque<ty>::pop_back()
{
    if (this->ft == NULL)
        throw std::invalid_argument("La cola esta vacia!");
    Node<ty> *tmp = this->tail;

    if (tmp == this->ft)
    {
        delete tmp;
        this->ft = NULL;
        this->tail = NULL;
        this->sz = 0;
        return;
    }

    this->tail = this->tail->prev;
    this->sz -= 1;
    delete tmp;
}

template <class ty>
void Deque<ty>::clear()
{
    if (this->ft == NULL)
        return;

    Node<ty> *it = this->ft;

    while (it != NULL)
    {
        Node<ty> *aux = it;
        it = it->next;
        delete aux;
    }

    this->ft = NULL;
    this->tail = NULL;
    this->sz = 0;
}

template <class ty>
ty Deque<ty>::front()
{
    if (this->ft == NULL)
        throw std::invalid_argument("La cola esta vacia!");
    return this->ft->Data;
}

template <class ty>
ty Deque<ty>::end()
{
    if (this->ft == NULL)
        throw std::invalid_argument("La cola esta vacia!");
    return this->tail->Data;
}

template <class ty>
bool Deque<ty>::empty()
{
    return this->ft == NULL;
}
template <class ty>
ty Deque<ty>::front_and_pop()
{
    ty r = this->front();
    this->pop();
    return r;
}

template <class ty>
size_t Deque<ty>::size()
{
    return this->sz;
}

template <class ty>
Deque<ty>::~Deque()
{
    if (this->ft != NULL)
    {
        Node<ty> *it = this->ft;

        while (it != NULL)
        {
            Node<ty> *aux = it;
            it = it->next;
            delete aux;
        }
    }
}

/*Priority Queue en proceso :v*/

int main(int argc, char const *argv[])
{

    return 0;
}

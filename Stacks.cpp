#include <bits/stdc++.h>

template <class t>
class Node
{
    /*
    Creamos una clase nodo para facilitarla implementacion de la estructura
    -Inicialmente el nodo cuenta con diferentes atributos siendo publicos 
    todos ellos al igual que los metodos y operadores disponibles.
    */
public:
    t Data;                                 //Datos del nodo
    Node<t> *next;                          //Guarda la direccion del nodo sig.
    Node<t> *prev;                          //Guarda la direccion del nodo previo
    Node(t data);                           //Constructor
    Node<t> &change_data(t newdata);        //Cambia los datos del nodo
    Node<t> &operator=(const t data) const; //Operador para cambiar los datos de un nodo

    ~Node();
};

template <class t>
Node<t>::Node(t data)
{
    this->Data = data;
    this->next = NULL;
    this->prev = NULL;
}
template <class t>
Node<t> &Node<t>::change_data(t newdata)
{
    this->Data = newdata;
}
template <class t>
Node<t> &Node<t>::operator=(const t data) const
{
    this->Data = data;
}

template <class t>
Node<t>::~Node()
{
}

template <class Type>
class Stacks
{
private:
    Node<Type> *nodes; //Variable para crear los nodos
    Node<Type> *tp;    //Guarda la direccion del top de la pila
    size_t sz;         //Guarada el tamaño total de la pila

public:
    Stacks();
    void push(Type Data);                                 //Inserta elementos en la pila
    void pop();                                           //Elimina el elemento en el top de la pila
    Type top();                                           //Retorna el top de la pila
    Type top_and_pop();                                   //Retorna el top de la pila y hace pop al mismo tiempo
    bool empty();                                         //Determina si la pila esta vacia
    size_t size();                                        //Retorna el tamaño de la pila
    Stacks<Type> &operator=(const Stacks<Type> &S) const; //Operador para copiar una pila
    void reverse();                                       //Invierte una pila sin usar memoria extra
    ~Stacks();
};

template <class Type>
Stacks<Type>::Stacks()
{
    this->nodes = NULL;
    this->tp = NULL;
    this->sz = 0;
}

template <class Type>
void Stacks<Type>::push(Type Data)
{
    if (this->tp == NULL)
    {
        this->nodes = new Node<Type>(Data);
        this->tp = this->nodes;
        this->sz += 1;
    }
    else
    {
        this->nodes = new Node<Type>(Data);
        this->tp->next = this->nodes;
        this->nodes->prev = this->tp;
        this->tp = this->nodes;
        this->sz += 1;
    }
}
template <class Type>
void Stacks<Type>::reverse()
{
    if (this->tp != NULL)
    {
        Type e = this->top();
        this->pop();
        if (this->empty())
        {
            this->push(e);
            return;
        }
        else
        {
            this->reverse();

            Type aux = this->top();
            this->pop();
            this->push(e);
            this->push(aux);
            return;
        }
    }
}

template <class Type>
void Stacks<Type>::pop()
{
    if (this->tp == NULL)
        throw std::invalid_argument("La pila esta vacia!");

    Node<Type> *tmp;
    tmp = this->tp;
    this->tp = tmp->prev;
    this->sz -= 1;
    delete tmp;
}

template <class Type>
Type Stacks<Type>::top()
{
    return this->tp->Data;
}
template <class Type>
Type Stacks<Type>::top_and_pop()
{
    if (this->tp == NULL)
        throw std::invalid_argument("La pila esta vacia!");
    Type t = this->top();
    this->pop();
    return t;
}

template <class Type>
bool Stacks<Type>::empty()
{
    return this->tp == NULL;
}
template <class Type>
size_t Stacks<Type>::size()
{
    return this->sz;
}

template <class Type>
Stacks<Type>::~Stacks()
{
    if (this->tp != NULL)
    {
        Node<Type> *tmp = this->tp;

        while (tmp != NULL)
        {
            Node<Type> *aux = tmp;
            tmp = tmp->prev;
            delete aux;
        }
    }
}

int main(int argc, char const *argv[])
{
    Stacks<char> S;
    S.push('h');
    S.push('o');
    S.push('l');
    S.push('a');
    S.reverse();
    //std::cout << S.top() << std::endl;
    //S.pop();
    //std::cout << S.top() << " , sz-> " << S.size() << std::endl;

    while (!S.empty())
    {
        std::cout << S.top_and_pop() << std::endl;
    }

    return 0;
}

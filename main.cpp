/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>

typedef int dado;

struct Node
{

    dado valor;
    Node *prox;

    Node()
    {
        prox = NULL;
    }

    Node(dado _valor)
    {
        valor = _valor;
        prox = NULL;
    }

    void print()
    {
        printf("%d -> ", valor);
    }

};

struct List
{

    Node *cabeca, *cauda;
    int size;

    List()
    {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

   
    bool empty()   //O(1)
    {
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor)   //O(1)
    {
        Node *novo = new Node(valor);
        if (empty())
        {
            cabeca = novo;
            cauda = novo;
        }
        else
        {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor)   //O(1)
    {
        Node *novo = new Node(valor);
        if (empty())
        {
            cabeca = novo;
            cauda = novo;
        }
        else
        {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }


    void print()   //O(n)
    {
        Node *tmp = cabeca;
        while (tmp != NULL)
        {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront()   //O(1)
    {
        if (!empty())
        {
            if (cabeca == cauda)   // Apenas 1 elemento
            {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else
            {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack()   //O(n)
    {
        if (!empty())
        {
            if (cabeca == cauda)
            {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else
            {
                Node *penultimo = cabeca;
                while (penultimo->prox != cauda)
                {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x)   //O(n)
    {
        Node *tmp = cabeca;
        while (tmp != NULL)
        {
            if (tmp->valor == x)
            {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }

//Questão 1 
    void ReceberNumero(int n)   
    {
        if(size>n)
        {
            for(int i=0; i<(size-n); i++)
            {
                popBack();
                size++;
            }
        }
        else
        {
            for(int i=0; i<(n-size); i++)
            {
                pushFront(0);
                size--;
            }
        }
    }

    
//Questão  3
    void Inserir()  
    {
        int nn=size;
        Node *tmp = cabeca;
        for(int i=0; i<nn; i++)
        {
            pushBack(tmp->valor);
            tmp = tmp->prox;
        }
    }

//Questão 4
    void Receber(int n) 
    {
        int cont=1;

        while (cont<=n)
        {
            if (find(cont)==NULL)
            {
                pushBack(cont);
            }
            cont++;


        }
    }
};



int main()

{
    List l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(6);
    l.pushBack(7);
    l.pushBack(8);
    l.pushBack(9);
    l.pushBack(10);
    
    /*l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();*/

    l.ReceberNumero(11);
    l.Inserir();
    l.Receber(20);

    l.print();
    printf("%d\n", l.size);
    return 0;
}




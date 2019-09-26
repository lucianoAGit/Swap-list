/*
 * List.cpp
 *
 *  Created on:
 *      Author:
 */

#include "List.h"
//pré-condição: nenhuma
//pós-condição: Lista é criada e iniciada como vazia
List::List()
{
  head = NULL;
  count = 0;
}
//pré-condição: Lista já tenha sido criada
//pós-condição: Lista é finalizada (destruída), liberando espaço ocupado pelo seus elementos
List::~List()
{
  clear();
}
//pré-condição: Lista já tenha sido criada
//pós-condição: função retorna true se a Lista está vazia; false caso contrário
bool List::empty()
{
  return (head == NULL);
}
//pré-condição: Lista já tenha sido criada
//pós-condição: função retorna true se a Lista está cheia; false caso contrário
bool List::full()
{
   return false;
}
//pré-condição: Lista já tenha sido criada
//pós-condição: todos os itens da Lista são descartados e ela torna-se uma Lista vazia
void List::clear()
{ ListPointer q;

  while (head != NULL)
  {  q = head;
     head = head->nextNode;
     delete q;
  }
  count = 0;
}
//pré-condição: Lista já tenha sido criada
//pós-condição: função retorna o número de itens na Lista
long List::size()
{
   return count;
}
//pre-condicao: Lista ja tenha sido criada, nao esta cheia e 1 <= p <= n+1, onde n e o numero de entradas na Lista
//pos-condicao: O item x e armazenado na posicao p na Lista e todas as entradas seguintes (desde que p<=n) tem suas posicoes incrementada em uma unidade
void List::insert(long p, ListEntry x)
{ ListPointer newNode, current;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  newNode = new ListNode;
  newNode->entry = x;
  if(p == 1)
  {  newNode->nextNode = head;
     head = newNode;
  }
  else
  {  setPosition(p-1,current);
     newNode->nextNode = current->nextNode;
     current->nextNode = newNode;
  }
  count++;
}
//pre-condicao: Lista ja tenha sido criada, nao esta vazia e 1 <= p <= n, onde n e o numero de entradas na Lista
//pos-condicao: A entrada da posicao p é removida da Lista e retornada na variavel x; as entradas de todas as posicoes seguintes (desde que p<n) tem suas posicoes decrementadas em uma unidade
void List::remove(long p, ListEntry &x)
{ ListPointer node, current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  if(p == 1)
  {  node = head;
     head = node->nextNode;
  }
  else
  {  setPosition(p-1,current);
     node = current->nextNode;
     current->nextNode = node->nextNode;
  }
  x = node->entry;
  delete node;
  count = count - 1;
}
//pre-condicao: Lista ja tenha sido criada, nao esta vazia e 1 <= p <= n, onde n e o numero de entradas na Lista
//pos-condicao: A entrada da posicao p da Lista é retornada na variavel x; a Lista permanece inalterada
void List::retrieve(long p, ListEntry &x)
{ ListPointer current;

  setPosition(p,current);
  x = current->entry;
}
// pré: Lista criada
// pós: Retorna posição que o elemento x encontra-se na lista
// caso exista mais de um x na lista, retorna o primeiro encontrado
// caso não encontre, retorna zero
long List::search(ListEntry x)
{ long p=1;
  ListPointer q=head;

  while (q != NULL && q->entry != x)
  {  q = q->nextNode;
     p++;
  }
  return (q == NULL ? 0 : p);
}
//---------------------------------------------------------------
string List::toString()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q->entry << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
string List::toStringAddr()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
void List::setPosition(long p, ListPointer &current)
{ long i;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  current = head;
  for(i=2; i<=p; i++)
      current = current->nextNode;
}
//---------------------------------------------------------------
long long List::getAddr(ListEntry x) 
{ ListPointer current=NULL;
  long p = search(x);
  if(p != 0)
    setPosition(p, current);
  return (long long)current;
}
//---------------------------------------------------------------

//---------------------------------------------------------------
bool List::swap(ListEntry a, ListEntry b)
{ 
ListPointer ant_A,ant_B,Node_A,Node_B,P_aux;
int t_list,i=0;

t_list = size(); 	

Node_A=Node_B=ant_A=ant_B=P_aux=head; //No início, todos os ponteiros apontam para a cabeça "inicio" da lista.
	
	if(empty() || t_list <= 1 || a == b) //Se a lista está vazia ou contém um único elemento ou a=b, o método não altera a lista e retorna false.
	{	return false;	
	}
	else if(t_list > 1)
	{	
		while(i<t_list)//Laço responsável por posicionar os ponteiros NodeA e o seu anterior ant_A, e os ponteiros NodeB e o seu anterior ant_B nas posições corretas.
		{
			if(Node_A->entry != a)
			{	ant_A = Node_A;								
				Node_A = Node_A->nextNode;					
			}
			if(Node_B->entry != b)
			{	ant_B = Node_B;								
				Node_B = Node_B->nextNode;						
			}
			i++; 
		}
	 	if(Node_A == NULL || Node_B == NULL)//Se os elementos a e b não forem encontrados na lista, o método não altera a lista e retorna false.
		{return false;
		}
		if(Node_A == head)//Se o NodeA for a cabeça "Inicio" da lista.
		{	head = Node_B;										
			ant_B->nextNode = Node_A;
			P_aux = Node_A->nextNode; //Necessário o uso de um ponteiro auxiliar "P_aux" para armazenar a referencia do proximo listNode.							
			Node_A->nextNode = Node_B->nextNode;						
			Node_B->nextNode = P_aux;								
			return true; 
		}
		else if(Node_B == head)//Se o NodeB for a cabeça "Inicio" da lista.
		{	head = Node_A;										
			ant_A->nextNode = Node_B;
			P_aux = Node_A->nextNode;								
			Node_A->nextNode = Node_B->nextNode;						
			Node_B->nextNode = P_aux;								
			return true;
		}
		else if(Node_A != head && Node_B != head)//Se o NodeA e NodeB forem quaisquer outras posições que não forem a cabeça "Inicio".
		{	ant_A->nextNode = Node_B; 						
			ant_B->nextNode = Node_A;
			P_aux = Node_A->nextNode;								
			Node_A->nextNode = Node_B->nextNode;						
			Node_B->nextNode = P_aux;								
			return true;
		}

	}
return false;
}
//---------------------------------------------------------------

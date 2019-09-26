#include <iostream>
#include "List.h"
using namespace std;
int main(){ 

List l;
int i,x=1,y,k,o,p;
cout<<"Quantos elementos deseja inserir na lista encadeada: "<<endl;
cin>>k;

for(i=0;i<k;i++){
cout<<"Entre com o elemento da lista encadeada: "<<endl;
cin>>y;

l.insert(x,y);
x++;
}
	
	cout << "Antes swap" << endl;
	cout << "Lista: " << l.toString() << endl;
	cout << "Nos..: " << l.toStringAddr() << endl;
	
cout<<"Deseja trocar quais elementos de posicao: ";
cin>>o;
cin>>p;	
	
	l.swap(o,p);
	cout << "Apos swap" << endl;
	cout << "Lista: " << l.toString() << endl;
	cout << "Nos..: " << l.toStringAddr() << endl;

return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

struct Cliente {
	string nome;
	string endereco;
	int telefone;
};
void imprimir (){
	cout<<" "<<endl;
}
int main(){
    int respMenu,Som=0;
    Cliente c[1000];
    
    for (;;){
    	system ("cls");
    cout<<" Digite o numero referente a acao escolhida \n 1.  Incluir um novo cliente na lista \n 2.  Incluir um novo projeto a um cliente \n 3.  Lista dos clientes \n 4.  Lista dos projetos \n 5.  Lista dos clientes com seus respectivos projetos \n 6.  Quantia a pagar por um cliente \n 7.  Quantia já paga por um cliente \n 8.  Pesquisar o projeto pelo codigo \n 9.  Pesquisar o cliente pelo codigo  \n 10. Remover um projeto de um cliente  \n 11. Remover um cliente \n 12. Ver lista de devedores"<<endl<<"-> ";
    cin >>respMenu;
    if (respMenu==1){
    	for (int i=0;i==0;i++){
    		cout<< "Digite o nome do cliente: ";
        	cin >> c[Som].nome;
        	cout<< "Digite o endere�o do cliente: ";
        	cin >> c[Som].endereco;
        	cout<< "Digite o telefone do cliente: ";
        	cin >>c[Som].telefone;
        	cout<< "Cliente cadastrado com sucesso!! ";
        	system("pause");
        	Som++;
        }
    }
    if (respMenu==2){
    	
	}
	if (respMenu==2){
		
	}
	if (respMenu==3){
		
	}
	if (respMenu==4){
		
	}
	if (respMenu==5){
		
	}
	if (respMenu==6){
		
	}
	if (respMenu==7){
		
	}
	if (respMenu==8){
		
	}
	if (respMenu==9){
		
	}
	if (respMenu==10){
		
	}
	if (respMenu==11){
		
	}
	if (respMenu==12){
		
	}
    if (respMenu==0){
        break;
        }

    }
}

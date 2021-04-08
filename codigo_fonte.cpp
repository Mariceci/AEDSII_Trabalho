#include <iostream>
#include <stdio.h>
using namespace std;

struct Projeto{
	string nomeP;
	string dataInicialP;
	string dataFinalP;
	float precoP;
	float pagoP;
	float receberP;
};
struct Cliente {
	string nome;
	string endereco;
	int telefone;
	Projeto proje;
};
void imprimir (){
	cout<<" "<<endl;
}
int main(){
    int respMenu,Som1=0,Som2=0;
    Cliente c[1000];
    Projeto p[1000];
    for (;;){
    	system ("cls");
    cout<<" Digite o numero referente a acao escolhida \n 1.  Incluir um novo cliente na lista \n 2.  Incluir um novo projeto a um cliente \n 3.  Lista dos clientes \n 4.  Lista dos projetos \n 5.  Lista dos clientes com seus respectivos projetos \n 6.  Quantia a pagar por um cliente \n 7.  Quantia já paga por um cliente \n 8.  Pesquisar o projeto pelo codigo \n 9.  Pesquisar o cliente pelo codigo  \n 10. Remover um projeto de um cliente  \n 11. Remover um cliente \n 12. Ver lista de devedores"<<endl<<"-> ";
    cin >>respMenu;
    if (respMenu==1){
    	cout<< "Digite o nome do cliente: ";
        cin >> c[Som1].nome;
        cout<< "Digite o endereco do cliente: ";
        cin >> c[Som1].endereco;
        cout<< "Digite o telefone do cliente: ";
        cin >> c[Som1].telefone;
        cout<< "Cliente cadastrado com sucesso!! ";
        system("pause");
        Som1++;
    }
    if (respMenu==2){
    	cout<< "Digite o nome do Projeto: ";
        cin >> p[Som2].nomeP;
        cout<< "Digite a data inicial do projeto: ";
        cin >> p[Som2].dataInicialP;
        cout<< "Digite a data final do projeto: ";
        cin >> p[Som2].dataFinalP;
		cout<< "Digite o preco do projeto: ";
        cin >> p[Som2].precoP;
		cout<< "Digite valor ja pago do projeto: ";
        cin >> p[Som2].pagoP;
		cout<< "Digite valor a receber do projeto: ";
        cin >> p[Som2].receberP;
        cout<< "Projeto cadastrado com sucesso!! ";
        system("pause");
        Som2++;  	
	}
	if (respMenu==3){
		cout<<"Lista de Clientes"<<endl;
		for (int i=0; i<Som1;i++){
			cout<< " Nome: " << c[i].nome << "\n Endereco: " << c[i].endereco << "\n Telefone: "<< c[i].telefone << endl << endl;
		}
		system("pause");
	}
	if (respMenu==4){
		cout<<"Lista de Projetos"<<endl;
		for (int i=0; i<Som2;i++){
			cout<< " Nome: " << p[i].nomeP << "\n Data Inicial: " << p[i].dataInicialP << "\n Data Final: "<< p[i].dataFinalP <<"\n Preco Total: "<< p[i].precoP <<"\n Preco a pagar: "<< p[i].pagoP << "\n Preco a receber: "<<p[i].receberP<< endl << endl;
		}
		system("pause");
		
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
		//if(receberP!=0){
			//cout<< //Clientes
		//}
		
	}
    if (respMenu==0){
        break;
        }

    }
}

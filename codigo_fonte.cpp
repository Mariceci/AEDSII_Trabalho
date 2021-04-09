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

/*void Busca Cliente (Cliente c; Sum1;nome;){
	for ()
}*/

void imprimir (){
	cout<<" "<<endl;
}
int main(){
    int respMenu,Som1=0,Som2=0;
    string Nc;
    Cliente c[1000];
   for (;;){
    	system ("cls");
    	cout<<" Digite o numero referente a acao escolhida \n 1.  Incluir um novo cliente na lista \n 2.  Incluir um novo projeto a um cliente \n 3.  Lista dos clientes \n 4.  Lista dos projetos \n 5.  Lista dos clientes com seus respectivos projetos \n 6.  Quantia a pagar por um cliente \n 7.  Quantia já paga por um cliente \n 8.  Pesquisar o projeto pelo codigo \n 9.  Pesquisar o cliente pelo codigo  \n 10. Remover um projeto de um cliente  \n 11. Remover um cliente \n 12. Ver lista de devedores"<<endl<<"-> ";
    	cin >>respMenu;
    	if (respMenu==1){
    	cout<< "Digite o nome do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som1].nome;
        cout<< "Digite o endereco do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som1].endereco;
        cout<< "Digite o telefone do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som1].telefone;
        cout<< "Cliente cadastrado com sucesso!! ";
        system("pause");
        Som1++;
    }
    if (respMenu==2){
    	cout << "Digite o nome do cliente que voce quer inserir um novo projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
    	cin >> Nc;
    	
    	cout<< "Digite o nome do Projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som2].proje.nomeP;
        cout<< "Digite a data inicial do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som2].proje.dataInicialP;
        cout<< "Digite a data final do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som2].proje.dataFinalP;
		cout<< "Digite o preco do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som2].proje.precoP;
		cout<< "Digite valor ja pago do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
        cin >> c[Som2].proje.pagoP;
		c[Som2].proje.receberP= c[Som2].proje.precoP- c[Som2].proje.pagoP;
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
			cout<< " Nome: " <<  c[i].proje.nomeP << "\n Data Inicial: " << c[i].proje.dataInicialP << "\n Data Final: "<< c[i].proje.dataFinalP <<"\n Preco Total: "<< c[i].proje.precoP <<"\n Preco a pagar: "<< c[i].proje.pagoP << "\n Preco a receber: "<<c[i].proje.receberP<< endl << endl;
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

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
	struct Cliente *esq;
    struct Cliente *dir;
};

typedef struct Cliente no;
typedef no *arvore;

void inserir (arvore &r, string Nome , int Tel, string end){
    if(r==NULL){
	r = new no;
	r->nome = Nome;
	r->telefone = Tel;
	r->endereco = end;
	r->esq = NULL;
	r->dir = NULL;
   } 
   else {
		if(Nome< r->nome) {
			inserir(r->esq,Nome,Tel,end);
		}
		else {
		   inserir(r->dir,Nome,Tel,end);
		}
   }
}

no *busca(arvore r, string k){
    if(r==NULL ||r->nome==k)
        return r;
    if(r->nome>k)
        return busca(r->esq,k);
    else
        return busca(r->dir,k);
}
void erd(arvore r){
    if(r!=NULL){
        erd(r->esq);
        cout <<r->nome<<" - ";
        erd(r->dir);
    }
}

void erd2(arvore r){
    if(r!=NULL){
        erd(r->esq);
        cout <<r->proje.nomeP<<" - ";
        erd(r->dir);
    }
}

void imprimir (){
	cout<<" "<<endl;
}

int main(){
	Projeto p[30];
	arvore r;
	r = NULL;
    int respMenu,Som2=0,tel;
    string nome,ende,b;
  	for (;;){
    	system ("cls");
    	cout<<" Digite o numero referente a acao escolhida \n 1.  Incluir um novo cliente na lista \n 2.  Incluir um novo projeto a um cliente \n 3.  Lista dos clientes \n 4.  Lista dos projetos \n 5.  Lista dos clientes com seus respectivos projetos \n 6.  Quantia a pagar por um cliente \n 7.  Quantia já paga por um cliente \n 8.  Pesquisar o projeto pelo codigo \n 9.  Pesquisar o cliente pelo codigo  \n 10. Remover um projeto de um cliente  \n 11. Remover um cliente \n 12. Ver lista de devedores"<<endl<<"-> ";
    	cin >>respMenu;
    	if (respMenu==1){
	    	cout<< "Digite o nome do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
	        cin >> nome;
	        cout<< "Digite o endereco do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
	        cin >> ende;
	        cout<< "Digite o telefone do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
	        cin >> tel;
	        cout<< "Cliente cadastrado com sucesso!! ";
	        inserir (r,nome,tel,ende);	        
	        system("pause");
    	}
   		if (respMenu==2){
	    	cout << "Digite o nome do cliente que voce quer inserir um novo projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
	    	cin >> b;
	    	arvore c = busca(r,b);
	    	if(c==NULL)
      	    	 cout<<endl<<"Nao encontrado";
    		else{
	       	 	cout<< "Digite o nome do Projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
		        cin >> c->proje.nomeP;
		        cout<< "Digite a data inicial do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
		        cin >> c->proje.dataInicialP;
		        cout<< "Digite a data final do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
		        cin >> c->proje.dataFinalP;
				cout<< "Digite o preco do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
		        cin >> c->proje.precoP;
				cout<< "Digite valor ja pago do projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
		        cin >> c->proje.pagoP;
				c->proje.receberP= c->proje.precoP - c->proje.pagoP;
		        cout<< "Projeto cadastrado com sucesso!! ";
		        system("pause"); 
     		} 	
		}
		if (respMenu==3){
			cout<<"Lista de Clientes"<<endl;
			erd(r);
			system("pause");
		}
		if (respMenu==4){
			cout<<"Lista de Projetos"<<endl;
			erd2(r);
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

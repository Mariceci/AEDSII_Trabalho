#include <iostream>
#include <stdio.h>
using namespace std;

struct Projeto{
	string Pessoa;
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
Projeto p[30];
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

void salvarlista(struct a,struct b,struct c,struct d,int e,int f){
	int cont=0
	for(int i=0;i<30;i++){
		if (cont!=0){
			p[cont].Pessoa = a;
			p[cont].nomeP = b;
			p[cont].dataInicialP = c;
			p[cont].dataFinalP = d;
			p[cont].precoP = e;
			p[cont].pagoP = f;
			p[cont].receberP = e-f;
			cont++;
		}
		else {
			p[i].Pessoa = a;
			p[i].nomeP = b;
			p[i].dataInicialP = c;
			p[i].dataFinalP = d;
			p[i].precoP = e;
			p[i].pagoP = f;
			p[i].receberP = e-f;
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
        cout <<r->nome<<endl;
        erd(r->dir);
    }
}



int main(){
	arvore r;
	r = NULL;
    int respMenu,Som2=0,tel;
    string nome,ende,b,c,d;
  	for (;;){
    	system ("cls");
    	cout<<" Digite o numero referente a acao escolhida \n 1.  Incluir um novo cliente na lista \n 2.  Incluir um novo projeto a um cliente \n 3.  Lista dos clientes \n 4.  Lista dos projetos \n 5.  Lista dos clientes com seus respectivos projetos \n 6.  Quantia a pagar por um cliente \n 7.  Quantia ja paga por um cliente \n 8.  Pesquisar o projeto pelo codigo \n 9.  Pesquisar o cliente pelo codigo  \n 10. Remover um projeto de um cliente  \n 11. Remover um cliente \n 12. Ver lista de devedores"<<endl<<"-> ";
    	cin >>respMenu;
    	if (respMenu==1){
	    	cout<< "Digite o nome do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
	        cin >> nome;
	        cout<< "Digite o endereco do cliente\nUtilize Underline(EX:Bairro_Rua): ";
	        cin >> ende;
	        cout<< "Digite o telefone do cliente \nN�o ultilize qualquer tipo de separa��o (EX: 00123456789: ";
	        cin >> tel;
	        cout<< "Cliente cadastrado com sucesso!! ";
	        inserir (r,nome,tel,ende);	        
	        system("pause");
    	}
   		if (respMenu==2){
   			erd(r);
	    	cout << "Digite o nome do cliente que voce quer inserir um novo projeto\nUtilize Underline(EX:Nome_Sobrenome): ";
	    	cin >> b;
	    	arvore c = busca(r,b);
	    	if(c==NULL)
      	    	 cout<<endl<<"Nao encontrado";
    		else{
	       	 	cout<< "Digite o nome do Projeto\nUtilize Underline(EX:Nome_Complemento): ";
		        cin >> c->proje.nomeP;
		        cout<< "Digite a data inicial do projeto\nUtilize Underline(EX:Setembro_14_2021): ";
		        cin >> c->proje.dataInicialP;
		        cout<< "Digite a data final do projeto\nUtilize Underline(EX:Setembro_14_2021): ";
		        cin >> c->proje.dataFinalP;
				cout<< "Digite o preco do projeto: ";
		        cin >> c->proje.precoP;
				cout<< "Digite valor ja pago do projeto: ";
		        cin >> c->proje.pagoP;
				c->proje.receberP= c->proje.precoP - c->proje.pagoP;
		        cout<< "Projeto cadastrado com sucesso!! ";
		        salvarlista(b,c->proje.nomeP,c->proje.dataInicialP,c->proje.dataFinalP,c->proje.precoP,c->proje.pagoP)
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
			for(int i=0;i<30;i++){
				cout<<p[i].nomeP << endl; //Tem q colocar eles organizados em ordem alfabetica ai vc usa o metodos de ordena��o
			}
			system("pause");		
		}
		if (respMenu==5){
			for(int i=0;i<30;i++){ // testar
				erd(r); // testar
				cout<<p[i].nomeP << endl; //Tem q colocar eles organizados em ordem alfabetica ai vc usa o metodos de ordena��o
			}	
		
		}
		if (respMenu==6){
			cout << "Digite o nome do cliente que voce quer saber quanto ele tem a pagar:"<<endl;
			cin >> c;
			cout<<"Ele precisa pagar a quantia de: ";
			for (int i=0; i<30;i++){
		       	if( c== p[i].nomeP ){
	      	    	 cout<<p[i].receberP<<" "<<endl;
	    		 	}
			}
			system("pause");
		}
		if (respMenu==7){
			cout << "Digite o nome do cliente que voce quer saber quanto ele ja pagou:"<<endl;
			cin >> d;
			cout<<"Ele ja pagau a quantia de: ";
			for (int i=0; i<30;i++){
		       	if(d ==p[i].nomeP){
	      	    	 cout<<p[i].pagoP<<" "<<endl;
	    		 	}
			}
			system("pause");
		}
		if (respMenu==8){
			
		}
		if (respMenu==9){
			
		}
		if (respMenu==10){
/*			string comparaNomeP;
			cout << "Digite o nome do projeto que voce quer remover:"<<endl;
			cin >> comparaNomeP;
			for (int i=0; i<30;i++){
		       	if( p[i].nomeP== comparaNomeP ){
	      	    	remove_p[i].nomeP;
	    		 	}
			}
			system("pause");
			
			*/
		}
		if (respMenu==11){
			string comparaNome;
			cout << "Digite o nome do cliente que voce quer remover:"<<endl; // testar
			cin >> comparaNome; // testar
			for (int i=0; i<30;i++){ // testar
		       	if( p[i].nome== comparaNome ){ // testar
	      	    	delete p[i].nome; // testar
	      			cout<<"Cliente removido!"<<endl; // testar
	    		 	}
			}
			system("pause");
			

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

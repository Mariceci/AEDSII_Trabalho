#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Projeto{
	string Pessoa;
	string nomeP;
	string dataInicialP;
	string dataFinalP;
	float precoP;
	float pagoP;
	float receberP;
	int cod;
};
struct Cliente {
	string nome;
	string endereco;
	int CPF;
	int telefone;
	struct Cliente *esq;
    struct Cliente *dir;
};
Projeto p[30];
typedef struct Cliente no;
typedef no *arvore;
int cont=0;

void inserir (arvore &r, string Nome ,int cpf, int Tel, string end){
    if(r==NULL){
	r = new no;
	r->nome = Nome;
	r->CPF = cpf;
	r->telefone = Tel;
	r->endereco = end;
	r->esq = NULL;
	r->dir = NULL;
   } 
   else {
		if(Nome< r->nome) {
			inserir(r->esq,Nome,cpf,Tel,end);
		}
		else {
		   inserir(r->dir,Nome,cpf,Tel,end);
		}
   }
}

void salva (string a,string b,string c,string d,int e,int f,int g){
	p[g].Pessoa=a;
	p[g].nomeP=b;
	p[g].dataInicialP=c;
	p[g].dataFinalP=d;
	p[g].precoP=e;
	p[g].pagoP=f;
	p[g].receberP=e-f;
	p[g].cod = g;	
	}

/*void ordena(Item *A, Indice *n)  
{ Indice i, j, Min;
  Item aux;
  for (i = 1; i <= *n - 1; i++) {
  	Min = i;
    	for (j = i + 1; j <= *n; j++){
          	if (p[j].nomeP < p[Min].nomeP){
            	Min = j;
            	cont ++;
            }
        }
      	aux = p[Min]; 
      	p[Min] = p[i]; 
      	p[i] = aux;
    }
}*/

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

void busca_proj(arvore r,int h){
    if(r!=NULL){
        busca_proj(r->esq,h);
        cout <<r->nome<<endl<<"Projetos:"<<endl;;
        arvore c=busca(r,r->nome);
        for (int i=0;i<h;i++){
	        if(c->nome==p[i].Pessoa){
	        	cout<<p[i].nomeP<<endl;
		}}
        busca_proj(r->dir,h);
    }
}
void buscar_cod (int codigo, int h){
	for (int i=0;i<h;i++){
	    if(codigo==p[i].cod){
	        cout<<"Nome do Projeto: "<<p[i].nomeP<<endl;
	        cout<<"Data de iniciacao do projeto: "<<p[i].dataInicialP;
			cout<<"Data de filanizacao do projeto: "<<p[i].dataFinalP;
			cout<<"Preco total do projeto: "<<p[i].precoP;
			cout<<"Preco ja pago pelo cliente: "<<p[i].pagoP;
			cout<<"Preco a pagar pelo cliente: "<<p[i].receberP;
		}
	}
	
}

int main(){
	arvore r;
	r = NULL;
    int respMenu,CPF,Som2=0,tel, pt,pp,pcod;
    string nome,ende,b,c,d,np, di , df;;
  	for (;;){
    	system ("cls");
    	cout<<" Digite o numero referente a acao escolhida \n 0.  Encerrar o Programa \n 1.  Incluir um novo cliente na lista \n 2.  Incluir um novo projeto a um cliente \n 3.  Lista dos clientes \n 4.  Lista dos projetos \n 5.  Lista dos clientes com seus respectivos projetos \n 6.  Quantia a pagar por um cliente \n 7.  Quantia ja paga por um cliente \n 8.  Pesquisar o projeto pelo codigo \n 9.  Pesquisar o cliente pelo codigo  \n 10. Remover um projeto de um cliente  \n 11. Remover um cliente \n 12. Ver lista de devedores"<<endl<<"-> ";
    	cin >>respMenu;
    	if (respMenu==1){
	    	cout<< "Digite o nome do cliente\nUtilize Underline(EX:Nome_Sobrenome): ";
	        cin >> nome;
	        cout<< "Digite o CPF do cliente: ";
	        cin>> CPF;
	        cout<< "Digite o endereco do cliente\nUtilize Underline(EX:Bairro_Rua): ";
	        cin >> ende;
	        cout<< "Digite o telefone do cliente \nN�o ultilize qualquer tipo de separa��o (EX: 00123456789: ";
	        cin >> tel;
	        cout<< "Cliente cadastrado com sucesso!! ";
	        inserir (r,nome,CPF,tel,ende);	        
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
		        cin >> np;
		        cout<< "Digite a data inicial do projeto\nUtilize Underline(EX:Setembro_14_2021): ";
		        cin >> di;
		        cout<< "Digite a data final do projeto\nUtilize Underline(EX:Setembro_14_2021): ";
		        cin >> df;
				cout<< "Digite o preco do projeto: ";
		        cin >> pt;
				cout<< "Digite valor ja pago do projeto: ";
		        cin >> pp;
		        cout<< "Projeto cadastrado com sucesso!! "<<endl<< "O codigo do projeto �: "<<cont+1;
		        salva(b,np,di,df,pt,pp,cont);
		        cont++;
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
			for(int i=0;i<cont;i++){
				cout<<p[i].nomeP << endl; //Tem q colocar eles organizados em ordem alfabetica ai vc usa o metodos de ordena��o
			}
			system("pause");		
		}
		if (respMenu==5){
			busca_proj(r,cont);	
			system("pause");
		}
		if (respMenu==6){
			cout<<"Lista de Clientes"<<endl;
			erd(r);
			cout << "Digite o nome do cliente que voce quer saber quanto ele tem a pagar:"<<endl;
			cin >> c;
			cout<<"Ele precisa pagar a quantia de: ";
			for (int i=0; i<30;i++){
		       	if( c== p[i].Pessoa ){
	      	    	 cout<<p[i].receberP<<" + ";
	    		 	}
			}
			system("pause");
		}
		if (respMenu==7){
			cout<<"Lista de Clientes"<<endl;
			erd(r);
			cout << "Digite o nome do cliente que voce quer saber quanto ele ja pagou:"<<endl;
			cin >> d;
			cout<<"Ele ja pagou a quantia de: ";
			for (int i=0; i<30;i++){
		       	if(d==p[i].Pessoa){
	      	    	 cout<<p[i].pagoP<<" + ";
	    		 	}
			}
			system("pause");
		}
		if (respMenu==8){
			cout<<"Digite o codigo do projeto: ";
			cin>>pcod;
			buscar_cod(pcod,cont);
			system("pause");
			
		}
		if (respMenu==9){
			
		}
	/*if (respMenu==10){
			string comparaNomeP;
			cout << "Digite o nome do projeto que voce quer remover:"<<endl;
			cin >> comparaNomeP;
			for (int i=0; i<30;i++){
		       	if( p[i].nomeP== comparaNomeP ){
	      	    	remove_p[i].nomeP;
	    		 	}
			}
			system("pause");
			
			
		}
		if (respMenu==11){
			string comparaNome;
			cout << "Digite o nome do cliente que voce quer remover:"<<endl; // testar
			cin >> comparaNome; // testar
			for (int i=0; i<30;i++){ // testar
		       	if( p[i].Pessoa== comparaNome ){ // testar
	      	    	 p.remove(p.begin()+i) ; // testar
	      			cout<<"Cliente removido!"<<endl; // testar
	    		 	}
			}
			system("pause"); 	
		}*/
		
		if (respMenu==12){
			cout<< "Lista de devedores:"<<endl;
			for (int i=0;i<30;i++){
				if(p[i].receberP!=0){
					cout<<p[i].Pessoa<<endl;
				}
			}
			system("pause");
		}
	    if (respMenu==0){
	        break;
	        }
	
	    }
}

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
	int cod;
};
struct Cliente {
	string nome;
	string endereco;
	double CPF;
	double telefone;
	int codi;
	struct Cliente *esq;
    struct Cliente *dir;
};
Projeto p[30];
typedef struct Cliente no;
typedef no *arvore;
int cont=0;

void inserir (arvore &r, string Nome ,double cpf, double Tel, string end,int codigo){
    if(r==NULL){
	r = new no;
	r->nome = Nome;
	r->CPF = cpf;
	r->telefone = Tel;
	r->endereco = end;
	r->codi = codigo;
	r->esq = NULL;
	r->dir = NULL;
   } 
   else {
		if(Nome< r->nome) {
			inserir(r->esq,Nome,cpf,Tel,end,codigo);
		}
		else {
		   inserir(r->dir,Nome,cpf,Tel,end,codigo);
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

void ordena(int contagem){
 int menor,j;
 string temp;
  for (int i = 1; i <contagem; i++) {
	menor = i;
	for (j = i + 1; j <contagem; j++){
	   if (p[j].nomeP < p[menor].nomeP){
	        menor = j;
	        }
	    }
	    cout<< temp<<endl;
	    cout<< p[j].nomeP<<endl;
	    cout<< p[menor].nomeP<<endl;
	    temp = p[j].nomeP;
	    p[j].nomeP=p[menor].nomeP;
	    p[menor].nomeP=temp;
	    cout<< "teste"<<endl;
		cout<< temp<<endl;
	    cout<< p[j].nomeP<<endl;
	    cout<< p[menor].nomeP<<endl;
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

void buscar_codP (int codigo, int h, arvore r ){
	for (int i=0;i<h;i++){
	    if(codigo==p[i].cod){
	        cout<<"Nome do Projeto: "<<p[i].nomeP<<endl;
	        cout<<"Data de iniciacao do projeto: "<<p[i].dataInicialP<<endl;
			cout<<"Data de filanizacao do projeto: "<<p[i].dataFinalP<<endl;
			cout<<"Preco total do projeto: "<<p[i].precoP<<endl;
			cout<<"Preco ja pago pelo cliente: "<<p[i].pagoP<<endl;
			cout<<"Preco a pagar pelo cliente: "<<p[i].receberP<<endl;
		}
		if(r->codi==codigo)
        	cout<<"Nome do cliente: "<<r->nome<<endl<<"O CPF desse cliente e: "<<r->CPF<<endl<<"O endereco: "<<r->endereco<<endl<<"Telefone: "<<r->telefone;
    	}
	}


no *buscar_codC(arvore r, int codigo){
	 if(r==NULL ||r->codi==codigo)
        return r;
    if(r->codi>codigo)
        return buscar_codC(r->esq,codigo);
    else
        return buscar_codC(r->dir,codigo);
}

int main(){
	arvore r;
	r = NULL;
    int respMenu,Som2=0,pt,pp,pcod,codC, contA=0;
    string nome,ende,b,c,d,np, di , df;
    double CPF,tel;
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
	        cout<< "Digite o telefone do cliente \nNao ultilize qualquer tipo de separacaoo (EX: 00123456789): ";
	        cin >> tel;
	        cout<< "Cliente cadastrado com sucesso!! \nO codigo desse cliente e : "<<contA <<"  ";
	        inserir (r,nome,CPF,tel,ende,contA);
			contA++;	        
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
		        cout<< "Digite a data inicial do projeto\n(EX:01/01/2021: ";
		        cin >> di;
		        cout<< "Digite a data final do projeto\n(EX:01/01/2021): ";
		        cin >> df;
				cout<< "Digite o preco do projeto \nUtilize ponto para centavos(EX: 11.11): ";
		        cin >> pt;
				cout<< "Digite valor ja pago do projeto \nUtilize ponto para centavos(EX: 11.11): ";
		        cin >> pp; 
		        cout<< "Projeto cadastrado com sucesso!! "<<endl<< "O codigo desse projeto é: "<<cont<<"  ";
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
			//ordena(cont);
			for(int i=0;i<cont;i++){
				cout<<p[i].nomeP << endl; 
			}
			system("pause");		
		}
		if (respMenu==5){
			"Cliente e sesus respectivos projetos: ";
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
			buscar_codP(pcod,cont,r);
			system("pause");
			
		}
		if (respMenu==9){
			cout<< "Digite o codigo do cliente : ";
			cin>>codC;
			buscar_codC(r,codC);
			cout<< "Nome do cliente: "<<r->nome<<endl<<"O CPF desse cliente e: "<<r->CPF<<endl<<"O endereco: "<<r->endereco<<endl<<"Telefone: "<<r->telefone<<endl;
			for (int i=0; i<30;i++){
		       	if(r->nome==p[i].Pessoa){
	      	    		cout<<"Nome do Projeto: "<<p[i].nomeP<<endl;
				        cout<<"Data de iniciacao do projeto: "<<p[i].dataInicialP<<endl;
						cout<<"Data de filanizacao do projeto: "<<p[i].dataFinalP<<endl;
						cout<<"Preco total do projeto: "<<p[i].precoP<<endl;
						cout<<"Preco ja pago pelo cliente: "<<p[i].pagoP<<endl;
						cout<<"Preco a pagar pelo cliente: "<<p[i].receberP<<endl;
						cout<<"O codigo do projeto e: "<<p[i].cod<<endl;
	    		 	}
			}
			system("pause");
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
			string parametro;
			cout<< "Lista de devedores:"<<endl;
			for (int i=0;i<cont;i++){
				if(p[i].receberP!=0){
					cout<<p[i].Pessoa<<endl<<"--Projeto(s)--"<<endl;
					parametro=p[i].Pessoa;
					for(int i=0;i<cont;i++){
						if (p[i].Pessoa==parametro){
							cout<<p[i].nomeP<<endl;
						}
					}
				}
			}
			system("pause");
		}
	    if (respMenu==0){
	        break;
	        }
	
	    }
}

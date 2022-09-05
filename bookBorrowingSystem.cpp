#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class booksystem{
	
public:
	
	//建構式
	booksystem(){
		borrowNumSum=0;
		borrowCharArray[100][50];
	} 
	//解構式 
	~booksystem(){
		cout<<"See you!"<<endl;
	} 
	
	//登入 
	void login(char *id_Input){
		FILE *in;
		int i,j;
		char id_data_in[100][50];
		
		in = fopen(id_Input,"r");
		if(in == NULL){
			cout<<"Welcome! Have a good experience for your first use!"<<endl<<endl;
		}
		else{
			fscanf(in,"%d",&borrowNumSum);
			fflush(stdin);
			fgets(id_data_in[0], sizeof(id_data_in[0]), in);
			for(i=0;i<borrowNumSum;i++){
				fflush(stdin);
				fgets(borrowCharArray[i], sizeof(borrowCharArray[i]), in);
		}
			cout<<"Welcome back! "<<id_Input<<endl<<endl;
		}
		fclose(in);
	}
		
	
	//登出 
	void logout(char *id_Input){
		FILE *out;
		int i,j;
		out = fopen(id_Input,"w");
		fprintf(out,"%d\n",borrowNumSum);
		for(i=0;i<borrowNumSum;i++){
			fprintf(out,"%s\n",borrowCharArray[i]);
		}
		fclose(out);
		cout<<"Already logged out and saved. Thanks for your visiting!\n";
		return;
	}
	
	
	//歷史借閱紀錄 
	void history(){
		int i;
		cout<<"You totoally borrowed "<<borrowNumSum<< " books."<<endl<<endl;
		for(i=0;i<borrowNumSum;i++){
			cout<<"Book"<<i+1<<" : "<< borrowCharArray[i]<<endl;
		}
		cout<<endl;
		return;
	}
	

	//借書 
	void borrow(){	
		int borrowNum,i;
		char bookname[50];
		cout<<"How many books you want to borrow?"<<endl;
		cin>>borrowNum;
	
		cout<<"Please enter these books' name: "<<endl;
		for(i=borrowNumSum;i<(borrowNumSum+borrowNum);i++){
			
			cout<<"book "<<i+1<<": ";
			fflush(stdin);
			//cin.ignore(); 會多一欄輸入? 
			cin.getline(borrowCharArray[i],50);
			}
		fflush(stdin);
		borrowNumSum += borrowNum;
		cout<<"Borrow completely!"<<endl;
	}
	

private:	
	int borrowNumSum;
	char borrowCharArray[100][50];

};

int main() {
	
	char option;
	booksystem account;
	char idInput[15];
	char borrowbook[20];
	
	cout<<"===BOOK SYSTEM==="<<endl<<endl;
	cout<<"Please enter your member ID: ";
	cin>> idInput;
	account.login(idInput);

	while(1){
		cout<<idInput<<", how can I help you?"<<endl<<endl
			<<"b: borrow book"<<endl<<"h: history record"<<endl<<"q: quit"<<endl<<">";
		cin>>option;
		
		switch(option){
			case 'b':
				account.borrow();
				break;
			case 'h':
				account.history();
				break;
			case 'q':
				account.logout(idInput);				
				system("pause");
				return 0;
			default:
				printf("Sorry, No this function \n");
				break;
		}
		system("pause");  
		system("cls");  
	}
	return 0;

}

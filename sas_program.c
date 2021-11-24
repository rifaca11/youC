#include <stdio.h>
#include <stdlib.h>
#include <string.h>




 // Data of client =======================================================================================
  
    typedef struct client
   {
       char first_name[20];
       char last_name [20];
       char  number [10];
       char  CIN [10];
       float amount;

   }Client;
int AllAccount =0;
Client TC[100];




// function create Account///////
void CreateAccount(){
	
        printf("--> enter first name:\n");
		scanf("%s",TC[AllAccount].first_name);
		
        printf("--> enter last name:\n");
		scanf("%s",TC[AllAccount].last_name);
		
        printf("--> enter number of client :\n");
		scanf("%s",TC[AllAccount].number);
		
        printf("--> enter cin :\n");
		scanf("%s",TC[AllAccount].CIN);
		
        printf("--> enter amount :\n");
		scanf("%f",&TC[AllAccount].amount);
		AllAccount++;
	
}
// function create Accounts///////
void CreateAccounts(){
	int nbrAccount,i;

    printf("donner nmbre des comptes\n");
    scanf("%d",&nbrAccount);
	for( i =0;i<nbrAccount;i++){
        printf("-->le compte %d\n",i+1);
		CreateAccount();
	}	
}
// function display a lot of account///////
void displayAccounts(){
	int i;
	for( i=0;i<AllAccount;i++){
		printf("--> affichage compte %d\n",i+1);
		printf("--> the first name %s \n",TC[i].first_name);
		printf("--> the last name %s \n",TC[i].last_name);
		printf("--> the the number %s \n",TC[i].number);
		printf("--> the the cin %s\n",TC[i].CIN);
		printf("--> the amount %f \n",TC[i].amount);
	}
}
// function display one account ///////**************************
void displayAccount(int i){
	
		printf("--> affichage compte %d\n",i+1);
		printf("--> the first name %s\n",TC[i].first_name);
		printf("--> the last name %s\n",TC[i].last_name);
		printf("--> the number %s \n",TC[i].number);
		printf("--> the cin %s\n",TC[i].CIN);
		printf("--> the amount %f\n",TC[i].amount);
	
}
// function search by cin ///////*********************************
int  SearshByCin(char CIN[10]){
    
    int i;
    
 for( i=0; i<AllAccount; i++)
 {
    if(strcmp(CIN, TC[i].CIN )== 0)
    {   
        return i;
    }
 }	
 return -1;
}

//********************************function Ascendant***************************************************
void trie_Ascendant( ) {
        Client c1;
     int i,j;
   
   
    for (i = 0; i < AllAccount - 1; i++)
    {
        for (j = i + 1; j < AllAccount; j++){

            if (TC[j].amount < TC[i].amount)
            {
                c1=TC[i];
                TC[i]=TC[j];
                TC[j]=c1;
                
            }
        }
    }
        
}

//********************************function Descendant***************************************************
void trie_Descendant( ) {
        Client c1;
   int i,j;
   
   
    for (i = 0; i < AllAccount - 1; i++)
    {
        for (j = i + 1; j < AllAccount; j++){

            if (TC[j].amount > TC[i].amount)
            {
                c1=TC[i];
                TC[i]=TC[j];
                TC[j]=c1;
                
            }
        }
    }
}



//********************************function Ascendant than figure***************************************************
void trie_asup(float figure) {
	int i;


 trie_Ascendant();

  
    
    
    for(i=0;i<AllAccount;i++)
	{
    	if(TC[i].amount>=figure)
		{
    		displayAccount(i);
		}
	}
    
}

//********************************funct2ion Descendant than figure***************************************************
void trie_dsup(float figure) {
int i;
    trie_Descendant();

        
        for(i=0;i<AllAccount;i++)
        {
            if(TC[i].amount >=figure)
            {
        displayAccount(i);
                
            }
        }
}
//*******************************************Loyalty***************************************************

void trieLoyalty() {
    trie_Descendant();
        int i;
        for(i=0;i<3;i++)
        {
            TC[i].amount+=TC[i].amount*(1.3/100);
        
        }displayAccounts();
}
// *************** retrait **************

void Retrait ()
{
    char CIN[10];
    int  withdrawal =0;
    printf("3tini cin ");
  scanf("%s",CIN);
    if(SearshByCin(CIN)>=0){
     printf("enter the sum of withdrawal DH : \n");
    scanf("%d", &withdrawal);
    do
    {
        if(withdrawal<0 ) //  amount(withdrawal) superior than 0
            {
            printf("enter the sum of withdrawal DH superior than 0 : \n");
            scanf("%d", &withdrawal);
            }

    }while (withdrawal<0 );
    if (withdrawal>TC[0].amount) // withdrawal superior than amount 

        printf(" u're amount is not enough to withdraw \n");

    else
    {
        TC[0].amount= TC[0].amount-withdrawal;

    }
 }
}
void Depot (){
     char CIN[10];
    int deposit=0;
     printf("3tini cin ");
  scanf("%s",CIN);
    if(SearshByCin(CIN)>=0)
    {
 printf("enter the sum of deposit DH : \n");
    scanf("%d", &deposit);
        do
    {

        if(deposit<0)
        { // amount superior than  0
            printf("enter the sum of deposit DH superior than 0 : \n");
            scanf("%d", &deposit);
        }
            
    }while (deposit<0 );
    if (deposit>TC[0].amount) // deposit superior than amount 
            printf(" u're amount is not enough to deposit \n");
    else
    TC[0].amount= TC[0].amount+deposit;
    
    }
}
int main()
{
    // VARIABLES ===========================================================================================
                    
     int choice ,i , npr,found;
       char CIN[10];            
                   
        do
        {
            do
            {
             // Main ==============================================================================
                printf("=========================== Main =============================\n");

                printf("1 => Create banck account \n");
                printf("2 => Create a lot of banck account \n");
                printf("3 => Operations \n");
                printf("4 => Display \n");
                printf("5 => Loyalty \n");
                printf("6 => Exit \n\n");
                printf("enter u're choice : \n");
			    scanf("%d", &choice);

            }while(choice <1 || choice>6);

                switch(choice)
                {

                    case 1: // enter one account ===========================================================================
                         CreateAccount();
                         system("cls");
                    break;
                    case 2: // create a lot of account  ======================================================================
                        CreateAccounts(); 
						system("pause");
						
                    break;
                    case 3: // enter the operation ==============================================================================
                         printf("Operations \n");
					
                        int choice_Operation;
                        do
                        {
                            printf("1 => Withdrawal\n");
                            printf("2 => Deposit \n");

                            printf("enter u're choice : \n");
                            scanf("%d", &choice_Operation);

                        }while(choice_Operation <1 || choice_Operation>2);
                          switch(choice_Operation)
                            {
                                case 1: // Withdrawal ==========================================================================
                                    Retrait();
                                      
                                break;
                                    
                                case 2: //  Deposit  =====================================================================================
								Depot();
                                break;

                            default:
                            break;
                                          
                            }         

                    case 4: // Display ==================================================================================
                    printf("Display \n");
                           int choice_display;
		                do
                        {
                            printf("1 => Search by cin \n");
                            printf("2 => In Ascending Order \n");
                            printf("3 => In Descending Order \n");
                            printf("4 => In Ascending Order (bank accounts with an amount greater than a number entered) \n ");
                            printf("5 => In Descending Order (bank accounts with an amount greater than the number entered) \n ");
                            

                            printf("enter u're choice : \n");
                            scanf("%d", &choice_display);

                        }while(choice_display <1 || choice_display>5);
                            if(choice_display==1)
			                {
                                printf("Enter a CIN  to search: \n ");
                                    scanf("%s", CIN);
                                    int ret=SearshByCin(CIN);
                                      if(ret>=0){
                                          displayAccount(ret);
                                      } else
                                          printf("malkaynx");
                                          
                            }  
                            else if(choice_display==2){
                                trie_Ascendant();
                                
                                displayAccounts();
                            }
                            else if(choice_display==3){

                                trie_Descendant();
                                displayAccounts();
                            }
                            else if (choice_display==4){
                                float figure;
                                     printf("enter a figure \n");
                                    scanf("%f",&figure);
                                     trie_asup(figure);
                            }
                                
                            else if (choice_display==5)
                            {
                                float figure;
                                     printf("enter a figure \n");
                                    scanf("%f",&figure);
                                    trie_dsup(figure);
                            }
                                
                            else 
                            printf("error");
			        break;
                            
                    case 5: 
                    trieLoyalty();
                    break;
                    
                    case 6:
                    exit(0);
                    break;
                    
                    default:
                    break;
                    
                }
				}while(choice !=6);
            return 0;
}


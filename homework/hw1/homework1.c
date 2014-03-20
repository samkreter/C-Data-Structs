//Sam Kreter
//sakfy6
//Homework 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20
#define CHAMP_LENGTH 20
#define TEAM_LENGTH 10


//struct defintinon for the list
typedef struct player{
	char* name;
	char* champion;
	char* team;
	int	kills;
	int deaths;
	
	struct player *next;
}Player;


//function prototypes
void check_malloc(char* string);
Player* rinsert(Player* head, Player* node);
Player* new_player(char* name, char* champion, char* team, int kills, int deaths);
Player* insert_by_player(Player* head, Player* node);
void print_list(Player* head);
int update_records(Player* head, char* champion, char* champ_name, int kills, int deaths);
void free_node(Player* head);
Player* delete_player_even(Player* head);
Player* delete_player_odd(Player* head);
Player* reverse_list(Player* head);

/*
 * This function begins by checking that exactly two command line arguments are given. If not
 * the program is terminated with an appropriate error message. It then attempts to open the input 
 * file and terminates with an appropriate error message if it fails. The function then runs through 
 * the input file, calls new_player() and then insert_by_player() to create a linked list. print_list() is
 * called when the linked list is fully completed. The program will then ask for a name of a player, 
 * new ratings, and call update_records. The function will prompted for a new champion name, kills, and deaths 
 * until update_records() is successful. After, the list is successfully updated print_list() will be called. The function will
 * then call delete_player_even(), print_list(), reverse_list(), print_list(), delete_player_odd,
 * and print_list() one last time before exiting.
 */
 int main(int argc, char** argv)
 {

    //check for the number of arguments
    if(argc != 2){
      printf("Incorrect number of command line arguments");
      exit(0);
    }
    //setting the varibles and intitlizing the list
    char name[NAME_LENGTH], champion[CHAMP_LENGTH],new_champ[CHAMP_LENGTH], team[TEAM_LENGTH];
    int kills, deaths;
    Player* node = NULL;
    Player* head = NULL;

    //opening the file
    FILE* input = fopen(argv[1],"r");
    if(input == NULL){
      printf("Unable to open the file");
      exit(0);
    }

   
    while(fscanf(input,"%s%s%s%d%d",name,champion,team,&kills,&deaths) != EOF){
      node = new_player(name,champion,team,kills,deaths);
      head = insert_by_player(head,node);
    }

   close(input); //closeing the file

   
  print_list(node);
   
   

  //get info for update records
  printf("\n\nEnter a Champion to change: ");
  scanf("%s",champion);
  printf("\nEnter new champion, kills, and deaths: ");
  scanf("%s%d%d",new_champ,&kills,&deaths);
  //keep asking till update is succesfull
  while(update_records(head,champion,new_champ,kills,deaths) != 1){
     printf("\nChampion to change could not be found!\n");
     printf("\n\nEnter a Champion to change: ");
     scanf("%s",champion);
     printf("\nEnter new champion, kills, and deaths: ");
     scanf("%s%d%d",new_champ,&kills,&deaths);
   }
   print_list(head);
   
   //delete the even kill/ death in the list
   head = delete_player_even(head);
   print_list(head);

   //reverse the list
   head = reverse_list(head);
   print_list(head);
   

   //delete the odd kills/deaths
   head = delete_player_odd(head);
   print_list(head);
 
    

   return 0;

 }  

//simple function to check if the malloc worked succesfully 
void check_malloc(char* string){
  if(string == NULL){
    printf("Failed to malloc memory");
    exit(0);
  }
}

/*
 * Allocate space for a new Player node and set its members. The default
 * value of next should be NULL 
 * Return: A pointer to the new node
 */
   
 Player* new_player(char* name, char* champion, char* team, int kills, int deaths)
 {
   //malloc the node
   Player* n = (Player *)malloc(sizeof(Player));
   if(n == NULL){
     printf("Failed to malloc node");
     exit(0);
   }
   
   n->next = NULL;  //set the pointer to NULL

   n->name = (char *)malloc(sizeof(name)); //malloc space for name array
   check_malloc(n->name);

   n->champion = (char *)malloc(sizeof(champion));//malloc space for champion array
   check_malloc(n->champion);

   n->team = (char *)malloc(sizeof(team)); //malloc space for team array 
   check_malloc(n->team);

   //copy all the data to the node
   strcpy(n->name,name);
   strcpy(n->champion,champion);
   strcpy(n->team,team);
   n->kills = kills;
   n->deaths = deaths;

   return n;
     
 }
   
 /*
 * Inserts Player* node into the linked list specified by the pointer head. The node
 * should be inserted in alphabetical order by the field name.
 * Return: A pointer to the head of the linked list
 */
Player* insert_by_player(Player* head, Player* node)
{
  
  Player* temp = head;
  Player* prev = head;
  int alpha;
  //test if it is first iteam in list
  if(head == NULL){
    head = node;
    return head;
  }
  //test if there are only two nodes in the list
  if(temp->next == NULL){
    if(strcmp(node->name,temp->name) <= 0){
      node->next = temp;
      return node;
    }
    temp->next = node;
    return head;
  }
  else{
    if(strcmp(node->name,temp->name) < 0){  //test the alphibetical order
      node->next = temp;
      return node;
    }
    prev = temp;
    temp = temp->next;
    while(temp->next != NULL){
 
      if(strcmp(node->name,prev->name) <= 0){
        node->next = temp;
        prev->next = node;
        return head;
      }
      prev = temp;  //incriment the varibles
      temp = temp->next; 
    }
    //test the last node
    if(strcmp(node->name,temp->name) <= 0){
      node->next = temp;
      prev->next = node;
    }
    else{
      temp->next = node;
    }

    return head;
 }
}

/*
 * Runs through the linked list specified by the pointer head and prints it 
 * to the screen
 */
void print_list(Player* head)
{
  //test if there is no list
  if(head == NULL){
    printf("\n\nThe player list is empty!\n");
    exit(0);
  }

   //print out the list
  Player* temp = head;
  printf("\n\n%10s%10s%10s%10s%10s\n","Player","Champion","Team","Kills","Deaths");
  while(temp->next != NULL){
    printf("\n%10s%10s%10s%10d%10d\n",temp->name,temp->champion,temp->team,temp->kills,temp->deaths);
    temp = temp->next;
  }
  printf("\n%10s%10s%10s%10d%10d\n",temp->name,temp->champion,temp->team,temp->kills,temp->deaths);
 
}

/*
 * Searches through the linked list specified by the pointer head for a champion with a  
 * field champion that matches the string name. If found, the nodes records are updated to 
 * match that of the parameters.
 * Return: 1 if the linked list is updated, 0 otherwise
 */ 
int update_records(Player* head, char* champion, char* champ_name, int kills, int deaths)
{
    if(head == NULL){ // test if there is no list
      return 0;
    }
    else if(strcmp(head->champion,champion) == 0){ //find the correct champ
      strcpy(head->champion,champ_name);  
      head->kills = kills;
      head->deaths = deaths; //change everything 
      return 1;
    }
    return update_records(head->next,champion,champ_name,kills,deaths);
}   

/*
 * Runs through the linked list specifed by the pointer head and deletes every node 
 * whose kill death ratio is even. Kill Death ratio is found by kills divided by deaths
 * This function should call free_node().
 * Return: The head of the linked list
 */

Player* delete_player_even(Player* head){
  if(head == NULL){
    printf("Can not delete an Empty list");
  }

  Player* curr = head;
  Player* temp = curr->next;
  Player* prev = NULL;

  //test if need delete first node
  if((curr->kills/curr->deaths)%2 == 0){
    head = temp;
    free_node(curr);
    curr = NULL;
  }
  prev = curr;
  curr = temp;
  temp = temp->next;
  while(temp->next != NULL){ //test the middle of the list to delete
     if((curr->kills/curr->deaths)%2 == 0){
       if(prev !=NULL){
        prev->next = temp;
       free_node(curr);
       curr = temp;
       temp = temp->next;
       }
       else{
        free_node(curr);
        head = temp; //first node not deleted so assign head to it
        curr = temp;
        temp = temp->next;
       }
     }
     else{
       prev = curr;
       curr = temp;  
       temp = temp->next;
     } 
  }
  
  if((curr->kills/curr->deaths)%2 == 0){ //test the last element
    if(prev != NULL){ //if there is no part of the list then move head
      prev->next = temp;
      free_node(curr);
      curr = temp;
    }
    else{
      free_node(curr);
      curr = temp;
      head = temp;
    }
  }
  else{
    prev = curr;
    curr = temp;
  } //test the last node
  if((curr->kills/curr->deaths)%2 == 0){
    if(prev != NULL){
      prev->next = NULL;
      free_node(curr);
    }
    else{
      free_node(curr);
      head = NULL;
    }
  }
  return head;
}
/*
 * Runs through the linked list specifed by the pointer head and deletes every node 
 * whose kill death ratio is odd. Kill Death ratio is found by kills divided by deaths
 * This function should call free_node().
 * Return: The head of the linked list
 */



Player* delete_player_odd(Player* head){
  if(head == NULL){
    printf("Can not delete an Empty list");
  }

  Player* curr = head;
  Player* temp = curr->next;
  Player* prev = NULL;
  //test the first node 
  if((curr->kills/curr->deaths)%2 != 0){
    head = temp;
    free_node(curr);
    curr = NULL;
  }
  prev = curr;
  curr = temp;
  temp = temp->next;
  while(temp->next != NULL){  //test the middle ;of the list
     if((curr->kills/curr->deaths)%2 != 0){
       if(prev !=NULL){
        prev->next = temp;
       free_node(curr);
       curr = temp;
       temp = temp->next;
       }
       else{
        free_node(curr);
        head = temp;
        curr = temp;
        temp = temp->next;
       }
     }
     else{
       prev = curr;
       curr = temp;  
       temp = temp->next;
     } 
  }
    //tst the last node
  if((curr->kills/curr->deaths)%2 != 0){
    if(prev != NULL){
      prev->next = temp;
      free_node(curr);
      curr = temp;
    }
    else{
      free_node(curr);
      curr = temp;
      head = temp; //if node first to not be delete assign head to it
    }
  }
  else{
    prev = curr;
    curr = temp;
  } //test last node in the list
  if((curr->kills/curr->deaths)%2 != 0){
    if(prev != NULL){
      prev->next = NULL;
      free_node(curr);
    }
    else{
      free_node(curr);
      head = NULL;
    }
  }
  return head;
}
/*
 * Frees all allocated memory associated with the node "node"
 * Return : None
 */
void free_node(Player* node)
{
  free(node->name);// free the name
  free(node->champion); //free the champion
  free(node->team); //free the team
  free(node); //free the actual node
}

/*
 * Reverses the linked list
 * Return: The head of the linked list.
 */
Player* reverse_list(Player* head)
{	
    if(head->next == NULL){
      return head; //base case
    }
    Player * curr = reverse_list(head->next);

    head->next->next = head; //assign the second in front node to the head to test
    head->next = NULL;
    return curr;
} 

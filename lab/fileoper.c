
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

//struct def
typedef struct{
  int id;
  int grade;
} data;

// array of structs def
data student[MAX];

//function prototypes
int loadArray(char* filename);
void printArray(int size);
int searchArray(int size, int id, int ngrade);
int writeContent(char* fname, int size);
void sortArray(int size);

int main(int argc, char** argv)
{
  if(argc != 3){  //check if theres enough args
    printf("Insufficient arguments");
    return 0;
  }
  int id, ngrade;
  int size=loadArray(argv[1]);
  if(size == 0){  // check if the file can be opened
    printf("Unable to open the input file");
    return 0;
  }
  printf("\n\nStudent record\n");
  printArray(size);

  printf("\nEnter the ID of the student to search: ");
  scanf("%d",&id);
  printf("Enter a grade for the student: ");
  scanf("%d",&ngrade);
 
  if(!searchArray(size,id,ngrade)){  // check if the id is valid
    printf("\nStudent with id %d is not present in the class\n",id);
  }
  else{
    printf("\nUpdated student record\n");
    printArray(size);
    if(!writeContent(argv[2],size)){
      printf("Could not write to %s",argv[2]);
    }
  }

  sortArray(size);
  printf("\nBonus part\nPrinting sorted student record\n");
  printArray(size);
	
  return 0;
}

//functions

int loadArray(char* filename)
{
  int i=0;
  FILE* file=fopen(filename,"r");
  if(file==NULL)
  {
    return 0;
  }
	
  int size;
	
  fscanf(file, "%d" , &size);
    	
        
  for(i=0;i<size;i++){
    fscanf(file, "%d", &student[i].id);
    fscanf(file, "%d", &student[i].grade);
  }
	
  fclose(file);
  return size;
}

void printArray(int size){
  int i;
  printf("ID Grade\n");
  for(i=0; i<size; i++){
    printf("%d %d\n",student[i].id, student[i].grade);
  }
}

int searchArray(int size, int id, int ngrade){
  int i;
  for(i=0; i<size; i++){
    if(id == student[i].id){
      student[i].grade = ngrade;
      return 1;
    }
  }
  return 0;
}

int writeContent(char* fname, int size){
  int i;

  FILE* file = fopen(fname,"w");
  
  if(file == NULL){
    return 0;
  }

  for(i=0; i<size; i++){
    fprintf(file,"%d %d\n",student[i].id,student[i].grade);
  }
  

  fclose(file);
  
  return 1;
}

void sortArray(int size){
  int i, j, temp;
  for(i=0; i<size; i++){
    for(j=0; j<size; j++){
      if(student[j-1].grade > student[j].grade){
        temp = student[j-1].grade;
        student[j-1].grade = student[j].grade;
        student[j].grade = temp;
      }
    }
  }
}

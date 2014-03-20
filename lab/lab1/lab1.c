/*
 * Sam Kreter
 * 14180381
 * 128STRUCT
 */


#include<stdio.h>
#include<stdlib.h>


#define MAX_NAME_LENGTH 20
#define MAX_ARRAY_LENGTH 25

//struct def
typedef struct student{
  char name[MAX_NAME_LENGTH];
  int num_A;
  int num_B;
  int num_C;
  int num_D;
  int num_F;
  float gpa;
}student;

student class[MAX_ARRAY_LENGTH];

//function prototypes
int read_file(FILE *input);
void print_grade_distribution(int num_students);
void calculate_gpa(int index);
void write_to_file(FILE *output, int num_students);



int main(int argc, char** argv){

 

 
  if(argc != 3){
    printf("Incorrect number of command line arguments\nCorrect Usage ./a.out <input file> <output file>\n");
    return 0;
  }


  FILE* file=fopen(argv[1],"r");
  if(file==NULL){
    printf("Read file failed to be opened");
    return 0;
  }


  int num_students = read_file(file);
  close(file);

  print_grade_distribution(num_students);

  FILE* output=fopen(argv[2],"w");
  if(file==NULL){
    printf("Write file failed to be opened");
  }

  write_to_file(output,num_students);
  close(output);
  
  return 0;

}


int read_file(FILE *input){
  int i=0, size;
 
  fscanf(input, "%d" ,&size);

  for(i=0; i<size; i++){
    fscanf(input,"%s",class[i].name);
    fscanf(input,"%d",&class[i].num_A);
    fscanf(input,"%d",&class[i].num_B);
    fscanf(input,"%d",&class[i].num_C);
    fscanf(input,"%d",&class[i].num_D);
    fscanf(input,"%d",&class[i].num_F);
    
    calculate_gpa(i);
  }

  return size;
}


void print_grade_distribution(int num_students){
  int num[5] = {0},i,j;
  char letters[5] = {'A','B','C','D','F'}; 

  for(i=0; i<5; i++){
    switch(i){
      case 0: for(j=0;j<num_students;j++){
                num[i] += class[j].num_A;
              } 
              break;
      case 1: for(j=0;j<num_students;j++){
                num[i] += class[j].num_B;
              }
              break;
      case 2: for(j=0;j<num_students;j++){
                num[i] += class[j].num_C;
              } 
              break;
      case 3: for(j=0;j<num_students;j++){
                num[i] += class[j].num_D;
              }
              break;
      case 4: for(j=0;j<num_students;j++){
                num[i] += class[j].num_F;
              }
              break;
    }   


  }

  
  for(i=0; i<5; i++){
    printf("%c:",letters[i]);
    for(j=0; j<num[i]; j++){
      printf("-");
    }
    printf("\n"); 
  }
  
}

void calculate_gpa(int index){
  int a,b,c,d,f; 
 
  a = class[index].num_A;
  b = class[index].num_B;
  c = class[index].num_C;
  d = class[index].num_D;
  f = class[index].num_F;
  
  class[index].gpa = (a*4.0 + b*3.0 + c*2.0 + d + f) /(float) (a+b+c+d+f);
 
}

void write_to_file(FILE *output, int num_students){
 int i;

  for(i=0;i<num_students;i++){
    fprintf(output,"%s %f\n",class[i].name,class[i].gpa);
  } 
}


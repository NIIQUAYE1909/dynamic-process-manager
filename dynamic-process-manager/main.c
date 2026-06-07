#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int pid;
    char name[30];
    float memoryUsage;
} Process;

int main(){
     Process* processes = NULL;
     int count = 0;

     printf("How many processes? ");
     scanf("%d", &count);

     processes = (Process*) malloc(count * sizeof(Process));

     if(processes == NULL){
         fprintf(stderr, "Memory allocation failed\n");
         return 1;
     }else{
          for(int i = 0; i < count; i++) {
      printf("\nProcess %d\n", i + 1);

      printf("Enter PID: ");
      scanf("%d", &processes[i].pid);

      printf("Enter Name: ");
      scanf("%s", processes[i].name);

      printf("Enter Memory Usage: ");
      scanf("%f", &processes[i].memoryUsage);
  }
      printf("\n--- PROCESS LIST ---\n");

     for(int i = 0; i < count; i++) {
           printf("PID: %d | Name: %s | Memory: %.2f MB\n",
           processes[i].pid,
           processes[i].name,
           processes[i].memoryUsage);
     }
     
     }
     free(processes);
     return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int pid;
    char name[30];
    float memoryUsage;
} Process;

int main(){
     Process* processes = NULL;
     int Oldcount = 0;

     printf("How many processes? ");
     scanf("%d", &Oldcount);

     processes = (Process*) malloc(count * sizeof(Process));

     if(processes == NULL){
         perror("Memory allocation failed\n");
         return 1;
     }

          for(int i = 0; i < count; i++) {
      printf("\nProcess %d\n", i + 1);

      printf("Enter PID: ");
      scanf("%d", &processes[i].pid);

      printf("Enter Name: ");
      scanf("%s", processes[i].name);

      printf("Enter Memory Usage: ");
      scanf("%f", &processes[i].memoryUsage);
  }
     int count = Oldcount + newCount;
     int newCount = 0;
        printf("\nHow many processes to add? ");
        scanf("%d", &newCount);
     
     Process* temp = (Process*) realloc(processes, count * sizeof(Process));
        if(temp == NULL){
            perror("Memory reallocation failed\n");
            free(processes);
            return 1;
        }else{
            processes = temp;
            temp = NULL;

            for(int i = 0; i < count; i++) {
                printf("\nProcess %d\n", i + 1);

                printf("Enter PID: ");
                scanf("%d", &processes[i].pid);

                printf("Enter Name: ");
                scanf("%s", processes[i].name);

                printf("Enter Memory Usage: ");
                scanf("%f", &processes[i].memoryUsage);
            }

        }

      printf("\n--- PROCESS LIST ---\n");

     for(int i = 0; i < (count); i++) {
           printf("PID: %d | Name: %s | Memory: %.2f MB\n",
           processes[i].pid,
           processes[i].name,
           processes[i].memoryUsage);
     }
     
     free(processes);
     return 0;

}

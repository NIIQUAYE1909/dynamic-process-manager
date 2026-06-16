#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int pid;
    char name[30];
    float memoryUsage;
} Process;

void AddProcess(Process** processes, int* Oldcount);

void ViewProcesses(Process* processes, int count);

void DeleteProcess(Process** processes, int* Oldcount);

void SearchProcess(Process* processes, int count);

void SaveProcesses(Process* processes, int count);

void LoadProcesses(Process** processes, int* Oldcount);

void UpdateProcess(Process* processses, int count);

int main(){
    Process* processes = NULL;
    int Oldcount = 0;
    bool Exit = true;

    while(Exit){
        printf("Welcome to the Dynamic Process Manager\n");
        printf("1. Add Process\n");
        printf("2. View Processes\n");
        printf("3. Delete Process\n");
        printf("4. Search Process\n");
        printf("5. Save Processes\n");
        printf("6. Load Processes\n");
        printf("7. Update Process\n");
        printf("8. Exit\n");
        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Add Process logic
                    AddProcess(&processes, &Oldcount);
                break;
            case 2:
                // View Processes logic
                ViewProcesses(processes, Oldcount);
                break;
            case 3:
                // Delete Process logic
                DeleteProcess(&processes, &Oldcount);   
                break;
            case 4:
                // Search Process logic
                SearchProcess(processes, Oldcount);
                break;
            case 5:
                // Save Processes logic
                SaveProcesses(processes, Oldcount);
                break;
            case 6:
                // Load Processes logic
                LoadProcesses(&processes, &Oldcount);
                break;
            case 7:
                // Update Process logic
                UpdateProcess(processes, Oldcount);
                break;
            case 8:
                Exit = false;
                free(processes);
                printf("Thanks for using the Dynamic Process Manager!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    
     return 0;

}

// FUNCTIONS 

void AddProcess(Process** processes, int* Oldcount){
    // Logic to add a process

    if(*Oldcount == 0){
        printf("How many processes? ");
        scanf("%d", Oldcount);

        *processes = (Process*) malloc((*Oldcount) * sizeof(Process));

        if(*processes == NULL){
            perror("Memory allocation failed\n");
            return;
        }
        for(int i = 0; i < (*Oldcount); i++) {
            printf("\nProcess %d\n", i + 1);

            printf("Enter PID: ");
            scanf("%d", &(*processes)[i].pid);

            printf("Enter Name: ");
            scanf("%s", (*processes)[i].name);

            printf("Enter Memory Usage: ");
            scanf("%f", &(*processes)[i].memoryUsage);
        }

    
    }else{
        int newCount = 0;
        printf("\nHow many processes to add? ");
        scanf("%d", &newCount);

        int count = (*Oldcount) + newCount;
     
     Process* temp = (Process*) realloc(*processes, count * sizeof(Process));
        if(temp == NULL){
            perror("Memory reallocation failed\n");
            free(*processes);
            return;
        }else{
            *processes = temp;
            temp = NULL;

            for(int i = (*Oldcount); i < count; i++) {
                printf("\nProcess %d\n", i + 1);

                printf("Enter PID: ");
                scanf("%d", &(*processes)[i].pid);

                printf("Enter Name: ");
                scanf("%s", (*processes)[i].name);

                printf("Enter Memory Usage: ");
                scanf("%f", &(*processes)[i].memoryUsage);
            }

            *Oldcount = count;
        }
    }
}

void ViewProcesses(Process* processes, int count){
    // Logic to view processes
    if(count == 0){
        printf("No processes to display.\n");
        return;
    }
    printf("\nCurrent Processes:\n");
    for(int i = 0; i < count; i++){
        printf("Process %d\n", i + 1);
        printf("PID: %d\n", processes[i].pid);
        printf("Name: %s\n", processes[i].name);
        printf("Memory Usage: %.2f MB\n", processes[i].memoryUsage);
        printf("-------------------------\n");
    }
}
void DeleteProcess(Process** processes, int* Oldcount){
    // Logic to delete a process
    if(*Oldcount == 0){
        printf("No processes to delete.\n");
        return;
    }
    int pidToDelete;
    printf("Enter the PID of the process to delete: ");
    scanf("%d", &pidToDelete);
    int indexToDelete = -1;
    for(int i = 0; i < (*Oldcount); i++){
        if((*processes)[i].pid == pidToDelete){
            indexToDelete = i;
            break;
        }
    }
    if(indexToDelete == -1){
        printf("Process with PID %d not found.\n", pidToDelete);
        return;
    }
    for(int i = indexToDelete; i < (*Oldcount) - 1; i++){
        (*processes)[i] = (*processes)[i + 1];
    }
    (*Oldcount)--;

    Process* temp = (Process*) realloc(*processes, (*Oldcount) * sizeof(Process));
    if(temp == NULL && (*Oldcount) > 0){
        perror("Memory reallocation failed\n");
        return;
    }else{
        *processes = temp;
        temp = NULL;    
    }
     printf("Process with PID %d deleted successfully.\n", pidToDelete);

}

void SearchProcess(Process* processes, int count){
    // Logic to search for a process
    if(count == 0){
        printf("No processes to search.\n");
        return;
    }
    int pidToSearch;
    printf("Enter the PID of the process to search: ");
    scanf("%d", &pidToSearch);
    for(int i = 0; i < count; i++){
        if(processes[i].pid == pidToSearch){
            printf("Process found:\n");
            printf("PID: %d\n", processes[i].pid);
            printf("Name: %s\n", processes[i].name);
            printf("Memory Usage: %.2f MB\n", processes[i].memoryUsage);
            return;
        }
    }
    printf("Process with PID %d not found.\n", pidToSearch);
}



void SaveProcesses(Process* processes, int count){
    // Logic to save processes to a file
    if(count == 0){
        printf("No processes to save.\n");
        return;
    }
    FILE* file = fopen("processes.txt", "w");
    if(file == NULL){
        perror("Could not open file for writing\n");
        return;
    }
    for(int i = 0; i < count; i++){
        fprintf(file, "PID: %d\n", processes[i].pid);
        fprintf(file, "Name: %s\n", processes[i].name);
        fprintf(file, "Memory Usage: %.2f MB\n", processes[i].memoryUsage);
        fprintf(file, "-------------------------\n");
    }
    fclose(file);
    printf("Processes saved to processes.txt\n");
}


void LoadProcesses(Process** processes, int* Oldcount){
    // Logic to load processes from a file
    FILE* file = fopen("processes.txt", "r");
    if(file == NULL){
        perror("Could not open file for reading\n");
        return;
    }
    char line[1024];
    int count = 0;
    while(fgets(line, sizeof(line), file) != NULL){
        if(strncmp(line, "PID:", 4) == 0){
            count++;
        }
    }
    rewind(file);
    *processes = (Process*) malloc(count * sizeof(Process));
    if(*processes == NULL){
        perror("Memory allocation failed\n");
        fclose(file);
        return;
    }
    int index = 0;
    while(fgets(line, sizeof(line), file) != NULL){
        if(strncmp(line, "PID:", 4) == 0){
            sscanf(line, "PID: %d", &(*processes)[index].pid);
            fgets(line, sizeof(line), file);
            sscanf(line, "Name: %s", (*processes)[index].name);
            fgets(line, sizeof(line), file);
            sscanf(line, "Memory Usage: %f MB", &(*processes)[index].memoryUsage);
            index++;
        }
    }
    fclose(file);
    *Oldcount = count;
    printf("Processes loaded from processes.txt\n");
}


void UpdateProcess(Process* processses, int count){
    // Logic to update a process
    if(count == 0){
        printf("No processes to update.\n");
        return;
    }
    int pidToUpdate;
    printf("Enter the PID of the process to update: ");
    scanf("%d", &pidToUpdate);
    for(int i = 0; i < count; i++){
        if(processses[i].pid == pidToUpdate){
            printf("Process found. Enter new details:\n");

            printf("Enter Name: ");
            scanf("%s", processses[i].name);

            printf("Enter Memory Usage: ");
            scanf("%f", &processses[i].memoryUsage);

            printf("Process with PID %d updated successfully.\n", pidToUpdate);
            return;
        }
    }
    printf("Process with PID %d not found.\n", pidToUpdate);
    
    
}
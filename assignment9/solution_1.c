// Student Records
#include <stdio.h>

int insert();
int search();
int display();
int delete();
int modify();

int main(void){
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1)
        insert();
    else if (choice == 2)
        search();
    else if (choice == 3)
        display();
    else if (choice == 4)
        delete();
    else if (choice == 5)
        modify();
    
    return 0;
}
int insert(void){
    int id;
   char name[20], course[20];
    
    FILE *fp;
    fp = fopen("studentRecords.csv", "a");
    
    scanf("%d %s %s", &id, name, course);
    
    fprintf(fp, "%d %s %s\n", id, name, course);
    fclose(fp);
    
    scanf("%d", &id);
   
   if (id == 2)
        search();
    else if (id == 3)
        display();
    else if (id == 4)
        delete();
    else if (id == 5)
        modify();
    else 
        return 0;
   
}

int search(void){
   int id, check = 0;
    char name[20], course[20];
    
    
   FILE *fp;
   fp = fopen("studentRecords.csv", "r");

   scanf("%d", &id);
   
    
   while(fscanf(fp, "%d %s %s\n", &id, name, course) != EOF) {
       if(id == id) {
           check = 1;
           break;
       }
   }
    
   if(check == 1)
       printf("\n%d %s %s\n", id, name, course);
   else
       printf("\nRecord does not exist");
    
   fclose(fp);
   
   scanf("%d", &id);
   
   if (id == 1)
        insert();
    else if (id == 3)
        display();
    else if (id == 4)
        delete();
    else if (id == 5)
        modify();
    else 
        return 0;
}

int display(void) {
   int id;
   char name[20], course[20];
    
   FILE *fp;
   fp = fopen("studentRecords.csv", "r");
   printf("\nAll records\n");
    
    while(fscanf(fp, "%d %s %s\n", &id, name, course) != EOF){
        printf("\n%d%s%s\n", id, name, course);
    }
    fclose(fp);
    scanf("%d", &id);
    
    if (id == 1)
        insert();
    else if (id == 2)
        search();
    else if (id == 4)
        delete();
    else if (id == 5)
        modify();
    else 
        return 0;

}

int delete(void) {
   int id;
   char name[20], course[20];
    
   FILE *fp, *ft;

   fp = fopen("studentRecords.csv", "r");
   ft = fopen("temp.txt", "w");

   scanf("%d", &id);
    
   while(fscanf(fp, "%d%s%s\n", &id, name, course) != EOF) {
       if(id == id)
           continue;
       else
           fprintf(ft, "%d%s%s\n", id, name, course);
   }

   fclose(fp);
   fclose(ft);
   
   remove("studentRecords.csv");
   rename("temp.txt", "studentRecords.csv");
   
   scanf("%d", &id);
   
   if (id == 1)
        insert();
    else if (id == 2)
        search();
    else if (id == 3)
        display();
    else if (id == 5)
        modify();
    else 
        return 0;

}

int modify(void) {
    
    int id;
   char name[20], course[20];
    
   FILE *fp;

   fp = fopen("studentRecords.csv", "r");
   
   while(fscanf(fp, "%d%s%s\n", &id, name, course) != EOF){
       if(id == id){
           scanf("%s", course);
           course[0] = *course;
       }
   }
    
    scanf("%d", &id);
   
   if (id == 1)
        insert();
    else if (id == 2)
        search();
    else if (id == 3)
        display();
    else if (id == 5)
        modify();
    else 
        return 0;
        
}

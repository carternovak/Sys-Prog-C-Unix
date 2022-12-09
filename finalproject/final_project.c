#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MEMORY 5 
#define MAX_word_LENGTH 12 // Needed to change from 11 to 12 for term "Data Mining" to work properly 

struct DoublyLinkedList { 
    char* word; 
    struct DoublyLinkedList* next; 
    struct DoublyLinkedList* prev; 
};

typedef struct{
    char* word;
    int freq;
} FreqList;

struct DoublyLinkedList* head; // points towards the head of the queue i.e leftmost 
struct DoublyLinkedList* tail; // points towards the tail of the queue i.e rightmost 

int counter = 1;

void addwordToMemoryModeOne(char * inputword);
void addwordToMemoryModeTwo(char * inputword);
void printMemoryQueue(struct DoublyLinkedList* test);
bool searchwordInMemoryQueue(char * targetword);
void deleteWord(struct DoublyLinkedList** head_ref, struct DoublyLinkedList* del);
void deleteAllOccurOfX(struct DoublyLinkedList** head_ref, char * targetword);
void assignTail(struct DoublyLinkedList** head_ref);
int findWord(FreqList * list, char * word);

int main(void) {
    //counter = 0;
    int numberOfwords;
    int mode;
    int temp;
    int x = 0, wordCnt = 0;
    printf("Mode: ");
    scanf("%d", &mode);
    printf("Number of words: ");
    scanf("%d", &numberOfwords);

    head = tail = NULL;
    char words[numberOfwords][MAX_word_LENGTH];
    if(mode == 1) {
        //printf("Made it to Mode 1!\n");
        for(int i = 0; i < numberOfwords; i++) {
            printf("Enter word %d: ", i + 1);
            scanf("%c", &temp);
            scanf("%[^\n]", words[i]);
            addwordToMemoryModeOne(words[i]);
            printMemoryQueue(head);
            printf("\n");
        }
    }else if(mode == 2) {
        FreqList mode2[numberOfwords];
        //mode2[3].word = NULL;
        //printf("Made it to Mode 2!\n");
        for(int i = 0; i < numberOfwords; i++) {
            mode2[i].word = NULL;
            x = 0;
            printf("Enter word %d: ", i + 1);
            scanf("%c", &temp);
            scanf("%[^\n]", words[i]);
            if(i == 0) {
                mode2[i].word = words[i];
                mode2[i].freq = 1;
                wordCnt++;
            } else {
                if(findWord(mode2, words[i]) > 0) {
                    while(mode2[x].word != NULL) {
                        if(strcmp(words[i], mode2[x].word) == 0){
                            mode2[x].freq += 1;
                            //printf("%d", mode2[0].freq);
                            break;
                        } else
                            x++;
                    }
                } else {
                    mode2[wordCnt].word = words[i];
                    mode2[wordCnt].freq = 1;
                    wordCnt++;
                }
            }
            addwordToMemoryModeTwo(words[i]);
            printMemoryQueue(head);
            printf("\n");
        }
        for(int i = 0; i < wordCnt; i++)
            printf("Word: %s Freq: %d\n", mode2[i].word, mode2[i].freq);
            
    }
    //printMemoryQueue(head);
    
    //searchwordInMemoryQueue("one");
    //assignTail(&head);
    //printf("What the tail should be: %s\n", tail->word);
    
}

void addwordToMemoryModeOne(char * inputword/*, FreqList * list*/) { 
    struct DoublyLinkedList* newWord = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if(counter == 1) {
        newWord->word = inputword;
        newWord->next = NULL;
        (tail) = newWord;
        tail->next = NULL;
        tail->prev = newWord;
        newWord->prev = NULL;
    
        (head) = newWord;
    }else if(searchwordInMemoryQueue(inputword)) {
        if(head->word != inputword) {    
            newWord->word = inputword;
            newWord->next = (head);
            newWord->prev = NULL;

            if((head) != NULL) {
                (head)->prev = newWord;
            }
        
            (head) = newWord;
            deleteAllOccurOfX(&head, inputword);
            
            counter -= 1;
            assignTail(&head);
        }
    } else if(!searchwordInMemoryQueue(inputword) && counter <= 5) {
        newWord->word = inputword;
        // Could not figure out how to traverse through both freq list and doubly linked list to
        // determine where the next word should be added
        /*
        struct DoublyLinkedList* current = head;
        for(int i = 0; i < ; i++)
            if(list[i]->freq == 2)
                continue;
            else if(list[i]->freq == 1)
                while(current->word != NULL){
                    if(strcmp(current->word, list[i]->word) == 0)
                        
                    current = current->next;
                }
                */
        newWord->next = (head);
        newWord->prev = NULL;

        if((head) != NULL) {
            (head)->prev = newWord;
        }
        
        (head) = newWord;
    } else if(counter > 5){
        if(head != tail) {  
            tail = tail->prev;  
            tail->next = NULL;  
        }  
        else {  
            head = tail = NULL;  
        }   
             
        newWord->word = inputword;
        newWord->next = (head);
        newWord->prev = NULL;
    
        if((head) != NULL)
            (head)->prev = newWord;
        (head) = newWord;
            
    }
    
    counter++;
} 

void addwordToMemoryModeTwo(char * inputword) {
    struct DoublyLinkedList* newWord = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if(counter == 1) {
        newWord->word = inputword;
        newWord->next = NULL;
        (tail) = newWord;
        tail->next = NULL;
        tail->prev = newWord;
        newWord->prev = NULL;
    
        (head) = newWord;
    }else if(searchwordInMemoryQueue(inputword)) {
        if(head->word != inputword) {    
            newWord->word = inputword;
            newWord->next = (head);
            newWord->prev = NULL;

            if((head) != NULL) {
                (head)->prev = newWord;
            }
        
            (head) = newWord;
            deleteAllOccurOfX(&head, inputword);
            
            counter -= 1;
            assignTail(&head);
        }
    } else if(!searchwordInMemoryQueue(inputword) && counter <= 5) {
        newWord->word = inputword;
        newWord->next = (head);
        newWord->prev = NULL;

        if((head) != NULL) {
            (head)->prev = newWord;
        }
        
        (head) = newWord;
        
        
    } else if(counter > 5){
        if(head != tail) {  
            tail = tail->prev;  
            tail->next = NULL;  
        }  
        else {  
            head = tail = NULL;  
        }   
             
        newWord->word = inputword;
        newWord->next = (head);
        newWord->prev = NULL;
    
        if((head) != NULL)
            (head)->prev = newWord;
        (head) = newWord;
            
    }
    
    counter++;
}

void printMemoryQueue(struct DoublyLinkedList* test) { 
    
    struct DoublyLinkedList* last;
    while (test != NULL) {
        printf(" %s ", test->word);
        last = test;
        test = test->next;
    }
    //free(last);
} 


bool searchwordInMemoryQueue(char * targetword) { 
    struct DoublyLinkedList* current = head;
    while (current != NULL) {
        if (strcmp(current->word, targetword) == 0){
            //printf("true");
            return true;
        }
        current = current->next;
    }
    return false;
    free(current);
}

void deleteWord(struct DoublyLinkedList** head_ref, struct DoublyLinkedList* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
 
    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);

}

void deleteAllOccurOfX(struct DoublyLinkedList** head_ref, char * targetword)
{
    struct DoublyLinkedList* current = *head_ref;
    struct DoublyLinkedList* next;
    current = current->next;
    while (current != NULL) {
        if (strcmp(current->word,targetword) == 0) {
            next = current->next;
            //printf("BWord: %s\n", current->word);
            /*tail->word = current->prev->word;
            tail->prev = current->prev->prev;
            tail->next = NULL;*/
            deleteWord(head_ref, current);
            current = next;
        } else {
            current = current->next;
            //printf("BWord: %s\n", current->word);
        }
    }
    free(current);
}
void assignTail(struct DoublyLinkedList** head_ref) {
    struct DoublyLinkedList* current = *head_ref;
    current = current->next;
    while (current != NULL) {
        if (current->next == NULL) {
            tail = current;
            tail->next = NULL;
            tail->prev = current->prev;
            return;
        } else {
            current = current->next;
        }
    }
    free(current);
}

int findWord(FreqList * list, char * word){
    int count = 0;
    int i = 0;
    //printf("SHOUDL BE NULL: %s", list[3].word);
    while(list[i].word != NULL){
        if(strcmp(word, list[i].word) == 0)
            count++;
        i++;
    }
    return count;
}


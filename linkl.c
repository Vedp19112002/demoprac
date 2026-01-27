#include<stdio.h>
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create_list();
void insert_at_position();
void delete_by_data();
void display();
void reverse_list();

int main(){
    int choice;
    printf("::::::OPERATIONS::::::\n\n");

    while(1){
    
    printf("1.Create linked list\n");
    printf("2.Insert at Position\n");
    printf("3.Delete choosen data\n");
    printf("4.Reverse Linked List\n");
    printf("5.Display\n");
    printf("9.Exit\n");
    switch(choice){
        case 1: create_list();
        break;
        case 2: insert_at_position();
        break;
        case 3: delete_by_data();
        break;
        case 4: reverse_list();
        break;
        case 5: display();
        break;
        case 9: printf("Exiting...");
        exit(0);
        default: printf("Invalid Choice, Try Again!!!);
     }
        }

   return 0;
}

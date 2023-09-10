#include<iostream>
#include<fstream>
struct node {
      int data;
      struct node* link;
   };
void print(struct node*head){
     if (head==NULL){
        std::cout<<("%d","list is empty");
        }
        else{
        struct node*ptr=(struct node*)malloc (sizeof(struct node));
        ptr = head;
        while (ptr!=NULL){ 
              std::cout<<("%d",ptr->data);
              std::cout<<("\t");
              ptr=ptr->link;
             
       }
        std::cout<<("\n");
        }
   }
void  del_pos(struct node  **head,int position ){
          struct node*current=(struct node*)malloc (sizeof(struct node));
          struct node*previous=(struct node*)malloc (sizeof(struct node));
          current=*head;
          previous=*head;
         if (*head==NULL){
            std::cout<<("list is empty");
            
          }
          else if (position==1){
                  *head=current ->link;
                  free(current);
                  current=NULL;
          }
          else{
           while (position!=1){
                     previous=current;
                     current=current ->link;
                     position--;
           }
           previous ->link=current ->link;
           free(current);
           current=NULL;
          }
 
 
 }    
 void add(struct node*head,int data){
      struct node*ptr=(struct node*)malloc (sizeof(struct node));
      ptr=head;
     struct node*temp=(struct node*)malloc (sizeof(struct node));
     temp->data=data;
     temp ->link=NULL;
      while (ptr->link!=NULL){
         ptr=ptr->link;
      }
      ptr->link=temp;
  }

struct node*third_last_element(struct node *head){
   if (head == NULL || head->link == NULL || head->link->link == NULL) {
        return NULL; // Not enough elements in the list
    }
    struct node*prev=(struct node*)malloc (sizeof(struct node));
    struct node*current=(struct node*)malloc (sizeof(struct node));
    struct node*link=(struct node*)malloc (sizeof(struct node));
    prev = NULL;
    current = head;
    link = head->link->link;
    
    while (link != NULL) {
        prev = current;
        current = current->link;
        link = link->link;
    }
    
    return prev;
}
int findPosition(struct node* head, int target) {
    int position = 1;
     struct node*current=(struct node*)malloc (sizeof(struct node));
     current = head;
    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        
        current = current->link;
        position++;
    }
    
    return -1;
}
int main()
{
  
   struct node*head=NULL;
   head =(struct node*)malloc(sizeof (struct node));
   head->data=34;
   head ->link = NULL;
   std::ifstream file("Test01.5.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    int data;
    while (file >> data) {
        add(head, data);
    }
   print(head);
   struct node*ThirdLast=(struct node*)malloc (sizeof(struct node));
    ThirdLast = third_last_element(head);
   if (ThirdLast!= NULL) {
        std::cout<<"Third last element:";
        std::cout<<ThirdLast->data;
        std::cout<<std::endl;
    } else {
        std::cout<<("Not enough elements in the linked list.");
    }
   int target;
   target=ThirdLast->data;
    int position = findPosition(head,target);
    if (position != -1) {
        std::cout<<("The position of third last element is :" );
        std::cout<< position;
        std::cout<<std::endl;

    } else {
        std::cout<<("Data not found in the linked list");
    }
    del_pos(&head,position);
    print(head);
   
   return 0;
}
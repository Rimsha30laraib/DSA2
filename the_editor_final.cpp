#include<iostream>
#include<fstream>
struct node {
      int data;
      struct node*next;
      struct node*prev;
   };
void print(struct node*head){
     if (head==NULL){
        std::cout<<"list is empty";
        }
        else{
        struct node*ptr=(struct node*)malloc (sizeof(struct node));
        ptr = head;
        while (ptr!=NULL){ 
              std::cout<<ptr->data;
              std::cout<<("\t");
              ptr=ptr->next;
       }
        }
        std::cout<<std::endl;
   }
struct node*add(struct node*head,int data){
      struct node*ptr=(struct node*)malloc (sizeof(struct node));
      ptr=head;
     struct node*temp=(struct node*)malloc (sizeof(struct node));
     temp->prev=NULL;
     temp->data=data;
     temp ->next=NULL;

      while (ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->next=temp;
      temp->prev=ptr;
      return head;
}
void  del_pos(struct node  **head,int position ){
          struct node*current=(struct node*)malloc (sizeof(struct node));
          struct node*previous=(struct node*)malloc (sizeof(struct node));
          current=*head;
          previous=*head;
         if (*head==NULL){
            std::cout<<"list is empty";
            
          }
          else if (position==1){
                  *head=current ->next;
                  free(current);
                  current=NULL;
          }
          else{
           while (position!=1){
                     previous=current;
                     current=current ->next;
                     position--;
           }
           previous ->next=current ->next;
           free(current);
           current=NULL;
          }
 }

void addAtIndex(node** head, int data, int index) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
    } 
    else if (index == 0) {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    } else {
        node* current = *head;
        int currentPosition = 0;
        while (currentPosition < index - 1 && current->next != NULL) {
            current = current->next;
            currentPosition++;
        }
        if (currentPosition < index - 1) {
            current->next = newnode;
            newnode->prev = current;
        } else {
            newnode->next = current->next;
            newnode->prev = current;
            current->next = newnode;
            if (newnode->next != NULL) {
                newnode->next->prev = newnode;
            }
        }
    }
  }       

 void movePointerForward(struct node** head, int steps) {
    if (*head == NULL) {
        return;
    }
    struct node* current = *head;
    for (int i = 0; i < steps; i++) {
        if (current->next != NULL) {
            current = current->next;
        } else {
            break;
        }
    }
    *head = current;
}

void movePointerBackward(struct node** head, int steps) {
    if (*head == NULL) {
        return;
    }
    struct node* current = *head;
    for (int i = 0; i < steps; i++) {
        if (current->prev != NULL) {
            current = current->prev;
        } else {
            break;
        }
    }
    *head = current;
}

void deleteAtIndex(struct node** head, int index) {
    if (*head == NULL) {
        return;
    }
    struct node* current = *head;
    for (int i = 0; current != NULL && i < index; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

void updateAtIndex(struct node* head, int index, int newdata) {
    if (head == NULL) {
        return;
    }
    struct node* current = head;
    for (int i = 0; current != NULL && i < index; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    current->data = newdata;
}
 
void shiftData(struct node** head, int currentIndex, int targetIndex) {
    if (*head == NULL) {
        return;
    }
    struct node* current = *head;
    struct node* target = *head;
    for (int i = 1; i <=currentIndex; i++) {
        if (current->next != NULL) {
            current = current->next;
        } else {
             std::cout<<"Current index is out of bounds";
            return; 
        }
    }
    for (int i = 1; i <=targetIndex; i++) {
        if (target->next != NULL) {
            target = target->next;
        } else {
             std::cout<<"Target index is out of bounds";
            return; 
        }
    }
    int temp = current->data;
    current->data = target->data;
    target->data = temp;
}

void DeleteIndex(struct node** head, struct node* pointer, int indexToDelete, int newData){
    struct node* nodeToDelete = *head;
    for (int i = 0; i < indexToDelete; i++) {
        if (nodeToDelete->next != NULL) {
            nodeToDelete = nodeToDelete->next;
        } else {
            return; 
        }
    }
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        *head = nodeToDelete->next;
    }
  
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    free(nodeToDelete);
}

int main()
{
    int position;
   struct node*head=NULL;
   head =(struct node*)malloc(sizeof (struct node));
   head->prev=NULL;
   head->data=34;
   head->next = NULL;
   std::ifstream file("Test01.4.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    int data;
    while (file >> data) {
        add(head, data);
    }
   print(head);
   addAtIndex(&head,15,1);
   print(head);
   movePointerForward(&head,2);
   print(head);
   updateAtIndex(head,0,5);
   print(head);
   deleteAtIndex(&head,2);
   print(head);
   movePointerBackward(&head,1);
   return 0;
}
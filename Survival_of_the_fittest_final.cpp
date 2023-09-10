#include<iostream>
#include<fstream>
struct Node {
      int id;
      struct Node* link;
   };
double findMedian(Node* head) {
    Node* slowPtr = head;
    Node* fastPtr = head;
    Node* prev = nullptr;

    while (fastPtr != nullptr && fastPtr->link != nullptr) {
        fastPtr = fastPtr->link->link;
        prev = slowPtr;
        slowPtr = slowPtr->link;
    }

    if (fastPtr != nullptr) {
        return slowPtr->id;
    } else {
        return (prev->id+ slowPtr->id) / 2;
    }
}
void swap(struct Node *a, struct Node* b) {
    int temp = a->id;
    a->id = b->id;
    b->id = temp;
}

void bubbleSort(struct Node *head) {
    int swapped;
    struct Node* current;
    struct Node* tail = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->link != tail) {
            if (current->id> current->link->id) {
                swap(current, current->link);
                swapped = 1;
            }
            current = current->link;
        }
        tail = current;
    } 
    while (swapped);
}
   void print(struct Node*head){
     if (head==NULL){
        std::cout<<"list is empty";
        }
        else{
        struct Node*ptr=(struct Node*)malloc (sizeof(struct Node));
        ptr = head;
        while (ptr!=NULL){ 
              std::cout<<ptr->id;
              std::cout<<"\t";
              ptr=ptr->link;
             
       }
        std::cout<<std::endl;
        }
   }
void add(struct Node*head,int id){
      struct Node*ptr=(struct Node*)malloc (sizeof(struct Node));
      ptr=head;
     struct Node*temp=(struct Node*)malloc (sizeof(struct Node));
     temp->id=id;
     temp ->link=NULL;
      while (ptr->link!=NULL){
         ptr=ptr->link;
      }
      ptr->link=temp;
  }


int main(){
   struct Node*head=NULL;
   head =(struct Node*)malloc(sizeof (struct Node));
   head->id=34;
   head ->link = NULL;
   std::ifstream file("Test01.2.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    int data;
    while (file >> data) {
        add(head, data);
        print(head);
        bubbleSort(head);
        print(head);
        std::cout<<"The median of the linked list is: ";
        std::cout<<findMedian(head);
        std::cout<<std::endl;
    }
    return 0;
}
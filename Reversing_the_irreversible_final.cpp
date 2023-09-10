#include<iostream>
#include<fstream>
struct customer {
     int transaction_id;
      int transaction_amount;
      int flag;
      struct customer* link;
   };
void print(struct customer*head){
     if (head==NULL){
        std::cout<<"list is empty";
        }
        else{
        struct customer*ptr=(struct customer*)malloc (sizeof(struct customer));
        ptr = head;
        while (ptr!=NULL){ 
              std::cout<<ptr->transaction_id;
              std::cout<<("\t");
              std::cout<<ptr->transaction_amount;
              ptr=ptr->link;
              std::cout<<std::endl;   
       }
        }
         
   }
void add(struct customer*head,int transaction_id,int transaction_amount){
      struct customer*ptr=(struct customer*)malloc (sizeof(struct customer));
      ptr=head;
     struct customer*temp=(struct customer*)malloc (sizeof(struct customer));
     temp->transaction_id=transaction_id;
     temp->transaction_amount=transaction_amount;
     temp ->link=NULL;
      while (ptr->link!=NULL){
         ptr=ptr->link;
      }
      ptr->link=temp;
}

void deleteValue(struct customer** head, int value) {
    struct customer* temp = *head;
    struct customer* prev = NULL;
    if (temp != NULL && temp->transaction_id == value) {
        *head = temp->link;
        free(temp);
        return;
    }
    while (temp != NULL && temp->transaction_id != value) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        return;
    }
    prev->link = temp->link;
    free(temp);
}

 int main()
 {
   struct customer*head=NULL;
  head =(struct customer*)malloc(sizeof (struct customer));
   head->transaction_id=54;
   head->transaction_amount=9865;
   head->link = NULL;
   std::ifstream file("Test01.3.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    int  data1,data2;
    while (file >> data1&& file>>data2) {
        add(head,data1,data2);
       
    } 
  print(head);
  deleteValue(&head,1002);
  deleteValue(&head,1005);
  deleteValue(&head,1008);
  std::cout<<"list after deleting data" <<std::endl;
  print (head);

  file.close();
   return 0;
}

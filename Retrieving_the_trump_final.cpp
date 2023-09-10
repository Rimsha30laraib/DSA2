#include<iostream>
#include<fstream>
struct node {
      int number;
      struct node* link;
   };
void add(struct node*head,int number){
      struct node*ptr=(struct node*)malloc (sizeof(struct node));
      ptr=head;
     struct node*temp=(struct node*)malloc (sizeof(struct node));
     temp->number=number;
     temp ->link=NULL;
      while (ptr->link!=NULL){
         ptr=ptr->link;
      }
      ptr->link=temp;
  }

  void del_pos(struct node **head,int position ){
          struct node*current=(struct node*)malloc (sizeof(struct node));
          struct node*previous=(struct node*)malloc (sizeof(struct node));
          current=*head;
          previous=*head;
         if (*head==NULL){
            std::cout<<"list is empty";
            
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
 void print(struct node*head){
     if (head==NULL){
        std::cout<<"list is empty";
        }
        else{
        struct node*ptr=(struct node*)malloc (sizeof(struct node));
        ptr = head;
        while (ptr!=NULL){ 
              std::cout<<ptr->number;
              ptr=ptr->link;
              std::cout<<"\n";
       }
        }
   }
   int find_length(struct node*head){
      int length=0;
      struct node*current=(struct node*)malloc (sizeof(struct node));
      current=head;
      while (current!=NULL){
            length++;
            current=current->link;
      }
      return length;

 }  
double findMedian(node* head) {
    struct node*slowPtr=(struct node*)malloc (sizeof(struct node));
    struct node*fastPtr=(struct node*)malloc (sizeof(struct node));
    struct node*prev=(struct node*)malloc (sizeof(struct node));
    slowPtr = head;
    fastPtr = head;
    prev = nullptr;

    while (fastPtr != nullptr && fastPtr->link != nullptr) {
        fastPtr = fastPtr->link->link;
        prev = slowPtr;
        slowPtr = slowPtr->link;
    }

    if (fastPtr != nullptr) {
        return slowPtr->number;
    } else {
        return (prev->number + slowPtr->number) ;
    }
}
void findMidvalue(struct node*head){
   if (head==NULL){
      std::cout<<"link is empty";
      return;
   }
   int length=0;
   struct node*current=head;
   while (current!=NULL){
      length++;
      current=current->link;
   }
   int midIndex=length/2;
   current=head;
   for(int i=1;i<midIndex;i++){
      current=current->link;
   }
   std::cout<<"mid two values are ",current->number,current->link->number;

}
void GetTrump(struct node*head,int length_of_list){
      if (length_of_list%2==0){
         findMidvalue(head);
      }
      else{
        std::cout<<"The median of the linked list is: ";
        std::cout<<findMedian(head);
        std::cout<<std::endl;
      }
   }
   void End(){
      std::cout<<"the program was end";
      

      return ;
   }
 int main()
{
   struct node*head=NULL;
   head =(struct node*)malloc(sizeof (struct node));
   head->number=34;
   head ->link = NULL;
   std::ifstream file("Test01.1.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    int data;
    while (file >> data) {
        add(head, data);
    }
   print(head);
   int length_of_list;
   length_of_list=find_length(head);
   GetTrump(head,length_of_list);
   End();
   return 0;
   
}  
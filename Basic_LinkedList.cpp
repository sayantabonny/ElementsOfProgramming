#include <iostream>


struct Node{
    int data;
    struct Node *next;
};

struct Node* head = nullptr;
struct Node* tail = nullptr;

void create(int B[],int n)
{
    struct Node* ptr=nullptr;
   
    for(int i=0;i<n;i++)
    { 
        struct Node *temp=new Node();  //won't work temp = {0,nullptr} because address are assigned at compile time hence same address.
      //  std::cout<<B[i]<<std::endl;;
      // std::cout<<&temp<<std::endl;;
        temp->data=B[i] ;                           //  temp.data=B[i];
        if(i==0)
        {
            head=temp;
            head->next=nullptr;
            ptr=head;
        }
        if(i==n-1)
        {
            tail=temp;
            tail->next=nullptr;
        }
        if(i!=0)
        {
            ptr->next=temp;
            ptr=temp;
        }
        
        
    }
}

void display_forward(struct Node *ptr)
{
    if(ptr!=nullptr)
    {
        std::cout<<ptr->data<<" ";
        display_forward(ptr->next);
    }
    
    return;
}

void display_backward(struct Node *ptr)
{
        if(ptr!=nullptr)
    {
        
        display_backward(ptr->next);
        std::cout<<ptr->data<<" ";
    }
    return;
}



int Max_element(struct Node *ptr, int max)
{
    if(ptr==nullptr)
    {
        return max;
    }
    else
    {
        max=(ptr->data)>max?(ptr->data):max;
        Max_element(ptr->next,max);
    }
}

int Max_element_NoParameter(struct Node *ptr)
{
    if(ptr==nullptr)
    {
        return 0;
    }
    else
    {
       int max=Max_element_NoParameter(ptr->next);
       return (ptr->data)>max?ptr->data:max;
    }
}

void insert(struct Node *ptr,int BB, int pos)
{
    struct Node *temp=new Node();
    temp->data=BB;
    if(pos==0)
    {
        temp->next=head;
        head=temp;
    }
    else{
        int c=1;
        while(ptr != nullptr)
        {
            std::cout<<" position "<<c<<" data "<<ptr->data<<std::endl;
            if(c+1==pos)
            {
                if(ptr->next==nullptr)
                {
                    tail=temp;
                }
                temp->next=ptr->next;
                ptr->next=temp;
                break;
            }
            ptr=ptr->next;
            c++;
        }
        //std::cout<<"Inside "<<c<<" "<<pos<<std::endl;
        if(c+1<pos)
        {
            tail->next=temp;
            temp->next=nullptr;
            tail=temp;
            
        }
    }
}


int main()
{
    //int *A= new int[10];
    int A[]={1,2,3,4,5,6,7,8,10,20,3,1,2,3,4,5,99,10,11,12,3,13};
    create(A,22);
    std::cout<<"Head:"<<head->data<<std::endl;
    std::cout<<"Tail:"<<tail->data<<std::endl;
    std::cout<<std::endl<<std::endl<<"Foward Traversal"<<std::endl;
    //display_forward(head);
    std::cout<<std::endl<<std::endl<<"Reverse Traversal"<<std::endl;
    //display_backward(head);

    std::cout<<std::endl<<std::endl<<"Maximum Element"<<std::endl;
    //std::cout<<Max_element(head,0);
    //std::cout<<Max_element_NoParameter(head);
     std::cout<<std::endl<<std::endl<<"Inserting Element"<<std::endl;
     insert(head,500,0);
     insert(head,69,10000);
     insert(head,4,24);
     insert(head,78,23);
     std::cout<<"Head:"<<head->data<<std::endl;
     std::cout<<"Tail:"<<tail->data<<std::endl;
     insert(head,50,3);
     insert(head,26,26);
     insert(head,29,29);
     display_forward(head);
     std::cout<<std::endl;
     //display_backward(head);
}

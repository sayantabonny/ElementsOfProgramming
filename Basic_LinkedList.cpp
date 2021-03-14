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
        std::cout<<ptr->data<<std::endl;
        display_forward(ptr->next);
    }
    return;
}

void display_backward(struct Node *ptr)
{
        if(ptr!=nullptr)
    {
        
        display_backward(ptr->next);
        std::cout<<ptr->data<<std::endl;
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
    std::cout<<Max_element_NoParameter(head);
}

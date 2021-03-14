#include <iostream>
class LinkedList
{
    public:
    int value;
    LinkedList *next=nullptr;
    LinkedList *head, *tail;
    LinkedList(int value)
    {
        this-> value=value;

    }
    void add_node(int n)
    {
        LinkedList *tmp = new LinkedList(n);
        tmp->next = nullptr;

        if(head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }    
};

LinkedList * removeDuplicateFormLinkedList (LinkedList *linkedList)
    {
        LinkedList *currentNode=linkedList;
        while(currentNode != nullptr)
        {
            LinkedList *nextDistinctNode = currentNode->next;
            while(nextDistinctNode != nullptr && nextDistinctNode->value==currentNode->value)
             {
                 nextDistinctNode=nextDistinctNode->next;
            }
            currentNode->next = nextDistinctNode;
            currentNode=nextDistinctNode;
        }
        return linkedList;
    }


int main()
{
    LinkedList a= new LinkedList(10);
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(5);
    a.add_node(2);
    a.add_node(1);
    while(a != nullptr)
    {
        std::cout<<"Before depuplication";
        std::cout<<a.value<<std::endl;
        a=a->next;

    }
    LinkedList a_new= removeDuplicateFormLinkedList(a->head);
    while(a_new != nullptr)
    {
        std::cout<<"After depuplication";
        std::cout<<a_new.value<<std::endl;
        a_new=a_new->next;
       
    }
    return 0;
}
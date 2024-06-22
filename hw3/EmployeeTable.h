#ifndef EMPLOYEETABLE_H
#define EMPLOYEETABLE_H

#include "Employee.h"
#include<vector>
#include<list>
struct node{
    Employee data;
    node* next;
};
class linkedlist
  {
    private:
    node *head, *tail;
    public:
    linkedlist()
    {
      head=NULL;
      tail=NULL;
    }

   linkedlist& operator=(const linkedlist &rhs) {

  if (this != &rhs) {
    removeAllNodes();
    node* r = rhs.head;
    while (r) {
       createnode(r->data);
       r = r->next;
    }
  }
  return *this;

}
node* find(string ssn){
    node *current = head;
    node *tmp;
    if(head == NULL){
        return NULL;
    }
    else if((current->data).getSsn() == ssn){
        return current;
    }
    else{
        while(current->next != NULL){
            tmp = current->next;
            if((tmp->data).getSsn() == ssn){
                return tmp;
                break;
            }
            else{
                current = current->next;
            }
        }
        return NULL;
    }
    
}
int len(){
    int i;
    if(head == NULL){
        return 0;
    }
    else{
    node *current = head;
        i = 0;
    while(current!=NULL){
      current = current->next;
        i++;
    }
    }
    return i;
}
int removeNode(node* a){
node *current = head;
node *tmp;
int i = 0;
if(head==NULL){
    return 0;
}
else if((head->data).compare(a->data)){
    if(head->next==NULL){
    head = NULL;
    tail = NULL;
    }
    delete current;
}
else{
    tmp = head->next;
    while(tmp){
        if((tmp->data).compare(a->data)){
            if(tmp->next == NULL){
                current->next = NULL;
                delete tmp;
                i++;
            }
            else{
                current->next = tmp->next;
                delete tmp;
                i++;
            }
        }
        else{
            tmp = tmp->next;
            current = current->next;
        }
    }
    return i;
    
}
}
    void removeAllNodes(){

	    node *current = head;

	    node *temp;

	    while(current!= NULL)

	    {

	         temp = current;

	         current = current->next;

	         delete temp;

	    }
	    
	    head = NULL;
	    tail = NULL;

    }
    void createnode(Employee value)
    {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
    }

  };	


class EmployeeTable {

private:
// TODO:
// ... members, methods
linkedlist** lists;
int bsize;

public:
// Constructors & Destructor, be careful about memory leaks.
    EmployeeTable(); // Default table size is 151 buckets.
    EmployeeTable(int numberOfBuckets); // numberOfBuckets is a prime number.
    EmployeeTable(const EmployeeTable& empTable);
    ~EmployeeTable();
    EmployeeTable& operator=(const EmployeeTable& rhs);

// Hash an employee to a non-negative integer ( return hash value, not
// bucket number). Use hashValue(mod numberOfBuckets) as bucket number.
// Return -1 on invalid parameters.
    int hashEmployee(string ssn);

// Put an employee to the hash table.
// Do nothing on invalid parameters.
    void addEntry(Employee& employee);

// Remove the entry from the hash table.
// Do nothing on invalid parameters.
    void removeEntry(Employee& employee);

// Get the total number of employees in the given bucket. 
// Return -1 on invalid bucket number.
    int getNumberOfEmployeeInBucket(int bucket);

// Find employee of the given ssn.
// Important: To add an extra flavor to your homework, your code
// will be evaluated by how much time it takes to access an employee
// on the average. You will get a small portion of your grade
// depending on the average access time of your code.
// For invalid cases, throw ItemNotFoundException.
    Employee findEmployee(string ssn);
};


#endif // EMPLOYEETABLE_H

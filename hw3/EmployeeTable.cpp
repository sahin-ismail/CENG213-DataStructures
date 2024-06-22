#include "EmployeeTable.h"
#include "ItemNotFoundException.h"

EmployeeTable::EmployeeTable() {
// TODO:
lists = new linkedlist*[151];
bsize = 151;
int i = 0;
while(i<bsize){
    lists[i] = NULL;
    i++;
}

}

EmployeeTable::EmployeeTable(int numberOfBuckets) {
// TODO:
lists = new linkedlist*[numberOfBuckets];
bsize = numberOfBuckets;
int i = 0;
while(i<bsize){
    lists[i] = NULL;
    i++;
}
}

EmployeeTable::EmployeeTable(const EmployeeTable& empTable) {
// TODO:
lists=new linkedlist*[empTable.bsize];
int i = 0;
bsize = empTable.bsize;
while(i<bsize){
    lists[i] = NULL;
    i++;
}
i = 0;
while(i<bsize){
    if(empTable.lists[i]!=NULL){
        lists[i] = new linkedlist(); 
        (*lists[i])=(*empTable.lists[i]);
    }
        i++;
}

}
EmployeeTable::~EmployeeTable(){
int i = 0;
while(i<bsize){
    if(lists[i]!=NULL){
        lists[i]->removeAllNodes();
    }
    delete lists[i];
    i++;
}
delete[] lists;
}
EmployeeTable& EmployeeTable:: operator=(const EmployeeTable& rhs) {
// TODO:
int i = 0;
while(i<bsize){
    if(lists[i]!=NULL){
        lists[i]->removeAllNodes();
    }
    delete lists[i];
    i++;
}
delete[] lists;
lists=new linkedlist*[rhs.bsize];
i = 0;
bsize = rhs.bsize;
while(i<bsize){
    lists[i] = NULL;
    i++;
}
i = 0;
while(i<bsize){
    if(rhs.lists[i]!=NULL){
        lists[i] = new linkedlist(); 
        (*lists[i])=(*rhs.lists[i]);
    }
        i++;
}
return *this;
}

int EmployeeTable::hashEmployee(string ssn) {
// TODO:
    if(ssn == ""){
        return -1;
    }
    long result = 0;
    int i = 0;
    while(i<ssn.size()){
        result = ssn[i] - 48 + result * 10;
        i++;
    }
    while(result < 0) result += bsize;
    return result;
}

void EmployeeTable::addEntry(Employee& employee) {
// TODO:
if((employee.getName() == "")||(employee.getExperience()==-1)||(employee.getCity()=="")||(employee.getSsn()=="")){
    return;
}
else{
int index = hashEmployee(employee.getSsn())%bsize;
if(index<0){index += bsize;}
if(lists[index]==NULL){
    lists[index] = new linkedlist;
    lists[index]->createnode(employee);
}
else{
    lists[index]->createnode(employee);

}
}
}

void EmployeeTable::removeEntry(Employee& employee) {
// TODO:
    if((employee.getName() == "")||(employee.getExperience()==-1)||(employee.getCity()=="")||(employee.getSsn()=="")){
        return;
    }
    else{
    int index = hashEmployee(employee.getSsn())%bsize;
    if(index<0){index += bsize;}
    node *a = new node;
    a->data = employee;
    a->next = NULL;
    if(lists[index]!=NULL){
        
        int b = lists[index]->removeNode(a);
        if(b == 0){
            throw ItemNotFoundException();
        }
        
    }
    delete a;
    
    }
}

int EmployeeTable::getNumberOfEmployeeInBucket(int bucket) {
// TODO:

if((bucket<1)||(bucket>bsize)){
    return -1;
}
else{
    if(lists[bucket]==NULL){
        return 0;
    }
    else{
        int a = lists[bucket]->len();
        return a;
    }
}
}

Employee EmployeeTable::findEmployee(string ssn) {
// TODO:
if(ssn == ""){
    throw ItemNotFoundException();
}
else{
    int index = hashEmployee(ssn)%bsize;
    if(index<0){index += bsize;}
    if(lists[index] == NULL){
        throw ItemNotFoundException();
    }
    else if(lists[index]->find(ssn) == NULL){
        throw ItemNotFoundException();
    }
    else{
        return (lists[index]->find(ssn))->data;
    }
}

}


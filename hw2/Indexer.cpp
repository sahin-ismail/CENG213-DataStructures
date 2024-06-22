#include <iostream>

#include "Indexer.h"

// Constructor
Indexer::Indexer(){}

// Destructor
Indexer::~Indexer(){}

// Copy constructor
Indexer::Indexer(const Indexer & _Indexer){
    // TODO
    // Write your code here
    this->Index = _Indexer.Index;
    
}

// = operator overloading
Indexer& Indexer::operator=(const Indexer& _Indexer){
    // TODO
    // Write your code here
	if (this != &_Indexer)
    {
		this->Index = _Indexer.Index;
	}
    
    
    return *this;
}

// adds a term entry with page pair p in the Index
// If there is no IndexNodeData with the first letter of term in Index,
// creates it and add to Index.
// If there is no TermTreeNodeData with the first letter of term in
// IndexNodeData whose letter is the first letter of term,
// creates it and add to that IndexNodeData.
// If TermTreeNodeData with the given term exists,
// adds page interval given in p to that TermTreeNodeData.
void Indexer::addTerm(string term, Pair p){
    // TODO
    // Write your code here
    IndexNodeData a(term[0]);
    if(Index.contains(a)){
        TermTreeNodeData t(term);
        if(Index.getVal(a).getTree().contains(t)){
            Index.getVal(a).getTree().getVal(t).addPage(p);
        }
        else{
            TermTreeNodeData g(term,p);
            Index.getVal(a).getTree().add(g);
        }
    }
    else{
        TermTreeNodeData g(term,p);
        Index.add(a);
        Index.getVal(a).getTree().add(g);
    }
}

// removes term from Index
// removes IndexNodeData of that term if there is no term index left in the IndexNodeData
void Indexer::removeTerm(string term){
    // TODO
    // Write your code here
    IndexNodeData a(term[0]);
    if(Index.contains(a)){
        TermTreeNodeData t(term);
        if(Index.getVal(a).getTree().contains(t)){
            Index.getVal(a).getTree().remove(t);
            if(Index.getVal(a).getTree().height()==-1){
                Index.remove(a);
            }
        }
    }
    
}

// removes IndexNodeData whose letter member is equal to given letter argument
void Indexer::removeLetter(char letter){
    // TODO
    // Write your code here
    IndexNodeData a(letter);
    if(Index.contains(a)){
        Index.remove(a);
    }
    
}

// converts Index to a balanced binary search tree
// applies only for IndexNodeData elements, term elements under
// IndexNodeData elements (tree member in IndexNodeData is not balanced)
void Indexer::makeIndexBalanced(){
    // TODO
    // Write your code here
    Index.makeItBalanced();
    
}

// converts IndexNodeData with the given letter argument to a balanced binary search tree
void Indexer::makeLetterBalanced(char letter){
    // TODO
    // Write your code here
    IndexNodeData a(letter);
    if(Index.contains(a)){
        Index.getVal(a).getTree().makeItBalanced();
    }
    
}

// tests if Index is balanced
bool Indexer::isIndexBalanced(){
    return Index.isBalanced();
}

// tests if IndexNodeData with the given letter argument is balanced
bool Indexer::isLetterBalanced(char letter){
    IndexNodeData li(letter);
    return Index.getVal(li).getTree().isBalanced();
}

// prints preorder traversal of letters in Index
void Indexer::printIndex(){
    Index.print();
}

// prints preorder traversal of terms starting with the given letter argument in Index
void Indexer::printLetter(char letter){
    IndexNodeData li(letter);
    Index.getVal(li).getTree().print();
}

// prints Index letters in tree form
void Indexer::printIndexSideways(){
    Index.printSideways();
}

// prints terms starting with the given letter argument in tree form
void Indexer::printLetterSideways(char letter){
    IndexNodeData li(letter);
    Index.getVal(li).getTree().printSideways();
}

// prints whole Index data
void Indexer::printAllIndex(){
    Index.printVal();
}





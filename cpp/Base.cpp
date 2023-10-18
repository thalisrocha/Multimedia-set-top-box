#include "Base.h"

Base::Base(){}

Base::Base(string name, string path){
    this -> name = name;
    this -> path = path;
} 

string Base::getPath() const{
    return this-> path; 
}  
    
void Base::setPath(string path){
    this-> path = path;
} 

string Base::getName() const{
    return this-> name; 
}  
    
void Base::setName(string name){
    this-> name = name;
} 

void Base::viewVariables(ostream & s){
    s<< this->getPath() << "" << this->getName() << endl;
}

Base::~Base(){
    std::cout << "Deleting" << std::endl;
}

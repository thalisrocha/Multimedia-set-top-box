/**
 * @file Group.h
 * @author Thalis Rocha Pestana
 * @brief Defines the Group class, which represents a group of 
 * Base objects implemented as a list of shared_ptr<Base> pointers.
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef GROUP_H
#define GROUP_H

#include "Base.h"
#include <memory>
#include <list>

using namespace std;
using Ptr = shared_ptr<Base>;

/**
 * @brief Represents a group of Base objects, implemented as a list of 
 * shared_ptr<Base> pointers.
 * 
 */
class Group: public list<Ptr>{

private:
    string groupName;

public:
    /**
     * @brief Default constructor
     * 
     * Construct a new Group object 
     * 
     */
    Group(){} 
    
    /**
     * @brief Construct a new Group object(Parameterized).
     * 
     * @param groupName The name of the group.
     * 
     */
    Group(string groupName):
    list<Ptr>(){
        this->groupName = groupName;
    }

    /**
     * @brief Returns the name of the group.
     * 
     * @return string The name of the group. 
     */
    string getGroupName(){
        return this->groupName;
    }

    /**
     * @brief Displays the variables of the Group and all its members.
     * 
     * @param s The output stream to write to.
     */
    void viewVariables(ostream & s){
        s<< "Group name:" << this->getGroupName() << ";";
        s<< "{" << ";";
        for(auto it = this->begin(); it!= this->end(); ++it){
            (*it)->viewVariables(s);
        }
        s<< "}" << ";";
    }
};

#endif
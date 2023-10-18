/**
 * @file Base.h
 * @author Thalis Rocha Pestana
 * @brief Definition of the Base class, an abstract class for multimedia 
 * objects.
 * 
 * @details This file defines the Base class, which serves as an abstract 
 * base class for different types of multimedia objects. It contains common
 * attributes and methods that are shared by all subclasses.
 * 
 * @note This class is not intended to be instantiated directly, as it is 
 * an abstract class.
 * 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef BASE_H
#define BASE_H
#include <string>
#include <iostream>
#include <list>
using namespace std;

/**
 * @brief Abstract base class for multimedia objects
 * 
 * The Base class defines common attributes and methods that are 
 * shared by all subclasses. It contains attributes for the name and
 * path of the multimedia object, as well as methods for accessing and 
 * modifying those attributes. It also defines a virtual method for 
 * playing the multimedia object and an abstract method for displaying the
 * variables of the object, which is implemented by subclasses.
 * 
 */
class Base{
private:
    string name{};    
    string path{};
public:

    /**
    * @brief Default constructor
    * 
    * Creates a new Base object with empty name and path.
    */
    Base();                         

    /**
     * @brief Construct a new Base object (Parameterized)
     * 
     * Creates a new Base object with the given name and path.
     * 
     * @param path path The path to the multimedia object
     * @param name name The name of the multimedia object
     */
    Base(string path, string name); 
    
    /**
    * @brief Destructor
    * 
    * Destroys the Base object and releases any resources used by it.
    */
    virtual ~Base();

    /**
    * @brief Accessor for the path variable
    * 
    * Returns the path to the multimedia object.
    * 
    * @return The path to the multimedia object
    */
    string getPath() const; 

    /**
    * @brief Accessor for the name variable
    * 
    * Returns the name of the multimedia object.
    * 
    * @return The name of the multimedia object
    */
    string getName() const;

    /**
     * @brief Modifier for the path variable
     * 
     * Sets the path to the multimedia object to the given value.
     * 
     * @param path 
     */
    void setPath(string path); 

    /**
     * @brief Modifier for the name variable
     * 
     * Sets the name of the multimedia object to the given value.
     * 
     * @param name name The new name of the multimedia object
     */
    void setName(string name);

    /**
    * @brief Method to view the object's variables
    * 
    * Prints the name and path of the multimedia object to the given output stream.
    * 
    * @param s The output stream to print the variables to
    */
    virtual void viewVariables(ostream & s);

    /**
    * @brief Abstract method to play the multimedia
    * 
    * This method must be implemented by any derived class, and should play the multimedia object
    * using the appropriate player for the type of multimedia.
    */
    virtual void playMedia() = 0;

};

#endif // BASE_H

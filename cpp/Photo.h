/**
 * @file Photo.h
 * @author Thalis Rocha Pestana
 * @brief This file contains the definition of the Photo class, which 
 * inherits from Base and represents a photo media file with a name, path, 
 * and location coordinates.
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PHOTO_H
#define PHOTO_H

#include "Base.h"

using namespace std;

/**
 * @brief The Photo class represents a photo media file with a name, path, 
 * and location coordinates.
 * 
 */
class Photo : public Base {
private:
    float longitude{};    
    float latitude{};
public:
    /**
     * @brief Default constructor for the Photo class
     * 
     */
    Photo(){} 
    
    /**
     * @brief Constructor for Photo class (Parameterized).
     * 
     * @param name The name of the photo (same name of the document).
     * @param path The path to the photo file.
     * @param longitude longitude The longitude of the location where the 
     * photo was taken.
     * @param latitude latitude The latitude of the location where the photo
     * was taken.
     */
    Photo(string name, string path, float longitude, float latitude):
    Base(name, path){
        this->longitude = longitude;
        this->latitude = latitude;
    }
    
    /**
     * @brief Getter for the latitude of the location where the photo was 
     * taken.
     * 
     * @return float The latitude of the location where the photo was taken.
     */
    float getLatitude() const{
        return this->latitude; 
    }  
    
    /**
     * @brief Getter for the longitude of the location where the photo was 
     * taken.
     * 
     * @return float The longitude of the location where the photo was taken.
     */
    float getLongitude() const{
        return this->longitude; 
    }  
    
    /**
     * @brief Setter for the latitude of the location where the photo was 
     * taken.
     * 
     * @param latitude The new value for the latitude of the location where
     * the photo was taken.
     */
    void setLatitude(float latitude){
        this->latitude = latitude;
    } 
    
    /**
     * @brief Setter for the longitude of the location where the photo was 
     * taken.
     * 
     * @param longitude longitude The new value for the longitude of the 
     * location where the photo was taken.
     */
    void setLongitude(float longitude){
        this->longitude = longitude;
    } 

    /**
     * @brief Prints the photo's information to the provided output stream.
     * 
     * @param s The output stream to print to.
     */
    void viewVariables(ostream & s){
        s<< "Photo:";
        s<< this->getPath() << "" << this->getName();
        s<< "Latitude:" << this->getLatitude() << " "
        << "Longitude:" << this->getLongitude() << ";";
    }

    /**
     * @brief Opens the photo file using the default image viewer.
     * 
     */
    void playMedia(){
        string str = "imagej " + getPath() + getName() + " " + "&";
        const char* ptr = str.data(); 
        system(ptr);
    }

};

#endif
/**
 * @file Film.h
 * @author Thalis Rocha Pestana
 * @brief Definition of the Film class, which is a derived class of the 
 * Video class. It adds the capability of managing chapters to the video 
 * functionality.
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FILM_H
#define FILM_H

#include "Video.h"

using namespace std;

/**
 * @brief This class is defined in the Film.h header file and inherits from
 * the Video class.
 * 
 * It adds two data members to the Video class, which are the number of 
 * chapters and an array of integers that represent the duration of each 
 * chapter. It also defines a setDurations function to set the values of the
 * chapters array. It overrides the viewVariables and playMedia functions 
 * from the Base and Video classes.
 * 
 */
class Film : public Video {
private:
    int nChapters{};
    int *chapters{};    
    
public:
    /**
     * @brief Construct a new Film object
     * 
     */
    Film(){} 
    
    /**
     * @brief Constructor for Video class (Parameterized).
     * 
     * @param name The name of the film.
     * @param path The path to the film file.
     * @param duration The duration of the film in seconds.
     * @param nChapters The number of chapters in the film.
     * @param chapters An array of integers representing the duration of 
     * each chapter in the film.
     */
    Film(string name, string path, float duration, 
    int nChapters, int *chapters):
    Video(name, path, duration){
        this->nChapters = nChapters; 
        this->chapters = new int(nChapters);
        for(int i = 0; i<nChapters; i++){
            this->chapters[i] = chapters[i];
        }      
    }

    /**
     * @brief Assignment operator for Film class.
     * 
     * @param from The Film object to assign from.
     */
    Film(const Film& from);
    Film& operator=(const Film& from);
    
    /**
     * @brief Set the durations of each chapter in the film.
     * 
     * @param nChapters The number of chapters in the film.
     * @param chapters An array of integers representing the duration of 
     * each chapter in the film.
     */
    void setDurations(int nChapters, int *chapters){
        //this->chapters = chapters;
        if (nChapters > 0 && chapters!=nullptr){
            if(this->nChapters!=nChapters){
                delete this->chapters;
                this->nChapters = nChapters;
                this->chapters = new int(nChapters);
            }
        } 
        else{
            this->chapters = nullptr;
        }
        for(int i=0; i<nChapters; i++){
            this->chapters[i] = chapters[i];
        }
    } 

    /**
     * @brief Get the number of chapters in the film.
     * 
     * @return const int The number of chapters in the film.
     */
    const int getNumberChap() const{
        return this->nChapters; 
    }  
    
    /**
     * @brief Get the array of integers representing the duration of each 
     * chapter in the film.
     * 
     * @return const int* The array of integers representing the duration 
     * of each chapter in the film.
     */
    const int * getChapters() const{
        return this->chapters; 
    }  
    
    /**
     * @brief Outputs the film's information to the specified output stream.
     * 
     * @param s The output stream to write the film's information to.
     */
    void viewVariables(ostream & s){
        s << "Film:";
        s << "Number of chapters:" << this->getNumberChap();
        for(int i=0; i<nChapters; i++){
            s<< "chapter[" << i << "]:" << this->chapters[i];
        }   
        s << ";";
    }

    /**
     * @brief Plays the film using the mpv player.
     * 
     */
    void playMedia(){
        string str = "mpv " + getPath() + getName() + " " + "&";
        const char* ptr = str.data(); 
        system(ptr);
    }

    /**
     * @brief Destroy the Film object.
     * 
     */
    virtual ~Film(){delete this->chapters;}

};

#endif
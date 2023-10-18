/**
 * @file Video.h
 * @author Thalis Rocha Pestana
 * @brief Contains the declaration of the Video class, which inherits from
 * the Base class and represents a video object.
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "Base.h"

using namespace std;

/**
 * @brief Represents a video object and inherits from the Base class.
 * 
 */
class Video : public Base {
private:
    float duration{};    

public:
    /**
     * @brief Default constructor for Video class.
     * 
     */
    Video(){}
    
    /**
     * @brief Constructor for Video class (Parameterized).
     * 
     * @param name The name of the video.
     * @param path The path to the video file.
     * @param duration The duration of the video.
     */
    Video(string name, string path, float duration):
    Base(name, path){
        this->duration = duration;
    }
    
    /**
     * @brief Get the Duration object
     * 
     * @return The duration of the video.
     */
    float getDuration() const{
        return this->duration; 
    }    
    
    /**
     * @brief Sets the duration of the video
     * 
     * @param duration The duration of the video.
     */
    void setDuration(int duration){
        this->duration = duration;
    } 

    /**
     * @brief Outputs the video variables.
     * 
     * @param s The stream to output.
     */
    void viewVariables(ostream & s){
        s<< "Video:";
        s<< "Duration:" << this->getDuration() << ";";
    }
    
    /**
     * @brief Plays the video using the mpv media player.
     * 
     */
    void playMedia(){
        string str = "mpv " + getPath() + getName() + " " + "&";
        const char* ptr = str.data(); 
        system(ptr);
    }

};

#endif
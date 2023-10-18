/**
 * @file Administrator.h
 * @author Thalis Rocha Pestana
 * @brief This file contains the Administrator class which is 
 * responsible for managing and creating multimedia and groups.
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <map>
#include <memory>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Base.h"

using namespace std;
using Ptr_base  = shared_ptr<Base>;
using Ptr_group = shared_ptr<Group>;

using Multimedia_map = map<string, Ptr_base>;
using Group_map = map<string, Ptr_group>;

/**
 * @brief The Administrator class is responsible for managing and creating 
 * multimedia and groups.
 * 
 */
class Administrator{

private:
    Multimedia_map multimedia_table;
    Group_map group_table;

public:
    /**
     * @brief Creates a new Photo object and adds it to multimedia_table.
     * 
     * @param name The name of the photo.
     * @param path The path to the photo.
     * @param longitude The longitude of the photo.
     * @param latitude The latitude of the photo.
     * @return Ptr_base A shared pointer to the new photo.
     */
    Ptr_base createPhoto(string name, string path, float longitude,
    float latitude){ 

        Ptr_base photo = Ptr_base(new Photo(name, path, longitude,
        latitude));

        multimedia_table[name] = photo;
        return photo;
    }

    /**
     * @brief Creates a Video object and adds it to multimedia_table.
     * 
     * @param name The name of the video.
     * @param path The path to the video.
     * @param duration The duration of the video.
     * @return Ptr_base A shared pointer to the new video.
     */
    Ptr_base createVideo(string name, string path, float duration){ 

        Ptr_base video = Ptr_base(new Video(name, path, duration));
        
        multimedia_table[name] = video;
        return video;
    }

    /**
     * @brief Creates a new Film object and adds it to multimedia_table.
     * 
     * @param name The name of the film.
     * @param path The path to the film.
     * @param duration The duration of the film.
     * @param nChapters The number of chapters in the film.
     * @param chapters An array containing the chapter lengths.
     * @return Ptr_base A shared pointer to the new film.
     */
    Ptr_base createFilm(string name, string path, float duration, 
    int nChapters, int *chapters){ 

        Ptr_base film = Ptr_base(new Film(name, path, duration,
            nChapters, chapters));
        
        multimedia_table[name] = film;
        return film;
    }

    /**
     * @brief Creates a new Group object and adds it to group_table.
     * 
     * @param groupName The name of the group.
     * @return Ptr_group A shared pointer to the new group.
     */
    Ptr_group createGroup(string groupName){

        Ptr_group group = Ptr_group(new Group(groupName));

        group_table[groupName] = group;
        return group;
    }

    /**
     * @brief Searches for a multimedia or group object with the given name
     * and displays its variables.
     * 
     * @param objName The name of the object to search for.
     */
    void searchMultimedia(string objName){
        auto it1 = multimedia_table.find(objName);
        auto it2 = group_table.find(objName);

        if(it1 == multimedia_table.end() && it2 == group_table.end()){
            cout << "No Groups or Multimedia found!" << endl;
        }else if(it1 == multimedia_table.end()){
            it2->second->viewVariables(cout);
        }else{
            it1->second->viewVariables(cout);
        }
    }

    /**
     * @brief Plays the multimedia object with the given name.
     * 
     * @param objName The name of the multimedia object to play.
     * @param s The output stream to write to.
     * @return int 1 if no object was found, 2 if the object was a group, 
     * and 3 if the object was multimedia.
     */
    int playMultimedia(string objName, ostream & s){
        auto it1 = multimedia_table.find(objName);
        auto it2 = group_table.find(objName);

        if(it1 == multimedia_table.end() && it2 == group_table.end()){
            cout << "No Groups or Multimedia found!" << endl;
            return 1;
        }else if(it1 == multimedia_table.end()){
            it2->second->viewVariables(s);
            return 2;
        }else{
            it1->second->playMedia();
            return 3;
        }
    }

    /**
     * @brief Displays the variables of a multimedia object or a group with
     * the given name.
     * 
     * @param objName The name of the multimedia object or group to display.
     * @param s The output stream to write to.
     * @return bool true if no multimedia object or group with the given 
     * name is found, false otherwise.
     */
    bool showVariables(string objName, ostream & s){
        auto it1 = multimedia_table.find(objName);
        auto it2 = group_table.find(objName);

        if(it1 == multimedia_table.end() && it2 == group_table.end()){
            cout << "No Groups or Multimedia found!" << endl;
            return true;
        }else if(it1 == multimedia_table.end()){
            it2->second->viewVariables(s);
            return false;
        }else{
            it1->second->viewVariables(s);
            return false;
        }
    }

}; 

#endif
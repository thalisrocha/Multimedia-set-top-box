/**
 * @file main.cpp
 * @author Thalis Rocha Pestana 
 * @brief This file contains the main function of the program which creates 
 * multimedia objects, adds them to groups, and runs a TCP server to receive 
 * requests and send responses to clients.
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
*/

//#define VERSION_1

#include "Base.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Administrator.h"
#include "tcpserver.h"

#include <string>       
#include <iostream>     
#include <sstream>   
#include <algorithm>
#include <memory>

using namespace std;
using Ptr = shared_ptr<Base>;

const int PORT = 3331;

/**
 * @brief The main function of the program.
 * 
 * @param argc The number of command-line arguments provided to the program.
 * @param argv An array of C-style strings containing the command-line arguments 
 * provided to the program.
 * @return int An integer indicating whether the program ran successfully (0) or 
 * encountered an error (non-zero). 
*/
int main(int argc, const char* argv[])
{
	#ifdef VERSION_1
    	int size = 3;
    	// Base ** medias = new Base*[size];
    	int* chapters = new int[size];
    	Administrator* adm = new Administrator;

    	for(int i=0; i<size; i++){
        	chapters[i] = i;
    	}

    	Ptr_group group = adm->createGroup("GroupTest1");
    	Ptr_base photo = adm->createPhoto("fla.jpg", 
		"/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 278, 92);
    	Ptr_base video = adm->createVideo("liberta.mp4", 
		"/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 25);
    	Ptr_base film = adm->createFilm("vizinhos.mp4", 
		"/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 25, size, chapters);

    	group->push_back(photo);
    	group->push_back(video);
    	group->push_back(film);

    	// adm->searchMultimedia("groupTest3");
    	adm->showVariables("GroupTest1", cout);
		adm->playMultimedia("fla.jpg", cout);

    	group->pop_back();
    	group->pop_back();
    	group->pop_back();

    	Ptr_group group2 = adm->createGroup("groupTest4");
    	group2->push_back(film);
    
	#else
		Administrator * db = new Administrator();
		Ptr_group group1 = db->createGroup("Group1"); 
		Ptr_group group2 = db->createGroup("Group2"); 

		int size = 3;
		int * chapters = new int[size];

		for(int i=0; i<size; i++){
        	chapters[i] = i;
    	}

    	Ptr_base photo1 = db->createPhoto("fla.jpg", 
		"/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 278, 92);
		Ptr_base photo2 = db->createPhoto("ronaldin.jpg",
		 "/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 278, 92);
    	Ptr_base video = db->createVideo("liberta.mp4", 
		"/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 25);
    	Ptr_base film = db->createFilm("vizinhos.mp4", 
		"/cal/exterieurs/rocha-22/Rocha_Pestana__Thalis/cpp/", 25, size, chapters);

		group1->push_back(photo1);
		group1->push_back(photo2);
		group2->push_back(video);
		group2->push_back(film);

		//std::cin >> request; 

		auto* server =
  		new TCPServer( [&](string const& request, string& response) {
		
			stringstream req (request);
			stringstream res;

			string entry;
			string object;

			req >> entry;
        	req >> object;

			if (entry == "show"){
				bool out = db->showVariables(object, res);
				if(out == true){
					res << "No Groups or Multimedia found!";
				}
			}else if(entry == "play"){
				int out = db->playMultimedia(object, res);
				if(out == 1){
					res << "No Groups or Multimedia found!";
				}else if(out == 2){
					res << "Group found!";
				}else if(out == 3){
					res << "Multimedia found!";
				}
			}else{
				res << "Invalid request!" << entry;
			}
			
    		// the request sent by the client to the server
    		std::cout << "request: " << request << endl;

    		// the response that the server sends back to the client
    		response = "RECEIVED: " + res.str();

    		// return false would close the connecytion with the client
    		return true;
  		});


  		//lance la boucle infinie du serveur
  		std::cout << "Starting Server on port " << PORT << endl;

  		int status = server->run(PORT);

  		// en cas d'erreur
  		if (status < 0) {
    		cerr << "Could not start Server on port " << PORT << endl;
    	return 1;
  		}

		delete chapters;
		delete db;

	#endif

    return 0;
}

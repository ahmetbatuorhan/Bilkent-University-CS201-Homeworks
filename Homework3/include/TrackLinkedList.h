#ifndef TRACKLINKEDLIST_H
#define TRACKLINKEDLIST_H

#include <iostream>
#include "MusicianLinkedList.h"

using namespace std;

class TrackLinkedList
{
      public:
            // Constructors
            TrackLinkedList();
            TrackLinkedList(const TrackLinkedList& copyList);
            ~TrackLinkedList();

            // Methods
            void addTrack(string trackTitle, int releaseYear);
            void removeTrack(string trackTitle);
            void addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole);
            void removeMusician(string trackTitle, string musicianFirstName, string musicianLastName);
            void showAllTracks();
            void showTrack(string trackTitle);
            void showMusicianRoles(string musicianFirstName, string musicianLastName);

      protected:

      private:
            // Struct
            struct TrackNode
            {
                  string trackTitle;
                  int releaseYear;

                  MusicianLinkedList musicianLinkedList;

                  TrackNode* next;
                  TrackNode* prev;
            };
            // Variables
            int size;
            TrackNode* head;
            TrackNode* tail;
            // Methods
            bool isEmpty() const;
            bool checkTrack(string trackTitle);
            void findTrack(string trackTitle, TrackNode*& result);
            void removeFromHead();
            bool equals(const string& a, const string& b);
};

#endif // TRACKLINKEDLIST_H

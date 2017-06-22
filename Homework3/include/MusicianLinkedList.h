#ifndef MUSICIANLINKEDLIST_H
#define MUSICIANLINKEDLIST_H

#include <iostream>

using namespace std;

class MusicianLinkedList
{
      public:
            MusicianLinkedList();
            ~MusicianLinkedList();
            MusicianLinkedList(const MusicianLinkedList& copyList);

            void addLast(string musicianFirstName, string musicianLastName, string musicianRole );
            void removeMusician(string musicianFirstName, string musicianLastName);
            void showAll();
            void musicianRoles(string trackTitle, int releaseYear, string musicianFirstName, string musicianLastName, bool& check);

      protected:

      private:
            // Struct
            struct MusicianNode
            {
                  string musicianFirstName;
                  string musicianLastName;
                  string musicianRole;

                  MusicianNode* next;
                  MusicianNode* prev;
            };

            // Variables
            int size;
            MusicianNode* head;
            MusicianNode* tail;

            // Methods
            bool checkMusician(string musicianFirstName, string musicianLastName);
            bool isEmpty() const;
            void findMusician(string musicianFirstName, string musicianLastName, MusicianNode*& result);
            void removeFromHead();
            bool equals(const string& a, const string& b);

};

#endif // MUSICIANLINKEDLIST_H

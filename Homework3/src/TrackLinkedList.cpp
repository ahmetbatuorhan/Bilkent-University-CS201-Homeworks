#include "TrackLinkedList.h"
#include "MusicianLinkedList.h"
#include <iostream>

using namespace std;

// CONSTRUCTORS
// Constructor
TrackLinkedList::TrackLinkedList() : size(0), head(NULL), tail(NULL)
{

}
// Destructor
TrackLinkedList::~TrackLinkedList()
{
      while(!isEmpty())
      {
            removeFromHead();
      }

      head = NULL;
      tail = NULL;
}
// Copy Constructor
TrackLinkedList::TrackLinkedList(const TrackLinkedList& copyList)
{
      if(copyList.isEmpty())
      {
            size = 0;
            head = NULL;
            tail = NULL;
      }

      else if(copyList.head->next == NULL)
      {
            head = new TrackNode;
            head->next = NULL;
            head->prev = NULL;
            head->releaseYear = copyList.head->releaseYear;
            head->trackTitle = copyList.head->trackTitle;

            head->musicianLinkedList = copyList.head->musicianLinkedList;

            tail = head;
      }
      else
      {
            head = new TrackNode;
            head->next = NULL;
            head->prev = NULL;
            head->releaseYear = copyList.head->releaseYear;
            head->trackTitle = copyList.head->trackTitle;

            head->musicianLinkedList = copyList.head->musicianLinkedList;

            tail = head;

            TrackNode* origPtr = copyList.head->next;
            TrackNode* temp = tail;

            while(origPtr != NULL)
            {
                  temp->next = new TrackNode;
                  temp->next->next = NULL;
                  temp->next->prev = temp;
                  temp->next->releaseYear = origPtr->releaseYear;
                  temp->next->trackTitle = origPtr->trackTitle;
                  temp->next->musicianLinkedList = origPtr->musicianLinkedList;
                  temp = temp->next;
                  tail = temp;
                  origPtr = origPtr->next;
            }
      }
}

// METHODS
void TrackLinkedList::addTrack(string trackTitle, int releaseYear)
{
      if(isEmpty())
      {
            checkTrack(trackTitle);
            head = new TrackNode;
            head->trackTitle = trackTitle;
            head->releaseYear = releaseYear;
            head->next = NULL;
            head->prev = NULL;

            tail = head;

            size++;
      }
      else
      {
            if(checkTrack(trackTitle))
            {
                  cout << "There is a track title called \"" << trackTitle << "\". (Case Insensitive)"<< endl;
                  return;
            }

            tail->next = new TrackNode;
            (tail->next)->trackTitle = trackTitle;
            (tail->next)->releaseYear = releaseYear;
            (tail->next)->next = NULL;
            (tail->next)->prev = tail;

            tail = tail->next;

            size++;
      }
}

void TrackLinkedList::removeTrack(string trackTitle)
{
      if(!checkTrack(trackTitle))
      {
            cout << "There is no track with the specified title \"" << trackTitle << "\""<< endl;
      }
      else
      {
            TrackNode* temp = NULL;

            findTrack(trackTitle, temp);

            if(size == 1)
            {
                  removeFromHead();
                  head = NULL;
                  tail = NULL;
                  return;
            }
            if(temp->prev != NULL)
            {
                  (temp->prev)->next = temp->next;
            }
            else
            {
                  head = head->next;
                  head->prev = NULL;
            }

            if(temp->next != NULL)
            {
                  (temp->next)->prev = temp->prev;
            }
            else
            {
                  tail = tail->prev;
                  tail->next = NULL;
            }

            temp->next = NULL;
            temp->prev = NULL;

            delete temp;

            size--;
      }
}

void TrackLinkedList::addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole)
{
      if( !checkTrack(trackTitle))
      {
            cout << "There is no track with the specified title \"" << trackTitle << "\""<< endl;
            return;
      }

      TrackNode* temp = NULL;
      findTrack(trackTitle, temp);

      temp->musicianLinkedList.addLast(musicianFirstName, musicianLastName, musicianRole);
}

void TrackLinkedList::removeMusician(string trackTitle, string musicianFirstName, string musicianLastName)
{
      if( !checkTrack(trackTitle))
      {
            cout << "There is no track with the specified title \"" << trackTitle << "\""<< endl;
            return;
      }
      TrackNode* temp = NULL;
      findTrack(trackTitle, temp);

      temp->musicianLinkedList.removeMusician(musicianFirstName, musicianLastName);
}

void TrackLinkedList::showAllTracks()
{
      if(isEmpty())
      {
            cout << "------- NONE -------" << endl;
            return;
      }

      TrackNode* temp = head;
      while(temp != NULL)
      {
            cout << temp->trackTitle << ", " << temp->releaseYear << endl;
            temp = temp->next;
      }
}

void TrackLinkedList::showTrack(string trackTitle)
{
      if( !checkTrack(trackTitle))
      {
            cout << "There is no track with the specified title \"" << trackTitle << "\""<< endl;
            return;
      }

      TrackNode* temp = NULL;
      findTrack(trackTitle, temp);

     cout << temp->trackTitle << ", " << temp->releaseYear << endl;
      temp->musicianLinkedList.showAll();
}

void TrackLinkedList::showMusicianRoles(string musicianFirstName, string musicianLastName)
{
      bool check;
      TrackNode* temp = head;
      cout << musicianFirstName << " " << musicianLastName << endl;

      while( temp != NULL)
      {
            temp->musicianLinkedList.musicianRoles(temp->trackTitle, temp->releaseYear, musicianFirstName, musicianLastName, check);
            temp = temp->next;
      }

      if(!check)
      {
            cout << "------- NONE -------" << endl;
      }
}


// PRIVATE METHODS
// This method is from here : http://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c/4119881#4119881
bool TrackLinkedList::equals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

bool TrackLinkedList::isEmpty() const
{
      return size == 0;
}

bool TrackLinkedList::checkTrack(string trackTitle)
{
      TrackNode* temp = head;

      while( temp != NULL)
      {
            if( equals(temp->trackTitle, trackTitle))
            {
                  return true;
            }
            temp = temp->next;
      }
      return false;
}

void TrackLinkedList::findTrack(string trackTitle, TrackNode*& result)
{
      TrackNode* temp = head;

      while( temp != NULL)
      {
            if(equals(temp->trackTitle, trackTitle))
            {
                  result = temp;
                  return;
            }
            temp = temp->next;
      }
}

void TrackLinkedList::removeFromHead()
{
      TrackNode* temp = head;
      head = head->next;
      temp->next = NULL;
      temp->prev = NULL;
      delete temp;

      size--;
}













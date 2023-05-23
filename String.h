//
// Created by justi on 5/23/2023.
//

#ifndef STRING_H
#define STRING_H
#include <iostream>
namespace justin_su
{

    class String
    {
        public:
            String();
            String(const char* s);
            ~String();
            size_t length();
            void toUpper();
            void toLower();
            void reverse();
            void insertSubstr(int start, const char* s);
            int indexOf(const char* subString);
            void removeSubstring(int start, int numToRemove);
            void append(const char* newSubString);
            void replace(const char* stringToReplace, const char* newString);
            friend std::ostream& operator<<(std::ostream& stream,const String& s);
            void operator+(const char* newString);
            void operator=(const String& s);
            bool operator==(const String& s);
            bool operator<(const String& s);
            bool operator>(const String& s);
            char at(int index);
            char operator[](int index);
        private:
        char* str;
        size_t size;


    };

}

#endif

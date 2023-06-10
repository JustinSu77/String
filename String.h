//
// Created by justi on 5/23/2023.
//

/**
 * Constructor
 *       String();
         String(const char* s);
   Destructor
         ~String();
   Member Functions
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
         char& operator[](int index);
   Member Variable
         char* str;
         size_t size;
 */


#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace justin_su
{

    class String {
    public:
        /**
         * Default constructor.
         */
        String();

        /**
         * Sets string constructor.
         * @param s as letters to be string
         */
        String(const char *s);

        /**
          * Deallocate dynamic char array.
         */
        ~String();

        /**
         * Return the number of characters in string.
         * @return length of string as size_t
         */
        size_t length();

        /**
         * Turns all letters to uppercase.
         */
        void toUpper();

        /**
         * Turn all letters to lowercase.
         */
        void toLower();

        /**
         * Reverse order of characters backwards.
         */
        void reverse();

        /**
         * Insert given substring into given start position.
         * Precondition: String has some letters or is empty
         * Postcondition: Given substring is inserted at given start index
         *                Length of string is increased by length of given subString
         * @param start location to insert subString at
         * @param subString string to be inserted
         */
        void insertSubstr(int start, const char *subString);


        /**
         * Returns the index where the given subString starts.
         * @param subString as subString of this string class
         * @return index where given subString starts
         *         -1 if subString does not exist
         */
        int indexOf(const char *subString);

        /**
         * Remove given numToRemove characters from string starting at start index.
         * @param start index to start removing
         * @param numToRemove as number of characters to remove
         */
        void removeSubstring(int start, int numToRemove);

        /**
         * Append given subString to end of string.
         * @param newSubString
         */
        void append(const char *newSubString);

        /**
         * Replace existing subString with new given subString.
         * @param stringToReplace as subString to be replaced
         * @param newString
         */
        void replace(const char *stringToReplace, const char *newString);

        /**
         * Overloads the << operator to print string.
         * @param stream as ostream
         * @param s as string to be printed out
         * @return ostream
         */
        friend std::ostream &operator<<(std::ostream &stream, const String &s);

        /**
         * Overloads + for to append string to existing string.
         * @param newString as string to be appended
         */
        void operator+(const char *newString);

        /**
         * Sets existing string to new string.
         * @param s as new string
         */
        void operator=(const String &s);

        /**
         * Returns whether not this string instance is equal to a given string instance
         * @param s other instance of this class
         * @return true if all characters are equal
         *         false otherwise
         */
        bool operator==(const String &s);

        /**
         * Returns whether or not the characters of this instance are alphanumerically less than an
         * existing instance of this class
         * @param s another instance of this class
         * @return true if is less than
         *         false if is greater than
         */
        bool operator<(const String &s);


        /**
      * Returns whether or not the characters of this instance are alphanumerically greater than an
      * existing instance of this class
      * @param s another instance of this class
      * @return true if is greater than
      *         false if is less than
      */
        bool operator>(const String &s);

        /**
         * Return character at given index.
         * If index is < 0 or greater than length - 1 throw runtime exception
         * @param index as position to return
         * @return letter at given index
         */
        char at(int index);

        /**
         * Overload [] operator to return character at given index.
         * If index is < 0 or greater than length - 1 throw runtime exception
         * @param index as position to return
         * @return letter at given index
         */
        char &operator[](int index);

    private:
        // char pointer for char array
        char* str;
        // size_t is used commonly in standard library so I will use as well
        size_t size;


    };

}

#endif

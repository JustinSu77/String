//
// Created by justi on 5/23/2023.
//

#include "String.h"
#include "cstring"
#include <iostream>
namespace justin_su
{
    // Sets str pointer to nullptr
    // Set size to 0
    String::String(): str(nullptr), size(0)
    {

    }

    String::String(const char* s)
    {
        // Set size to length of given string
        size = strlen(s);
        // Allocate dynamic char array
        str = new char[size]{};

        // Copy characters from given string to str pointer
        for (int i = 0; i < size; i++)
        {
            str[i] = s[i];
        }

    }

    String::~String()
    {
        // Deallocate str dynamic char pointer
        delete[] str;
    }



    std::ostream& operator<<(std::ostream& stream, const String &s)
    {
        // Output the characters
        for (int i = 0; i < s.size; i++)
        {
            stream << s.str[i];
        }
        // Return ostream
        return stream;
    }

    size_t String::length()
    {
        return size;
    }

    void String::toUpper()
    {
        for (int i = 0; i < size; i++)
        {
            // Change character to its ascii code
            unsigned int ascii_code = (int)str[i];
            // If the character is lowercase
            if (ascii_code >= 97 && ascii_code <= 122)
            {
                // Make it uppercase
                ascii_code = ascii_code - 32;
                // Turn the new ascii code to a char value
                char newChar = (char)ascii_code;
                // Set the current position of string to the char value
                str[i] = newChar;
            }

        }
    }

    void String::toLower()
    {
        // Loop through characters
        for (int i = 0; i < size; i++)
        {
            // Change letter character to its ascii code
            unsigned int ascii_code = (int)str[i];
            // If  letter character is a lowercase
            if (ascii_code >= 65 && ascii_code <= 90)
            {
                // make it uppercase
                ascii_code = ascii_code + 32;
                // change it bach to a letter
                char newChar = (char)ascii_code;
                // assign it to the current position of the string
                str[i] = newChar;
            }

        }
    }

    void String::reverse()
    {
       // If there is only 1 letter or string is empty, return
        if (size == 0 || size == 1)
            return;
        // Two pointer method for reversing string
        size_t start = 0;
        size_t end = size - 1;
        // While pointers do not meet
        while (start < end)
        {
            // swap letters
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            // increment pointers
            start++;
            end--;
        }
    }

    void String::insertSubstr(int start, const char* subString)
    {
        // If given start index is out of bounds, throw exception
        if (start < 0 || start > size)
            throw std::runtime_error("Given start is out of bounds!");
        size_t subStrLength = strlen(subString);
        // if given substring is empty, return
        if (subStrLength == 0)
            return;
        // set new length of string
        size = size + subStrLength;
        // Aloccate larger dynamic char array
        char* newStr = new char[size]{};
        // If string is empty just copy the substring into string
        if (size == 0)
        {
            for (int i = 0; i < subStrLength; i++)
            {
                newStr[i] = str[i];
            }
            delete[] str;
            str = newStr;
            return;
        }

        // Insert substring at start index
        // runner pointer to given subString
        const char* runner = subString;

        // Used to assign characters to array
        int index = 0;
        // Loop through the string
        for (int i = 0; i < size; i++)
        {
            // If the current position is between the start index and the end index subString will be
            if (i >= start && i <= start + subStrLength - 1)
            {
                // Assign character from given substring
                newStr[i] = *(runner);
                // Increment runner pointer
                runner++;
            }
            else
            {
                // Otherwise just copy the character from existing char array to new char array
                newStr[i] = str[index];
                // increment the character assignment counter
                index++;
            }
        }
        // Deallcate old dynamic array
        delete[] str;
        // Set str to newly created dynamic array
        str = newStr;

    }

    int String::indexOf(const char* subString)
    {
        // Get length of given subString
        int subStringLength = strlen(subString);
        // Store first letter of subString
        char firstChar = subString[0];
        // Loop through character of string
        for (int i = 0; i < size; i++)
        {
            // if a character matches the first character of the given substring
            if (str[i] == firstChar)
            {
                // Keep checking while the characters match
                int charsToCheck = subStringLength;
                // Start from current position
                int index = i;
                // Runner pointer to subString
                const char* runner = subString;
                bool found = true;
                // While there are characters to check
                while (charsToCheck > 0)
                {
                    // If current character does not match the given subString
                    if (str[index] != *runner)
                    {
                        // Get out of loop
                        found = false;
                        break;
                    }
                    // Otherwise increment the pointers to letter for string and subString
                    runner++;
                    index++;
                    // Decrease the number of letters to check
                    charsToCheck--;
                }
                // If letters are not different, substring exists in string
                if (found)
                    // Return its index
                    return i;
            }

        }
        // Otherwise return -1 when substring does not exist
        return -1;
    }

    void String::removeSubstring(int start, int numToRemove)
    {
        // Set the last position of string to be checked
        int end = start + numToRemove - 1;
        // Set new size of string
        int newSize = size - numToRemove ;
        // Allocate new char dynamic array
        char* newArray = new char[newSize]{};
        // Use to assign letters to array
        int index = 0;
        // Loop through string
        for (int i = 0; i < size; i++)
        {
            // if character is not between the start and end of the given subString
             if (i < start || i > end)
             {
                 // Copy it to new array
                 newArray[index] = str[i];
                 // Increment
                 index++;
             }
        }

        size = newSize;
        delete[] str;
        str = newArray;
    }

    void String::append(const char* newSubString)
    {
        // Store new size of string
        size_t newSize = size + strlen(newSubString);
        // Allocate dynamic array with new size
        char* newStr = new char[newSize]{};

        int i;
        // Copy string to new dynamic char array
        for (i = 0; i < size; i++)
        {
            newStr[i] = str[i];
        }
        // Copy characters from given newSubString into new char dynamic array
        int index = i;
        for (int j = 0; j < strlen(newSubString); j++)
        {
            newStr[index] = newSubString[j];
            index++;
        }
        // set size to newSize
        size = newSize;
        // Deallocate old dynamic array
        delete[] str;
        // Set str pointer to new dynamic array
        str = newStr;

    }

    void String::replace(const char* stringToReplace, const char* newString)
    {
        // If string is empty. return
        if (size == 0)
            return;

        // Get the index where given stringToReplace starts
        int indexToRemove = indexOf(stringToReplace);
        // If the given stringToReplace exists
        if (indexToRemove != -1)
        {
                // Remove it from the string
                removeSubstring(indexToRemove, strlen(stringToReplace));
                // Insert the given newString at given index
                insertSubstr(indexToRemove,newString);
        }
    }

    void String::operator=(const String &s)
    {
        // Set size to given string size
        size = s.size;
        // Copy characters from given existing instance of this class
        for (int i = 0; i < size; i++)
        {
            str[i] = s.str[i];
        }


    }

    void String::operator+(const char* newString)
    {
        // If string is empty, return
        if(strlen(newString) == 0)
            return;
        // Otherwise append given newString to string
        append(newString);
    }

    bool String::operator==(const String& s)
    {
        // If size is not equal, return false
        if (size != s.size)
            return false;
        // If characters are not equal return false
        // Loop through
        for (int i = 0; i < size; i++)
        {
            // If character are not equal
            if (str[i] != s.str[i])
                return false;
        }
        // Otherwise return true
        return true;
    }

    bool String::operator<(const String& s)
    {
        // Loop through characters of string
        for (int i = 0; i < size; i++)
        {
            // if current character alphanumeric value  is greater than the current character at given string instance
            if (str[i] > s.str[i])
                return false;
        }
        return true;
    }

    bool String::operator>(const String &s)
    {
        // Loop through characters of string
        for (int i = 0; i < size; i++)
        {
            // if current character alphanumeric value  is greater than the current character at given string instance
            if (str[i] < s.str[i])
                return false;
        }
        return true;
    }

    char String::at(int index)
    {
        // If given index is out of bounds, throw exception
        if (index < 0 || index > size)
            throw std::runtime_error("at: Given index out of bounds!");
        // Return the character
        return str[index];
    }

    char& String::operator[](int index)
    {
        // If given index is out of bounds, throw exception
        if (index < 0 || index > size)
            throw std::runtime_error("at: Given index out of bounds!");
        // Return the character
        return str[index];
    }


} 
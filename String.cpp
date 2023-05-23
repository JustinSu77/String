//
// Created by justi on 5/23/2023.
//

#include "String.h"
#include "cstring"
#include <iostream>
namespace justin_su
{
    String::String(): str(nullptr), size(0)
    {

    }
    String::String(const char* s)
    {
        size = strlen(s);
        str = new char[size]{};
        for (int i = 0; i < size; i++)
        {
            str[i] = s[i];
        }

    }

    String::~String()
    {
        delete[] str;
    }

    void String::operator=(const String &s)
    {
        size = s.size;
        for (int i = 0; i < size; i++)
        {
            str[i] = s.str[i];
        }


    }

    std::ostream &operator<<(std::ostream &stream, const String &s)
    {
        for (int i = 0; i < s.size; i++)
        {
            stream << s.str[i];
        }

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
            unsigned int ascii_code = (int)str[i];
            if (ascii_code >= 97 && ascii_code <= 122)
            {
                ascii_code = ascii_code - 32;
                char newChar = (char)ascii_code;
                str[i] = newChar;
            }

        }
    }

    void String::toLower()
    {
        for (int i = 0; i < size; i++)
        {
            unsigned int ascii_code = (int)str[i];
            if (ascii_code >= 65 && ascii_code <= 90)
            {
                ascii_code = ascii_code + 32;
                char newChar = (char)ascii_code;
                str[i] = newChar;
            }

        }
    }

    void String::reverse()
    {
        if (size == 0 || size == 1)
            return;
        size_t start = 0;
        size_t end = size - 1;
        while (start < end)
        {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }

    void String::insertSubstr(int start, const char* s)
    {
        if (start < 0 || start > size)
            throw std::runtime_error("Given start is out of bounds!");
        size_t subStrLength = strlen(s);
        if (subStrLength == 0)
            return;
        size = size + subStrLength;
        char* newStr = new char[size]{};
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

        // Insert substring
        const char* runner = s;
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (i >= start && i <= start + subStrLength - 1)
            {

                newStr[i] = *(runner);
                runner++;
            }
            else
            {
                newStr[i] = str[index];
                index++;
            }
        }
        delete[] str;
        str = newStr;

    }

    int String::indexOf(const char* subString)
    {
        int subStringLength = strlen(subString);
        char firstChar = subString[0];
        for (int i = 0; i < size; i++)
        {
            if (str[i] == firstChar)
            {
                int charsToCheck = subStringLength;
                int index = i;
                const char* runner = subString;
                bool found = true;
                while (charsToCheck > 0)
                {
                    if (str[index] != *runner)
                    {
                        found = false;
                        break;
                    }
                    runner++;
                    index++;
                    charsToCheck--;
                }
                if (found)
                    return i;
            }

        }
        return -1;
    }

    void String::removeSubstring(int start, int numToRemove)
    {
        int end = start + numToRemove - 1;
        int newSize = size - numToRemove ;
        char* newArray = new char[newSize]{};
        int index = 0;
        for (int i = 0; i < size; i++)
        {
             if (i < start || i > end)
             {

                 newArray[index] = str[i];
                 index++;
             }
        }
        size = newSize;
        delete[] str;
        str = newArray;
    }

    void String::append(const char* newSubString)
    {
        size_t newSize = size + strlen(newSubString);
        char* newStr = new char[newSize]{};
        std::cout << newSize << std::endl;
        int i;
        for (i = 0; i < size; i++)
        {
            newStr[i] = str[i];
        }
        std::cout << i << std::endl;
        int index = i;
        for (int j = 0; j < strlen(newSubString); j++)
        {
            newStr[index] = newSubString[j];
            index++;
        }
        size = newSize;
        delete[] str;
        str = newStr;

    }

    void String::replace(const char* stringToReplace, const char* newString)
    {
        if (size == 0)
            return;

            int removeindex = indexOf(stringToReplace);
            if (removeindex != -1)
            {
                removeSubstring(removeindex, strlen(stringToReplace));
                insertSubstr(removeindex,newString);
            }
    }

    void String::operator+(const char* newString)
    {
        if(strlen(newString) == 0)
            return;
        append(newString);
    }

    bool String::operator==(const String& s)
    {
        if (size != s.size)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (str[i] != s.str[i])
                return false;
        }
        return true;
    }

    bool String::operator<(const String& s)
    {
        for (int i = 0; i < size; i++)
        {
            if (str[i] > s.str[i])
                return false;
        }
        return true;
    }

    bool String::operator>(const String &s)
    {
        for (int i = 0; i < size; i++)
        {
            if (str[i] < s.str[i])
                return false;
        }
        return true;
    }

    char String::at(int index)
    {
        if (index < 0 || index > size)
            throw std::runtime_error("at: Given index out of bounds!");
        return str[index];
    }

    char& String::operator[](int index)
    {
        if (index < 0 || index > size)
            throw std::runtime_error("at: Given index out of bounds!");
        return str[index];
    }


} // justin_su
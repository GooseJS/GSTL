#include "String.h"

namespace GSTL
{
    String::String()
    {
        _data = new char[1];
        _data[0] = '\0';
        _len = 0;
        _maxLen = 0;
    }

    String::String(const char *data)
    {
        _len = strlen(data);
        _maxLen = _len;
        _data = new char[_len + 1];
        strcpy(_data, data);
    }

    String::String(String &string)
    {
        _len = string.size();
        _maxLen = _len;
        _data = new char[_len + 1];
        strcpy(_data, string.c_str());
    }

    String::String(const String &string)
    {
        _len = string.size();
        _maxLen = _len;
        _data = new char[_len + 1];
        strcpy(_data, string.c_str());
    }

    void String::append(const char* s)
    {
        size_t newLen = _len + strlen(s);
        if (_maxLen < newLen)
            resize(newLen);
        strcat(_data, s);
        _len = newLen;
        _maxLen = newLen;
    }

    void String::append(String &s)
    {
        append(s.c_str());
    }

    void String::resize(size_t maxLen)
    {
        if (maxLen < _maxLen)
        {
            char* temp = new char[maxLen + 1];
            memcpy(temp, _data, maxLen);
            temp[maxLen] = '\0';
            delete[] _data;
            _data = new char[maxLen + 1];
            strcpy(_data, temp);
            delete[] temp;
            _maxLen = maxLen;
            _len = maxLen;
        }
        else if (maxLen > _maxLen)
        {
            char* temp = new char[maxLen + 1];
            strcpy(temp, _data);
            delete[] _data;
            _data = new char[maxLen + 1];
            strcpy(_data, temp);
            delete[] temp;
            _maxLen = maxLen;
        }
    }

    int String::count(const char &s)
    {
        int count = 0;
        for (int i = 0; i < _len; i++)
            if (s == _data[i]) count++;
        return count;
    }

    int String::count(const char* s)
    {
        int count = 0;
        size_t countLen = strlen(s);
        char* buffer = new char[countLen + 1];
        buffer[countLen] = '\0';

        for (int i = 0; i < _len - countLen; i++)
        {
            memcpy(buffer, _data + (i * sizeof(char)), countLen);
            if (!strcmp(s, buffer)) count++;
        }

        delete[] buffer;
        return count;
    }

    String String::substring(int start, int end)
    {
        if (start > end)
            return String();
        if (start > _len) start = 0;
        if (end > _len) end = static_cast<int>(_len);
        auto bufferSize = static_cast<size_t>(end - start);
        char* buffer = new char[bufferSize + 1];
        memcpy(buffer, _data + start, bufferSize);
        buffer[bufferSize] = '\0';
        String result = String(buffer);
        delete[] buffer;
        return result;
    }

    String::~String()
    {
        delete[] _data;
    }
}
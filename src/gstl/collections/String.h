#pragma once

#include <cstdlib>
#include <cstring>

namespace GSTL
{
    class String
    {
    private:
        char* _data;
        size_t _len;
        size_t _maxLen;
    public:
        String();
        explicit String(const char* s);
        String(String &s);
        String(const String &s);
        ~String();

        void resize(size_t maxLen);

        void append(const char* s);
        void append(String &s);

        int count(const char &s);
        int count(const char* s);

        String substring(int start, int end);

        const inline size_t size() const { return _len; }
        const inline char* c_str() const { return _data; }

        inline bool operator<(String s)
        {
            return strcmp(c_str(), s.c_str()) == 0;
        }

        inline bool operator>(String s)
        {
            return strcmp(c_str(), s.c_str()) != 0;
        }
    };
}
#pragma once

#include <cstdlib>

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
        ~String();

        void resize(size_t maxLen);

        void append(const char* s);
        void append(String &s);

        int count(const char &s);
        int count(const char* s);

        String substring(int start, int end);

        const inline size_t size() { return _len; }
        const inline char* c_str() { return _data; }
    };
}
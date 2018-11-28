#pragma once

namespace GSTL
{
    template<typename T>
    class Vec2
    {
    public:
        T _x;
        T _y;
    public:
        inline Vec2()
        {
            _x = 0;
            _y = 0;
        }
        inline explicit Vec2(T xy)
        {
            _x = xy;
            _y = xy;
        }
        inline Vec2(T x, T y)
        {
            _x = x;
            _y = y;
        }
        inline Vec2(const Vec2 &v)
        {
            _x = v.x();
            _y = v.y();
        }

        inline T x() const { return _x; }
        inline T y() const { return _y; }
        inline void x(const T &x) { _x = x; }
        inline void y(const T &y) { _y = y; }

        inline void add(const T &xy) { add(xy, xy); }
        inline void add(const Vec2<T> &v) { add(v.x(), v.y()); }
        inline void add(const T &x, const T &y) { _x += x; _y += y; }

        inline void subtract(const T &xy) { subtract(xy, xy); }
        inline void subtract(const Vec2<T> &v) { subtract(v.x(), v.y()); }
        inline void subtract(const T &x, const T &y) { _x -= x; _y -= y; }

        inline void multiply(const T &xy) { multiply(xy, xy); }
        inline void multiply(const Vec2<T> &v) { multiply(v.x(), v.y()); }
        inline void multiply(const T &x, const T &y) { _x *= x, _y *= y; }

        inline void divide(const T &xy) { divide(xy, xy); }
        inline void divide(const Vec2<T> &v) { divide(v.x(), v.y()); }
        inline void divide(const T &x, const T &y) { _x /= x; _y /= y; }

        inline bool equals(const Vec2<T> &v) { return _x == v.x() && _y == v.y(); }

        inline Vec2<T> operator+(const Vec2<T> &v) const
        {
            Vec2<T> result = Vec2(_x, _y);
            result.add(v);
            return result;
        }

        inline Vec2<T> operator-(const Vec2<T> &v) const
        {
            Vec2<T> result = Vec2(_x, _y);
            result.subtract(v);
            return result;
        }

        inline Vec2<T> operator*(const Vec2<T> &v) const
        {
            Vec2<T> result = Vec2(_x, _y);
            result.multiply(v);
            return result;
        }

        inline Vec2<T> operator/(const Vec2<T> &v) const
        {
            Vec2<T> result = Vec2(_x, _y);
            result.divide(v);
            return result;
        }

        inline bool operator==(const Vec2<T> &v) const
        {
            return equals(v);
        }

    };
}
#pragma once

// simple 2D vector class
class vec2D {
    public:
        double x;
        double y;
        vec2D( double xIn = 0.0, double yIn = 0.0 ): x( xIn ), y( yIn ) {  }

        vec2D& operator+=( const vec2D& in ) {
            x += in.x;
            y += in.y;
            return *this;
        }

        vec2D& operator-=( const vec2D& in ) {
            x -= in.x;
            y -= in.y;
            return *this;
        }

        vec2D& operator*=( const vec2D& in ) {
            x *= in.x;
            y *= in.y;
            return *this;
        }

        vec2D& operator*=( const double& in ) {
            x *= in;
            y *= in;
            return *this;
        }

        double abs() const {
            double rv = sqrt( x * x + y * y );
            return rv;
        }

        void reset() {
            x = 0.0;
            y = 0.0;
        }

        vec2D norm() const {
            double length = abs();
            vec2D rv( x / length, y / length );
            return rv;
        }
};

inline vec2D operator+( vec2D const& a, vec2D const& b ) {
    vec2D result( a );
    result += b;
    return result;
}

inline vec2D operator-( vec2D const& a, vec2D const& b ) {
    vec2D result( a );
    result -= b;
    return result;
}

inline vec2D operator*( vec2D const& a, vec2D const& b )  {
    vec2D result( a );
    result *= b;
    return result;
}

inline vec2D operator*( vec2D const& a,  const double& b )  {
    vec2D result( a );
    result *= b;
    return result;
}

inline vec2D operator*( const double& a, vec2D const& b )  {
    vec2D result( b );
    result *= a;
    return result;
}

inline vec2D operator/( vec2D const& a, const double& b ) {
    return ( a * ( 1.0 / b ) );
}

inline std::ostream& operator<<( std::ostream& os, const vec2D& vec ) {
    os << "[" << int( vec.x ) << " " << int( vec.y ) << "]";
    return os;
}

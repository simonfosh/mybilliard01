#pragma once
namespace my_render_win32_imp {


    class DebugHelper {
    public:

        static wstring getStringFromInt( int val ) {
            wchar_t tmp[256];
            _snwprintf_s( tmp, sizeof( tmp ), L"%d", val );
            return tmp;
        }

        static wstring getStringFromFloat( float val ) {
            wchar_t tmp[256];
            _snwprintf_s( tmp, sizeof( tmp ), L"%f", val );
            return tmp;
        }

        static wstring getStringFromVec3( NxVec3 val ) {
            return wstring( L"( " ) +getStringFromFloat( val.x ) + L", "
                + getStringFromFloat( val.y ) + L", "
                + getStringFromFloat( val.z ) + L" )";
        }

        static bool isSameVec3( NxVec3 lhs, NxVec3 rhs, float epsilon ) {
            return isSameFloat( lhs.x, rhs.x, epsilon ) &&
                isSameFloat( lhs.y, rhs.y, epsilon ) &&
                isSameFloat( lhs.z, rhs.z, epsilon );
        }

        static bool isSameFloat( float lhs, float rhs, float epsilon ) {
             return (lhs + epsilon) > rhs && (lhs - epsilon) < rhs;
        }
    };

}
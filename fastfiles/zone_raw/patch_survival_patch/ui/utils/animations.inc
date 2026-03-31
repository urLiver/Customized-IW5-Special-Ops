#ifndef UTILS_ANIMATIONS__
    #define UTILS_ANIMATIONS__              1

    #define Animation_Get( anim_name, milli_seconds ) \
        select ( ( localvarfloat( anim_name ) > 0 ) , \
            max( min( ( milliseconds( ) - localvarfloat( anim_name ) ) / milli_seconds , 1 ) , 0 ), \
            max( min( 1 - ( milliseconds( ) + localvarfloat( anim_name ) ) / milli_seconds , 1 ) , 0 ) \
        )

    #define Animation_Start( anim_name ) \
        setLocalVarFloat anim_name ( ( 1 ) * milliseconds( ) );

    #define Animation_Reverse( anim_name ) \
        setLocalVarFloat anim_name ( ( -1 ) * milliseconds( ) );

    #define Animation_Focus( anim_name ) \
        onFocus \
        { \
            Animation_Start( anim_name ); \
            play "mouse_over"; \
        } \
        leaveFocus \
        { \
            Animation_Reverse( anim_name ); \
        }

    #define Animation_Mouse( anim_name ) \
        mouseEnter \
        { \
            Animation_Start( anim_name ); \
            play "mouse_over"; \
        } \
        mouseExit \
        { \
            Animation_Reverse( anim_name ); \
        }

#endif
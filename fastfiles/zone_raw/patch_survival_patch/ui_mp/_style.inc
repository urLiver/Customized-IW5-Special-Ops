#include "ui/utils/animations.inc"
#include "ui/utils/game_defaults.inc"

#ifndef _STYLE
    #define _STYLE 1

    #define _Shop_BuyWeaponButton( _y, current_menu, position_idx, armory_idx, anim_name ) \
        itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 ) 260 24 4 4 \
                style                       1 \
                type                        1 \
                visible                     when( menuistopmost( current_menu ) ); \
                background                  "white" \
                backcolor                   1 1 1 1 \
                disabled                    when( levelforexperienceso( getplayerdata( "experience" ) ) < int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ) ) \
                exp backcolor r             ( select( position_idx % 2, 0.2275, 0.2824 ) ) \
                exp backcolor g             ( select( position_idx % 2, 0.2392, 0.2941 ) ) \
                exp backcolor b             ( select( position_idx % 2, 0.2275, 0.2824 ) ) \ 
                Animation_Focus( anim_name ); \
                action \
                { \
                    play "mouse_click"; \
                    if( int( getplayerdata( "surHUD_credits" ) ) >= int( tablelookup( "sp/survival_armories.csv", 0, armory_idx, 3 ) ) ) \
                    { \
                        setLocalVarString purchase_item ( "purchase_" + armory_idx ); \
                        scriptmenuresponse localVarString( purchase_item ); \
                    } \
                } \
            } \
            itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 ) 260 22 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   0.7 1 0.7 0.85 \
                background                  "navbar_selection_bar" \
                exp backcolor a             ( Animation_Get( anim_name, 250 ) ) \
            } \
            itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 + 22 ) 260 6 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   1 1 1 1 \
                background                  "navbar_selection_bar_shadow" \
                exp backcolor a             ( Animation_Get( anim_name, 250 ) ) \
            } \
            itemDef \
            { \
                rect                        195 ( _y + position_idx * 24 ) 250 22 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   1 1 1 1 \
                textfont                    FONT_SMALL \ 
                textalign                   ALIGN_MIDDLE_LEFT \
                textscale                   0.375 \
                exp text                    "@" + tablelookup( "sp/survival_armories.csv", 0, armory_idx, 4 ); \
                exp forecolor r             ( select( levelforexperienceso( getplayerdata( "experience" ) ) < int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ), 0.5, 1 ) ) \
                exp forecolor g             ( select( levelforexperienceso( getplayerdata( "experience" ) ) < int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ), 0.5, 1 ) ) \
                exp forecolor b             ( select( levelforexperienceso( getplayerdata( "experience" ) ) < int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ), 0.5, 1 ) ) \
            } \
            itemDef \
            { \
                rect                        195 ( _y + position_idx * 24 ) 250 22 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) && levelforexperienceso( getplayerdata( "experience" ) ) >= int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ) ); \
                forecolor                   0.7 1 0.7 1 \
                textfont                    FONT_SMALL \ 
                textalign                   ALIGN_MIDDLE_RIGHT \
                textscale                   0.375 \
                exp text                    ( locstring( "@SO_SURVIVAL_CREDITS", int( tablelookup( "sp/survival_armories.csv", 0, armory_idx, 3 ) ) ) ) \ 
                exp forecolor r             ( select( int( getplayerdata( "surHUD_credits" ) ) >= int( tablelookup( "sp/survival_armories.csv", 0, armory_idx, 3 ) ), 0.7, 1 ) ) \
                exp forecolor g             ( select( int( getplayerdata( "surHUD_credits" ) ) >= int( tablelookup( "sp/survival_armories.csv", 0, armory_idx, 3 ) ), 1, 0.7 ) ) \
                exp forecolor b             ( select( int( getplayerdata( "surHUD_credits" ) ) >= int( tablelookup( "sp/survival_armories.csv", 0, armory_idx, 3 ) ), 0.7, 0.7 ) ) \ 
            } \
            itemDef \
            { \
                rect                        195 ( _y + position_idx * 24 ) 250 22 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) && levelforexperienceso( getplayerdata( "experience" ) ) < int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ) ); \
                forecolor                   1 0.7 0.7 1 \
                textfont                    FONT_SMALL \ 
                textalign                   ALIGN_MIDDLE_RIGHT \
                textscale                   0.375 \
                exp text                    ( locstring( "@SO_SURVIVAL_ARMORY_LOCKED_LV", ( int( tablelookup("sp/survival_armories.csv", 0, armory_idx, 7 ) ) + 1 ) ) ); \
            }

    #define _Shop_PageButton( _y, current_menu, position_idx, display_text, menu, anim_name ) \
        itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 ) 260 24 4 4 \
                style                       1 \
                type                        1 \
                visible                     when( menuistopmost( current_menu ) ); \
                background                  "white" \
                backcolor                   1 1 1 1 \
                exp backcolor r             ( select( position_idx % 2, 0.2275, 0.2824 ) ) \
                exp backcolor g             ( select( position_idx % 2, 0.2392, 0.2941 ) ) \
                exp backcolor b             ( select( position_idx % 2, 0.2275, 0.2824 ) ) \ 
                Animation_Focus( anim_name ); \
                action \
                { \
                    play "mouse_click"; \
                    open menu; \
                } \
            } \
            itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 ) 260 22 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   0.7 1 0.7 0.85 \
                background                  "navbar_selection_bar" \
                exp backcolor a             ( Animation_Get( anim_name, 250 ) ) \
            } \
            itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 + 22 ) 260 6 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   1 1 1 1 \
                background                  "navbar_selection_bar_shadow" \
                exp backcolor a             ( Animation_Get( anim_name, 250 ) ) \
            } \
            itemDef \
            { \
                rect                        195 ( _y + position_idx * 24 ) 250 22 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   1 1 1 1 \
                textfont                    FONT_SMALL \ 
                textalign                   ALIGN_MIDDLE_LEFT \
                textscale                   0.375 \
                exp text                    ( display_text ) \
            }

    #define _Shop_Begin( _y, current_menu, display_text ) \
        itemDef \
            { \
                rect                        190 ( _y ) 260 32 4 4 \
                style                       1 \
                decoration                  \
                visible                     when( menuistopmost( current_menu ) ); \
                background                  "white" \
                backcolor                   0.2075 0.2192 0.2075 1 \
            } \
            itemDef \
            { \
                rect                        190 ( _y + 32 ) 260 10 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   0.7 1 0.7 0.65 \
                backcolor                   0.7 1 0.7 0.65 \
                background                  "white" \
            } \
            itemDef \
            { \
                rect                        190 ( _y + 32 ) 260 10 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   1 1 1 1 \
                background                  "navbar_selection_bar_shadow" \
            } \
            itemDef \
            { \
                rect                        195 ( _y ) 250 32 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   1 1 1 1 \
                textfont                    FONT_BOLD \ 
                textalign                   ALIGN_MIDDLE_LEFT \
                textscale                   0.375 \
                exp text                    ( display_text ) \
            } \
            itemDef \
            { \
                rect                        195 ( _y ) 234 16 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   1 1 1 1 \
                textfont                    FONT_SMALL \ 
                textalign                   ALIGN_MIDDLE_RIGHT \
                textscale                   0.3 \
                exp text                    ( locstring("@SO_SURVIVAL_ARMORY_LOCKED_LV", ( levelforexperienceso( getplayerdata( "experience" ) ) + 1 ) ) ) \
            } \
            itemDef \
            { \
                rect                        195 ( _y + 2 ) 14 14 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   1 1 1 1 \
                exp material                tablelookup( "sp/rankTable.csv", 0, levelforexperienceso( getplayerdata( "experience" ) ), 6 ); \
                exp rect x                  ( 195 + 250 - 14 ) \
            } \
            itemDef \
            { \
                rect                        195 ( _y + 16 ) 250 16 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   0.7 1 0.7 0.85 \
                textfont                    FONT_SMALL \ 
                textalign                   ALIGN_MIDDLE_RIGHT \
                textscale                   0.3 \
                exp text                    ( locstring( "@SO_SURVIVAL_CREDITS", getplayerdata( "surHUD_credits" ) ) ) \
            }

    #define _Shop_End( _y, current_menu, position_idx ) \
            itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 ) 260 6 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                forecolor                   0.7 1 0.7 0.65 \
                backcolor                   0.7 1 0.7 0.65 \
                background                  "white" \
            } \
            itemDef \
            { \
                rect                        190 ( _y + position_idx * 24 ) 260 6 4 4 \
                decoration                  \
                style                       1 \
                visible                     when( menuistopmost( current_menu ) ); \
                backcolor                   1 1 1 1 \
                background                  "navbar_selection_bar_shadow" \
            }

    #define _Shop_SubFrame( current_menu ) \
        name                        current_menu \
		rect                        0 0 640 480 4 4 \
		visible                     when( menuistopmost( current_menu ) ); \
        popup \
		onOpen \
		{ \
			focusfirst; \
		} \
        onClose \
        { \
            open "survival_armory_weapon" \
        } \
        onESC \
        { \
            close self; \ 
        } \
        itemDef \
        { \
            rect                        -1280 -480 2560 960 2 2 \
            style                       3 \
            decoration                  \
            visible                     when( menuistopmost( current_menu ) ); \
            backcolor                   0 0 0 0.8 \
            forecolor                   0 0 0 0.8 \
            background                  "white" \
        }

    #define _Shop_MainFrame( current_menu ) \
        name                        current_menu \
		rect                        0 0 640 480 4 4 \
		visible                     when( menuistopmost( current_menu ) ); \
        popup \
		onOpen \
		{ \
			focusfirst; \
		} \
        onClose \
        { \
            scriptmenuresponse quit; \
            play ""; \
        } \
        onESC \
        { \
            close self; \ 
        } \
        itemDef \
        { \
            rect                        -1280 -480 2560 960 2 2 \
            style                       3 \
            decoration                  \
            visible                     when( menuistopmost( current_menu ) ); \
            backcolor                   0 0 0 0.8 \
            forecolor                   0 0 0 0.8 \
            background                  "white" \
        }
#endif
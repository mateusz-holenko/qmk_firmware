#include QMK_KEYBOARD_H
#include "raw_hid.h"

// --- HELPERS ---
#define _____ KC_NO
#define __v__ KC_TRNS
// --- END OF HELPERS ---

// --- LAYERS ---
#define _WORKMAN_LAYER 0
#define _QWERTY_LAYER  1
#define _SYMBOLS_LAYER 2
#define _TMUX_LAYER 3
#define _QTILE_LAYER 4
#define _ALT_LAYER 5
#define _MOVE_LAYER 6
#define _MOUSE_LAYER 7
#define _SYSTEM_LAYER 8
// --- END OF LAYERS ---

// --- TAP DANCES ---
enum {
    TD_1_F1,
    TD_2_F2,
    TD_3_F3,
    TD_4_F4,
    TD_5_F5,
    TD_6_F6,
    TD_7_F7,
    TD_8_F8,
    TD_9_F9,
    TD_0_F10,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_1_F1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2_F2]  = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3_F3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4_F4]  = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5_F5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6_F6]  = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7_F7]  = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8_F8]  = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9_F9]  = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
};
// --- END OF TAP DANCES ---

// --- COMBOS ---
#if 0
enum combo_events {
    AS_COMBO
};

const uint16_t PROGMEM test_combo[] = { KC_A, KC_S, COMBO_END };

combo_t key_combos[1] = { 
    [AS_COMBO] = COMBO_ACTION(test_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case AS_COMBO:
      if (pressed) {
        tap_code16(RALT(KC_A));
      }
      break;
  }
} 
#endif
// --- END OF COMBOS ---

// --- MACROS ---
enum custom_keycodes {
    _TMUX_PREV = SAFE_RANGE,
    _TMUX_PANE0,
    _TMUX_PANE1,
    _TMUX_PANE2,
    _TMUX_PANE3,
    _TMUX_PANE4,
    _TMUX_PANE5,
    _TMUX_PANE6,
    _TMUX_PANE7,
    _TMUX_PANE8,
    _TMUX_PANE9,
    _TMUX_UP,
    _TMUX_DOWN,
    _TMUX_LEFT,
    _TMUX_RIGHT,
    _TMUX_SPLITH,
    _TMUX_SPLITV,
    _TMUX_KILL,
    _TMUX_MAX,
    _TMUX_MAX2,
    _TMUX_CREATE,

    _QTILE_PREV,
    _QTILE_GROUP0,
    _QTILE_GROUP1,
    _QTILE_GROUP2,
    _QTILE_GROUP3,
    _QTILE_GROUP4,
    _QTILE_GROUP5,
    _QTILE_GROUP6,
    _QTILE_GROUP7,
    _QTILE_GROUP8,
    _QTILE_GROUP9,
    _QTILE_UP,
    _QTILE_DOWN,
    _QTILE_LEFT,
    _QTILE_RIGHT,
};

#define TMUX_ACTION \
        register_code(KC_LCTL); \
        tap_code(KC_A); \
        unregister_code(KC_LCTL);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
    case _TMUX_PREV:
        register_code(KC_LCTL);
        tap_code(KC_A);
        tap_code(KC_A);
        unregister_code(KC_LCTL);
        break;
    case _TMUX_UP:
        TMUX_ACTION
        tap_code(KC_K);
        break;
    case _TMUX_DOWN:
        TMUX_ACTION
        tap_code(KC_J);
        break;
    case _TMUX_LEFT:
        TMUX_ACTION
        tap_code(KC_H);
        break;
    case _TMUX_RIGHT:
        TMUX_ACTION
        tap_code(KC_L);
        break;
    case _TMUX_PANE0:
        TMUX_ACTION
        tap_code(KC_0);
        break;
    case _TMUX_PANE1:
        TMUX_ACTION
        tap_code(KC_1);
        break;
    case _TMUX_PANE2:
        TMUX_ACTION
        tap_code(KC_2);
        break;
    case _TMUX_PANE3:
        TMUX_ACTION
        tap_code(KC_3);
        break;
    case _TMUX_PANE4:
        TMUX_ACTION
        tap_code(KC_4);
        break;
    case _TMUX_PANE5:
        TMUX_ACTION
        tap_code(KC_5);
        break;
    case _TMUX_PANE6:
        TMUX_ACTION
        tap_code(KC_6);
        break;
    case _TMUX_PANE7:
        TMUX_ACTION
        tap_code(KC_7);
        break;
    case _TMUX_PANE8:
        TMUX_ACTION
        tap_code(KC_8);
        break;
    case _TMUX_PANE9:
        TMUX_ACTION
        tap_code(KC_9);
        break;
    case _TMUX_SPLITH:
        TMUX_ACTION
        tap_code(KC_BSLS);
        break;
    case _TMUX_SPLITV:
        TMUX_ACTION
        tap_code(KC_MINUS);
        break;
    case _TMUX_MAX:
    case _TMUX_MAX2:
        TMUX_ACTION
        tap_code(KC_Z);
        break;
    case _TMUX_KILL:
        TMUX_ACTION
        tap_code(KC_X);
        tap_code(KC_Y);
        break;

    case _TMUX_CREATE:
        TMUX_ACTION
        tap_code(KC_C);
        break;

    case _QTILE_PREV:
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_U);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_UP:
        register_code(KC_LGUI);
        tap_code(KC_K);
        unregister_code(KC_LGUI);
        break;
    case _QTILE_DOWN:
        register_code(KC_LGUI);
        tap_code(KC_J);
        unregister_code(KC_LGUI);
        break;
    case _QTILE_LEFT:
        register_code(KC_LGUI);
        tap_code(KC_H);
        unregister_code(KC_LGUI);
        break;
    case _QTILE_RIGHT:
        register_code(KC_LGUI);
        tap_code(KC_L);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP0:
        register_code(KC_LGUI);
        tap_code(KC_0);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP1:
        register_code(KC_LGUI);
        tap_code(KC_1);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP2:
        register_code(KC_LGUI);
        tap_code(KC_2);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP3:
        register_code(KC_LGUI);
        tap_code(KC_3);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP4:
        register_code(KC_LGUI);
        tap_code(KC_4);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP5:
        register_code(KC_LGUI);
        tap_code(KC_5);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP6:
        register_code(KC_LGUI);
        tap_code(KC_6);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP7:
        register_code(KC_LGUI);
        tap_code(KC_7);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP8:
        register_code(KC_LGUI);
        tap_code(KC_8);
        unregister_code(KC_LGUI);
        break;

    case _QTILE_GROUP9:
        register_code(KC_LGUI);
        tap_code(KC_9);
        unregister_code(KC_LGUI);
        break;
    }

    return true;
};
// --- END OF MACROS ---

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_WORKMAN_LAYER] = LAYOUT_ortho_5x15(
        	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        	LT(_SYSTEM_LAYER, KC_ESC)        , /* | */ TD(TD_1_F1)   , TD(TD_2_F2)    ,  TD(TD_3_F3)   ,  TD(TD_4_F4)         , TD(TD_5_F5)  , /* | */ _____, _____,  _____                 , /* | */ TD(TD_6_F6)           , TD(TD_7_F7)         , TD(TD_8_F8)   , TD(TD_9_F9)    , TD(TD_0_F10)                     , /* | */ KC_BSPC     ,
        	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        	KC_TAB          , /* | */ KC_Q   , KC_D                  , KC_R           , KC_W           , KC_B                 , /* | */ _____, _____        , _____, /* | */ KC_J           , KC_F                          , KC_U                , KC_P          , KC_SCLN        , /* | */ KC_QUOT                  ,
        	LCTL_T(KC_ESC)  , /* | */ KC_A   , KC_S                  , KC_H           , KC_T           , KC_G                 , /* | */ _____, _____        , _____, /* | */ KC_Y           , KC_N                          , KC_E                , KC_O          , KC_I           , /* | */ KC_ENT                   ,
        	OSM(MOD_LSFT)   , /* | */ KC_Z   , KC_X                  , KC_M           , KC_C           , KC_V                 , /* | */ _____, _____        , _____, /* | */ KC_K           , KC_L                          , OSL(_SYMBOLS_LAYER) , KC_DOT        , KC_SLSH        , /* | */ KC_RSFT                  ,
        	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        	_____           , /* | */ KC_LGUI, KC_LALT               , KC_BSPC        , KC_SPC         , LT(_TMUX_LAYER, _TMUX_PREV)      , /* | */ _____, _____        , _____, /* | */ TT(_MOVE_LAYER), LT(_ALT_LAYER, KC_ENT)        , TT(_QTILE_LAYER)    , KC_RALT       , KC_RGUI        , /* | */ TG(_SYMBOLS_LAYER))      ,
        	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[_QWERTY_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__    ,  __v__   ,  __v__ , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ KC_Q    , KC_W     , KC_E     , KC_R   , KC_T          , /* | */ __v__, __v__ , __v__, /* | */ KC_Y            , KC_U   , KC_I    , KC_O     , KC_P      , /* | */ __v__       ,
        	__v__         , /* | */ KC_A    , KC_S     , KC_D     , KC_F   , KC_G          , /* | */ __v__, __v__ , __v__, /* | */ KC_H            , KC_J   , KC_K    , KC_L     , __v__     , /* | */ __v__       ,
        	__v__         , /* | */ KC_Z    , KC_X     , KC_C     , KC_V   , KC_B          , /* | */ __v__, __v__ , __v__, /* | */ KC_N            , KC_M   , __v__   , __v__    , __v__     , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__    , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__)      ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

	[_MOVE_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__              ,  __v__   ,  __v__ , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__                      , __v__    , __v__     , __v__       , __v__       , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__              , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ KC_INS                     , KC_HOME  , KC_UP     , KC_END      , KC_PGUP     , /* | */ __v__       ,
        	__v__         , /* | */ __v__   , __v__              , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ KC_DEL                     , KC_LEFT  , KC_DOWN   , KC_RIGHT    , KC_PGDN     , /* | */ __v__       ,
        	__v__         , /* | */ __v__   , __v__              , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ TG(_MOUSE_LAYER)           , __v__    , __v__     , __v__       , __v__       , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__              , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__                      , __v__    , __v__     , __v__       , __v__       , /* | */ __v__)      ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

	[_MOUSE_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__    ,  __v__        ,  __v__      , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__       , __v__        , __v__          , __v__             , /* | */ KC_MS_ACCEL0       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__    , __v__         , __v__       , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__       , KC_MS_UP     , KC_END         , KC_MS_WH_UP       , /* | */ KC_MS_ACCEL1       ,
        	__v__         , /* | */ __v__   , __v__    , __v__         , __v__       , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__           , KC_MS_LEFT  , KC_MS_DOWN   , KC_MS_RIGHT    , KC_MS_WH_DOWN     , /* | */ KC_MS_ACCEL2       ,
        	__v__         , /* | */ __v__   , __v__    , __v__         , __v__       , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__           , KC_MS_BTN1  , KC_MS_BTN3   , KC_MS_BTN2     , __v__             , /* | */ __v__              ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__   , __v__    , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__       , __v__        , __v__          , __v__             , /* | */ __v__)             ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

	[_SYSTEM_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__           , /* | */ RGB_TOG   , RGB_MOD     ,  RGB_HUI   ,  RGB_SAI  , RGB_VAI          , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ RESET                    ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__           , /* | */ __v__     , RGB_RMOD    , RGB_HUD    , RGB_SAD   , RGB_VAD          , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ DEBUG                    ,
        	KC_ASUP         , /* | */ RGB_M_P   , RGB_M_B     , RGB_M_R    , RGB_M_SW  , RGB_M_SN         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__                    ,
                KC_ASDN         , /* | */ RGB_M_K   , RGB_M_X     , RGB_M_G    , RGB_M_T   , __v__            , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ DF(_WORKMAN_LAYER)       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	KC_ASTG         , /* | */ KC_ASOFF   , KC_ASON     , __v__      , __v__     , __v__            , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ DF(_QWERTY_LAYER))       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

	[_SYMBOLS_LAYER] = LAYOUT_ortho_5x15(
        	// ----------------------- -------------------------------------------------------------------------------------------------------------
        	__v__ , /* | */ __v__      , __v__     ,  __v__    ,  __v__     , __v__      , /* | */ __v__, __v__ , __v__, /* | */ __v__                , __v__      , __v__      , __v__   , __v__      , /* | */ __v__  ,
        	// ----------------------- -------------------------------------------------------------------------------------------------------------
        	__v__ , /* | */ S(KC_5)    , S(KC_7)   , S(KC_EQL) , S(KC_2)    , S(KC_4)    , /* | */ __v__, __v__ , __v__, /* | */ KC_SLSH              , KC_LBRC    , KC_RBRC    , S(KC_1) , S(KC_QUOT) , /* | */ __v__  ,
        	__v__ , /* | */ S(KC_MINS) , S(KC_9)   , KC_EQL    , S(KC_LBRC) , KC_0       , /* | */ __v__, __v__ , __v__, /* | */ KC_1                 , S(KC_RBRC) , S(KC_8)    , S(KC_0) , KC_MINS    , /* | */ __v__  ,
        	__v__ , /* | */ KC_6       , KC_7      , KC_8      , KC_9       , S(KC_BSLS) , /* | */ __v__, __v__ , __v__, /* | */ KC_BSLS              , KC_2       , KC_3       , KC_4    , KC_5       , /* | */ __v__  ,
        	// ----------------------- -------------------------------------------------------------------------------------------------------------
        	__v__ , /* | */ __v__      , S(KC_GRV) , S(KC_6)   , __v__      , KC_GRV     , /* | */ __v__, __v__ , __v__, /* | */ S(KC_3)              , KC_COMM    , S(KC_COMM) , __v__   , __v__      , /* | */ __v__) ,
        	// ----------------------- -------------------------------------------------------------------------------------------------------------

    	[_TMUX_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__         , __v__          ,  __v__         ,  __v__       , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , __v__        , __v__         , __v__          , __v__           , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__         , _TMUX_MAX      , _TMUX_MAX2     , __v__        , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , __v__        , _TMUX_UP      , __v__          , __v__           , /* | */ __v__       ,
        	__v__         , /* | */ _TMUX_KILL    , _TMUX_SPLITH   , _TMUX_SPLITV   , _TMUX_PREV   , _TMUX_PANE0        , /* | */ __v__, __v__ , __v__, /* | */ _TMUX_PANE1           , _TMUX_LEFT   , _TMUX_DOWN    , _TMUX_RIGHT    , __v__           , /* | */ __v__       ,
        	__v__         , /* | */ _TMUX_PANE6   , _TMUX_PANE7    , _TMUX_PANE8    , _TMUX_PANE9  , _TMUX_CREATE       , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , _TMUX_PANE2  , _TMUX_PANE3   , _TMUX_PANE4    , _TMUX_PANE5     , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__         , __v__          , __v__          , __v__        , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , __v__        , __v__         , __v__          , __v__           , /* | */ __v__)      ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    	[_ALT_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__      , __v__       ,  __v__   ,  __v__     , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__      , __v__   , __v__         , __v__          , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__      , __v__       , __v__    , __v__      , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__      , __v__   , __v__         , __v__          , /* | */ __v__       ,
        	__v__         , /* | */ ALGR(KC_A) , ALGR(KC_S)  , __v__    , __v__      , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__      , ALGR(KC_E) ,      ALGR(KC_O),  __v__    , /* | */ __v__       ,
        	__v__         , /* | */ ALGR(KC_Z) , ALGR(KC_X)  , __v__    , ALGR(KC_C) , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , ALGR(KC_L) , __v__   , __v__         , __v__          , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__      , __v__       , __v__    , KC_BSPC    , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__      , __v__   , __v__         , __v__          , /* | */ __v__)      ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    	[_QTILE_LAYER] = LAYOUT_ortho_5x15(
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__         , __v__          ,  __v__         ,  __v__       , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , __v__        , __v__         , __v__          , __v__           , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__         , __v__          , __v__          , __v__        , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , __v__        , _QTILE_UP         , __v__          , __v__        , /* | */ __v__       ,
        	__v__         , /* | */ __v__         , __v__          , __v__          , _QTILE_PREV  , _QTILE_GROUP0      , /* | */ __v__, __v__ , __v__, /* | */ _QTILE_GROUP1         , _QTILE_LEFT   , _QTILE_DOWN    , _QTILE_RIGHT    , __v__           , /* | */ __v__       ,
        	__v__         , /* | */ _QTILE_GROUP6 , _QTILE_GROUP7  , _QTILE_GROUP8  , _QTILE_GROUP9, __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , _QTILE_GROUP2  , _QTILE_GROUP3   , _QTILE_GROUP4    , _QTILE_GROUP5     , /* | */ __v__       ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        	__v__         , /* | */ __v__         , __v__          , __v__          , __v__        , __v__              , /* | */ __v__, __v__ , __v__, /* | */ __v__                 , __v__        , __v__         , __v__          , __v__           , /* | */ __v__)      ,
        	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
#if 0
	[_EMPTY_LAYER] = LAYOUT_ortho_5x15(
	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
	__v__         , /* | */ __v__   , __v__    ,  __v__   ,  __v__ , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__       ,
	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
	__v__         , /* | */ __v__   , __v__    , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__       ,
	__v__         , /* | */ __v__   , __v__    , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__       ,
	__v__         , /* | */ __v__   , __v__    , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__       ,
	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
	__v__         , /* | */ __v__   , __v__    , __v__    , __v__  , __v__         , /* | */ __v__, __v__ , __v__, /* | */ __v__           , __v__  , __v__   , __v__    , __v__     , /* | */ __v__)      ,
	// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
        raw_hid_send(data, length);
}

bool _reenable_as;

uint32_t layer_state_set_user(uint32_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _TMUX_LAYER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MOVE_LAYER));

    switch (biton32(state)) {
      case _SYMBOLS_LAYER:
          _reenable_as |= get_autoshift_state();
          autoshift_disable();
          break;
      default:
          if (_reenable_as) {
              _reenable_as = false;
              autoshift_enable();
          }
          break;
      }
   return state;
}

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 2, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _WORKMAN_LAYER));
    return state;
}


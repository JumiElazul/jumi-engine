#ifndef JUMI_ENGINE_CORE_INPUT_KEYCODES_H
#define JUMI_ENGINE_CORE_INPUT_KEYCODES_H

using JUMI_KEY = int;
using JUMI_MOUSE_BUTTON = int;
using JUMI_JOYSTICK = int;
using JUMI_GAMEPAD_BUTTON = int;
using JUMI_MOD = int;
using JUMI_KEY_STATE = bool;

#define JUMI_RELEASE                                    0
#define JUMI_PRESS                                      1
#define JUMI_REPEAT                                     2

#define JUMI_KEY_SPACE                                  32
#define JUMI_KEY_APOSTROPHE                             39 
#define JUMI_KEY_COMMA                                  44
#define JUMI_KEY_MINUS                                  45
#define JUMI_KEY_PERIOD                                 46
#define JUMI_KEY_SLASH                                  47
#define JUMI_KEY_0                                      48
#define JUMI_KEY_1                                      49
#define JUMI_KEY_2                                      50
#define JUMI_KEY_3                                      51
#define JUMI_KEY_4                                      52
#define JUMI_KEY_5                                      53
#define JUMI_KEY_6                                      54
#define JUMI_KEY_7                                      55
#define JUMI_KEY_8                                      56
#define JUMI_KEY_9                                      57
#define JUMI_KEY_SEMICOLON                              59
#define JUMI_KEY_EQUAL                                  61
#define JUMI_KEY_A                                      65
#define JUMI_KEY_B                                      66
#define JUMI_KEY_C                                      67
#define JUMI_KEY_D                                      68
#define JUMI_KEY_E                                      69
#define JUMI_KEY_F                                      70
#define JUMI_KEY_G                                      71
#define JUMI_KEY_H                                      72
#define JUMI_KEY_I                                      73
#define JUMI_KEY_J                                      74
#define JUMI_KEY_K                                      75
#define JUMI_KEY_L                                      76
#define JUMI_KEY_M                                      77
#define JUMI_KEY_N                                      78
#define JUMI_KEY_O                                      79
#define JUMI_KEY_P                                      80
#define JUMI_KEY_Q                                      81
#define JUMI_KEY_R                                      82
#define JUMI_KEY_S                                      83
#define JUMI_KEY_T                                      84
#define JUMI_KEY_U                                      85
#define JUMI_KEY_V                                      86
#define JUMI_KEY_W                                      87
#define JUMI_KEY_X                                      88
#define JUMI_KEY_Y                                      89
#define JUMI_KEY_Z                                      90
#define JUMI_KEY_LEFT_BRACKET                           91
#define JUMI_KEY_BACKSLASH                              92
#define JUMI_KEY_RIGHT_BRACKET                          93
#define JUMI_KEY_GRAVE_ACCENT                           96
#define JUMI_KEY_WORLD_1                                161
#define JUMI_KEY_WORLD_2                                162

/* Function keys */
#define JUMI_KEY_ESCAPE                                 256
#define JUMI_KEY_ENTER                                  257
#define JUMI_KEY_TAB                                    258
#define JUMI_KEY_BACKSPACE                              259
#define JUMI_KEY_INSERT                                 260
#define JUMI_KEY_DELETE                                 261
#define JUMI_KEY_RIGHT                                  262
#define JUMI_KEY_LEFT                                   263
#define JUMI_KEY_DOWN                                   264
#define JUMI_KEY_UP                                     265
#define JUMI_KEY_PAGE_UP                                266
#define JUMI_KEY_PAGE_DOWN                              267
#define JUMI_KEY_HOME                                   268
#define JUMI_KEY_END                                    269
#define JUMI_KEY_CAPS_LOCK                              280
#define JUMI_KEY_SCROLL_LOCK                            281
#define JUMI_KEY_NUM_LOCK                               282
#define JUMI_KEY_PRINT_SCREEN                           283
#define JUMI_KEY_PAUSE                                  284
#define JUMI_KEY_F1                                     290
#define JUMI_KEY_F2                                     291
#define JUMI_KEY_F3                                     292
#define JUMI_KEY_F4                                     293
#define JUMI_KEY_F5                                     294
#define JUMI_KEY_F6                                     295
#define JUMI_KEY_F7                                     296
#define JUMI_KEY_F8                                     297
#define JUMI_KEY_F9                                     298
#define JUMI_KEY_F10                                    299
#define JUMI_KEY_F11                                    300
#define JUMI_KEY_F12                                    301
#define JUMI_KEY_F13                                    302
#define JUMI_KEY_F14                                    303
#define JUMI_KEY_F15                                    304
#define JUMI_KEY_F16                                    305
#define JUMI_KEY_F17                                    306
#define JUMI_KEY_F18                                    307
#define JUMI_KEY_F19                                    308
#define JUMI_KEY_F20                                    309
#define JUMI_KEY_F21                                    310
#define JUMI_KEY_F22                                    311
#define JUMI_KEY_F23                                    312
#define JUMI_KEY_F24                                    313
#define JUMI_KEY_F25                                    314
#define JUMI_KEY_KP_0                                   320
#define JUMI_KEY_KP_1                                   321
#define JUMI_KEY_KP_2                                   322
#define JUMI_KEY_KP_3                                   323
#define JUMI_KEY_KP_4                                   324
#define JUMI_KEY_KP_5                                   325
#define JUMI_KEY_KP_6                                   326
#define JUMI_KEY_KP_7                                   327
#define JUMI_KEY_KP_8                                   328
#define JUMI_KEY_KP_9                                   329
#define JUMI_KEY_KP_DECIMAL                             330
#define JUMI_KEY_KP_DIVIDE                              331
#define JUMI_KEY_KP_MULTIPLY                            332
#define JUMI_KEY_KP_SUBTRACT                            333
#define JUMI_KEY_KP_ADD                                 334
#define JUMI_KEY_KP_ENTER                               335
#define JUMI_KEY_KP_EQUAL                               336
#define JUMI_KEY_LEFT_SHIFT                             340
#define JUMI_KEY_LEFT_CONTROL                           341
#define JUMI_KEY_LEFT_ALT                               342
#define JUMI_KEY_LEFT_SUPER                             343
#define JUMI_KEY_RIGHT_SHIFT                            344
#define JUMI_KEY_RIGHT_CONTROL                          345
#define JUMI_KEY_RIGHT_ALT                              346
#define JUMI_KEY_RIGHT_SUPER                            347
#define JUMI_KEY_MENU                                   348
#define JUMI_KEY_LAST                                   JUMI_KEY_MENU

#define JUMI_MOD_SHIFT                                  0x0001
#define JUMI_MOD_CONTROL                                0x0002
#define JUMI_MOD_ALT                                    0x0004
#define JUMI_MOD_SUPER                                  0x0008
#define JUMI_MOD_CAPS_LOCK                              0x0010
#define JUMI_MOD_NUM_LOCK                               0x0020
#define JUMI_MOUSE_BUTTON_1                             0
#define JUMI_MOUSE_BUTTON_2                             1
#define JUMI_MOUSE_BUTTON_3                             2
#define JUMI_MOUSE_BUTTON_4                             3
#define JUMI_MOUSE_BUTTON_5                             4
#define JUMI_MOUSE_BUTTON_6                             5
#define JUMI_MOUSE_BUTTON_7                             6
#define JUMI_MOUSE_BUTTON_8                             7
#define JUMI_MOUSE_BUTTON_LAST                          JUMI_MOUSE_BUTTON_8
#define JUMI_MOUSE_BUTTON_LEFT                          JUMI_MOUSE_BUTTON_1
#define JUMI_MOUSE_BUTTON_RIGHT                         JUMI_MOUSE_BUTTON_2
#define JUMI_MOUSE_BUTTON_MIDDLE                        JUMI_MOUSE_BUTTON_3

#define JUMI_JOYSTICK_1                                 0
#define JUMI_JOYSTICK_2                                 1
#define JUMI_JOYSTICK_3                                 2
#define JUMI_JOYSTICK_4                                 3
#define JUMI_JOYSTICK_5                                 4
#define JUMI_JOYSTICK_6                                 5
#define JUMI_JOYSTICK_7                                 6
#define JUMI_JOYSTICK_8                                 7
#define JUMI_JOYSTICK_9                                 8
#define JUMI_JOYSTICK_10                                9
#define JUMI_JOYSTICK_11                                10
#define JUMI_JOYSTICK_12                                11
#define JUMI_JOYSTICK_13                                12
#define JUMI_JOYSTICK_14                                13
#define JUMI_JOYSTICK_15                                14
#define JUMI_JOYSTICK_16                                15
#define JUMI_JOYSTICK_LAST                              JUMI_JOYSTICK_16

#define JUMI_GAMEPAD_BUTTON_A                           0
#define JUMI_GAMEPAD_BUTTON_B                           1
#define JUMI_GAMEPAD_BUTTON_X                           2
#define JUMI_GAMEPAD_BUTTON_Y                           3
#define JUMI_GAMEPAD_BUTTON_LEFT_BUMPER                 4
#define JUMI_GAMEPAD_BUTTON_RIGHT_BUMPER                5
#define JUMI_GAMEPAD_BUTTON_BACK                        6
#define JUMI_GAMEPAD_BUTTON_START                       7
#define JUMI_GAMEPAD_BUTTON_GUIDE                       8
#define JUMI_GAMEPAD_BUTTON_LEFT_THUMB                  9
#define JUMI_GAMEPAD_BUTTON_RIGHT_THUMB                 10
#define JUMI_GAMEPAD_BUTTON_DPAD_UP                     11
#define JUMI_GAMEPAD_BUTTON_DPAD_RIGHT                  12
#define JUMI_GAMEPAD_BUTTON_DPAD_DOWN                   13
#define JUMI_GAMEPAD_BUTTON_DPAD_LEFT                   14
#define JUMI_GAMEPAD_BUTTON_LAST                        JUMI_GAMEPAD_BUTTON_DPAD_LEFT

#define JUMI_GAMEPAD_BUTTON_CROSS                       JUMI_GAMEPAD_BUTTON_A
#define JUMI_GAMEPAD_BUTTON_CIRCLE                      JUMI_GAMEPAD_BUTTON_B
#define JUMI_GAMEPAD_BUTTON_SQUARE                      JUMI_GAMEPAD_BUTTON_X
#define JUMI_GAMEPAD_BUTTON_TRIANGLE                    JUMI_GAMEPAD_BUTTON_Y

#endif

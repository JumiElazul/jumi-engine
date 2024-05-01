#include "engine_core/input/keycodes.h"
#include <glfw/glfw3.h>

namespace jumi
{

    jumi_keyaction glfw_keyaction_to_jumi(int glfw_key)
    {
        switch (glfw_key)
        {
            case GLFW_RELEASE:                          return jumi_keyaction::release;
            case GLFW_PRESS:                            return jumi_keyaction::press;
            case GLFW_REPEAT:                           return jumi_keyaction::repeat;
        }
    }

    int jumi_keyaction_to_glfw(jumi_keyaction jumi_key)
    {
        switch (jumi_key)
        {
            case jumi_keyaction::release:               return GLFW_RELEASE;
            case jumi_keyaction::press:                 return GLFW_PRESS;
            case jumi_keyaction::repeat:                return GLFW_REPEAT;
        }
    }

    jumi_key glfw_key_to_jumi(int glfw_key)
    {
        switch (glfw_key)
        {
            case GLFW_KEY_SPACE:                        return jumi_key::key_space;
            case GLFW_KEY_APOSTROPHE:                   return jumi_key::key_apostrophe;
            case GLFW_KEY_COMMA:                        return jumi_key::key_comma;
            case GLFW_KEY_MINUS:                        return jumi_key::key_minus;
            case GLFW_KEY_PERIOD:                       return jumi_key::key_period;
            case GLFW_KEY_SLASH:                        return jumi_key::key_slash;
            case GLFW_KEY_0:                            return jumi_key::key_0;
            case GLFW_KEY_1:                            return jumi_key::key_1;
            case GLFW_KEY_2:                            return jumi_key::key_2;
            case GLFW_KEY_3:                            return jumi_key::key_3;
            case GLFW_KEY_4:                            return jumi_key::key_4;
            case GLFW_KEY_5:                            return jumi_key::key_5;
            case GLFW_KEY_6:                            return jumi_key::key_6;
            case GLFW_KEY_7:                            return jumi_key::key_7;
            case GLFW_KEY_8:                            return jumi_key::key_8;
            case GLFW_KEY_9:                            return jumi_key::key_9;
            case GLFW_KEY_SEMICOLON:                    return jumi_key::key_semicolon;
            case GLFW_KEY_EQUAL:                        return jumi_key::key_equal;
            case GLFW_KEY_A:                            return jumi_key::key_a;
            case GLFW_KEY_B:                            return jumi_key::key_b;
            case GLFW_KEY_C:                            return jumi_key::key_c;
            case GLFW_KEY_D:                            return jumi_key::key_d;
            case GLFW_KEY_E:                            return jumi_key::key_e;
            case GLFW_KEY_F:                            return jumi_key::key_f;
            case GLFW_KEY_G:                            return jumi_key::key_g;
            case GLFW_KEY_H:                            return jumi_key::key_h;
            case GLFW_KEY_I:                            return jumi_key::key_i;
            case GLFW_KEY_J:                            return jumi_key::key_j;
            case GLFW_KEY_K:                            return jumi_key::key_k;
            case GLFW_KEY_L:                            return jumi_key::key_l;
            case GLFW_KEY_M:                            return jumi_key::key_m;
            case GLFW_KEY_N:                            return jumi_key::key_n;
            case GLFW_KEY_O:                            return jumi_key::key_o;
            case GLFW_KEY_P:                            return jumi_key::key_p;
            case GLFW_KEY_Q:                            return jumi_key::key_q;
            case GLFW_KEY_R:                            return jumi_key::key_r;
            case GLFW_KEY_S:                            return jumi_key::key_s;
            case GLFW_KEY_T:                            return jumi_key::key_t;
            case GLFW_KEY_U:                            return jumi_key::key_u;
            case GLFW_KEY_V:                            return jumi_key::key_v;
            case GLFW_KEY_W:                            return jumi_key::key_w;
            case GLFW_KEY_X:                            return jumi_key::key_x;
            case GLFW_KEY_Y:                            return jumi_key::key_y;
            case GLFW_KEY_Z:                            return jumi_key::key_z;
            case GLFW_KEY_LEFT_BRACKET:                 return jumi_key::key_left_bracket;
            case GLFW_KEY_BACKSLASH:                    return jumi_key::key_backslash;
            case GLFW_KEY_RIGHT_BRACKET:                return jumi_key::key_right_bracket;
            case GLFW_KEY_GRAVE_ACCENT:                 return jumi_key::key_grave_accent;
            case GLFW_KEY_WORLD_1:                      return jumi_key::key_world_1;
            case GLFW_KEY_WORLD_2:                      return jumi_key::key_world_2;
            case GLFW_KEY_ESCAPE:                       return jumi_key::key_escape;
            case GLFW_KEY_ENTER:                        return jumi_key::key_enter;
            case GLFW_KEY_TAB:                          return jumi_key::key_tab;
            case GLFW_KEY_BACKSPACE:                    return jumi_key::key_backspace;
            case GLFW_KEY_INSERT:                       return jumi_key::key_insert;
            case GLFW_KEY_DELETE:                       return jumi_key::key_delete;
            case GLFW_KEY_RIGHT:                        return jumi_key::key_right;
            case GLFW_KEY_LEFT:                         return jumi_key::key_left;
            case GLFW_KEY_DOWN:                         return jumi_key::key_down;
            case GLFW_KEY_UP:                           return jumi_key::key_up;
            case GLFW_KEY_PAGE_UP:                      return jumi_key::key_page_up;
            case GLFW_KEY_PAGE_DOWN:                    return jumi_key::key_page_down;
            case GLFW_KEY_HOME:                         return jumi_key::key_home;
            case GLFW_KEY_END:                          return jumi_key::key_end;
            case GLFW_KEY_CAPS_LOCK:                    return jumi_key::key_caps_lock;
            case GLFW_KEY_SCROLL_LOCK:                  return jumi_key::key_scroll_lock;
            case GLFW_KEY_NUM_LOCK:                     return jumi_key::key_num_lock;
            case GLFW_KEY_PRINT_SCREEN:                 return jumi_key::key_print_screen;
            case GLFW_KEY_PAUSE:                        return jumi_key::key_pause;
            case GLFW_KEY_F1:                           return jumi_key::key_f1;
            case GLFW_KEY_F2:                           return jumi_key::key_f2;
            case GLFW_KEY_F3:                           return jumi_key::key_f3;
            case GLFW_KEY_F4:                           return jumi_key::key_f4;
            case GLFW_KEY_F5:                           return jumi_key::key_f5;
            case GLFW_KEY_F6:                           return jumi_key::key_f6;
            case GLFW_KEY_F7:                           return jumi_key::key_f7;
            case GLFW_KEY_F8:                           return jumi_key::key_f8;
            case GLFW_KEY_F9:                           return jumi_key::key_f9;
            case GLFW_KEY_F10:                          return jumi_key::key_f10;
            case GLFW_KEY_F11:                          return jumi_key::key_f11;
            case GLFW_KEY_F12:                          return jumi_key::key_f12;
            case GLFW_KEY_F13:                          return jumi_key::key_f13;
            case GLFW_KEY_F14:                          return jumi_key::key_f14;
            case GLFW_KEY_F15:                          return jumi_key::key_f15;
            case GLFW_KEY_F16:                          return jumi_key::key_f16;
            case GLFW_KEY_F17:                          return jumi_key::key_f17;
            case GLFW_KEY_F18:                          return jumi_key::key_f18;
            case GLFW_KEY_F19:                          return jumi_key::key_f19;
            case GLFW_KEY_F20:                          return jumi_key::key_f20;
            case GLFW_KEY_F21:                          return jumi_key::key_f21;
            case GLFW_KEY_F22:                          return jumi_key::key_f22;
            case GLFW_KEY_F23:                          return jumi_key::key_f23;
            case GLFW_KEY_F24:                          return jumi_key::key_f24;
            case GLFW_KEY_F25:                          return jumi_key::key_f25;
            case GLFW_KEY_KP_0:                         return jumi_key::key_kp_0;
            case GLFW_KEY_KP_1:                         return jumi_key::key_kp_1;
            case GLFW_KEY_KP_2:                         return jumi_key::key_kp_2;
            case GLFW_KEY_KP_3:                         return jumi_key::key_kp_3;
            case GLFW_KEY_KP_4:                         return jumi_key::key_kp_4;
            case GLFW_KEY_KP_5:                         return jumi_key::key_kp_5;
            case GLFW_KEY_KP_6:                         return jumi_key::key_kp_6;
            case GLFW_KEY_KP_7:                         return jumi_key::key_kp_7;
            case GLFW_KEY_KP_8:                         return jumi_key::key_kp_8;
            case GLFW_KEY_KP_9:                         return jumi_key::key_kp_9;
            case GLFW_KEY_KP_DECIMAL:                   return jumi_key::key_kp_decimal;
            case GLFW_KEY_KP_DIVIDE:                    return jumi_key::key_kp_divide;
            case GLFW_KEY_KP_MULTIPLY:                  return jumi_key::key_kp_multiply;
            case GLFW_KEY_KP_SUBTRACT:                  return jumi_key::key_kp_subtract;
            case GLFW_KEY_KP_ADD:                       return jumi_key::key_kp_add;
            case GLFW_KEY_KP_ENTER:                     return jumi_key::key_kp_enter;
            case GLFW_KEY_KP_EQUAL:                     return jumi_key::key_kp_equal;
            case GLFW_KEY_LEFT_SHIFT:                   return jumi_key::key_left_shift;
            case GLFW_KEY_LEFT_CONTROL:                 return jumi_key::key_left_control;
            case GLFW_KEY_LEFT_ALT:                     return jumi_key::key_left_alt;
            case GLFW_KEY_LEFT_SUPER:                   return jumi_key::key_left_super;
            case GLFW_KEY_RIGHT_SHIFT:                  return jumi_key::key_right_shift;
            case GLFW_KEY_RIGHT_CONTROL:                return jumi_key::key_right_control;
            case GLFW_KEY_RIGHT_ALT:                    return jumi_key::key_right_alt;
            case GLFW_KEY_RIGHT_SUPER:                  return jumi_key::key_right_super;
            case GLFW_KEY_MENU:                         return jumi_key::key_menu;
        }
    }

    int jumi_key_to_glfw(jumi_key jumi_key)
    {
        switch (jumi_key)
        {
            case jumi_key::key_space:                   return GLFW_KEY_SPACE;
            case jumi_key::key_apostrophe:              return GLFW_KEY_APOSTROPHE;
            case jumi_key::key_comma:                   return GLFW_KEY_COMMA;
            case jumi_key::key_minus:                   return GLFW_KEY_MINUS;
            case jumi_key::key_period:                  return GLFW_KEY_PERIOD;
            case jumi_key::key_slash:                   return GLFW_KEY_SLASH;
            case jumi_key::key_0:                       return GLFW_KEY_0;
            case jumi_key::key_1:                       return GLFW_KEY_1;
            case jumi_key::key_2:                       return GLFW_KEY_2;
            case jumi_key::key_3:                       return GLFW_KEY_3;
            case jumi_key::key_4:                       return GLFW_KEY_4;
            case jumi_key::key_5:                       return GLFW_KEY_5;
            case jumi_key::key_6:                       return GLFW_KEY_6;
            case jumi_key::key_7:                       return GLFW_KEY_7;
            case jumi_key::key_8:                       return GLFW_KEY_8;
            case jumi_key::key_9:                       return GLFW_KEY_9;
            case jumi_key::key_semicolon:               return GLFW_KEY_SEMICOLON;
            case jumi_key::key_equal:                   return GLFW_KEY_EQUAL;
            case jumi_key::key_a:                       return GLFW_KEY_A;
            case jumi_key::key_b:                       return GLFW_KEY_B;
            case jumi_key::key_c:                       return GLFW_KEY_C;
            case jumi_key::key_d:                       return GLFW_KEY_D;
            case jumi_key::key_e:                       return GLFW_KEY_E;
            case jumi_key::key_f:                       return GLFW_KEY_F;
            case jumi_key::key_g:                       return GLFW_KEY_G;
            case jumi_key::key_h:                       return GLFW_KEY_H;
            case jumi_key::key_i:                       return GLFW_KEY_I;
            case jumi_key::key_j:                       return GLFW_KEY_J;
            case jumi_key::key_k:                       return GLFW_KEY_K;
            case jumi_key::key_l:                       return GLFW_KEY_L;
            case jumi_key::key_m:                       return GLFW_KEY_M;
            case jumi_key::key_n:                       return GLFW_KEY_N;
            case jumi_key::key_o:                       return GLFW_KEY_O;
            case jumi_key::key_p:                       return GLFW_KEY_P;
            case jumi_key::key_q:                       return GLFW_KEY_Q;
            case jumi_key::key_r:                       return GLFW_KEY_R;
            case jumi_key::key_s:                       return GLFW_KEY_S;
            case jumi_key::key_t:                       return GLFW_KEY_T;
            case jumi_key::key_u:                       return GLFW_KEY_U;
            case jumi_key::key_v:                       return GLFW_KEY_V;
            case jumi_key::key_w:                       return GLFW_KEY_W;
            case jumi_key::key_x:                       return GLFW_KEY_X;
            case jumi_key::key_y:                       return GLFW_KEY_Y;
            case jumi_key::key_z:                       return GLFW_KEY_Z;
            case jumi_key::key_left_bracket:            return GLFW_KEY_LEFT_BRACKET;
            case jumi_key::key_backslash:               return GLFW_KEY_BACKSLASH;
            case jumi_key::key_right_bracket:           return GLFW_KEY_RIGHT_BRACKET;
            case jumi_key::key_grave_accent:            return GLFW_KEY_GRAVE_ACCENT;
            case jumi_key::key_world_1:                 return GLFW_KEY_WORLD_1;
            case jumi_key::key_world_2:                 return GLFW_KEY_WORLD_2;
            case jumi_key::key_escape:                  return GLFW_KEY_ESCAPE;
            case jumi_key::key_enter:                   return GLFW_KEY_ENTER;
            case jumi_key::key_tab:                     return GLFW_KEY_TAB;
            case jumi_key::key_backspace:               return GLFW_KEY_BACKSPACE;
            case jumi_key::key_insert:                  return GLFW_KEY_INSERT;
            case jumi_key::key_delete:                  return GLFW_KEY_DELETE;
            case jumi_key::key_right:                   return GLFW_KEY_RIGHT;
            case jumi_key::key_left:                    return GLFW_KEY_LEFT;
            case jumi_key::key_down:                    return GLFW_KEY_DOWN;
            case jumi_key::key_up:                      return GLFW_KEY_UP;
            case jumi_key::key_page_up:                 return GLFW_KEY_PAGE_UP;
            case jumi_key::key_page_down:               return GLFW_KEY_PAGE_DOWN;
            case jumi_key::key_home:                    return GLFW_KEY_HOME;
            case jumi_key::key_end:                     return GLFW_KEY_END;
            case jumi_key::key_caps_lock:               return GLFW_KEY_CAPS_LOCK;
            case jumi_key::key_scroll_lock:             return GLFW_KEY_SCROLL_LOCK;
            case jumi_key::key_num_lock:                return GLFW_KEY_NUM_LOCK;
            case jumi_key::key_print_screen:            return GLFW_KEY_PRINT_SCREEN;
            case jumi_key::key_pause:                   return GLFW_KEY_PAUSE;
            case jumi_key::key_f1:                      return GLFW_KEY_F1;
            case jumi_key::key_f2:                      return GLFW_KEY_F2;
            case jumi_key::key_f3:                      return GLFW_KEY_F3;
            case jumi_key::key_f4:                      return GLFW_KEY_F4;
            case jumi_key::key_f5:                      return GLFW_KEY_F5;
            case jumi_key::key_f6:                      return GLFW_KEY_F6;
            case jumi_key::key_f7:                      return GLFW_KEY_F7;
            case jumi_key::key_f8:                      return GLFW_KEY_F8;
            case jumi_key::key_f9:                      return GLFW_KEY_F9;
            case jumi_key::key_f10:                     return GLFW_KEY_F10;
            case jumi_key::key_f11:                     return GLFW_KEY_F11;
            case jumi_key::key_f12:                     return GLFW_KEY_F12;
            case jumi_key::key_f13:                     return GLFW_KEY_F13;
            case jumi_key::key_f14:                     return GLFW_KEY_F14;
            case jumi_key::key_f15:                     return GLFW_KEY_F15;
            case jumi_key::key_f16:                     return GLFW_KEY_F16;
            case jumi_key::key_f17:                     return GLFW_KEY_F17;
            case jumi_key::key_f18:                     return GLFW_KEY_F18;
            case jumi_key::key_f19:                     return GLFW_KEY_F19;
            case jumi_key::key_f20:                     return GLFW_KEY_F20;
            case jumi_key::key_f21:                     return GLFW_KEY_F21;
            case jumi_key::key_f22:                     return GLFW_KEY_F22;
            case jumi_key::key_f23:                     return GLFW_KEY_F23;
            case jumi_key::key_f24:                     return GLFW_KEY_F24;
            case jumi_key::key_f25:                     return GLFW_KEY_F25;
            case jumi_key::key_kp_0:                    return GLFW_KEY_KP_0;
            case jumi_key::key_kp_1:                    return GLFW_KEY_KP_1;
            case jumi_key::key_kp_2:                    return GLFW_KEY_KP_2;
            case jumi_key::key_kp_3:                    return GLFW_KEY_KP_3;
            case jumi_key::key_kp_4:                    return GLFW_KEY_KP_4;
            case jumi_key::key_kp_5:                    return GLFW_KEY_KP_5;
            case jumi_key::key_kp_6:                    return GLFW_KEY_KP_6;
            case jumi_key::key_kp_7:                    return GLFW_KEY_KP_7;
            case jumi_key::key_kp_8:                    return GLFW_KEY_KP_8;
            case jumi_key::key_kp_9:                    return GLFW_KEY_KP_9;
            case jumi_key::key_kp_decimal:              return GLFW_KEY_KP_DECIMAL;
            case jumi_key::key_kp_divide:               return GLFW_KEY_KP_DIVIDE;
            case jumi_key::key_kp_multiply:             return GLFW_KEY_KP_MULTIPLY;
            case jumi_key::key_kp_subtract:             return GLFW_KEY_KP_SUBTRACT;
            case jumi_key::key_kp_add:                  return GLFW_KEY_KP_ADD;
            case jumi_key::key_kp_enter:                return GLFW_KEY_KP_ENTER;
            case jumi_key::key_kp_equal:                return GLFW_KEY_KP_EQUAL;
            case jumi_key::key_left_shift:              return GLFW_KEY_LEFT_SHIFT;
            case jumi_key::key_left_control:            return GLFW_KEY_LEFT_CONTROL;
            case jumi_key::key_left_alt:                return GLFW_KEY_LEFT_ALT;
            case jumi_key::key_left_super:              return GLFW_KEY_LEFT_SUPER;
            case jumi_key::key_right_shift:             return GLFW_KEY_RIGHT_SHIFT;
            case jumi_key::key_right_control:           return GLFW_KEY_RIGHT_CONTROL;
            case jumi_key::key_right_alt:               return GLFW_KEY_RIGHT_ALT;
            case jumi_key::key_right_super:             return GLFW_KEY_RIGHT_SUPER;
            case jumi_key::key_menu:                    return GLFW_KEY_MENU;
        }
    }

    jumi_mousebutton glfw_mousebutton_to_jumi(int glfw_mousebutton)
    {
        switch (glfw_mousebutton)
        {
            case GLFW_MOUSE_BUTTON_1:                   return jumi_mousebutton::mouse_button_1;
            case GLFW_MOUSE_BUTTON_2:                   return jumi_mousebutton::mouse_button_2;
            case GLFW_MOUSE_BUTTON_3:                   return jumi_mousebutton::mouse_button_3;
            case GLFW_MOUSE_BUTTON_4:                   return jumi_mousebutton::mouse_button_4;
            case GLFW_MOUSE_BUTTON_5:                   return jumi_mousebutton::mouse_button_5;
            case GLFW_MOUSE_BUTTON_6:                   return jumi_mousebutton::mouse_button_6;
            case GLFW_MOUSE_BUTTON_7:                   return jumi_mousebutton::mouse_button_7;
            case GLFW_MOUSE_BUTTON_8:                   return jumi_mousebutton::mouse_button_8;
        }
    }

    int jumi_mousebutton_to_glfw(jumi_mousebutton jumi_mousebutton)
    {
        switch (jumi_mousebutton)
        {
            case jumi_mousebutton::mouse_button_1:      return GLFW_MOUSE_BUTTON_1;
            case jumi_mousebutton::mouse_button_2:      return GLFW_MOUSE_BUTTON_2;
            case jumi_mousebutton::mouse_button_3:      return GLFW_MOUSE_BUTTON_3;
            case jumi_mousebutton::mouse_button_4:      return GLFW_MOUSE_BUTTON_4;
            case jumi_mousebutton::mouse_button_5:      return GLFW_MOUSE_BUTTON_5;
            case jumi_mousebutton::mouse_button_6:      return GLFW_MOUSE_BUTTON_6;
            case jumi_mousebutton::mouse_button_7:      return GLFW_MOUSE_BUTTON_7;
            case jumi_mousebutton::mouse_button_8:      return GLFW_MOUSE_BUTTON_8;
        }
    }

    jumi_keymod glfw_keymod_to_jumi(int glfw_keymod)
    {
        switch (glfw_keymod)
        {
            case GLFW_MOD_SHIFT:                        return jumi_keymod::mod_shift;
            case GLFW_MOD_CONTROL:                      return jumi_keymod::mod_control;
            case GLFW_MOD_ALT:                          return jumi_keymod::mod_alt;
            case GLFW_MOD_SUPER:                        return jumi_keymod::mod_super;
            case GLFW_MOD_CAPS_LOCK:                    return jumi_keymod::mod_caps_lock;
            case GLFW_MOD_NUM_LOCK:                     return jumi_keymod::mod_num_lock;
        }
    }

    jumi_joystick glfw_joystick_to_jumi(int glfw_joystick)
    {
        switch (glfw_joystick)
        {
            case GLFW_JOYSTICK_1:                       return jumi_joystick::joystick_1;
            case GLFW_JOYSTICK_2:                       return jumi_joystick::joystick_2;
            case GLFW_JOYSTICK_3:                       return jumi_joystick::joystick_3;
            case GLFW_JOYSTICK_4:                       return jumi_joystick::joystick_4;
            case GLFW_JOYSTICK_5:                       return jumi_joystick::joystick_5;
            case GLFW_JOYSTICK_6:                       return jumi_joystick::joystick_6;
            case GLFW_JOYSTICK_7:                       return jumi_joystick::joystick_7;
            case GLFW_JOYSTICK_8:                       return jumi_joystick::joystick_8;
            case GLFW_JOYSTICK_9:                       return jumi_joystick::joystick_9;
            case GLFW_JOYSTICK_10:                      return jumi_joystick::joystick_10;
            case GLFW_JOYSTICK_11:                      return jumi_joystick::joystick_11;
            case GLFW_JOYSTICK_12:                      return jumi_joystick::joystick_12;
        }
    }

    int jumi_joystick_to_glfw(jumi_joystick jumi_joystick)
    {
        switch (jumi_joystick)
        {
            case jumi_joystick::joystick_1:             return GLFW_JOYSTICK_1;
            case jumi_joystick::joystick_2:             return GLFW_JOYSTICK_2;
            case jumi_joystick::joystick_3:             return GLFW_JOYSTICK_3;
            case jumi_joystick::joystick_4:             return GLFW_JOYSTICK_4;
            case jumi_joystick::joystick_5:             return GLFW_JOYSTICK_5;
            case jumi_joystick::joystick_6:             return GLFW_JOYSTICK_6;
            case jumi_joystick::joystick_7:             return GLFW_JOYSTICK_7;
            case jumi_joystick::joystick_8:             return GLFW_JOYSTICK_8;
            case jumi_joystick::joystick_9:             return GLFW_JOYSTICK_9;
            case jumi_joystick::joystick_10:            return GLFW_JOYSTICK_10;
            case jumi_joystick::joystick_11:            return GLFW_JOYSTICK_11;
            case jumi_joystick::joystick_12:            return GLFW_JOYSTICK_12;
        }
    }

    jumi_gamepad_button glfw_gamepad_button_to_jumi(int glfw_gamepad_button)
    {
        switch (glfw_gamepad_button)
        {
            case GLFW_GAMEPAD_BUTTON_A:                 return jumi_gamepad_button::a;
            case GLFW_GAMEPAD_BUTTON_B:                 return jumi_gamepad_button::b;
            case GLFW_GAMEPAD_BUTTON_X:                 return jumi_gamepad_button::x;
            case GLFW_GAMEPAD_BUTTON_Y:                 return jumi_gamepad_button::y;
            case GLFW_GAMEPAD_BUTTON_LEFT_BUMPER:       return jumi_gamepad_button::left_bumper;
            case GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER:      return jumi_gamepad_button::right_bumper;
            case GLFW_GAMEPAD_BUTTON_BACK:              return jumi_gamepad_button::back;
            case GLFW_GAMEPAD_BUTTON_START:             return jumi_gamepad_button::start;
            case GLFW_GAMEPAD_BUTTON_GUIDE:             return jumi_gamepad_button::guide;
            case GLFW_GAMEPAD_BUTTON_LEFT_THUMB:        return jumi_gamepad_button::left_thumb;
            case GLFW_GAMEPAD_BUTTON_RIGHT_THUMB:       return jumi_gamepad_button::right_thumb;
            case GLFW_GAMEPAD_BUTTON_DPAD_UP:           return jumi_gamepad_button::dpad_up;
            case GLFW_GAMEPAD_BUTTON_DPAD_RIGHT:        return jumi_gamepad_button::dpad_right;
            case GLFW_GAMEPAD_BUTTON_DPAD_DOWN:         return jumi_gamepad_button::dpad_down;
            case GLFW_GAMEPAD_BUTTON_DPAD_LEFT:         return jumi_gamepad_button::dpad_left;
        }
    }

    int jumi_gamepade_button_to_glfw(jumi_gamepad_button jumi_gamepad_button)
    {
        switch (jumi_gamepad_button)
        {
            case jumi_gamepad_button::a:                return GLFW_GAMEPAD_BUTTON_A;
            case jumi_gamepad_button::b:                return GLFW_GAMEPAD_BUTTON_B;
            case jumi_gamepad_button::x:                return GLFW_GAMEPAD_BUTTON_X;
            case jumi_gamepad_button::y:                return GLFW_GAMEPAD_BUTTON_Y;
            case jumi_gamepad_button::left_bumper:      return GLFW_GAMEPAD_BUTTON_LEFT_BUMPER;
            case jumi_gamepad_button::right_bumper:     return GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER;
            case jumi_gamepad_button::back:             return GLFW_GAMEPAD_BUTTON_BACK;
            case jumi_gamepad_button::start:            return GLFW_GAMEPAD_BUTTON_START;
            case jumi_gamepad_button::guide:            return GLFW_GAMEPAD_BUTTON_GUIDE;
            case jumi_gamepad_button::left_thumb:       return GLFW_GAMEPAD_BUTTON_LEFT_THUMB;
            case jumi_gamepad_button::right_thumb:      return GLFW_GAMEPAD_BUTTON_RIGHT_THUMB;
            case jumi_gamepad_button::dpad_up:          return GLFW_GAMEPAD_BUTTON_DPAD_UP;
            case jumi_gamepad_button::dpad_right:       return GLFW_GAMEPAD_BUTTON_DPAD_RIGHT;
            case jumi_gamepad_button::dpad_down:        return GLFW_GAMEPAD_BUTTON_DPAD_DOWN;
            case jumi_gamepad_button::dpad_left:        return GLFW_GAMEPAD_BUTTON_DPAD_LEFT;
            case jumi_gamepad_button::left_x:           return GLFW_GAMEPAD_AXIS_LEFT_X;
            case jumi_gamepad_button::left_y:           return GLFW_GAMEPAD_AXIS_LEFT_Y;
            case jumi_gamepad_button::right_x:          return GLFW_GAMEPAD_AXIS_RIGHT_X;
            case jumi_gamepad_button::right_y:          return GLFW_GAMEPAD_AXIS_RIGHT_Y;
            case jumi_gamepad_button::left_trigger:     return GLFW_GAMEPAD_AXIS_LEFT_TRIGGER;
            case jumi_gamepad_button::right_trigger:    return GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER;
        }
    }

}
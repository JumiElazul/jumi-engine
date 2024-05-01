#ifndef JUMI_ENGINE_INPUT_KEYCODES_H
#define JUMI_ENGINE_INPUT_KEYCODES_H
#include <magic_enum.hpp>
#include <string_view>
#include <type_traits>

namespace jumi
{
    template<typename Enum>
    constexpr std::string_view enum_to_string(Enum input)
    {
        static_assert(std::is_enum<Enum>::value, "enum_to_string can only be used with enums");
        return magic_num::enum_name(input);
    }

    enum class jumi_keyaction
    {
        release,
        press,
        repeat
    };

    enum class jumi_key
    {
        key_space,
        key_apostrophe,
        key_comma,
        key_minus,
        key_period,
        key_slash,
        key_0,
        key_1,
        key_2,
        key_3,
        key_4,
        key_5,
        key_6,
        key_7,
        key_8,
        key_9,
        key_semicolon,
        key_equal,
        key_a,
        key_b,
        key_c,
        key_d,
        key_e,
        key_f,
        key_g,
        key_h,
        key_i,
        key_j,
        key_k,
        key_l,
        key_m,
        key_n,
        key_o,
        key_p,
        key_q,
        key_r,
        key_s,
        key_t,
        key_u,
        key_v,
        key_w,
        key_x,
        key_y,
        key_z,
        key_left_bracket,
        key_backslash,
        key_right_bracket,
        key_grave_accent,
        key_world_1,
        key_world_2,

        key_escape,
        key_enter,
        key_tab,
        key_backspace,
        key_insert,
        key_delete,
        key_right,
        key_left,
        key_down,
        key_up,
        key_page_up,
        key_page_down,
        key_home,
        key_end,
        key_caps_lock,
        key_scroll_lock,
        key_num_lock,
        key_print_screen,
        key_pause,
        key_f1,
        key_f2,
        key_f3,
        key_f4,
        key_f5,
        key_f6,
        key_f7,
        key_f8,
        key_f9,
        key_f10,
        key_f11,
        key_f12,
        key_f13,
        key_f14,
        key_f15,
        key_f16,
        key_f17,
        key_f18,
        key_f19,
        key_f20,
        key_f21,
        key_f22,
        key_f23,
        key_f24,
        key_f25,
        key_kp_0,
        key_kp_1,
        key_kp_2,
        key_kp_3,
        key_kp_4,
        key_kp_5,
        key_kp_6,
        key_kp_7,
        key_kp_8,
        key_kp_9,
        key_kp_decimal,
        key_kp_divide,
        key_kp_multiply,
        key_kp_subtract,
        key_kp_add,
        key_kp_enter,
        key_kp_equal,
        key_left_shift,
        key_left_control,
        key_left_alt,
        key_left_super,
        key_right_shift,
        key_right_control,
        key_right_alt,
        key_right_super,
        key_menu,
    };

    enum class jumi_mousebutton
    {
        mouse_button_1,
        mouse_button_2,
        mouse_button_3,
        mouse_button_4,
        mouse_button_5,
        mouse_button_6,
        mouse_button_7,
        mouse_button_8,
    };

    enum class jumi_keymod
    {
        mod_shift,
        mod_control,
        mod_alt,
        mod_super,
        mod_caps_lock,
        mod_num_lock,
    };

    enum class jumi_joystick
    {
        joystick_1,
        joystick_2,
        joystick_3,
        joystick_4,
        joystick_5,
        joystick_6,
        joystick_7,
        joystick_8,
        joystick_9,
        joystick_10,
        joystick_11,
        joystick_12,
        joystick_13,
        joystick_14,
        joystick_15,
        joystick_16,
    };

    enum class jumi_gamepad_button
    {
        a,
        b,
        x,
        y,
        left_bumper,
        right_bumper,
        back,
        start,
        guide,
        left_thumb,
        right_thumb,
        dpad_up,
        dpad_right,
        dpad_down,
        dpad_left,
        left_x,
        left_y,
        right_x,
        right_y,
        left_trigger,
        right_trigger,
    };

}

#endif

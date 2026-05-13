#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <cstddef>
#include <type_traits>
#include <unordered_map>

enum class InputAction
{
    MoveForward,
    MoveBack,
    MoveLeft,
    MoveRight,
    Jump,
    Attack,
    Dodge,
    LockOn,
    Interact,
    TogglePause,
    ToggleDebug,
    ReloadAssets
};

struct InputActionHasher
{
    std::size_t operator()(InputAction action) const noexcept
    {
        using Underlying = std::underlying_type_t<InputAction>;
        return static_cast<std::size_t>(static_cast<Underlying>(action));
    }
};

struct InputActionMap
{
    std::unordered_map<InputAction, int, InputActionHasher> bindings;

    static InputActionMap Default()
    {
        InputActionMap map;
        map.bindings[InputAction::MoveForward]  = 'W';
        map.bindings[InputAction::MoveBack]     = 'S';
        map.bindings[InputAction::MoveLeft]     = 'A';
        map.bindings[InputAction::MoveRight]    = 'D';
        map.bindings[InputAction::Jump]         = VK_SPACE;
        map.bindings[InputAction::Attack]       = 'F';
        map.bindings[InputAction::Dodge]        = VK_SHIFT;
        map.bindings[InputAction::LockOn]       = 'Q';
        map.bindings[InputAction::Interact]     = 'E';
        map.bindings[InputAction::TogglePause]  = VK_ESCAPE;
        map.bindings[InputAction::ToggleDebug]  = VK_F1;
        map.bindings[InputAction::ReloadAssets] = VK_F5;
        return map;
    }

    bool IsHeld(InputAction action) const
    {
        const auto it = bindings.find(action);
        if (it == bindings.end())
            return false;
        return (GetAsyncKeyState(it->second) & 0x8000) != 0;
    }

    bool IsPressed(InputAction action, bool& wasDown) const
    {
        const bool isDown = IsHeld(action);
        const bool pressed = isDown && !wasDown;
        wasDown = isDown;
        return pressed;
    }

    bool IsVirtualKeyHeld(int virtualKey) const
    {
        return (GetAsyncKeyState(virtualKey) & 0x8000) != 0;
    }
};

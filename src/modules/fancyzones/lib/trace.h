#pragma once

struct Settings;
interface IZoneSet;

class Trace
{
public:
    static void RegisterProvider() noexcept;
    static void UnregisterProvider() noexcept;

    class FancyZones
    {
    public:
        static void EnableFancyZones(bool enabled) noexcept;
        static void ToggleZoneViewers(bool visible) noexcept;
        static void OnKeyDown(DWORD vkCode, bool win, bool control, bool inMoveSize) noexcept;
    };

    static void SettingsChanged(const Settings& settings) noexcept;
    static void VirtualDesktopChanged() noexcept;

    class ZoneWindow
    {
    public:
        enum class InputMode
        {
            Keyboard,
            Mouse
        };

        static void KeyUp(WPARAM wParam, bool isEditorMode) noexcept;
        static void MoveSizeEnd(_In_opt_ winrt::com_ptr<IZoneSet> activeSet) noexcept;
        static void CycleActiveZoneSet(_In_opt_ winrt::com_ptr<IZoneSet> activeSet, InputMode mode) noexcept;

        class EditorModeActivity
        {
        public:
            void Start() noexcept;
            void Stop(_In_opt_ winrt::com_ptr<IZoneSet> activeSet) noexcept;
        private:
            std::optional<TraceLoggingActivity<g_hProvider, PROJECT_KEYWORD_MEASURE>> m_activity{};
        };
    };
};

/**
 * Mouse coordinates
 */
struct MousePosition {
    int x;
    int y;
};

/**
 * Info about mouse state
 */
struct MouseState {
    MousePosition position;
    bool leftButtonPressed;
    bool rightButtonPressed;
    bool scrollPressed;
};

static const char *code = 
  "<!DOCTYPE html>"
  "<html>"
    "<head><title>CONTROL DISPLAY</title></head>"
    "<body>"
      "<div>"
        "<form action='/' method='post'>"
            "<p>New Text: </p>"
            "<input type='text' name='display' placeholder='What would you like to tell the world?'>"
            "<br>"
            "<select name='effect'>"
                "<option value='Effect 1'>" //change to function that will do all these for me
                "<option value='Effect 2'>" //change to function that will do all these for me
            "</select>"
            "<br>"
            "<input type='submit' value='Change'>"
        "</form>"
      "</div>"
    "</body>"
  "</html>";

static const int EFFECTS[] = {
    PA_PRINT,
    PA_SCAN_HORIZ,
    PA_SCROLL_LEFT,
    PA_WIPE,
    PA_SCROLL_UP_LEFT,
    PA_SCROLL_UP,
    PA_OPENING_CURSOR,
    PA_GROW_UP,
    PA_MESH,
    PA_SCROLL_UP_RIGHT,
    PA_BLINDS,
    PA_CLOSING,
    PA_RANDOM,
    PA_GROW_DOWN,
    PA_SCAN_VERT,
    PA_SCROLL_DOWN_LEFT,
    PA_WIPE_CURSOR,
    PA_DISSOLVE,
    PA_OPENING,
    PA_CLOSING_CURSOR,
    PA_SCROLL_DOWN_RIGHT,
    PA_SCROLL_RIGHT,
    PA_SLICE,
    PA_SCROLL_DOWN
};

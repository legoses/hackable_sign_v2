const int MAX_EFFECT = 30; //keep track of the amount of possible effects

//html that is displayed on webpage
static const char *code = 
    "<style>"
        "body, input, select {"
        "    font-family: 'Courier New', monospace;"
        "}"
    "</style>"
    "<!DOCTYPE html>"
    "<html>"
    "<head><title>CONTROL DISPLAY</title></head>"
    "<body>"
      "<div>"
        "<form action='/' method='post'>"
            "<p>New Text: </p>"
            "<input type='text' name='display' placeholder='What would you like to tell the world?' style='width:300px'>"
            "<br>"
            "<p>Set Speed: </p>"
            "<input type='text' name='speed' placeholder='50' style='width:50px'>"
            "<br>"
            "<br>"
            "<select name='effect'>"
                "<option value=''>-- Select an effect --</option>"
                "<option value='0'>PA_NO_EFFECT</option>"
                "<option value='1'>PA_PRINT</option>"
                "<option value='2'>PA_SLICE</option>"
                "<option value='3'>PA_WIPE</option>"
                "<option value='4'>PA_MESH</option>"
                "<option value='5'>PA_FADE</option>"
                "<option value='6'>PA_RANDOM</option>"
                "<option value='7'>PA_WIPE_CURSOR</option>"
                "<option value='8'>PA_OPENING</option>"
                "<option value='9'>PA_OPENING_CURSOR</option>"
                "<option value='10'>PA_CLOSING</option>"
                "<option value='11'>PA_CLOSING_CURSOR</option>"
                "<option value='12'>PA_BLINDS</option>"
                "<option value='13'>PA_DISSOLVE</option>"
                "<option value='14'>PA_SCROLL_UP</option>"
                "<option value='15'>PA_SCROLL_DOWN</option>"
                "<option value='16'>PA_SCROLL_LEFT</option>"
                "<option value='17'>PA_SCROLL_RIGHT</option>"
                "<option value='18'>PA_SCROLL_UP_LEFT</option>"
                "<option value='19'>PA_SCROLL_UP_RIGHT</option>"
                "<option value='20'>PA_SCROLL_DOWN_LEFT</option>"
                "<option value='21'>PA_SCROLL_DOWN_RIGHT</option>"
                "<option value='22'>PA_SCAN_HORIZ</option>"
                "<option value='23'>PA_SCAN_HORIZX</option>"
                "<option value='24'>PA_SCAN_VERT</option>"
                "<option value='25'>PA_SCAN_VERTX</option>"
                "<option value='26'>PA_GROW_UP</option>"
                "<option value='27'>PA_GROW_DOWN</option>"
                "<option value='28'>PA_SCAN_HORIZ</option>"
                "<option value='29'>PA_SCAN_VERT</option>"
                "<option value='30'>PA_SPRITE</option>"
            "</select>"
            "<br>"
            "<input type='submit' value='Change'>"
        "</form>"
      "</div>"
    "</body>"
    "</html>";

static textEffect_t EFFECTS[] = {
    PA_NO_EFFECT,
    PA_PRINT,
    PA_SLICE,
    PA_WIPE,
    PA_MESH,
    PA_FADE,
    PA_RANDOM,
    PA_WIPE_CURSOR,
    PA_OPENING,
    PA_OPENING_CURSOR,
    PA_CLOSING,
    PA_CLOSING_CURSOR,
    PA_BLINDS,
    PA_DISSOLVE,
    PA_SCROLL_UP,
    PA_SCROLL_DOWN,
    PA_SCROLL_LEFT,
    PA_SCROLL_RIGHT,
    PA_SCROLL_UP_LEFT,
    PA_SCROLL_UP_RIGHT,
    PA_SCROLL_DOWN_LEFT,
    PA_SCROLL_DOWN_RIGHT,
    PA_SCAN_HORIZ,
    PA_SCAN_HORIZX,
    PA_SCAN_VERT,
    PA_SCAN_VERTX,
    PA_GROW_UP,
    PA_GROW_DOWN,
    PA_SCAN_HORIZ,
    PA_SCAN_VERT,
    PA_SPRITE
};

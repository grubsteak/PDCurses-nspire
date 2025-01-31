/* Public Domain Curses */

#include "pdcsdl.h"

/*man-start**************************************************************

  Name:                                                         pdcsetsc

  Synopsis:
        int PDC_set_blink(PDC_bool blinkon);
        void PDC_set_title(const char *title);

  Description:
        PDC_set_blink() toggles whether the A_BLINK attribute sets an
        actual blink mode (PDC_TRUE), or sets the background color to high
        intensity (PDC_FALSE). The default is platform-dependent (PDC_FALSE in
        most cases). It returns OK if it could set the state to match 
        the given parameter, ERR otherwise. Current platforms also 
        adjust the value of COLORS according to this function -- 16 for 
        PDC_FALSE, and 8 for PDC_TRUE.

        PDC_set_title() sets the title of the window in which the curses
        program is running. This function may not do anything on some
        platforms. (Currently it only works in Win32 and X11.)

  Portability                                X/Open    BSD    SYS V
        PDC_set_blink                           -       -       -
        PDC_set_title                           -       -       -

**man-end****************************************************************/

int PDC_curs_set(int visibility)
{
    int ret_vis;

    PDC_LOG(("PDC_curs_set() - called: visibility=%d\n", visibility));

    ret_vis = SP->visibility;

    SP->visibility = visibility;

    PDC_gotoyx(SP->cursrow, SP->curscol);

    return ret_vis;
}

void PDC_set_title(const char *title)
{
    PDC_LOG(("PDC_set_title() - called:<%s>\n", title));

    SDL_WM_SetCaption(title, title);
}

int PDC_set_blink(PDC_bool blinkon)
{
    if (pdc_color_started)
        COLORS = 16;

    return blinkon ? ERR : OK;
}
